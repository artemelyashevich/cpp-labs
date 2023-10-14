#include <iostream>
#include <vector>

using namespace std;

void task1()
{
	double v, u, t1, t2;
	cout << "Введите скорость лодки: " << endl;
	cin >> v;
	cout << "Введите время, которое потребоволось лодке, чтобы пересечь озеро: " << endl;
	cin >> t1;
	cout << "Введите скорость течения реки: " << endl;
	cin >> u;
	if (u > v) {
		cout << "Скорость лодки должна быть больше скорости течения!" << endl;
	}
	else {
		cout << "Введите время, которое потребоволось лодке, чтобы пересечь реку: " << endl;
		cin >> t2;
		cout << "\nПуть, пройденный лодкой по озеру: " << v * t1 << endl;
		cout << "\nПуть, пройденный лодкой по реке: " << (v - u) * t2 << endl;
	}
}

void task2() 
{
	double v1, v2, s, t;
	cout << "Введите скорость первого автомобиля: " << endl;
	cin >> v1;
	cout << "Введите скорость второго автомобиля: " << endl;
	cin >> v2;
	cout << "Введите расстояние между автомобилями:  " << endl;
	cin >> s;
	cout << "Введите время: " << endl;
	cin >> t;
	cout << "\nРасстояние между автомобилями: " << abs(s - (v1 + v2) * t) << endl;
}

class Task3 {
public:
	Task3(int c, int v) {
		this->c = c;
		this->v = v;
	}

	void solution() {
		this->fillMatrix();
		this->printMatrix();
		this->findDet();
		this->findSolution();
		this->printSolution();
	}

private:
	int c, v;
	vector<vector<double>> matrix;
	vector<double> x;
	double det;

	void fillMatrix() {
		vector<double> curr = {};
		double val;
		cout << "Введите коэффиценты: " << endl;
		for (int i = 0; i < this->c; i++) {
			for (int j = 0; j < this->v; j++) {
				cin >> val;
				curr.push_back(val);
			}
			this->matrix.push_back(curr);
			curr.clear();
		}
	}

	void printMatrix() {
		cout << endl << "Матрица: \n" << endl;
		for (vector<double> i : this->matrix) {
			copy(i.begin(), i.end(), ostream_iterator<int>(cout, " "));
			cout << endl;
		}
	}

	void findDet() {
		this->det = this->matrix[0][0] * this->matrix[1][1] - this->matrix[0][1] * this->matrix[1][0];
	}

	void findSolution() {
		if (this->det != 0) {
			double det1 = this->matrix[0][2] * this->matrix[1][1] - this->matrix[0][1] * this->matrix[1][2];
			double det2 = this->matrix[0][0] * this->matrix[1][2] - this->matrix[0][2] * this->matrix[1][0];
			this->x.push_back(det1 / this->det);
			this->x.push_back(det2 / this->det);
		}
		else cout << "Система не имеет одного решения..." << endl;
	}

	void printSolution() {
		for (int i = 0; i < this->x.size(); i++) {
			cout << i + 1 << " корень = " << this->x[i] << endl;
		}
	}
};

#include <iostream>
#include <vector>

using namespace std;

void task4()
{
	int x;
	cout << "Введите день: " << endl;
	cin >> x;
	if (x > 365 || x < 0) {
		cout << "Неверный ввод" << endl;
	}
	else {
		vector<string> days = { "Воскресенье", "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота" };
		if (x % 7 == 0) {
			cout << days.at(days.size() - 1) << endl;
		}
		else cout << days.at((x % 7) - 1) << endl;
	}
}

void task5() {
	int a, b, c;
	cout << "Введите 1 сторону прямоугольника: " << endl;
	cin >> a;
	cout << "Введите 2 сторону прямоугольника: " << endl;
	cin >> b;
	cout << "Введите сторону квадрата: " << endl;
	cin >> c;
	int s = (a / c) * (b / c);
	int square = (a * b) - (s * c * c);
	cout << "Всего квадратов: " << s << endl;
	cout << "Свободная площадь: " << square << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	//task4();
	//Task3 task3 = Task3(2, 3);
	//task3.solution();
	task4();
	//task5();
	return 0;
}