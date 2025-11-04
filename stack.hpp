#ifndef _STACK_STACK_HPP
#define _STACK_STACK_HPP

#include <stdexcept>
#include <string>

class invalid_peek_error : public std::logic_error {
public:
    invalid_peek_error(const std::string& message) : std::logic_error(message) {};
};

class invalid_pop_error : public std::logic_error {
public:
    invalid_pop_error(const std::string& message) : std::logic_error(message) {};
};

// Stack class template
template <typename StackElementType>
class Stack {
private:
    struct Node {
        StackElementType data;
        Node* next;

        Node(const StackElementType& value, Node* nextNode = nullptr)
        : data(value), next(nextNode) {}
    };

	Node* topNode; //pointer to the top node of the stack
    size_t count; //number of elements in the stack

public:
    //Default constructor
    Stack() : topNode(nullptr), count(0) {}

	//Destructor
    ~Stack() {
        while (topNode != nullptr) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }

    // Copy constructor
    Stack(const Stack& other) : topNode(nullptr), count(0) {
        if (other.topNode != nullptr) {
			// Create a reversed temporary stack to maintain order
            Node* curr = other.topNode;
            Stack<StackElementType> temp;
            while (curr != nullptr) {
                temp.push(curr->data);
                curr = curr->next;
            }
            // Move from temp to this stack to correct order
            while (temp.size() > 0) {
                push(temp.pop());
            }
        }
        return *this;
    }

    // Push: adds an element to the top
    void push(const StackElementType& value) {
        Node* newNode = new Node(value, topNode);
        topNode = newNode;
        ++count;
    }

    // Pop: removes and returns the top element
    StackElementType pop() {
        if (isEmpty()) {
			throw invalid_pop_error("Cannot pop from an empty stack.");
        }
        Node* temp = topNode;
        StackElementType poppedValue = temp->data;
        topNode = topNode->next;
        delete temp;
        --count;
        return poppedValue;
    }

    // Peek: returns the top element without removing it
    StackElementType peek() const {
        if (isEmpty()) {
			throw invalid_peek_error("Cannot peek from an empty stack.");
        }
        return topNode->data;
    }

    // Returns the number of elements
    size_t size() const {
        return count;
    }

    // Returns true if the stack is empty
    bool isEmpty() const {
        return count == 0;
    }
};
#endif