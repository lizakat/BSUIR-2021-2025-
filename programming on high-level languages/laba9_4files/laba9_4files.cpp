/*
4. «Организация».

+Создать класс, который будет описывать некоторый объект (задать не менее трех характеристик) и базовые методы для работы с ним.

+Создать в этом классе операторы работы с потоками ввода-вывода, ориентированными на работу с текстовыми файлами.

+Создать в этом классе методы (чтение, запись, …) для работы с текстовыми файлами в бинарном режиме
(на основе методов потока для работы с отдельными символами).

+Создать в этом классе методы (чтение, запись, …) для работы с бинарными файлами в бинарном режиме
(на основе методов потока для работы с блоками памяти).

+Для обработки всех ошибочных ситуаций использовать конструкцию try…catch().

В головной функции выполнить обработку данных в трех режимах:
-- работа с текстовым файлом в текстовом режиме;
-- работа с текстовым файлом в бинарном режиме;
-- работа с бинарным файлом в бинарном режиме;

Для каждого выше указанного варианта выполнить следующие действия:
+-- сформировать файл данных (не менее 5 строк или записей);
-- вывести записи данных в прямом и обратном порядке не считывая все записи в память
   (при вводе-выводе данных применить знания флагов вывода и манипуляторов);
+-- найти записи по условию (по шаблону названия) и вывести их на экран;
-- удалить записи по условию в файле, удаляемые записи вывести на экран.*/

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <vector>
using namespace std;

#define file1 "TxtTxt.txt"
#define file2 "TxtBin.txt"
#define file3 "BinBin.bin"

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

class Organization
{
   string OrgName;
   int NumberOfMembers;
   float Income;

public:
   Organization(const string OrgName = "", const int NumberOfMembers = 0, const float Income = 0) {}
   ~Organization()
   {
      OrgName.clear();
   }
   void setOrgName()
   {
      cout << "Enter Organization's name:" << endl;
      cin >> OrgName;
   }
   void setNumberOfMembers()
   {
      cout << "Number of members:" << endl;
      cin >> NumberOfMembers;
   }
   void calculateIncome()
   {
      float BasicIncome;
      cout << "Enter average contribution per member:   ";
      cin >> BasicIncome;
      Income = BasicIncome * NumberOfMembers;
   }
   void writeTXTtxt();
   void writeTXTbin();
   void writeBINbin();
   void readTXTtxt();
   void readTXTbin();
   void readBINbin();
   void findTXTtxt(string orgname);
   void findTXTbin(string orgname);
   void findBINbin(string orgname);
   void delTXTtxt(string orgname);
   void delTXTbin(string orgname);
   void delBINbin(string orgname);
   friend ostream &operator<<(ostream &os, Organization &organization)
   {
      os << organization.OrgName << " " << organization.NumberOfMembers << " " << organization.Income << endl;
      return os;
   }

   friend istream &operator>>(istream &is, Organization &organization)
   {
      is >> organization.OrgName >> organization.NumberOfMembers >> organization.Income;
      return is;
   }
};

void Organization::writeTXTtxt()
{
   ofstream fout1;
   fout1.open(file1, ios::app);
   if (!fout1.is_open())
   {
      throw Exception("Ошибка открытия файла");
   }
   fout1 << *this;
   fout1.close();
}
void Organization::writeTXTbin()
{
   ofstream fout2;
   fout2.open(file2, ios::binary | ios::app);
   if (!fout2.is_open())
   {
      throw Exception("Ошибка открытия файла");
   }
   size_t len = this->OrgName.length();
   fout2.write(reinterpret_cast<char *>(&len), sizeof(size_t));
   fout2.write(this->OrgName.c_str(), len);
   fout2.write((char *)&(this->NumberOfMembers), sizeof(int));
   fout2.write((char *)&(this->Income), sizeof(Income));
   fout2.close();
}
void Organization::writeBINbin()
{
   ofstream fout3;
   fout3.open(file3, ios::binary | ios::app);
   if (!fout3.is_open())
   {
      throw Exception("Ошибка открытия файла");
   }
   size_t len = this->OrgName.length();
   fout3.write(reinterpret_cast<char *>(&len), sizeof(size_t));
   fout3.write(this->OrgName.c_str(), len);
   fout3.write((char *)&(this->NumberOfMembers), sizeof(int));
   fout3.write((char *)&(this->Income), sizeof(Income));
   fout3.close();
}

