#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* last = NULL;

// Insert at beginning
void insertBefore(int val) {
    Node* n = new Node{val, NULL};

    if (last == NULL) {
        last = n;
        last->next = last;
    } else {
        n->next = last->next;
        last->next = n;
    }
}

// Insert at end
void insertAfter(int val) {
    Node* n = new Node{val, NULL};

    if (last == NULL) {
        last = n;
        last->next = last;
    } else {
        n->next = last->next;
        last->next = n;
        last = n;
    }
}

// Delete node (all cases)
void deleteNode(int val) {
    if (last == NULL) return;

    Node *curr = last->next, *prev = last;

    do {
        if (curr->data == val) {
            // single node
            if (curr == last && curr->next == last)
                last = NULL;

            // deleting first node
            else if (curr == last->next)
                last->next = curr->next;

            // deleting last node
            else if (curr == last) {
                prev->next = curr->next;
                last = prev;
            }
            // middle node
            else
                prev->next = curr->next;

            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != last->next);
}

// Display
void display() {
    if (last == NULL) return;

    Node* temp = last->next;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != last->next);
}

int main() {
    insertBefore(10);
    insertAfter(20);
    insertAfter(30);
    display();

    cout << "\nAfter deletion 1:\n";
    deleteNode(20);
    cout << "\nAfter deletion 2:\n";
    deleteNode(30);
    cout << "\nAfter deletion 3:\n";
    deleteNode(10);
    
    display();
}