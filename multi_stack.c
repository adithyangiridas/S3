#include<stdio.h>

int push1(int stack[],int top1,int top2){
  if(top1==top2){
    printf("Stack Full.\n");
    return top1;
  }
  printf("Enter the element to push:");
  scanf("%d",&stack[++top1]);
  printf("Element added.\n");
  display1(stack,top1);
  return top1;
}

int  push2(int stack[],int top2,int top1){
  if(top1==top2){
    printf("Stack Full.\n");
    return top2;
  }
  printf("Enter the element to push:");
  scanf("%d",&stack[--top2]);
  printf("Element added.\n");
  display2(stack,top2);
  return top2;
}

int pop1(int stack[],int top1){
  if(top1==-1){
    printf("Stack empty.\n");
    return top1;
  }
  top1--;
  printf("Element removed.\n");
  display1(stack,top1);
  return top1;
}

int pop2(int stack[],int top2){
  if(top2==10){
    printf("Stack empty.\n");
    return top2;
  }
  top2++;
  printf("Element removed.\n");
  display2(stack,top2);
  return top2;
}

void display1(int stack[],int top1){
  if(top1==-1){
    printf("Stack empty.\n");
    return;
  }
  printf("Stack 1:");
  for(int i=top1;i>=0;--i)
    printf("%d ",stack[i]);
  printf("\n");
}

void display2(int stack[],int top2){
  if(top2==10){
    printf("Stack empty.\n");
    return;
  }
  printf("Stack 2:");
  for(int i=top2;i<=9;++i)
    printf("%d ",stack[i]);
  printf("\n");
}

void main(){
  int stack[10],top1=-1,top2=10,ch;
  char c='y';
  while(c=='y'){
    printf("\tMENU\n1 - Push stack 1\n2 - Push stack 2\n3 - Pop stack 1\n4 - Pop stack 2\n5 - Display stack 1\n6 - Display stack 2\n7 - Exit\nEnter the choice:");
    scanf("%d",&ch);
    if(ch==1)
      top1=push1(stack,top1,top2);
    else if(ch==2)
      top2=push2(stack,top2,top1);
    else if(ch==3)
      top1=pop1(stack,top1);
    else if(ch==4)
      top2=pop2(stack,top2);
    else if(ch==5)
      display1(stack,top1);
    else if(ch==6)
      display2(stack,top2);
    else if(ch==7)
      exit(0);
    else
      printf("Invalid choice.\n");
  }
}
      
  
