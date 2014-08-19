#include<iostream>

using namespace std;

/*---------------------------------------------------------------------------*/
typedef struct node {
    int data;
    struct node *next;
} Node;


/*---------------------------------------------------------------------------*/
Node * getNewNode() {
    Node * temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL) {
        cout << "Error allocating memory!" << endl;
        return NULL;
    }
    temp->next = NULL;
    return temp;
}


/*---------------------------------------------------------------------------*/
Node * generateLinkedList() {
    Node * head = getNewNode();
    if (head == NULL) {
        return 0;
    }
    head->data = 0;

    Node * current = head;

    for (int i = 1; i <= 5; i++) {
        Node * temp = getNewNode();
        if (temp == NULL) {
            return NULL;
        }
        temp->next = NULL;
        temp->data = i;

        current->next = temp;
        current = current->next;
    }

    return head;
}


/*---------------------------------------------------------------------------*/
void printLinkedList(Node *head) {
    cout << "Linked list contents: " ;
    Node * temp = head;

    while (temp != NULL) {
        cout << "\t " << temp->data;
        temp = temp->next;
    }
    cout << endl;
}


/*---------------------------------------------------------------------------*/
void reverseLinkedList(Node **head) {
    Node *prev = NULL;
    Node *curr = *head;
    Node *next;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *head = prev;
}


/*---------------------------------------------------------------------------*/
Node * reverseLinkedListRecursive(Node *head, Node *prev) {
    if (head == NULL) {
        return prev;
    }

    Node * next = head->next;
    head->next = prev;

    return reverseLinkedListRecursive(next, head);
}


/*---------------------------------------------------------------------------*/
int main() {
    // Generate a linked list
    Node *head = generateLinkedList();
    printLinkedList(head);

    // Reverse without recursion
    reverseLinkedList(&head);
    printLinkedList(head);
    reverseLinkedList(&head);
    printLinkedList(head);
    reverseLinkedList(&head);
    printLinkedList(head);

    // Reverse with recursion
    head = reverseLinkedListRecursive(head, NULL);
    printLinkedList(head);
    head = reverseLinkedListRecursive(head, NULL);
    printLinkedList(head);
    head = reverseLinkedListRecursive(head, NULL);
    printLinkedList(head);

    return 0;
}
