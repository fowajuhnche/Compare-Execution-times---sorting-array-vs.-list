#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

/* Linked List Declarations Start */

struct LinkedListNode {
    int data;
    LinkedListNode* next;

    LinkedListNode(int _data = 0) {
        data = _data;
        next = NULL;
    }
};

/* Function to insert a new node to a linked list, returns the new head after insertion (inserts at the end of the linked list) */
LinkedListNode* insert(LinkedListNode* head, int val) {
    if (head == NULL) {
        return new LinkedListNode(val);
    }
    LinkedListNode* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new LinkedListNode(val);
    return head;
}

/* Function to print the linked list (for debugging purposes) */
void printLL(LinkedListNode* head) {
    LinkedListNode* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

/* Linked List Declarations End */

// Sorting Algo Chosen: Insertion Sort

// For linked list

/* Helper function for inserting the sorted node at its correct position */
void sortedInsertLL(LinkedListNode *&sortedList, LinkedListNode *newNode) {
    if (sortedList == NULL || sortedList->data >= newNode->data) {
        newNode->next = sortedList;
        sortedList = newNode;
        return;
    }

    LinkedListNode *curr = sortedList;
    while (curr->next != NULL && curr->next->data < newNode->data) {
        curr = curr->next;
    }
    newNode->next = curr->next;
    curr->next = newNode;
}

/* Function to sort the linked list using insertion sort algo */
void insertionSortLL(LinkedListNode *head) {
    LinkedListNode *curr = head;
    LinkedListNode *sorted = NULL;
    while (curr != NULL) {
        LinkedListNode *next = curr->next;
        sortedInsertLL(sorted, curr);
        curr = next;
    }
    head = sorted;
}

// Array

/* This function dynamically allocates memory for 
n (user input number) elements and returns its pointer */
int* createArray(int n) {
    int *arr = new int[n];
    return arr;
}

/* Function to print the array */
void printArr(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return;
}

// Insertion Sort Array
/* Insertion sort algo function for integer array */
void insertionSort(int *arr, int n) {
    int i, key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}

int main() {
    srand(time(NULL));
    LinkedListNode *list = NULL;
    int *arr = NULL;

    cout << "No of Elements\tTime by LL\tTime by Arr\n";

    for (int t = 0; t < 10; t++) {
        list = NULL;
        arr = NULL;
        clock_t start,end;
        double time_ll, time_arr;
        /* Linked List and array Creation (no of elements generated on random) */
        int nos = 1 + rand() % 100000;
        arr = createArray(nos);
        for (int  i = 0;i < nos; i++) {
            int element =rand() % 10000; // Generates an element between 0 and 10000
            arr[i] = element; // Insert to array
            list = insert(list, element); // Insert to Linked List
        }

        /* Before Sorting Result */
        // cout << "Unsorted Mode\n";
        // printLL(list);
        // printArr(arr, nos);

        // Apply Sorting Algorithm
        start = clock();
        insertionSortLL(list); // Insertion Sort applied For Linked List
        end = clock();
        time_ll = (double)(end - start)/CLOCKS_PER_SEC;
        start = clock();
        insertionSort(arr, nos); // Insertion Sort applied For Integer Array (Dynamically Allocated)
        end = clock();
        time_arr = (double)(end - start)/CLOCKS_PER_SEC;

        /* After Sorting Result */
        // cout << "\n\nAfter Sorting\n\n";
        // printLL(list);
        // printArr(arr, nos);

        /* Print Tablular output */
        cout << nos << "\t\t" << time_ll << "\t\t" << time_arr << "\n";
    }

    delete[] arr; // Free the dynamically allocated  memory of the array to prevent memory leak
    return 0;   
}