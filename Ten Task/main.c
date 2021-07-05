#include "stdio.h"
#include "stdlib.h"

#define true 1 == 1
#define false 1 != 1

typedef int boolean;

typedef struct Node {
  int dat;
  struct Node *next;
} Node;

typedef struct {
  Node *head;
  int size;
} List;

void init(List* lst) {
  lst->head = NULL;
  lst->size = 0;
}

//Печать узла
void printNode(Node *el) {
  if(el == NULL) {
    printf("[ ] ");
  } else {
    printf("[ %d ] ", el->dat);
  }
}

//Печать списка
void printList(List *list) {
  Node *current = list->head;
  if (current == NULL) {
    printNode(current);
  } else {
    do {
      printNode(current);
      current = current->next;
    } while(current != NULL);
  }
  printf("Size list: %d\n", list->size);
}

//Вставка элемента
void ins(List *lst, int data) {
  Node *new = (Node*) malloc(sizeof(Node));
  new->dat = data;
  new->next = NULL;

  Node *current = lst->head;
  if (current == NULL) {
    lst->head = new;
    lst->size++;
  } else {
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new;
    lst->size++;
  }
}

//Проверка сортировки
boolean checkIncr (List *list) {
  Node *current = list->head;
  int temp = current->dat;
  current = current->next;

  do {
    if(temp > current->dat) return false;
    temp = current->dat;
    current = current->next;
  } while(current != NULL);
  return true;
}

//Копирование списка
void copyList(List *list1, List *list2) {
  Node *current1 = list1->head;

  do {
    ins(list2, current1->dat);
    current1 = current1->next;
  } while (current1 != NULL);
}

int main(int argc, char const *argv[]) {

  List *list = (List*)malloc(sizeof(List));
  init(list);

  printList(list);
  ins(list, 4);
  ins(list, 4);
  ins(list, 4);
  ins(list, 11);
  ins(list, 12);
  printList(list);

  if(checkIncr(list)) printf("It's sort\n");
  else printf("Not sort\n");

  List *list2 = (List*)malloc(sizeof(List));

  copyList(list, list2);
  printList(list2);

  return 0;
}
