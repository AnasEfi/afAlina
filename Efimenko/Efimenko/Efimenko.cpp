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
	cout << "1.Добавить фрукт на тарелку" << endl
		<< "2.Показать фрукты на тарелке" << endl
		<< "3.Считать тарелку салата из фруктов" << endl
		<< "4.Сохранить тарелку салата" << endl
		<< "5.Записать рецепт салата" << endl
		<< "6.Получить рецепт салата" << endl

		<< "0.Выход" << endl
		<< "Выберите действие:";
}

int main()
{
	setlocale(LC_ALL, "rus");
	vector <Fruit_Efimenko> plate;
	vector<Fruit_Efimenko> for_recipe;
	vector <Salad> recipe2;
	ofstream fout;
	ifstream fin;
	while (true)
	{
		PrintMenu();
		switch (getCorrectNumber(0, 6))
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
			else cout << "ошибка" << endl;
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
				Fruit_Efimenko Fruit;
				Fruit_Efimenko* ptr = &Fruit;
				Fruit.enter();
				for_recipe.push_back(Fruit);
				recipe.salad.push_back(ptr);
				cout << "Добавить еще фркукт? 1-да 0-нет" << endl;
				cin >> decision;
			}
			recipe2.push_back(recipe);
			break;
		}
		case 6:
		{
			for (auto& item : recipe2)
			{
				item.print();
			}
			
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

