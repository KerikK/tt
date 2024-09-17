#include <iostream>
#include <cstdlib>
#include <ctime>

// Function to check if a number is positive, negative, or zero
void checkNumber(int& num) {
    if (num > 0) {
        std::cout << "The number is positive." << std::endl;
    }
    else if (num < 0) {
        std::cout << "The number is negative." << std::endl;
    }
    else {
        std::cout << "The number is zero." << std::endl;
    }
}

// Function to fill an array with random double values
void fillArray(double* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = static_cast<double>(rand()) / RAND_MAX;
    }
}

// Function to display an array of double values
void displayDoubleArray(const double* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Function to swap elements at even indices with elements at odd indices in an integer array
void swapArrayElements(int* arr, int size) {
    for (int i = 0; i < size - 1; i += 2) {
        if (i + 1 < size) {
            std::swap(arr[i], arr[i + 1]);
        }
    }
}

// Function to display an array of integer values
void displayIntArray(const int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Function to split an integer array into positive and negative arrays
void splitArray(int* arr, int size, int*& positiveArr, int& posSize, int*& negativeArr, int& negSize) {
    posSize = 0;
    negSize = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] >= 0) {
            ++posSize;
        }
        else {
            ++negSize;
        }
    }

    positiveArr = new int[posSize];
    negativeArr = new int[negSize];

    int posIndex = 0;
    int negIndex = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] >= 0) {
            positiveArr[posIndex++] = arr[i];
        }
        else {
            negativeArr[negIndex++] = arr[i];
        }
    }
}

// Main function
int main() {
    srand(static_cast<unsigned>(time(0)));

    // Task 1
    int number;
    std::cout << "Task 1: Enter a number: ";
    std::cin >> number;
    checkNumber(number);

    // Task 2
    char choice;
    do {
        int size;
        std::cout << "Task 2: Enter the size of the array: ";
        std::cin >> size;

        double* array = new double[size];
        fillArray(array, size);
        std::cout << "Array: ";
        displayDoubleArray(array, size);
        delete[] array;

        std::cout << "Do you want to continue (y/n)? ";
        std::cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    // Task 3
    std::cout << "Task 3: Enter the size of the array: ";
    int size;
    std::cin >> size;

    int* array = new int[size];
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 100;
    }

    std::cout << "Initial array: ";
    displayIntArray(array, size);

    swapArrayElements(array, size);

    std::cout << "Array after swapping: ";
    displayIntArray(array, size);

    delete[] array;

    // Task 4
    std::cout << "Task 4: Enter the size of the array: ";
    std::cin >> size;

    int* arr = new int[size];
    std::cout << "Enter the elements of the array:" << std::endl;
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    int* positiveArr = nullptr;
    int* negativeArr = nullptr;
    int posSize, negSize;

    splitArray(arr, size, positiveArr, posSize, negativeArr, negSize);

    std::cout << "Positive elements of the array: ";
    displayIntArray(positiveArr, posSize);

    std::cout << "Negative elements of the array: ";
    displayIntArray(negativeArr, negSize);

    delete[] arr;
    delete[] positiveArr;
    delete[] negativeArr;

    return 0;
}
