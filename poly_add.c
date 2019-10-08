#include<stdio.h>

struct node{
  int coeff,exp;
  struct node* link;
};

struct node* poly_add(struct node* phead,struct node* qhead){
  struct node *pptr,*qptr,*rptr,*rhead=NULL,*newnode;
  pptr=phead;
  qptr=qhead;
  rptr=rhead;
  while(pptr!=NULL && qptr!=NULL){
    if(pptr->exp > qptr->exp){
      newnode=(struct node*)malloc(sizeof(struct node));
      newnode->coeff=pptr->coeff;
      newnode->exp=pptr->exp;
      newnode->link=NULL;
      if(rhead==NULL){
	rhead=rptr=newnode;
      }
      else{
	rptr->link=newnode;
	rptr=newnode;
      }
      pptr=pptr->link;
    }
    else if(qptr->exp > pptr->exp){
      newnode=(struct node*)malloc(sizeof(struct node));
      newnode->coeff=qptr->coeff;
      newnode->exp=qptr->exp;
      newnode->link=NULL;
      if(rhead==NULL)
	rhead=rptr=newnode;
      else{
	rptr->link=newnode;
	rptr=newnode;
      }
      qptr=qptr->link;
    }
    else if(pptr->exp==qptr->exp){
      newnode=(struct node*)malloc(sizeof(struct node));
      newnode->coeff=pptr->coeff+qptr->coeff;
      newnode->exp=pptr->exp;
      newnode->link=NULL;
      if(rhead==NULL)
	rhead=rptr=newnode;
      else{
	rptr->link=newnode;
	rptr=newnode;
      }
      pptr=pptr->link;
      qptr=qptr->link;
    }
  }
  while(pptr!=NULL){
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->coeff=pptr->coeff;
    newnode->exp=pptr->exp;
    newnode->link=NULL;
    if(rhead==NULL)
      rhead=rptr=newnode;
    else{
      rptr->link=newnode;
      rptr=newnode;
    }
    pptr=pptr->link;
  }
  while(qptr!=NULL){
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->coeff=qptr->coeff;
    newnode->exp=qptr->exp;
    newnode->link=NULL;
    if(rhead==NULL)
      rhead=rptr=newnode;
    else{
      rptr->link=newnode;
      rptr=newnode;
    }
    qptr=qptr->link;
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
  rhead=poly_add(phead,qhead);
  printf("First polynomial:");
  traverse(phead);
  printf("\nSecond polynomial:");
  traverse(qhead);
  printf("\nPolynomial sum:");
  traverse(rhead);
  printf("\n");
}

    
    
  
		
