#pragma once
#include <string>
#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;

class Fruit_Efimenko
{
public:
	int amount = 0; //��������� �� ���������
	string name;
	double price = 0;

	void print()
	{
		cout << "��������: " << name << endl;
		cout << "���-��: " << amount << '\n' << "����: " << price << endl;
	}
	void enter()
	{
		cin.clear();
		cout << "������� ���: ";
		cin >> name;
		cout << "������� ���-��: ";
		cin >> amount;
		cout << "������� ����-��: ";
		cin >> price;
		cout << "����� ��������"<< endl;
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

