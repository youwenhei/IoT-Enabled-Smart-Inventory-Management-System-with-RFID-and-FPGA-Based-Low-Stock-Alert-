#ifndef DATABASE_H
#define DATABASE_H
#pragma once
#include <jdbc/mysql_driver.h>
#include <jdbc/mysql_connection.h>

class Database {
private:
	sql::mysql::MySQL_Driver* driver;
	sql::Connection* con;

public:
	Database();
	~Database();

	sql::Connection* getConnection() const;

	bool isConnected();
};

#endif
