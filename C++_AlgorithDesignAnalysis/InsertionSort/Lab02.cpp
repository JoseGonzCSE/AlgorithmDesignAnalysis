#include <iostream>
#include <math.h>
#define MAX_INT 2147483647

using namespace std;

//start of void merge function 
void merge(int arrayPtr[], int left, int mid, int right) {

    //
    int n1 = mid - left + 1;
    int n2 = right - mid;

    //
    int *leftArrayPtr = new int[n1 + 1];
    int *rightArrayPtr = new int[n2 + 1];

    //
    for (int i = left; i <= mid; i++) {
        leftArrayPtr[i - left] = arrayPtr[i];
    }

    //
    for (int j = mid + 1; j <= right; j++) {
        rightArrayPtr[j - mid - 1] = arrayPtr[j];
    }

    //
    leftArrayPtr[mid - left + 1] = MAX_INT;
    rightArrayPtr[right - mid] = MAX_INT;

    //
    int indexL = 0;
    int indexR = 0;

    //
    for (int k = left; k <= right; k++) {

        //
        if (leftArrayPtr[indexL] <= rightArrayPtr[indexR]) {
            arrayPtr[k] = leftArrayPtr[indexL];
            indexL++;   
        }

        //
        else {
            arrayPtr[k] = rightArrayPtr[indexR];
            indexR++; 
        }

    }

//end of void merge fuction
}

//start of void mergeSort function 
void mergeSort(int arrayPtr[], int left, int right) {

    //
    if (left < right) {

        //
        int mid = floor((left + right) / 2);

        //
        mergeSort(arrayPtr, left, mid);

        //
        mergeSort(arrayPtr, mid + 1, right);

        //
        merge(arrayPtr, left, mid, right);
    }

//end of void mergeSort function 
}

//start of main function
int main() {

    //
    int arrayLength;

    //
    cin >> arrayLength;

    //
    int *arrayPtr = new int[arrayLength];


    //
    for (int i = 0; i < arrayLength; i++) {
        cin >> arrayPtr[i];
    }

    //
    int left = 0;
    int right = arrayLength - 1;

    //
    mergeSort(arrayPtr, left, right);

    //
    for (int i = 0; i < arrayLength; i++) {
        cout << arrayPtr[i] << ";";
    }

    //end of main function
    return 0;
}