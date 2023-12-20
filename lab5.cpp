#include <iostream>
#include <vector>

using namespace std;

class Matrix
{
public:
    Matrix() = default;

    Matrix(vector<vector<int>> matrix)
    {
        this->matrix = matrix;
    }

    bool operator==(const Matrix &other) const
    {
        return matrix == other.matrix;
    }

    vector<vector<int>> getMatrix()
    {
        return this->matrix;
    };

    double getDet()
    {
        return this->det;
    }

    vector<int> getFreeM()
    {
        return this->freeM;
    }

    void printMatrix()
    {
        for (vector<int> row : this->matrix)
        {
            for (int i : row)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }

    void setMatrix(int size)
    {
        int value;
        vector<int> row;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cin >> value;
                row.push_back(value);
            }
            this->matrix.push_back(row);
            row.clear();
        }
        cout << "Введите столбец свободных членов: " << endl;
        for (int i = 0; i < 3; i++)
        {
            cin >> value;
            this->freeM.push_back(value);
        }
        this->det = this->findDet(this->matrix);
        this->kramerMethod();
    }

    void printResult()
    {
        for (double i : this->solution)
        {
            cout << i << endl;
        }
    }

private:
    vector<vector<int>> matrix;
    vector<int> freeM;
    vector<double> solution;
    double det = 0;

    double findDet(vector<vector<int>> matrix)
    {
        size_t sizeMatrix = matrix.size();
        vector<vector<int>> newMatrix = matrix;
        int leftMultiply = 1, rightMultiply = 1;
        int leftSum = 0, rightSum = 0;

        for (int i = 0; i < sizeMatrix; i++)
        {

            for (int j = 0; j < matrix.at(i).size() - 1; j++)
            {
                newMatrix.at(i).push_back(matrix.at(i).at(j));
            }
        }
        for (int i = 0; i < sizeMatrix; i++)
        {
            for (int pos = 0; pos < sizeMatrix; pos++)
            {
                leftMultiply *= newMatrix.at(pos).at(pos + i);
                rightMultiply *= newMatrix.at(pos).at(sizeMatrix - pos + i - 1);
            }
            leftSum += leftMultiply;
            rightSum += rightMultiply;
            rightMultiply = 1;
            leftMultiply = 1;
        }
        return leftSum - rightSum;
    }

    void kramerMethod()
    {
        vector<vector<int>> intermediateMatrix = this->getMatrix();
        vector<double> detArray;
        int position = 0;
        size_t size = intermediateMatrix.size();
        for (int i = 0; i < 3; i++)
        {
            position = i;
            for (int j = 0; j < 3; j++)
            {
                intermediateMatrix.at(j).at(i) = this->getFreeM().at(j);
            }
            detArray.push_back(this->findDet(intermediateMatrix));
            intermediateMatrix = this->getMatrix();
        }
        for (double i : detArray)
        {
            this->solution.push_back(i / this->det);
        }
    }
};

int main()
{
    setlocale(0, "rus");
    Matrix matrix1;
    matrix1.setMatrix(3);
    matrix1.printResult();
    return 0;
}