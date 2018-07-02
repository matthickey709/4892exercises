/*
    Question 1:
        std::shared_ptr allows multiple shared_ptr to point at an object, and the
        object being pointed at will be removed when the last shared pointer goes
        out of scope. With std::unique_ptr, only one pointer can own the object
        and when the unique_ptr goes out of scope, the object is deleted.

        This means that unique_ptr will be the better choice for parents pointing
        to children, as each child can only have one parent, and it takes care of
        memory management, as when a child is deleted, all of that child's children
        will be deleted.
*/


#include "Tree.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[]) {
    Tree<int> myTree;

    myTree.setRoot(42);

    cout << "The value of the root node is " << myTree.getRootValue() << endl;

    myTree.addChild(22);
    myTree.addChild(55);

    for(auto i : myTree.root->children) {
        cout << "Child: " << i->val << endl;
    }








    Tree<int> anotherTree;

    anotherTree.setRoot(400);
    anotherTree.addChild(11);

    anotherTree.addchild(90);

    myTree.addSubtree(std::move(anotherTree));

    return 0;
}
