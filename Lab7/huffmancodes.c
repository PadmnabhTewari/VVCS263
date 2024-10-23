#include <stdio.h> 
#include <stdlib.h> 

// Structure for a node in the Huffman tree
typedef struct Node {
    char data;       // character data
    int freq;        // frequency of the character
    struct Node *left, *right;  // left and right child nodes
} Node;

// Create a new node with given data and frequency
Node* createNode(char data, int freq) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

// Function to swap two nodes in the heap
void swap(Node** a, Node** b) {
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain the min-heap property by heapifying the subtree rooted at index i
void min_heapify(Node* A[], int i, int n) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int smallest = i;
    
    if (left < n && A[left]->freq < A[smallest]->freq)
        smallest = left;
    
    if (right < n && A[right]->freq < A[smallest]->freq)
        smallest = right;
    
    if (smallest != i) {
        swap(&A[i], &A[smallest]);
        min_heapify(A, smallest, n);
    }
}

// Function to build a min-heap from an unsorted array of nodes
void build_min_heap(Node* A[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        min_heapify(A, i, n);
}

// Function to extract the minimum node from the heap
Node* extract_min(Node* A[], int* n) {
    Node* root = A[0];
    A[0] = A[*n - 1];
    (*n)--;
    min_heapify(A, 0, *n);
    return root;
}

// Function to insert a new node into the heap
void insert(Node* A[], int* n, Node* key) {
    (*n)++;
    int i = *n - 1;
    A[i] = key;
    
    while (i && A[i]->freq < A[(i - 1) / 2]->freq) {
        swap(&A[i], &A[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Function to print the Huffman codes
void printCodes(Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (!(root->left) && !(root->right)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// Huffman function that implements the algorithm as described
Node* huffman(char data[], int freq[], int size) {
    Node* heap[100];
    int n = 0;
    
    // Step 2: Initialize the priority queue with the characters
    for (int i = 0; i < size; i++) {
        heap[i] = createNode(data[i], freq[i]);
        n++;
    }
    
    build_min_heap(heap, n);
    
    // Step 3: Extract two minimum frequency nodes and merge them
    while (n > 1) {
        Node* x = extract_min(heap, &n);
        Node* y = extract_min(heap, &n);
        
        Node* z = createNode('$', x->freq + y->freq);  // Create internal node
        z->left = x;
        z->right = y;
        
        insert(heap, &n, z);  // Insert new node into heap
    }
    
    // The final node is the root of the Huffman tree
    return extract_min(heap, &n);
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {45, 13, 12, 16, 9, 5};
    
    int size = sizeof(data) / sizeof(data[0]);
    
    // Step 1: Build Huffman Tree
    Node* root = huffman(data, freq, size);
    
    // Print Huffman Codes
    int arr[100], top = 0;
    printCodes(root, arr, top);
    
    return 0;
}
