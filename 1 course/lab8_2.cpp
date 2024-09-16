#include <iostream>
#include <string>
#include <vector>
#include <ctime>

struct AutoRepair
{
    std::string carBrand;
    int repairCode;
    double repairPrice;
    std::string clientInfo;
    std::string orderDate;
};

bool isLastTwoMonths(const std::string &orderDate)
{
    std::time_t currentTime = std::time(nullptr);
    std::tm *now = std::localtime(&currentTime);
    std::tm orderTime = {};
    std::istringstream(orderDate) >> std::get_time(&orderTime, "%d.%m.%Y");
    return (now->tm_year == orderTime.tm_year && now->tm_mon - orderTime.tm_mon <= 2);
}

int main()
{
    const int numOrders = 5;
    std::vector<AutoRepair> orders(numOrders);

    for (int i = 0; i < numOrders; i++)
    {
        AutoRepair order;

        std::cout << "Введите марку автомобиля: ";
        std::getline(std::cin >> std::ws, order.carBrand);

        std::cout << "Введите код ремонтной работы: ";
        std::cin >> order.repairCode;

        std::cout << "Введите цену ремонта: ";
        std::cin >> order.repairPrice;

        std::cout << "Введите сведения о клиенте (Фамилия И.О.): ";
        std::getline(std::cin >> std::ws, order.clientInfo);

        std::cout << "Введите дату приема заказа (ДД.ММ.ГГГГ): ";
        std::getline(std::cin >> std::ws, order.orderDate);

        orders[i] = order;
    }

    std::vector<int> recentOrders;

    for (int i = 0; i < numOrders; i++)
    {
        if (isLastTwoMonths(orders[i].orderDate))
        {
            recentOrders.push_back(i);
        }
    }

    std::cout << "\nНомера заказов самых дорогих ремонтов за последние два месяца:\n";

    double maxPrice = 0.0;

    for (const auto &orderIndex : recentOrders)
    {
        if (orders[orderIndex].repairPrice > maxPrice)
        {
            maxPrice = orders[orderIndex].repairPrice;
        }
    }

    for (const auto &orderIndex : recentOrders)
    {
        if (orders[orderIndex].repairPrice == maxPrice)
        {
            std::cout << "Номер заказа: " << orderIndex + 1 << std::endl;
        }
    }

    return 0;
}