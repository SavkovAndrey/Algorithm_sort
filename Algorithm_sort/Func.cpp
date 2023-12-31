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
		mass[i] = rand() % 31 - 15;
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
	cout << "4 - ���������� �����������\n";
	cout << "5 - ���������� �� ������\n";
	cout << "6 - ���������� ���������\n";
	cout << "7 - ���������� �����\n";
	cout << "8 - ���������� �������\n";
	cout << "9 - ���������� ��������\n";
	cout << "10- ���������� �����\n";
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
		for (int j = 0; j < size - i - 1; j++)
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

//------------------------- ����������: ���������
void Insert(int* mass, int size)                        //   (�� ������� ��� �������)
{ 
	int buff, i, j;                                     // ���������� ��� , ��� ��� j ������������ �� ������
	for (i = 1; i < size; i++)
	{
		buff = mass[i];                                 // ��������� ������� �������
		for (j = i - 1; j >= 0 && mass[j] > buff; j--)  // ������� ��� �������� � ���� �� �������� (� ���� ��� ������ ��������)
		{
			mass[j + 1] = mass[j];                      // ������������ �������� � ����� 
		}
		mass[j + 1] = buff;                             // � "��� �������" ���������� ����... � ����� � ��� j + 1 ������!!
	}                                                   // �.�. ��������� �������� ���� ��� ��� j-- 
	cout << "\n��������� ���������� ������� ���������!\n\n";
}

//------------------------- ����������: ��������� ��������
void Rec_insert(int* mass, int size)
{
	if (size <= 1)
	{
		cout << "\n��������� ���������� ������� ���������!\n\n";
		return; 
	}

	Rec_insert(mass, size - 1);                          // ������� ���������� size - 1 �������
	
	int buff = mass[size - 1], j;                        // �� ��������� ������ size = 2 (��� ��� 0 � 1 ������� if)
		for (j = size - 2; j >= 0 && mass[j] > buff; j--)// ����� ������� i �� ����. ������ ����� size - 1  
		{                                                // � ������ size, ��� ��� �� "������������" ��������� ���������� 
			mass[j + 1] = mass[j];                       // ������� � �������� �������
		}
		mass[j + 1] = buff;
	
}

//------------------------- ����������: �����
void Shell(int* mass, int size)
{
	for (int step = size / 2; step > 0; step /= 2)
	{
		for (int i = step; i < size; i++)
		{
			int buff = mass[i], j;
			for (j = i; j >= step && mass[j - step] > buff; j -= step)
			{
				mass[j] = mass[j - step];
			}
			mass[j] = buff;
		}
	}
	cout << "\n��������� ���������� ������� �����!\n\n";
}

//------------------------- ����������: ����� �����������
void Rec_shell(int* mass, int size, int step)                // step ����� � ��������� ���������� � ��� �� ��� 
{                                                            // ����� �������� ( �������� ���� �� ������. ������)
		for (int i = step; i < size; i++)
		{
			int buff = mass[i], j;
			for (j = i; j >= step && mass[j - step] > buff; j -= step)
			{
				mass[j] = mass[j - step];
			}
			mass[j] = buff;
		}
	
	if(step > 0)
	Rec_shell(mass, size, step / 2);
}

//------------------------- ����������: �������
void Quick(int* mass, int start, int end)                      // �������� ( ������, � ������ ����., �� ����� ����)
{
	if (start < end)                                           // ���� ���� ��� �����������
	{
		int pivot = Partition(mass, start, end);               // �������� ������ pivot �������� ����� ������ 
		                                                       // ������������ ��������� � ������� Partition
		Quick(mass, start, pivot - 1);                         // ��������� �������� ����� �� pivot
		Quick(mass, pivot + 1, end);                           // ��������� �������� ������ �� pivot
	}	
}

//------------------------- ����������: ������� (����������� ��������� � ������� ������� pivot)
int Partition(int* mass, int start, int pivot)                 // ������� ������������ ��� �������� ������� ���
{                                                              // pivot ����� ���� , � ������� ������
	int i = start;
	while (i < pivot)                                          // ������������� � ����-������� �� �� pivot
	{                                   
		if (mass[i] > mass[pivot] && i == pivot - 1)           // ��������� ������ �� ������� ��� PIVOT  
		{                                                      // � !!! �� �������� �� ��� , ���� �������� - ������ 
			swap(mass[i], mass[pivot]);                        // ������ �������.
			pivot--;
		}

		else if (mass[i] > mass[pivot])                        // ���� �� ��������, �� ��� �� ����. ������ PIVOT
		{                                                      // ��:
			swap(mass[pivot - 1], mass[pivot]);                // ������� pivot  � ���� 
			swap(mass[i], mass[pivot]);                        // ������ ����������� ����. � ��� ��� ���������� � PIVOT
			pivot--;                                           // ��������� ������ pivot �� 1 ( ��� ��� ��� ������� 
		}                                                      // ��������� � ���� �� 1), ��� �� ������ ��������������
		                                                       // ������ �������� PIVOT
		else i++;     // ����������� ������ ���� �� ���� ����� ��������� ������ ���:
	}                 // ���� ���� �����, �� �� ����� i-���� ����� ��� ������ ������� � ��� ����� ��������� ��� ������
	
	return pivot;     // ���������� ������ �������� PIVOT � ��� ����� �� ����� ������� � ��������� ���������                                          
}                     // ����� ����������� �������� ����� � ������ �� ���� �������� ���� ����������� ������� Quick

