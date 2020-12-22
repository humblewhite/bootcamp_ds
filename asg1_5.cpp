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

int print () {
  int count = 1;
  Node *current = head;
  while (current) {
    printf ("%d -> ", current->number);
    current = current->next;
    count++;
  }
  printf ("NULL\n"); count--;
  return count;
}

int find (int x) {
  Node *temp = head;
  int count = 1;
  if (head->next == NULL) {
    return head->number;
  } else {
    while (count < x) {
      count++;
      temp = temp->next;
    }
    return temp->number;
  }
}

int main () {
  push (90);
  push (80);
  push (70);
  push (75);
  push (60);
  push (50);
  push (100);
  int count = print();
  printf ("%d\n", count);
  int x; scanf ("%d", &x);
  if (x != 0 && x <= count) {
    printf ("%d\n", find(x));
  } else printf ("There is no %d-th element in this Linked List\n", x);
  return 0;
}