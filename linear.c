#include<stdio.h>

int linear(int a[],int size,int x){
	for(int i=0;i<size;++i)
		if(a[i]==x)
			return i;
	return 10;
}

int binary(int a[],int size,int x){
	int l,u,mid;
	l=0;
	u=size-1;
	while(l<=u){
		mid=(l+u)/2;
		if(x==a[mid])
			return mid;
		else if(x>a[mid])
			l=mid+1;
		else
			u=mid-1;
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
	int x,c,a[10],size=10;
	for(int i=0;i<size;++i){
		printf("Enter element:");
		scanf("%d",&a[i]);
	}
	printf("Enter the number to be searched:");
	scanf("%d",&x);
	printf("				MENU\n1 - Linear Search\n2 - Binary Search\nEnter the choice:");
	scanf("%d",&c);
	if(c==1)
		x=linear(a,size,x);
	else if(c==2){
		sort(a,size);
		x=binary(a,size,x);
	}
	else
		printf("Invalid choice..");
	if(x==10)
		printf("Element not present...\n");
	else 
		printf("Element present at position %d..\n",x);
}