//------------------------- ����������: ��������
void MergeSort(int* mass, int start, int end)
{
	int mid;
	if (start < end) {

		mid = (start + end) / 2;
		MergeSort(mass, start, mid);                     // ��� ������ ���� ����������� ������� �� ��������� 
		MergeSort(mass, mid + 1, end);                   // �� ���������� � ��� "�������������" ��������
		Merge(mass, start, end, mid);                    // �������� ����������� Merge, ������� ��� ������ 
	}                                                    // �������, ��� ������� �������������
}

//------------------------- ����������: �������� (������)
void Merge(int* mass, int start, int end, int mid)       // �� ������ ���� ���� �������� ������� � ������� �����
{                                                        // ����������� ��������, �������� (m, 0, 1, 0)
	int *mergedList = new int[end + 1];                  // �������� mid ����� ���� �� ��������� � ��� �� start � end
	int i, j, k;                                         // mergeList - ��������� ������ ��� �������� �������� ������
	i = start;
	k = start;                                    // ������ ���������� ������� (�������������, ���� ���-�� �������� ����)
	j = mid + 1;

	while (i <= mid && j <= end) {               // "�� ������ �� ��������" � "�� �������� + 1 �� �����"
		if (mass[i] < mass[j]) {                 // �� ���������� ������ ��. ������ �������� � ������ ��. ������ ��������
			mergedList[k] = mass[i];             // ����� �������� ������, ��� ���������� � ��������� ������ �� �������
			k++;
			i++;                                 // i - ������ ������ �������� j - ������ ������. 
		}                                        // ����������� ��� ������ �� ����� �������� ����� �������
		else {                                   // �� � ������ ����������� k, ��� ��� ��� ������ ������ ����. ���.
			mergedList[k] = mass[j];
			k++;
			j++;
		}
	}

	while (i <= mid) {                           // ���� ����� �������� ����� �������� ��. � ������ �������� 
		mergedList[k] = mass[i];                 // ����� �� �� ����. ���.
		k++;
		i++;
	}

	while (j <= end) {                           // ���� �������� �� ������  - �� ����� �� �� ����. ���. 
		mergedList[k] = mass[j];
		k++;
		j++;
	}

	for (i = start; i < k; i++) {                   // ����� ������������ ������������� ��������� ������, ��������� ���
		mass[i] = mergedList[i];                    // � �������� ������
	}
	delete[] mergedList;                            // ��������� �������...
}

//------------------------- ����������: ����� (������������ ����)
void Heap(int* mass, int size, int root)                         // � ������� ���������� "���������������" ������ (������)
{
	int largest = root;                                          // ������� ���������� ������
	int l = 2 * root + 1;                                        // ������ ��. ����� �� �����
	int r = 2 * root + 2;                                        // ������ ��. ������ �� �����

	if (l < size && mass[l] > mass[largest])            // ���� �� ����� ��. � �������!? � �� ������ �� �� �����?
		largest = l;                                    // ���� �� - �� �� ������!

	if (r < size && mass[r] > mass[largest])            // ���� �� ������ ��. � �������!? � �� ������ �� �� �����?
		largest = r;                                    // ���� �� - �� ������!

	if (largest != root)                                // ���� ������ ����� ��������� �������� if, ������ � ��� ������
	{
		swap(mass[root], mass[largest]);
		Heap(mass, size, largest);                      // ���� ������ ��������, �� ����� ��������� ������ ����� - ��
	}                                                   // �����, ������� "�����" ����...
}

//------------------------- ����������: �����
void HeapSort(int* mass, int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)            // n/2 - 1 , ������� ��� ����������� ������� ��. ������� ���������
		Heap(mass, size, i);                           // ������: ��� size 5, ������ i = 1, ����� 0... ��� ����� 
	                                                   // ������� ���������������... ���� size ������ ������������ ���,
	                                                   // ��� �����
	for (int i = size - 1; i >= 0; i--)                
	{                                                  // ������ ������ ������ � ����� ������� � ��������� size - 1,
		swap(mass[0], mass[i]);                        // � ����� �� ������� ���� ��. - �� ������������...
		Heap(mass, i, 0);                              // ������ ��������� ������, ��� � �������� �� 1 ������... 
	}
}