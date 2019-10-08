#include<stdio.h>

struct node{
  int data;
  struct node* link;
};

struct node *front,*rear;

void display(){
  if(front==NULL){
    printf("Queue empty\n");
    return;
  }
  struct node* temp=front;
  printf("Queue:\nFRONT");
  while(temp!=NULL){
    printf("-->%d",temp->data);
    temp=temp->link;
  }
  printf("<--REAR\n");
}

void enqueue(){
  struct node* newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("Enter the element to be inserted:");
  scanf("%d",&newnode->data);
  newnode->link=NULL;
  if(front==NULL)
    front=rear=newnode;
  else{
    rear->link=newnode;
    rear=newnode;
  }
  printf("Element inserted\n");
  display();
}

void dequeue(){
  if(front==NULL){
    printf("Queue Empty\n");
    return;
  }
  struct node* temp=front;
  if(front==rear)
    front=rear=NULL;
  else
    front=front->link;
  free(temp);
  printf("Element deleted\n");
  display();
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
      printf("Invalid choice\n");
  }
}

  
