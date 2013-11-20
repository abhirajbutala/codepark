/* Program to find the longest common substring for any two given strings. */

#include<iostream>

using namespace std;

void LCSubstr(char *X, char *Y) {
    if (X == NULL || Y == NULL) {
        return;
    }

    int xlen = strlen(X);
    int ylen = strlen(Y);
    int arr[xlen][ylen];

    int maxLen = 0;
    int startPos = 0;
    int endPos = 0;

    for (int i = 0; i < xlen; i++) {
        for (int j = 0; j < ylen; j++) {
            if (X[i] == Y[j]) {
                if (i == 0 || j == 0) {
                    arr[i][j] = 1;
                } else {
                    arr[i][j] = arr[i - 1][j - 1] + 1;
                    if (arr[i][j] > maxLen) {
                        maxLen = arr[i][j];
                        startPos = i - maxLen + 1;
                        endPos = i;
                    }
                }
            } else {
                arr[i][j] = 0;
            }
        }
    }

    cout << "Longest Common Substring Length: " << maxLen << endl;
    cout << "Longest Common Substring: ";
    for (int i = startPos; i <= endPos; i++) {
        cout << X[i];
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    char X[] = "ABABCA";
    char Y[] = "AABCA";

    LCSubstr(X, Y);

    return 0;
}
