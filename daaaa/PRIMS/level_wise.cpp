# include <iostream>
# include <queue>
using namespace std;

struct tree{
	int item;
	tree *left;
	tree *right;
	tree *parent;
};


tree *save = NULL;
tree *recent= NULL;
tree *recent_dele_parent = NULL;

queue<tree *> q;


void heapify(tree *root)
{

	if(root == NULL) return;
	

	tree *temp;
	temp = root;

	while(root != NULL) {

		if(root -> left == NULL && root -> right == NULL) {
			break;
		} else if (root -> left == NULL) {
			if(root -> item > root -> right -> item){
				swap(root -> item, root ->right->item);
			}
		} else if (root -> right == NULL) {
			if(root -> item > root -> left -> item){
				swap(root -> item,root -> left -> item);
			}
		} else {
			
			int y;
			y = min(root -> left -> item, root -> right -> item);

			if(y < root -> item) {
				if(y == root -> left -> item){
					swap(root -> left -> item, root -> item);
				} else {
					swap(root -> right -> item, root -> item);
				}
			} 
		}

		root = root -> parent;
	}

	heapify(temp -> left);
	heapify(temp -> right);
}
void min_heap_insert(tree *root,int s)
{
	tree *temp;

	if(root == NULL){
		root = new tree;
		root -> item = s;

		root -> left = root -> right = NULL;
		root -> parent = NULL;
		q.push(root);
		q.push(root);
		save = root;
		recent = root;
	} else {

			
			if( recent_dele_parent != NULL && recent_dele_parent -> left == NULL){
				
					recent_dele_parent -> left = new tree;
					recent_dele_parent -> left -> item = s;
					recent_dele_parent -> left -> left = NULL;
					recent_dele_parent -> left -> right = NULL;
					recent_dele_parent -> left -> parent = recent_dele_parent;
					recent = recent_dele_parent -> left;
			} else if ( recent_dele_parent != NULL && recent_dele_parent -> right == NULL && recent_dele_parent != q.front()){

					recent_dele_parent -> right = new tree;
					recent_dele_parent -> right -> item = s;
					recent_dele_parent -> right -> left = NULL;
					recent_dele_parent -> right -> right = NULL;
					recent_dele_parent -> right -> parent = recent_dele_parent;
					recent = recent_dele_parent -> right;
			}  else {

			temp = q.front();
			q.pop();

			
			if (temp -> left == NULL) {
				
				temp -> left = new tree;
				temp -> left -> item = s;
				temp -> left -> left = NULL;
				temp -> left -> right = NULL;
				temp -> left -> parent = temp;
				q.push(temp -> left);
				q.push(temp -> left);
				recent = temp -> left;
			} else {

				temp -> right = new tree;
				temp -> right -> item = s;
				temp -> right -> left = NULL;
				temp -> right -> right = NULL;
				temp -> right -> parent = temp;
				q.push(temp -> right);
				q.push(temp -> right);
				recent = temp -> right;
			}
		}
	}

	root = save;
	heapify(root);

	root = save;
//	cout << save -> item.wt << " " << recent -> item.wt << endl;
//	print_level(root);
//	cout << endl << endl << endl;

	
}


void print_level_sum(tree *root)
{
	
	queue<tree*> q1;
	tree *p;
	int s = 0;
	int cur = 0;
	int nex = 0;
	q1.push(root);
	cur++;
	

	while(!q1.empty()){
		
		p = q1.front();
		q1.pop();
		cur--;

		s = s + p -> item;

		if(p -> left != NULL){
			q1.push(p -> left);
			nex++;
		} 
		if(p -> right != NULL) {
			q1.push(p -> right);
			nex++;
		}
		

		if(cur == 0) {
			cout << s << endl;
			cur = nex;
			nex = 0;
			s = 0;
		}
	}
}

int main()
{
	int n;
	cin >> n;

	tree *root = NULL;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		root = save;
		min_heap_insert(root,x);
	}

	print_level_sum(root);
	return 0;
}
