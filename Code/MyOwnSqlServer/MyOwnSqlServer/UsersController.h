#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "md5.h"
#include "ExceptionDefenition.hpp"
#include <algorithm>
/*
Класс хранит данные о пользователях
Позволяет создавать изменять данные о пользователях
А также предоставляет функционал авторизации
Реализован паттерн синглетон
*/
using namespace std;
namespace UtilsSpace
{
	typedef enum { Admin, User } UserState;
	struct UserDef 
	{
		UserState State;
		string UserName;
		string PassHash;
		UserDef(string UserName, string Password, UserState State)
		{
			this->UserName = UserName;
			this->PassHash = md5(Password);
			this->State = State;
		}
		UserDef() {}
	};
	class UsersController
	{
		vector<UserDef> UsersDb; // Хранит записи о пользователях
		
		UsersController();
		void WriteUserDbToFile(); // Записывает данные о пользователях в файл. Вызывается при изменении UserDb
	public:
		static UsersController& GetInstance()
		{
			static UsersController s;
			return s;
		}
		~UsersController();
		// Методы работы с пользователями
		// 
		void CreateUser(string UserName, string Password, UserState State);
		void ChangePassword(string UserName, string Password);
		void DeleteUser(string UserName);
		bool ChechAuth(string UserName, string Password);
		UserDef GetUserStruct(string UserName);
		//UsersController(UsersController &const);
		UsersController& operator= (UsersController const&);
	};

#include <type_traits>

	template<typename T>
	typename std::enable_if<std::is_enum<T>::value, std::istream&>::type
		operator >>(std::istream &is, T& enumVar)
	{
		//std::cout << "enum\n"; // just to see it is this one that gets used
		int intVal;
		is >> intVal;
		enumVar = static_cast<T>(intVal); // note the explicit cast to make it legal
		return is;
	}
}