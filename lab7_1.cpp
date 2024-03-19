#include <iostream>

double sumOfPositiveElements(double* arr, int size) {
    double sum = 0.0;

    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            sum += arr[i];
        }
    }

    return sum;
}

double productBetweenMinMax(double* arr, int size) {
    if (size == 0) {
        return 0.0;
    }

    double minValue = arr[0];
    double maxValue = arr[0];
    int minIndex = 0;
    int maxIndex = 0;

    for (int i = 1; i < size; i++) {
        if (std::abs(arr[i]) < std::abs(minValue)) {
            minValue = arr[i];
            minIndex = i;
        }

        if (std::abs(arr[i]) > std::abs(maxValue)) {
            maxValue = arr[i];
            maxIndex = i;
        }
    }

    if (minIndex == maxIndex) {
        return 0.0;
    }

    double product = 1.0;
    int startIndex = std::min(minIndex, maxIndex) + 1;
    int endIndex = std::max(minIndex, maxIndex);

    for (int i = startIndex; i < endIndex; i++) {
        product *= arr[i];
    }

    return product;
}

void sortArrayDescending(double* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    std::cout << "Enter the size of the array: ";
    std::cin >> n;

    double* arr = new double[n];

    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    double sumPositives = sumOfPositiveElements(arr, n);
    double product = productBetweenMinMax(arr, n);

    sortArrayDescending(arr, n);

    std::cout << "Sum of positive elements: " << sumPositives << std::endl;
    std::cout << "Product between min and max: " << product << std::endl;
    std::cout << "Sorted array in descending order: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    delete[] arr;

    return 0;
}