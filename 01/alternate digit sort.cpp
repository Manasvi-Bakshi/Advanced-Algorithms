#include <iostream>
using namespace std;

void insertionSortAscending(int array[], int num) {
    for (int i = 1; i < num; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void insertionSortDescending(int array[], int num) {
    for (int i = 1; i < num; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] < key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

void sortArray(int array[], int num) {
    int even[num / 2 + 1], odd[num / 2 + 1];
    int evenCount = 0, oddCount = 0;

    for (int i = 0; i < num; i++) {
        if (i % 2 == 0) {
            even[evenCount++] = array[i];
        } else {
            odd[oddCount++] = array[i];
        }
    }

    insertionSortAscending(even, evenCount);
    insertionSortDescending(odd, oddCount);

    cout << "Even-positioned elements (sorted ascending): ";
    for (int i = 0; i < evenCount; i++) {
        cout << even[i] << " ";
    }
    cout << endl;

    cout << "Odd-positioned elements (sorted descending): ";
    for (int i = 0; i < oddCount; i++) {
        cout << odd[i] << " ";
    }
    cout << endl;

    int evenIndex = 0, oddIndex = 0;

    for (int i = 0; i < num; i++) {
        if (i % 2 == 0) {
            array[i] = even[evenIndex++];
        } else {
            array[i] = odd[oddIndex++];
        }
    }
}

void print(int array[], int num) {
    cout << "Final sorted array: ";
    for (int i = 0; i < num; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    int array[] = {8, 4, 5, 2, 9, 1};
    int num = sizeof(array) / sizeof(array[0]);

    sortArray(array, num);
    print(array, num);

    return 0;
}
