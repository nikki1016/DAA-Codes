#include<iostream>
#include<cstdio>
using namespace std;
#include<cstdlib>
#include<algorithm>
int c=0;
struct edge{
	int src,dest,wt;
};
struct graph{
	int v,e;
	struct edge *ed;
};
struct subset{
	int parent,rank;
};
struct graph *create(int v,int e) {
	struct graph *g=(struct graph *)malloc(sizeof(struct graph));
	g->v=v;
	g->e=e;
	g->ed=(struct edge *)malloc(e*sizeof(struct edge));
	return g;
}
int find(struct subset sub[],int i) {
	if(sub[i].parent!=i) {
		sub[i].parent=find(sub,sub[i].parent);
	}
	return sub[i].parent;
}
void unions(struct subset sub[],int x,int y) {
	int a=find(sub,x);
	int b=find(sub,y);
	if(sub[a].rank<sub[b].rank) {
		sub[a].parent=b;
	} else if(sub[a].rank>sub[b].rank) {
		sub[b].parent=a;
	} else {
		sub[b].parent=a;
		sub[a].rank++;
	}
}
int myC(const void *a,const void *b) {
	struct edge *a1=(struct edge *)a;
	struct edge *b1=(struct edge *)b;
	return a1->wt > b1->wt;
}
void kruskal(struct graph *g) {
	int ver=g->v;
	struct edge res[ver];
	int e=0;
	int i=0;
	qsort(g->ed,g->e,sizeof(g->ed[0]),myC);
	struct subset *sub=(struct subset *)malloc(ver*sizeof(struct subset));
	for(i=0;i<ver;i++) {
		sub[i].parent=i;
		sub[i].rank=0;
	}
	i=0;
	while(e<ver-1) {
		struct edge n=g->ed[i++];
		int x=find(sub,n.src);
		int y=find(sub,n.dest);
		if(x!=y) {
			res[e++]=n;
			unions(sub,x,y);
		}
	}
	printf("Following are the edges in the constructed MST\n");
    for (i = 0; i < e; ++i)
        printf("%d -- %d == %d\n", res[i].src, res[i].dest,
                                                   res[i].wt);
}
void addEdge(struct graph *g,int src,int dest,int wt) {
	g->ed[c].src=src;
	g->ed[c].dest=dest;
	g->ed[c].wt=wt;
	c++;
}
int main(){
	int n;
	scanf("%d",&n);
	int a,b,wt,v,e;
	scanf("%d%d",&v,&e);
	struct graph *g=create(v,e);
	while(n--) {
		scanf("%d%d%d",&a,&b,&wt);
		addEdge(g,a,b,wt);
	}
	kruskal(g);
}
