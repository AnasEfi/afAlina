#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "Fruit_Efimenko.h"
using namespace std;

class Salad
{
public:
	string causin;
	string name;

 vector <Fruit_Efimenko*> salad;

	void add_fruit(Fruit_Efimenko* subject)
	{
		salad.push_back(subject);
	}
	
	void print()
	{
		if (!salad.size() == 0)
		{
			cout << "Название салата: " << name << '\n' << "Название кухни: " << causin << endl;
			cout << "Ингредиенты: ";

			for (auto& ptr:salad)
			{
				cout << "Фрукт" << ptr->name << '\n' << "Кол-во: " << ptr->amount << '\n' << "Цена:" << ptr->price << endl;
			}
		} else cout << "рецептов нет" << endl;
	}
	void enter()
	{
		cin.clear();
		cout << "Введите название салата: ";
		cin >> name;
		cout << "Введите название национальной кухни: ";
		cin >> causin;
	}

	int getSize()
	{
		return salad.size();
	}
};
