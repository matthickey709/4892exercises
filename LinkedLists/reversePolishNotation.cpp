#include "reversePolishNotation.h"

using namespace std;

int main(int argc, char const *argv[]) {
    vector<string> thosePoles =  {"1", "2", "+", "3", "*"};

    for (auto n : thosePoles) {
        cout << n << " ";
    }
    cout <<endl;

    int poleMath = reversePoleMath(thosePoles.begin(), thosePoles.end());

    cout << "The result of the RPN math should be 9 and it is: " << poleMath << endl;
    return 0;
}
