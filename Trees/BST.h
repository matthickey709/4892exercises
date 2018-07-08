/*
 * Copyright 2018 Jonathan Anderson
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <cassert>
#include <cstddef>      // for definition of size_t
#include <functional>   // std::function
#include <memory>       // std::unique_ptr
#include <iostream>     // std::cout
#include <stack>		// std::stack


template<typename T, typename Comparator = std::less<T>>
class BinarySearchTree
{
public:
	// Types of traversal for BSTs
	enum class Traversal {
			PreOrder, 	// visit node before children
			InOrder,  	// visit left, then root, then right (for BST this is least->greatest)
			PostOrder	// visit node after children
	};


	//! Does this tree contain the given value?
	bool contains(const T &value)
	{
		return (not empty() and root_->contains(value));
	}

	size_t maxDepth() const
	{
		if (empty())
		{
			return 0;
		}

		return root_->maxDepth();
	}

	//! Is this tree empty?
	bool empty() const
	{
		return (not root_);
	}

	//! Insert a new value into the appropriate place in the tree.
	void insert(T value)
	{
		insert(std::move(value), root_);
	}

	/**
	 * Find the minimum value in the tree.
	 *
	 * @pre   tree is not empty
	 */
	const T& min() const
	{
		assert(root_);
		return root_->min();
	}

	/**
	 * Find the minimum value in the tree.
	 *
	 * @pre   tree is not empty
	 */
	const T& max() const
	{
		assert(root_);
		return root_->max();
	}

	/**
	 * Remove a value (if it exists) from the tree.
	 *
	 * @returns   whether or not anything was found to remove
	 */
	bool remove(const T &&value)
	{
		return remove(value, root_);
	}

    void print()
    {
        assert(root_);
        root_->print();
    }

	/**
	 * Output this tree in a GraphViz DOT representation as a
	 * directed graph ("digraph").
	 *
	 * Calls to this method will cause an entire graph (starting
	 * with "digraph G {") to be output to the given std::ostream.
	 *
	 * @param   o    the output stream to write to
	 */
	void printDot(std::ostream &o) const {
		o << "digraph G {" << '\n';
		root_->printDot(o);
		o << "}\n";
	}

