#include<iostream>
#include<string>


using namespace std;


class Combination {
    private:
        string input;
        string output;
    public:
        Combination(string str) {
            input = str;
        }

        ~Combination() {
        }

        void combinate(int start) {
            for (int i = start; i < input.length(); i++) {
                output.push_back(input[i]);
                cout << output << endl;
                combinate(i + 1);
                output.erase(output.size() - 1);
            }
        }
};


int main(int argc, char *argv[]) {

    string s1("wxyz");
    Combination c1(s1);
    c1.combinate(0);

    return 0;
}
