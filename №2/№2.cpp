#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void fillArrayRandomly(std::vector<int>& arr, int size, int min, int max) {
    for (int i = 0; i < size; ++i) {
        arr.push_back(getRandomNumber(min, max));
    }
}

void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

void removeFibonacciNumbers(std::vector<int>& arr) {
    std::vector<int> result;
    for (int num : arr) {
        int a = 0, b = 1, fib = 0;
        while (fib < num) {
            fib = a + b;
            a = b;
            b = fib;
        }
        if (fib != num) {
            result.push_back(num);
        }
    }
    arr = result;
}

void sortColumnsDescending(std::vector<std::vector<int>>& matrix) {
    for (size_t j = 0; j < matrix[0].size(); ++j) {
        std::vector<int> column;
        for (size_t i = 0; i < matrix.size(); ++i) {
            column.push_back(matrix[i][j]);
        }
        std::sort(column.begin(), column.end(), std::greater<int>());
        for (size_t i = 0; i < matrix.size(); ++i) {
            matrix[i][j] = column[i];
        }
    }
}

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    srand(time(nullptr));

    int size = 10;
    int matrixRows = 5;
    int matrixColumns = 5;

    std::vector<int> array;
    fillArrayRandomly(array, size, -50, 50);

    std::cout << "A one-dimensional array:" << std::endl;
    printArray(array);
    std::cout << std::endl;

    removeFibonacciNumbers(array);
    std::cout << "Array after removing Fibonacci numbers:" << std::endl;
    printArray(array);
    std::cout << std::endl;

    std::vector<std::vector<int>> matrix(matrixRows, std::vector<int>(matrixColumns));
    for (int i = 0; i < matrixRows; ++i) {
        fillArrayRandomly(matrix[i], matrixColumns, -50, 50);
    }

    std::cout << "Two-dimensional array before sorting columns:" << std::endl;
    printMatrix(matrix);
    std::cout << std::endl;

    sortColumnsDescending(matrix);
    std::cout << "Two-dimensional array after sorting columns in descending order:" << std::endl;
    printMatrix(matrix);

    return 0;
}