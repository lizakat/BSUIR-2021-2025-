/*Тема работы: Обработка исключительных ситуаций.

4. Класс «Очередь».

Создать обычный или шаблонный класс согласно заданию. Данные в классе хранить в статическом массиве.
Набор методов класса должен обеспечить основные операции с элементами объекта
(добавление, удаление, поиск, просмотр и т.п.) и операции над однотипными объектами (сравнение, присвоение и т.п.).

Обработку всех ошибочных ситуаций реализовать с использованием схемы обработки исключительных ситуаций.
Реализовать собственный класс обработки исключительной ситуации.

Рассмотреть замену обработчиков функций terminate() и unexpected() собственными функциями.

В функции main выполнить действия с экземпляром класса, которые продемонстрируют работу методов,
в том числе и реакцию на возникновение ошибок.*/

#include <iostream>
#include <stdlib.h>
using namespace std;
#define MAX_SIZE 5
#define QUEUE_EMTPY_EXCEPTION "Queue is empty"
#define QUEUE_FULL_EXCEPTION "Queue is full"

class QueueException
{
    string message = "Queue exception";

public:
    QueueException(string &&message) : message(message) {}

    string ShowException()
    {
        return message;
    }
};

int menu();

template <typename Type>
class Queue
{

    int front;
    int rear;
    int size;
    Type array[MAX_SIZE] = {};

public:
    Queue()
    {
        front = -1;
        rear = 0;
        this->size = 0;
    }
    ~Queue(){};
    int getSize()
    {
        return size;
    }
    void enQueue()
    {
        int elem;

        try
        {
            if (size == MAX_SIZE)
            {
                throw QueueException(QUEUE_FULL_EXCEPTION);
            }
            cout << "Enter element" << endl;
            cin >> elem;

            if (front == -1)
                front++;
            array[size] = elem;
            rear++;
            size++;
            return;
        }
        catch (QueueException &ex)
        {
            cout << ex.ShowException() << endl;
            return;
        }
    }
    void deQueue()
    {
        try
        {
            if (size == 0)
            {
                throw QueueException(QUEUE_EMTPY_EXCEPTION);
            }
            for (int i = 0; i < size - 1; i++)
            {
                array[i] = array[i + 1];
            }
            size--;
            rear--;
            return;
        }
        catch (QueueException &ex)
        {
            cout << ex.ShowException() << endl;
            return;
        }
    }
    void out()
    {
        try
        {
            if (size == 0)
            {
                throw QueueException(QUEUE_EMTPY_EXCEPTION);
            }
            for (int i = 0; i < size; i++)
            {
                cout << array[i] << " ";
            }
            cout << endl;
        }
        catch (QueueException &ex)
        {
            cout << ex.ShowException() << endl;
            return;
        }
    }
    Type findbyKey()
    {
        Type key;

        try
        {
            if (size == 0)
            {
                throw QueueException(QUEUE_EMTPY_EXCEPTION);
            }
            cout << "enter key" << endl;
            cin >> key;
            if (key < 0 || key > size)
            {
                throw QueueException("Wrong key");
            }

            return array[key];
        }
        catch (QueueException &ex)
        {
            cout << ex.ShowException() << endl;
            return 0;
        }
    }
};

void myUnexpected()
{
    cout << "My unexpected()" << endl;
    exit(1);
}

void myTerminate()
{
    cout << "My terminate()";
    exit(1);
}

int main()
{
    set_unexpected(myUnexpected);
    set_terminate(myTerminate);

    Queue<int> q1;
    bool b = 1;
    while (b)
        switch (menu())
        {
        case 1:
            q1.enQueue();
            break;
        case 2:
            q1.deQueue();
            break;
        case 3:
            q1.out();
            break;
        case 4:
            cout << q1.getSize() << endl;
            break;
        case 5:

            cout << q1.findbyKey() << endl;
            break;
        default:
            b = 0;
            break;
        }
    system("pause");
    return 0;
}

int menu()
{
    int ch;
    cout << endl
         << "1.Add element" << endl
         << "2.Del element" << endl
         << "3.Show queue" << endl
         << "4.Get size" << endl
         << "5.Find el by order" << endl;
    cin >> ch;
    return ch;
}
