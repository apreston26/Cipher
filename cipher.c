#include <stdio.h>
#include "lcg.h"

#define TRUE 1
#define OFF 0
#define EFLAG 1
#define DFLAG 2

void characterHandler();
void cipherSolver(int m, int c, int flag, int b);

int main()
{
  /*characterHandler();*/
  cipherSolver(126, 25, 1, 2); 
  return 0;
}
/*
void characterHandler()
{
  int chars = 0;
  int isLine = 0;
  int lineCounter = 1;
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
	}
      if (isLine == 0)
        {
	  printf("%5d: ", lineCounter);
	  if (chars == 'e') flag = EFLAG;
	  if (chars == 'd') flag = DFLAG;
          isLine = 1;
        }
      if (chars == '\n')
        {
	  flag = OFF;
          isLine = 0;
          lineCounter++;
        }

    }
  if (errorFlag == TRUE)
    {
      printf("%5d: Error", lineCounter);
    }
}
*/
void cipherSolver(int m, int c, int flag, int b)
{
  struct LinearCongruentialGenerator lcg = makeLCG(m,c);
  int chars;
  int eByte = 0;
  int dataCounter = 0;
  
   while((chars = getchar()) != '\n')
    { 
      if (chars == ',')
	{
	  dataCounter++;
	}
      if (dataCounter == 2 && chars != ',')
	{
	  unsigned long x = getNextRandomValue(&lcg);
	  eByte = x ^ chars;
	  if (eByte < 32)
	    {
	      printf("*");
	      putchar('@' + eByte);
	    }
	  if (eByte > 32 && eByte <= 127)
	    {
	      putchar(eByte);
	    }
	}
      }
 }





