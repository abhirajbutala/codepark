#include<iostream>

using namespace std;


/*---------------------------------------------------------------------------*/
void binSearch(int *arr, int size, int elem) {
    if (arr == NULL) {
        return;
    }

    int start = 0;
    int end = size - 1;
    int mid;

    while (start <= end) {
        mid = (start + end)/2;

        if (arr[mid] == elem) {
            cout << "Element found!" << endl;
            return;
        } else if (arr[mid] < elem) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    cout << "Element not found!" << endl;
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

    int arr[] = {1, 3, 5, 6, 9, 10, 11};
    binSearch(arr, 7, 1);
    binSearch(arr, 7, 5);
    binSearch(arr, 7, 11);
    binSearch(arr, 7, 12);


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
