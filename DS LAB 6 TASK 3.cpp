#include <iostream>
using namespace std;

// Book Class
class Book {
public:
    string id, name, author, isbn;
    double price;

    Book() {}

    Book(string i, string n, double p, string a, string is) {
        id = i; name = n; price = p; author = a; isbn = is;
    }
};

// Node Class
class Node {
public:
    Book data;
    Node* next;
    Node* prev;

    Node(Book b) {
        data = b;
        next = prev = NULL;
    }
};

// Doubly Circular Linked List
class BookList {
    Node* head;

public:
    BookList() {
        head = NULL;
    }

    // Add Book
    void addBook(Book b) {
        Node* n = new Node(b);

        if (head == NULL) {
            head = n;
            n->next = n;
            n->prev = n;
        } else {
            Node* last = head->prev;

            last->next = n;
            n->prev = last;
            n->next = head;
            head->prev = n;
        }
        cout << "Added successfully\n";
    }

    // Remove Book
    void removeBook(string id) {
        if (head == NULL) {
            cout << "List empty\n";
            return;
        }

        Node* temp = head;

        do {
            if (temp->data.id == id) {
                // single node
                if (temp->next == temp) {
                    head = NULL;
                }
                else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;

                    if (temp == head)
                        head = temp->next;
                }

                delete temp;
                cout << "Deleted successfully\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Book not found\n";
    }

    // Update Book
    void updateBook(string id) {
        Node* temp = head;

        if (head == NULL) return;

        do {
            if (temp->data.id == id) {
                cout << "Enter new name: ";
                cin >> temp->data.name;
                cout << "Enter new price: ";
                cin >> temp->data.price;
                cout << "Updated successfully\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Book not found\n";
    }

    // Print all books
    void printBooks() {
        if (head == NULL) return;

        Node* temp = head;
        do {
            cout << temp->data.id << " "
                 << temp->data.name << " "
                 << temp->data.price << " "
                 << temp->data.author << " "
                 << temp->data.isbn << endl;

            temp = temp->next;
        } while (temp != head);
    }

    // Print specific book
    void printBook(string id) {
        Node* temp = head;

        if (head == NULL) return;

        do {
            if (temp->data.id == id) {
                cout << temp->data.name << " Found\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);

        cout << "Book not found\n";
    }
};

// Main Function 
int main() {
    BookList list;

    // Add 3 books (you can make 10 if needed)
    list.addBook(Book("1", "C++", 500, "Usama", "111"));
    list.addBook(Book("2", "DSA", 600, "Talha", "222"));
    list.addBook(Book("3", "OOP", 700, "Umair", "333"));

    cout << "\nUsama Books:\n";
    list.printBooks();

    // Remove (2 times: valid + invalid)
    list.removeBook("2");
    list.removeBook("10");
    cout << "\nAfter Deletion:\n";
    list.printBooks();

    // Update + print
    list.updateBook("1");
    list.printBook("1");

    return 0;
}