#include <iostream>
using namespace std;

struct Node{
    float data;
    Node* prev;
    Node* next;
};

Node* head=NULL;

void insert(float val){
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = NULL;

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

int main(){

    float rain;

    cout<<"Enter rainfall for 7 days:\n";

    for(int i=1;i<=7;i++){
        cout<<"Day "<<i<<": ";
        cin>>rain;

        if(rain<0){
            cout<<"Invalid input\n";
            i--;
            continue;
        }

        insert(rain);
    }

    Node* temp=head;

    float total=0, max=head->data, min=head->data;
    int count=0;
    float day5=0;

    while(temp!=NULL){
        total+=temp->data;

        if(temp->data>max)
            max=temp->data;

        if(temp->data<min)
            min=temp->data;

        count++;

        if(count==5)
            day5=temp->data;

        temp=temp->next;
    }

    cout<<"Total Rainfall: "<<total<<endl;
    cout<<"Average Rainfall: "<<total/7<<endl;
    cout<<"Highest Rainfall: "<<max<<endl;
    cout<<"Lowest Rainfall: "<<min<<endl;
    cout<<"Rainfall on Day 5: "<<day5<<endl;
}