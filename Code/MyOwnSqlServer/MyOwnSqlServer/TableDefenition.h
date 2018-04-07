#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "BasicTypes.h"
#include "ExceptionDefenition.hpp"
/*
������ ��������� ������ �������� ����� ������� � ���� ������
�������� ������ ���� �������� � 
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
		vector<string*> Data; // ������ ��������� �� ����� �������
	public:

		TableDefenition(vector<BasicTypes::Type> &TypesOfColumns,vector<string> &NamesOfColumns);
		~TableDefenition();
		void AddString(vector<string> &Names);
		void DeleteString(string PK); // �������� ����� �� ���������� �����
		void DeleteString(int Id); // �������� ������ �� ��
		//testing temp functions
		void DumpTable();
	};
}

