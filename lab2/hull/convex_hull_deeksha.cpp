#include <stdio.h>
#include<stdlib.h>
int c=0;
struct node {
	int xc;
	int yc;
	struct node *next;
	struct node *pre;
};
void quicksort(int y[],int x[],int first,int last){
    int pivot,j,temp,temp2,i;
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
struct node *merge(struct node *lhull,struct node *rhull,int nl,int nr){c++;
	int i,j,cx=0,cy=0,cxr=0,cyr=0,x1,x2,x3,x4,y1,y2,y3,y4,xl,yl,xr,yr,cl=nl,cr=nr;
	struct node *p1=lhull,*p2=rhull,*ml,*mr,*l,*r,*ul,*ur,*ll,*lr,*minh,*maxh;ml=p1;mr=p2;l=ml;r=mr;cl--;cr--;
	if(nl==2&&nr==2){
	while(cl--){
		if(p1->xc==p1->next->xc)cx++;
		 if(p1->yc==p1->next->yc)cy++;//else break;
	}
	while(cr--){
		if(p2->xc==p2->next->xc)cxr++;
		 if(p2->yc==p2->next->yc)cyr++;//else break;
	}
	if(cx==nl-1&&cxr==nr-1&&lhull->xc==rhull->xc){
		p1=lhull;minh=lhull;maxh=lhull;
		do{
		if(p1->yc<=minh->yc)minh=p1;
		if(p1->yc>=maxh->yc)maxh=p1;
		p1=p1->next;
	}while(p1!=lhull);p1=rhull;
	do{
		if(p1->yc<=minh->yc)minh=p1;
		if(p1->yc>=maxh->yc)maxh=p1;
		p1=p1->next;
	}while(p1!=rhull);
		minh->next=maxh;maxh->pre=minh;minh->pre=maxh;maxh->next=minh;
		return minh;
	}
	if(cy==nl-1&&cyr==nr-1&&lhull->yc==rhull->yc){
		p1=lhull;minh=lhull;maxh=lhull;
		do{
		if(p1->xc<=minh->xc)minh=p1;
		if(p1->xc>=maxh->xc)maxh=p1;
		p1=p1->next;
	}while(p1!=lhull);p1=rhull;
	do{
		if(p1->xc<=minh->xc)minh=p1;
		if(p1->xc>=maxh->xc)maxh=p1;
		p1=p1->next;
	}while(p1!=rhull);
		minh->next=maxh;maxh->pre=minh;minh->pre=maxh;maxh->next=minh;
		return maxh;
	}
	}
	p1=lhull;p2=rhull;
	do{
		if(p1->xc>ml->xc)ml=p1;
		else if(p1->xc==ml->xc){
			if(p1->yc<ml->yc)ml=p1;
		}
		p1=p1->next;
	}while(p1!=lhull);//printf("ml->=%d %d ",ml->xc,ml->yc);
	do{
		if(p2->xc<mr->xc)mr=p2;
		p2=p2->next;
	}while(p2!=rhull);//printf("mr->=%d %d\n",mr->xc,mr->yc);
	l=ml;r=mr;
	while(1){x1=ml->xc-mr->xc;y1=ml->yc-mr->yc;x2=ml->pre->xc-mr->xc;y2=ml->pre->yc-mr->yc;cl=nl;cr=nr;
	x3=mr->xc-ml->xc;y3=mr->yc-ml->yc;x4=mr->next->xc-ml->xc;y4=mr->next->yc-ml->yc;
	if(((x1*y2)-(x2*y1))>0&&((x3*y4)-(x4*y3))<0)break;
			 
		while(!(((x1*y2)-(x2*y1))>0)){ml=ml->pre;
		x1=ml->xc-mr->xc;y1=ml->yc-mr->yc;x2=ml->pre->xc-mr->xc;y2=ml->pre->yc-mr->yc;
		cl--;/*if(cl==0)break;*/}
		while(!(((x3*y4)-(x4*y3))<0)){mr=mr->next;cr--;
		x3=mr->xc-ml->xc;y3=mr->yc-ml->yc;x4=mr->next->xc-ml->xc;y4=mr->next->yc-ml->yc;/*if(cr==0)break;*/}
		
		 }ul=ml;ur=mr;ml=l;mr=r;/*printf("ul=%d %d ur=%d %d ml=%d mr=%d\n",ul->xc,ul->yc,ur->xc,ur->yc,ml->xc,mr->xc);*/
		 while(1){x1=ml->xc-mr->xc;y1=ml->yc-mr->yc;x2=ml->next->xc-mr->xc;y2=ml->next->yc-mr->yc;
			 	x3=mr->xc-ml->xc;y3=mr->yc-ml->yc;x4=mr->pre->xc-ml->xc;y4=mr->pre->yc-ml->yc;
			 	cl=nl;cr=nr;
			 		if(((x1*y2)-(x2*y1))<0&&((x3*y4)-(x4*y3))>0)break;
		while(!(((x1*y2)-(x2*y1))<0)){ml=ml->next;cl--;
		x1=ml->xc-mr->xc;y1=ml->yc-mr->yc;x2=ml->next->xc-mr->xc;y2=ml->next->yc-mr->yc;/*if(cl==1)break;*/}
		while(!(((x3*y4)-(x4*y3))>0)){mr=mr->pre;cr--;
		x3=mr->xc-ml->xc;y3=mr->yc-ml->yc;x4=mr->pre->xc-ml->xc;y4=mr->pre->yc-ml->yc;/*if(cr==1)break;*/}
		 }ll=ml;lr=mr;//printf("ll=%d %d lr=%d %d\n",ll->xc,ll->yc,lr->xc,lr->yc);
		 ul->next=ur;ur->pre=ul;
		 ll->pre=lr;lr->next=ll;
		 if(ll->yc>lr->yc)l=lr;else l=ll;
		 return l;
	
}
struct node *chull(int n,int x[],int y[],int l,int u){
	if(l==u-1){
		struct node * h = (struct node *)malloc(sizeof(struct node));
		struct node * t = (struct node *)malloc(sizeof(struct node));
			h->xc=x[l];	h->yc=y[l];
			t->xc=x[u];t->yc=y[u];
			h->next=t;h->pre=t;t->next=h;t->pre=h;
			if(h->yc<t->yc){//printf("1h->xc=%d h->next->xc=%d\n",h->xc,h->next->xc);
			return h;}
				else if(h->yc>t->yc){//printf("2h->xc=%d h->next->xc=%d\n",h->xc,h->next->xc);
				return t;}
				if(h->xc<t->xc){//printf("3h->xc=%d h->next->xc=%d\n",h->xc,h->next->xc);
				return t;}
			//	printf("4h->xc=%d h->next->xc=%d\n",h->xc,h->next->xc);
			 return h;
	}
	if(l==u-2){
		int mi=l,my=y[l],i,dx[3],dy[3],j=0,t,x1=x[l],y1=y[l],x2=x[l+1],y2=y[l+1],x3=x[l+2],y3=x[l+2];
		if((y2-y1)*(x3-x2)==(y3-y2)*(x2-x1)){
			struct node *n1 = (struct node *)malloc(sizeof(struct node));
					struct node *n2 = (struct node *)malloc(sizeof(struct node));
			if(x2-x1==0){int min=y[l],j=l;
					n1->xc=x[l];n2->xc=x[l];
					for(i=l+1;i<=u;i++){if(y[i]<min){min=y[i];j=i;}}
					n1->yc=min;min=-10000;for(i=l;i<=u;i++){if(y[i]>min&&i!=j)min=y[i];}
					n2->yc=min;n1->next=n2;n2->pre=n1;n1->pre=n2;n2->next=n1;return n1;
			}
			if(y2-y1==0){
				n1->xc=x[u];n1->yc=y[u];n2->xc=x[l];n2->yc=y[l];
				n1->next=n2;n2->pre=n1;n1->pre=n2;n2->next=n1;return n1;
			}
			n1->xc=x[u];n1->yc=y[u];n2->xc=x[l];n2->yc=y[l];
			if((float)(y2-y1)/(float)(x2-x1)<0)return n2;else return n1; 
			
		}
		//printf("y[mi]=%d x[mi]=%d ",y[mi],x[mi]);
	//	if(y[mi]==y[mi+1]&&x[mi]<x[mi+1]){mi=l+1;my=y[l+1];}
	//0	else if(y[mi]==y[mi+2]&&x[mi]<x[mi+2]){mi=l+1;my=y[l+1];}
		//printf("y[mi+1]=%d x[mi]=%d ",y[mi+1],x[mi+1]);
		for(i=l;i<=u;i++){
			if(y[i]<my){
				my=y[i];mi=i;
			}
		}j=0;
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
			n2->next=n3;n3->pre=n2;
			n3->next=n1;n1->pre=n3;//printf("c1--");
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
		else{//printf("--3**\n");
			if(dy[0]>dy[1]){
				int t=dy[0];
				dy[0]=dy[1];dy[1]=t;t=dx[0];dx[0]=dx[1];dx[1]=t;}
				n2->xc=dx[0];n2->yc=dy[0];n3->xc=dx[1];n3->yc=dy[1];
				n1->next=n2;
			n2->pre=n1;
			n2->next=n3;n3->pre=n2;
			n3->next=n1;n1->pre=n3;
			//printf("c3--\n");printf("##n1->xc %d n1->yc %d n2->xc %d n2->yc %d n3->xc %d n3->yc %d\n",n1->xc,n1->yc,n2->xc,n2->yc,n3->xc,n3->yc);
			if(n1->next->yc==n1->yc&&n1->next->xc>n1->xc){return n1->next;}
			else if(n1->pre->yc==n1->yc&&n1->pre->xc>n1->xc){return n1->pre;}
		//	printf("n1->xc %d n1->yc %d n2->xc %d n2->yc %d n3->xc %d n3->yc %d\n",n1->xc,n1->yc,n2->xc,n2->yc,n3->xc,n3->yc);
			return n1;
				
			}
		}
int nl=0,nr=0;//printf("l=%d u1=%d u2=%d u3=%d\n",l,(l+u)/2,((l+u)/2)+1,u);
//if(c==0){
struct node *lhull=chull(n,x,y,l,(l+u)/2),*ptr;c++;
//}else return;
ptr=lhull;
//printf("lhull-");
do{//printf("%d %d+",ptr->xc,ptr->yc);
	ptr=ptr->next;nl++;
	}while(ptr!=lhull);//printf("\n");
struct node *rhull=chull(n,x,y,((l+u)/2)+1,u);ptr=rhull;
//printf("rhull-");
do{//printf("%d %d= ",ptr->xc,ptr->yc);
ptr=ptr->next;nr++;
	}while(ptr!=rhull);//printf("\nnl=%d nr=%d\n",nl,nr);
struct node *fhull=merge(lhull,rhull,nl,nr);ptr=fhull;
//printf("fhull-");
do{//printf("%d %d** ",ptr->xc,ptr->yc);
ptr=ptr->next;
	}while(ptr!=fhull);//printf("\n");
return fhull;return lhull;
}
int main(void) {
	int n,i,j,k,l,mi,mai;
	struct node *head=NULL,*ptr;
	scanf("%d",&n);
	int x[n],y[n],a[n],b[n];
	for(i=0;i<n;i++){
		scanf("%d%d",&x[i],&y[i]);a[i]=x[i];b[i]=y[i];
	}
	
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			for(k=j+1;k<n;k++){
				if(i!=j&&j!=k&&x[i]!=-99999&&x[j]!=-99999&&x[k]!=-99999){
					if((x[k]-x[i])*(y[j]-y[i])==(y[k]-y[i])*(x[j]-x[i])){//printf("i=%d j=%d k=%d\n",i,j,k);
						if(y[i]==y[j]==y[k]){
							mi=i;mai=i;
							if(x[mi]>x[j])mi=j;if(x[mai]<x[j])mai=j;
							if(x[mi]>x[k])mi=k;if(x[mai]<x[k])mai=k;
							if(i!=mi&&i!=mai){x[i]=-99999;y[i]=-99999;}
							else if(j!=mi&&j!=mai){x[j]=-99999;y[j]=-99999;}
							else if(k!=mi&&k!=mai){x[k]=-99999;y[k]=-99999;}
						}
						else if(x[i]==x[j]==x[k]){
							mi=i;mai=i;
							if(y[mi]>y[j])mi=j;if(y[mai]<y[j])mai=j;
							if(y[mi]>y[k])mi=k;if(y[mai]<y[k])mai=k;
							if(i!=mi&&i!=mai){x[i]=-99999;y[i]=-99999;}
							else if(j!=mi&&j!=mai){x[j]=-99999;y[j]=-99999;}
							else if(k!=mi&&k!=mai){x[k]=-99999;y[k]=-99999;}
						}
						else {mi=i;mai=i;
							if(x[mi]>x[j])mi=j;if(x[mai]<x[j])mai=j;
							if(x[mi]>x[k])mi=k;if(x[mai]<x[k])mai=k;
							if(i!=mi&&i!=mai){x[i]=-99999;y[i]=-99999;}
							else if(j!=mi&&j!=mai){x[j]=-99999;y[j]=-99999;}
							else if(k!=mi&&k!=mai){x[k]=-99999;y[k]=-99999;}
							
						}
					}
				}
			}
		}
	}j=0;
	for(i=0;i<n;i++){
		if(x[i]!=-99999&&y[i]!=-99999){a[j]=x[i];b[j]=y[i];j++;}
	}//for(i=0;i<n;i++)	printf("$$%d %d\n",x[i],y[i]);
	quicksort(b,a,0,j-1);//printf("j=%d\n",j);
//	for(i=0;i<j;i++){
//		printf("%d %d\n",a[i],b[i]);
//	}
	if(n>0)ptr=head=chull(j,a,b,0,j-1);
//	printf("head->xc=%d head->pre->xc=%d head->pre->pre->xc=%d ",head->xc,head->pre->xc,head->pre->pre->xc);
	int c=0;
	if(ptr!=NULL){
	do{
		printf("%d %d\n",ptr->xc,ptr->yc);
		ptr=ptr->next;c++;
	//	if(c==n+1)break;
	}while(ptr!=head);}
	return 0;
}


