#include <iostream>
#include <string>
using namespace std;

struct Node{
    string name;
    int score;
    Node* prev;
    Node* next;
};

Node* head=NULL;

void addPlayer(string name,int score){

    Node* newNode=new Node();
    newNode->name=name;
    newNode->score=score;
    newNode->next=NULL;

    if(head==NULL){
        newNode->prev=NULL;
        head=newNode;
        return;
    }

    Node* temp=head;
    while(temp->next!=NULL)
        temp=temp->next;

    temp->next=newNode;
    newNode->prev=temp;
}

void display(){

    Node* temp=head;

    while(temp!=NULL){
        cout<<temp->name<<" - "<<temp->score<<endl;
        temp=temp->next;
    }
}

void deletePlayer(string name){

    Node* temp=head;

    while(temp!=NULL && temp->name!=name)
        temp=temp->next;

    if(temp==NULL) return;

    if(temp==head)
        head=temp->next;

    if(temp->next!=NULL)
        temp->next->prev=temp->prev;

    if(temp->prev!=NULL)
        temp->prev->next=temp->next;

    delete temp;
}

void sameScore(int score){

    Node* temp=head;

    while(temp!=NULL){
        if(temp->score==score)
            cout<<temp->name<<" "<<temp->score<<endl;

        temp=temp->next;
    }
}

void displayBackward(string name){

    Node* temp=head;

    while(temp!=NULL && temp->name!=name)
        temp=temp->next;

    if(temp==NULL) return;

    while(temp!=NULL){
        cout<<temp->name<<" "<<temp->score<<endl;
        temp=temp->prev;
    }
}

int main(){

    addPlayer("Ali",80);
    addPlayer("Sara",75);
    addPlayer("Ahmad",80);

    cout<<"All Players:\n";
    display();

    cout<<"\nPlayers with score 80:\n";
    sameScore(80);

    cout<<"\nBackward from Ahmad:\n";
    displayBackward("Ahmad");

    deletePlayer("Sara");

    cout<<"\nAfter Deleting Sara:\n";
    display();
}