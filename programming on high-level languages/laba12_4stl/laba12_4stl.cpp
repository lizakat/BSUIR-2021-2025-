/*Тема работы: Использование библиотеки STL для реализации обработки данных.

4. Подсчет слов в строке, которые содержат все символы из указанного набора символов.

Реализовать программу, которая обрабатывает строки текстового файла согласно заданию,
а результаты обработки помещает в строки другого текстового файла.
Для хранения и обработки данных использовать контейнеры и алгоритмы библиотеки STL.

На экран выводить отладочную информацию: какой файл открыт (или ошибка открытия файла),
номер обработанной строки и результат ее обработки и т.п. Для обработки всех исключительных ситуаций использовать конструкцию try…catch().*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <exception>

using namespace std;

class Exception
{
    string message = "exception";

public:
    Exception(string &&message) : message(message) {}

    string what()
    {
        return message;
    }
};
int main()
{
    string symbols = "abc";
    string str;
    string word;
    int numOfline = 0;
    ifstream fin;
    ofstream fout;
    try
    {
        fin.open("input.txt");

        if (!fin.is_open())
            throw Exception("file input.txt not open");
        else
            cout << "file input.txt is open" << endl;

        fout.open("output.txt");

        if (!fout.is_open())
            throw Exception("file output.txt non open");
        else
            cout << "file output.txt is open" << endl;

        int n = 0;
        while (!fin.eof())
        {
            numOfline++;
            int counter = 0;
            getline(fin, str);
            if (str == "")
                throw Exception("File is empty");

            stringstream stst(str);
            while (!stst.eof())
            {
                n = 0;
                stst >> word;
                for (int i = 0; i < symbols.length(); i++)
                {
                    if (word.find_first_of(symbols[i]) != string::npos)
                        n++;
                    else
                        break;
                }
                if (n == symbols.length())
                    counter += 1;
            }
            fout << "Line № " << numOfline << ": " << counter << "  words that contains symbols '" << symbols << "'" << endl;
        }
    }
    catch (Exception &ex)
    {
        cout << ex.what() << endl;
    }

    fin.close();
    fout.close();
    system("pause");
    return 0;
}