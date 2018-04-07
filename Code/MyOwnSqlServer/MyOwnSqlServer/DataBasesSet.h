#pragma once
#include <vector>
#include "ExceptionDefenition.hpp"
#include <string>
/*
Класс описывает оснвоной класс взаимодействия с данными
Через данный класс осуществляеться любое изменение таблиц
Данные храняться непосредственно в ОЗУ
Предусмотрен простейший механизм отката изменений в отдельно взятой таблицу посредством чтения этой таблицы с жесткого диска
*/

namespace LogicDef
{

	struct Responce
	{
		int Code;
		
	};
	class DataBasesSet
	{

	public:
		void ProcessOperation(); // Метод 
		DataBasesSet();
		~DataBasesSet();
	};
}

