// 4.4 - 17

#include <iostream>
#include <random>

using namespace std;

class Node
{
public:
    double data;
    Node *next;

    Node(double value) : data(value), next(nullptr) {}
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

    void addElement(double value)
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

    void insertRepeats(int count)
    {
        if (head == nullptr)
            return;

        Node *current = head;
        Node *prev = nullptr;
        double prevVal = current->data;
        int repeatCount = 1;

        while (current != nullptr)
        {
            if (current->data == prevVal)
            {
                repeatCount++;
            }
            else
            {
                if (repeatCount > 1)
                {
                    for (int i = 0; i < count; i++)
                    {
                        Node *newNode = new Node(prevVal);
                        if (prev == nullptr)
                        {
                            newNode->next = head;
                            head = newNode;
                        }
                        else
                        {
                            newNode->next = prev->next;
                            prev->next = newNode;
                        }
                        prev = newNode;
                    }
                }
                prevVal = current->data;
                repeatCount = 1;
            }

            prev = current;
            current = current->next;
        }

        if (repeatCount > 1)
        {
            for (int i = 0; i < count; i++)
            {
                Node *newNode = new Node(prevVal);
                prev->next = newNode;
                prev = newNode;
            }
        }
    }

    void fillRandom(int count, double minVal, double maxVal)
    {
        random_device rd;
        mt19937 gen(rd());
        uniform_real_distribution<double> dis(minVal, maxVal);

        for (int i = 0; i < count; i++)
        {
            double value = dis(gen);
            addElement(value);
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
        cout << "3. Вставить повторения" << endl;
        cout << "4. Заполнить рандомными числами" << endl;
        cout << "5. Выход" << endl;
        cout << "Выберите операцию: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            double value;
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
            int count;
            cout << "Введите количество повторений: ";
            cin >> count;
            list.insertRepeats(count);
            cout << "Повторения вставлены" << endl;
            break;
        }
        case 4:
        {
            int count;
            double minVal, maxVal;
            cout << "Введите количество элементов: ";
            cin >> count;
            cout << "Введите минимальное значение: ";
            cin >> minVal;
            cout << "Введите максимальное значение: ";
            cin >> maxVal;
            list.fillRandom(count, minVal, maxVal);
            cout << "Список заполнен рандомными числами" << endl;
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