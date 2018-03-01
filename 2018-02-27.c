// This problem was asked by Google.
//
// An XOR linked list is a more memory efficient doubly linked list. Instead of
// each node holding next and prev fields, it holds a field named both, which is
// a XOR of the next node and the previous node. Implement a XOR linked list; it
// has an add(element) which adds the element to the end, and a get(index) which
// returns the node at index.
//
// If using a language that has no pointers (such as Python), assume you have
// access to get_pointer and dereference_pointer functions that converts between
// nodes and memory addresses.

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node* next;
} node;

node* create(int data, node* next) {
  node* new_node = (node*)malloc(sizeof(node));
  if (new_node == NULL) {
    printf("Error creating a new node.\n");
    exit(0);
  }
  new_node->data = data;
  new_node->next = next;

  return new_node;
}

node* prepend(node* head, int data) {
  node* new_node = create(data, head);
  head = new_node;
  return head;
}

node* get_next(node* current) {
  return current->next;
}

void display(node* n) {
  if (n != NULL) {
    printf("addr: %p, data: %d, next: %p\n", n, n->data, n->next);
  }
}

void printLinkedList(node* head) {
  node* cursor = head;
  while (cursor != NULL) {
    display(cursor);
    cursor = get_next(cursor);
  }
}

void freeLinkedList(node* head) {
  node* prev = head;
  while (prev != NULL) {
    node* temp = prev->next;
    free(temp);
    prev = temp;
  }
}

int main(int argc, char* argv[]) {
  node* head = prepend(head, 1);
  head = prepend(head, 2);
  head = prepend(head, 3);
  printLinkedList(head);
  freeLinkedList(head);
  printf("\n");
}