#include<stdio.h>
int main()
{
    int n;
    scanf("%d",n);
    int A[n][n];
    int b[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",A[i][j]);
        }
    }
    for(int k=0;k<n;k++){
            scanf("%d",b[k]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++){
            int d=A[i][i]/A[i][j];
            for(int k=0;k<n;k++)
            {
                A[i][k]-=A[i][j]*d;
                b[k]=b[k]-b[j]*d;
            }
        }
    }
    
}
