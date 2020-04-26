#pragma once
#include <iostream>
using namespace std;

class SString {
public:
	SString();

	SString(char b, int leng);

	SString(SString& a);
	
	SString(const char* tstr);

	~SString();

	char* get_s() //осуществляем доступ к закрытому полю init
	{
		return init;
	}
	int get_l()//осуществляем доступ к закрытому полю length
	{
		return length;
	}
	void set_s(const char* s);//устанавливаем значение для s

	friend SString operator +(SString& a, SString& b);

	SString& operator =(const SString& a);

	void complete(SString& a, SString& b)
	{

		init = new char[a.get_l() + 1 + b.get_l()];//создаем массив размера [...]
		length = a.get_l() + b.get_l();//длина самой строки 
		size = a.get_l() + 1 + b.get_l(); //длина строки + \0
		for (int i = 0; i < a.get_l(); i++) init[i] = a.get_s()[i];
		for (int i = 0; i < b.get_l(); i++) init[i + a.get_l()] = b.get_s()[i];
		init[a.get_l() + b.get_l()] = 0;
	}

	friend bool operator == (SString& a, SString& b);

	friend bool operator <(SString& a, SString& b);

	friend bool operator >(SString& a, SString& b);

	char& operator [](const int index);

	friend ostream& operator <<(ostream& out, SString& a);

	friend istream& operator >> (istream& in, SString& b);

	char* find(const char* e);

	char* find_c(char* c);

	void Tstrtok(char* c);

private:
	char* init;
	int length;
	int size;
};
