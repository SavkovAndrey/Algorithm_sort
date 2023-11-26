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
	cout << "\nВы перезаписали массив новыми случайными данными!\n\n";
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
	cout << "1 - показать МЕНЮ\n";
	cout << "2 - перезаписать массив случайными числами\n";
	cout << "3 - вывести массив на экран\n";
	cout << "4 - сортировка ПУЗЫРЬКОВАЯ массива\n";
	cout << "5 - сортировка ПО ВЫБОРУ\n";
	cout << "0 - выход из программы\n\n";
}

//------------------------- ВЫВОД ПОДМЕНЮ
void Podmenu_4()
{
	cout << "\nКонкретнее: \n";
	cout << "1 - обычная\n2 - оптимизированаая\n3 - рекурсивная\n0 - выход в меню общее\nСделайте выбор: ";
	
}

//------------------------- ВЫВОД ПОДМЕНЮ
void Podmenu_5()
{
	cout << "\nКонкретнее: \n";
	cout << "1 - обычная\n2 - рекурсивная\n0 - выход в меню общее\nСделайте выбор: ";
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
	cout << "\nПроведена Пузырьковая сортировка массива!\n\n";
}

//------------------------- СОРТИРОВКА: ОПТИМИЗИРОВАННАЯ ПУЗЫРЬКОВАЯ
void Opt_bubble(int* mass, int size)
{
	bool finish = false;
	
	do
	{
		finish = false;
		for (int i = 0; i < size - 1; i++)
		{
			if (mass[i] > mass[i + 1])
			{
				swap(mass[i], mass[i + 1]);
				finish = true;
			}
		}
	} while (finish);
	cout << "\nПроведена оптимизированная Пузырьковая сортировка массива!\n\n";
}

//------------------------- СОРТИРОВКА: РЕКУРСИВНАЯ ПУЗЫРЬКОВАЯ
void Recur_bubble(int* mass, int size)
{
	if (size == 1)
	{
		cout << "\nПроведена Рекурсивная Пузырьковая сортировка массива!\n\n";
		return;
	}

	for (int i = 0; i < size - 1; i++)
		if (mass[i] > mass[i + 1])
			swap(mass[i], mass[i + 1]);

	Recur_bubble(mass, size - 1);
}

//------------------------- СОРТИРОВКА: ПО ВЫБОРУ
void Select(int* mass, int size)
{
	int index;
	for (int i = 0; i < size - 1; i++)
	{
		index = i;
		for (int j = i + 1; j < size; j++)
		{
			if (mass[j] < mass[index])
			{
				index = j;
			}
		}
			if (index != i)
			{
				swap(mass[i], mass[index]);
			}
	}
	cout << "\nПроведена сортировка массива ПО ВЫБОРУ!\n\n";
}

//------------------------- СОРТИРОВКА: ПО ВЫБОРУ РЕКУРСИВНАЯ
void Rec_select(int* mass, int size)
{
	if (size == 1)
	{
		cout << "\nПроведена Рекурсивная сортировка массива ПО ВЫБОРУ!\n\n";
		return;
	}
	
	int index = 0;
		for (int i = 0; i < size; i++)
		{
			if (mass[i] < mass[index])
			{
				index = i;
			}
		}
		
		swap(mass[0], mass[index]);          // нулевой элемент будет каждый раз разный, так как мы "смещаем курсор"
		Rec_select(mass + 1, size - 1);      // на каждом шаге уменьшаем размер и "смещаем курсор по массиву"
}