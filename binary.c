
#include<stdlib.h>

int binary(int a[],int l,int u,int x){
	int mid;
	while(l<=u){
		mid=(l+u)/2;
		if(x==a[mid])
			return mid;
		else if(x>a[mid])
			return binary(a,mid+1,u,x);
		else
			return binary(a,l,mid-1,x);
	}
	return 10;
}

void sort(int a[],int size){
	int temp,i,j;
	for(i=0;i<size;++i)
		for(j=0;j<size-1-i;++j){
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	printf("Array after sorting:");
	for(i=0;i<size;++i)
		printf("%d ",a[i]);
}

void main(){
	int x,a[10],size=10;
	for(int i=0;i<size;++i){
		printf("Enter element:");
		scanf("%d",&a[i]);
	}
	printf("Enter the number to be searched:");
	scanf("%d",&x);
	sort(a,size);
	x=binary(a,0,size-1,x);
	if(x==10)
		printf("Element not present...\n");
	else 
		printf("Element present at position %d..\n",x);
}


