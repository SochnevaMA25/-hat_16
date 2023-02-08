#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;
struct _Users 
{
	string login;
	string pass;
	_Users() {};
	_Users(string login, string pass) : login(login), pass(pass) {};
};
struct _Message
{
	string sender;
	string mes;
	_Message() {};
	_Message(string send, string m) : sender(send), mes(m) {};
};
typedef map <string, _Message> Mes; //recipient -> sender/mes
typedef map <string, _Users> m_user; //nick->login/pass

class Client
{	
private:
	m_user user;
	
public:
	Client();

	void check(string nickname, string login, string pass);
	bool check_nick(string nick);
	bool check_login(string nickname, string login);
	bool check_pass(string nickname, string pass);
	void reg(string nickname, string login, string pass);
	string get_nickname();
	void print();
};
class CHat :public Client
{
	Mes mes;
public: 
	CHat() {};
	void get_mes(string nickname);		//отдать
	void send_mes(string nickname, string send, string message);	//отправить
	bool check_mes(string nickname);
};
