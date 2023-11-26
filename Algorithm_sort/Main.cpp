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

	cout << "Введите размер тестового массива: ";
	cin >> size;
	
	mass = creat_mass(size);
	fill_mass(mass, size);
	output_mass(mass, size);
	menu();

	while (true)
	{
		cout << "Сделайте выбор:";
		int n;
		cin >> n;

		switch (n)
		{
		    case 1:  menu();  break;
			case 2:  fill_mass(mass, size);  break;
			case 3:  output_mass(mass, size);  break;
			case 4:	{
				Podmenu_4();   int m;   cin >> m;
				switch (m){
					case 1:  Bubble(mass, size);  break;
					case 2:  Opt_bubble(mass, size);  break;
					case 3:  Recur_bubble(mass, size);  break;
					case 0:  break;
				}  break;
			}
			case 5: {
				Podmenu_5();   int m;   cin >> m;
				switch (m) {
				case 1:  Select(mass, size);  break;
				case 2:  Rec_select(mass, size);  break;
				case 0:  break;
				}  break;
			}
			case 6: {
				Podmenu_5();   int m;   cin >> m;
				switch (m) {
				case 1:  Select(mass, size);  break;
				//case 2:  Rec_select(mass, size);  break;
				case 0:  break;
				}  break;
			}
			case 0:
			{
				cout << "\nВы вышли из программы!\n";
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