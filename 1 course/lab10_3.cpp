// 4,4 - 2

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList
{
private:
    Node *head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }

    void addElement(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void displayElements()
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void removeMaxElements()
    {
        if (head == nullptr)
            return;

        int maxVal = head->data;
        Node *current = head->next;
        Node *prev = head;

        while (current != nullptr)
        {
            if (current->data > maxVal)
                maxVal = current->data;
            current = current->next;
        }

        current = head;
        while (current != nullptr)
        {
            if (current->data == maxVal)
            {
                prev->next = current->next;
                delete current;
                current = prev->next;
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
    }

    void fillRandom(int count, int minVal, int maxVal)
    {
        srand(time(0));
        for (int i = 0; i < count; i++)
        {
            int randomValue = minVal + rand() % (maxVal - minVal + 1);
            addElement(randomValue);
        }
    }
};

int main()
{
    setlocale(LC_ALL, "RUS");
    LinkedList list;
    int choice;

    do
    {
        cout << "1. Добавить элемент" << endl;
        cout << "2. Просмотреть элементы" << endl;
        cout << "3. Удалить все наибольшие элементы, кроме одного" << endl;
        cout << "4. Заполнить список случайными числами" << endl;
        cout << "5. Выход" << endl;
        cout << "Выберите операцию: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int value;
            cout << "Введите значение элемента: ";
            cin >> value;
            list.addElement(value);
            cout << "Элемент добавлен" << endl;
            break;
        }
        case 2:
        {
            cout << "Элементы списка: ";
            list.displayElements();
            break;
        }
        case 3:
        {
            list.removeMaxElements();
            cout << "Наибольшие элементы, кроме одного, удалены" << endl;
            break;
        }
        case 4:
        {
            int count, minVal, maxVal;
            cout << "Введите количество элементов: ";
            cin >> count;
            cout << "Введите минимальное значение: ";
            cin >> minVal;
            cout << "Введите максимальное значение: ";
            cin >> maxVal;
            list.fillRandom(count, minVal, maxVal);
            cout << "Список заполнен случайными числами" << endl;
            break;
        }
        case 5:
            cout << "Программа завершена." << endl;
            break;
        default:
            cout << "Некорректный ввод. Попробуйте снова." << endl;
            break;
        }

        cout << endl;
    } while (choice != 5);

    return 0;
}