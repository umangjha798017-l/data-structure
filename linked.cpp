#include<iostream>
#include<cstdlib>
using namespace std;

struct node {
    int data;
    struct node *next;
};

// Create a new node
struct node* createNode(int value) {
    struct node* newnode =
        (struct node*)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->next = NULL;

    return newnode;
}

// Insert node at the end
void insertEnd(struct node* &start, int value) {
    struct node* newnode = createNode(value);

    if(start == NULL) {
        start = newnode;
    }
    else {
        struct node* ptr = start;

        while(ptr->next != NULL) {
            ptr = ptr->next;
        }

        ptr->next = newnode;
    }
}

// Create linked list
void createList(struct node* &start) {
    int n, value;

    cout << "No of nodes ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "Insert Node " << i+1 << " data ";
        cin >> value;

        insertEnd(start, value);
    }
}

// Display linked list
void display(struct node* start) {
    struct node* ptr = start;

    cout << "Linked List is ";

    while(ptr != NULL) {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }

    cout << "NULL";
}

// Free all nodes
void freeList(struct node* &start) {
    cout << "\nReleasing memories...\n";

    struct node* ptr = start;

    while(ptr != NULL) {
        struct node* nextnode = ptr->next;

        free(ptr);

        ptr = nextnode;
    }

    start = NULL;

    cout << "All nodes freed";
}

int main() {
    struct node *start = NULL;

    createList(start);
    display(start);
    freeList(start);

    return 0;
}