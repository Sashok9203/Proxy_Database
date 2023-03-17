#pragma once
#include <string>
class IDataBase
{
public:
	virtual ~IDataBase() {}
	virtual void Log(const std::string& message) = 0;
	virtual void Connect(const std::string& connectionString) = 0;
};

