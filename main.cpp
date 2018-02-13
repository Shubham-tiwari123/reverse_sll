#include <iostream>
#include<stack>     //using stack stl function
using namespace std;
class linklist{
    struct node{
        int data;
        node *next;
    };
    node *start,*temp,*newnode,*start1,*newnode1;
    int data1,num,num1;
public:
    linklist(){
        start = NULL;
        start1 = NULL;
    }
    void enter();
    void display();
    void reverse_list();
};
void linklist::enter(){
    cout<<"Enter the number of nodes:-";
    cin>>num;
    for(int i=0;i<num;i++){
        cout<<"\nEnter the data:-";
        cin>>data1;
        if(start == NULL){
            start = new node;
            start->data = data1;
            start->next = NULL;
        }
        else{
            temp = start;
            while(temp->next != NULL){
                temp = temp->next;
            }
            newnode = new node;
            newnode->data = data1;
            newnode->next = NULL;
            temp->next = newnode;
        }
    }
}
void linklist::display(){
    temp = start;
    while(temp!=NULL){
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
}
//reversing using stack function:-
void linklist::reverse_list(){
    stack <int> g;
    temp = start;
    while(temp!=NULL){
        g.push(temp->data);     //putting data into stack while traversing
        temp=temp->next;
    }
    //puting back to linklist
    num1 = g.size();
    for(int i=0;i<num1;i++){
        if(start1 == NULL){
            start1 = new node;
            start1->data = g.top();
            start1->next = NULL;
        }

        else{
            temp = start1;
            while(temp->next != NULL){
                temp = temp->next;
            }
            newnode1 = new node;
            newnode1->data = g.top();
            newnode1->next = NULL;
            temp->next = newnode1;
        }
        g.pop();
    }
    //displaying the result after reversing
    cout<<endl<<"After reverse:-\n";

    temp = start1;
    while(temp!=NULL){
        cout<<temp->data<<"\t";
        temp=temp->next;
    }
}
int main()
{
    linklist l;
    l.enter();
    l.display();
    l.reverse_list();
}
