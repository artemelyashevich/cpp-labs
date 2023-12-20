#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

class Matrix
{
public:
    Matrix() = default;

    Matrix(const vector<double> &matrix, int SIZE)
        : matrix(matrix), SIZE(SIZE)
    {
    }

    bool operator==(const Matrix &other) const
    {
        return false;
    }

    vector<double> getMatrix()
    {
        return this->matrix;
    }

    void setMatrix(vector<double> matrix)
    {
        this->matrix = matrix;
    }

    void sollution()
    {

        double ratio = 0;
        this->printMAtrix();

        for (int i = 0; i < this->SIZE; i++)
        {
            if (this->matrix.at(i * (SIZE + 1) + i) == 0)
            {
                int j;
                for (j = i + 1; j < this->SIZE; j++)
                {
                    if (this->matrix.at(j * (this->SIZE + 1) + i) != 0)
                    {
                        this->swap(i, j);
                        break;
                    }
                }
                if (j == this->SIZE)
                {
                    cout << "Система уравнений не имеет единственного решения." << endl;
                    return;
                }
            }

            for (int j = 0; j < this->SIZE; j++)
            {
                if (i != j)
                {
                    ratio = this->matrix.at(j * (SIZE + 1) + i) / this->matrix.at(i * (SIZE + 1) + i);
                    for (int k = 0; k <= this->SIZE; k++)
                    {
                        this->matrix.at(j * (SIZE + 1) + k) -= ratio * this->matrix.at(i * (SIZE + 1) + k);
                    }
                }
            }
        }

        this->search();
        this->printSollution();
    }

private:
    vector<double> matrix;
    int SIZE = 3;

    void swap(int r1, int r2)
    {
        for (int i = 0; i <= this->SIZE; i++)
        {
            double temp = this->matrix.at(r1 * (this->SIZE + 1) + i);
            this->matrix.at(r1 * (SIZE + 1) + i) = this->matrix.at(r2 * (this->SIZE + 1) + i);
            this->matrix.at(r2 * (SIZE + 1) + i) = temp;
        }
    }

    bool handleError(int i)
    {
        return i == this->SIZE;
    }

    void search()
    {
        for (int i = 0; i < this->SIZE; i++)
        {
            this->matrix.at(i * (SIZE + 1) + this->SIZE) /= this->matrix.at(i * (SIZE + 1) + i);
            matrix.at(i * (SIZE + 1) + i) = 1;
        }
    }

    void printSollution()
    {
        cout << "Решение:" << endl;
        for (int i = 0; i < this->SIZE; i++)
        {
            cout << "x" << i + 1 << " = " << this->matrix.at(i * (SIZE + 1) + SIZE) << endl;
        }
    }

    void printMAtrix()
    {
        for (int i = 0; i < this->SIZE; i++)
        {
            for (int j = 0; j <= this->SIZE; j++)
            {
                cout << matrix[i * (this->SIZE + 1) + j] << "\t";
            }
            cout << "\n";
        }
    }
};

int main()
{
    setlocale(LC_ALL, "rus");

    srand(time(0));

    vector<vector<double>> matrix;

    int choice;

    cout << "Если хотите ввксти матрицу с клавиатуры, введите 1, иначе 0" << endl;

    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        int value;
        for (int i = 0; i < 3; i++)
        {
            vector<double> row;
            for (int j = 0; j <= 3; j++)
            {
                cin >> value;
                row.push_back(value);
            }
            matrix.push_back(row);
            row.clear();
        }
        break;
    }
    case 0:
    {
        for (int i = 0; i < 3; i++)
        {
            vector<double> row;
            for (int j = 0; j <= 3; j++)
            {
                row.push_back(rand() % 10);
            }
            matrix.push_back(row);
            row.clear();
        }
        break;
    }

    default:
        cout << "Неверный ввод!" << endl;
        return 1;
    }

    vector<double> newMatrix(12);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j <= 3; j++)
        {
            newMatrix.at(i * (4) + j) = matrix.at(i).at(j);
        }
    }

    Matrix matrix1;
    matrix1.setMatrix(newMatrix);
    matrix1.sollution();

    return 0;
}