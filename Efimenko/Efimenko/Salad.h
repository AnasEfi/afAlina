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
		cout << '\n'<< "+++++++++++++++++++++++" << endl;
		cout << "�������� ������: " << name << '\n' << "�������� �����: " << causin << endl;
		cout << "�����������: " << endl;

		for (auto& ptr : salad)
		{
			cout << "�����: " << ptr->name << '\n' << "���-��: " << ptr->amount << '\n' << "����:" << ptr->price << endl;
		}
		cout << "+++++++++++++++++++++++" << '\n' <<endl;

	}
	void enter()
	{
		cin.clear();
		cout << "������� �������� ������: ";
		cin >> name;
		cout << "������� �������� ������������ �����: ";
		cin >> causin;
	}

	void save_recipe(ofstream& fout)
	{
		
		fout << "recipe" << '\n' << name << '\n' << causin << '\n';
		for (auto& ptr : salad)
		fout<<"Fruit"<<'\n' << ptr->name << '\n' << ptr->amount << '\n' << ptr->price << endl;
	}
	void load_recipe(ifstream& fin)
	{
		string data;
		getline(fin, name);
		getline(fin, causin);
		while (getline(fin, data))
		{
			Fruit_Efimenko* ptr = new Fruit_Efimenko();
			getline(fin, ptr->name);
			fin >> ptr->amount;
			fin >> ptr->price;
			fin.ignore();
			salad.push_back(ptr);
		}
	}
	void delvec()
	{
		for (auto& ptr: salad)
			delete ptr;
	}
};
