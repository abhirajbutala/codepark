#include<iostream>
#include "assert.h"

using namespace std;


/*---------------------------------------------------------------------------*/
int binSearch(int *arr, int low, int high, int elem) {
    if (arr == NULL) {
        return -1;
    }

    int mid;
    while (low <= high) {
        mid = (low + high)/2;

        if (arr[mid] == elem) {
            return mid;
        } else if (arr[mid] < elem) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}


/*---------------------------------------------------------------------------*/
int binSearchRecursive(int *arr, int low, int high, int elem) {
    if (low > high) {
        return -1;
    }

    int mid = (low + high)/2;

    if (arr[mid] == elem) {
        return mid;
    } else if (arr[mid] < elem){
        return binSearchRecursive(arr, mid+1, high, elem);
    } else {
        return binSearchRecursive(arr, low, mid-1, elem);
    }
}


/*---------------------------------------------------------------------------*/
void rotatedArrayMinSearch(int *arr, int size) {
    if (arr == NULL) {
        return;
    }

    int start = 0;
    int end = size - 1;
    int mid;

    while (start < end) {
        mid = start + (end - start)/2;

        if (arr[mid] > arr[end]) {
            start = mid + 1;
        } else {
            end = mid;
        }
    }

    cout << "Minimum element is: " << arr[start] << endl;
}


/*---------------------------------------------------------------------------*/
void rotatedArrayElemSearch(int *arr, int size, int elem) {
    if (arr == NULL) {
        return;
    }

}


/*---------------------------------------------------------------------------*/
int main(int argc, char *argv[]) {

    int pos;
    int arr[] = {1, 3, 5, 6, 9, 10, 11};

    pos = binSearch(arr, 0, 6, 1);
    assert(pos == 0);
    pos = binSearch(arr, 0, 6, 5);
    assert(pos == 2);
    pos = binSearch(arr, 0, 6, 11);
    assert(pos == 6);
    pos = binSearch(arr, 0, 6, 12);
    assert(pos == -1);


    pos = binSearchRecursive(arr, 0, 6, 6);
    assert(pos == 3);
    pos = binSearchRecursive(arr, 0, 6, 11);
    assert(pos == 6);
    pos = binSearchRecursive(arr, 0, 6, 1);
    assert(pos == 0);
    pos = binSearchRecursive(arr, 0, 6, 21);
    assert(pos == -1);



    int arr2[] = {5, 6, 7, 8, 9, 10, 20, 40};
    rotatedArrayMinSearch(arr2, 8);

    int arr3[] = {5, 6, 7, 8, 9, 9, 1, 2, 3};
    rotatedArrayMinSearch(arr3, 9);

    int arr4[] = {5};
    rotatedArrayMinSearch(arr4, 1);

    int arr5[] = {5, 1, 2, 3};
    rotatedArrayMinSearch(arr5, 4);
    return 0;
}
