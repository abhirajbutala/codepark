/* Program to create a BST from sorted array of integers */

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} Node;

Node *getNewNode() {
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL) {
        printf("Error allocating memory!");
        return NULL;
    }
    temp->left = temp->right = NULL;
    return temp;
}


void printTree(Node *root) {
    if (root != NULL) {
        printTree(root->left);
        printf("%d\t", root->value);
        printTree(root->right);
    }
}

Node * arrayToBST(int *arr, int start, int end) {
    if (arr == NULL) {
        return NULL;
    }

    if (start < end) {
        int middle = (start + end)/2;

        Node *currNode = getNewNode();
        if (currNode == NULL) {
            return NULL;
        }

        currNode->value = arr[middle];
        currNode->left = arrayToBST(arr, start, middle-1);
        currNode->right = arrayToBST(arr, middle + 1, end);
        return currNode;
    } else if (start == end) {
        Node *currNode = getNewNode();
        if (currNode == NULL) {
            return NULL;
        }

        currNode->value = arr[start];
        return currNode;
    } else {
        return NULL;
    }
}

int main () {
    int arr[] = {1, 1, 3, 4, 5};

    Node *root = arrayToBST(arr, 0, 4);
    printTree(root);
}

