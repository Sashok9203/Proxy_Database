

#include <iostream>
#include "User.h"
#include "PDataBase.h"
#include "DataBase.h"
int main()
{
    DataBase dataBase;
    PDataBase pDataBase(dataBase);
    User user(pDataBase);
    for (int i = 0; i < 20; i++)
        user.Log("Message #" + i);
}


