#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 100
typedef struct {
char arr[MAX];
int top;
}Stack;
void init(Stack*s){
s->top=-1;
}
int isEmpty(Stack*s){
return s->top==-1;
}
int isFull(Stack*s){
return s->top==MAX-1;
}
void push(Stack*s,char c){
if(!isFull(s)){
    s->arr[++(s->top)]=c;
}
}
char pop(Stack*s){
if(!isEmpty(s)){
    return s->arr[(s->top)--];
}
    return '\0';
}
char peek(Stack*s){
if(!isEmpty(s)){
    return s->arr[s->top];
}
    return '\0';
}
int precedence(char op){
switch (op){
case '+':
case '-':return 1;
case '*':
case '/':return 2;
case '^':return 3;
}
return 0;
}
int isOperator(char c){
return c=='+'||c=='-'||c=='*'||c=='/'||c=='^';
}
void infixToPostfix(char*infix,char*postfix){
Stack s;
init(&s);
int k=0;
for (int i=0;infix[i]!='\0';i++){
    char c=infix[i];
    if (isalnum(c)){
        postfix[k++]=c;
    }
    else if(c=='('){
                push(&s,c);
            }
            else if(c==')'){
                while(!isEmpty(&s)&&peek(&s)!='('){
                        postfix[k++]=pop(&s);
                      }
                    pop(&s);
            }
            else if(isOperator(c)){
                while(!isEmpty(&s)&&precedence(peek(&s))>=precedence(c)){
                    if(c=='^'&&peek(&s)=='^'){
                        break;
                    }else{
                    postfix[k++]=pop(&s);
                    }
                }
                push(&s,c);
            }
}
while(!isEmpty(&s)){
    postfix[k++]=pop(&s);
}
    postfix[k]='\0';
}
int main(){
char infix[MAX];
char postfix[MAX];
printf("Enter infix expression:");
fgets(infix,MAX,stdin);
infix[strcspn(infix,"\n")]='\0';
infixToPostfix(infix,postfix);
printf("Postfix expression:%s\n",postfix);
return 0;
}
