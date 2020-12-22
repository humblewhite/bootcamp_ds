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

void find () {
  Node *temp = head;
  while (temp->next) {
    if (temp->number == temp->next->number) {
      Node *temp2 = temp->next->next;
      free (temp->next);
      temp->next = temp2;
    } else temp = temp->next;
  }
}

void print () {
  Node *current = head;
  while (current) {
    printf ("%d -> ", current->number);
    current = current->next;
  }
  printf ("NULL\n");
}

int main () {
  push (90);
  push (80);
  push (70);
  push (70);
  push (70);
  push (60);
  push (50);
  push (50);
  print();
  printf ("After removing the duplicate(s):\n");
  find();
  print();
  return 0;
}