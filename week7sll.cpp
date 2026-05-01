#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

class Stack {
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == NULL;
    }

    // Check if stack is full (rare case for linked list)
    bool isFull() {
        Node* temp = new(nothrow) Node;
        if (temp == NULL)
            return true;
        delete temp;
        return false;
    }

    // Push operation
    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot insert " << x << endl;
            return;
        }

        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = top;
        top = newNode;

        cout << x << " pushed into stack\n";
    }

    // Pop operation
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop\n";
            return;
        }

        Node* temp = top;
        cout << temp->data << " popped from stack\n";
        top = top->next;
        delete temp;
    }

    // Peek operation
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
        } else {
            cout << "Top element is: " << top->data << endl;
        }
    }

    // Display stack
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return;
        }

        Node* temp = top;
        cout << "Stack elements: ";
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n--- STACK MENU (Linked List) ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Check if Empty\n";
        cout << "5. Check if Full\n";
        cout << "6. Display\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.peek();
                break;

            case 4:
                if (s.isEmpty())
                    cout << "Stack is Empty\n";
                else
                    cout << "Stack is NOT Empty\n";
                break;

            case 5:
                if (s.isFull())
                    cout << "Stack is Full (Memory Full)\n";
                else
                    cout << "Stack is NOT Full\n";
                break;

            case 6:
                s.display();
                break;

            case 7:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 7);

    return 0;
}

