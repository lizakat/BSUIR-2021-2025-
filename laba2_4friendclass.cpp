#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Sto;
class Automobile
{
    double mileage;
    string name;
    static int id;

public:
    friend void printInfo(Automobile &automobile);
    friend class Sto;

    Automobile(const int _id, string _name, double _mileage) : name(_name), mileage(_mileage)
    {
        id = _id;
    };              //конструктор инициализации
    Automobile(){}; //конструктор по умолчанию
    ~Automobile()
    {
        name.clear();
    };

    void setId(const int _id);
    void setName(const string _name);
    friend int checkNum(Automobile *car, int carNum);
};

int Automobile::id = 0;

void Automobile::setName(const string _name)
{
    name = _name;
}
void Automobile::setId(const int _id)
{
    id = _id;
}

class Sto
{
    // Automobile car;
public:
    void setMileage(Automobile &car, double _mileage)
    {
        car.mileage = _mileage;
    }
    ~Sto(){};
};

void printInfo(Automobile &automobile)
{
    cout << "-----------------------------" << endl;
    cout << "ID - " << automobile.id++ << endl
         << "Name - " << automobile.name << endl
         << "Mileage - " << automobile.mileage << endl;
    cout << "-----------------------------" << endl;
}

int prov_int(int num)
{
    while (true)
    {
        rewind(stdin);
        if ((cin >> num) && num > 1 && !cin.fail())
            break;
        cin.clear();
        cin.ignore(32767, '\n');
    }
    return (num);
}

double prov_double(double num)
{
    while (true)
    {
        rewind(stdin);
        if ((cin >> num) && num > 1 && !cin.fail())
            break;
        cin.clear();
        cin.ignore(32767, '\n');
    }
    return (num);
}

int main()
{
    int carNum = 0;

    cout << "Please, enter a number of the cars: ";
    carNum = prov_int(carNum);

    Automobile *car = new Automobile[carNum];
    Sto sto;
    double _mileage;
    string _name;
    int _id;
    cout << "ID: " << endl;
    _id = prov_int(_id);

    for (int i = 0; i < carNum; i++)
    {
        cout << i + 1 << endl;
        cout << "Car's mlileage: " << endl;
        _mileage = prov_double(_mileage);
        cout << "Owner's name:  " << endl;
        cin >> _name;
        car[i].setName(_name);
        sto.setMileage(car[i], _mileage);
        cout << endl;
        car[i].setId(_id);
    }

    for (int i = 0; i < carNum; i++)
    {
        cout << "Num - " << i + 1 << endl;
        printInfo(car[i]);
    }

    cout << "Do you want to change sb mileage ?" << endl
         << "1 - yes, 0 - no" << endl;

    bool chooser;
    cin >> chooser;
    if (chooser)
    {
        cout << "Choose num of editable auto:  ";
        int num = checkNum(car, carNum) - 1;
        cout << "Enter mileage: " << endl;
        _mileage = prov_double(_mileage);
        sto.setMileage(car[num], _mileage);
    }

    cout << "Edited:" << endl
         << endl;
    for (int i = 0; i < carNum; i++)
    {
        cout << "Num - " << i + 1 << endl;
        printInfo(car[i]);
    }
    delete[] car;
    ~Automobile()
    {
        cout << "TTT";
    };
    return 0;
}

int checkNum(Automobile *car, int carNum)
{
    int num;
    while (!(cin >> num) || num - 1 < 0 || num - 1 > carNum)
    {
        cout << "Please, enter a num again: " << endl;
    }
    return num;
}