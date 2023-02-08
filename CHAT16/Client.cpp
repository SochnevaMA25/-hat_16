#include "Client.h"
#include <vector>
#include <string>
using namespace std;

Client::Client() {};
//----------------------------------------
// Function...... check
// Description... проверка пользователя 
// Note.......... 
// Parameters:
//  I nickname - ник пользователя
//  I login - логин пользователя
//  I pass - пароль
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
                cout << "Вы успешно вошли! " << endl;
                
            }
            else
            {
                cout << "Неверный пароль! " << endl;
            }
        }
        else
        {
            cout << "Неверный логин! " << endl;
        }
    }
    else
    {
        reg(nickname, login, pass);
    }
}
//----------------------------------------
// Function...... check_nick
// Description... проверка есть ли такой ник 
// Note.......... 
// Parameters:
//  I nickname - ник пользователя
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
// Description... проверка есть ли такой логин 
// Note.......... 
// Parameters:
//  I nickname - ник пользователя
//  I login - логин пользователя
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
// Description... сверка пароля
// Note.......... 
// Parameters:
//  I nickname - ник пользователя
//  I pass - пароль пользователя
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
// Description... регистрация
// Note.......... 
// Parameters:
//  I nickname - ник пользователя
//  I login - логин пользователя
//  I pass - пароль
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
// Description... печать всех пользователей
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
// Description... выдача сообщений
// Note.......... 
// Parameters:
//  I nickname - ник пользователя
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
        cout << "Новых сообщений нет! " << endl;
    }
}
//----------------------------------------
// Function...... send_mes
// Description... отправка сообщения
// Note.......... 
// Parameters:
//  I nickname - ник получателя
//  I sender - логин пользователя
//  I message - сообщение
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
// Description... проверка есть ли сообщение
// Note.......... 
// Parameters:
//  I nickname - ник получателя
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
