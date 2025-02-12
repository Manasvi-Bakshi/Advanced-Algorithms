#include <iostream>
using namespace std;

void mergeThreeArrays(int array1[], int size1, int array2[], int size2, int array3[], int size3, int result[]) {
    int i = 0, j = 0, k = 0, m = 0;

    while (i < size1 && j < size2 && k < size3) {
        if (array1[i] <= array2[j] && array1[i] <= array3[k]) {
            result[m++] = array1[i++];
        } else if (array2[j] <= array1[i] && array2[j] <= array3[k]) {
            result[m++] = array2[j++];
        } else {
            result[m++] = array3[k++];
        }
    }

    while (i < size1 && j < size2) {
        if (array1[i] <= array2[j]) {
            result[m++] = array1[i++];
        } else {
            result[m++] = array2[j++];
        }
    }

    while (i < size1 && k < size3) {
        if (array1[i] <= array3[k]) {
            result[m++] = array1[i++];
        } else {
            result[m++] = array3[k++];
        }
    }

    while (j < size2 && k < size3) {
        if (array2[j] <= array3[k]) {
            result[m++] = array2[j++];
        } else {
            result[m++] = array3[k++];
        }
    }

    while (i < size1) {
        result[m++] = array1[i++];
    }

    while (j < size2) {
        result[m++] = array2[j++];
    }

    while (k < size3) {
        result[m++] = array3[k++];
    }
}

void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main() {
    int array1[] = {1, 4, 7};
    int array2[] = {2, 5, 8};
    int array3[] = {3, 6, 9};
    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);
    int size3 = sizeof(array3) / sizeof(array3[0]);
    int result[size1 + size2 + size3];

    mergeThreeArrays(array1, size1, array2, size2, array3, size3, result);
    cout << "Merged array: ";
    printArray(result, size1 + size2 + size3);

    return 0;
}
