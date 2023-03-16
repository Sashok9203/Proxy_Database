#pragma once
#include <string>
class IDataBase
{
public:
	virtual void Log(const std::string& message) = 0;
};

