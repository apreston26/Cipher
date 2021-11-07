#include <stdio.h>
#include "lcg.h"

#define TRUE 1
#define OFF 0
#define EFLAG 1
#define DFLAG 2

void characterHandler();
int cipherSolver(int m, int c, int flag, int b);

int main()
{
  characterHandler();
  return 0;
}

void characterHandler()
{
  int chars = 0;
  int isLine = 0;
  int lineCounter = 1;
  int dataCounter = 0;
  int flag = OFF;
  int errorFlag = OFF;
  int lcg_m = 0;
  int lcg_c = 0;
  int tempNum = 0;
  int value = 0;
  
  while ((chars = getchar()) != EOF)
    {
      if (chars != ',' && (chars >= '0' && chars <= '9'))
	{
	  tempNum = chars - '0';
	  value = value * 10;
	  value = value + tempNum;
	}
      if (chars == ',')
	{
	  if (lcg_m == 0) lcg_m = value;
	  if (lcg_m != 0) lcg_c = value;
	  value = 0;
	  dataCounter++;
	}
      if (isLine == 0)
        {
	  printf("%5d: ", lineCounter);
	  if (chars == 'e') flag = EFLAG;
	  if (chars == 'd') flag = DFLAG;
          isLine = 1;
        }
      if (dataCounter == 2 && chars != ',')
	{
	  
	}
       putchar(cipherSolver(126,25,flag,chars));
      if (chars == '\n')
        {
	  lcg_m = 0;
	  lcg_c = 0;
	  value = 0;
	  flag = OFF;
          isLine = 0;
	  dataCounter = 0;
          lineCounter++;
	  printf("\n");
        }
    }
  if (errorFlag == TRUE)
    {
      printf("%5d: Error", lineCounter);
    }
}

int cipherSolver(int m, int c, int flag, int b)
{
  struct LinearCongruentialGenerator lcg = makeLCG(m,c);
  int eByte = 0;
  if (flag == EFLAG)
    {
	  unsigned long x = getNextRandomValue(&lcg);
	  eByte = x ^ b;
	  if (eByte < 32)
	    {
	      printf("*");
	      return ('@' + eByte);
	    }
	  if (eByte > 32 && eByte <= 127)
	    {
	      return eByte;
	    }
    }
  return -1;
}
    
    




