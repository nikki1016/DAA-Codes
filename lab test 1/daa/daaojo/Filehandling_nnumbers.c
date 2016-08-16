#include <stdio.h>
#include <conio.h>
int a[100];
void quick(int a[],int low,int up);
int partition(int a[],int low,int up);
int main()
{
	FILE *f;
	int b,c,d;
	c=0;
	f = fopen("abc.txt","r");
	do {
		fscanf(f,"%d ",&d);
		a[c]=d;
		c++;
	}while(!feof(f));
	fclose(f);
	quick(a,0,c-1);
	b=0;
	f = fopen("ab.txt","w");
	while(b<c){
		fprintf(f,"%d ",a[b]);
		b++;
	}
	fclose(f);	
	return 0;
}
void quick(int a[],int low,int up)
{
	int pivloc;
	if(low >= up)
		return;
	pivloc = partition(a,low,up);
	quick(a,low,pivloc-1);
	quick(a,pivloc+1,up);
}
int partition(int a[],int low,int up)
{
	int temp,i,j,pivot;
	i = low+1;
	j = up;
	pivot = a[low];
	while(i <= j)
	{
		while((a[i] < pivot) &&(i < up))
			i++;
		while (a[j] > pivot)
			j--;
		if(i < j)
		{
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
		else
			i++;
	}
	a[low] = a[j];
	a[j] = pivot;
	return j;
}

