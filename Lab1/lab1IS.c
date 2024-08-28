#include <stdio.h>
int main() {
    int arr[1000];
    for(int j=1000;j>0;j--){
        arr[1000-j]=j;
    }
    insertion_sort(arr,1000);
    int i;
    for(i=0;i<1000;i++){
        printf("%d  ",arr[i]);
    }
}
void insertion_sort(int arr[],int n)
{
  for(int i=1;i<n;i++)
  {
    int key=arr[i];
    int j=i-1;
    while(j>=0 && arr[j]>key){
         arr[j+1]=arr[j];
         j=j-1;
    }
    arr[j+1]=key;
  }
}
