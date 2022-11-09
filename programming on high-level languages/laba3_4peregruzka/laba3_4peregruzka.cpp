//  = [] () (++) (+- <> однотипные операнды) члены класса
//  (+- <> разнотипные операнды) << friend

// преобразование во втроенный тип и в пользоваетльский тип
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

/* using std::cin;
using std::cout;
using std::endl;
using std::ostream; */

int menu();

class Complex
{
    double real;
    double imag;

public:
    // friend void get(Complex &el);
    Complex(const double real = 0, const double imag = 0) : imag(imag), real(real) {}
    Complex &operator=(const Complex &n)
    {
        this->real = n.real;
        this->imag = n.imag;
        return *this;
    }
    Complex operator+(const Complex &n)
    {
        return Complex(this->real + n.real, this->imag + n.imag);
    }
    Complex operator-(const Complex &n)
    {
        return Complex(this->real - n.real, this->imag - n.imag);
    }
    friend ostream &operator<<(ostream &get, const Complex &n)
    {
        get << n.real << showpos << n.imag << noshowpos << "i";
        return get;
    }
    bool operator>(const Complex &n)
    {
        return this->real > n.real && this->imag > n.imag;
    }
    bool operator<(const Complex &n)
    {
        return this->real < n.real && this->imag < n.imag;
    }
    bool operator==(const Complex &n)
    {
        return this->real == n.real && this->imag == n.imag;
    }
    Complex &operator++()
    {
        this->real++;
        this->imag++;
        return *this;
    }
    Complex operator++(int)
    {
        Complex temp(*this);
        this->real++;
        this->imag++;
        return temp;
    }
    Complex &operator--()
    {
        this->real--;
        this->imag--;
        return *this;
    }
    Complex operator--(int)
    {
        Complex temp(this->real, this->imag);
        this->real--;
        this->imag--;
        return temp;
    }
    operator int() const
    {
        (int)this->real;
        return (int)this->real;
    }
};

int main()
{
    double r, i;
    cout << "Input the first complex number: " << endl;
    cout << "Real part = ";
    cin >> r;
    cout << "imaginary part = ";
    cin >> i;
    Complex a(r, i);
    cout << a << endl;

    cout << "Input the second complex number: " << endl;
    cout << "Real part = ";
    cin >> r;
    cout << "imaginary part = ";
    cin >> i;
    Complex b(r, i);
    cout << b << endl;
    Complex c;

    bool ch = true;
    bool res;
    while (ch)
    {
        switch (menu())
        {
        case 1:
            c = b;
            cout << c << endl;
            break;
        case 2:
            cout << a + b << endl;
            break;
        case 3:
            cout << a - b << endl;
            break;
        case 4:
            res = a < b;
            cout << res << endl;
            break;
        case 5:
            res = a > b;
            cout << res << endl;
            break;
        case 6:
            res = a == b;
            cout << res << endl;
            break;
        case 7:
            c = a++;
            cout << c << endl;
            cout << a << endl;
            break;
        case 8:
            c = ++a;
            cout << c << endl;
            cout << a << endl;
            break;
        case 9:
            c = a--;
            cout << c << endl;
            cout << a << endl;
            break;
        case 10:
            c = --a;
            cout << c << endl;
            cout << a << endl;
            break;
        case 11:
            cout << ((int)a) << endl;
            break;
        default:
            ch = false;
            break;
        }
    }
    system("pause");
    return 0;
}

int menu()
{
    cout << "Choose the operator" << endl;
    int chooser;
    cout << "1)  c=b" << endl;
    cout << "2)  a+b" << endl;
    cout << "3)  a-b" << endl;
    cout << "4)  a<b" << endl;
    cout << "5)  a>b" << endl;
    cout << "6) a==b" << endl;
    cout << "7)  a++" << endl;
    cout << "8)  ++a" << endl;
    cout << "9)  a--" << endl;
    cout << "10)  --a" << endl;
    cout << "11)  a real part double to int" << endl;
    cout << "Other to exit" << endl;
    cin >> chooser;
    return chooser;
}
