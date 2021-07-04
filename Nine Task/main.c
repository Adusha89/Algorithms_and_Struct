#include <stdio.h>
#include <stdlib.h>

//Для задания со стеком
#define T int
#define SIZE 1000
#define true 1 == 1
#define false 1 != 1

typedef int boolean;

//Для задания с очередью
#define SZ 10

typedef struct {
  int pr;
  int dat;
} Node;

Node* arr[SZ];
int head;
int tail;
int items;

//Стек
int cursor = -1;
T Stack[SIZE];

boolean push(T data) {
  if(cursor < SIZE) {
    Stack[++cursor] = data;
    return true;
  } else {
    printf("\nStack overflow");
    return false;
  }
}

T pop() {
  if (cursor != -1) {
    return Stack[cursor--];
  } else {
    printf("\nStack is empty");
    return -1;
  }
}

//Очередь

//Инициализация пустой очереди
void init () {
  for (int i = 0; i < SZ; ++i) {
    arr[i] = NULL;
  }
  head = 0;
  tail = 0;
  items = 0;
}

//Вставка нового элемента
void ins(int pr, int dat) {
  Node *node = (Node*) malloc(sizeof(Node));
  node->dat = dat;
  node->pr = pr;

  if (items == SZ) {
      printf("\nQueue is full\n");
      return;
    }
  else {
      arr[tail++] = node;
      items++;
    }
}

Node* rem() {
  if (items == 0) {
    return NULL;
  }
  else {
    int max_pos;
    Node* max = arr[0];
    for(int i = 1; i < items; i++)
    {
      if(arr[i]->pr > max->pr) {
        max_pos = i;
        max = arr[i];
      }
    }
    for(int i = max_pos; i < items; i++) {
      arr[i] = arr[i+1];
    }
    arr[--items] = NULL;
    tail--;
  }
}

void printQueue() {
  printf("[ ");
  for (int i = 0; i < SZ; ++i) {
    if (arr[i] == NULL)
      printf("[*, *] ");
    else
      printf("[%d, %d] ", arr[i]->pr, arr[i]->dat);
  }
  printf(" ]\n");
}

//Перевод в двоичную систему
void convert2Binary (int number) {
  do {
    push(number % 2);
  } while (number/=2);

  while(cursor != -1)
    printf("%d",pop());
  printf("\n");
}

int main(int argc, char const *argv[]) {

  int  number;

  printf("\nInput number\n<");
  scanf("%d", &number);

  convert2Binary(number);

  init();
  ins(1,5);
  ins(3,7);
  ins(3,7);
  ins(7,7);
  ins(2,5);

  printQueue();

  rem();
  rem();
  rem();

  printQueue();
  ins(12,5);
  printQueue();
  rem();
  printQueue();
  return 0;
}
