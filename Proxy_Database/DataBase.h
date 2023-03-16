#pragma once
#include "IDataBase.h"
#include <fstream>
#include <iostream>
class DataBase : public IDataBase
{
private:
	const std::string connectionString ;
	bool isConnected;
public:
	DataBase();
	bool IsConnected() { return isConnected; }
	void Connect(const std::string& connectionString);
	void Log(const std::string& message);
};

