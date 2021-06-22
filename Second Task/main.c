#include <stdio.h>
#include <math.h>
 int is_Simple(int n)
 {
   int flag = 1;
   int sqrtn = sqrt(n);
   for(int i = 2; i <= sqrtn; i++)
   {
     if(n%i == 0)
     {
       flag = 0;
       break;
     }
   }
   return flag;
 }

int main(int argc, char const *argv[]) {
  int n;
  do {
    printf("Vvedite chislo bolshe 1\n");
    scanf("%d", &n);
  } while(n <= 1);
  int flag = is_Simple(n);

  if(flag)
  printf("Chislo %d prostoe\n", n);
  else printf("Chislo %d ne prostoe\n", n);

  return 0;
}
