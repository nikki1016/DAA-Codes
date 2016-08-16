#include <iostream>
#include <queue>
using namespace std;
struct edge{
	int start;
	int end;
	int weight;
};
struct node{
	edge n;
	struct node *left;
	struct node *right;
	struct node *parent;
};
int matrix[100][100];
int no_of_nodes = 0;
queue<struct edge> result;
void insert(struct node **head, queue<struct node *> &que , int s, int d, int x)
{
	struct node *p = NULL, *q = NULL;
	p = new struct node;
	p->n.weight = x;
	p->n.start = s;
	p->n.end = d;
	p->right = p->left = NULL;

	if((*head) == NULL){
		p->parent = NULL;
		*(head) = p;
		que.push(*head);
	} else {
		q = que.front();

		if(q->left == NULL){
			p->parent = q;
			q->left = p;
			que.pop();
		
		}else {
			p->parent = q;
			q->right = p;
		}
		que.push(p);
	}
	return ;
}
void heapify(struct node *p){
	int largest = p->n.weight, ctr = 0;
	struct edge enode = p->n;
	if(p->left != NULL){
		heapify(p->left);
		if(largest >= p->left->n.weight){
			largest = p->left->n.weight;
			ctr = 1;
		}
	}
	if(p->right != NULL){
		heapify(p->right);
		if(largest >= p->right->n.weight){
			largest = p->right->n.weight;
			ctr = 2;
		}
	}
	if(ctr == 1){
		p->n = p->left->n;
		p->left->n = enode;
	}else if(ctr == 2){
		p->n = p->right->n;
		p->right->n = enode;
	}
//	p = p->parent;

}
bool invisited(int visited[], int name){
	for(int i = 0; i < no_of_nodes; i ++){
		if( visited[i] == name){
			return 1;
		}
	}
	return 0;
}
void prims(){
	int start_node, visited_node = 0 , visited[no_of_nodes];
	int i;
	struct edge mindistance;
	cout << "enter node to start\n";
	cin >> start_node;
	visited[visited_node] = start_node;
	visited_node ++;
	while(visited_node != no_of_nodes){
		struct node *head = NULL;
		node *save = NULL;
		queue<struct node *> que;
		for(int j = 0; j < visited_node ; j++ ){
			for(i = 0; i < no_of_nodes; i ++){
				if(matrix[visited[j]][i] != -1 && !invisited(visited,i)) {
					insert(&head,que,visited[j],i,matrix[visited[j]][i]);
					if(j == 0 && i == 0){
						save = head;
					}
				}
			}
		}
		cout << "Inserted\n";
		heapify(save);
		cout << "Heapified\n";
		mindistance = save->n;
		//NASTY COUT ...... :( :( :(
	//	cout << "minium edge found this time was " << mindistance.start << " to " << mindistance.end << " with weight " << mindistance.weight << endl;
		visited[visited_node] = mindistance.end;
		cout << "Here";
		visited_node ++;
		result.push(mindistance);
		matrix[mindistance.start][mindistance.end] = -1;
		matrix[mindistance.end][mindistance.start] = -1;
	}
}
int main()
{
	int i,j;
	int no_of_edges, start_n ,visited_nodes = 0;
	cout << "enter no of nodes and no of edges respectively :\n";
	cin >> no_of_nodes >> no_of_edges;
	for(i = 0; i < no_of_nodes; i ++){
		for(j = 0; j < no_of_nodes; j++){
			matrix[i][j] = -1;
		}
	}
	for(i = 0; i < no_of_edges; i ++){
		int s,d,w;
		cin >> s >> d >> w;
		matrix[s][d] = w;
		matrix[d][s] = w;
	}
	prims();
	int size = result.size();
	for(i = 0; i < size; i ++){
		cout << result.front().start << " " << result.front().end << " " << result.front().weight << endl;
		result.pop();
	}
	return 0;
}
