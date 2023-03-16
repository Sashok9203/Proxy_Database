#pragma once
#include "IDataBase.h"
class User
{
private:
	IDataBase& database;
public:
	User(IDataBase& database) :database(database) {}
	void Log(const std::string& message) { database->Log(message); }
};

