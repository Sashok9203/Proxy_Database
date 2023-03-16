#include "DataBase.h"

DataBase::DataBase() :connectionString("database.txt"), isConnected(false){}

void DataBase::Connect(const std::string& connectionString)
{
	if (this->connectionString != connectionString) throw std::exception(" Error database path...");
	isConnected =  (rand() % 10) < 6;
}

void DataBase::Log(const std::string& message)
{
	std::ofstream ofs;
	ofs.open(connectionString, std::ofstream::app);
	if (!ofs) throw std::exception(" Data base error...");
	ofs << message << std::endl;
	ofs.close();
}



