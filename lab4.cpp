#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void task1()
{
    unsigned long long int number;
    cin >> number;
    int max = number % 10;
    while (number > 0)
    {
        if (number % 10 > max)
            max = number % 10;
        number /= 10;
    }
    cout << max << endl;
}

bool isPrime(int number)
{
    for (int i = 2; i <= number / 2; i++)
    {
        if (number % i == 0)
            return false;
    }
    return true;
}

void task2()
{
    int number;
    cin >> number;
    if (isPrime(number))
    {
        cout << number << endl;
    }
    else
    {
        for (int i = 2; i <= number / 2; i++)
        {
            if (number % i == 0 && isPrime(i))
            {
                cout << i << endl;
            }
        }
    }
}

bool isExcelent(unsigned long long int number)
{
    int result = 0;
    for (int i = 1; i < number; i++)
    {
        if (number % i == 0)
        {
            result += i;
        }
    }
    return result == number;
}

void task3()
{
    unsigned long long int number;
    cin >> number;
    for (int i = 1; i < number; i++)
    {
        if (isExcelent(i))
            cout << i << endl;
    }
}

void task4()
{
    int n;
    double sum = 0;
    cin >> n;
    for (int k = 1; k < n; k++)
    {
        sum += (pow(-1, k) * (k - 7)) / (2 * tgamma(n - k + 1));
    }
    cout << fixed << setprecision(2) << sum << endl;
}

int main()
{
    setlocale(0, "rus");
    cout << "\tЗадание 1" << endl;
    task1();
    cout << "\tЗадание 2" << endl;
    task2();
    cout << "\tЗадание 3" << endl;
    task3();
    cout << "\tЗадание 4" << endl;
    task4();
    return 0;
}