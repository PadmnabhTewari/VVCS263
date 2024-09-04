#include <stdio.h>

int maxCrossingSum(int A[], int p, int q, int r) {
    int left_sum = -10000000;
    int sum1 = 0;
    for (int i = q; i >= p; i--) {
        sum1 += A[i];
        if (sum1 > left_sum) {
            left_sum = sum1;
        }
    }
    int right_sum = -10000000;
    int sum2 = 0;
    for (int i = q + 1; i <= r; i++) { 
        sum2 += A[i];
        if (sum2 > right_sum) {
            right_sum = sum2;
        }
    }

    return left_sum + right_sum;
}

int maxSubarraySum(int A[], int p, int r) {
    if (p==r) 
    {
        return A[p];
    }
    int q=(p+r)/2;
    int leftMax=maxSubarraySum(A, p, q);
    int rightMax=maxSubarraySum(A, q + 1, r);  
    int crossMax=maxCrossingSum(A, p, q, r);
    if (leftMax>=rightMax && leftMax>=crossMax) {
        return leftMax;
    } else if (rightMax>=leftMax && rightMax>=crossMax) {
        return rightMax;
    } else {
        return crossMax;
    }
}

int main() {
    int A[]={1, 2, 3, 4, 5,-11,-12,55,120,-102,105};
    int p=0;
    int r=10; 
    int s=maxSubarraySum(A,p,r);
    printf("%d\n", s);
    return 0;
}
