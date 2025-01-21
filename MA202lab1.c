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
    printf("\n");
    printf("\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%0.2f",L[i][j]);
        }
        printf("\n");
    }
    float z[n];
    z[0]=b[0];
    for(int i=1;i<n;i++){
        float sum=0;
        for(int j=i;j>=0;j--){
            sum=sum+(A[i][j]*b[i-1]);
        }
        z[i]=b[i]-sum;
    }
    float x[n];
    x[n-1]=z[n-1];
    for(int i=0;i<n-1;i++){
        float sum=0;
        for(int j=i;j<n;j++){
            sum=sum+(A[i][j]*z[i+1]);
        }
        x[i]=z[i]-sum;
    }
    for(int i=0;i<n;i++){
        printf("%f",x[i]);
    }
    return 0;
}
