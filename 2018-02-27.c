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
  struct node* both;
} node;

node* node_xor(node* a, node* b) {
  return (node*)((size_t)a ^ (size_t)b);
}

node* get_next(node* n, node* prev) {
  return node_xor(prev, n->both);
}

void set_next(node* n, node* next) {
  n->both = node_xor(n->both, next);
}

node* get_prev(node* n, node* next) {
  return node_xor(n->both, next);
}

void set_prev(node* n, node* prev) {
  n->both = node_xor(n->both, prev);
}

node* create(int data, node* prev, node* next) {
  node* new_node = (node*)malloc(sizeof(node));
  if (new_node == NULL) {
    printf("Error creating a new node.\n");
    exit(0);
  }
  new_node->data = data;
  new_node->both = node_xor(prev, next);

  return new_node;
}

node* prepend(node* head, int data) {
  node* new_node = create(data, NULL, head);
  if (head != NULL) {
    set_prev(head, new_node);
  }
  head = new_node;
  return head;
}

// add a new node (data) to the end of the list
node* add(node* head, int data) {
  if (head == NULL) {
    return create(data, NULL, NULL);
  }

  // iterate through list until we reach the last element
  node* last = NULL;
  node* current = head;
  while(current != NULL) {
    node* temp = current;
    current = get_next(current, last);
    last = temp;
  }

  // create the new element and add it as last's next ptr
  node* new_node = create(data, last, NULL);
  set_next(last, new_node);

  return head;
}

// returns a node at idx
node* get(node* head, int idx) {
  node* prev = NULL;
  node* current = head;
  int i = 0;
  while(current != NULL) {
    if (i == idx) {
      return current;
    }
    i++;
    node* temp = current;
    current = get_next(current, prev);
    prev = temp;
  }
  return NULL;
}

void display(node* n, node* prev) {
  if (n != NULL) {
    printf("addr: %p, ", n);
    printf("data: %d, ", n->data);
    printf("both: %p, ", n->both);
    printf("prev: %p, ", prev);
    printf("next: %p\n", get_next(n, prev));
  }
}

void printLinkedList(node* head) {
  node* prev = NULL;
  node* current = head;
  while (current != NULL) {
    display(current, prev);
    node* temp = current;
    current = get_next(current, prev);
    prev = temp;
  }
  printf("\n");
}

int main(int argc, char* argv[]) {
  node* head = create(1, NULL, NULL);
  add(head, 2);
  add(head, 3);
  add(head, 4);
  add(head, 5);
  head = prepend(head, 6);
  // node* head = prepend(NULL, 1);
  // head = prepend(head, 2);
  // head = prepend(head, 3);
  printLinkedList(head);
  display(get(head, 5), get(head, 4));
}