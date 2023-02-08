#include "Client.h"
#include <vector>
#include <string>
using namespace std;

Client::Client() {};
//----------------------------------------
// Function...... check
// Description... �������� ������������ 
// Note.......... 
// Parameters:
//  I nickname - ��� ������������
//  I login - ����� ������������
//  I pass - ������
// Return: void
// Change History:
//----------------------------------------
void Client::check(string nickname, string login, string pass)
{
    if (check_nick(nickname) == true)
    {
        if (check_login(nickname, login) == true)
        {
            if (check_pass(nickname, pass) == true)
            {
                cout << "�� ������� �����! " << endl;
                
            }
            else
            {
                cout << "�������� ������! " << endl;
            }
        }
        else
        {
            cout << "�������� �����! " << endl;
        }
    }
    else
    {
        reg(nickname, login, pass);
    }
}
//----------------------------------------
// Function...... check_nick
// Description... �������� ���� �� ����� ��� 
// Note.......... 
// Parameters:
//  I nickname - ��� ������������
// Return: bool
// Change History:
//----------------------------------------
bool Client::check_nick(string nick)
{
    map <string, _Users>:: iterator it = user.find(nick);
    if (it != user.end())
        return true;

    return false;
    
}
//----------------------------------------
// Function...... check_login
// Description... �������� ���� �� ����� ����� 
// Note.......... 
// Parameters:
//  I nickname - ��� ������������
//  I login - ����� ������������
// Return: bool
// Change History:
//----------------------------------------
bool Client::check_login(string nickname, string login)
{
    for (int i = 0; i < user.size(); ++i) {
        if (user[nickname].login == login)
            return true;
    }
    return false;
}
//----------------------------------------
// Function...... check_login
// Description... ������ ������
// Note.......... 
// Parameters:
//  I nickname - ��� ������������
//  I pass - ������ ������������
// Return: bool
// Change History:
//----------------------------------------
bool Client::check_pass(string nick, string pass)
{
   for (int i = 0; i < user.size(); ++i) {
        if (user[nick].pass == pass)
            return true;
    }
    return false;
}
//----------------------------------------
// Function...... reg
// Description... �����������
// Note.......... 
// Parameters:
//  I nickname - ��� ������������
//  I login - ����� ������������
//  I pass - ������
// Return: void
// Change History:
//----------------------------------------
void Client::reg(string nickname, string login, string pass)
{
    _Users u(login, pass);
    user.insert({ nickname, u });
}
//----------------------------------------
// Function...... print
// Description... ������ ���� �������������
// Note.......... 
// Return: void
// Change History:
//----------------------------------------
void Client::print()
{
    cout << user.size() << endl;
    cout << "Print: " << endl;
    for (map<string, _Users>::iterator it = user.begin(); it != user.end(); ++it)
    {
        cout << it->first << it->second.login << it->second.pass << endl;
    }

}
//----------------------------------------
// Function...... get_mes
// Description... ������ ���������
// Note.......... 
// Parameters:
//  I nickname - ��� ������������
// Return: void
// Change History:
//----------------------------------------
void CHat::get_mes(string nickname)
{
    if (check_mes(nickname) == true) 
    {
        cout << mes[nickname].sender << ": " << mes[nickname].mes << endl;
        mes.erase(nickname);
    }
    else
    {
        cout << "����� ��������� ���! " << endl;
    }
}
//----------------------------------------
// Function...... send_mes
// Description... �������� ���������
// Note.......... 
// Parameters:
//  I nickname - ��� ����������
//  I sender - ����� ������������
//  I message - ���������
// Return: void
// Change History:
//----------------------------------------
void CHat::send_mes(string nickname, string sender, string message)
{
    _Message m_message(sender, message);
    mes.insert({ nickname, m_message });
}
//----------------------------------------
// Function...... check_mes
// Description... �������� ���� �� ���������
// Note.......... 
// Parameters:
//  I nickname - ��� ����������
// Return: bool
// Change History:
//----------------------------------------
bool CHat::check_mes(string nickname)
{
    map <string, _Message>::iterator it = mes.find(nickname);
    if (it != mes.end())
        return true;

    return false;
}
