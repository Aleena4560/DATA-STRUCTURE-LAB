#include <iostream>
using namespace std;

// Book Node Class 
class Node {
public:
    string title;
    double price;
    int edition;
    int pages;
    Node* next;

    Node(string t, double p, int e, int pg) {
        title = t;
        price = p;
        edition = e;
        pages = pg;
        next = NULL;
    }
};

// Stack Class 
class Stack {
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    // Push
    void push(string t, double p, int e, int pg) {
        Node* n = new Node(t, p, e, pg);
        n->next = top;
        top = n;
        cout << "Book pushed\n";
    }

    // Pop
    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        cout << "Book popped\n";
    }

    // Peek (Top element)
    void peek() {
        if (top == NULL) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "\nTop Book:\n";
        cout << top->title << " | " << top->price << " | "
             << top->edition << " | " << top->pages << endl;
    }

    // Display all books
    void display() {
        if (top == NULL) {
            cout << "Stack is empty\n";
            return;
        }

        Node* temp = top;
        cout << "\nRemaining Books:\n";
        while (temp != NULL) {
            cout << temp->title << " | " << temp->price << " | "
                 << temp->edition << " | " << temp->pages << endl;
            temp = temp->next;
        }
    }
};

// Main Function 
int main() {
    Stack s;

    // 1. Push 5 books
    s.push("C++", 500, 1, 300);
    s.push("DSA", 600, 2, 350);
    s.push("OOP", 700, 3, 400);
    s.push("DBMS", 550, 2, 320);
    s.push("OS", 650, 1, 280);

    // 2. Find top element
    s.peek();

    // 3. Pop 2 books
    s.pop();
    s.pop();

    // 4. Display remaining books
    s.display();

    return 0;
}