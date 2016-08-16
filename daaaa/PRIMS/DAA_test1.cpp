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

void put_recent(tree *to_be_del,tree *temp)
{


	if(temp == NULL){
		temp = save;
		while(temp -> right != NULL){
			temp = temp -> right;
		}

		recent = temp;
		return;
	}
	if(to_be_del == temp -> right){
		temp = temp -> left;

		while(temp -> right != NULL) {
			temp = temp -> right;
		}

		if(temp -> left != NULL){
			recent = temp -> left;
		} else {
			recent = temp;
		}
		return;
	}
	
	put_recent(to_be_del -> parent,temp -> parent);
}

	
	
void extract_min( tree *root)
{

	int x;
	tree *temp;
	tree *to_be_del;
	if(recent == root) {
		
		x = root -> item;
		root = recent = NULL;
	//	cout << x << " ";
	} else {

		to_be_del = recent;
		swap(root -> item, recent -> item);
		x = recent -> item;
	//	cout << x << " ";
		temp = recent -> parent;

	

		put_recent(to_be_del,temp);
		
		
		if(to_be_del == temp -> left) {
			
			temp -> left = NULL;
		} else {
			temp  -> right = NULL;
		}
	
		recent_dele_parent = temp;
	

		
		
		
	}

	root = save;
	heapify(root);

//	cout << recent_dele_parent -> item.wt << endl << endl;

}
		
		
int print_height(tree *root)
{
	if(root == NULL){
		return 0;
	} else {
		return 1 + max(print_height(root -> left),print_height(root -> right));
	}
}		
		

void print_level(tree *root)
{
	queue<tree *> q1;
	q1.push(root);
	tree *temp;

	while(!q1.empty()){
		temp = q1.front();
		q1.pop();

		cout << "Parent is " << temp -> item << " ";
		
		if(temp -> left != NULL){
			cout << "Left child is " << temp -> left -> item << " ";
			q1.push(temp -> left);
		} 
		if (temp -> right != NULL){
			cout << "Right child is "<<temp -> right -> item <<endl;
			q1.push(temp -> right);
		}
	}
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




int main()
{

	tree *root = NULL;

	for (int i = 0; ; i++){
		cout << "1.Insert\n2.Delete\n3.Print_height\n4. Print_level";

		int k;
		cin >> k;

		if(k == 1){

			int p;
			cout << "Enter the value\n";
			cin >> p;
			root = save;
			min_heap_insert(root,p);
		} else if (k == 2){
			root = save;
			 extract_min(root);
		} else if(k == 3){
			root =save;
			if(root -> left != NULL){
			cout << print_height(root -> left) << " ";
			} else {
				cout << "Left is NULL\n";
			}

			if(root -> right != NULL){
			cout << print_height(root -> right) << endl;
			} else {
				cout << "Right is NULL\n";
			}
		} else if(k == 4){
			root = save;
			print_level(root);
		}
	}
		
	return 0;
}
