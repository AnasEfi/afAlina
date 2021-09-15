#pragma once
#include <string>
#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;

class Fruit_Efimenko
{
public:
	int amount = 0; //параметры по умолчанию
	string name;
	double price = 0;

	void print()
	{
		cout << "Название: " << name << endl;
		cout << "Кол-во: " << amount << '\n' << "Цена: " << price << endl;
	}
	void enter()
	{
		cin.clear();
		cout << "Введите имя: ";
		cin >> name;
		cout << "Введите кол-во: ";
		cin >> amount;
		cout << "Введите стои-ть: ";
		cin >> price;
		cout << "Фрукт добавлен"<< endl;
	}
	void save(ofstream& fout)
	{
		fout << "fruit" <<'\n'<< name << '\n' << amount << '\n' << price << '\n';
	}
	void load(ifstream& fin)
	{
		getline(fin,name);
		fin >> amount;
		fin >> price;
		fin.ignore();
	}
};

