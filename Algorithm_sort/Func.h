#pragma once
int* creat_mass(int size);                        // �������� �������
void fill_mass(int* mass, int size);              // ���������� �������
void output_mass(int* mass, int size);            // ����� �������
void menu();                                      // ����
void Podmenu_4();                                 // �������
void Podmenu_5();                                  // �������
void Bubble(int* mass, int size);                 // �������
void Opt_bubble(int* mass, int size);             // ���������������� �������
void Recur_bubble(int* mass, int size);           // ����������� �������
void Select(int* mass, int size);                 // �� ������
void Rec_select(int* mass, int size);             // �� ������ ��������
void Insert(int* mass, int size);                 // ���������
void Rec_insert(int* mass, int size);             // ��������� ��������
void Shell(int* mass, int size);                  // �����
void Rec_shell(int* mass, int size, int step);    // ����� ��������
void Quick(int* mass, int start, int end);        // �������
int Partition(int* mass, int start, int end);     // ������� (��� �������)
