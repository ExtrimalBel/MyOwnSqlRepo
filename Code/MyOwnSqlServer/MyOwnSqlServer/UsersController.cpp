#include "stdafx.h"
#include "UsersController.h"
namespace UtilsSpace
{

	UsersController::UsersController()
	{
		//������ ������ � �������������
		string ErrorMessage = "���������� ��������� ����";
		int UserCount;
		ifstream infile;
		infile.open("users.txt");
		if (!infile.is_open()) throw Exceptions::FileNotOpended(ErrorMessage);
		if (!(infile >> UserCount)) throw Exceptions::FileReadError(ErrorMessage);
		UsersDb.resize(UserCount,UserDef());
		for (int i = 0; i < UserCount;i++)
		{
			if (!(infile >> UsersDb[i].State)) throw Exceptions::FileReadError(ErrorMessage);
			if (!(infile >> UsersDb[i].UserName)) throw Exceptions::FileReadError(ErrorMessage);
			if (!(infile >> UsersDb[i].PassHash)) throw Exceptions::FileReadError(ErrorMessage);
		}
	}


	void UsersController::CreateUser(string UserName, string Password, UserState State)
	{
		// �������� ���� �� ����� ������������ � ����
		for (UserDef x : UsersDb)
		{
			if (UserName == x.UserName) throw Exceptions::UserNameAlreadyExist("����� ����������� ��� ����������");
		}
		// �������� ������ �� �������������
		if (Password.size() < 6) throw Exceptions::CreateUserPassIncorrect("������ ������� ���");
		
		UsersDb.push_back(UserDef(UserName,Password,State)); // ��������� ������ � ������������
		// ��������������� ������ � ����
		WriteUserDbToFile();
	}

	void UsersController::WriteUserDbToFile()
	{
		ofstream outfile;
		outfile.open("users.txt",ofstream::out | ofstream::trunc);
		if (!outfile.is_open()) throw Exceptions::FileIOError("���������� ������� ���� ��� ������");
		int UsersCount = UsersDb.size();
		outfile << UsersCount << endl;
		for (int i = 0; i < UsersCount;i++)
		{
			outfile << UsersDb[i].State << endl;
			outfile << UsersDb[i].UserName << endl;
			outfile << UsersDb[i].PassHash << endl;
		
		}
		outfile.close();
	}


	bool UsersController::ChechAuth(string UserName,string Password)
	{
		string temphash = md5(Password);
		for (UserDef x : UsersDb)
		{
			if (x.UserName == UserName && x.PassHash == temphash) return true;
		}
		return false;
	}

	void UsersController::ChangePassword(string UserName, string Password)
	{
		std::for_each(UsersDb.begin(), UsersDb.end(), [&UserName, &Password](UserDef &x)
		{
			if (x.UserName == UserName)
			{
				x.PassHash = md5(Password);
			}
		});
	}

	void UsersController::DeleteUser(string UserName)
	{
		for (unsigned int i = 0; i < UsersDb.size();i++)
		{
			if (UsersDb[i].UserName == UserName)
			{
				UsersDb.erase(UsersDb.begin() + i);
				WriteUserDbToFile();
				return;
			}
		}
		throw Exceptions::UserNotFound("���������� ������� ������������");
	}

	UserDef UsersController::GetUserStruct(string UserName)
	{
		for (UserDef x : UsersDb)
		{
			if (x.UserName == UserName) return x;
		}
		throw Exceptions::UserNotFound("������������ �� ������");
	}
	UsersController::~UsersController()
	{
	}
}