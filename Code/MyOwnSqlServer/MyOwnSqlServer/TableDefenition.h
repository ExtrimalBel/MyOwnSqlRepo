#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "BasicTypes.h"
#include "ExceptionDefenition.hpp"
/*
Данный заголовок задает описание одной таблицы в базе данных
Содержит массив имен столбцов и 
*/
using namespace std;

namespace BaseLogicDef
{

	class TableDefenition
	{
		string TableName;
		/*Defined Caption of Table*/
		vector<BasicTypes::Type> TypesOfColumns;
		vector<string> NamesOfColumns;
		int CountOfColumns;
		vector<string*> Data; // Хранит указатели на сроки таблицы
	public:

		TableDefenition(vector<BasicTypes::Type> &TypesOfColumns,vector<string> &NamesOfColumns);
		~TableDefenition();
		void AddString(vector<string> &Names);
		void DeleteString(string PK); // Удаление стоки по первичному ключу
		void DeleteString(int Id); // Удаление строки по ид
		//testing temp functions
		void DumpTable();
	};
}

