#pragma once
#include "IDataBase.h"
#include "DataBase.h"
class PDataBase :  public IDataBase
{
private:
	IDataBase& database;
public:
	PDataBase(DataBase& database) :database(database) {}
	void Log(const std::string& message) override;
};

