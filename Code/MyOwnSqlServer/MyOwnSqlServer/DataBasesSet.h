#pragma once
#include <vector>
#include "ExceptionDefenition.hpp"
#include <string>
/*
����� ��������� �������� ����� �������������� � �������
����� ������ ����� ��������������� ����� ��������� ������
������ ��������� ��������������� � ���
������������ ���������� �������� ������ ��������� � �������� ������ ������� ����������� ������ ���� ������� � �������� �����
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
		void ProcessOperation(); // ����� 
		DataBasesSet();
		~DataBasesSet();
	};
}

