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

void print () {
  Node *current = head;
  while (current) {
    printf ("%d -> ", current->number);
    current = current->next;
  }
  printf ("NULL\n");
}

void reverse () {
  Node *current = head;
  Node *prev = NULL, *then = NULL;
  while (current) {
    then = current->next;
    current->next = prev;
    prev = current;
    current = then;
  }
  head = prev;
}

int main () {
  push (100);
  push (90);
  push (80);
  push (70);
  push (75);
  push (60);
  push (50);
  printf ("Before:\n");
  print();
  reverse();
  printf ("After:\n");
  print();
}