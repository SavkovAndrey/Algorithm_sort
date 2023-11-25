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

	cout << "������� ������ ��������� �������: ";
	cin >> size;
	
	mass = creat_mass(size);
	fill_mass(mass, size);
	output_mass(mass, size);

	while (true)
	{
		menu();
		int n;
		cin >> n;

		switch (n)
		{
			case 1:
			{
				fill_mass(mass, size);
				cout << "\n�� ������������ ������ ������ ���������� �������!\n\n";
				break;
			}

			case 2:
			{
				output_mass(mass, size);
				break;
			}

			case 0:
			{
				cout << "\n�� ����� �� ���������!\n";
				system("pause");
				return 0;
			break;
			}
		}
	}

	delete[] mass;
	system("pause");
	return 0;
}