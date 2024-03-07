#include <iostream>
using namespace std;

//Pivot as First element rather than the last element

int Partition(int arr[], int left, int right) {
    int pivot = arr[left];
    int i = left;
    int j = right;
    while (i < j) {
        while (arr[i] <= pivot && i < right) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[left], arr[j]);

    return j;
}

void QuickSort(int arr[], int left, int right) {
    if (left < right) {
        int loc = Partition(arr, left, right);
        QuickSort(arr, left, loc - 1);
        QuickSort(arr, loc + 1, right);
    }
}

void printArray(int arr[], const int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {59, 53, 55, 97, 103, 49, 3, 117, 35};
    constexpr int arrSize = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, arrSize);

    QuickSort(arr, 0, arrSize - 1);

    cout << "Sorted array:   ";
    printArray(arr, arrSize);

    return 0;
}
