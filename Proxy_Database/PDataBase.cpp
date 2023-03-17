#include "PDataBase.h"
#include <ctime>
#include <sstream>

const std::string PDataBase::getDate() const
{
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    std::stringstream ss;

    ss << now->tm_year + 1900 << "/" << now->tm_mon + 1 << "/" << now->tm_mday << " "
        << (now->tm_hour < 10 ? "0" : "") << std::to_string(now->tm_hour) << ":"
        << (now->tm_min < 10 ? "0" : "") << std::to_string(now->tm_min) << " - ";
    return ss.str();
}

void PDataBase::cashToDataBase()
{
    std::string tmp;
    std::ifstream ifs(localDataBase);
    while (std::getline(ifs, tmp))
        try{dataBase->Log(tmp);}
    catch (const std::exception&)
    {
        ifs.close();
        throw;
    }
    ifs.close();
    std::ofstream ofs(localDataBase);
    ofs.close();
    isCashed = false;
}

PDataBase::~PDataBase()
{
    if (dataBase)
    {
        if (isCashed )
        {
            do
            {
                try { cashToDataBase(); }
                catch (const std::exception&)
                {
                    dataBase->Connect(dataBasePaht);
                }
            } while (isCashed);
        }
        delete dataBase;
    }
}

void PDataBase::Log(const std::string& message)
{
    if (!dataBase) loadDataBase();
    std::string dMessage = getDate() + message;
    try
    {
        if (isCashed) cashToDataBase();
        dataBase->Log(dMessage);
    }
    catch (const std::exception&)
    {
        std::ofstream ofs;
        ofs.open(localDataBase, std::ofstream::app);
        ofs << dMessage << std::endl;
        ofs.close();
        isCashed = true;
    }
}

void PDataBase::Connect(const std::string& connectionString)
{
    if (!dataBase) loadDataBase();
    try
    {
        dataBase->Connect(connectionString);
        dataBasePaht = connectionString;
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what();
    }
}

