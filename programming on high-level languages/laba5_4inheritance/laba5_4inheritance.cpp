/* «Транспортное средство»

 По полученному базовому классу создать классы наследников по двум разным ветвям наследования (B←P1←P11 и B←P2←P21):
-- во всех классах должны быть свои данные (характеристики объектов), расположенные в private или protected секциях;
-- во всех классах создать конструкторы инициализации объектов для всех классов (не забыть про передачу параметров в конструкции базовых классов);
-- во всех классах создать деструкторы;
-- во всех классах создать метод вывода объекта на экран (всех его параметров);
-- остальные методы создавать по необходимости.

Создать класс с множественным наследованием (P11 ← P3 → P21). Создать в этом классе выше описанные
функции (в коде функций не использовать доступ к данным через оператор разрешения зоны видимости ::).

В головной функции создать экземпляр класса P3. Вывести содержимое экземпляра класса P3 на экран.
Проверить, что получится, если не будет использовано виртуальное наследование.*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class Transport
{
protected:
    int Number;
    string Colour;

public:
    Transport(int Number = 0, string Colour = "") : Number(Number), Colour(Colour) {}
    Transport(Transport &other)
    {
        this->Number = other.Number;
        this->Colour = other.Colour;
    }
    ~Transport()
    {
        Colour.clear();
    }
    int getNumber() const
    {
        return Number;
    }
    void setNumber(int number)
    {
        Number = number;
    }
    const string &getColour() const
    {
        return Colour;
    }
    void setColour(const string &colour)
    {
        Colour = colour;
    }
    virtual void show()
    {
        cout << "Vehicle Number: " << Number << endl
             << "Vehicle Colour is " << Colour << endl
             << endl;
    }
};

class PersonalTransport : virtual public Transport
{
private:
    string PersonalTransportInfo = "PersonalTransport";

protected:
    double Mileage;

public:
    PersonalTransport(int Number = 0, string Colour = "", double Mileage = 0) : Transport(Number, Colour), Mileage(Mileage){};
    ~PersonalTransport()
    {
        PersonalTransportInfo.clear();
    }

    const string &getPersonalTransportInfo() const
    {
        return PersonalTransportInfo;
    }
    double getMileage() const
    {
        return Mileage;
    }
    void setMileage(int mileage)
    {
        Mileage = mileage;
    }
    virtual void show()
    {
        cout << "Vehicle Number: " << Number << endl
             << "Vehicle Colour is " << Colour << endl
             << PersonalTransportInfo << endl
             << "Mileage:  " << endl
             << endl;
    }
};

class PublicTransport : virtual public Transport
{
private:
    string PublicTransportInfo = "PublicTransport";

protected:
    double Cost;

public:
    PublicTransport(int Number = 0, string Colour = "", double Cost = 0) : Transport(Number, Colour), Cost(Cost){};
    ~PublicTransport()
    {
        PublicTransportInfo.clear();
    }
    const string &getPublicTransportInfo() const
    {
        return PublicTransportInfo;
    }
    double getCost() const
    {
        return Cost;
    }
    void setCost(int cost)
    {
        Cost = cost;
    }
    virtual void show()
    {
        cout << "Vehicle Number: " << Number << endl
             << "Vehicle Colour is " << Colour << endl
             << PublicTransportInfo << endl
             << "Cost:  " << Cost << endl
             << endl;
    }
};

class Bus : virtual public PublicTransport
{
protected:
    int Capacity;

public:
    Bus(double Number = 0, string Colour = "", double Cost = 0, int Capacity = 0) : Transport(Number, Colour), PublicTransport(Number, Colour, Cost), Capacity(Capacity){};
    ~Bus() {}

    int getCapacity() const
    {
        return Capacity;
    }
    void setCapacity(int capacity)
    {
        Capacity = capacity;
    }
    virtual void show()
    {
        cout << "Vehicle Number:  " << Number << endl
             << "Vehicle Colour is  " << Colour << endl
             << getPublicTransportInfo() << endl
             << "Cost:  " << Cost << endl
             << "Capacity:  " << Capacity << endl
             << endl;
    }
};

class Car : virtual public PersonalTransport
{
protected:
    string Model;

public:
    Car(double Number = 0, string Colour = "", double Mileage = 0, string Model = "") : Transport(Number, Colour), PersonalTransport(Number, Colour, Mileage), Model(Model){};
    ~Car()
    {
        Model.clear();
    }

    string getModel() const
    {
        return Model;
    }
    void setModel(string model)
    {
        Model = model;
    }
    virtual void show()
    {
        cout << "Vehicle Number:  " << Number << endl
             << "Vehicle Colour is  " << Colour << endl
             << getPersonalTransportInfo() << endl
             << "Mileage:  " << Mileage << endl
             << "Model:  " << Model << endl
             << endl;
    }
};

class Marshrutka : public Bus, public Car
{
protected:
    string DriverName;
    int BreakdownNum;

public:
    Marshrutka(Marshrutka &other) : Car(other), Bus(other), PublicTransport(other), PersonalTransport(other), Transport(other)
    {
        this->Number = other.Number;
        this->Colour = other.Colour;
        this->Cost = other.Cost;
        this->Mileage = other.Mileage;
        this->Capacity = other.Capacity;
        this->Model = other.Model;
        this->BreakdownNum = other.BreakdownNum;
        this->DriverName = other.DriverName;
    }
    Marshrutka(const int Number = 0, string Colour = "", double Cost = 0, double Mileage = 0, int Capacity = 0, string Model = "", int BreakdownNum = 0, string DriverName = "")
        : Transport(Number, Colour),
          PersonalTransport(Number, Colour, Mileage),
          PublicTransport(Number, Colour, Cost),
          Bus(Number, Colour, Cost, Capacity),
          Car(Number, Colour, Mileage, Model), DriverName(DriverName), BreakdownNum(BreakdownNum)
    {
    }
    ~Marshrutka()
    {
        DriverName.clear();
    }

    const string &getDriverName() const
    {
        return DriverName;
    }
    void setName(const string &drivername)
    {
        DriverName = drivername;
    }
    int getAge() const
    {
        return BreakdownNum;
    }
    void setBreakdownNum(int breakdownNum)
    {
        BreakdownNum = breakdownNum;
    }
    void inputData()
    {
        cout << endl
             << "Enter Number: ";
        cin >> Number;
        cout << "Enter Colour: ";
        cin >> Colour;
        cout << "Enter Cost: ";
        cin >> Cost;
        cout << "Enter Mileage: ";
        cin >> Mileage;
        cout << "Enter Capacity: ";
        cin >> Capacity;
        cout << "Enter Model: ";
        cin >> Model;
        cout << "Enter Driver Name: ";
        cin >> DriverName;
        cout << "Enter Number of Breakdowns: ";
        cin >> BreakdownNum;
        cout << endl;
    }

    virtual void show() /*override*/
    {
        cout << "Vehicle Number:  " << Number << endl
             << "Vehicle Colour is  " << Colour << endl
             << "-------------------" << endl
             << "Mileage:  " << Mileage << endl
             << "Model:  " << Model << endl
             << "------------------" << endl
             << "Cost:  " << Cost << endl
             << "Capacity:  " << Capacity << endl
             << "------------------" << endl
             << "Driver Name:  " << DriverName << endl
             << "Number of Breakdowns:  " << BreakdownNum << endl
             << endl;
    }
};

int main()
{
    cout << "Input data for MARSHRUTKA:" << endl;
    Marshrutka a;
    a.inputData();
    Marshrutka b(8565, "Red", 2.5, 1234.5, 18, "BMW", 0, "Dmitry");
    a.show();
    b.show();

    /*  Car c;
     c.setNumber(1111);
     c.setColour("Black");
     c.setMileage(126.5);
     c.setModel("Volvo");
     c.show();

     PublicTransport d(1225, "Yellow", 0.9);
     d.show();

     Transport e(9636, "White");
     e.show(); */

    system("pause");
    return 0;
}