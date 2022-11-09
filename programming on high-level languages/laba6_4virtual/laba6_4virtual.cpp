/* «Транспортное средство»

По полученному базовому классу создать классы наследников по двум разным ветвям наследования (B←P1←P11 и B←P2):
-- во всех классах должны быть свои данные (характеристики объектов), расположенные в private или protected секциях;
-- во всех классах создать конструкторы инициализации объектов для всех классов (не забыть про передачу параметров в конструкции базовых классов);
-- во всех классах создать деструкторы;
-- остальные методы создавать по необходимости.

Создать в базовом классе чисто виртуальные функции расчета (например, расчет площади фигуры и т.п.) и вывода объекта на экран
(всех его параметров). Выполнить реализацию этих виртуальных функций в классах наследниках.

Задать в базовом классе деструктор как виртуальный.

В головной функции динамически создать массив указателей на базовый класс. Заполнить массив указателями на
динамически создаваемые объекты производных классов (P1, P11, P2). Для каждого элемента массива проверить
работу виртуальных функций. Удалить из памяти динамически выделенные объекты.*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class Transport
{
protected:
    int Number;
    string Colour;
    double GasMileage;
    double Distance;

public:
    Transport(int Number = 0, string Colour = "", double GasMileage = 0, double Distance = 0) : Number(Number), Colour(Colour), GasMileage(GasMileage), Distance(Distance) {}
    /* Transport(Transport &other)
    {
        this->Number = other.Number;
        this->Colour = other.Colour;
        this->GasMileage = other.GasMileage;
        this->Distance = other.Distance;
    } */
    virtual ~Transport()
    {
        Colour.clear();
    }

    virtual void show() = 0;
    virtual void inputData() = 0;
    virtual double FullGasMileage() = 0;
};

class Car : virtual public Transport
{
protected:
    string Model;

public:
    Car(double Number = 0, string Colour = "", double GasMileage = 0, double Distance = 0, string Model = "") : Transport(Number, Colour, GasMileage, Distance), Model(Model){};
    ~Car()
    {
        Model.clear();
    }

    double FullGasMileage() override
    {
        return GasMileage * Distance / 100;
    }
    void inputData() override
    {
        cout << endl
             << "Enter Number: ";
        cin >> Number;
        cout << "Enter Colour: ";
        cin >> Colour;
        cout << "Enter Model: ";
        cin >> Model;
        cout << "Enter GasMileage: ";
        cin >> GasMileage;
        cout << "Enter Distance: ";
        cin >> Distance;
    }
    void show() override
    {
        cout << "Car:" << endl
             << "Vehicle Number:  " << Number << endl
             << "Vehicle Colour is  " << Colour << endl
             << "Model:  " << Model << endl
             << "Vehicle Gas Miliage: " << GasMileage << " l/100km" << endl
             << "Distance: " << Distance << " km" << endl
             << "Full Gas Miliage per " << Distance << " km: " << FullGasMileage() << endl
             << endl;
    }
};

class PublicTransport : virtual public Transport
{
protected:
    double Cost;

public:
    PublicTransport(int Number = 0, string Colour = "", double GasMileage = 0, double Distance = 0, double Cost = 0) : Transport(Number, Colour, GasMileage, Distance), Cost(Cost){};
    virtual ~PublicTransport() {}

    double FullGasMileage() override
    {
        return GasMileage * Distance / 100 * 2;
    }
    void inputData() override
    {
        cout << endl
             << "Enter Number: ";
        cin >> Number;
        cout << "Enter Colour: ";
        cin >> Colour;
        cout << "Enter Cost: ";
        cin >> Cost;
        cout << "Enter GasMileage: ";
        cin >> GasMileage;
        cout << "Enter Distance: ";
        cin >> Distance;
    }
    void show() override
    {
        cout << "Public Transport: " << endl
             << "Vehicle Number:  " << Number << endl
             << "Vehicle Colour is  " << Colour << endl
             << "Cost:  " << Cost << endl
             << "Vehicle Gas Miliage: " << GasMileage << " l/km" << endl
             << "Distance: " << Distance << " km" << endl
             << "Full Gas Miliage per " << Distance << " km: " << FullGasMileage() << endl
             << endl;
    }
};

class Bus : virtual public PublicTransport
{
protected:
    int Capacity;

public:
    Bus(double Number = 0, string Colour = "", double GasMileage = 0, double Distance = 0, double Cost = 0, int Capacity = 0) : Transport(Number, Colour, GasMileage, Distance), PublicTransport(Number, Colour, Cost), Capacity(Capacity){};
    ~Bus() {}

    double FullGasMileage() override
    {
        return GasMileage * Distance / 100 * Capacity / 10;
    }
    void inputData() override
    {
        cout << endl
             << "Enter Number: ";
        cin >> Number;
        cout << "Enter Colour: ";
        cin >> Colour;
        cout << "Enter Cost: ";
        cin >> Cost;
        cout << "Enter Capacity: ";
        cin >> Capacity;
        cout << "Enter GasMileage: ";
        cin >> GasMileage;
        cout << "Enter Distance: ";
        cin >> Distance;
    }
    void show() override
    {
        cout << "Bus: " << endl
             << "Vehicle Number:  " << Number << endl
             << "Vehicle Colour is  " << Colour << endl
             << "Cost:  " << Cost << endl
             << "Capacity:  " << Capacity << endl
             << "Vehicle Gas Miliage: " << GasMileage << " l/km" << endl
             << "Distance: " << Distance << " km" << endl
             << "Full Gas Miliage per " << Distance << " km: " << FullGasMileage() << endl
             << endl;
    }
};

int main()
{
    int carnumber;
    int publtrnumber;
    int busnumber;
    cout << "Enter number of vehicles: " << endl;
    cout << "Car: ";
    cin >> carnumber;
    cout << "Public Transport: ";
    cin >> publtrnumber;
    cout << "Bus: ";
    cin >> busnumber;
    Transport **salon = new Transport *[carnumber + busnumber + publtrnumber];
    for (int i = 0; i < carnumber; i++)
    {
        salon[i] = new Car;
        cout << endl
             << "Input data for Car[" << i + 1 << "]";
        salon[i]->inputData();
    }
    for (int i = 0; i < publtrnumber; i++)
    {
        salon[i + carnumber] = new PublicTransport;
        cout << endl
             << "Input data for Public Transport[" << i + 1 << "]";
        salon[i + carnumber]->inputData();
    }
    for (int i = 0; i < busnumber; i++)
    {
        salon[i + carnumber + publtrnumber] = new Bus;
        cout << endl
             << "Input data for Bus[" << i + 1 << "]";
        salon[i + carnumber + publtrnumber]->inputData();
    }
    for (int i = 0; i < carnumber + busnumber + publtrnumber; i++)
    {
        cout << "---------------------------" << endl;
        salon[i]->show();
    }

    system("pause");
    return 0;
}