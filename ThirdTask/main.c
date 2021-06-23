#include <stdio.h>
const int sizeX = 5;
const int sizeY = 5;
int map[][5]={{0,0,0,0,0},
{0,0,0,0,0},
{0,0,0,0,0},
{0,0,0,0,1},
{0,0,0,0,0}};
void Binary (int n)
{
  if(n >= 2)
  Binary(n/2);
  printf("%d", n%2);
}

float toPow(float a, int b)
{
  if(b == 1) return a;
  return a * toPow(a, b-1);
}

float toPowFeat(float a, int b)
{
  if (b == 0)
  		return 1;
  	if (b % 2 == 1)
  		return toPowFeat(a, b-1) * a;
  	else {
  		int c = toPowFeat(a, b/2);
  		return c * c;
  	}

}
int routes(int x, int y) {
    if(map[x][y] == 1)
    return 0;
    if((x == 0 && y == 0))
    return 0;
  else if(x == 0 ^ y == 0)
    return 1;
  else
    return routes(x, y-1) + routes(x - 1, y);
}

int main(int argc, char const *argv[]) {
int bin_n;
do {
  printf("Vvedite chislo\n");
  scanf("%d",&bin_n);
} while(bin_n < 0);
Binary(bin_n);
printf("\n");

float a;
int b;
printf("Vvedite osnovanie\n");
scanf("%f",&a);
do {
  printf("Vvedite stepen\n");
  scanf("%d",&b);

} while(b < 0);
if(b == 0) {
  printf("%f v stepeni %d = 1", a, b);
}
else {
  printf("%f\n",toPow(a,b));

  printf("%f\n",toPowFeat(a,b));
}


for (int y = 0; y < sizeY; ++y) {
  for (int x = 0; x < sizeX; ++x) {
    printf("%5d", routes(x, y));
  }
  printf("\n");
}
  return 0;
}
