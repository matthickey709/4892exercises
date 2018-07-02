#include <list>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>

template<typename T>
class Queue {
public:

    //! Load a value into the queue
    void enqueue(T& n) {
        // add value to the beginning of the list of values
        std::cout << "Enqueueing " << n << '\n';
        this->values.push_front(n);
    }

    //! Take a value out of the queue
    void dequeue() {
        // check to see if the queue is empty
        if (this->size() > 0) {
            // take value off the end (FIFO queue)
            std::cout << "Dequeueing " << this->values.back() << std::endl;
            this->values.pop_back();
        } else {
            std::cout << "Queue empty, cannot dequeue..." << '\n';
        }

    }

    //! Return the size of the queue
    size_t size() {
        return this->values.size();
    }





private:
    std::list<T> values;
};
