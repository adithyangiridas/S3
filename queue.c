#include<stdio.h>

int front=-1,rear=-1,a[10];

void enqueue(){
  if(front==0 && rear==9 || front==rear+1){
    printf("Queue Full.\n");
    return;
  }
  int x;
  printf("Enter the element to insert:");
  scanf("%d",&x);
  if(front==-1)
    front=rear=0;
  else if(rear==9)
    rear=0;
  else
    rear++;
  a[rear]=x;
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
  else if(front==9)
    front=0;
  else
    front++;
  printf("Element %d deleted.\n",x);
  display();
}

void display(){
  if(front==-1){
    printf("Queue empty.\n");
    return;
  }
  printf("Queue:");
  if(front<=rear)
    for(int i=front;i<=rear;++i)
      printf("%d ",a[i]);
  else{
    for(int i=front;i<=9;++i)
      printf("%d ",a[i]);
    for(int i=0;i<=rear;++i)
      printf("%d ",a[i]);
  }
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
