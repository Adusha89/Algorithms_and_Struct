#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define true 1 == 1
#define false 1 != 1

typedef int boolean;

//Список
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

//Стек

typedef struct NodeStack {
  char dat;
  struct NodeStack *next;
} NodeStack;

typedef struct {
  NodeStack *head;
  int size;
} Stack;

void initStack(Stack *stack) {
  stack->head = NULL;
  stack->size = 0;
}

//Добавляем элемент в стек
boolean push(Stack *stack, char value) {
  NodeStack *tmp = (NodeStack*)malloc(sizeof(NodeStack));
  if (tmp == NULL) {
    printf("\nStack overflow\n");
    return false;
  }
  tmp->dat = value;
  tmp->next = stack->head;

  stack->head = tmp;
  stack->size++;
  return true;
}

//Удаление элемента стека
char pop(Stack *stack) {
  if(stack->size == 0) {
    printf("Stack is empty \n");
    return -1;
  }
  NodeStack *tmp = stack->head;
  char data = stack->head->dat;
  stack->head = stack->head->next;
  free(tmp);
  stack->size--;
  return data;
}

//Печать узла стека
void printNodeStack(NodeStack *n) {
  if (n == NULL) {
    printf(" ");
    return;
  }
  printf(" %c ", n->dat);
}

//Печать стека
void printStack(Stack *stack) {
  NodeStack *current = stack->head;
  if(current == NULL) {
    printNodeStack(current);
  } else {
    do {
      printNodeStack(current);
      current = current->next;
    } while (current != NULL);
  }
  printf(" Size: %d \n", stack->size);
}

//Печать узла списка
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

//Заполнение списка
void fillList(List *ls, int n, int m) {
  srand ( time(NULL) );
  for(int i = 0; i < n; i++){
    ins(ls, (rand() % m));
  }
}

boolean checkStr(char *str, Stack *stack) {
  int i = 0;
  char c, c1;
  while(i < strlen(str) - 1) {
      c = str[i];

      if(c == '(') push(stack, ')');
      if(c == '{') push(stack, '}');
      if(c == '[') push(stack, ']');

      if(c == ')') {
        c1 = pop(stack);
        if(c1 != c ) { return false; }
      }
      if(c == ']') {
        c1 = pop(stack);
        if(c1 != c ) { return false; }
      }
      if(c == '}') {
        c1 = pop(stack);
        if(c1 != c ) { return false; }
      }
      i++;
  }
  if((stack->size) != 0) return false;
  return true;
}

//Первое задание
void firstTask() {
  char str[256];
  Stack *stack = (Stack*)malloc(sizeof(Stack));
  initStack(stack);

  printf("Input str\n");
  fgets(str, 256, stdin);
  
  if(checkStr(str, stack)) printf("Balance \n");
  else printf("Not balance \n");

}

//Второе задание
void secondTask() {
  List *list = (List*)malloc(sizeof(List));
  init(list);
  fillList(list, 10, 50);

  List *list2 = (List*)malloc(sizeof(List));
  init(list2);

  copyList(list, list2);
  printList(list);
  printList(list2);
}

//Третье задание
void thirdTask() {
  List *list = (List*)malloc(sizeof(List));
  init(list);
  fillList(list, 10, 30);

  printList(list);

  if(checkIncr(list)) printf("It's sort\n");
  else printf("Not sort\n");

}

int main(int argc, char const *argv[]) {
  firstTask();
  secondTask();
  thirdTask();

  return 0;
}
