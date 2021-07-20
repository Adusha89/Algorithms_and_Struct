#include "stdio.h"
#include "stdbool.h"
#include "stdlib.h"


typedef struct {
    char* data;
    int key;
} KeyNode;

KeyNode** hashTable;
int hashTableSize;

KeyNode *nullItem;

//Итоговая сумма монет
#define FINALSUM 98

//Массив номиналов
int nominal[] = {50, 10, 5, 2, 1};

//Жадный алгоритм
void Greed () {
  int sum = 0, i = 0, count = 0;

  while (sum != FINALSUM) {
    if(sum + nominal[i] <= FINALSUM) {
      sum += nominal[i];
      count++;
    }
    else i++;
  }

  printf("Minimal coin is: %d \n", count);
}

int hash (char* str) {
  int i = 0, hashkey = 0;

  while(str[i]) {
    hashkey += (int)str[i++];
  }

  return hashkey;
}

// KeyNode* createNode(char* data) {
//   KeyNode *p = (KeyNode*) malloc(sizeof(KeyNode));
//   if(!p) {
//     printf("Out of memmory \n");
//     return NULL;
//   }
//   p->data = data;
//   p->key = hash(data);
//   return p;
// }
//
// void initTable(int size, int idx) {
//   for (int i = idx; i < size; ++i) {
//     hashTable[i] = NULL;
//   }
// }
//
//
//
// bool insertNode(char* data) {
//   KeyNode *node = createNode(data);
//   if(!node) return false;
//
//   int hashVal = node->key;
//   if(isFull()) increaseCapacity();
//
//   hashTable[hashVal] = node;
//   return true;
// }

int main(int argc, char const *argv[]) {

  Greed();

  return 0;
}
