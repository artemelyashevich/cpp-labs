#include <iostream>
#include <iomanip>
#include <random>
#include <vector>
#include <map>

using namespace std;

void task1() {
	string operations[3] = { "камень", "ножницы", "бумагу" };
	int user;
	int ai = rand() % 3 + 1;
	cout << "Камень(1)\nНожницы(2)\nБумага(3)\n" << endl;
	cin >> user;
	cout << "\nКомпьютер выбрал " << operations[ai - 1] << endl;
	if ((user == 1) && (ai == 3) || (user == 2) && (ai == 1) || (user == 3) && (ai == 2)) cout << "\nКомпьтер выиграл" << endl;
	if ((user == 1) && (ai == 2) || (user == 2) && (ai == 3) || (user == 3) && (ai == 1)) cout << "\nВы выиграли" << endl;
	else if (user == ai) cout << "Ничья" << endl;
};

void printResult(char operation, int a, int b, int result) {
	cout << a << " " << operation << " " << b << " = " << result << endl;
}

void task2() {
	// так как есть операция факторила, то пользователь должен ввести целые числа
	int a;
	int b;
	char operation;
	cout << "\tумножение (*)\n\tсложение (+)\n\tвычитание (-)\n\tделение (:)\n\tделение с остатком (%)\n\tделение нацело (/)\n\tчисло размещений (r)\n\tчисло сочетаний (s)\n" << endl;
	int cond = 1;
	do
	{
		cout << "Введите первое число:" << endl;
		cin >> a;
		cout << "Введите операцию:" << endl;
		cin >> operation;

		if (operation != '!') {
			cout << "Введите второе число:" << endl;
			cin >> b;
			switch (operation)
			{
			case '*': {
				printResult(operation, a, b, a * b);
				break;
			}
			case '+': {
				printResult(operation, a, b, a + b);
				break;
			}
			case '-': {
				printResult(operation, a, b, a - b);
				break;
			}
			case '%': {
				printResult(operation, a, b, a % b);
				break;
			}
			case '/': {
				printResult(operation, a, b, a / b);
				break;
			}
			case ':':
				cout << a << " : " << b << " = " << double(a) / double(b) << endl;
				break;
			case 'r':
			{
				cout << "Число размещений = " << fixed << setprecision(0) << tgamma(a + 1) / tgamma(a - b + 1) << endl;
				break;
			}
			case 's':
			{
				cout << "Число сочетаний = " << fixed << setprecision(0) << (tgamma(a + 1) / tgamma(a - b + 1)) / tgamma(b + 1) << endl;
				break;
			}
			default: break;
			}
		}
		else {
			if (a <= 20) {
				cout << a << "! = " << fixed << setprecision(0) << tgamma(a + 1) << endl;
			}
			else {
				cout << a << "! = " << fixed << setprecision(0) << tgamma(a + 1) << endl;
			}
		}
		cout << "Чтобы продолжить нажмите 1, чтобы завершить 0" << endl;
		cin >> cond;
	} while (cond != 0);
}

void task3() {
	cout << "Если вы согласны с высказыванием, введите 1, иначе 0\n" << endl;

	vector<pair<int, string>> questions;

	vector<pair<float, string>> results;

	questions.push_back({ 1, "Ректор мехмата - Босяков С. М." });
	questions.push_back({ 1, "Заместитель декана по учебно-воспитательной работе и соц вопросам - Курсов В. В." });
	questions.push_back({ 1, "В Беларуси люди гораздо богаче чем на западе. В США средняя зарплата меньше миллиона долларов. А в Беларуси меньше миллиарда долларов." });
	questions.push_back({ 1, "лучший куратор - Ванек, забей ***" });
	questions.push_back({ 0, "В состав факультета входят 8 кафедр" });
	questions.push_back({ 0, "Аудитории мехмата занимают третий этаж главного корпуса БГУ" });
	questions.push_back({ 0, "Поток: «Можете писать побольше (крупнее) - ничего не видно» \nВоронович И.И.:" });
	questions.push_back({ 1, "Пример идеала - мехмат" });
	questions.push_back({ 1, "Водка в малых количествах полезна в любом объеме" });
	questions.push_back({ 1, "Мы с Китаем самые сильные в мире, нас 9 миллионов и их 2 милиарда." });
	questions.push_back({ 1, "Артиллерия всегда по своим стреляет" });
	questions.push_back({ 0, "Витя молодец" });
	questions.push_back({ 1, "Бутерброд с ветчиной лучше вечного блаженства?" });
	questions.push_back({ 1, "Ха тэ эм эл" });
	questions.push_back({ 1, "Скажем родине спасибо за то, что у нас есть четверги" });
	questions.push_back({ 0, "Пушкину нужна была математика, чтобы его застрелили" });
	questions.push_back({ 1, "Неравенство Ленин отменил, но мы всё равно изучаем" });
	questions.push_back({ 1, "Студент бгу - элита общества" });
	questions.push_back({ 1, "бгу - флагман белорусской науки" });
	questions.push_back({ 1, "Алигн итемс" });
	questions.push_back({ 1, "При входе преподавателя будем практиковать громкие аплодисменты, плавно переходящие в бурные овации" });

	results.push_back({ 25, "абитуриент" });
	results.push_back({ 50, "обезьяна" });
	results.push_back({ 75, "Шамонин" });
	results.push_back({ 100, "легедна мехмата" });

	vector<int> answers;

	int answer;

	for (pair<int, string> question : questions) {
		cout << question.second << endl;
		cin >> answer;
		answers.push_back(answer);
	}

	int countR = 0;

	for (int i = 0; i < answers.size() - 1; i++) {
		if (answers.at(i) == questions.at(i).first) countR++;
	}

	float result = ((double)countR / (double)questions.size()) * 100;

	cout << "Вы ответили верно на " << setprecision(2) << result << "% вопросов" << endl;

	for (pair<float, string> i : results) {
		if (int(result) <= i.first) {
			cout << "\nВаш уровень: " << i.second << endl;
			break;
		}
	}
}


int main() {
	setlocale(0, "rus");
	srand(time(0));
	cout << "\t----Task1----\n" << endl;
	task1();
	system("pause");
	cout << "\n\t----Task2----\n" << endl;
	task2();
	system("pause");
	cout << "\n\t----Task3----\n" << endl;
	task3();
	system("pause");
	return 0;
}