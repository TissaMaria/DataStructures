#include <stdio.h>
#define SIZE 5
int arr[5], top=-1;
void push(int value){
if(top==SIZE-1){
    printf("\nThe stack is filled\n");
}else{

    top+=1;
    arr[top]=value;
    printf("\nSuccessfully Added\n");}
   }
void pop(){
    if(top==-1){
    printf("\nThe stack is empty\n");
}else{
    printf("\n%d has been deleted from the array\n",arr[top]);
    top=top-1;
   }
}
void display(){
    if(top==-1){
    printf("\nThe stack is empty\n");
}else{
    for(int i=0;i<=top;i++){
    printf("%d\n",arr[i]);}

   }

}
int main(){
    int boolean=1,choice,value;
    while(boolean){
        printf("\n1.PUSH\t2.PULL\t3.DISPLAY\t4.EXIT\n");
        scanf("%d",&choice);
        switch(choice){
        case 1:{printf("Enter a value");
            scanf("%d",&value);
                push(value);
                break;}
        case 2:pop();
        break;
        case 3:display();
        break;
        case 4:boolean=0;
        break;
        default:printf("Invalid Input");
        }
    }
    return 0;
    }
