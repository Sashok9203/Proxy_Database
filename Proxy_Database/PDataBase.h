#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "IDataBase.h"
#include "DataBase.h"
class PDataBase :  public IDataBase
{
private:
	bool isCashed;
	IDataBase& dataBase;
	const std::string localDataBase;
	std::string dataBasePaht;
	const std::string getDate() const;
	void cashToDataBase();
public:
	PDataBase(DataBase& database) :dataBase(database),isCashed(false),localDataBase("localTempDatabase.txt"), dataBasePaht("") {}
	~PDataBase();
	void Log(const std::string& message) override;
	bool IsConnected() { return dataBase.IsConnected(); }
	void Connect(const std::string& connectionString) override;
};

