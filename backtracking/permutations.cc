#include<iostream>
#include<string>


using namespace std;


class Permutation {
    private:
        string input;
        string output;
        bool *flags;
    public:
        Permutation(string str) {
            input = str;
            flags = new bool[str.length()];
            for (int i = 0; i < str.length(); i++) {
                flags[i] = false;
            }
        }

        ~Permutation() {
            delete[] flags;
        }

        void permute() {
            if (output.length() == input.length()) {
                cout << output << endl;
                return;
            }

            for (int i = 0; i < input.length(); i++) {
                if (flags[i] == true) {
                    continue;
                }
                flags[i] = true;
                output.push_back(input[i]);
                permute();
                output.erase(output.size() - 1);
                flags[i] = false;
            }
        }
};


int main(int argc, char *argv[]) {

    string s1("abcd");

    Permutation p1(s1);
    p1.permute();

    return 0;
}
