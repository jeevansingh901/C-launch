#include <iostream>

using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int d){
        data=d;
        next=NULL;
    }
};


void insert(node* &head,int data){
    node *n=new node(data);
    n->next=head;
    head=n;
}
void print(node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}
int main()
{
    node* head=NULL;
    for(int i=0;i<=5;i++){
    insert(head,i);
    }
    print(head);

    return 0;
}
