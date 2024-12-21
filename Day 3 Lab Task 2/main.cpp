#include <iostream>

using namespace std;

void SwapArray(int &pos1, int &pos2) {
    int temp = pos1;
    pos1 = pos2;
    pos2 = temp;
}

void BubbleSort(int *Array, int ArraySize) {
    int sorted = 0;
    for (int outer = 0; sorted == 0; outer++) {
        sorted = 1;
        for (int i = 0; i < ArraySize - 1; i++) {
            if (Array[i] > Array[i + 1]) {
                SwapArray(Array[i], Array[i + 1]);
                sorted = 0;
            }
        }
    }
}


int binarySearchonArray(int target, int Array[], int ArraySize) {
    int lo = 0, md, hi = ArraySize - 1;
    while (hi >= lo) {
        md = (lo + hi) / 2;
        if (Array[md] == target)
            return md;
        else if (Array[md] < target)
            lo = md + 1;
        else
            hi = md - 1;
    }
    return -1;
}

int binarySearchonLinkedList(int target, int Array[], int ArraySize) {

    return -1;
}


int main() {
    int arr[7] = {4, 5, 3, 2, 77, 0, 10};
    int size = 7;

    BubbleSort(arr, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int target = 10;
    int index = binarySearchonArray(target, arr, size);

    if (index != -1) {
        cout << "Element " << target << " found at index " << index << endl;
    } else {
        cout << "Element " << target << " not found in array." << endl;
    }

    return 0;
}
