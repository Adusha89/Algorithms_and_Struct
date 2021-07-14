#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "stdbool.h"

#define COUNTTREE 50
#define COUNTNODE 10000

//Узел дерева
typedef struct Node {
  int key;
  struct Node *left;
  struct Node *right;
} TreeNode;

//Вставка узла
TreeNode* treeInsert(TreeNode *t, int data) {
  TreeNode *newNode;
  newNode = (TreeNode*) malloc(sizeof(TreeNode));
  newNode->key = data;
  newNode->left = NULL;
  newNode->right = NULL;
  TreeNode *current = t;
  TreeNode *parrent = t;
  if(t == NULL) {
    t = newNode;
  } else {
    while (current->key != data) {
      parrent = current;
      if (current->key > data) {
        current = current->left;
        if (current == NULL) {
          parrent->left = newNode;
          return t;
        }
      } else {
        current = current->right;
        if (current == NULL) {
          parrent->right = newNode;
          return t;
        }
      }
    }
  }
  return t;
}

//Печать дерева
void printTree(TreeNode *root) {
  if (root) {
    printf("%d", root->key);
    if (root->left || root->right) {
      printf("(");
      if(root->left)
        printTree(root->left);
      else
        printf("NULL");
      printf(",");
      if(root->right)
        printTree(root->right);
      else
        printf("NULL");
      printf(")");
    }
  }
}

//Создание массива из 50 деревьев
void createArrTree(TreeNode** arr)
{
  srand (time(NULL));

  for(int i = 0; i < COUNTTREE; i++) {
    arr[i] = treeInsert(NULL,rand()%COUNTNODE);
    for(int j = 1; j < COUNTNODE; j++) {
      treeInsert(arr[i], (rand()%COUNTNODE));
    }
  }
}

//Определение max
int max(int a, int b) {
  return (a > b) ? a : b;
}

//Высота дерева
int heightTree(TreeNode* root) {
  if (root == NULL)
    return 0;

  return 1 + max(heightTree(root->left), heightTree(root->right));
}

//Проверка на балансировку
bool isBalanceTree(TreeNode* root) {
  int leftheight, rightheight;

  if(root == NULL)
    return true;

  leftheight = heightTree(root->left);
  rightheight = heightTree(root->right);

  if(abs(leftheight - rightheight) <= 1 && isBalanceTree(root->left) && isBalanceTree(root->right))
    return true;

  return false;
}

//Процент балансированных деревьев
void percentBalance(TreeNode** arr) {
  float count = 0;

  for(int i = 0; i < COUNTTREE; i++) {
    if(isBalanceTree(arr[i])) count++;
    // printTree(arr[i]);
    // printf("\n");
  }

  printf("%.20f%% \n", (count/COUNTTREE)*100);
}

//Бинарный поиск
TreeNode* binaryFind(TreeNode* root, int find) {
  if(root == NULL)
    return NULL;
  if(root->key == find)
    return root;

  if(find < root->key) {
    binaryFind(root->left, find);
  } else {
      binaryFind(root->right, find);
  }
}

int main(int argc, char const *argv[]) {


  TreeNode** arr = (TreeNode**)malloc(sizeof(TreeNode)*COUNTTREE);

  createArrTree(arr);
  percentBalance(arr);
  TreeNode* temp = binaryFind(arr[1], 3);
  (temp != NULL) ? printf("Node Find \n") : printf("Node not find \n");
  return 0;
}
