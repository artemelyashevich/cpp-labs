// 11

#include <iostream>
#include <ctime>
#include <unordered_map>

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

void removeUniqueElements(List *head)
{
    unordered_map<int, int> elementCount;

    List *current = head->next;
    while (current != nullptr)
    {
        elementCount[current->value]++;
        current = current->next;
    }

    current = head;
    while (current->next != nullptr)
    {
        int value = current->next->value;
        if (elementCount[value] == 1)
        {
            List *temp = current->next;
            current->next = current->next->next;
            delete temp;
        }
        else
        {
            current = current->next;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");

    List list;
    list.value = 0;
    list.next = nullptr;

    fillListWithRandValues(&list, 1, 100, 20);
    cout << "Изначальный список" << endl;
    printList(list);
    cout << "Список, в котором нет не уникальных элементов" << endl;
    removeUniqueElements(&list);
    printList(list);
}