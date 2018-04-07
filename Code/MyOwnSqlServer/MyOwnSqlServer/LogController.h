#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "ExceptionDefenition.hpp"
/*
Класс реализует функционал логгирования действий производимых программой
Реализован паттерн одиночка

*/
using namespace std;


namespace UtilsSpace
{
	class LogController
	{
	public:

		static LogController& GetLogController()
		{
			return GetLogController("Log.txt");
		}
		static LogController& GetLogController(string FileName)
		{
			static LogController s(FileName);
			return s;
		}
		void WriteMessage(string Message);
	private:
		ofstream FileObject;
		static LogController *Instance;
		LogController(string FileName);
		LogController(LogController &const) = delete;
		LogController& operator= (LogController const&) = delete;
		~LogController();
	};
}


