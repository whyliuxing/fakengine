#pragma once

/*
type:           [1]
iter:     begin(2)     end(8)
            |           |
data:   _ _ * * * * * * _ _ _ 
buffer: _ _ _ _ _ _ _ _ _ _ _ 
index:  0 1 2 3 4 5 6 7 8 9 10

type:           [2]
iter:      end(2)   begin(7)
            |         |
data:   * * _ _ _ _ _ * * * *  
buffer: _ _ _ _ _ _ _ _ _ _ _ 
index:  0 1 2 3 4 5 6 7 8 9 10


type:           [3]
iter:      begin(4),end(4)
                |
data:   _ _ _ _ _ _ _ _ _ _ _ 
buffer: _ _ _ _ _ _ _ _ _ _ _ 
index:  0 1 2 3 4 5 6 7 8 9 10

type:           [4]
iter:      begin(4),end(4)
|				 |
data:   * * * * * * * * * * *
buffer: _ _ _ _ _ _ _ _ _ _ _
index:  0 1 2 3 4 5 6 7 8 9 10

*/
template <typename T>
class circle_buffer_auto
{
public:
	circle_buffer_auto(size_t N = c_circle_buffer_auto_size) : m_buffer(0), 
		m_size(0), m_datasize(0), m_begin(0), m_end(0),
		m_store_datasize(0), m_store_begin(0), m_store_end(0)
	{
		m_buffer = (int8_t*)FALLOC(N * sizeof(T));
		m_size = N;
	}
	circle_buffer_auto(const circle_buffer_auto<T> & r) : m_size(r.m_size), m_datasize(r.m_datasize), 
		m_begin(r.m_begin), m_end(r.m_end), m_store_datasize(r.m_store_datasize), 
		m_store_begin(r.m_store_begin), m_store_end(r.m_store_end)
	{
		m_buffer = (int8_t*)FALLOC(m_size * sizeof(T));
		memcpy(m_buffer, r.m_buffer, sizeof(T) * m_size);
	}
	~circle_buffer_auto()
	{
		SAFE_FREE(m_buffer);
	}
	circle_buffer_auto<T> & operator = (const circle_buffer_auto<T> & r)
	{
		m_size = r.m_size;
		SAFE_FREE(m_buffer);
		m_buffer = (int8_t*)FALLOC(m_size * sizeof(T));
		memcpy(m_buffer, r.m_buffer, sizeof(T) * m_size);
		m_datasize = r.m_datasize;
		m_begin = r.m_begin;
		m_end = r.m_end;
		m_store_datasize = r.m_store_datasize;
		m_store_begin = r.m_store_begin;
		m_store_end = r.m_store_end;
		return *this;
	}
public:
	force_inline bool can_write(size_t size)
	{
		return m_datasize + size <= m_size;
	}
	force_inline void skip_write(size_t size)
	{
		m_datasize += size;
		m_end += size;
		if (m_end >= m_size)
		{
			m_end -= m_size;
		}
	}
	force_inline bool write(const T * p, size_t size)
	{
		if (!can_write(size))
		{
			if (!grow(size))
			{
				return false;
			}
			if (!can_write(size))
			{
				return false;
			}
		}

		real_write(p, size);

		skip_write(size);

		return true;
	}
	force_inline bool can_read(size_t size)
	{
		return m_datasize >= size;
	}
	force_inline void skip_read(size_t size)
	{
		m_datasize -= size;
		m_begin += size;
		if (m_begin >= m_size)
		{
			m_begin -= m_size;
		}
	}
	force_inline bool read(T * out, size_t size)
	{
		if (!can_read(size))
		{
			return false;
		}

		real_read(out, size);

		skip_read(size);

		return true;
	}
	force_inline void store()
	{
		m_store_datasize = m_datasize;
		m_store_begin = m_begin;
		m_store_end = m_end;
	}
	force_inline void restore()
	{
		m_datasize = m_store_datasize;
		m_begin = m_store_begin;
		m_end = m_store_end;
	}
	force_inline bool clear()
	{
		m_datasize = 0;
		m_begin = 0;
		m_end = 0;
		return true;
	}
	force_inline size_t size()
	{
		return m_datasize;
	}
	force_inline size_t capacity()
	{
		return m_size;
	}
	force_inline bool empty()
	{
		return size() == 0;
	}
	force_inline bool full()
	{
		return size() == capacity();
	}
	force_inline T * get_read_line_buffer()
	{
		return m_buffer + m_begin;
	}
	force_inline size_t get_read_line_size()
	{
		return std::min<size_t>(m_datasize, m_size - m_begin);
	}
	force_inline T * get_write_line_buffer()
	{
		return m_buffer + m_end;
	}
	force_inline size_t get_write_line_size()
	{
		return std::min<size_t>(m_size - m_datasize, m_size - m_end);
	}
	force_inline bool grow(size_t add_size)
	{
		size_t new_size = m_size + add_size + std::min<size_t>(m_size, add_size);
		return resize(new_size);
	}
	force_inline bool resize(size_t new_size)
	{
		if (new_size < m_datasize)
		{
			return false;
		}

		int8_t * buffer = (int8_t*)FALLOC(new_size * sizeof(T));
		size_t old_data_size = m_datasize;
		if (!read(buffer, m_datasize))
		{
			SAFE_FREE(buffer);
			return false;
		}

		m_datasize = old_data_size;
		m_begin = 0;
		m_end = m_datasize;
		m_size = new_size;
		SAFE_FREE(m_buffer);
		m_buffer = buffer;

		return true;
	}
private:
	force_inline void real_write(const T * p, size_t size)
	{
		if (m_end >= m_begin)	// [1][3]
		{
			// 能装下
			if (m_size - m_end >= size)
			{
				memcpy(m_buffer + m_end, p, size * sizeof(T));
			}
			else
			{
				memcpy(m_buffer + m_end, p, (m_size - m_end) * sizeof(T));
				memcpy(m_buffer, p + (m_size - m_end), (size - (m_size - m_end)) * sizeof(T));
			}
		}
		else	//[2]
		{
			memcpy(m_buffer + m_end, p, size * sizeof(T));
		}
	}
	force_inline void real_read(T * out, size_t size)
	{
		if (m_begin >= m_end)	// [2][4]
		{
			// 能读完
			if (m_size - m_begin >= size)
			{
				memcpy(out, m_buffer + m_begin, size * sizeof(T));
			}
			else
			{
				memcpy(out, m_buffer + m_begin, (m_size - m_begin) * sizeof(T));
				memcpy(out + (m_size - m_begin), m_buffer, (size - (m_size - m_begin)) * sizeof(T));
			}
		}
		else	// [1]
		{
			memcpy(out, m_buffer + m_begin, size * sizeof(T));
		}
	}
private:
	T * m_buffer;
	size_t m_size;
	size_t m_datasize;
	size_t m_begin;
	size_t m_end;
	size_t m_store_datasize;
	size_t m_store_begin;
	size_t m_store_end;
};

