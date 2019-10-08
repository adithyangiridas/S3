#include<stdio.h>

void insertion(int a[],int n){
	int i,key,j;
	for(i=1;i<n;++i){
		key=a[i];
		j=i-1;
		while(j>=0 && key<a[j]){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=key;
	}
}

void main(){
	int i,a[10],n;
	printf("Enter the no. of elements:");
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=0;i<n;++i)
		scanf("%d",&a[i]);
	insertion(a,n);
	printf("Sorted Array: ");
	for(i=0;i<n;++i)
		printf("%d ",a[i]);
}
	
