#include <iostream>
using namespace std;

class Profile
{
public:
    int id;
    string name;
    string gender;
    int age;
    string email;
    string interest;
    string dob;

    Profile() {}

    Profile(int i, string n, string g, int a,
            string e, string in, string d)
    {
        id = i;
        name = n;
        gender = g;
        age = a;
        email = e;
        interest = in;
        dob = d;
    }

    void display()
    {
        cout << "\nID: " << id;
        cout << "\nName: " << name;
        cout << "\nGender: " << gender;
        cout << "\nAge: " << age;
        cout << "\nEmail: " << email;
        cout << "\nInterest: " << interest;
        cout << "\nDate of Birth: " << dob;
        cout << "\n----------------------\n";
    }
};

class Node
{
public:
    Profile data;
    Node* next;

    Node(Profile p)
    {
        data = p;
        next = NULL;
    }
};

class Portal
{
private:
    Node* head;

public:
    Portal()
    {
        head = NULL;
    }

    // Insert Profile 
    void InsertProfile(Profile p)
    {
        Node* newNode = new Node(p);

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

    // Display All Profiles 
    void Display()
    {
        if (head == NULL)
        {
            cout << "No Profiles Found\n";
            return;
        }

        Node* temp = head;
        while (temp != NULL)
        {
            temp->data.display();
            temp = temp->next;
        }
    }

    // Search Profile 
    void searchProfile(string name)
    {
        Node* temp = head;

        while (temp != NULL)
        {
            if (temp->data.name == name)
            {
                cout << "\nProfile Found:\n";
                temp->data.display();
                return;
            }
            temp = temp->next;
        }

        cout << "Profile Not Found\n";
    }

    // Update Profile 
    void UpdateProfile(int id)
    {
        Node* temp = head;

        while (temp != NULL)
        {
            if (temp->data.id == id)
            {
                cout << "Enter New Name: ";
                cin >> temp->data.name;

                cout << "Enter Gender: ";
                cin >> temp->data.gender;

                cout << "Enter Age: ";
                cin >> temp->data.age;

                cout << "Enter Email: ";
                cin >> temp->data.email;

                cout << "Enter Interest: ";
                cin >> temp->data.interest;

                cout << "Enter DOB: ";
                cin >> temp->data.dob;

                cout << "Profile Updated Successfully\n";
                return;
            }

            temp = temp->next;
        }

        cout << "Profile Not Found\n";
    }

    // Delete Profile 
    void DeleteProfile(string name)
    {
        if (head == NULL)
        {
            cout << "List Empty\n";
            return;
        }

        if (head->data.name == name)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Profile Deleted\n";
            return;
        }

        Node* temp = head;

        while (temp->next != NULL &&
               temp->next->data.name != name)
        {
            temp = temp->next;
        }

        if (temp->next == NULL)
        {
            cout << "Profile Not Found\n";
            return;
        }

        Node* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;

        cout << "Profile Deleted Successfully\n";
    }
};

int main()
{
    Portal portal;
    int choice;

    do
    {
        cout << "\n===== SOCIAL MEDIA PORTAL =====\n";
        cout << "1. Add New Profile\n";
        cout << "2. Update Profile\n";
        cout << "3. Delete Profile\n";
        cout << "4. Search Profile\n";
        cout << "5. Display All Profiles\n";
        cout << "6. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int id, age;
            string name, gender, email, interest, dob;

            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Gender: ";
            cin >> gender;
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Email: ";
            cin >> email;
            cout << "Enter Interest: ";
            cin >> interest;
            cout << "Enter DOB: ";
            cin >> dob;

            Profile p(id, name, gender, age,
                      email, interest, dob);

            portal.InsertProfile(p);
        }

        else if (choice == 2)
        {
            int id;
            cout << "Enter ID to Update: ";
            cin >> id;
            portal.UpdateProfile(id);
        }

        else if (choice == 3)
        {
            string name;
            cout << "Enter Name to Delete: ";
            cin >> name;
            portal.DeleteProfile(name);
        }

        else if (choice == 4)
        {
            string name;
            cout << "Enter Name to Search: ";
            cin >> name;
            portal.searchProfile(name);
        }

        else if (choice == 5)
        {
            portal.Display();
        }

    } while (choice != 6);

    cout << "Program Ended\n";

    return 0;
}