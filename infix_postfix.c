#include<stdio.h>

void infix_postfix(char infix[],char postfix[],char variables[]){
  int i=0,j=0,k=0,top=0;
  char c,stack[50];
  stack[0]='(';
  while(infix[i]!='\0'){
    c=infix[i];
    if(c=='(')
      stack[++top]='(';
    else if(c=='^')
      stack[++top]='^';
    else if(c=='*'||c=='/'||c=='%'){
      while(stack[top]=='*'||stack[top]=='/'||stack[top]=='%'||stack[top]=='^')
	postfix[j++]=stack[top--];
      stack[++top]=c;
    }
    else if(c=='+'||c=='-'){
      while(stack[top]!='(')
	postfix[j++]=stack[top--];
      stack[++top]=c;
    }
    else if(c>='0'&&c<='9'||c>='a'&&c<='z'||c>='A'&&c<='Z')
      variables[k++]=postfix[j++]=c;
    else if(c==')'){
      while(stack[top]!='(')
	postfix[j++]=stack[top--];
      top--;
    }
    else{
      printf("Invalid Expression.\n");
      exit(0);
    }
    i++;
  }
  while(stack[top]!='(')
    postfix[j++]=stack[top--];
  variables[k]=postfix[j]='\0';
}

void evaluate(char postfix[],char variables[]){
  int values[50],i=0,stack[50],top=-1,a,b,d,j;
  char c;
  if(variables[0]!='\0')
    printf("Enter the values of the variables:\n");
  while(variables[i]!='\0'){
    c=variables[i];
    if(c>='0' && c<='9')
      values[i]=(int)c-48;
    else{
      printf("Enter the value of %c:",c);
      scanf("%d",&values[i]);
    }
    i++;
  }
  i=0;
  while(postfix[i]!='\0'){
    c=postfix[i];
    if(c>='0'&&c<='9' || c>='a'&&c<='z' || c>='A'&&c<='Z'){
      for(j=0;variables[j]!='\0';++j)
	if(variables[j]==c)
	  break;
      stack[++top]=values[j];
    }
    else{
      a=stack[top--];
      b=stack[top--];
      if(c=='+')
	d=b+a;
      else if(c=='-')
	d=b-a;
      else if(c=='*')
	d=b*a;
      else if(c=='/')
	d=b/a;
      else if(c=='%')
	d=b%a;
      else
	d=b^a;
      stack[++top]=d;
    }
    i++;
  }
  printf("Result of evaluation:%d\n",stack[top]);
}

void main(){
  char infix[50],postfix[50],variables[50];
  printf("Enter the infix expression:");
  scanf("%s",&infix);
  infix_postfix(infix,postfix,variables);
  printf("Postfix Expression:%s\n",postfix);
  evaluate(postfix,variables);
}
    
   
      
	
      
	
	
      
