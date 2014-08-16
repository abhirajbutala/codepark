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
/* Please refer to Algorithm Design Manual Section 4.9.1 (Page 133) for more
 * details on the algorithm.
 *
 * This algorithm is O(lg n), which is better than O(lg n + s) algorithm in
 * which the binary search for the element is performed and then the low and
 * high positions of the element are found after linear traversal from the
 * position returned by binary search.
 */
int getLowPos(int *arr, int low, int high, int elem) {
    if (low > high) {
        return low;
    }

    int mid = (low + high)/2;
    if (arr[mid] < elem) {
        return getLowPos(arr, mid+1, high, elem);
    } else {
        return getLowPos(arr, low, mid-1, elem);
    }
}

int getHighPos(int *arr, int low, int high, int elem) {
    if (high < low) {
        return high;
    }

    int mid = (low + high)/2;
    if (arr[mid] > elem) {
        return getHighPos(arr, low, mid-1, elem);
    } else {
        return getHighPos(arr, mid+1, high, elem);
    }
}

int elementCount(int *arr, int low, int high, int elem) {
    if (arr == NULL) {
        return 0;
    }

    // Find low and high positions of the element & return the difference.
    int lowPos = getLowPos(arr, low, high, elem);
    //cout << "low position is : " << lowPos << endl;
    int highPos = getHighPos(arr, low, high, elem);
    //cout << "high position is : " << highPos << endl;

    return (highPos - lowPos + 1);
}


/*---------------------------------------------------------------------------*/
int main(int argc, char *argv[]) {

    int pos;
    int arr[] = {1, 3, 5, 6, 9, 10, 11};

    /* Binary Search Non-Recursive */
    pos = binSearch(arr, 0, 6, 1);
    assert(pos == 0);
    pos = binSearch(arr, 0, 6, 5);
    assert(pos == 2);
    pos = binSearch(arr, 0, 6, 11);
    assert(pos == 6);
    pos = binSearch(arr, 0, 6, 12);
    assert(pos == -1);


    /* Binary Search Recursive */
    pos = binSearchRecursive(arr, 0, 6, 6);
    assert(pos == 3);
    pos = binSearchRecursive(arr, 0, 6, 11);
    assert(pos == 6);
    pos = binSearchRecursive(arr, 0, 6, 1);
    assert(pos == 0);
    pos = binSearchRecursive(arr, 0, 6, 21);
    assert(pos == -1);


    /* Minimum element from Sorted Rotated Array */
    int arr2[] = {5, 6, 7, 8, 9, 10, 20, 40};
    rotatedArrayMinSearch(arr2, 8);
    int arr3[] = {5, 6, 7, 8, 9, 9, 1, 2, 3};
    rotatedArrayMinSearch(arr3, 9);
    int arr4[] = {5};
    rotatedArrayMinSearch(arr4, 1);
    int arr5[] = {5, 1, 2, 3};
    rotatedArrayMinSearch(arr5, 4);

    /* Counting occurances of a element in sorted array */
    int arr6[] = {1, 2, 3, 4, 4, 4, 4, 5, 5, 6};
    assert (elementCount(arr6, 0, 9, 2) == 1);
    assert (elementCount(arr6, 0, 9, 4) == 4);
    assert (elementCount(arr6, 0, 9, 5) == 2);
    assert (elementCount(arr6, 0, 9, 10) == 0);
    assert (elementCount(arr6, 0, 9, -1) == 0);

    return 0;
}
