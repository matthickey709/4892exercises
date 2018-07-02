#include <memory>
#include <list>
#include <iostream>

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

    template <typename Visitor>
    void visitPreorder(Visitor visit) {
        // first visit the root node of the tree
        preorder(this->root);
    }

    template <typename Visitor>
    void visitPostorder(Visitor visit) {
        postorder(this->root);
    }

private:
    std::unique_ptr<Node> root;

    void preorder(std::unique_ptr<Node> node) {
        if (node != nullptr) {
            visit(node->val);
            preorder(node->child);
            preorder(node->sibling);
        }
    }

    void postorder(std::unique_ptr<Node> node) {
        if (node != nullptr) {
            postorder(node->child);
            visit(node->val);
            postorder(node->sibing);
        }
    }
};


template <typename T>
void visit(const T &value)
{
    static size_t i = 0;
    std::cout << "Node " << i++ << ": " << value << "\n";
}
