#include <iostream>

using namespace std;

class Sort{
public:
    void Swap(int &Num1, int &Num2)
    {
        int temp = Num1;
        Num1 = Num2;
        Num2 = temp;
    }
    void Merge(int* TargetArray, int Left,
                         int Mid, int Right)
    {
        int n1 = Mid - Left + 1;
        int n2 = Right - Mid;


        int L[n1], R[n2];

        for (int i = 0; i < n1; i++)L[i] = TargetArray[Left + i];
        for (int j = 0; j < n2; j++)
            R[j] = TargetArray[Mid + 1 + j];

        int i = 0, j = 0;
        int k = Left;

        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                TargetArray[k] = L[i];
                i++;
            }
            else {
                TargetArray[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1) {
            TargetArray[k] = L[i];
            i++;
            k++;
        }
        while (j < n2) {
            TargetArray[k] = R[j];
            j++;
            k++;
        }
    }
    void MergeSort(int * TargetArray, int Left, int Right)
    {
            if (Left >= Right)
        return;

    int Mid = Left + (Right - Left) / 2;
    MergeSort(TargetArray, Left, Mid);
    MergeSort(TargetArray, Mid + 1, Right);
    Merge(TargetArray, Left, Mid, Right);
    }
    int Partition(int * TargetArray, int Low, int High) {

        int pivot = TargetArray[High];

        int i = Low - 1;

        for (int j = Low; j <= High - 1; j++) {
            if (TargetArray[j] < pivot) {
                i++;
                Swap(TargetArray[i], TargetArray[j]);
            }
        }
        Swap(TargetArray[i + 1], TargetArray[High]);
        return i + 1;
    }
    void quickSort(int * TargetArray, int Low, int High) {

        if (Low < High) {

            // pi is the partition return index of pivot
            int pi = Partition(TargetArray, Low, High);

            quickSort(TargetArray, Low, pi - 1);
            quickSort(TargetArray, pi + 1, High);
        }
    }
    void BubbleSort(int *Array, int ArraySize) {
        int sorted = 0;
        for (int outer = 0; sorted == 0; outer++) {
            sorted = 1;
            for (int i = 0; i < ArraySize - 1; i++) {
                if (Array[i] > Array[i + 1]) {
                    Swap(Array[i], Array[i + 1]);
                    sorted = 0;
                }
            }
        }
    }
    void InsertionSort(int * TargetArray, int ArraySize)
    {
        for (int i = 1; i < ArraySize; ++i) {
            int key = TargetArray[i];
            int j = i - 1;
            while (j >= 0 && TargetArray[j] > key) {
                TargetArray[j + 1] = TargetArray[j];
                j = j - 1;
            }
            TargetArray[j + 1] = key;
        }
    }
    void selectionSort(int * TargetArray, int ArraySize) {


        for (int i = 0; i < ArraySize - 1; ++i) {

            int Min = i;

            for (int j = i + 1; j < ArraySize; ++j) {
                if (TargetArray[j] < TargetArray[Min]) {

                    Min = j;
                }
            }


            Swap(TargetArray[i], TargetArray[Min]);
        }
    }


};
int main()
{
    Sort sorting;
    int arr1[5] = {3,2,5,1,14};
    int arr2[5] = {55,60,3,14,6};
    int arr3[5] = {4,2,15,6,20};
    int arr4[5] = {12,2,80,7,56};
    int arr5[5] = {64, 25, 12, 22, 11};
    sorting.MergeSort(arr1,0,4);
    sorting.quickSort(arr2,0,4);
    sorting.BubbleSort(arr3,5);
    sorting.InsertionSort(arr4,5);
    sorting.selectionSort(arr5,5);
    //cout << "Hello world!" << endl;
    for (int i = 0; i < 5; i++)
        cout << arr1[i] << " ";
    cout << endl;
    for (int i = 0; i < 5; i++)
        cout << arr2[i] << " ";
    cout << endl;
    for (int i = 0; i < 5; i++)
        cout << arr3[i] << " ";
    cout << endl;
    for (int i = 0; i < 5; i++)
        cout << arr4[i] << " ";
    cout << endl;
    for (int i = 0; i < 5; i++)
        cout << arr5[i] << " ";
    cout << endl;
    return 0;
}

