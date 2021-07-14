#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"

typedef struct NodeStack {
  int dat;
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
bool push(Stack *stack, int value) {
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
int pop(Stack *stack) {
  if(stack->size == 0) {
    printf("Stack is empty \n");
    return -1;
  }
  NodeStack *tmp = stack->head;
  int data = stack->head->dat;
  stack->head = stack->head->next;
  free(tmp);
  stack->size--;
  return data;
}


#define N 6
//const int n = 6;
int matrix[N][N] = {
        {0,1,1,0,0,0},
        {0,0,0,1,1,1},
        {0,0,0,0,0,1},
        {1,0,0,0,0,0},
        {0,0,0,0,0,0},
        {0,0,0,0,1,0},
};

int visited[N] = {0};

void depthTravers(int st) {
  int r;
  Stack *stack = (Stack*)malloc(sizeof(Stack));
  initStack(stack);

  push(stack, st);
  do {
    st = pop(stack);
    printf("%d ", st);
    if(visited[st]) continue;
    visited[st] = 1;

    for(r = 0; r < N; ++r) {
      if (matrix[st][r] == 1 && !visited[r]) {
        push(stack, r);
        visited[r] = 1;
      }
    }

  } while(stack->head != NULL) ;

  // printf("%d ", st);
  // visited[st] = 1;
  // for(r = 0; r < N; ++r) {
  //   if (matrix[st][r] == 1 && !visited[r]) {
  //     depthTravers(r);
  //
  //   }
  // }
}

void resetArr() {
  for (int i = 0; i < N; ++i) {
    visited[i] = 0;
  }
}

int main(int argc, char const *argv[]) {

  Stack *stack = (Stack*)malloc(sizeof(Stack));
  initStack(stack);

  depthTravers(0);
  resetArr();
  printf("\n");
  depthTravers(2);
  resetArr();
  printf("\n");
  depthTravers(1);
  resetArr();
  printf("\n");
  return 0;
}
