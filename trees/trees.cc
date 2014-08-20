#include<iostream>

using namespace std;


/*---------------------------------------------------------------------------*/
typedef struct node {
    int value;
    struct node *left;
    struct node *right;
} Node;


/*---------------------------------------------------------------------------*/
Node *getNewNode() {
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL) {
        cout << "Error allocating memory!" << endl;
        return NULL;
    }
    temp->left = temp->right = NULL;
    return temp;
}


/*---------------------------------------------------------------------------*/
void printTree(Node *root) {
    if (root != NULL) {
        printTree(root->left);
        cout << "\t" << root->value;
        printTree(root->right);
    }
}


/*---------------------------------------------------------------------------*/
Node * sortedArrayToBST(int *arr, int low, int high) {
    if (low > high) {
        return NULL;
    }

    int mid = low + (high - low)/2;
    Node *current = getNewNode();
    current->value = arr[mid];
    current->left = sortedArrayToBST(arr, low, mid-1);
    current->right = sortedArrayToBST(arr, mid+1, high);
    return current;
}


/*---------------------------------------------------------------------------*/
Node * insertElementBST(Node *root, int elem) {
    if (root == NULL) {
        root = getNewNode();
        root->value = elem;
    } else if (root->value < elem) {
        root->right = insertElementBST(root->right, elem);
    } else {
        root->left = insertElementBST(root->left, elem);
    }

    return root;
}


/*---------------------------------------------------------------------------*/
Node * deleteElementBST(Node *root, int elem) {
    if (root == NULL) {
        return NULL;
    }

    if (root->value == elem) {
        // If node does not have any children, just delete the node
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }

        // If node has one child, then remove the node and return that child
        if (root->left != NULL && root->right == NULL) {
            Node *temp = root->left;
            root->left = NULL;
            free(root);
            return temp;
        }
        if (root->left == NULL && root->right != NULL) {
            Node *temp = root->right;
            root->right = NULL;
            free(root);
            return temp;
        }

        // If we reach here, then root has two children. In this case we find
        // the smallest node which is larger than root, and replace root's
        // value with this new node's value. Then we delete this smallest
        // node from the tree. Magic of recursion!
        Node *replacement = root->right;
        while (replacement->left != NULL) {
            replacement = replacement->left;
        }

        root->value = replacement->value;
        root->right = deleteElementBST(root->right, replacement->value);
        return root;

    } else if (root->value < elem) {
        root->right = deleteElementBST(root->right, elem);
    } else {
        root->left = deleteElementBST(root->left, elem);
    }

    return root;
}


/*---------------------------------------------------------------------------*/
void preOrderTraversal(Node * root) {
    if (root == NULL) {
        return;
    }
    cout << "\t" << root->value;
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}


/*---------------------------------------------------------------------------*/
void inOrderTraversal(Node * root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    cout << "\t" << root->value;
    inOrderTraversal(root->right);
}


/*---------------------------------------------------------------------------*/
void postOrderTraversal(Node * root) {
    if (root == NULL) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << "\t" << root->value;
}


/*---------------------------------------------------------------------------*/
void findInOrderSuccessor(Node *root, int elem, bool *flag) {
    if (root == NULL) {
        return;
    }

    findInOrderSuccessor(root->left, elem, flag);
    if (*flag == true) {
        cout << "In Order successor : " << root->value << endl;
        *flag = false;
        return;
    }

    if (root->value == elem) {
        *flag = true;
    }
    findInOrderSuccessor(root->right, elem, flag);

}


/*---------------------------------------------------------------------------*/



/*---------------------------------------------------------------------------*/
int main () {
    int arr[] = {1, 2, 3, 4, 5, 6, 8, 9};

    // Create a BST from a sorted Array
    Node *root = sortedArrayToBST(arr, 0, 7);
    cout << "Initial tree contents :";
    printTree(root);
    cout << endl;

    // Insert an element into BST
    root = insertElementBST(root, 13);
    root = insertElementBST(root, -1);
    root = insertElementBST(root, 7);
    cout << "Tree contents after inserting 13, -1 and 7 :" ;
    printTree(root);
    cout << endl;


    // Tree Traversals
    // Preorder
    cout << "Pre Order Traversal :";
    preOrderTraversal(root);
    cout << endl;
    // Inorder
    cout << "In Order Traversal :";
    inOrderTraversal(root);
    cout << endl;
    // Postorder
    cout << "Post Order Traversal :";
    postOrderTraversal(root);
    cout << endl;


    // Find in-order successor of a given node in the tree
    bool flag = false;
    findInOrderSuccessor(root, 4, &flag);
    findInOrderSuccessor(root, -1, &flag);
    findInOrderSuccessor(root, 13, &flag);

    // DFS

    // BFS


    // Delete an element into BST
    root = deleteElementBST(root, 4);
    cout << "Tree contents after deleting 4 :" ;
    printTree(root);
    cout << endl;

    root = deleteElementBST(root, 13);
    cout << "Tree contents after deleting 13 :" ;
    printTree(root);
    cout << endl;

    root = deleteElementBST(root, 1);
    cout << "Tree contents after deleting 1 :" ;
    printTree(root);
    cout << endl;

    return 0;
}

/*---------------------------------------------------------------------------*/
