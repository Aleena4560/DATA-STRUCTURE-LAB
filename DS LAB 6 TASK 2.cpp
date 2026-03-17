#include <iostream>
using namespace std;

struct Node {
    string name;
    Node* next;
};

Node* last = NULL;

// Add employee (at end)
void addEmployee(string name) {
    Node* n = new Node{name, NULL};

    if (last == NULL) {
        last = n;
        last->next = last;
    } else {
        n->next = last->next;
        last->next = n;
        last = n;
    }
    cout << "Added successfully\n";
}

// Delete employee
void deleteEmployee(string name) {
    if (last == NULL) {
        cout << "List empty\n";
        return;
    }

    Node *curr = last->next, *prev = last;

    do {
        if (curr->name == name) {
            if (curr == last && curr->next == last)
                last = NULL;
            else if (curr == last->next)
                last->next = curr->next;
            else if (curr == last) {
                prev->next = curr->next;
                last = prev;
            } else
                prev->next = curr->next;

            delete curr;
            cout << "Deleted successfully\n";
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != last->next);

    cout << "Not found\n";
}

// Search employee
void searchEmployee(string name) {
    if (last == NULL) {
        cout << "List empty\n";
        return;
    }

    Node* temp = last->next;
    do {
        if (temp->name == name) {
            cout << "Found successfully\n";
            return;
        }
        temp = temp->next;
    } while (temp != last->next);

    cout << "Not found\n";
}

// Display
void display() {
    if (last == NULL) return;

    Node* temp = last->next;
    do {
        cout << temp->name << " ";
        temp = temp->next;
    } while (temp != last->next);
}

int main() {
    addEmployee("Aleena");
    addEmployee("Minah");
    addEmployee("Rida");

    display();

    cout << "\n";
    searchEmployee("Aleena");

    deleteEmployee("Rida");

    cout << "\nAfter deletion:\n";
    display();
}