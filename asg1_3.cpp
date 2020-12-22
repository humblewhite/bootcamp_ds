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
  Node *temp = head->next;
  int count = 1;
  while (temp) {
    temp = temp->next;
    count++;
  }
  return count;
}

void print () {
  Node *current = head;
  while (current) {
    printf ("%d -> ", current->number);
    current = current->next;
  }
  printf ("NULL\n");
}

int findMid (int x) {
  Node *temp = head;
  int count = 1;
  while (count <= x/2) {
    if (x % 2 == 0 && count == x/2-1) {
      printf ("%d and ", temp->next->number);
    }
    count++;
    temp = temp->next;
  }
  return temp->number;
}

int main () {
  push (90);
  push (80);
  push (70);
  // push (75);
  push (60);
  push (50);
  push (100);
  print ();
  int x = check();
  printf ("The middle element is : ");
  printf ("%d\n", findMid(x));
  return 0;
}