void Organization::readTXTtxt()
{
   ifstream fin1;
   fin1.open(file1);
   if (!fin1.is_open())
   {
      throw Exception("Ошибка открытия файла");
   }

   Organization org;
   while (fin1 >> org)
      cout << org;

   fin1.close();
}
void Organization::readTXTbin()
{
   ifstream fin2;
   fin2.open(file2, ios::binary);
   if (!fin2.is_open())
   {
      throw Exception("Ошибка открытия файла");
   }
   Organization org;

   int len;
   while (fin2.read((char *)&len, sizeof(int)))
   {
      char c;
      org.OrgName = "";
      for (int i = 0; i < len; i++)
      {
         fin2.read((char *)&c, sizeof(c));
         org.OrgName += c;
      }
      fin2.read((char *)(&org.NumberOfMembers), sizeof(int));
      fin2.read((char *)(&org.Income), sizeof(float));

      cout << org;
   }
   fin2.close();
}
void Organization::readBINbin()
{
   ifstream fin3;
   fin3.open(file3, ios::binary);
   if (!fin3.is_open())
   {
      throw Exception("Ошибка открытия файла");
   }
   Organization org;
   int len;
   while (fin3.read((char *)&len, sizeof(int)))
   {

      char c;
      org.OrgName = "";
      for (int i = 0; i < len; i++)
      {
         fin3.read((char *)&c, sizeof(c));
         org.OrgName += c;
      }
      fin3.read((char *)(&org.NumberOfMembers), sizeof(int));
      fin3.read((char *)(&org.Income), sizeof(float));

      cout << org;
   }
   fin3.close();
}

void Organization::findTXTtxt(string orgname)
{
   ifstream fin1;
   fin1.open(file1);
   if (!fin1.is_open())
   {
      throw Exception("Ошибка открытия файла");
   }
   Organization org;
   int cou = 0;
   while (fin1 >> org)
   {
      if (org.OrgName == orgname)
      {
         cou++;
         cout << org;
         break;
      }
   }

   if (cou == 0)
   {
      throw Exception("Not found");
   }
   fin1.close();
}
void Organization::findTXTbin(string orgname)
{
   ifstream fin2;
   fin2.open(file2, ios::binary);
   if (!fin2.is_open())
   {
      //    throw exception("Ошибка открытия файла");
   }
   Organization org;
   int cou = 0;
   int len;
   while (fin2.read((char *)&len, sizeof(int)))
   {
      char c;
      org.OrgName = "";
      for (int i = 0; i < len; i++)
      {
         fin2.read((char *)&c, sizeof(c));
         org.OrgName += c;
      }

      fin2.read((char *)(&org.NumberOfMembers), sizeof(int));
      fin2.read((char *)(&org.Income), sizeof(float));
      if (org.OrgName == orgname)
      {
         cou++;
         cout << org;
         break;
      }
   }

   if (cou == 0)
   {
      cout << "Not found" << endl;
   }
   fin2.close();
}
void Organization::findBINbin(string orgname)
{
   ifstream fin3;
   fin3.open(file2, ios::binary);
   if (!fin3.is_open())
   {
      //    throw exception("Ошибка открытия файла");
   }
   Organization org;
   int cou = 0;
   int len;
   while (fin3.read((char *)&len, sizeof(int)))
   {
      char c;
      org.OrgName = "";
      for (int i = 0; i < len; i++)
      {
         fin3.read((char *)&c, sizeof(c));
         org.OrgName += c;
      }

      fin3.read((char *)(&org.NumberOfMembers), sizeof(int));
      fin3.read((char *)(&org.Income), sizeof(float));
      if (org.OrgName == orgname)
      {
         cou++;
         cout << org;
         break;
      }
   }
   if (cou == 0)
   {
      cout << "Not found" << endl;
   }
   fin3.close();
}

