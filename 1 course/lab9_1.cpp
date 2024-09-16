// 7

#include <iostream>
#include <ctime>

using namespace std;

struct List
{
    int value;
    List *next;

    void pushBack(int v)
    {
        List *newNode = new List();
        newNode->value = v;
        newNode->next = nullptr;

        if (next == nullptr)
        {
            next = newNode;
            return;
        }

        List *last = next;
        while (last->next != nullptr)
        {
            last = last->next;
        }
        last->next = newNode;
    }
};

void fillListWithRandValues(List *head, int minValue, int maxValue, int count)
{
    srand(time(nullptr));

    List *current = head;

    for (int i = 0; i < count; ++i)
    {
        int randomValue = rand() % (maxValue - minValue + 1) + minValue;
        current->pushBack(randomValue);
        current = current->next;
    }
}

void duplicateEvenElements(List *head)
{
    List *current = head->next;

    while (current != nullptr)
    {
        if (current->value % 2 == 0)
        {
            List *newNode = new List();
            newNode->value = current->value;
            newNode->next = current->next;

            current->next = newNode;
            current = newNode->next;
        }
        else
        {
            current = current->next;
        }
    }
}

void printList(List list)
{
    List *current = list.next;
    while (current != nullptr)
    {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    setlocale(LC_ALL, "RUS");

    List list;
    list.value = 0;
    list.next = nullptr;

    fillListWithRandValues(&list, 1, 100, 10);
    cout << "Изначальный список" << endl;
    printList(list);
    cout << "Список с продублированными элементами" << endl;
    duplicateEvenElements(&list);
    printList(list);
}