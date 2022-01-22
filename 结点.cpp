#include <bits/stdc++.h>
using namespace std;
struct node{
	int data;
	node*next;
};
node* create(int a[]){
	node* p,*pre,*head;
	head=new node;
	head->next=NULL;
	pre=head;
	for(int i=0; i<5 ;++i){
		p=new node;
		p->data=a[i];
		p->next=NULL;
		pre->next=p;
		pre=p;
	}
	return head;
}
void divide(node *head){
	node* odd=head;
	node* even=head->next;
	node* p=odd;
	node* q=even;
	while(odd->next!=NULL||odd->next->next!=NULL){
		odd->next=odd->next->next;
		odd=odd->next;
		even->next=even->next->next;
		even=even->next;
	}
	while(p!=NULL){
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
	while(q!=NULL){
		cout<<q->data<<" ";
		q=q->next;
	}
}

int search(node *head,int x){
	int count=0;
	node* p=head->next;
	while(p!=NULL){
		if(p->data==x){
			count++;
		}
		p=p->next; 
	}
	return count;
}

void insert(node* head, int pos, int x){
	node* p=head;
	for(int i=0; i<pos-1; i++){
		p=p->next;
	}
	node* q=new node;
	q->data=x;
	q->next=p->next;
	p->next=q;
}

node* reverse(node* head){
	node* p=head;
	node* q=NULL;
	node* tmp;
	while(p!=NULL){
		tmp = p;
		p = p->next;
		tmp->next = q;
		q =tmp;
	}
	
	return q;
}

node* reverse1(node* head) {
	if (head == NULL || head->next == NULL)
		return head;
	node* newHead =	reverse1(head->next);
	head->next->next = head;
	head->next = NULL;
	
	return newHead;
}
int main()
{
	int a[5]={5,3,6,1,2};
	node* head=create(a);
	node* L=head->next;
	while(L!=NULL){
		cout<<L->data<<" ";
		L=L->next;
	}
	node* newHead=reverse1(head->next);
	while(newHead!=NULL){
		cout<<newHead->data<<" ";
		newHead=newHead->next;
	}
	divide(head->next);
	return 0;
}
