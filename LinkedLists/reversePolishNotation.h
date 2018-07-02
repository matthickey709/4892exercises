#include <iostream>
#include <vector>
#include <stack>
#include <sstream>


template<typename Iter>
int reversePoleMath(Iter begin, Iter end) {
    std::stack<int> mathNums;
    for (auto i = begin; i != end; i++) {
        // check if the current string is an operator
        // doing dumbly for the example i have... would be more robust if assignment
        if ((*i == '+') || (*i == '*')) {
            // take the two most recent numbers off the stack (pop)
            int hold1 = mathNums.top();
            mathNums.pop();
            int hold2 = mathNums.top();
            mathNums.pop();
            // switch statement for operations
            switch(*i) {
                case '+':
                    mathNums.push(hold1 + hold2);
                    break;
                case '*':
                    mathNums.push(hold1 * hold2);
                    break;
            }

        } else {
            // current iteration is a number, push it onto the stack and keep going
            int currNum;
            std::istringstream(*i) >> currNum;
            mathNums.push(currNum);

        }
    }

    int result = mathNums.top();
    // reset the stack (remove all elements)
    while(!mathNums.empty()) {
        mathNums.pop();
    }

    //return the answer of the RPN math
    return result;

}
