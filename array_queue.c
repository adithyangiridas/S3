#include<stdio.h>

#define SIZE 10
int front=-1,rear=-1,a[SIZE];

void enqueue(){
  if(rear==SIZE-1){
    printf("Queue Full.\n");
    return;
  }
  int x;
  printf("Enter the element to insert:");
  scanf("%d",&x);
  if(rear==-1){
    front=rear=0;
    a[rear]=x;
  }
  else
    a[++rear]=x;
  printf("Element inserted.\n");
  display();
}

void dequeue(){
  if(front==-1){
    printf("Queue Empty.\n");
    return;
  }
  int x=a[front];
  if(front==rear)
    front=rear=-1;
  else
    front++;
  printf("Element %d deleted.\n",x);
  display();
}

void display(){
  if(front==-1){
    printf("Queue Empty.\n");
    return;
  }
  printf("Queue:");
  for(int i=front;i<=rear;++i)
    printf("%d ",a[i]);
  printf("\n");
}

void main(){
  int ch;
  while(1){
    printf("\tMENU\n1 - Enqueue\n2 - Dequeue\n3 - Display\n4 - Exit\nEnter the choice:");
    scanf("%d",&ch);
    if(ch==1)
      enqueue();
    else if(ch==2)
      dequeue();
    else if(ch==3)
      display();
    else if(ch==4)
      exit(0);
    else
      printf("Invalid Choice.\n");
  }
}

    
    
