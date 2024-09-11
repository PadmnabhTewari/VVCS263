#include <stdio.h>
#include<stdlib.h>
int prime(int n){
    if(n==1){
        return 0;
    }
    if(n==0){
        return 0;
    }
    int c=0;
    for(int i=2;i<n/2+1;i++)
    {
       if(n%i==0){
        c=c+1;
       }
    }
    if(c==0){
        return 1;
    }
    else{
        return 0;
    }
}
int number_of_primes(int n){
    int c=0;
    while(n>0){
        if(prime(n%10)==1){
            c=c+1;
        }
        n=n/10;
    }
        return c;
}
int biggiesmall(int a,int b){
    if(prime(a)==1){
        if(prime(b)==1){
            if(a<b){
                return 1;
            }
            else{
                return 0;
            }

        }
        else{
            return 1;
        }
    }
    else{
        if(prime(b)==1){
            return 0;
        }
        else{
            int c=number_of_primes(a);
            int d=number_of_primes(b);
            if(c<d){
                return 1;
            }
            else if(c>d){
                return 0;
            }
            else{
                if(a<b){
                    return 1;
                }
                else{
                    return 0;
                }
            }
        }
    }
}
void merge(int arr[], int p, int q, int r) {
    int nl = q-p+1;
    int nr = r-q;
    int L[nl];
    int R[nr];
    for (int i=0;i<nl;i++) {
        L[i] = arr[p+i];
    }
    for (int j=0;j<nr;j++) {
        R[j] = arr[q+j+1];
    }   
    int i = 0;
    int j = 0;
    int k = p;
    while (i<nl && j<nr) {
        if (biggiesmall(L[i],R[j])==1) {
            arr[k]=L[i];
            i++;
        } else {
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while (i<nl) {
        arr[k]=L[i];
        i++;
        k++;
    }
    while (j<nr) {
        arr[k]=R[j];
        j++;
        k++;
    }
}
void merge_sort(int arr[],int p,int r) 
{
    if (p<r) 
    {
        int q=p+(r-p)/2;
        merge_sort(arr,p,q);
        merge_sort(arr,q+1,r);
        merge(arr,p,q,r);
    }
}
int main(){
    int arr[100];
    for(int i=1;i<=100;i++){
          arr[i-1]=rand()%10000+1;
    }
    int p=0;
    int r=100-1;
    merge_sort(arr,p,r);
    for(int i=0;i<99;i++){
          printf("%d ",arr[i]);
    }
}

