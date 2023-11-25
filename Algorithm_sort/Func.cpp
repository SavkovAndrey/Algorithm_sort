#include <iostream>
#include <iomanip>
#include "Func.h"
using namespace std;

//------------------------- СОЗДАНИЕ МАССИВА
int *creat_mass(int size)
{
	int *mass = new int[size];
	return mass;
}

//------------------------- ЗАПОЛНЕНИЕ МАССИВА
void fill_mass(int* mass, int size)
{
	for (int i = 0; i < size; i++)
	{
		mass[i] = rand() % 21 - 10;
	}
}

//------------------------- ВЫВОД МАССИВА
void output_mass(int* mass, int size)
{
	cout << "\nМассив:\n";
	for (int i = 0; i < size; i++)
	{
		cout << setw(4) << mass[i];
	}
	cout << "\n\n";
}

//------------------------- ВЫВОД МЕНЮ
void menu()
{
	cout << "1 - перезаписать массив случайными числами\n";
	cout << "2 - вывести массив на экран\n";
	cout << "3 - сортировка ПУЗЫРЬКОВАЯ массива\n";
	cout << "0 - выход из программы\n\n";
	cout << "Сделайте ваш выбор: ";
}

//------------------------- СОРТИРОВКА:  ПУЗЫРЬКОВАЯ
void Bubble(int* mass, int size)
{
	int temp = 0;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			if (mass[j] > mass[j + 1])
			{
				temp = mass[j];
				mass[j] = mass[j + 1];
				mass[j + 1] = temp;
			}
		}
	}
}