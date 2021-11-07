#include "lcg.h"
#include <stdio.h>
#define TRUE 1

struct LinearCongruentialGenerator makeLCG(unsigned long m, unsigned long c);
unsigned long getNextRandomValue(struct LinearCongruentialGenerator* lcg);
int uniquePrimesProduct(int n);

struct LinearCongruentialGenerator makeLCG(unsigned long m, unsigned long c)
{
  struct LinearCongruentialGenerator lcg;
  int p = 0;
  int error = 0;
  lcg.m = m;
  lcg.c = c;
  lcg.x = 0;
  p = uniquePrimesProduct(m);

  if (lcg.m % 4 == 0)
  {
   lcg.a = 1 + 2 * p;
  }
  else
  {
   lcg.a = 1 + p;
  }

  if (lcg.m < 0) error = TRUE;
  if (0 > lcg.a || lcg.a > lcg.m) error = TRUE;
  if (0 >= lcg.c || lcg.c > lcg.m) error = TRUE;

  if (error == TRUE)
  {
    lcg.m = 0;
    lcg.c = 0;
    lcg.a = 0;
    lcg.x = 0;
    p = 0;
  }
  return lcg;
}

unsigned long getNextRandomValue(struct LinearCongruentialGenerator* lcg)
{
  if (lcg->x == 0)
    {
      lcg->x = lcg->c;
      return lcg->x;
    }
  return lcg->x = (lcg->a * lcg->x + lcg->c) % lcg->m;
}

int uniquePrimesProduct(int n)
{
  int tester = 2;
  int product = 1;
  while (TRUE) {
  if ((tester * tester) > n)
    {
      product *=n;
      return product;
    }
  if ((n % tester) == 0)
    {
      product *= tester;
      while ((n % tester) == 0)
	{
	  n = (n / tester);	  
	}
    }
  else 
    {
      tester++;
    }
  }
  return product;
}
