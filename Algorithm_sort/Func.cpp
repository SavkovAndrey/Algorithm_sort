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
	cout << "\n";
	for (int i = 0; i < size; i++)
	{
		cout << setw(4) << mass[i];
	}
	cout << "\n\n";
}