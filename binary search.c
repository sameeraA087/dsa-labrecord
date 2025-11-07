#include<stdio.h>
int binarySearch(int arr[],int n,int target){
int low=0;
int high=n-1;
while(low<=high){
    int mid=low+(high-low)/2;
    if (arr[mid]==target){
        return mid;
    }else if (arr[mid]<target){
    low= mid+1;
    }else{
    high=mid-1;
    }
}
return -1;
}
int main(){
int arr[]={2,3,5,6,8};
int n=sizeof(arr)/sizeof(arr[0]);
int target=6;
int result=binarySearch(arr,n,target);
if (result!=-1){
printf("Element %d found at index %d\n",target,result);
}else{
printf("Element %d not found\n",target);
}
return 0;
}
