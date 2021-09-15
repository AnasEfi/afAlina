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
			cout << "�������� ������: " << name << '\n' << "�������� �����: " << causin << endl;
			cout << "�����������: ";

			for (auto& ptr:salad)
			{
				cout << "�����" << ptr->name << '\n' << "���-��: " << ptr->amount << '\n' << "����:" << ptr->price << endl;
			}
		} else cout << "�������� ���" << endl;
	}
	void enter()
	{
		cin.clear();
		cout << "������� �������� ������: ";
		cin >> name;
		cout << "������� �������� ������������ �����: ";
		cin >> causin;
	}

	int getSize()
	{
		return salad.size();
	}
};
