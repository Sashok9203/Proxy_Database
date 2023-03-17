#include <iostream>
#include "User.h"
#include "PDataBase.h"
#include "DataBase.h"

int main()
{
    User user(new PDataBase());
    for (int i = 0; i < 20; i++)
    {
        try{user.Log("database.txt", "Message #" + std::to_string(i+1));}
        catch (const std::exception& ex)
        {
            std::cout << ex.what()<<std::endl;
        }
    }
    std::cout << " All messages sended to database....";
}


