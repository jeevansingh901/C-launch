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
int length(node* head){
int len=0;
while(head!=NULL){
head= head->next;
len++;
}
return len;
}
void insertattail(node* &head,int data){

if(head==NULL){
head=new node(data);
 return;
}
node *tail=head;
while(tail->next!=NULL){
tail=tail->next;
}
tail->next=new node(data);

}
void insertatmid(node* &head,int data,int p){
if(head==NULL || p==0){
insert(head,data);
}
else if(p>length(head)){
insertattail(head,data);
}
else{
int jump=1;
node* temp=head;
while(jump<=p-1){
temp=temp->next;
jump++;

}
node *n=new node(data);
n->next=temp->next;
temp->next=n;


}
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
    
 for(int i=1;i<=5;i++){
     insert(head,i);
 }
    insertattail(head,7);
     insertatmid(head,2,4);
    print(head);

    return 0;
}
