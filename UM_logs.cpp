
// Домашнее задание 18.12 Евгений Нуриев.
// Работал из по VS.
// Поэтому:
// Как бы я выдал права доступа
// chmod 700 /usr/logs/user_logs
// chmod 700 /usr/logs/nessage_logs
//
// Запись логов пользовтеля сделана для удобства работы в эмуляторе, либо в терминале.


#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class User {
public:
	//Запись логов пользователей
	void write_logs() {
		ofstream file;
		file.open("D:/user_logs.txt", ios::app);
		if (file.is_open()) {

			cout << "Enter your Name: ";
			cin >> name;
			cout << "Enter your Login: ";
			cin >> login;
			cout << "Enter your Password: ";
			cin >> password;
			file << name << ":" << login << ":" << password << endl;
			file.close();
		}
		else {
			cout << "The file of logs users isn't open!" << endl;
		}

	}
	//Чтение логов пользователей
	void read_logs() {
		ifstream file;
		file.open("D:/user_logs.txt");
		if (file.is_open()) {
			string str;
			while (getline(file,str)) {
				cout << str <<endl;
			}
			file.close();
		}
		

	}
private:
	string name;
	string login;
	string password;

};
class Message {
public:
	//Запись логов сообщений
	void text_logs() {
		ofstream m_logs;
		m_logs.open("D://message_logs.txt", ios::app);
		if (m_logs.is_open()) {
			
			cout << "Text your message: " << endl;
			getline(cin,text,'.');// Здесь я поставил сепаратор ТОЧКУ
			cout << "Enter of sender: " << endl;
			cin >> sender;
			cout << "Enter of receiver: " << endl;
			cin >> receiver;
			m_logs << "[ Message: \"" << text << "\" From:" << sender << " To:" << receiver << " ]" << endl;
			m_logs.close();
		}
		else {
			cout << "The file of logs messages isn't open!" << endl;
		}

	}
	//Чтение логов сообщений
	void read_logs() {
		ifstream r_logs;
		r_logs.open("D://message_logs.txt");
		if (r_logs.is_open()) {
			string str;
			while (getline(r_logs,str)) {
				cout << str << endl;
			}
		}
		else {
			cout << "The file of logs messages isn't open!" << endl;
		}

	}
private:
	string text;
	string sender;
	string receiver;

};
//Главная программа логов, с которой все начинается
class Logs {
public:
	Logs() {
		menu();
	}
	
	void menu() {
		int ch = 0;
		bool exit = false;
		while (!exit) {
			cout << "\n---Writing logs users and messages---\n" << endl;
			cout << "What do you want ?" << endl;
			cout << "1. Write message" << endl;
			cout << "2. Read out logs messages" << endl;
			cout << "3. Write out logs of users" << endl;
			cout << "4. Read out logs of users" << endl;
			cout << "0. EXIT" << endl;
			cin >> ch;
			switch (ch) {
			case 0: {
				exit = true;
				break;
			}
			case 1: {
				Message m;
				m.text_logs();
				break;
			}
			case 2: {
				Message m;
				m.read_logs();
				break; 
			}
			case 3: {
				User u;
				u.write_logs();
				break;
			}
			case 4: {
				User u;
				u.read_logs();
					break;
			}
			default: 
				break;
			}
		}
	}
};

int main()
{
	Logs log;
}

