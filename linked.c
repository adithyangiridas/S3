#include<stdio.h>

struct node{
 int data;
 struct node* link;
};

void traverse(struct node* head){
  struct node* temp=head;
  printf("HEAD-->");
  while(temp!=NULL){
    printf("%d-->",temp->data);
    temp=temp->link;
  }
  printf("NULL\n");
} 

void search(struct node* head){
  int x,pos=1,f=0;
  printf("Enter the element to be searched:");
  scanf("%d",&x);
  struct node* temp=head;
  while(temp!=NULL){
    if(x==temp->data){
      printf("%d found at position %d\n",x,pos);
      f=1;
    }
    temp=temp->link;
    pos++;
  }
  if(f==0)
    printf("Element not found.\n");
}
    

struct node* insert(struct node* head){
  int pos,count=0;
  struct node* temp,*newnode;
  printf("Enter the position to insert:");
  scanf("%d",&pos);
  temp=head;
  while(temp!=NULL){
    temp=temp->link;
    count++;
  }
  if(pos<1 || pos>count+1){
    printf("Invalid position.\n");
    return head;
  }
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("Enter the element to be inserted:");
  scanf("%d",&count);
  newnode->data=count;
  if(pos==1){
    newnode->link=head;
    head=newnode;
  }
  else{
    temp=head;
    for(int i=1;i<pos-1;++i)
      temp=temp->link;
    newnode->link=temp->link;
    temp->link=newnode;
  }
  printf("Element inserted successfully.\n");
  traverse(head);
  return head;
}

struct node* delete(struct node* head){
  int pos,count=0;
  struct node* temp,*temp1;
  printf("Enter the position of element to be deleted:");
  scanf("%d",&pos);
  temp=head;
  while(temp!=NULL){
    temp=temp->link;
    count++;
  }
  if(pos<1 || pos>count){
    printf("Invalid position.\n");
    return head;
  }
  temp=head;
  if(pos==1){
    head=head->link;
    free(temp);
  }
  else{
    for(int i=1;i<pos-1;++i)
      temp=temp->link;
    temp1=temp;
    temp=temp->link;
    temp1->link=temp->link;
    free(temp);
  }
  printf("Element deleted successfully.\n");
  traverse(head);
  return head;
}

void main(){
  struct node* head=NULL;
  int ch;
  char c='y';
  while(c=='y'){
    printf("\tMENU\n1 - Insert\n2 - Delete\n3 - Search\n4 - Traverse\n5 - Exit\nEnter the choice:");
    scanf("%d",&ch);
    if(ch==1)
      head=insert(head);
    else if(ch==2)
      head=delete(head);
    else if(ch==3)
      search(head);
    else if(ch==4)
      traverse(head);
    else if(ch==5)
      exit(0);
    else
      printf("Invalid choice.\n");
    printf("Do you want to continue?(y/n):");
    scanf("%c",&c);
    scanf("%c",&c);
  }
}

  
  
  
  
