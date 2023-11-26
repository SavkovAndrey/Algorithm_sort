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
	cout << "\n�� ������������ ������ ������ ���������� �������!\n\n";
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
	cout << "1 - �������� ����\n";
	cout << "2 - ������������ ������ ���������� �������\n";
	cout << "3 - ������� ������ �� �����\n";
	cout << "4 - ���������� ����������� �������\n";
	cout << "5 - ���������� �� ������\n";
	cout << "0 - ����� �� ���������\n\n";
}

//------------------------- ����� �������
void Podmenu_4()
{
	cout << "\n����������: \n";
	cout << "1 - �������\n2 - ����������������\n3 - �����������\n0 - ����� � ���� �����\n�������� �����: ";
	
}

//------------------------- ����� �������
void Podmenu_5()
{
	cout << "\n����������: \n";
	cout << "1 - �������\n2 - �����������\n0 - ����� � ���� �����\n�������� �����: ";
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
	cout << "\n��������� ����������� ���������� �������!\n\n";
}

//------------------------- ����������: ���������������� �����������
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
	cout << "\n��������� ���������������� ����������� ���������� �������!\n\n";
}

//------------------------- ����������: ����������� �����������
void Recur_bubble(int* mass, int size)
{
	if (size == 1)
	{
		cout << "\n��������� ����������� ����������� ���������� �������!\n\n";
		return;
	}

	for (int i = 0; i < size - 1; i++)
		if (mass[i] > mass[i + 1])
			swap(mass[i], mass[i + 1]);

	Recur_bubble(mass, size - 1);
}

//------------------------- ����������: �� ������
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
	cout << "\n��������� ���������� ������� �� ������!\n\n";
}

//------------------------- ����������: �� ������ �����������
void Rec_select(int* mass, int size)
{
	if (size == 1)
	{
		cout << "\n��������� ����������� ���������� ������� �� ������!\n\n";
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
		
		swap(mass[0], mass[index]);          // ������� ������� ����� ������ ��� ������, ��� ��� �� "������� ������"
		Rec_select(mass + 1, size - 1);      // �� ������ ���� ��������� ������ � "������� ������ �� �������"
}