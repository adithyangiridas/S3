#include<stdio.h>

int push(int stack[],int top,int size){
  int x;
  if(top==size-1){
    printf("Stack Full.\n");
    return top;
  }
  printf("Enter the element to push:");
  scanf("%d",&x);
  top++;
  stack[top]=x;
  printf("Element added.\n");
  display(stack,top);
  return top;
}

int pop(int stack[],int top){
  if(top==-1){
    printf("Stack Empty.\n");
    return top;}
  top--;
  printf("Element removed.\n");
  display(stack,top);
  return top;
}

void display(int stack[],int top){
  if(top==-1){
    printf("Stack Empty.\n");
    return;
  }
  printf("Stack:");
  for(int i=top;i>=0;--i)
    printf("%d ",stack[i]);
  printf("\n");
}    
    
void main(){
  int stack[10],top=-1,size=10,ch;
  char c='y';
  while(c=='y'){
    printf("\tMENU\n1 - push\n2 - pop\n3 - display\n4 - exit\nEnter the choice:");
    scanf("%d",&ch);
    if(ch==1)
      top=push(stack,top,size);
    else if(ch==2)
      top=pop(stack,top);
    else if(ch==3)
      display(stack,top);
    else if(ch==4)
      exit(0);
    else
      printf("Invalid Choice.\n");
    printf("Do you want to continue?(y/n):");
    scanf("%c",&c);
    scanf("%c",&c);
  }
}
