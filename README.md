# -hat_mod16
Переработанная концепция чата с использованием шаблонов STL

////////////ИДЕЯ///////////////// 

--------------         
  регистрация          
--------------         
        (1)------------|
     |                 |
--------------         |
получение              |
сообщений              |
--------------         |
      |                |                 
--------------         |
отправка               |
сообщений              |
--------------         |
      |                |
      (1) -------------|

      РЕГИСТРАЦИЯ

    При регистрации пользователя идет запись в map m_user в формате пара:
	ник -> структура _Users(login/pass).
  Проверка на уже наличие такого пользователя в базе происходит на основе 
  поиска в map ника и сравнения логина, и пароля. Если ник и логин совпали, 
  но не совпал пароль, то пользователю объявляется о неправильном вводе. 
  Если совпадает ник, но не совпадает логин, то считается, что логин неверный. 
  Если же такого ника вообще нет, то заводится новая строчка и пользователь регистрируется. 

  ПОЛУЧЕНИЕ СООБЩЕНИЙ

    После инициализации пользователя проверяется есть ли сообщения для пользователя. 
  Если есть, то выводятся на экран. 

  ОТПРАВКА СООБЩЕНИЙ

    У пользователя спрашивают кому он хочет отправить сообщение. 
	
////////////Структура///////////////// 	
  
// структура пользователей (логин - пароль)
struct _Users 
{
	string login;
	string pass;
	_Users() {};
	_Users(string login, string pass) : login(login), pass(pass) {};
};

// структура сообщений (получатель - сообщение)
struct _Message
{
	string sender;
	string mes;
	_Message() {};
	_Message(string send, string m) : sender(send), mes(m) {};
};
// словарь пар (отправитель - структура сообщений)
typedef map <string, _Message> Mes; //recipient -> sender/mes
// словарь пар (ник пользователя - структура пользователей)
typedef map <string, _Users> m_user; //nick->login/pass

class Client
{	
private:
	m_user user;
	
public:
	Client();

	void check(string nickname, string login, string pass);		//проверка пользователя
	bool check_nick(string nick);
	bool check_login(string nickname, string login);
	bool check_pass(string nickname, string pass);
	void reg(string nickname, string login, string pass);		//регистрация
	void print();												//печать пользователей
};
class CHat :public Client
{
	Mes mes;
public: 
	CHat() {};
	void get_mes(string nickname);									//выдать сообщение
	void send_mes(string nickname, string send, string message);	//отправить
	bool check_mes(string nickname);								//проверка наличия сообщений для пользователя 
};
