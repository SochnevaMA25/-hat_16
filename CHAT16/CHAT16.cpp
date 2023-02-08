// CHAT16.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "Client.h"
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    string nick;
    string login;
    string pass;
    string companion;
   // string mes;
    int i = 0;
    int k = 0;
    Client cl;
    CHat ch;
    string line;
    cout << "Введите ник: " << endl;
    cin >> nick;
    cout << "Введите логин: " << endl;
    cin >> login;
    cout << "Введите пароль: " << endl;
    cin >> pass;
    cl.check(nick, login, pass);

    while (true) 
    {
        if (i == 0) {
            ch.get_mes(nick);
            cout << "Кому отправить сообщение? Введите ник: " << endl;
            cin >> companion;
            cout << "Введите сообщение: " << endl;
            string message_1 = "";
            string message_2 = "";
            cin >> message_1;

            getline(cin, message_2);
            string message_3 = message_1 + message_2;
            ch.send_mes(companion, nick, message_3);

        }
        else
        {
            cout << "Введите ник: " << endl;
            cin >> nick;
            cout << "Введите логин: " << endl;
            cin >> login;
            cout << "Введите пароль: " << endl;
            cin >> pass;
            cl.check(nick, login, pass);
            ch.get_mes(nick);
            cout << "Кому отправить сообщение? Введите ник: " << endl;
            cin >> companion;
            cout << "Введите сообщение: " << endl;
            string message_1 = "";
            string message_2 = "";
            cin >> message_1;

            getline(cin, message_2);
            string message_3 = message_1 + message_2;
            ch.send_mes(companion, nick, message_3);
           
        }
        cout << "Для выхода из чата нажмите 1" << endl;
        cin >> k;
        if (k == 1)
        {
            return false;
        }
        cout << "Остаться в системе? Да - введите 0 " << endl;
        cin >> i;
    }
 
    return 0;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
