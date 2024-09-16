#include <iostream>
#include <string>
#include <vector>

struct CompetitionResult
{
    std::string fullName;
    std::string sportsClub;
    std::string category;
    int accuracy;
};

int main()
{
    setlocale(LC_ALL, "rus");
    const int numResults = 5;

    std::vector<CompetitionResult> results(numResults);

    for (int i = 0; i < numResults; i++)
    {
        CompetitionResult result;

        std::cout << "Введите Фамилию И.О. спортсмена: ";
        std::cin >> result.fullName;

        std::cout << "Введите название спортивного товарищества: ";
        std::cin >> result.sportsClub;

        std::cout << "Введите категорию (биатлон, триатлон): ";
        std::string cat;
        std::cin >> cat;
        if (cat != "биатлон" || cat != "триатлон")
        {
            std::cout << "Такой категории не существует";
            return;
        }
        result.category = cat;
        std::cout << "Введите точность стрельбы (очки, число до 100): ";
        int acc;
        std::cin >> acc;
        if (acc < 0 || acc > 100)
        {
            std::cout << "Точность может быть от 0 до 100!" << std::endl;
            return;
        }
        result.accuracy = acc;
        results[i] = result;
    }

    // Подсчет очков для каждого товарищества
    std::vector<std::string> sportsClubs;
    std::vector<int> points;

    for (const auto &result : results)
    {
        auto it = std::find(sportsClubs.begin(), sportsClubs.end(), result.sportsClub);

        if (it != sportsClubs.end())
        {
            int index = std::distance(sportsClubs.begin(), it);
            points[index] += result.accuracy;
        }
        else
        {
            sportsClubs.push_back(result.sportsClub);
            points.push_back(result.accuracy);
        }
    }
    std::cout << "\nРезультаты:\n";
    for (size_t i = 0; i < sportsClubs.size(); i++)
    {
        std::cout << "Товарищество: " << sportsClubs[i] << ", Очки: " << points[i] << std::endl;
    }
    return 0;
}