private:
	struct Node
	{
		// Did you know that structs can have methods too?
		Node(T &&value)
			: element_(std::move(value)), count_(1), left_(nullptr), right_(nullptr)
		{
		}

		bool contains(const T& key) const {
            if (Comparator()(key, this->element_)) { // key is less than current element
				return (this->left_ ? this->left_->contains(key) : false);
			} else if (Comparator()(this->element_, key)) { // key is greater than current element
				return (this->right_ ? this->right_->contains(key) : false);
			} else {
				return true;
			}
        }

		const T& min() const {
            if (this->left_ == nullptr) {
                return this->element_;
            }
            return this->left_->min();
        }
		const T& max() const {
            if (this->right_ == nullptr) {
                return this->element_;
            }

            return this->right_->max();
        }

		/**
 		* Find the minimum node in a subtree and remove it, returning it by value.
 		*/
		T takeMin() {
			// if the tree goes at least a couple deeper
			if (this->left_ and this->left_->left_) {
				return this->left_->takeMin();
			} else if (this->left_) {
				// the node to the left is the min. save its value and delete
				T temp = this->left_->element_;
				this->left_.reset();
				return temp;
			} else {
				std::cout << "Should never get here" << '\n';
				return 0;
			}
		}


		size_t maxDepth() const {

			size_t leftDepth = 0, rightDepth = 0;


            if (this->left_ != nullptr) {
				leftDepth = this->left_->maxDepth() +1;
			}

			if (this->right_ != nullptr) {
				rightDepth = this->right_->maxDepth() +1;
			}


			return (leftDepth > rightDepth ? leftDepth : rightDepth);

        }

		void print() {
            if (this->left_ != nullptr)
				this->left_->print();
			std::cout << this->element_ << ' ';
			if (this->right_ != nullptr) {
				this->right_->print();
			}
        }

		/**
		 * Output information about this node in GraphViz DOT format.
		 *
		 * This will output information about this node
		 * (with no graph-level decorations such as "digraph G {")
		 * and recursively descend to its children.
		 */
		void printDot(std::ostream &o) const {
			// Print the info about the node
			o << this->element_ << " [ label = \"count " << this->count_ << ", value " << this->element_ << " \"];\n";
			// Link to the children
			if (this->left_)
				o << this->element_ << " -> " << this->left_->element_ << " [ label = \"L\" ];\n";
			if (this->right_)
				o << this->element_ << " -> " << this->right_->element_ << " [ label = \"R\" ];\n";

			if (this->left_)
				this->left_->printDot(o);
			if (this->right_)
				this->right_->printDot(o);
		}

		T element_;
		size_t count_;
		std::unique_ptr<Node> left_;
		std::unique_ptr<Node> right_;
	};

	/**
	 * Internal implementation of recursive insert.
	 *
	 * @param   value      the value to insert
	 * @param   node       the root of the (sub-)tree being inserted into;
	 *                     may be null if the (sub-)tree is empty
	 */
	void insert(T &&value, std::unique_ptr<Node> &node) {
        // if the root is null, make a new node
        if (node == nullptr) {
            node.reset(new Node(std::move(value)));
        } else if (compare_(value, node->element_)) {  // left side of tree
            this->insert(std::move(value), node->left_);
        } else if (compare_(node->element_, value)){  // left side of tree
            this->insert(std::move(value), node->right_);
        } else {
			node->count_++;
		}
    }

	/**
	 * Internal implementation of recursive removal.
	 *
	 * @param   value      the value to remove
	 * @param   node       the root of the (sub-)tree being removed into;
	 *                     may be null if the (sub-)tree is empty
	 */
	bool remove(const T &value, std::unique_ptr<Node> &node) {
		if (node == nullptr) {  // if node is null nothing has been found
			return false;
		} else if (compare_(value, node->element_)) {
			return this->remove(value, node->left_);
		} else if (compare_(node->element_, value)) {
			return this->remove(value, node->right_);
		} else if (node->count_ > 1) {
			node->count_--;
			return true;
		} else if (node->left_ and node->right_) {
			T minOfRight;
			if (node->right_->left_)
				minOfRight = node->right_->takeMin();
			else
			{
				minOfRight = node->right_->element_;
				this->remove(minOfRight, node->right_);
			}
			node->element_ = std::move(minOfRight);
			return true;
		} else {
			node.swap(node->left_ ? node->left_ : node->right_);
			return true;
		}
	}

	class Iterator {
	public:
		Iterator()
			: current(nullptr), traversalType(Traversal::InOrder)
		{

		}


		Iterator(Traversal t)
			: traversalType(t)
		{
			// upon initialization, push a nullptr to the stack
			nodeTracker.push(nullptr);

		}

		/**
		 * The dereference operator.
		 *
		 * @returns   a reference to the "current" element
		 */
		const T& operator*() {
			return current->element_;
		}

		/**
		 * Pre-increment operator (i.e., `++i`).
		 *
		 * This method increments the iterator and then returns a
		 * reference to the newly-incremented iterator.
		 *
		 * @returns   a reference to this iterator, after incrementing
		 */
		Iterator& operator++() {
			nodeTracker.pop();
			this->current = nodeTracker.top();

			return *this;
		}

		/**
		 * Post-increment operator (i.e., `i++`).
		 *
		 * This method returns a copy of this iterator as it currently
		 * is (i.e., pointing where it currently points) and _then_
		 * increments itself.
		 *
		 * @param     ignored   this is only used to distinguish the two
		 *                      increment operators (pre- and post-)
		 *                      from each other: its value should be
		 *                      ignored
		 *
		 * @returns   an iterator to the previously-current element
		 */
		Iterator operator++(int ignored) {
			// hold a const_iterator of current element to be returned.
			Iterator temp = *this;
			nodeTracker.pop();
			this->current = nodeTracker.top();
			// return the previously current element (temp)
			return temp;
		}

		void traverser(std::unique_ptr<Node> &n) {
			if (!n) return;
			// check the traversal type
			if (traversalType == Traversal::PreOrder) {
				traverser(n->right_);
				traverser(n->left_);
				nodeTracker.push(n.get());
			} else if (traversalType == Traversal::PostOrder) {
				nodeTracker.push(n.get());
				traverser(n->right_);
				traverser(n->left_);
			} else {
				traverser(n->right_);
				nodeTracker.push(n.get());
				traverser(n->left_);
			}

			// set current to top element of stack
			this->current = nodeTracker.top();
		}

		//! Is this iterator pointing at the same place as another one?
		bool operator== (const Iterator& other) const {
			if (current == other.current) {
				return true;
			} else {
				return false;
			}
		}

		//! Is this iterator pointing at a different place from another?
		bool operator!= (const Iterator& other) const {
			if (current != other.current) {
				return true;
			} else {
				return false;
			}
		}
	private:
		Node * current;
		const Traversal traversalType;
		std::stack<Node*> nodeTracker;
	};

	Comparator compare_;
	std::unique_ptr<Node> root_;

public:
	/**
	 * Returns an iterator that can be used to traverse the tree in the given order.
	 *
	 * This iterator should visit every node in the tree exactly once, after which
	 * it should test equal to the iterator returned from `end()`.
	 */
	Iterator begin(Traversal t) {
		Iterator iter(t);
		iter.traverser(this->root_);
		return iter;
	}

	/**
	 * The end of a tree traversal.
	 *
	 * The iterator returned by this method should be usable as the end-of-iteration
	 * marker for any iterator on this tree, whether it was traversing the tree in
	 * pre-, in- or post-order.
	 */
	Iterator end() {
		Iterator iter;
		return iter;
	}

};
