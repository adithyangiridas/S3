#include<stdio.h>

struct node{
  int data;
  struct node* link;
};

void display(struct node* top){
  if(top==NULL){
    printf("Stack Empty\n");
    return;
  }
  struct node* temp=top;
  printf("Stack:\nTOP");
  while(temp!=NULL){
    printf("-->%d",temp->data);
    temp=temp->link;
  }
  printf("-->NULL\n");
}
 
struct node* push(struct node* top){
  struct node* newnode;
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("Enter the element to be pushed:");
  scanf("%d",&newnode->data);
  newnode->link=NULL;
  if(top==NULL)
    top=newnode;
  else{
    newnode->link=top;
    top=newnode;
  }
  display(top);
  return top;
}

struct node* pop(struct node* top){
  if(top==NULL){
    printf("Stack Empty\n");
    return top;
  }
  struct node* temp=top;
  top=top->link;
  free(temp);
  printf("Element deleted\n");
  display(top);
  return top;
}

void main(){
  struct node* top=NULL;
  int ch;
  while(1){
    printf("\tMENU\n1 - PUSH\n2 - POP\n3 - DISPLAY\n4 - EXIT\nEnter the choice:");
    scanf("%d",&ch);
    if(ch==1)
      top=push(top);
    else if(ch==2)
      top=pop(top);
    else if(ch==3)
      display(top);
    else if(ch==4)
      exit(0);
    else
      printf("Invalid Choice\n");

  }
}

    
  
