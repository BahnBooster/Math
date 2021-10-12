//------Preamble------//

/*
Legal information:

Copyright (c) 2021 Christian Strasser
All rights reserved.

This source code is licensed under the Clear BSD License found in the
LICENSE file in the root directory of this project.

Description:

This is a prime number generator. The purpose is to get the prime numbers from 2 to MAX.

How does it work?
The program iterates (+step size 1) a counter (i) from 0 to MAX. The first prime number is given (2).
From there the program checks the current step to be prime.

How exactly?
For each step i, the modulo operation is performed on i and each previously found prime number, j. If i mod j ever
returns a remainder of 0, it is known that i is not prime! If i mod j returns a remainder, then i mod (j-1) is checked.
This continues for each previously found prime number, until a remainder of 0 is returned, or all the numbers have been
checked. If i is determined to be prime, it is saved, and the process repeats for (i + 1), up until i = MAX

ROW determines the count of prime numbers for each line.
LAST determines the count of the last prime numbers you want to see (0 for all).
*/

//------Include of libraries------//
#include <stdio.h>

//------Symbolic constants and macros------//
#define MAX 7919U
#define ROW 10U
#define LAST 0U

#if MAX <= 1
#error "MAX has to be greater than 1!"
#endif

#if MAX >= 10090 && ROW > 1
#error "For prime numbers > 10000: Please compile with ROW 1U!"
#endif

#if MAX >= 100003
#warning "For prime numbers > 100000: Please alter the layout!"
#endif

#if ROW <= 0
#error "ROW has to be greater than 0!"
#endif

//------Main function (program)------//
int main(void)
{
  unsigned int i = 0;
  unsigned int j = 0;
  
  unsigned int r = 0;
  
  unsigned int p = 0; //Real count of prime numbers
  unsigned int prime[MAX];
  
  float progress = 0;
  float step = 0;

  //First prime number
  prime[p] = 2;
  
  //2 | for each % progress
  step = (float) MAX / 50;
  progress = step;
  
  if (step <= 1)
  {
    progress = 100;
  }
  
  
  printf("\nComputing prime numbers...\n");
  printf("-----------1----------------------50----------------------100\n");
  printf("Progress...");
  
  //Computing prime numbers
  while (i <= MAX)
  {
    
    if ((float) i + 1 >= progress && step > 1)
    {
      printf("|");
      progress += step;
      fflush(stdout);
    }
    else if (step <= 1 && progress == 100)
    {
      printf("||||||||||||||||||||||||||||||||||||||||||||||||||");
      progress += step;
      fflush(stdout);
    }
    
    if (i > prime[p])
    {
      j = p;
      while (j > 0)
      {
        if (i % prime[j] == 0)
          break;
        j--;
      }
      if (j == 0 && i % prime[j] != 0)
      {
        p++;
        prime[p] = i;
      }
    }
    i++;
  }
  printf("\n-------------------------------------------------------------");
  printf("\n\n");
  printf("|----------------|");
  
  r = 0;
  while (r < ROW)
  {
    printf("-----");
    r++;
  }
  
  printf("-|\n|  Prime number  |");
  r = 0;
  while (r < ROW)
  {
    printf("     ");
    r++;
  }
  printf(" |\n|----------------|");
  
  r = 0;
  while (r < ROW)
  {
    printf("-----");
    r++;
  }
  printf("-|\n");
  
  //Print prime numbers
  j = 0;
  if (LAST > 0 &&  LAST <= MAX)
  {
    j = p - (LAST - 1);
  }
  
  while (j <= p)
  {
    r = 0;
    printf("|  %4d to %4d  |",j+1, j+ROW);
    while (r < ROW)
    {
      printf("%5d", prime[j]);
      r++;
      j++;
      if (j > p)
      {
        while (r < ROW)
        {
          printf("     ");
          r++;
        }
      }
    }
    printf(" |\n");
  }
  printf("|----------------|");
  
  r = 0;
  while (r < ROW)
  {
    printf("-----");
    r++;
  }
  printf("-|\n");
  
  return 0;
}
//------Functions------//
/*none*/
