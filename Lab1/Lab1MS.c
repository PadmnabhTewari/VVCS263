#include <stdio.h>
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
        if (L[i]<=R[j]) {
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
int main() {
    int arr[101]; 
    for (int j=100;j>=0;j--) {
        arr[100-j]=j;
        printf("%d ",arr[100-j]);
    }
    printf("\n");
    int p = 0;
    int r = 100; 
    merge_sort(arr, p, r);
    for (int i=0;i<=r;i++) {
        printf("%d ",arr[i]);
    }
    printf("\n"); 
    return 0;
}
