#include <stdio.h>
#include<stdlib.h>
struct node {
	float xc;
	float yc;
	struct node *next;
	struct node *pre;
};
void quicksort(float y[],float x[],float first,float last){
    int pivot,j,i;
    float temp,temp2;
if(first<last){
         pivot=first;
         i=first;
         j=last;
		while(i<j){
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j){
                 temp=x[i];
                 temp2=y[i];
                  x[i]=x[j];
                  y[i]=y[j];
                  x[j]=temp;
                  y[j]=temp2;
             } }
		 temp=x[pivot];
		 temp2=y[pivot];
         x[pivot]=x[j];//printf("x[%d]=%d ",pivot,x[pivot]);printf("\n");
         y[pivot]=y[j];//printf("y[%d]=%d",pivot,y[pivot]);printf("\n");
         x[j]=temp;
         y[j]=temp2;
         quicksort(y,x,first,j-1);
         quicksort(y,x,j+1,last);
}}
struct node *merge(struct node *lhull,struct node *rhull,int nl,int nr){
	int i,j,f1=0,f2=0,cl,cr; float x1,x2,x3,x4,y1,y2,y3,y4,xl,yl,xr,yr;
	struct node *p1=lhull,*p2=rhull,*ml,*mr,*l,*r,*ul,*ur,*ll,*lr;ml=p1;mr=p2;l=ml;r=mr;//printf("nl=%d nr=%d\n",nl,nr);
	if(nl==1&&nr==1){
		if(lhull->xc==rhull->xc&&lhull->yc==rhull->yc)return lhull;
		lhull->next=rhull;lhull->pre=rhull;
		rhull->next=lhull;rhull->pre=lhull;
		if(lhull->yc<rhull->yc)return lhull;
		else return rhull;
	}
	if(nl==2&&nr==2){
		if(lhull->xc==lhull->next->xc&&rhull->xc==rhull->next->xc&&lhull->xc==rhull->xc){
			struct node *ptr=lhull,*ptr2=lhull;//printf("***\n");
			if(ptr->yc>lhull->next->yc)ptr=lhull->next;
			if(ptr->yc>rhull->yc)ptr=rhull;
			if(ptr->yc>rhull->next->yc)ptr=rhull->next;
			
			if(ptr2->yc<lhull->next->yc)ptr2=lhull->next;
			if(ptr2->yc<rhull->yc)ptr2=rhull;
			if(ptr2->yc<rhull->next->yc)ptr2=rhull->next;
			ptr->next=ptr2;ptr2->next=ptr;
			ptr->pre=ptr2;ptr2->pre=ptr;//printf("..%d %d %d %d\n",ptr->xc,ptr->yc,ptr2->xc,ptr2->yc);
			return ptr;
		}
		if(lhull->yc==lhull->next->yc&&rhull->yc==rhull->next->yc&&lhull->yc==rhull->yc){
			struct node *ptr=lhull,*ptr2=lhull;//printf("***\n");
			if(ptr->xc>lhull->next->xc)ptr=lhull->next;
			if(ptr->xc>rhull->xc)ptr=rhull;
			if(ptr->xc>rhull->next->xc)ptr=rhull->next;
			
			if(ptr2->xc<lhull->next->xc)ptr2=lhull->next;
			if(ptr2->xc<rhull->xc)ptr2=rhull;
			if(ptr2->xc<rhull->next->xc)ptr2=rhull->next;
			ptr->next=ptr2;ptr2->next=ptr;
			ptr->pre=ptr2;ptr2->pre=ptr;
			return ptr2;
		}
	}
	p1=lhull;p2=rhull;
	do{
		if(p1->xc>ml->xc)ml=p1;
		else if(p1->xc==ml->xc){
			if(p1->yc>ml->yc)ml=p1;
		}
		p1=p1->next;
	}while(p1!=lhull);//printf("ml->=%d %d ",ml->xc,ml->yc);
	do{
		if(p2->xc<mr->xc)mr=p2;
		else if(p2->xc==mr->xc){
			if(p2->yc<mr->yc)mr=p2;
		}
		p2=p2->next;
	}while(p2!=rhull);//printf("mr->=%d %d\n",mr->xc,mr->yc);
	l=ml;r=mr;cl=nl-1;cr=nr-1;
	while(1){
		x1=ml->xc-mr->xc;  y1=ml->yc-mr->yc;    x2=ml->pre->xc-mr->xc;    y2=ml->pre->yc-mr->yc;
		x3=mr->xc-ml->xc;  y3=mr->yc-ml->yc;    x4=mr->next->xc-ml->xc;   y4=mr->next->yc-ml->yc;
	
		if(((x1*y2)-(x2*y1))>0&&((x3*y4)-(x4*y3))<0)break;
			 
		while(!(((x1*y2)-(x2*y1))>0)){
			if(((x1*y2)-(x2*y1))==0)cl--;
			ml=ml->pre;
			x1=ml->xc-mr->xc;        y1=ml->yc-mr->yc;
			x2=ml->pre->xc-mr->xc;   y2=ml->pre->yc-mr->yc;
			if(cl==0){f1=1;break;}
		}
		x3=mr->xc-ml->xc;   y3=mr->yc-ml->yc;   x4=mr->next->xc-ml->xc;  y4=mr->next->yc-ml->yc;
		
		while(!(((x3*y4)-(x4*y3))<0)){
				mr=mr->next;  
				if(((x3*y4)-(x4*y3))==0)cr--;
			x3=mr->xc-ml->xc;  y3=mr->yc-ml->yc;  x4=mr->next->xc-ml->xc;  y4=mr->next->yc-ml->yc;
			if(cr<=0){f2=1;break;}}
		
		if(f1==1||f2==1)break;
		 }
		 ul=ml;  ur=mr;  ml=l;   mr=r;  f1=0;  f2=0;  cl=nl-1;  cr=nr-1;
		 //printf("ul=%d %d ur=%d %d ml=%d %d mr=%d %d\n",ul->xc,ul->yc,ur->xc,ur->yc,ml->xc,ml->yc,mr->xc,mr->yc);
		 
