#include<iostream>
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
void insert(node* &head, int data){
    node *n=new node(data);
    n->next=head;
    head=n;

}
int length(node* head){
    int len=0;
    while(head!=NULL){
        len++;
        head=head->next;
    }
    return len;
}
void insertattail(node *&head,int data){
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
       if(head==NULL||p==0){
           insert(head,data);


       }
else if(p>length(head)){
insertattail(head,data);

}
else {
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
void deleteAthead(node* &head){
if(head==NULL){
    return;
}
node* temp=head;
head=head->next;
delete(temp);

}
void deleteAtEnd(node* &head){
if(head==NULL){
    return;
}

    node* prev=NULL;
    node *temp=head;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    delete(temp);
    prev->next=NULL;



}
void deleteAtmid(node*&head,int p){
if(head==NULL||p==0){
    return;
}
else if(p>length(head)){
    deleteAtEnd(head);
}
else {
    int jump=1;
    node* temp=head;
    while(jump<p-1){
        temp=temp->next;
        jump++;
    }
     node *k=temp->next;
     temp->next=temp->next->next;
     delete(k);

}


}
void print(node* head){
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }
}
void rev(node* &head){
node *p=NULL;
node *c=head;
node *n;
while(c!=NULL){
    n=c->next;
    c->next=p;
    p=c;
    c=n;
}
head=p;
}
int main(){

  node* head=NULL;

 for(int i=1;i<=5;i++){
     insert(head,i);
 }

    insertattail(head,7);
     insertatmid(head,8,4);
    print(head);
    cout<<endl;
   deleteAthead(head);
   deleteAtmid(head,3);
   deleteAtEnd(head);
   print(head);
   rev(head);
   cout<<endl;
   print(head);

return 0;

}
