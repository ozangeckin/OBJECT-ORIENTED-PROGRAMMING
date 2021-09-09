#include<iostream>

using namespace std;

class Node{
    public:
        Node(int data_){
            data=data_;
            next=NULL;
        }
        int data;
        Node *next;
};


class LinkedList{
    public:
        LinkedList(){
            head=NULL;
        }
        void push(int data_){
            Node* temp =new Node(data_);
            temp->next=head;
            head=temp;

        }
        void print(){
            Node *temp=head;
            while(temp !=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
        }
        Node* getHead(){
            return head;
        }
        void setHead(Node *other){
            head=other;

        }
    private:
        Node *head;

};

void reverse(LinkedList& list){
    Node *current=list.getHead();
    Node *prev=NULL,*next=NULL;

    while(current !=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    list.setHead(prev);
}

int main(){
    LinkedList obje;
    obje.push(10);
    obje.push(20);
    obje.push(30);
    obje.push(40);

    cout<<"Orjinal Link List :"<<endl;
    obje.print();
    reverse(obje);
    cout<<"\n\nReverse Link List :"<<endl;
    obje.print();
    cout<<endl;
    return 0;
}