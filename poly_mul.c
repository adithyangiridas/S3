#include<stdio.h>

struct node{
  int coeff,exp;
  struct node* link;
};

struct node* poly_mul(struct node* phead,struct node* qhead){
  struct node *pptr,*qptr,*rptr1,*rptr2,*rhead=NULL,*newnode;
  int f;
  pptr=phead;
  qptr=qhead;
  rptr1=rhead;
  while(pptr!=NULL && qptr!=NULL){
    while(qptr!=NULL){
      rptr2=rhead;
      f=0;
      while(rptr2!=NULL){
	if(rptr2->exp==pptr->exp+qptr->exp){
	  f=1;
	  break;
	}
	rptr2=rptr2->link;
      }
      if(f==1)
	rptr2->coeff+=pptr->coeff*qptr->coeff;
      else{
	newnode=(struct node*)malloc(sizeof(struct node));
        newnode->coeff=pptr->coeff*qptr->coeff;
        newnode->exp=pptr->exp+qptr->exp;
        newnode->link=NULL;
        if(rhead==NULL){
	  rhead=rptr1=newnode;
        }
        else{
	  rptr1->link=newnode;
	  rptr1=newnode;
        }
      }
      qptr=qptr->link;
    }
    qptr=qhead;
    pptr=pptr->link;
  }
  return rhead;
}

struct node* insert(){
  int d,c;
  struct node *newnode,*pptr,*phead=NULL;
  printf("Enter the degree of the polynomial:");
  scanf("%d",&d);
  for(int i=d;i>=0;--i){
    printf("Enter the coefficient of x^%d:",i);
    scanf("%d",&c);
    if(c!=0){
      newnode=(struct node*)malloc(sizeof(struct node));
      newnode->coeff=c;
      newnode->exp=i;
      newnode->link=NULL;
      if(phead==NULL)
	phead=pptr=newnode;
      else{
	pptr->link=newnode;
	pptr=newnode;
      }
    }
  }
  return phead;
}

void traverse(struct node* phead){
  struct node* pptr;
  if(phead==NULL)
    printf("zero polynomial");
  else{
    pptr=phead;
    while(pptr!=NULL){
      printf(" %dx^%d ",pptr->coeff,pptr->exp);
      pptr=pptr->link;
      if(pptr!=NULL)
	printf("+");
    }
  }
}

void main(){
  struct node *phead,*qhead,*rhead;
  printf("Enter the first polynomial:\n");
  phead=insert();
  printf("Enter the second polynomial:\n");
  qhead=insert();
  rhead=poly_mul(phead,qhead);
  printf("First polynomial:");
  traverse(phead);
  printf("\nSecond polynomial:");
  traverse(qhead);
  printf("\nPolynomial product:");
  traverse(rhead);
  printf("\n");
}
