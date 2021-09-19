// Efimenko.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>
#include "Fruit_Efimenko.h"
#include "Salad.h"
#include "utils.h"

using namespace std;

void PrintMenu()
{
	cout << '\n' << "1.Добавить фрукт на тарелку" << endl
		<< "2.Показать фрукты на тарелке" << endl
		<< "3.Считать из файла тарелку салата из фруктов" << endl
		<< "4.Сохранить тарелку салата" << endl
		<< "==========================" << endl
		<< "5.Записать рецепт салата" << endl
		<< "6.Показать рецепт салата" << endl
		<< "7.Сохранить рецепт в файл" << endl
		<< "8.Считать рецепт из файла" << endl
		<< "9.Удалить рецепт" << endl
		<< "0.Выход" << '\n' << endl
		<< "Выберите действие:";
}

int main()
{
	setlocale(LC_ALL, "rus");
	vector <Fruit_Efimenko> plate;
	vector <Salad> book;
	ofstream fout;
	ifstream fin;
	while (true)
	{
		PrintMenu();
		switch (getCorrectNumber(0, 9))
		{
		case 1:
		{
			Fruit_Efimenko Fruit;
			Fruit.enter();
			plate.push_back(Fruit);
			break;
		}
		case 2:
		{
			if (!plate.size() == 0) {
				for (auto& Fruit : plate)
				{
					Fruit.print();
				}
			}
			else cout << "Тарелка пуста" << endl;
			break;
		}
		case 3:
		{
			string data;
			fin.open("data.txt", ios::in);
			if (!fin.is_open()) {
				cout << "Ошибка при открытия файла" << endl;
				break;
			}
			while (getline(fin, data))
			{
				Fruit_Efimenko Fruit;
				Fruit.load(fin);
				plate.push_back(Fruit);
			}
			fin.close();
			break;
		}
		case 4:
		{
			fout.open("data.txt", ios::out);
			if (fout.is_open()) {
				if (plate.size() != 0) {
					for (Fruit_Efimenko Fruit : plate) {
						Fruit.save(fout);
					}  fout.close();
				}
				else cout << "Файл пуст" << endl;
			}
			else cout << "ошибка в открытии файла" << endl;
			break;
		}

		case 5:
		{
			Salad recipe;
			bool decision = true;
			recipe.enter();
			while (decision)
			{
				cout << "Добавьте фрукт" << endl;
				Fruit_Efimenko* ptr = new Fruit_Efimenko();
				ptr->enter();
				recipe.add_fruit(ptr);
				cout << "Добавить еще фрукт? 1-да 0-нет" << endl;
				cin >> decision;
			}
			book.push_back(recipe);
			break;
		}
		case 6:
		{
			if (book.size() == 0)
			{
				cout << "Рецептов нет" << endl;
				break;
			}
			for (auto& item : book)
				item.print();
			break;
		}
		case 7:
		{
			fout.open("data2.txt", ios::out);
			if (fout.is_open()) {
				if (book.size() == 0)
				{
					cout << "Нет рецептов" << endl;
					fout.close();
					break;
				}
				for (Salad item : book)
					item.save_recipe(fout);
				fout.close();
			}
			else cout << "ошибка в открытии файла" << endl;
			break;
		}

		case 8:
		{
			string data;
			fin.open("data2.txt", ios::in);
			if (!fin.is_open()) {
				cout << "Ошибка при открытия файла" << endl;
				break;
			}
			while (getline(fin, data))
			{
				Salad recipe;
				recipe.load_recipe(fin);
				book.push_back(recipe);
			}
			fin.close();
			break;
		}
		case 9:
		{
			for (auto& recipe : book)
			{
				recipe.delvec();
			}
			book.clear();
			break;
		}


		case 0: //выход
		{
			return 0;
		}
		default:
		{
			cout << "ошибка" << endl;
			break;
		}
		}
	}
	return 0;
}

