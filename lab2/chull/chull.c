#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include<time.h>
#define INF 1000000

struct point {
    float x;
    float y;
    int v;
};

struct data {
    struct point p;
    struct data *next;
    struct data *prev;
};

int cmp (const void *c, const void  *b) {
    struct point *p1 = (struct point *)c;
    struct point *p2 = (struct point *)b;
    if(p1 -> x == p2->x)
    {	
    	if(p1 -> y == p2 ->y)
    	return (p1->v - p2->v);
		return (p1->y - p2->y) ; 
	}
    return (p1 -> x - p2-> x);
}

float slope(struct point a, struct point b) {
    if(a.x == b.x) {
        return INF;
    }
    else {
        float v = (a.y - b.y)/(a.x - b.x);
        return v;
    }
}

int test (struct data * left, struct data *right, struct data *templ, struct data *tempr,int sign) {
    int flag =1;
    float s = slope(tempr->p, templ->p);
    //if(s==INF)
   // return 0;
 //   printf("%f %f %f %f %f\n",templ->p.x,templ->p.y,tempr->p.x,tempr->p.y,s);
    int y1 = templ->p.y;
    int x1 = templ->p.x;
        int y = templ->next->p.y;
        int x = templ->next->p.x;
        float ans = y - y1 - (x-x1)*s;
    //    printf("x=%d y=%d ans=%d\n",x,y,ans);
        ans = ans*sign;
        if(ans<0) {
            flag = 0;
            return flag;
        }
        y=templ->prev->p.y;
        x=templ->prev->p.x;
        ans = y - y1 - (x - x1) * s;
      //  printf("xprev=%d y=%d ans=%d\n",x,y,ans);
        ans = ans * sign;
        if(ans<0) {
        	flag = 0;
        	return flag;
        }
        y = tempr->next->p.y;
        x = tempr->next->p.x;
        ans = y - y1 - (x-x1)*s;
       // printf("xr=%d y=%d ans=%d\n",x,y,ans);
        ans = ans*sign;
        if(ans<0) {
            flag = 0;
            return flag;
        }
        y = tempr->prev->p.y;
        x = tempr->prev->p.x;
        ans = y - y1 - (x-x1)*s;
   //     printf("xprevr=%d y=%d ans=%d\n",x,y,ans);
        ans = ans*sign;
        if(ans<0) {
            flag = 0;
            return flag;
        }

    return flag;
}

