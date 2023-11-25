#include <iostream>
#include <iomanip>
#include "Func.h"
using namespace std;

//------------------------- �������� �������
int *creat_mass(int size)
{
	int *mass = new int[size];
	return mass;
}

//------------------------- ���������� �������
void fill_mass(int* mass, int size)
{
	for (int i = 0; i < size; i++)
	{
		mass[i] = rand() % 21 - 10;
	}
}

//------------------------- ����� �������
void output_mass(int* mass, int size)
{
	cout << "\n������:\n";
	for (int i = 0; i < size; i++)
	{
		cout << setw(4) << mass[i];
	}
	cout << "\n\n";
}

//------------------------- ����� ����
void menu()
{
	cout << "1 - ������������ ������ ���������� �������\n";
	cout << "2 - ������� ������ �� �����\n";
	cout << "3 - ���������� ����������� �������\n";
	cout << "0 - ����� �� ���������\n\n";
	cout << "�������� ��� �����: ";
}

//------------------------- ����������:  �����������
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