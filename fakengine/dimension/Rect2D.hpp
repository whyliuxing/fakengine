#pragma once

#include "dimension/Point2D.hpp"
#include "dimension/Size2D.hpp"

template <typename T> class rect2d
{
    
    public:
        
        force_inline rect2d() :
            Left    (0),
            Right   (0),
            Top     (0),
            Bottom  (0)
        {
        }
        force_inline rect2d(T X, T Y) :
            Left    (X),
            Right   (X),
            Top     (Y),
            Bottom  (Y)
        {
        }
        force_inline rect2d(T NewLeft, T NewTop, T NewRight, T NewBottom) :
            Left    (NewLeft    ),
            Right   (NewRight   ),
            Top     (NewTop     ),
            Bottom  (NewBottom  )
        {
        }
        force_inline rect2d(const rect2d<T> &Other) :
            Left    (Other.Left     ),
            Right   (Other.Right    ),
            Top     (Other.Top      ),
            Bottom  (Other.Bottom   )
        {
        }
        force_inline ~rect2d()
        {
        }
        
        /* === Operators === */
        
        force_inline bool operator == (const rect2d<T> &other) const
        {
            return Left == other.Left && Top == other.Top && Right == other.Right && Bottom == other.Bottom;
        }
        force_inline bool operator != (const rect2d<T> &other) const
        {
            return Left != other.Left && Top != other.Top && Right != other.Right && Bottom != other.Bottom;
        }
        
        force_inline rect2d<T> operator + (const rect2d<T> &other) const
        {
            return rect2d<T>(Left + other.Left, Top + other.Top, Right + other.Right, Bottom + other.Bottom);
        }
        force_inline rect2d<T>& operator += (const rect2d<T> &other)
        {
            Left += other.Left; Top += other.Top; Right += other.Right; Bottom += other.Bottom; return *this;
        }
        
        force_inline rect2d<T> operator - (const rect2d<T> &other) const
        {
            return rect2d<T>(Left - other.Left, Top - other.Top, Right - other.Right, Bottom - other.Bottom);
        }
        force_inline rect2d<T>& operator -= (const rect2d<T> &other)
        {
            Left -= other.Left; Top -= other.Top; Right -= other.Right; Bottom -= other.Bottom; return *this;
        }
        
        force_inline rect2d<T> operator / (const rect2d<T> &other) const
        {
            return rect2d<T>(Left / other.Left, Top / other.Top, Right / other.Right, Bottom / other.Bottom);
        }
        force_inline rect2d<T>& operator /= (const rect2d<T> &other)
        {
            Left /= other.Left; Top /= other.Top; Right /= other.Right; Bottom /= other.Bottom; return *this;
        }
        
        force_inline rect2d<T> operator * (const rect2d<T> &other) const
        {
            return rect2d<T>(Left * other.Left, Top * other.Top, Right * other.Right, Bottom * other.Bottom);
        }
        force_inline rect2d<T>& operator *= (const rect2d<T> &other)
        {
            Left *= other.Left; Top *= other.Top; Right *= other.Right; Bottom *= other.Bottom; return *this;
        }
        
        force_inline rect2d<T> operator - () const
        {
            return rect2d<T>(-Left, -Top, -Right, -Bottom);
        }
        
        /* === Functions === */
        
        //! Sets the rectangle's size.
        force_inline void setSize(const size2d<T> &Size)
        {
            Right   = Left  + Size.Width;
            Bottom  = Top   + Size.Height;
        }
        //! Returns the rectangle's size.
        force_inline size2d<T> getSize() const
        {
            return size2d<T>(Right - Left, Bottom - Top);
        }
        
        //! Sets the rectangle's center point.
        force_inline void setCenter(const point2d<T> &Center)
        {
            *this += rect2d<T>(Center - getCenter());
        }
        //! Returns the rectangle's center point.
        force_inline point2d<T> getCenter() const
        {
            return point2d<T>((Right + Left)/2, (Bottom + Top)/2);
        }
        
        //! Sets the left-top point.
        force_inline void setLTPoint(const point2d<T> &Point)
        {
            Left    = Point.X;
            Top     = Point.Y;
        }
        //! Returns the left-top point.
        force_inline point2d<T> getLTPoint() const
        {
            return point2d<T>(Left, Top);
        }
        
        //! Sets the right-bottom point.
        force_inline void setRBPoint(const point2d<T> &Point)
        {
            Right   = Point.X;
            Bottom  = Point.Y;
        }
        //! Returns the right-bottom point.
        force_inline point2d<T> getRBPoint() const
        {
            return point2d<T>(Right, Bottom);
        }
        
        //! Returns the rectangle's width (Right - Left).
        force_inline T getWidth() const
        {
            return Right - Left;
        }
        //! Returns the rectangle's height (Bottom - Top).
        force_inline T getHeight() const
        {
            return Bottom - Top;
        }
        //! Returns true if all four components are 0.
        force_inline bool empty() const
        {
            return Left == Right == Top == Bottom == 0;
        }
        //! Returns true if this is a valid rectangle.
        force_inline bool valid() const
        {
            return getWidth() >= 0 && getHeight() >= 0;
        }
        
        force_inline rect2d<T>& repair()
        {
            if (Left > Right)
                Swap(Left, Right);
            if (Top > Bottom)
                Swap(Top, Bottom);
            return *this;
        }
        
        force_inline bool overlap(const point2d<T> &Point) const
        {
            return (Point.X >= Left && Point.X < Right && Point.Y >= Top && Point.Y < Bottom);
        }
        force_inline bool overlap(const rect2d<T> &other) const
        {
            return (Bottom > other.Top && Top < other.Bottom && Right > other.Left && Left < other.Right);
        }
        
        template <typename B> force_inline rect2d<B> cast() const
        {
            return rect2d<B>(static_cast<B>(Left), static_cast<B>(Top), static_cast<B>(Right), static_cast<B>(Bottom));
        }
        
        /* === Members === */
        
        T Left, Right, Top, Bottom;
        
};

typedef rect2d<int32_t> rect2di;
typedef rect2d<float> rect2df;

// ================================================================================

