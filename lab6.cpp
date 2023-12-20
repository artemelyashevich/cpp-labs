#include <iostream>
#include <vector>

using namespace std;

class Matrix
{
public:
    Matrix() = default;

    Matrix(vector<vector<int>> matrix, vector<int> vect)
    {
        this->matrix = matrix;
        this->vect = vect;
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

    vector<int> getVect()
    {
        return this->vect;
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

        // fill matrix 3x3
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

        /*cout << "Введите столбец свободных членов: " << endl;
        for (int i = 0; i < 3; i++) {
            cin >> value;
            this->freeM.push_back(value);
        }*/

        // fill matrix 1x3
        for (int i = 0; i < size; i++)
        {
            cin >> value;
            this->vect.push_back(value);
        }

        this->det = this->findDet(this->matrix);
        this->multiply();
        // this->kramerMethod();
    }

    void printResult()
    {
        for (double i : this->sollution)
        {
            cout << i << endl;
        }
    }

private:
    vector<vector<int>> matrix;
    vector<int> freeM;
    vector<int> vect;
    vector<double> sollution;
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
            this->sollution.push_back(i / this->det);
        }
    }

    void multiply()
    {
        for (int i = 0; i < 3; i++)
        {
            this->vect.at(i) = this->getInversMatrix().at(i).at(0) * this->vect.at(0) + this->getInversMatrix().at(i).at(1) * this->vect.at(1) + this->getInversMatrix().at(i).at(2) * this->vect.at(2);
        }
        for (int i : this->vect)
        {
            cout << i << endl;
        }
    }

    vector<vector<int>> getInversMatrix()
    {
        vector<vector<int>> inverseMatrix;
        vector<int> intermediateMatrix;
        intermediateMatrix.push_back(this->getMatrix().at(1).at(1) * this->getMatrix().at(2).at(2) - this->getMatrix().at(1).at(2) * this->getMatrix().at(2).at(1));
        intermediateMatrix.push_back(this->getMatrix().at(1).at(0) * this->getMatrix().at(2).at(2) - this->getMatrix().at(2).at(1) * this->getMatrix().at(2).at(0));
        intermediateMatrix.push_back(this->getMatrix().at(1).at(0) * this->getMatrix().at(2).at(1) - this->getMatrix().at(1).at(1) * this->getMatrix().at(2).at(0));
        inverseMatrix.push_back(intermediateMatrix);
        intermediateMatrix.clear();
        intermediateMatrix.push_back(this->getMatrix().at(0).at(1) * this->getMatrix().at(2).at(2) - this->getMatrix().at(0).at(2) * this->getMatrix().at(2).at(1));
        intermediateMatrix.push_back(this->getMatrix().at(0).at(0) * this->getMatrix().at(2).at(2) - this->getMatrix().at(0).at(2) * this->getMatrix().at(2).at(0));
        intermediateMatrix.push_back(this->getMatrix().at(0).at(0) * this->getMatrix().at(2).at(1) - this->getMatrix().at(0).at(1) * this->getMatrix().at(2).at(0));
        inverseMatrix.push_back(intermediateMatrix);
        intermediateMatrix.clear();
        intermediateMatrix.push_back(this->getMatrix().at(0).at(1) * this->getMatrix().at(1).at(2) - this->getMatrix().at(0).at(2) * this->getMatrix().at(1).at(1));
        intermediateMatrix.push_back(this->getMatrix().at(0).at(0) * this->getMatrix().at(1).at(2) - this->getMatrix().at(1).at(0) * this->getMatrix().at(0).at(2));
        intermediateMatrix.push_back(this->getMatrix().at(0).at(0) * this->getMatrix().at(1).at(1) - this->getMatrix().at(0).at(1) * this->getMatrix().at(1).at(0));
        inverseMatrix.push_back(intermediateMatrix);
        intermediateMatrix.clear();
        for (int i = 0; i < inverseMatrix.size(); i++)
        {
            for (int j = 0; j < inverseMatrix.at(i).size(); j++)
            {
                inverseMatrix.at(i).at(j) = inverseMatrix.at(i).at(j) / this->det;
            }
        }
        for (int i = 0; i < inverseMatrix.size(); i++)
        {
            for (int j = 0; j < inverseMatrix.at(i).size(); j++)
            {
                inverseMatrix.at(i).at(j) = inverseMatrix.at(j).at(i);
            }
        }
        return inverseMatrix;
    }
};

int main()
{
    setlocale(0, "rus");
    Matrix matrix1;
    matrix1.setMatrix(3);
    // matrix1.printResult();
    return 0;
}