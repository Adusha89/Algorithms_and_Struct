#include <stdio.h>

#define T int
#define SIZE 1000
#define true 1 == 1
#define false 1 != 1

typedef int boolean;

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

void conver2Binary (int number) {
  do {
    push(number % 2);
  } while (number/=2);

  while(cursor != -1)
    printf("%d",pop());
}

int main(int argc, char const *argv[]) {

  int  number;

  printf("\nInput number\n<");
  scanf("%d", &number);

  conver2Binary(number);
  
  return 0;
}
