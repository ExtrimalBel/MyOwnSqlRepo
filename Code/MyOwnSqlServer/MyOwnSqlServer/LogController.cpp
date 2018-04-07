#include "stdafx.h"
#include "LogController.h"

using namespace std;

namespace UtilsSpace
{

	LogController::LogController(string FileName)
	{
		FileObject.open(FileName);
		if (!FileObject.is_open()) throw Exceptions::FileNotOpended("Невозможно открыть файл лога для записи");
	}


	LogController::~LogController()
	{
		FileObject.close();
	}

	void LogController::WriteMessage(string Message)
	{
		FileObject << Message << endl;
	}
}