#include<iostream>
#include<queue>

using namespace std;

/*****************************************************************************/
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
    cout << "Swapped " << *a << " and " << *b << "\n";
}

void print_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << "\t";
    }
    cout << "\n";
}

/*****************************************************************************/
void selection_sort(int *arr, int size) {
    int min;

    for (int i = 0; i < size; i++) {
        min = i; // Note that position of min element is tracked
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap(&arr[i], &arr[min]);
        }
    }
}

/*****************************************************************************/
void insertion_sort(int *arr, int size) {
    for (int i = 1; i < size; i++) {
        for (int j = i; (j>0) && (arr[j] < arr[j-1]); j--) {
            swap(&arr[j], &arr[j-1]);
        }
    }
}

/*****************************************************************************/
void merge(int *arr, int low, int middle, int high) {
    queue<int> queue1;
    queue<int> queue2;

    for (int i = low; i <= middle; i++) {
        queue1.push(arr[i]);
    }
    for (int i = middle+1; i <= high; i++) {
        queue2.push(arr[i]);
    }

    int j = low;
    while (!(queue1.empty() || queue2.empty())) {
        if (queue1.front() < queue2.front()) {
            arr[j++] = queue1.front();
            queue1.pop();
        } else {
            arr[j++] = queue2.front();
            queue2.pop();
        }
    }

    while (!queue1.empty()) {
        arr[j++] = queue1.front();
        queue1.pop();
    }
    while (!queue2.empty()) {
        arr[j++] = queue2.front();
        queue2.pop();
    }
}

void merge_sort(int *arr, int low, int high) {
    if (low < high) {
        int middle = (low + high)/2;
        merge_sort(arr, low, middle);
        merge_sort(arr, middle+1, high);
        merge(arr, low, middle, high);
    }
}

/*****************************************************************************/
int partition(int *arr, int low, int high) {
    int pivot = high;
    int firsthigh = low;

    for (int i = low; i <= high; i++) {
        if (arr[i] < arr[pivot]) {
            swap(&arr[i], &arr[firsthigh]);
            firsthigh++;
        }
    }
    swap(&arr[pivot], &arr[firsthigh]);

    return(firsthigh);
}

void quick_sort(int *arr, int low, int high) {
    if ((high - low) > 0) {
        int pos = partition(arr, low, high);
        quick_sort(arr, low, pos-1);
        quick_sort(arr, pos+1, high);
    }
}


/*****************************************************************************/
int main(int argc, char *argv[]) {
    int size;

    // Selection Sort
    int array[] = {1, 10, 7, 123, 45, 2, 23};
    size = sizeof(array) / sizeof(int);
    selection_sort(array, size);
    print_array(array, size);

    // TODO Heap Sort

    // Insertion Sort
    int arr2[] = {1, 10, 7, 123, 45, 2, 23};
    size = sizeof(arr2) / sizeof(int);
    insertion_sort(arr2, size);
    print_array(arr2, size);

    // Merge Sort
    int arr3[] = {1, 10, 7, 123, 45, 2, 23};
    size = sizeof(arr3) / sizeof(int);
    // Note that index starts from 0 and goes only till size-1
    merge_sort(arr3, 0, size-1);
    print_array(arr3, size);

    // Quick Sort
    int arr4[] = {1, 10, 7, 123, 45, 2, 23};
    size = sizeof(arr4) / sizeof(int);
    // Note that index starts from 0 and goes only till size-1
    quick_sort(arr4, 0, size-1);
    print_array(arr4, size);

    return (0);
}
