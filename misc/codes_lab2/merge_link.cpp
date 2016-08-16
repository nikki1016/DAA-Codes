#include<stdio.h>
#include<stdlib.h>

struct node{
	int val;
	struct node *next;
};
struct node *root = NULL;
int ctr = 0;
void create(int data)
{
	struct node *p = (struct node *)malloc(sizeof(struct node));
	struct node *temp;
	p->val = data;
	p->next = NULL;
	if(root == NULL)
	{
		root = p;
		ctr++;
	}
	else {
		temp = root;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = p;
		ctr++;
	}
}
void display()
{
	struct node *t = root;
	int temp = ctr;
	while(temp != 1)
	{
		printf("%d->",t->val);
		t = t->next;
		temp--;	
	}
	printf("%d\n",t->val);
}
struct node *merge(struct node *p,struct node *q)
{
	struct node *start_merge, *x;
	if(p->val <= q->val)
	{
		start_merge = p;
		p = p->next;
	}
	else {
		start_merge = q;
		q = q->next;
	}
	
	x = start_merge;
	
	while(p != NULL && q != NULL)
	{
		if(p->val <= q->val)
		{
			x->next = p;
			x = x->next;
			p = p->next;
		}
		else {
			x->next = q;
			x = x->next;
			q = q->next;
		}
	}
	if(p != NULL)
	{
		x->next = p;
	}
	else {
		x->next = q;
	}
	return start_merge;
}
struct node *divide(struct node *p)
{
	struct node *q,*start_sec;
	q = p->next->next;
	while(q != NULL)
	{
		p = p->next;
		q = q->next;
		if(q != NULL)
		{
			q = q->next;
		}
	}
	start_sec = p->next;
	p->next = NULL;
	return start_sec;
}
struct node *merge_sort(struct node *r)
{
	struct node *start_1,*start_2,*start_merge;
	if(r != NULL && r->next != NULL)
	{
		start_1 = r;
		start_2 = divide(r);
		start_1 = merge_sort(start_1);
		start_2 = merge_sort(start_2);
		start_merge =  merge(start_1,start_2);
		return start_merge;
	}
	else {
		return r;
	}
}
int main()
{
	create(23);
	create(34);
	create(12);
	create(5);
	create(89);
	create(7);
	display();
	root = merge_sort(root);
	//printf("%d \n",root->next->val);
	display();
	return 0;
}

