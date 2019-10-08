#include<stdlib.h>

void bubble(int a[],int n){
	int temp,i,j;
	for(i=0;i<n;++i)
		for(j=0;j<n-1-i;++j)
			if(a[j]>a[j+1]){
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
}

void main(){
	int i,a[10],n;
	printf("Enter the no. of elements:");
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=0;i<n;++i)
		scanf("%d",&a[i]);
	bubble(a,n);
	printf("Sorted Array: ");
	for(i=0;i<n;++i)
		printf("%d ",a[i]);
}
