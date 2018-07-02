#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int variable1 = 5005;

    string variable2 = "matthew";

    cout << "The address of variable1 is " << &variable1 << endl;
    cout << "The address of variable2 is " << &variable2 << endl;

    // This shows that stack grows downwards, because the second variable to be
    // declared has a lower memory address than the first to be declared.
    return 0;
}