struct data *merge(struct data *left, struct data *right) {
    struct data *templ = left;
    struct data *tempr = right;
    struct data *lowleft,*highleft,*lowright,*highright;
    float hy = -1*INF;
    float ly = INF;
    do {
        if(templ->p.y < ly) {
            ly = templ->p.y;
            lowleft = templ;
        }
        if(templ->p.y == ly && templ->p.x > lowleft->p.x)
        {
        	lowleft=templ;
        }
        if(templ->p.y > hy) {
            hy = templ->p.y;
            highleft = templ;
        }
        if(templ->p.y == hy && templ->p.x < highleft->p.x)
        {
        	highleft=templ;
        }
        templ = templ->next;
    }
    while(templ!=left);
  //  printf("lowleft %f %f\n",lowleft->p.x,lowleft->p.y);
  //  printf("highleft %f %f\n",highleft->p.x,highleft->p.y);
    ly = INF;
    hy = -1 * INF;
    do {
        if(tempr->p.y < ly) {
            ly = tempr->p.y;
            lowright = tempr;
        }
        if(tempr->p.y == ly && tempr->p.x > lowright->p.x)
        {
        	lowright=tempr;
        }
        if(tempr->p.y > hy) {
            hy = tempr->p.y;
            highright = tempr;
        }
        if(tempr->p.y == hy && tempr->p.x > highright->p.x)
        {
        	highright=tempr;
        }
        tempr = tempr->next;
    }
    while(tempr!=right);
   // printf("lowright %f %f\n",lowright->p.x,lowright->p.y);
   // printf("highright %f %f\n",highright->p.x,highright->p.y);
    templ = lowleft;
    tempr = lowright;
    do {
        int flag = 0;
        tempr= lowright;
        do {
            if(test(left,right,templ,tempr,1)) {
                flag = 1;
                break;
            }
            tempr = tempr->next;
        }
        while(tempr!=lowright);
        if(flag) break;
        templ = templ->next;
    }
    while(templ!=lowleft);
   // printf("lowleft1 %f %f\n",templ->p.x,templ->p.y);
   // printf("lowright1 %f %f\n",tempr->p.x,tempr->p.y);
    while(slope(templ->p,tempr->p)==INF&&tempr!=highright)
    {
    	tempr=tempr->next;
    }
  //  printf("lowleft2 %f %f\n",templ->p.x,templ->p.y);
    //printf("lowright2 %f %f\n",tempr->p.x,tempr->p.y);
    while(slope(templ->p,tempr->p)==slope(templ->p,tempr->next->p)&&tempr!=highright&&tempr->next->p.y>0)
    {
    	tempr=tempr->next;
    }
   while(slope(templ->p,tempr->p)==slope(templ->next->p,tempr->p)&&templ->next->p.x<templ->p.x&&templ->next->p.y==templ->p.y)
    {
    	templ=templ->next;
    }
    lowleft = templ;
    lowright = tempr;
//	printf("lowleft3 %f %f\n",lowleft->p.x,lowleft->p.y);
  //  printf("lowright3 %f %f\n",lowright->p.x,lowright->p.y);
    templ = highleft;
    tempr = highright;
    do {
        int flag = 0;
        tempr= highright;
        do {
            if(test(left,right,templ,tempr,-1)) {
                flag = 1;
                break;
            }
            tempr = tempr->next;
        }
        while(tempr!=highright);
        if(flag) break;
        templ = templ->next;
    }
    while(templ!=highleft);
    while(slope(templ->p,tempr->p)==INF&&templ!=lowleft)
    {
    	templ=templ->next;
    }    
	while(slope(templ->p,tempr->p)==slope(templ->next->p,tempr->p)&&templ!=lowleft)
    {
    	templ=templ->next;
    }
    while(slope(templ->p,tempr->p)==slope(templ->p,tempr->next->p)&&tempr->next->p.x>tempr->p.x&&tempr->next->p.y==tempr->p.y)
    {
    	tempr=tempr->next;
    }
    highleft = templ;
    highright = tempr;
//	printf("highleft2 %f %f\n",highleft->p.x,highleft->p.y);
  //  printf("highright2 %f %f\n",highright->p.x,highright->p.y);
    highleft->next = highright;
    lowright->next = lowleft;
    highright->prev = highleft;
    lowleft->prev= lowright;
   // return lowleft;
   return highleft;
}
struct data * convex_hull (struct point a[], int l, int r) {
//	printf("l=%d r=%d %f %f %d %f %f %d\n",l,r,a[l].x,a[l].y,a[l].v,a[r].x,a[r].y,a[r].v);
    if(l==r) {
        struct data *h = (struct data *)malloc(sizeof(struct data));
        h->p = a[l];
        h->next = h;
        h->prev = h;
        return h;
    }
    else if(l == r-1) {
    	if(a[l].x!=a[r].x||a[l].y!=a[r].y)
    	{
        struct data *h = (struct data *)malloc(sizeof(struct data));
        h->p = a[l];
        struct data *h1 = (struct data *)malloc(sizeof(struct data));
        h1->p = a[r];
        h -> next = h1;
        h1->next = h;
        h->prev = h1;
        h1 -> prev = h;
        return h;
    	}
    	else
    	{
    		struct data *h = (struct data *)malloc(sizeof(struct data));
        h->p = a[l];
        h->next = h;
        h->prev = h;
  //      printf("%f %f %d %d %d\n",h->p.x,h->p.y,h->p.v,a[l].v,a[r].v);
        return h;
      	}
    }
    else if(l == r-2) {
        int i;
        struct point temp[3];
        for (i=0;i<3;i++) {
            temp[i]=a[l+i];
        }
        if(slope(a[l],a[l+1])<slope(a[l],a[l+2])) {
            struct point t = temp[1];
            temp[1] = temp[2];
            temp[2] =t;
        }
        else if(slope(a[l],a[l+1])==slope(a[l],a[l+2]))
        {
        	struct data *h = (struct data *)malloc(sizeof(struct data));
        	h->p = temp[0];
        	struct data *h1 = (struct data *)malloc(sizeof(struct data));
        	h1->p = temp[2];
        	 h -> next = h1;
        	h1->next = h;
        	h->prev = h1;
        	h1 -> prev = h;
        	return h;
        }
        else if(a[l].x==a[l+1].x&&a[l].x==a[l+2].x&&a[l].y==a[l+1].y&&a[l].y==a[l+2].y)
        {
        	struct data *h = (struct data *)malloc(sizeof(struct data));
        h->p = a[l];
        h->next = h;
        h->prev = h;
        return h;
        }
        else if(a[l].x==a[l+1].x&&a[l].y==a[l+1].y)
        {
        	struct data *h = (struct data *)malloc(sizeof(struct data));
        	h->p = temp[0];
        	struct data *h1 = (struct data *)malloc(sizeof(struct data));
        	h1->p = temp[2];
        	 h -> next = h1;
        	h1->next = h;
        	h->prev = h1;
        	h1 -> prev = h;
        	return h;
        }
        struct data *h = (struct data *)malloc(sizeof(struct data));
        h->p = temp[0];
        struct data *h1 = (struct data *)malloc(sizeof(struct data));
        h1->p = temp[1];
        struct data *h2 = (struct data *)malloc(sizeof(struct data));
        h2->p = temp[2];
        h1->next = h2;
        h1->prev = h;
        h->next = h1;
        h->prev = h2;
        h2->next = h;
        h2->prev = h1;
        return h;
    }
    else {
        int mid = (l+r)/2;
     //   printf("mid=%d\n",mid);
        struct data *left = convex_hull(a,l,mid);
        struct data *right = convex_hull(a,mid+1,r);
        
        struct data *temp = left;
        printf("Left hull is : \n");
	    do {
    		printf("%.0f %.0f\n",temp->p.x,temp->p.y);
    		temp = temp->next;
    	}while(temp!=left);
    	
    	printf("Right hull is : \n");
    	temp = right;
    	 do {
    		printf("%.0f %.0f\n",temp->p.x,temp->p.y);
    		temp = temp->next;
    	}while(temp!=right);
    	
    	   struct data *answer = merge(left,right);
       // struct data *temp=answer;
     //   do
      //  {
      //  	printf("%f %f\n",temp->p.x,temp->p.y);
      //  	temp=temp->next;
      //  }
      //  while(temp!=answer);
        return answer;
    }
}
double dist(struct data *temp1,struct data *temp2)
{
	return sqrt(pow((temp1->p.x-temp2->p.x),2)+pow((temp1->p.y-temp2->p.y),2));
}
int main()
{	int t;
scanf("%d",&t);
while(t--){

    int j,n,i,t,di;
    double dis;
    	scanf("%d",&n);
    	struct point a[100009];
    	for (i=0;i<n;i++) {
    		scanf("%f %f",&a[i].x,&a[i].y);
    		a[i].v=i+1;
    	}
    //	for (i=0;i<n;i++) {
    //		printf("%f %f %d\n",a[i].x,a[i].y,a[i].v);
    //	}
   		qsort(a,n,sizeof(struct point),cmp);
   //		for (i=0;i<n;i++) {
   // 		printf("%f %f %d\n",a[i].x,a[i].y,a[i].v);
  //  	}
    struct data *temp,*head = convex_hull(a,0,n-1);
   // end=clock();
   // time_spent=(double) (end-beg);//CLOCKS_PER_SEC;
//	fprintf(fp,"%d %lf\n",n,time_spent);
	temp = head;
    do {
    	if(temp->p.x == temp->next->p.x && temp->p.y == temp->next->p.y) {
    	if(temp->p.v<temp->next->p.v){
		temp->next=temp->next->next;
    	temp->next->prev=temp;
    	}
    	else
    	{
    		temp->prev->next=temp->next;
    		temp->next->prev=temp->prev;
    	}
    }
        temp = temp->next;
    }
    while(temp!=head);
    int h[100009];
    i=0;
    temp = head;
    dis=0;
    printf("HULL\n");
    do {
    	printf("%.0f %.0f\n",temp->p.x,temp->p.y);
    	temp = temp->next;
    }while(temp!=head);
}
/*    do {
    	h[i++]=temp->p.v;
        temp = temp->prev;
        dis+=dist(temp->next,temp);
    }
    while(temp!=head);
    di=(int)dis;
    printf("%d\n",di);*/
//}
//	fclose(fp);
//fclose(fp1);
//fclose(fp2);
    return 0;
}
