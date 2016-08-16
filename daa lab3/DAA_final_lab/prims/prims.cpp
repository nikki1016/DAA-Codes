# include <iostream>
# include <queue>
using namespace std;

struct list{

	int item;
	int weight;
	struct list *next;
};

struct node{
	
	int src;
	int dest;
	int wt;
};

struct tree {
	
	node item;
	tree *left;
	tree *right;
	tree *parent;
};

queue<tree*> q;
tree *save = NULL;
tree *recent = NULL;
tree *recent_dele_parent = NULL;
	

void adj_list_insert(list *a[],int y, int z, int w)
{
	list *temp;
	
	if(a[y] == NULL) {
		a[y] = new list;
		a[y] -> item = z;
		a[y] -> weight = w;
		a[y] -> next = NULL;
	} else {

		temp = a[y];

		while(temp -> next != NULL) {
			if(temp -> item == z) {
				return;
			}
			temp = temp -> next;
			
		}

		temp -> next = new list;
		temp -> next -> item = z;
		temp -> next -> weight = w;
		temp -> next -> next = NULL;
	}

	

	if(a[z] == NULL) {

		a[z]  = new list;
		a[z] -> item = y;
		a[z] -> weight = w;
		a[z] -> next = NULL;
	} else {

		temp = a[z];
		while(temp -> next != NULL) {

			if(temp -> item == y) {
				return;
			}
			temp = temp -> next;
		}

		temp -> next = new list;
		temp -> next -> item = y;
		temp -> next -> weight = w;
		temp ->next -> next = NULL;
	}
	

}

bool search(int b[], int ctr, int k)
{
	for (int i = 0; i < ctr; i++){
		if(b[i] == k) return true;
	}
	return false;
}




void heapify(tree *root)
{

	if(root == NULL) return;
	

	tree *temp;
	temp = root;

	while(root != NULL) {

		if(root -> left == NULL && root -> right == NULL) {
			break;
		} else if (root -> left == NULL) {
			if(root -> item.wt > root -> right -> item.wt){
				swap(root -> item, root ->right->item);
			}
		} else if (root -> right == NULL) {
			if(root -> item.wt > root -> left -> item.wt){
				swap(root -> item,root -> left -> item);
			}
		} else {
			
			int y;
			y = min(root -> left -> item.wt, root -> right -> item.wt);

			if(y < root -> item.wt) {
				if(y == root -> left -> item.wt){
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

	
	
node extract_min( tree *root)
{

	node x;
	tree *temp;
	tree *to_be_del;
	if(recent == root) {
		
		x = root -> item;
		root = recent = NULL;
		save = NULL;
		return x;
	} else {

		to_be_del = recent;
		swap(root -> item, recent -> item);
		x = recent -> item;
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

	return x;
}
		
		
		
		
		


void min_heap_insert(tree *root,int s, int d, int w)
{
	tree *temp;

	if(root == NULL){
		root = new tree;
		root -> item.src = s;
		root -> item.dest = d;
		root -> item. wt = w;

		root -> left = root -> right = NULL;
		root -> parent = NULL;
		q.push(root);
		q.push(root);
		save = root;
		recent = root;
	} else {

			
			if( recent_dele_parent != NULL && recent_dele_parent -> left == NULL){
				
					recent_dele_parent -> left = new tree;
					recent_dele_parent -> left -> item.src = s;
					recent_dele_parent -> left -> item.dest = d;
					recent_dele_parent -> left -> item.wt = w;
					recent_dele_parent -> left -> left = NULL;
					recent_dele_parent -> left -> right = NULL;
					recent_dele_parent -> left -> parent = recent_dele_parent;
					recent = recent_dele_parent -> left;
			} else if ( recent_dele_parent != NULL && recent_dele_parent -> right == NULL && recent_dele_parent != q.front()){

					recent_dele_parent -> right = new tree;
					recent_dele_parent -> right -> item.src = s;
					recent_dele_parent -> right -> item.dest = d;
					recent_dele_parent -> right -> item.wt = w;
					recent_dele_parent -> right -> left = NULL;
					recent_dele_parent -> right -> right = NULL;
					recent_dele_parent -> right -> parent = recent_dele_parent;
					recent = recent_dele_parent -> right;
			}  else {

			temp = q.front();
			q.pop();

			
			if (temp -> left == NULL) {
				
				temp -> left = new tree;
				temp -> left -> item.src = s;
				temp -> left -> item.dest = d;
				temp -> left -> item.wt = w;
				temp -> left -> left = NULL;
				temp -> left -> right = NULL;
				temp -> left -> parent = temp;
				q.push(temp -> left);
				q.push(temp -> left);
				recent = temp -> left;
			} else {

				temp -> right = new tree;
				temp -> right -> item.src = s;
				temp -> right -> item.dest = d;
				temp -> right -> item.wt = w;
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
				
	
			
		
	
void prims(list *a[],int n)
{

	int b[n];
	int edge[100][2];
	int ctr = 0;
	int sz = 0;
	bool visited[n+1][n+1];
	list *temp;

	
	tree *root = NULL;
	b[ctr] = 1;
	ctr++;


	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= n; j++) {
			visited[i][j] = false;
		}
	}

	temp = a[1];
	
	while(temp != NULL){
		root = save;
		min_heap_insert(root,1,temp -> item,temp -> weight);
		temp = temp -> next;
	
	}
	
	node m;
	root = save;
	
	
	while(ctr < n){
		root = save;
		m = extract_min(root);
	//	cout << m.wt << endl;
		if(visited[m.src][m.dest] == true || search(b,ctr,m.dest) == true){
			continue;
		} else {


			edge[sz][0] = m.src;
			edge[sz][1] = m.dest;
			sz++;
			b[ctr] = m.dest;
			ctr++;
			
			temp = a[m.dest];
			while(temp != NULL){
				root = save;
				if(search(b,ctr,temp -> item) == false){
					//cout << "Inserting" << temp -> item << endl;
					min_heap_insert(root,m.dest,temp -> item,temp -> weight);
				}
				temp = temp -> next;
			}

			visited[m.src][m.dest] = true;
			visited[m.dest][m.src] = true;
		}
	}

	for (int i = 0; i < sz; i++) {
		cout << edge[i][0] << " " << edge[i][1] << endl;
	}

}
			

	
	

	

int main()
{
	cout << "Enter number of vertices\n";

	int n;   // n is the number of vertices.
	cin >> n;

	list* adj[n+1];

	for (int i = 0; i < n+1; i++) {

		adj[i] = NULL;
	}

	cout << "Enter number of edges\n";
	int x;
	cin >> x;

	cout << "Enter" << x << "edges\n";

	for (int i = 0; i < x; i++) {

		int y,z,w;
		cin >> y >> z >> w;

		adj_list_insert(adj,y,z,w);
	}

	
	/*
	for (int i = 1; i <= n; i++){
		temp = adj[i];
		while(temp != NULL){
			cout << temp -> item << " ";
			temp = temp -> next;
		}

		cout << endl;
	}
		
	cout << endl << endl << endl;
	*/
	prims(adj,n);

	
	return 0;
}



	
