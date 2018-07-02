/*
    Question 1:
        The child-sibling structure does NOT change the choice of unique_ptr over
        shared_ptr from the child-parent approach. This is because the convention
        of only one node owning another still holds. A node (that isn't the root node)
        will only have 1 thing pointing to it: its parent if it is the "oldest"
        child, or its sibling if it isn't the oldest child.
*/


#include <memory>
#include <list>

template<typename T>
class Tree {
public:
    struct Node {
        T val;
        std::unique_ptr<Node> child;
        std::unique_ptr<Node> sibling;
    };
    /**
     * Set the value of the tree's root node.
     */
    Tree& setRoot(T value) {
        this->root = std::make_unique<Node>();
        this->root->val = value;

        return *this;
    }

    /**
     * Add a leaf node to the top level of this tree.
     */
    Tree& addChild(T value) {
        this->root = std::make_unique<Node>();
        this->root->val = value;
        return *this;
    }

    Tree& addSibling(T value) {
        this->root->child->sibling = std::make_unique<Node>();
        this->root->child->sibling->val = value;

        return *this;
    }

    /**
     * Add a subtree to the top level of this tree, using move
     * semantics to "steal" the subtree's nodes.
     */
    Tree& addSubtree(Tree<T>&& subtree) {
        std::unique_ptr<Node> newNode = std::move(subtree.root);
        this->root->child = std::move(newNode);
        return *this;
    }

    T getRootValue() {
        return this->root->val;
    }

    std::unique_ptr<Node> getRootChild() {
        return this->root->child;
    }

private:
    std::unique_ptr<Node> root;
};
