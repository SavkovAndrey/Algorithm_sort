#pragma once
int* creat_mass(int size);                        // создание массива
void fill_mass(int* mass, int size);              // заполнение массива
void output_mass(int* mass, int size);            // вывод массива
void menu();                                      // меню
void Podmenu_4();                                 // подменю
void Podmenu_5();                                  // подменю
void Bubble(int* mass, int size);                 // пузырек
void Opt_bubble(int* mass, int size);             // оптимизированный пузырек
void Recur_bubble(int* mass, int size);           // рекурсивный пузырек
void Select(int* mass, int size);                 // по выбору
void Rec_select(int* mass, int size);             // по выбору рекурсия
void Insert(int* mass, int size);                 // вставками
void Rec_insert(int* mass, int size);             // вставками рекурсия
void Shell(int* mass, int size);                  // шелла
void Rec_shell(int* mass, int size, int step);    // шелла рекурсия
void Quick(int* mass, int start, int end);        // быстрая
int Partition(int* mass, int start, int end);     // быстрая (доп функция)
