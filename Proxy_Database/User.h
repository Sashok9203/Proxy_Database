#pragma once
#include "IDataBase.h"
class User
{
private:
	IDataBase& database;
public:
	User(IDataBase& database) :database(database) {}
	void Log(const std::string& dataBasePath, const std::string& message) { database.Connect(dataBasePath); database.Log(message); }
};

