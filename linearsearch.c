#include<stdio.h>
int linearSearch(int arr[],int n,int key){
int i;
for (i=0;i<n;i++){
    if (arr[i]==key)
        return i;
}
return -1;
}
int main(){
int arr[]={5,3,8,6,2};
int n=sizeof(arr)/sizeof(arr[0]);
int target=2;
int result=linearSearch(arr,n,target);
if(result!=-1){
printf("Element %d found at index %d\n",target,result);
}else{
printf("Element %d not found\n",target);
}
return 0;
}
