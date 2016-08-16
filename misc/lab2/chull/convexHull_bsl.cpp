#include <iostream>
#include <stdio.h>
#include <stdlib.h>
# include <utility>
#include <algorithm>
using namespace std;

struct node{
	int x;
	int y;
	struct node* prev;
	struct node* next;
};

int count(struct node *tail){
	int c =0;
	if(tail==NULL)return c;
	struct node* ptr = tail->next;
	while(ptr!=tail){
		c++;
		ptr = ptr->next;
	}
	c++;
	return c;
}
double eqn(int x1,int y1,int x2,int y2,int x,int y)
{
	if(((x==x1)&&(y==y1))||((x==x2)&&(y==y2))) return 0.000;
	double m = ((double)(y2-y1))/((double)(x2-x1));
	m = ((double)(y-y1)-(m*((double)(x-x1))));
	return m;
}
struct node* insert(struct node *tail,int a,int b)
{	struct node *temp =(struct node *)malloc(sizeof(struct node));
	temp->x = a;
	temp->y = b;
	temp->next = NULL;
	temp->prev = NULL;
	if(tail == NULL){
		temp->next = temp;
		temp->prev = temp;
		tail = temp;
	}
	else {
		temp->prev= tail;
		temp->next = tail->next;
		tail->next->prev = temp;
		tail->next = temp;
		tail = temp;
	}
	return tail;
}
void display(struct node *tail)
{	if(tail==NULL)return;
	struct node* ptr = tail->next;
	while(ptr!=tail){
		printf("x = %d\ty = %d\n",ptr->x,ptr->y);
		ptr = ptr->next;
	}
	printf("x = %d\ty = %d\n",tail->x,tail->y);
}
struct node *test_upper(struct node *tail,struct node *a, struct node *b)
{
	struct node* ptr = tail;
	do{
		printf("x = %d\ty = %d\n",ptr->x,ptr->y);
		if(eqn(a->x,a->y,b->x,b->y,ptr->x,ptr->y) > 0.00)
				return ptr;
		ptr = ptr->next;
	}while(ptr!=tail);
	
	return b;
}
struct node *test_lower(struct node *tail,struct node *a, struct node *b)
{
	struct node* ptr = tail;
	do{
		if(eqn(a->x,a->y,b->x,b->y,ptr->x,ptr->y) < 0.00)
				return ptr;
		ptr = ptr->next;
	}while(ptr!=tail);

	return b;
}

struct node *merge(struct node *convex_left,struct node *convex_right,struct node *tail){
	struct node *res = NULL,*ptr,*a,*b,*a1,*b1;
	if(count(convex_left)==0){
		res = convex_right;
		return res;
	}
	else if(count(convex_right)==0){
		res = convex_left;
		return res;
	}
	a1 = convex_left;
	a = convex_left;
	ptr = convex_left->next;
	while(ptr!=convex_left){
		if(ptr->y > a->y)
			a = ptr;
		if(ptr->y < a1->y)
			a1 = ptr;
		ptr = ptr->next;
	}
	b1 = convex_right;
	b = convex_right;
	ptr = convex_right->next;
	while(ptr!=convex_right){
		if(ptr->y > b->y)
			b = ptr;
		if(ptr->y < b1->y)
			b1 = ptr;
		ptr = ptr->next;
	}
	ptr = test_upper(convex_right,a,b);
	while(ptr != b) {
		if(ptr != b) b = ptr;
		ptr = test_upper(convex_right,a,b);
	}
	ptr = test_upper(convex_left,b,a);
	while(ptr != a) {
		a = ptr;
		ptr = test_upper(convex_left,b,a);
	}
	ptr  = test_lower(convex_right,a1,b1);
	while(ptr != b1) {
		b1 = ptr;
		ptr = test_lower(convex_right,a1,b1);
	}
	ptr  = test_lower(convex_left,b1,a1);
	while(ptr != a1) {
		a1 = ptr;
		ptr = test_lower(convex_left,b1,a1);
	}

	ptr = a1;
	while(ptr != a){
		res = insert(res,ptr->x,ptr->y);
		ptr = ptr->next;
	}
	res = insert(res,ptr->x,ptr->y);
	ptr = b;
	while(ptr != b1){
		res = insert(res,ptr->x,ptr->y);
		ptr = ptr->next;
	}
	res = insert(res,ptr->x,ptr->y);
	return res;
}

struct node *convexhull(struct node *tail){
	struct node *res = NULL,*p = NULL, *ptr = NULL;
	int n = count(tail);
	int mid = n/2;
	if(n==0){
		return res;
	}
	else if(n==1){
		res = insert(res,tail->x,tail->y);
		return res;
	}
	else if(n==2){
		res = insert(res,tail->x,tail->y);
		res = insert(res,tail->prev->x,tail->prev->y);
		return res;
	}
	/*else {
		printf("Here!!!\n");
		int flag = 0;
		int k = tail->next->x;
		p = tail->next->next;
		ptr = tail->next;
		while(p!=ptr){
			if(p->x!=k){
				printf("Here flag = 1!!!\n");
				flag = 1;
				break;
			}
			p = p->next;
		}
		if(flag == 0){			
			res = insert(res,tail->next->x,tail->next->y);
			res = insert(res,tail->x,tail->y);
			printf("Here flag = 0!!!\n");
			return res;
		}*/
		else {
			printf("Here flag = 1!!!!\n");
			struct node *left = NULL, *right = NULL;
			cout<<"tail to be divided\n";
			display(tail);
			ptr = tail->next;
			int i = 1;
			while(i <= mid){
					left=insert(left,ptr->x,ptr->y);
					cout<<"Inserting in left\n";
					ptr = ptr->next;
					i++;
			}
			while(i <= n){
				cout<<"Inserting in right\n";
				right = insert(right,ptr->x,ptr->y);
				ptr = ptr->next;
				i++;
			}
			
			/*cout<<"LEFT IS\n";
			display(left);
			cout<<"RIGHT IS\n";
			display(right);*/
			struct node *left_hull = NULL, *right_hull = NULL;
			left_hull = convexhull(left);
			right_hull = convexhull(right);
			cout<<"LEFT HULL IS\n";
			display(left_hull);
			cout<<"RIGHT HULL IS\n";
			display(right_hull);						
			res = merge(left_hull,right_hull,tail);
			cout<<"HULL IS\n";
			display(res);
			return res;
		}
	//}
}
int main()
{	struct node *tail = NULL,*res = NULL;
	int n, i;
	pair<int,int> p[100];
	scanf("%d", &n);
	int x[n];
	int y[n];	
	for (i = 0; i < n; i++) {
		scanf("%d%d",&x[i],&y[i]);
		p[i] = make_pair(x[i],y[i]);
	}
	sort(p,p+n);
	for (i = 0; i < n; i++) {
		x[i] = p[i].first;
		y[i]  = p[i].second;
	}
	for(i=0;i<n;i++)
		tail = insert(tail,x[i],y[i]);
	//display(tail);
	res = convexhull(tail);
	cout<<"HULL IS:\n";
	display(res);
}
