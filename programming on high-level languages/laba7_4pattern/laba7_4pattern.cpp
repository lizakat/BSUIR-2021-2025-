/*   Тема работы: Шаблоны функций и классов.
Цель работы: Создание консольной программы для реализации шаблонов функций и классов, включая: явные
специализации шаблонных функций и классов, стандартные типы в шаблонных классах.
Общие требования к выполнению работы

4. Функция поиска первого элемента в массиве по заданному ключу.

Реализовать явную специализацию шаблонной функции или класса для строк символов (char *).

В функции main выполнить действия с шаблонной функцией или классом, которые продемонстрируют работу
методов.*/

#include <iostream>
#include <stdlib.h>
using namespace std;
#define SIZE 10

template <typename Type>
void FindByKey(Type *Array, int ArraySize, Type Key)
{
    for (int i = 0; i < ArraySize; i++)
    {
        if (Array[i] == Key)
        {
            cout << "Array[" << i << "] = " << Array[i] << endl;
            return;
        }
    }
    cout << "Not found" << endl;
}

template <>
void FindByKey(char *Array, int ArraySize, char Key)
{
    for (int i = 0; i < ArraySize; i++)
    {
        if (Array[i] == Key)
        {
            cout << "Array[" << i << "] = " << Array[i] << endl;
            return;
        }
    }
    cout << "Not found" << endl;
}

template <typename IO>
void InputOutput(IO *Array, int ArraySize)
{
    for (int i = 0; i < SIZE; i++)
    {
        cin >> Array[i];
    }

    for (int i = 0; i < SIZE; i++)
    {
        cout << Array[i] << "  ";
    }
}

int main()
{
    int *int_array = new int[SIZE];
    char *char_array = new char[SIZE];
    double *double_array = new double[SIZE];
    int ikey;
    char ckey;
    double dkey;

    cout << endl
         << "Int values: " << endl;
    InputOutput(int_array, SIZE);
    cout << endl
         << "Enter int key: ";
    cin >> ikey;
    FindByKey(int_array, SIZE, ikey);

    cout << endl
         << "Char values: " << endl;
    InputOutput(char_array, SIZE);
    cout << endl
         << "Enter char key: ";
    cin >> ckey;
    FindByKey(char_array, SIZE, ckey);

    cout << endl
         << "Double values: " << endl;
    InputOutput(double_array, SIZE);
    cout << endl
         << "Enter double key: ";
    cin >> dkey;
    FindByKey(double_array, SIZE, dkey);

    system("pause");
    delete[] char_array;
    delete[] int_array;
    delete[] double_array;
}