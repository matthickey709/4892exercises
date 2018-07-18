// this method will be called on the parent of the node with invalid balance factor
void rotateRight(std::unique_ptr<AVLNode> &n) {
    // save the value whose balance factor is off temporarily
    std::unique_ptr<AVLNode> temp = std::move(n);
    // start rotation
    n.reset(std::move(temp->left_));
    // put the originally unbalanced node to the right of the new left element
    n->left_->right_.reset(std::move(temp));
}

void rotateLeft(std::unique_ptr<AVLNode> &n) {
    std::unique_ptr<AVLNode> temp = std::move(n);
    n.reset(std::move(temp->right_));
    n->right_->left_.reset(std::move(temp));
}