void Organization::delTXTtxt(string orgname)
{
   ifstream fin1;
   ofstream temp;
   fin1.open(file1);
   temp.open("temp.txt", ios::app);
   if (!fin1.is_open() || !temp.is_open())
   {
      //   throw exception("Ошибка открытия файла");
   }
   Organization org;
   int cou = 0;
   while (fin1 >> org)
   {
      if (org.OrgName == orgname)
      {
         cou++;
         cout << org;
      }
      else
      {
         temp << org;
      }
   }

   if (cou == 0)
   {
      cout << "Not found" << endl;
   }
   fin1.close();
   temp.close();
   remove(file1);
   rename("temp.txt", file1);
}
void Organization::delTXTbin(string orgname)
{
   ifstream fin2;
   ofstream temp;
   fin2.open(file2, ios::binary);
   temp.open("temp.txt", ios::binary | ios::app);
   if (!fin2.is_open() || !temp.is_open())
   {
      //    throw exception("Ошибка открытия файла");
   }
   Organization org;
   int cou = 0;
   int len;
   while (fin2.read((char *)&len, sizeof(int)))
   {
      char c;
      org.OrgName = "";
      for (int i = 0; i < len; i++)
      {
         fin2.read((char *)&c, sizeof(c));
         org.OrgName += c;
      }

      fin2.read((char *)(&org.NumberOfMembers), sizeof(int));
      fin2.read((char *)(&org.Income), sizeof(float));
      if (org.OrgName == orgname)
      {
         cou++;
         cout << org;
      }
      else
      {
         temp.write((char *)(&len), sizeof(int));
         temp.write(org.OrgName.c_str(), len);
         temp.write((char *)&(org.NumberOfMembers), sizeof(int));
         temp.write((char *)&(org.Income), sizeof(float));
      }
   }

   if (cou == 0)
   {
      cout << "Not found" << endl;
   }
   temp.close();
   fin2.close();
   remove(file2);
   rename("temp.txt", file2);
}

void Organization::delBINbin(string orgname)
{
   ifstream fin3;
   ofstream temp;
   fin3.open(file3, ios::binary);
   temp.open("temp.txt", ios::binary | ios::app);
   if (!fin3.is_open() || !temp.is_open())
   {
      //    throw exception("Ошибка открытия файла");
   }
   Organization org;
   int cou = 0;
   int len;
   while (fin3.read((char *)&len, sizeof(int)))
   {
      char c;
      org.OrgName = "";
      for (int i = 0; i < len; i++)
      {
         fin3.read((char *)&c, sizeof(c));
         org.OrgName += c;
      }

      fin3.read((char *)(&org.NumberOfMembers), sizeof(int));
      fin3.read((char *)(&org.Income), sizeof(float));
      if (org.OrgName == orgname)
      {
         cou++;
         cout << org;
      }
      else
      {
         temp.write((char *)(&len), sizeof(int));
         temp.write(org.OrgName.c_str(), len);
         temp.write((char *)&(org.NumberOfMembers), sizeof(int));
         temp.write((char *)&(org.Income), sizeof(float));
      }
   }
   if (cou == 0)
   {
      cout << "Not found" << endl;
   }
   temp.close();
   fin3.close();
   remove(file3);
   rename("temp.txt", file3);
}
int main()
{
   system("chcp 1251");
   system("cls");
   setlocale(LC_ALL, ".1251");

   int number;
   cout << "Enter number of organizations: ";
   cin >> number;

   Organization org;

   for (int i = 0; i < number; i++)
   {

      org.setOrgName();
      org.setNumberOfMembers();
      org.calculateIncome();

      org.writeTXTtxt();
      org.writeTXTbin();
      org.writeBINbin();
   }
   cout << "TT:" << endl;
   org.readTXTtxt();
   cout << "TB:" << endl;
   org.readTXTbin();
   cout << "BB" << endl;
   org.readBINbin();
   cout << endl
        << "find" << endl;
   org.findTXTtxt("dasha1");
   org.findTXTbin("liza");
   org.findBINbin("masha");
   cout << endl
        << "del" << endl;
   org.delTXTtxt("dasha");
   org.delTXTbin("masha");
   org.delBINbin("liza");
   org.readTXTtxt();
   org.readTXTbin();
   org.readBINbin();
   system("pause");
   return 0;
}

int menu()
{
   int ch;
   cout << endl
        << "1.Add element" << endl
        << "2.find element" << endl
        << "3.Show" << endl
        << "4.Find el by order" << endl;
   cin >> ch;
   return ch;
}