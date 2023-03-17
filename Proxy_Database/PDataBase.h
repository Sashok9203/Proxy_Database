#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "IDataBase.h"
#include "DataBase.h"
class PDataBase :  public IDataBase
{
private:
	bool isCashed;
	DataBase* dataBase;
	const std::string localDataBase;
	std::string dataBasePaht;
	const std::string getDate() const;
	void cashToDataBase();
	void loadDataBase() { dataBase = new DataBase(); }
public:
	PDataBase() :isCashed(false),localDataBase("localTempDatabase.txt"), dataBasePaht(""),dataBase(nullptr) {}
	~PDataBase();
	void Log(const std::string& message) override;
	void Connect(const std::string& connectionString) override;
};

