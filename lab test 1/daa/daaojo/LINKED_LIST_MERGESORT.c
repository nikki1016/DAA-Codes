#include <stdio.h>
#include <stdlib.h>

struct node {
	int info;
	struct node *next; 
};
struct node *root;
int ctr = 0;
struct node *divide(struct node *p){
	struct node *q,*ss;
	q=p->next->next;
	while(q!=NULL){
		p=p->next;
		q=q->next;
		if(q!=NULL) q = q->next;
	}
	ss = p->next;
	p->next = NULL;
	return ss;
}

struct node *merge(struct node *p1,struct node *p2){
	struct node *sm,*q;
	if(p1->info <= p2->info){
		sm = p1;
		p1 = p1->next;
	}
	else {
		sm = p2;
		p2 = p2->next;
	}
	q = sm;
	while(p1!=NULL && p2!=NULL){
		if(p1->info<=p2->info){
			q->next = p1;
			q=q->next;
			p1 =p1->next;
		}
		else {
			q->next = p2;
			q = q->next;
			p2 = p2->next;
		}
	}
	if(p1!=NULL)
	q->next = p1;
	else
	q->next = p2;
	return sm;
}
struct node *merge_sort(struct node *start)
{
	struct node *sf,*ss,*sm;
	if(start!=NULL && start->next !=NULL){
		sf = start;
		ss = divide(sf);
		sf = merge_sort(sf);
		ss = merge_sort(ss);
		sm = merge(ss,sf);
	}
	else return start;
}

void create(int h){
	struct node *n = (struct node *)malloc(sizeof(struct node));
	n->info = h;
	n->next = NULL;
	if(ctr==0){
		root = n;
		ctr++;
	}
	else {
		struct node *t = root;
		while(t->next!=NULL){
			t = t->next;
		}
		t->next = n;
		ctr++;
	}
}

void display(){
	struct node *t = root;
		while(t->next!=NULL){
			printf("%d->",t->info);
			t = t->next;
		}
		printf("%d\n",t->info);
}
int main()
{	int a;
	while(1){
		scanf("%d",&a);
		if(a==-1) break;
		create(a);
	}
	display();
	root = merge_sort(root);
	display();	
}
