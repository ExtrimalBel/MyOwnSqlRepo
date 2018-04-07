#pragma once
#include <iostream>
#include <string>

using namespace std;
namespace Exceptions
{
	class BaseException
	{
	public:
		string Message;
		BaseException(string Message)
		{
			this->Message = Message;
		}
	};

	class WrongStringAdded : public BaseException
	{
	public:
		WrongStringAdded(string Message) : BaseException(Message) {}
	};

	class TableCreateError : public BaseException
	{
	public:
		TableCreateError(string Message) : BaseException(Message) {}
	};

	class FileNotOpended : public BaseException
	{
	public:
		FileNotOpended(string Message) : BaseException(Message) {}
	};

	class FileIOError : public BaseException
	{
	public:
		FileIOError(string Message) : BaseException(Message) {}
	};

	class UserNotFound : public BaseException
	{
	public:
		UserNotFound(string Message) : BaseException(Message) {}
	};

	class UserPasswordIncorrect : public BaseException
	{
		UserPasswordIncorrect(string Message) : BaseException(Message) {}
	};

	class FileReadError : public BaseException
	{
	public:
		FileReadError(string Message) : BaseException(Message) {}
	};

	class UserNameAlreadyExist : public BaseException
	{
	public:
		UserNameAlreadyExist(string Message) : BaseException(Message) {}
	};
	class CreateUserPassIncorrect : public BaseException
	{
	public:
		CreateUserPassIncorrect(string Message) : BaseException(Message) {}
	};
}

