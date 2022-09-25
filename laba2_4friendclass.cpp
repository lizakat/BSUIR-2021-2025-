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

    Automobile(const int id = 0, const string name = "", const double mileage = 0){};
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
    Automobile car;

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
    cout << "id - " << automobile.id << endl
         << "Name - " << automobile.name << endl
         << "mileage - " << automobile.mileage << endl;
    cout << "-----------------------------" << endl;
}

int main()
{
    int carNum = 0;

    while (true)
    {
        cout << "Please, enter a number of the automobiles: ";
        fflush(stdin);
        cin >> carNum;
        if (carNum > 0)
            break;
    }

    Automobile *car = new Automobile[carNum];
    Sto sto;
    double _mileage;
    for (int i = 0; i < carNum; i++)
    {
        string _name;
        int _id;
        cout << "id:" << endl;
        cin >> _id;
        cout << "mileage: " << endl;
        cin >> _mileage;
        cout << "name:" << endl;
        cin >> _name;
        car[i].setName(_name);
        car[i].setId(_id);
        sto.setMileage(car[i], _mileage);
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
        cout << "Choose num of editable auto" << endl;
        int num = checkNum(car, carNum) - 1;
        cout << "mileage" << endl;
        cin >> _mileage;
        sto.setMileage(car[num], _mileage);
    }

    cout << "Edited:" << endl
         << endl;
    for (int i = 0; i < carNum; i++)
    {
        cout << "Num - " << i + 1 << endl;
        printInfo(car[i]);
    }
    getchar();
    delete[] car;
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