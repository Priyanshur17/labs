#include <iostream>

using namespace std;
int findSum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}


float findAverage(int arr[], int size) {
    return static_cast<float>(findSum(arr, size)) / size;
}


int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}


int findMin(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main() {
    int size;

    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    cout << "Sum: " << findSum(arr, size) << endl;
    cout << "Average: " << findAverage(arr, size) << endl;
    cout << "Maximum: " << findMax(arr, size) << endl;
    cout << "Minimum: " << findMin(arr, size) << endl;

    return 0;
}

