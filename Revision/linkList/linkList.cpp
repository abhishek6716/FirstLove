#include<iostream>
using namespace std;

class Node{
    public: 
    int data;
    Node *next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

void print(Node *head){
    Node *temp=head;
    while (temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

Node* takeInput(){
    int data;
    cin>>data;
    Node *head=NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head==NULL){
            head=newNode;
        } else{
            Node *temp=head;
            while(temp->next != NULL){
                temp=temp->next;
            }
            temp->next=newNode;
        }
        cin>>data;
    }
    return head;
}

Node* takeInput2(){
    int data;
    cin>>data;
    Node *head=NULL;
    Node *tail=NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
        } else{
            tail->next=newNode;
            tail=newNode;
        }
        cin>>data;
    }
    return head;
}

int lengthLL(Node *head){
    Node *temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}

int lengthLL_rec(Node *head){
    if(head==NULL){
        return 0;
    }
    return lengthLL_rec(head->next)+1;
}

void printithNode(Node *head, int i){
    Node *temp=head;
    int k=0;
    while(k<i){
        temp=temp->next;
        k++;
    }
    cout<<temp->data<<endl;
}

Node* insertNode(Node *head, int i, int data){
    Node *newNode = new Node(data);
    int cnt=0;
    Node *temp=head;
    if(i==0){
        newNode->next=head;
        head=newNode;
        return head;
    }
    while(temp != NULL && cnt<i-1){
        temp=temp->next;
        cnt++;
    }
    if(temp!=NULL){
        Node *a=temp->next;
        temp->next=newNode;
        newNode->next=a;
    }
    return head;
}

Node* InsertNode_rec(Node *head, int i, int data){                             // insertNode rec
    if(head==NULL){
        if(i==0){
            Node *newNode=new Node(data);
            return newNode;
        }
        else{
            return head;
        }
    }
    Node *newNode=new Node(data);
    if(i==0){
        newNode->next=head;
        head=newNode;
        return head;
    }
    head->next=InsertNode_rec(head->next, i-1, data);
    return head;
}

Node* deleteNode(Node *head, int i){
    int cnt=0;
    Node *temp=head;
    if(i==0){
        Node *a=head;
        head=head->next;
        delete a;
        return head;
    }
    while(temp != NULL && cnt<i-1){
        temp=temp->next;
        cnt++;
    }
    if(temp!=NULL && temp->next != NULL){
        Node *a=temp->next;
        temp->next=temp->next->next;
        delete a;
    }
    return head;
}

Node* DeleteNode_rec(Node *head, int pos){                                     // delete node rec
    if(head==NULL){
        return head;
    }
    if(pos==0){
        Node *temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    Node *smallHead=DeleteNode_rec(head->next, pos-1);
    head->next=smallHead;
    return head;
}

int findIndex(Node *head, int n){
    Node *temp=head;
    int cnt=0;
    while (temp!=NULL){
        if(temp->data==n){
            return cnt;
        }
        temp=temp->next;
        cnt++;
    }
}

Node* appendLastNtoFirst(Node *head, int n){
    if(head==NULL || n==0){
        return head;
    }
    Node *p1=head;
    Node *p2=head;
    Node *initialHead=head;
    for(int i=0; i<n; i++){
        p1=p1->next;
    }
    while(p1->next!=NULL){
        p1=p1->next;
        p2=p2->next;
    }
    Node *temp=p2->next;
    p2->next=NULL;
    p1->next=initialHead;
    head=temp;
    return head;
}

Node* RemoveDuplicates(Node* head){                                            // remove duplicates
    if(head==NULL){                                                            // input:  1 1 2 2 3 3 4 5 5 6
        return head;                                                           // output: 1 2 3 4 5 6
    }
    Node* temp=head;
    while(temp->next!=NULL){
        if(temp->data==temp->next->data){
            Node* a=temp->next;
            temp->next=temp->next->next;
            delete a;
        }
        else{
            temp=temp->next;
        }
    }
    return head;
}

void PrintReverse(Node* head){                                                 // Print Reverse
    if(head==NULL){
        return;
    }
    PrintReverse(head->next);
    cout<<head->data<<" ";
}

Node* ReverseLinkedList(Node* head){                                           // reverselinkedlist
    Node* curr=head;
    Node* prev=NULL;
    Node* fwd=NULL;

    while(curr!=NULL){
        fwd=curr->next;
        curr->next=prev;
        prev=curr;
        curr=fwd;
    }
    return prev;
}

bool isPelindrome(Node *head){
    if(head==NULL || head->next==NULL){
        return true;
    }
    Node* fast=head;
    Node* slow=head;
    while(fast->next!=NULL && fast->next->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }

    Node* secondHead=slow->next;
    slow->next=NULL;
    secondHead=ReverseLinkedList(secondHead);

        //compare the two sublists
    Node* firstSubList=head;
    Node* secondSubList=secondHead;
    bool ans=true;

    while(secondSubList!=NULL){
        if(firstSubList->data != secondSubList->data){
            ans=false;
            break;
        }
        firstSubList=firstSubList->next;
        secondSubList=secondSubList->next;
    }

    //rejoins the two sublists
    firstSubList=head;
    secondSubList=ReverseLinkedList(secondHead);

    while(firstSubList->next != NULL){
        firstSubList=firstSubList->next;
    }
    firstSubList->next=secondSubList;
    return ans;
}

int main(){
    // Node n1(100);
    // Node n2(200);
    // Node n3(300);
    // Node n4(400);
    // Node n5(500);
    // Node n6(600);
    // Node *head=&n1;
    // n1.next=&n2;
    // n2.next=&n3;
    // n3.next=&n4;
    // n4.next=&n5;
    // n5.next=&n6;
    // print(head);

    // Node *m1=new Node(10);
    // Node *m2=new Node(20);
    // Node *m3=new Node(30);
    // Node *m4=new Node(40);
    // Node *m5=new Node(50);
    // Node *head2=m1;
    // m1->next=m2;
    // m2->next=m3;
    // m3->next=m4;
    // m4->next=m5;

    Node *head = takeInput();
    print(head);
    cout<<lengthLL(head)<<endl;
    cout<<lengthLL_rec(head)<<endl;
    // insertNode(head, 3, 23);
    // deleteNode(head, 10);
    print(head);
}