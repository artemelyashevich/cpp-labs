#include <iostream>
#include <cmath>

using namespace std;

void convertMoney(double price) {
    int rubles = static_cast<int>(price);
    cout << "Стоимость бумаги: " << rubles << " рублей " << static_cast<int>(round((price - rubles) * 100)) << " копеек" << endl;
}

void task1()
{
    double sum, time, bet;
    cout << "Введите сумму: " << endl;
    cin >> sum;
    cout << "Введите время (в днях): " << endl;
    cin >> time;
    if (sum > 5000)
        bet = 0.13;
    else
        bet = 0.1;
    double result = sum * bet * time / 365;
    convertMoney(result);
}

void task2()
{
    double priceWhite;
    double priceColor;
    int countWhite;
    int countColor;
    int rubles = 0;
    int typePeper;
    cout << "Цветная бумага: 0\nЧерно-белая бумага: 1\n" << endl;
    cin >> typePeper;
    if (typePeper == 1) {
        cout << "Введите стоимость черно-белой бумаги: " << endl;
        cin >> priceWhite;
        cout << "Введите кол-во черно-белой бумаги: " << endl;
        cin >> countWhite;
        if (countWhite > 50)
            priceWhite = (priceWhite - priceWhite * 0.05) * countWhite;
        else
            priceWhite = priceWhite * countWhite;
        convertMoney(priceWhite);
    }
    else {
        cout << "Введите стоимость цветной бумаги: " << endl;
        cin >> priceColor;

        cout << "Введите кол-во цветной бумаги: " << endl;
        cin >> countColor;

        if (countColor > 25)
            priceColor = (priceColor - priceColor * 0.05) * countColor;
        else
            priceColor = priceColor * countColor;
        convertMoney(priceColor);
    }
}

void task3()
{
    double a;
    double b;
    double c;
    double d;
    cout << "Введите a, b, c: " << endl;
    cin >> a >> b >> c;
    d = pow(b, 2) - 4 * a * c;
    if (d == 0)
    {
        cout << "X = " << -b / (2 * a) << endl;
    }
    else if (d < 0)
    {
        cout << "Нет решений" << endl;
    }
    else
    {
        cout << "X1 = " << (-b + pow(d, 0.5)) / (2 * a) << endl;
        cout << "X2 = " << (-b - pow(d, 0.5)) / (2 * a) << endl;
    }
}

void task4()
{
    double price;
    cout << "Введите сумму: " << endl;
    cin >> price;
    if ((price > 1000) && (price < 2000))
    {
        cout << "Кэшбек равен: " << ceil(price * 0.15) << endl;
    }
    else
    {
        cout << "Кэшбек равен: " << ceil(price * 0.2) << endl;
    }
}

void task5()
{
    double x;
    double y;
    cout << "Введите х: " << endl;
    cin >> x;
    double a = 0.2;
    double b = 0.5;
    double z = pow(2.718281828454590, a * x);
    if (x < log10(a))
        y = a * pow(sin(x), 2) + b * cos(z * x);
    else if ((x >= -log10(a)) && (x <= b))
        y = pow(a, b) - pow(cos(a + z * x), 3);
    else
        y = pow((2.5 * pow(a, 3) + pow((b - z * x * x), 6)), 0.5);
    cout << "y = " << y << endl;
}

int main()
{
    setlocale(LC_ALL, "rus");
    cout << "\tЗадание 1:\n " << endl;
    task1();
    cout << "\tЗадание 2:\n " << endl;
    task2();
    cout << "\tЗадание 3:\n " << endl;
    task3();
    cout << "\tЗадание 4:\n " << endl;
    task4();
    cout << "\tЗадание 5:\n " << endl;
    task5();
    system("pause");
    return 0;
}