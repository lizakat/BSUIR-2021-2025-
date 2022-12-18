/*Тема работы: Контейнеры объектов.

4. Список двусвязный.

Построить шаблонный класс, который будет описывать элемент хранимых данных, доступ к ним, сравнение элементов и т.п. по необходимости.

Для полученного варианта задания, построить контейнерный шаблонный класс операций над элементами данных, включающий операции:
-- добавления;
-- удаления;
-- поиска;
-- просмотра;
-- остальные функции добавлять по необходимости.

Для данного контейнерного класса предусмотреть при формировании элемента задание режима уникальных элементов
(т.е. проверку на дублирование значений элементов).

Для обработки всех ошибочных ситуаций использовать конструкцию try…catch().

Дополнительно к контейнеру рекомендуется реализовать класс-итератор.

В функции main создать три экземпляра шаблонного класса-контейнера для разных типов данных.
Работа с этими объектами должна демонстрироваться на следующих операциях: добавить – просмотреть – найти – удалить – найти – просмотреть.

Проверить обработку исключительных ситуаций (например, чтение из пустого стека, дублирование объектов и т.п.).*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
template <typename T>
struct Node
{
    T data;
    Node<T> *next = nullptr;
    Node<T> *prev = nullptr;
};
template <typename T>
class List
{
protected:
    Node<T> *head;
    Node<T> *tail;
    long amount;

public:
    List()
    {
        head = nullptr;
        tail = nullptr;
        amount = 0;
    }
    ~List()
    {
        while (head)
        {
            this->pop_head();
        }
    }
    long size() { return this->amount; }
    void push_head(T input_object)
    {
        if (head == nullptr)
        {
            head = new Node<T>;
            head->data = input_object;
            head->next = nullptr;
            head->prev = nullptr;
            tail = head;
            amount++;
            return;
        }
        else
        {
            Node<T> *node = new Node<T>;
            node->data = input_object;
            node->next = head;
            node->prev = nullptr;
            head->prev = node;
            head = node;
            amount++;
        }
        return;
    }
    void push_tail(T input_object)
    {
        if (head == nullptr)
        {
            head = new Node<T>;
            head->data = input_object;
            head->next = nullptr;
            head->prev = nullptr;
            tail = head;
            amount++;
            return;
        }
        else
        {
            Node<T> *node = new Node<T>;
            node->data = input_object;
            node->next = nullptr;
            node->prev = tail;
            tail->next = node;
            tail = node;
            amount++;
        }
        return;
    }
    List(const List<T> &other)
    {
        if (this->head)
        {
            amount = 0;
            tail = head = NULL;
        }
        Node<T> *temp = new Node<T>;
        temp = other.head;
        ;
        while (temp)
        {
            this->push_head(temp->data);
            temp = temp->next;
        }
    }
    T pop_head()
    {
        if (!(head))
            return T();
        T data = head->data;
        Node<T> *node = head;
        head = head->next;
        if (head)
            head->prev = nullptr;
        delete node;
        amount--;
        return data;
    }
    T pop_tail()
    {
        if (!(head))
            return T();
        T data = tail->data;
        Node<T> *node = tail;
        tail = tail->prev;
        if (tail)
            tail->next = nullptr;
        delete node;
        amount--;
        return data;
    }
    T &operator[](long num)
    {
        Node<T> *curr = head;
        if (num < 0 || num >= amount)
            return curr->data;
        for (long i = 0; i < num; i++)
            curr = curr->next;
        return curr->data;
    }
    void delete_element(Node<T> *node)
    {
        if (head == node)
            head = head->next;
        if (tail == node)
            tail = tail->prev;
        if (node->next != nullptr)
            node->next->prev = node->prev;
        if (node->prev != nullptr)
            node->prev->next = node->next;
        delete node;
        node = nullptr;
        this->amount--;
    }
    void output()
    {
        Node<T> *j = this->begin();
        while (j != nullptr)
        {
            cout << j->data << " ";
            j = j->next;
        }
    }

    Node<T> *begin() { return head; }
    Node<T> *end()
    {
        if (tail == nullptr)
            return tail->prev;
        if (tail != nullptr)
            return tail;
    }
};

int menu()
{
    int ch;
    cout << endl
         << "1.Push head el" << endl
         << "2.Push tail el" << endl
         << "3.Pop head el" << endl
         << "4.Pop tail el" << endl
         << "5.Size" << endl
         << "6.Show[index]" << endl
         << "7.Del element" << endl
         << "8.Show all" << endl;
    cin >> ch;
    return ch;
}
int main()
{
    List<int> list;
    bool corr = 1;
    while (corr)
    {
        switch (menu())
        {
        case 1:
            int temp;
            cout << "Enter: ";
            cin >> temp;
            list.push_head(temp);
            break;

        case 2:
            int temp1;
            cout << "Enter: ";
            cin >> temp1;
            list.push_tail(temp1);
            break;

        case 3:

            list.pop_head();
            break;

        case 4:

            list.pop_tail();
            break;

        case 5:
            cout << list.size() << endl;
            break;

        case 6:
            int index;
            cout << "Enter: ";
            cin >> index;
            cout << list[index] << endl;
            break;
        case 7:
            Node<int> *curr;
            curr = list.begin();
            int num;
            cout << "Enter: ";
            cin >> num;
            if (num < 0 || num >= list.size())
                return -1;
            for (long i = 0; i < num; i++)
                curr = curr->next;
            list.delete_element(curr);
            break;
        case 8:
            list.output();
            break;
        default:
            corr = 0;
            break;
        }
    }
    system("pause");
    return 0;
}
