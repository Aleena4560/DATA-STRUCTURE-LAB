#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void insertEnd(int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL){
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}
void insertBeginning(int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if(head != NULL)
        head->prev = newNode;

    head = newNode;
}
void insertAfter45(int value){
    Node* temp = head;

    while(temp != NULL && temp->data != 45)
        temp = temp->next;

    if(temp == NULL) return;

    Node* newNode = new Node();
    newNode->data = value;

    newNode->next = temp->next;
    newNode->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}
void deleteBeginning(){
    if(head == NULL) return;

    Node* temp = head;
    head = head->next;

    if(head != NULL)
        head->prev = NULL;

    delete temp;
}
void deleteAfter45(){
    Node* temp = head;

    while(temp != NULL && temp->data != 45)
        temp = temp->next;

    if(temp == NULL || temp->next == NULL) return;

    Node* del = temp->next;
    temp->next = del->next;

    if(del->next != NULL)
        del->next->prev = temp;

    delete del;
}
void display(){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){

    insertEnd(1);
    insertEnd(45);
    insertEnd(60);
    insertEnd(12);

    cout<<"Initial List: ";
    display();

    insertBeginning(10);
    cout<<"After inserting at beginning: ";
    display();

    insertAfter45(99);
    cout<<"After inserting after 45: ";
    display();

    deleteBeginning();
    cout<<"After deleting beginning: ";
    display();

    deleteAfter45();
    cout<<"After deleting after 45: ";
    display();
}