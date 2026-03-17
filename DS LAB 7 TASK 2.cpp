#include <iostream>
using namespace std;

// Inventory Class 
class Inventory {
    int serialNum;
    int manufactYear;
    int lotNum;

public:
    // Set data
    void setData(int s, int y, int l) {
        serialNum = s;
        manufactYear = y;
        lotNum = l;
    }

    // Display data
    void display() {
        cout << "Serial: " << serialNum
             << ", Year: " << manufactYear
             << ", Lot: " << lotNum << endl;
    }
};

// Node Class 
class Node {
public:
    Inventory data;
    Node* next;

    Node(Inventory obj) {
        data = obj;
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
    void push(Inventory obj) {
        Node* n = new Node(obj);
        n->next = top;
        top = n;
        cout << "Part added to inventory\n";
    }

    // Pop
    void pop() {
        if (top == NULL) {
            cout << "Inventory empty\n";
            return;
        }

        Node* temp = top;
        cout << "Removed Part:\n";
        temp->data.display();

        top = top->next;
        delete temp;
    }

    // Display all
    void displayAll() {
        if (top == NULL) {
            cout << "No parts remaining\n";
            return;
        }

        Node* temp = top;
        cout << "\nRemaining Parts:\n";
        while (temp != NULL) {
            temp->data.display();
            temp = temp->next;
        }
    }
};

// Main Function
int main() {
    Stack s;
    int choice;

    do {
        cout << "\n1. Add Part\n2. Remove Part\n0. Exit\n";
        cin >> choice;

        if (choice == 1) {
            int sNum, year, lot;

            cout << "Enter Serial Number: ";
            cin >> sNum;
            cout << "Enter Manufacturing Year: ";
            cin >> year;
            cout << "Enter Lot Number: ";
            cin >> lot;

            Inventory obj;
            obj.setData(sNum, year, lot);

            s.push(obj);
        }
        else if (choice == 2) {
            s.pop();
        }

    } while (choice != 0);

    // Final display
    s.displayAll();

    return 0;
}