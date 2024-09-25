#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parent(int i) {
    return (i - 1) / 2;
}

int left(int i) {
    return 2 * i + 1;
}

int right(int i) {
    return 2 * i + 2;
}


int compare(int a, int b) {
    int onea = a % 10;
    int oneb = b % 10;

    if (onea != oneb) {
        return onea-oneb;
    }
    return a - b;
}

void min_heapify(int A[], int i, int n) {
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l<n && compare(A[l],A[smallest])<0) {
        smallest=l;
    }

    if (r<n && compare(A[r],A[smallest])<0) {
        smallest=r;
    }

    if (smallest!=i) {
        int temp = A[i];
        A[i]=A[smallest];
        A[smallest]=temp;
        min_heapify(A,smallest,n);
    }
}

void build_min_heap(int A[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        min_heapify(A, i, n);
    }
}

void insert(int A[], int *n, int key) {
    (*n)++;
    A[*n - 1] = key;
    int i = *n - 1;

    while (i != 0 && compare(A[parent(i)], A[i]) > 0) {
        int temp = A[i];
        A[i] = A[parent(i)];
        A[parent(i)] = temp;
        i = parent(i);
    }
}

int pop_min(int A[],int *n) {
    if (*n<=0) return -1;
    if (*n==1) {
        (*n)--;
        return A[0];
    }
    int r=A[0];
    A[0]=A[*n-1];
    (*n)--;
    min_heapify(A,0,*n);
    return r;
}

void heapsort(int A[], int n) {
    build_min_heap(A, n);
    for (int i = n - 1; i > 0; i--) {
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        min_heapify(A, 0, i);
    }
}
void print_heap(int A[], int n) {
    for (int i = n-1 ; i>=0; i--) {
        printf("%d ", A[i]);
    }
    printf("\n");
}
int main() {
    int heap[100], n = 0,a=1;
    int c,val,length;
    while (a>0) {
        printf("1. Insert into heap\n");
        printf("2. Display heap in sorted order (heapsort)\n");
        printf("3. Create an empty min heap\n");
        printf("4. Pop from heap\n");
        printf("5. Build heap from input list\n");
        printf("6. Generate random array and heapsort\n");
        printf("7. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &c);
        if (c == 1) {
            printf("Enter value to insert: ");
            scanf("%d", &val);
            insert(heap, &n, val);
            printf("After insertion: ");
            print_heap(heap, n);
        } 
        else if (c == 2) {
            heapsort(heap, n);
            printf("Heap sorted: ");
            print_heap(heap, n);
        } 
        else if (c == 3) {
            n = 0;
            printf("Empty min heap created.\n");
        } 
        else if (c == 4) {
            int popped = pop_min(heap, &n);
            printf("Popped value: %d\n", popped);
            printf("Heap after pop: ");
            print_heap(heap, n);
        } 
        else if (c == 5) {
            printf("Enter comma-separated values: ");
            char input[500];
            scanf("%s", input);
            char *token = strtok(input, ",");
            while (token != NULL) {
                heap[n++] = atoi(token);
                token = strtok(NULL, ",");
            }
            build_min_heap(heap, n);
            printf("Heap built: ");
            print_heap(heap, n);
        } 
        else if (c == 6) {
            printf("Enter length of array to generate: ");
            scanf("%d", &length);
            int arr[100];
            for (int i = 0; i < length; i++) {
                arr[i] = rand() % 90000 + 10000;
            }

            heapsort(arr, length);
            printf("Heap sorted: ");
            for (int i = 0; i < length; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
        } 
        else if (c == 7) {
            break;
        } 
        else {
            printf("Invalid option.\n");
        }
    }

    return 0;
}
