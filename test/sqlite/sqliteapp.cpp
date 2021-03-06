#include "fakengine.h"
#include "sqliteapp.h"

bool sqliteapp::ini( int argc, char *argv[] )
{
	return true;
}

bool sqliteapp::heartbeat()
{
	sqlite3 * handle = 0;
	int ret = sqlite3_open("test.db", &handle);
	sqlite3_stmt *stmt;
	ret = sqlite3_prepare(handle, "select * from aaa", -1, &stmt, NULL);
	while (SQLITE_ROW == sqlite3_step(stmt)) 
	{
		stringc aa = (const char *)sqlite3_column_text(stmt, 0);
		int bb = sqlite3_column_int(stmt, 1);
		FUSE(bb);
	}
	sqlite3_finalize(stmt);
	sqlite3_close(handle);
	return true;
}

bool sqliteapp::exit()
{
	return true;
}

sqliteapp::sqliteapp() : mainapp("sqliteapp")
{

}
