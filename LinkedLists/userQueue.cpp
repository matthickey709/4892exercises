#include "Queue.h"

using namespace std;

int main(int argc, char const *argv[]) {
    Queue<int> myQueue;



    bool quit = false;



    while (!quit) {

        string command;
        int value;
        cout << "Please enter a command: ";
        cin >> command >> value;

        cout << endl;

        if (command == "quit") {
            quit = true;
        }

        cout << command << " " << value << endl;

        if (command == "enqueue") {
            myQueue.enqueue(value);
        } else if (command == "dequeue") {
            myQueue.dequeue();
        }




    }

    return 0;
}
