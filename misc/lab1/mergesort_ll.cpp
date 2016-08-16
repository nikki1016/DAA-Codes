#include <stdio.h>
#include <stdlib.h>

struct node {
	int info;
	struct node *next;
};

int ctr = 0;
struct node *create(struct node *head, int val);
struct node *merge(struct node *p1, struct node *p2);
struct node *divide (struct node *p);
struct node *mergesort(struct node *start);
void display(struct node *head);

int main()
{
	struct node *head = NULL;
	head = create(head, 5);
	head = create(head, 7);
	head = create(head, 9);
	head = create(head, 10);
	head = create(head, 2);
	
	head =mergesort(head);
	display(head);
	
}

struct node *create(struct node *head, int val)
{
	struct node *n, *ptr;
	n = (struct node *)malloc(sizeof(struct node));
	n->info = val;
	n->next = NULL;
	
	if (ctr == 0) {	
		head = n;
		ctr++;
	}
	else {
		ptr = head;
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = n;
		ctr++;
	}
	
	return head;
}

void display(struct node *head)
{
	struct node *ptr;
	ptr = head;
	
	while (ptr->next != NULL) {
		printf("%d-->", ptr->info);
		ptr= ptr->next;
	}
	printf("%d\n", ptr->info);
	
}

struct node *mergesort(struct node *start)
{
	struct node *start_first, *start_second, *start_merged;
	
	if (start != NULL && start->next != NULL) {
		start_first = start;
		start_second = divide(start);
		start_first = mergesort(start_first);
		start_second = mergesort(start_second);
		start_merged = merge(start_first, start_second);
		return start_merged;
	}
	else
		return start;
}

struct node *divide (struct node *p)
{
	struct node *q, *start_sec;
	q = p->next->next;
	
	while (q != NULL) {
		p = p->next;
		q = q->next;
		if (q != NULL)
			q = q->next;
	}
	start_sec = p->next;
	p->next = NULL;
	return start_sec;
}

struct node *merge(struct node *p1, struct node *p2) {
	struct node *sm, *q;
	if (p1->info <= p2->info) {
		sm = p1;
		p1 = p1->next;
	}
	else {
		sm = p2;
		p2 = p2->next;
	}
	
	q = sm;
	
	while (p1!= NULL && p2 != NULL ) {
		if (p1->info <= p2->info) {
			q->next = p1;
			q = q->next;
			p1= p1->next;
		}
		else {
				q->next = p2;
			q = q->next;
			p2= p2->next;
		}
	}
	
	if (p1!= NULL) {
		q->next = p1;
	}
	else
		q->next = p2;
		
	return sm;	
}


