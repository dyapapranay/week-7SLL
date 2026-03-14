#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    // Constructor
    Stack() {
        top = NULL;
    }

    // Check if stack is empty
    bool isEmpty() {
        return (top == NULL);
    }

    // Push operation
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;

        cout << value << " pushed into stack" << endl;
    }

    // Pop operation
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return;
        }

        Node* temp = top;
        cout << top->data << " popped from stack" << endl;
        top = top->next;
        delete temp;
    }

    // Peek operation
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Top element is: " << top->data << endl;
        }
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.peek();

    s.pop();
    s.peek();

    return 0;
}

