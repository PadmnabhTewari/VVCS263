#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int LookupChain(int **m, int p[], int i, int j) {
    if (m[i][j] < INT_MAX) {
        return m[i][j];
    }
    if (i == j) {
        m[i][j] = 0;
    } else {
        for (int k = i; k <= j - 1; k++) {
            int q = LookupChain(m, p, i, k) + LookupChain(m, p, k + 1, j) + p[i - 1] * p[k] * p[j];
            if (q < m[i][j]) {
                m[i][j] = q;
            }
        }
    }
    return m[i][j];
}
int memoizedmatrixchain(int p[], int n) 
{
    int **m = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        m[i] = (int *)malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            m[i][j] = INT_MAX;
        }
    }
    int result = LookupChain(m, p, 1, n - 1);  
    for (int i = 0; i < n; i++) 
    {
        free(m[i]);
    }
    free(m);
    return result;
}
int main() 
{
    int p[] = {};
    int n = sizeof(p)/sizeof(p[0]);
    printf("Minimum number of multiplications is %d\n", memoizedmatrixchain(p, n));
    return 0;
}
