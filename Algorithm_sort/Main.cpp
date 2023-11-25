#include <iostream>
#include <iomanip>
#include "Func.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RU");
	srand(time(NULL));
	int size;
	int* mass;

	cout << "¬ведите размер тестового массива: ";
	cin >> size;
	
	mass = creat_mass(size);
	fill_mass(mass, size);
	output_mass(mass, size);


	delete[] mass;
	system("pause");
	return 0;
}