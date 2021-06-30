#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <math.h>

typedef enum convert {
  toArr = 1,
  to2Arr
} CONVERT;

//Флаг 1 - Перевод двумерного массива в одномерый
//Флаг 2 - Перевод одномерного массива в двумерный
void arr2Arr(int** arr, int* arr1, int n, int m, CONVERT flag)
{
  int ch = 0;
  if(flag == toArr)
  {
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
      {
        arr1[ch] = arr[i][j];
        ch++;
      }
  }
  if(flag == to2Arr)
  {
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
      {
        arr[i][j] = arr1[ch];
        ch++;
      }
  }
}
//Печать массива
void print2Arr(int** arr, int n, int m)
{
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < m; j++)
      printf("%4d ", arr[i][j]);
    printf("\n");
  }
}
//Заполнение массива случайными числами
void randArr(int** arr, int n, int m)
{
  int raz = n*m;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        arr[i][j] = rand() % raz;
}
//Сортировка массива
void bubbleSort(int** arr, int n, int m)
{
  int* arr1 = (int*) calloc(n*m, sizeof(int));
  arr2Arr(arr, arr1, n, m, toArr);
  int swap = *arr1;
  int raz = n*m;
  for(int i = 0; i < raz; i++)
    for(int j = 1; j < raz - i; j++)
    {
      if(*(arr1 + j) < *(arr1 + j - 1))
      {
        swap = *(arr1 + j);
        *(arr1 + j) = *(arr1 + j - 1);
        *(arr1 + j - 1) = swap;
      }
    }
  arr2Arr(arr, arr1, n, m, to2Arr);
  free(arr1);
}

void trabPradKnut()
{
  const int n = 11;
  int p[n];
  for(int i = 0; i < n; i++)
  {
    printf("Vvedite p[%d]:",i);
    scanf("%d", &p[i]);
  }
  for(int i = 0; i < n; i++)
    printf("%5d", p[i]);
  printf("\n");
  int tmp;
  for(int i = 0; i <= n/2-1; i++)
  {
    tmp = p[n-1-i];
    p[n-1-i] = p[i];
    p[i] = tmp;
  }
  for(int i = 0; i < n; i++)
    printf("%5d", p[i]);
  printf("\n");
  float tpk;
  for(int i = 0; i < n; i++)
  {
    tpk = sqrt(fabs(p[i])) + 5*pow(p[i],3);
    if(tpk > 400)
      printf("Znahenie %f > 400\n", tpk);
  }
}
int main(int argc, char const *argv[]) {

  int row, col;

  printf("Vvedite razmernost massiva:\n");
  printf("n: ");
  scanf("%d", &row);
  printf("m: ");
  scanf("%d", &col);
  int** arr = (int**) calloc(row, sizeof(int*));
  for( int i = 0; i < row; i++)
    arr[i] = (int*) calloc(col, sizeof(int*));
  randArr(arr, row, col);
  print2Arr(arr, row, col);
  bubbleSort(arr, row, col);
  printf("\n");
  print2Arr(arr, row, col);

  trabPradKnut();

  for(int i = 0; i < row; i++)
    free(arr[i]);
  free(arr);
  return 0;
}