	while(1){
			x1=ml->xc-mr->xc;  y1=ml->yc-mr->yc;  x2=ml->next->xc-mr->xc;  y2=ml->next->yc-mr->yc;
			x3=mr->xc-ml->xc;  y3=mr->yc-ml->yc;  x4=mr->pre->xc-ml->xc;   y4=mr->pre->yc-ml->yc;
			 	//cl=nl;cr=nr;
			if(((x1*y2)-(x2*y1))<0&&((x3*y4)-(x4*y3))>0)break;
			
		while(!(((x1*y2)-(x2*y1))<0)){
					ml=ml->next;
					if(((x1*y2)-(x2*y1))==0)cl--;
					x1=ml->xc-mr->xc;  y1=ml->yc-mr->yc;  x2=ml->next->xc-mr->xc;  y2=ml->next->yc-mr->yc;
					if(cl<=0){f1=1;break;}}
	//	printf("inside ll=%d %d mr=%d %d ",ml->xc,ml->yc,mr->xc,mr->yc);
	//	printf("x3=%d x4=%d y3=%d y4=%d ",x3,x4,y3,y4);
	//	printf("inside ll=%d %d mr=%d %d ",ml->xc,ml->yc,mr->xc,mr->yc);
		x3=mr->xc-ml->xc;  y3=mr->yc-ml->yc;  x4=mr->pre->xc-ml->xc;  y4=mr->pre->yc-ml->yc;
		while(!(((x3*y4)-(x4*y3))>0)){
			mr=mr->pre;
			if(((x3*y4)-(x4*y3))==0)cr--;
			x3=mr->xc-ml->xc;  y3=mr->yc-ml->yc;  x4=mr->pre->xc-ml->xc;  y4=mr->pre->yc-ml->yc;
			if(cr==0){f2=1;break;}}
	//	printf("cr=%d mr=%d %d\n",cr,mr->xc,mr->yc);
		if(f1==1||f2==1)break;
		 }
		 ll=ml; lr=mr;//printf("ll=%d %d lr=%d %d\n",ll->xc,ll->yc,lr->xc,lr->yc);
		 ul->next=ur; ur->pre=ul;
		 ll->pre=lr; lr->next=ll;
		 if(ll->yc>lr->yc)l=lr;
		 else l=ll;
		 return l;
}
struct node *chull(int n,float x[],float y[],int l,int u){
	if(l==u){
		struct node * h = (struct node *)malloc(sizeof(struct node));
		h->xc=x[l];h->yc=y[l];
		h->next=h;h->pre=h;
		return h;
	}
	if(l==u-1){
		struct node * h = (struct node *)malloc(sizeof(struct node));
		struct node * t = (struct node *)malloc(sizeof(struct node));
		if(x[l]==x[u]&&y[l]==y[u]){
			h->xc=x[l];h->yc=y[l];h->next=h;h->pre=h;return h;
		}
			h->xc=x[l];	h->yc=y[l];
			t->xc=x[u]; t->yc=y[u];
			h->next=t;  h->pre=t;  t->next=h;  t->pre=h;
			if(h->yc<t->yc){//printf("1h->xc=%d h->next->xc=%d\n",h->xc,h->next->xc);
						return h;}
			else if(h->yc>t->yc){//printf("2h->xc=%d h->next->xc=%d\n",h->xc,h->next->xc);
						return t;}
			if(h->xc<t->xc){//printf("3h->xc=%d h->next->xc=%d\n",h->xc,h->next->xc);
						return t;}
			//	printf("4h->xc=%d h->next->xc=%d\n",h->xc,h->next->xc);
			 return h;
	}
	if(l==u-2){//printf("inside 2nd case\n");
		int mi=l,j=0,i; 
		float my=y[l],dx[3],dy[3],x1=x[l],y1=y[l],x2=x[l+1],y2=y[l+1],x3=x[l+2],y3=y[l+2];
		
		if((y2-y1)*(x3-x2)==(y3-y2)*(x2-x1)){//printf("inside collinear\n");
					struct node *n1 = (struct node *)malloc(sizeof(struct node));
					struct node *n2 = (struct node *)malloc(sizeof(struct node));
		/*	if(x1==x2&&y1==y2&&x3==x2&&y3==y2){
				n1->xc=x[l];n1->yc=y[l];n1->next=n1;n1->pre=n1;
				return n1;
			}
			if(x1==x2&&y1==y2){//printf("inside\n");
					struct node *n1 = (struct node *)malloc(sizeof(struct node));
					struct node *n2 = (struct node *)malloc(sizeof(struct node));
					n1->xc=x1;n1->yc=y1;n2->xc=x3;n2->yc=y3;
					n1->next=n2;n2->next=n1;n2->pre=n1;n1->pre=n2;
					if(n1->yc<n2->yc)return n1;
					else return n2;
		}
		if(x2==x3&&y2==y3){
					struct node *n1 = (struct node *)malloc(sizeof(struct node));
					struct node *n2 = (struct node *)malloc(sizeof(struct node));
					n1->xc=x1;n1->yc=y2;n2->xc=x3;n2->yc=y3;
					n1->next=n2;n2->next=n1;n2->pre=n1;n1->pre=n2;
					if(n1->yc<n2->yc)return n1;
					else return n2;
		}*/
			if(x2-x1==0){
			float min=y[l];
			int j=l;
					n1->xc=x[l];  n2->xc=x[l];
					for(i=l+1;i<=u;i++){
						if(y[i]<min){min=y[i];j=i;}}
					n1->yc=min; min=-100000;
					for(i=l;i<=u;i++){
						if(y[i]>min&&i!=j)min=y[i];}
					n2->yc=min; n1->next=n2; n2->pre=n1; n1->pre=n2; n2->next=n1;
					return n1;
			}
			if(y2-y1==0){
				n1->xc=x[u]; n1->yc=y[u]; n2->xc=x[l]; n2->yc=y[l];
				n1->next=n2; n2->pre=n1;  n1->pre=n2;  n2->next=n1;
				return n1;
			}
			n1->xc=x[u]; n1->yc=y[u]; n2->xc=x[l]; n2->yc=y[l];
			n1->next=n2; n2->pre=n1;  n1->pre=n2;  n2->next=n1;
			if((float)(y2-y1)/(float)(x2-x1)<0)return n1;
			else return n2; 
			
		}
		//printf("y[mi]=%d x[mi]=%d ",y[mi],x[mi]);
	//	if(y[mi]==y[mi+1]&&x[mi]<x[mi+1]){mi=l+1;my=y[l+1];}
	//0	else if(y[mi]==y[mi+2]&&x[mi]<x[mi+2]){mi=l+1;my=y[l+1];}
		//printf("y[mi+1]=%d x[mi]=%d ",y[mi+1],x[mi+1]);
		
		for(i=l;i<=u;i++){
			if(y[i]<my){
				my=y[i];mi=i;
			}
		}
		j=0;
		
		for(i=l;i<=u;i++){
			if(i!=mi){
				dx[j]=x[i];
				dy[j]=y[i];j++;
			}
		}
		struct node *n1 = (struct node *)malloc(sizeof(struct node));
		n1->xc=x[mi];n1->yc=y[mi];
		struct node *n2 = (struct node *)malloc(sizeof(struct node));
		n2->xc=dx[0];n2->yc=dy[0];
		struct node *n3 = (struct node *)malloc(sizeof(struct node));n3->xc=dx[1];n3->yc=dy[1];
		//printf("dx[0]=%d dy[0]=%d dx[1]=%d dy[1]=%d\n",dx[0],dy[0],dx[1],dy[1]);
	//	printf("--n1->xc %d n1->yc %d n2->xc %d n2->yc %d n3->xc %d n3->yc %d\n",n1->xc,n1->yc,n2->xc,n2->yc,n3->xc,n3->yc);
		if((dy[0]-y[mi])*(dx[1]-x[mi])>(dy[1]-y[mi])*(dx[0]-x[mi])){//printf("1\n");
			n1->next=n2;
			n2->pre=n1;
			n2->next=n3; n3->pre=n2;
			n3->next=n1; n1->pre=n3;//printf("c1--");
		//	printf("n1->xc %d n1->yc %d n2->xc %d n2->yc %d n3->xc %d n3->yc %d\n",n1->xc,n1->yc,n2->xc,n2->yc,n3->xc,n3->yc);
			if(n1->next->yc==n1->yc&&n1->next->xc>n1->xc)return n1->next;
			else if(n1->pre->yc==n1->yc&&n1->pre->xc>n1->xc)return n1->pre;
			
			return n1;
		}
		else if((dy[0]-y[mi])*(dx[1]-x[mi])<(dy[1]-y[mi])*(dx[0]-x[mi])){
			n1->next=n3;
			n3->pre=n1;
			n3->next=n2;n2->pre=n3;
			n2->next=n1;n1->pre=n2;//printf("c2--");
			if(n1->next->yc==n1->yc&&n1->next->xc>n1->xc)return n1->next;
			else if(n1->pre->yc==n1->yc&&n1->pre->xc>n1->xc)return n1->pre;
			return n1;
		}
	}
int nl=0,nr=0;//printf("l=%d u1=%d u2=%d u3=%d\n",l,(l+u)/2,((l+u)/2)+1,u);
//if(c==0){
struct node *lhull=chull(n,x,y,l,(l+u)/2),*ptr;//c++;
//}else return;
ptr=lhull;
//printf("lhull- ");
do{//printf("%f %f+",ptr->xc,ptr->yc);
	ptr=ptr->next;nl++;
	}while(ptr!=lhull);//printf("\n");
//	printf("((l+u)/2)+1=%d u=%d\n",((l+u)/2)+1,u);
struct node *rhull=chull(n,x,y,((l+u)/2)+1,u);
ptr=rhull;
//printf("rhull- ");
do{//printf("%f %f= ",ptr->xc,ptr->yc);
ptr=ptr->next;nr++;
	}while(ptr!=rhull);//printf("\nnl=%d nr=%d\n",nl,nr);
struct node *fhull=merge(lhull,rhull,nl,nr);
ptr=fhull;
//printf("fhull-- ");
/*do{printf("%f %f** ",ptr->xc,ptr->yc);
ptr=ptr->next;
	}while(ptr!=fhull);//printf("\n");*/
return fhull;
}
int main(void) {
	int n,i,j,k,l,mi,mai,in,fi;
	struct node *head=NULL,*ptr;
	scanf("%d",&n);
	float x[n],y[n],a[n],b[n];
	for(i=0;i<n;i++){
		scanf("%f%f",&x[i],&y[i]);
	}
	
	quicksort(y,x,0,n-1);//printf("j=%d\n",j);
/*	for(i=0;i<n;i++){
		printf("++%f %f\n",x[i],y[i]);
	}*/
	in=0;fi=0;
		while(in<n){
		i=in;
			while(x[i]==x[i+1]&&i<n-1)i++;
			fi=i;
			if(in<fi&&in>=0&&fi<n){quicksort(x,y,in,fi);}
			in=i+1;
		}
	j=0;i=0;
	while(i<n){
		a[j]=x[i];
		b[j]=y[i];
		while(x[i]==x[i+1]&&y[i]==y[i+1]&&i+1<n)i++;
		i++;j++;
	}
	
/*	for(i=0;i<j;i++){
		printf("%f %f\n",a[i],b[i]);
	}*/
	if(j>0)ptr=head=chull(j,a,b,0,j-1);
//	printf("head->xc=%d head->pre->xc=%d head->pre->pre->xc=%d ",head->xc,head->pre->xc,head->pre->pre->xc);
	int c=0;
	if(ptr!=NULL){
	do{
		printf("%f %f\n",ptr->xc,ptr->yc);
		ptr=ptr->next;c++;
	//	if(c==n+1)break;
	}while(ptr!=head);}
	return 0;
}

