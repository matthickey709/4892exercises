#include <memory>
#include <list>

template<typename T>
class Tree {
public:
    struct Node {
        T val;
        std::list<std::unique_ptr<Node>> children;
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
        std::unique_ptr<Node> newNode = std::make_unique<Node>();
        newNode->val = value;
        this->root->children.emplace_back(std::move(newNode));

        return *this;
    }

    /**
     * Add a subtree to the top level of this tree, using move
     * semantics to "steal" the subtree's nodes.
     */
    Tree& addSubtree(Tree<T>&& subtree) {
        // create the new root node of subtree and set its value to root of incoming tree
        std::unique_ptr<Node> newNode = std::make_unique<Node>();
        newNode->val = subtree.root->val;

        // move semantics to move the root node of subtree's children over
        newNode->children = std::move(subtree.children);

        // set the new Node to be a child of the current tree's root node
        this->root->children.emplace_back(std::move(newNode));

        return *this;
    }

    T getRootValue() {
        return this->root->val;
    }

    std::list<std::unique_ptr<Node>> getRootChildren() {
        return this->root->children;
    }

    std::unique_ptr<Node> root;
};
