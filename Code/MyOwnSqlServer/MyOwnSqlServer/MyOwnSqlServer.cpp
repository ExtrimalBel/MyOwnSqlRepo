// MyOwnSqlServer.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "UsersController.h"
#include <iostream>
int main()
{
	
		UtilsSpace::UsersController UC = UtilsSpace::UsersController::GetInstance();
	UC.CreateUser("Vasya", "porn1234", UtilsSpace::User);
		cout << UC.ChechAuth("Vasya", "14523456789");
		cout << UC.ChechAuth("admin", "123456789");
		//UC.DeleteUser("Vasya");
    return 0;
}

