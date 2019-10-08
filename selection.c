#include<stdio.h>

void selection(int a[],int n){
	int i,j,pos,min,temp;
	for(i=0;i<n-1;++i){
		min=a[i];
		pos=i;
		for(j=i+1;j<n;++j)
			if(min>a[j]){
				min=a[j];
				pos=j;
			}
		if(pos!=i){
			temp=a[i];
			a[i]=a[pos];
			a[pos]=temp;
		}
	}
}

void main(){
	int i,a[10],n;
	printf("Enter the no. of elements:");
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=0;i<n;++i)
		scanf("%d",&a[i]);
	selection(a,n);
	printf("Sorted Array: ");
	for(i=0;i<n;++i)
		printf("%d ",a[i]);
}
