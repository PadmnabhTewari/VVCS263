#include <stdio.h>
int parent(int i) 
{
    return (i-1)/2;
}

int left(int i) 
{
    return 2*i+1;
}

int right(int i) 
{
    return 2*i+2;
}
void max_heapify(int A[], int i, int n) 
{
    int l=left(i);
    int r=right(i);
    int largest=i;
    if (l<n && A[l]>A[largest]) 
    {
        largest=l;
    }
    if (r<n && A[r]>A[largest]) 
    {
        largest=r;
    }
    if (largest!=i) {
        int temp=A[i];
        A[i]=A[largest];
        A[largest]=temp;
        max_heapify(A,largest,n);
    }
}
void build_max_heap(int A[], int n) 
{
    for (int i=n/2-1;i>=0;i--) 
    {
        max_heapify(A,i,n);
    }
}
void heapsort(int A[], int n) 
{
    build_max_heap(A,n);
    for (int i=n-1;i>0;i--) 
    {
        int temp=A[0];
        A[0]=A[i];
        A[i]=temp;
        max_heapify(A, 0, i);
    }
}

int main() 
{
    int A[50];
    for (int i=0;i<50;i++) 
    {
        A[i]=49-i; 
    }
    heapsort(A,50);
    for (int i=0;i<50;i++) 
    {
        printf("%d\n",A[i]);
    }
    return 0;
}
