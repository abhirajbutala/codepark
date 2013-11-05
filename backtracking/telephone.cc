/*
Write a function that takes a seven-digit telephone number and prints out all
of the possible “words” or combinations of letters that can represent the
given number. Because the 0 and 1 keys have no letters on them, you should
change only the digits 2–9 to letters. You’ll be passed an array of seven
integers, with each element being one digit in the number. You may assume
that only valid phone numbers will be passed to your function. You can use
the helper function:

char getCharKey( int telephoneKey, int place )

which takes a telephone key (0–9) and a place of either 1, 2, 3 and returns the
character corresponding to the letter in that position on the specified key. For
example, GetCharKey(3,2) will return ‘E’ because the telephone key 3 has the
letters “DEF” on it and ‘E’ is the second letter.

 */


#include<iostream>
#include<string>

using namespace std;

char getCharKey(int tKey, int place) {
    if ((tKey < 0 && tKey > 9) ||
        (place < 1 && place > 3)) {
        return '\0';
    }

    switch (tKey) {
        case 0:
            return '0';
        case 1:
            return '1';
        case 2:
            return 'A' + place - 1;
        case 3:
            return 'D' + place - 1;
        case 4:
            return 'G' + place - 1;
        case 5:
            return 'J' + place - 1;
        case 6:
            return 'M' + place - 1;
        case 7:
            return 'P' + place - 1;
        case 8:
            return 'T' + place - 1;
        case 9:
            return 'W' + place - 1;
        default:
            return '\0';
    }
}

class TelephoneWord {
    private:
        int *phoneNum;
        string word;
    public:
        TelephoneWord(int *arr) {
            phoneNum = arr;
        }
        ~TelephoneWord() {
        }

        void enumerate(int pos) {
            if (pos == 7) {
                cout << word << endl;
                return;
            }

            for (int j = 1; j <= 3; j++) {
                word.push_back(getCharKey(phoneNum[pos], j));
                enumerate(pos + 1);
                word.erase(word.size() - 1);
                if (phoneNum[pos] == 0 || phoneNum[pos] == 1) {
                    // If the digit is either 0 or 1, we don't want to repeat
                    // three times because there are no letters.
                    return;
                }
            }

        }
};


int main(int argc, char *argv[]) {
    int num[] = {4, 9, 7, 1, 9, 2, 7};

    TelephoneWord phone(num);
    phone.enumerate(0);

    return 0;
}

