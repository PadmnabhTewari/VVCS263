#include<stdio.h>
void LUdec(int n,float A[n][n],float U[n][n],float L[n][n])
{
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++)
        {
            float sum=0;
            for(int k=0;k<i;k++)
            {
              sum=sum+(L[i][k]*U[k][j]);  
            }
            U[i][j]=A[i][j]-sum;
        }   
    
        for(int j=i;j<n;j++){
            if(i==j){
                continue;
            }
            else{
                float sum=0;
                for(int k=0;k<i;k++){
                    sum=sum+(L[j][k]*U[k][i]);
                }
                L[j][i]=(A[j][i]-sum)/U[i][i];
            }
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    float A[n][n],L[n][n],U[n][n];
    int b[n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%f",&A[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                L[i][j]=1;
            }
            else{
                L[i][j]=0;
            }
            U[i][j]=0;
        }
    }
    for(int k=0;k<n;k++)
    {
            scanf("%d",&b[k]);
    }
    LUdec(n,A,U,L);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%0.2f",U[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%0.2f",L[i][j]);
        }
        printf("\n");
    }
    return 0;
}
