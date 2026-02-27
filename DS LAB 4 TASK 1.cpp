#include <iostream>
using namespace std;

class Mobile{
private:
    string brand;
    int unitsOnHand;
    double price;

public:
    // Constructor
    Mobile(string b = "", int u = 0, double p = 0)
    {
        brand = b;
        unitsOnHand = u;
        price = p;
    }

    // Setter Functions
    void setBrand(string b)
    {
        brand = b;
    }

    void setUnits(int u)
    {
        unitsOnHand = u;
    }

    void setPrice(double p)
    {
        price = p;
    }

    // Getter Functions
    string getBrand()
    {
        return brand;
    }

    int getUnits()
    {
        return unitsOnHand;
    }

    double getPrice()
    {
        return price;
    }
};
// Class node
class Node{
public:
    Mobile data;
    Node* next;

    Node(Mobile m)
    {
        data = m;
        next = NULL;
    }
};
// Store linked list
class Store
{
private:
    Node* head;

public:
    Store()
    {
        head = NULL;
    }

    // Insert at Start
    void insertAtStart(Mobile m)
    {
        Node* newNode = new Node(m);
        newNode->next = head;
        head = newNode;
    }

    // Insert at End 
    void insertAtEnd(Mobile m)
    {
        Node* newNode = new Node(m);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }

    // Insert at Position 
    void insertAtPosition(Mobile m, int pos)
    {
        if (pos == 1)
        {
            insertAtStart(m);
            return;
        }

        Node* newNode = new Node(m);
        Node* temp = head;

        for (int i = 1; i < pos - 1 && temp != NULL; i++)
            temp = temp->next;

        if (temp == NULL)
        {
            cout << "Invalid Position\n";
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete from Start 
    void deleteFromStart()
    {
        if (head == NULL)
        {
            cout << "List Empty\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete from End 
    void deleteFromEnd()
    {
        if (head == NULL)
        {
            cout << "List Empty\n";
            return;
        }

        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next->next != NULL)
            temp = temp->next;

        delete temp->next;
        temp->next = NULL;
    }

    // Delete from Position 
    void deleteFromPosition(int pos)
    {
        if (head == NULL)
        {
            cout << "List Empty\n";
            return;
        }

        if (pos == 1)
        {
            deleteFromStart();
            return;
        }

        Node* temp = head;

        for (int i = 1; i < pos - 1 && temp->next != NULL; i++)
            temp = temp->next;

        if (temp->next == NULL)
        {
            cout << "Invalid Position\n";
            return;
        }

        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    }

    // Display mobiles
    void display()
    {
        if (head == NULL)
        {
            cout << "No Mobiles in Store\n";
            return;
        }

        Node* temp = head;

        while (temp != NULL)
        {
            cout << "Brand: " << temp->data.getBrand() << endl;
            cout << "Units: " << temp->data.getUnits() << endl;
            cout << "Price: " << temp->data.getPrice() << endl;
            cout << "---------------------\n";

            temp = temp->next;
        }
    }
};

int main()
{
    Store store;

    Mobile m1("Samsung", 10, 85000);
    Mobile m2("Apple", 5, 200000);
    Mobile m3("Oppo", 15, 45000);
    Mobile m4("Vivo", 8, 50000);

    cout << "Insert at Start\n";
    store.insertAtStart(m1);

    cout << "Insert at End\n";
    store.insertAtEnd(m2);

    cout << "Insert at Position 2\n";
    store.insertAtPosition(m3, 2);

    cout << "\nMobiles After Insertion:\n";
    store.display();

    cout << "\nDelete from Start\n";
    store.deleteFromStart();

    cout << "Delete from End\n";
    store.deleteFromEnd();

    cout << "Insert Again at End\n";
    store.insertAtEnd(m4);

    cout << "\nFinal Mobile List:\n";
    store.display();

    return 0;
}