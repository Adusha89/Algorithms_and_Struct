#include "stdio.h"
#include "stdbool.h"
#include "string.h"
#include "stdlib.h"


//Хотел сделать шифр перестановкой не через двумерный массив
//но не смог реализовать, если матрица, условно, не полностью заполняется
//В идеальном случае работает, как в видео уроке
//Хотел сделать без дозаполнения случайными символами, но не успел пока
//Не против подсказки в этом напрвлении

//Очистка строки
void clearString(char* inbox) {
  int i = 0, len = strlen(inbox);
  bool flag = false;
  while(inbox[i]) {
    if(!((inbox[i] >= '0' && inbox[i] <= '9')||
        (inbox[i] >= 'a' && inbox[i] <= 'z')||
          (inbox[i] >= 'A' && inbox[i] <= 'Z'))) {
            for(int j = i; j < len; j++) {
              inbox[j] = inbox[j+1];
            }
          }
        else i++;
  }
}

//Шифрование Цезаря
char* encodeCezar(char* inbox, int key) {
  int i = 0, j = 0;
  char* outbox = (char*)malloc(sizeof(char)*strlen(inbox));
  while(inbox[i]) {
    if(inbox[i] >= '0' && inbox[i] <= '9') {
      if(inbox[i] + key > '9') outbox[j++] = '0' + inbox[i++] + key - '9' - 1;
        else outbox[j++] = inbox[i++] + key;
    } else if(inbox[i] >= 'a' && inbox[i] <= 'z') {
        if(inbox[i] + key > 'z') outbox[j++] = 'a' + inbox[i++] + key - 'z' - 1;
          else outbox[j++] = inbox[i++] + key;
    }   else if(inbox[i] >= 'A' && inbox[i] <= 'Z') {
          if(inbox[i] + key > 'Z') outbox[j++] = 'A' + inbox[i++] + key - 'Z' - 1;
            else outbox[j++] = inbox[i++] + key;
    }   else i++;

  }
  outbox[++j] = '\0';
  return outbox;
}

//Расшифровка Цезаря
void decodeCezar(char* inbox, int key) {
  int i = 0;
  while(inbox[i]) {
    if(inbox[i] >= '0' && inbox[i] <= '9') {
      if(inbox[i] - key < '0') inbox[i++] = '9' + inbox[i] - key - '0' + 1;
        else inbox[i++] = inbox[i] - key;
    } else if(inbox[i] >= 'a' && inbox[i] <= 'z') {
        if(inbox[i] - key < 'a') inbox[i++] = 'z' + inbox[i] - key - 'a' + 1;
          else inbox[i++] = inbox[i] - key;
    }   else if(inbox[i] >= 'A' && inbox[i] <= 'Z') {
          if(inbox[i] - key < 'A') inbox[i++] = 'Z' + inbox[i] - key - 'A' + 1;
            else inbox[i++] = inbox[i] - key;
    }

  }
}

//Шифр перестановкой
char* rebaseEncode(char* inbox, int key) {
  int i = 0, j = 0;
  int len = strlen(inbox);
  char* outbox = (char*)malloc(sizeof(char)*len);

  while(i <= key) {
    for(int k = i; k < len; k = k + key + 1) {
      outbox[j++] = inbox[k];
    }
    i++;
  }
  outbox[++j] = '\n';
  return outbox;
}

//Дешифр перестановкой
char* rebaseDecode(char* inbox, int key) {
  int i = 0, j = 0;
  int len = strlen(inbox);
  char* outbox = (char*)malloc(sizeof(char)*len);

  while(i < key) {
    for(int k = i; k < len; k = k + key) {
      outbox[j++] = inbox[k];
    }
    i++;
  }
  return outbox;
}

int main(int argc, char const *argv[]) {

  char message[256];
  int key;

  printf("Input message\n");
  fgets(message, 255, stdin);

  printf("Input key \n<");
  scanf("%d", &key);



  char* code = encodeCezar(message, key);
  printf("%s \n", code);
  decodeCezar(code, key);
  printf("%s \n", code);

  clearString(message);
  char* encode = rebaseEncode(message, key);
  printf("%s \n", encode);
  printf("%s \n", rebaseDecode(encode, key));
  return 0;
}
