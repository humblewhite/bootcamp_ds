#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Node {
  int number;
  Node *next;
};

Node *merge (Node *list1, Node *list2) {
  struct Node temp;
  Node *tail = &temp;
  temp.next = NULL;
  int flag = 0;
  while (flag != 2) {
    if (list1 == NULL) {
      tail->next = list2; flag = 1; break;
    } else if (list2 == NULL) {
      tail->next = list1;
      if (flag == 1) { flag == 2; } break;
    }
    if (list1->number >= list2->number) {
      struct Node *space = list1;
      list1 = list1->next;
      tail->next = space;
    } else {
      struct Node *space = list2;
      list2 = list2->next;
      tail->next = space;
    }
    tail = tail->next;
  }
  return temp.next;
}

void push (Node** temp, int number) {
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->number = number;
  newNode->next = *temp;
  *temp = newNode;
}

void print (Node *result) {
  while (result) {
    printf ("%d -> ", result->number);
    result = result->next;
  }
  printf ("NULL\n");
}

int main () {
  struct Node* result = NULL;
  struct Node* list1 = NULL;
  struct Node* list2 = NULL;

  push (&list1, 5);
  push (&list1, 10);
  push (&list1, 20);
  // print (list1);
  push (&list2, 1);
  push (&list2, 15);
  push (&list2, 25);
  push (&list2, 30);
  // print (list2);
  result = merge(list1, list2);
  print(result);

  return 0;
}