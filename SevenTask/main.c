#include <stdio.h>
#include <stdlib.h>

//Подсчет кол-ва четных чисел
int countEven(const int* arr, int len)
{
  int count = 0;
  for(int i = 0; i < len; i++) {
    if(arr[i]%2 == 0) count++;
  }
  return count;
}

//Вычленяем массив четых чисел
void arrEven(int* arr, int* arreven, int len)
{
  int count = 0;
  int countnot = 0;
  for(int i = 0; i < len; i++) {
    if(arr[i]%2 == 0) arreven[count++] = arr[i];
  }
}

//Слияние массивов
void mergeArr(int* arr, int* arreven, int len)
{
  int count = 0;
  for(int i = 0; i < len; i++) {
    if(arr[i]%2 == 0) arr[i] = arreven[count++];
  }
}

//Перемена местами двух элементов
void swapInt(int* a, int* b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

//Заполнение массива случайными числами до m
void randArr(int* arr, int n, int m)
{
  for(int i = 0; i < n; i++)
        arr[i] = rand() % m;
}

//Печать массива
void printArr(int* arr, int n)
{
  for(int i = 0; i < n; i++)
    printf("%4d ", arr[i]);
  printf("\n");
}

//Поиск медианы
void Med(int* a, int* b, int* c)
{
    swapInt(((*a >= *b && *a <= *c) || (*a <= *b && *a >= *c) ? a :
          ((*b >= *a && *b <= *c) || (*b <= *a && *b >= *c) ? b : c)), b);
}

//Быстрая сортировка
void Qs(int* arr, int first, int last)
{
  int i = first;
  int j = last;
  int x = arr[(first + last)/2];
  do {
      while (arr[i] < x) i++;
      while (arr[j] > x) j--;
      if(i <= j) {
        swapInt(&arr[i], &arr[j]);
        i++;
        j--;
      }
  } while (i <= j);
  if(i < last) Qs(arr, i, last);
  if(first < j) Qs(arr, first, j);
}

//Сортировка вставками
void sortInserts(int* arr, int len)
{
  int temp, pos;
  for (int i = 1; i < len; i++) {
      temp = arr[i];
      pos = i - 1;
      while (pos >= 0 && arr[pos] > temp) {
        arr[pos + 1] = arr[pos];
        pos--;
      }
  }
}

//Интерфейс улучшенной сортировки
void sortQ (int* arr, int len)
{
  if(len <=10)
  {
    sortInserts(arr, len);
    return;
  }
  Med(&arr[0], &arr[len/2], &arr[len-1]);
  Qs(arr, 0, len-1);
}

void bucketSort(int* arr, int len)
{
  const int max = len;
  const int b = 10;
  int buckets[b][max+1];
  for(int i = 0; i < b; ++i) {
      buckets[i][max] = 0;
  }

  for(int digit = 1; digit < 1000000000; digit*=10) {
    for (int i = 0; i < max; ++i) {
      int d = (arr[i] / digit) % b;
      buckets[d][buckets[d][max]++] = arr[i];
    }
    int idx = 0;
    for(int i = 0; i < b; ++i) {
      for (int j = 0; j < buckets[i][max]; ++j) {
        arr[idx++] = buckets[i][j];
      }
      buckets[i][max] = 0;
    }
  }
}
int main(int argc, char const *argv[]) {
  int n, option, counteven, *arr, *arreven;

  while(1) {
    printf("Menu:\n");
    printf("1. Qsort\n");
    printf("2. Bucket sort\n");
    printf("0. Exit\n");
    scanf("%d", &option);
    switch (option) {
      case 1:
      printf("Vvedite razmer massiva\n");
      scanf("%d", &n);
      arr = (int*)calloc(n, sizeof(int));
      randArr(arr, n, 125);
      printArr(arr, n);
      sortQ(arr, n);
      printArr(arr, n);
      randArr(arr, n, 125);
      break;

      case 2:
      printf("Vvedite razmer massiva\n");
      scanf("%d", &n);
      arr = (int*)calloc(n, sizeof(int));
      randArr(arr, n, 125);
      printArr(arr, n);
      counteven = countEven(arr, n);
      arreven = (int*)calloc(counteven, sizeof(int));
      arrEven(arr, arreven, n);
      bucketSort(arreven, counteven);
      mergeArr(arr, arreven, n);
      printArr(arr, n);
      randArr(arr, n, 125);
      break;

      case 0:
      free(arreven);
      return 0;

      default:
      printf("Vvod nekorrekten\n");
    }
  }



  return 0;
}
