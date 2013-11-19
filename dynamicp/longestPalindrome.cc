#include<iostream>

using namespace std;

void longestPalindrome (char *str, int size) {
    if (str == NULL) {
        return;
    }


    bool arr[size][size];
    memset(arr, 0, sizeof(arr));

    int start = 0;
    int maxLength = 1;

    for (int i = 0; i < size; i++) {
        arr[i][i] = true;
    }

    for (int i = 1; i < size; i++) {
        if (str[i] == str[i-1]) {
            arr[i-1][i] = true;
            start = i-1;
            maxLength = 2;
        }
    }

    int j;
    for (int k = 3; k <= size; k++) {
        for (int i = 0; i < (size - k) + 1; i++) {
            j = (i + k) - 1;
            if ((arr[i + 1][j - 1] == true)  && (str[i] == str[j])) {
                arr[i][j] = true;
                if (k > maxLength) {
                    maxLength = k;
                    start = i;
                }
            }
        }
    }

    if (maxLength > 1) {
        cout << "Longest palindrome: ";
        for (int i = start; i <= maxLength; i++) {
            cout << str[i];
        }
        cout << endl;
    } else {
        cout << "No palindrome substr found!" << endl;
    }
}


int main(int argc, char *argv[]) {
    char str[] = "motom";
    longestPalindrome(str, 5);

    char str2[] = "moottoor";
    longestPalindrome(str2, 8);

    char str3[] = "abcd";
    longestPalindrome(str3, 4);

    return 0;
}


