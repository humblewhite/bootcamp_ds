#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
  int number;
  Node *next;
} *head, *tail;

void push (int number) {
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->number = number;
  newNode->next = NULL;
  if (!head) {
    head = tail = newNode;
  } else {
    tail->next = newNode;
    tail = newNode;
  }
}

int check () {
  if (head == NULL) {
    return 1;
  } else {
    Node *temp = head->next;
    while (temp != NULL && temp != head) {
      temp = temp->next;
    }
    if (temp == head) {
      return 1;
    } else return 0;
  }
}

void print () {
  Node *current = head;
  while (current) {
    printf ("%d -> ", current->number);
    current = current->next;
  }
  tail->next = head; tail = head;
  printf ("%d -> NULL\n", tail->number);
}

int main () {
  push (90);
  push (80);
  push (70);
  push (60);
  push (50);
  print ();
  int x = check();
  if (x == 1) {
    printf ("Circular Linked List\n");
  } else printf ("Not a Circular Linked List\n");
  return 0;
}