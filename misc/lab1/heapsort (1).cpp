#include<bits/stdc++.h>

using namespace std;

struct node {
	int val;
	node *left;
	node *right;
	node *parent;
};

struct node * maxheapify(struct node *,struct node *);
void traverse(struct node *);

struct node * create_heap(struct node *root,int data,int count) {
	bitset<64> foo;
	foo = count;
	node *newnode;
	newnode = new node;
	newnode->val = data;
	newnode->parent = NULL;
	newnode->left = NULL;
	newnode->right = NULL;
	if (root == NULL) {
		root = newnode;
		return root;
	} else {
		node *temp;
		temp = new node;
		temp = root;
		int size = floor(log2(count));
		for (int i = size - 1; i >= 1; i--) {
			if (foo.test(i)) {
				temp = temp->right;
			} else {
				temp = temp->left;
			}
		}

		if (foo.test(0)) {
			newnode->parent = temp;
			temp->right = newnode;
		} else {
			newnode->parent = temp;
			temp->left = newnode;
		}
		
		root = maxheapify(root,newnode);
	}
	return root;
}

struct node * maxheapify(struct node *root,struct node *cur) {
	while (cur != root) {
		if (cur->val > cur->parent->val) {
			swap(cur->val,cur->parent->val);
			cur = cur->parent;
		} else {
			break;
		}
	}

	return root;
}

struct node * heapify(struct node *root) {
	node *temp = new node;
	temp = root;
	while (temp->left != NULL) {
		if (temp->right == NULL) {
			if (temp->val < temp->left->val) {
				swap(temp->val,temp->left->val);
				temp = temp->left;
			} else {
				break;
			}
		} else {
			int largest = max(temp->val,max(temp->left->val,temp->right->val));
			if (largest == temp->val) {
				break;
			} else if (largest == temp->left->val) {
				swap(temp->val,temp->left->val);
				temp = temp->left;
			} else {
				swap(temp->val,temp->right->val);
				temp = temp->right;
			}
		}
	}

	return root;

}
struct node * heapsort(struct node * root,int count) {
	stack<int> s;
	node * temp = new node;
	bitset<64> foo;
	while (count > 1) {
		foo = count;
		int size = log2(count);
		s.push(root->val);
		temp = root;
		for (int i = size - 1; i >= 1; i--) {
			if(foo.test(i)) {
				temp = temp->right;
			} else {
				temp = temp->left;
			}
		}
		
		if (foo.test(0)) {
			swap(temp->right->val,root->val);
			free(temp->right);
			temp->right = NULL;
		} else {
			swap(temp->left->val,root->val);
			free(temp->left);
			temp->left = NULL;
		}
		count--;
		root = heapify(root);
		foo.reset();
	}
	s.push(root->val);
	free(root);
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}

void traverse(struct node *root) {
	queue<struct node *> q;
	q.push(root);

	while (!q.empty()) {
		struct node * temp;
		temp = new node;
		temp = q.front();
		q.pop();
		cout << temp->val << " ";
		if (temp->left != NULL) {
			q.push(temp->left);
		}
		if (temp->right != NULL) {
			q.push(temp->right);
		}
	}
	cout << endl;
}

int main()
{
	int n;
	scanf("%d", &n);
	int a[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int count = 0;
	struct node * root = NULL;
	for (int i = 0; i < n; i++) {
		count++;
		root = create_heap(root,a[i],count);
	}

	root = heapsort(root,count);

	return 0;
}
