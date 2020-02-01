#include <stdio.h>
#define SW 40

/* prints one octave of a keyboard
  (portrait view)
   programmed in C by antlerSphere */

void topLine();
void blackKeys();
void midLine();
void whiteKeys();
void bottomLine();
void plus();
void spaces(int num);
void pipebar();
void newline();

int main() 
{

  topLine();
  blackKeys();
  midLine();
  whiteKeys(); 
  bottomLine();

return 0;

}

/*****************************************/

void topLine()
{

int i;

spaces(1);

for (i=0; i<SW-6; i++)
    putchar('_');      

  newline();
    
}

/*****************************************/

void blackKeys()
{

int i;
char s_or_f = '#';
char f_or_s = 'b';

  for (i=0; i<5; i++)
  {
    printf("|  |%c%c%c||%c%c%c|  |  |%c%c%c||%c%c%c||%c%c%c|  |", f_or_s, s_or_f, f_or_s, s_or_f, f_or_s, s_or_f, f_or_s, s_or_f, f_or_s, s_or_f, f_or_s, s_or_f, f_or_s, s_or_f, f_or_s);
      if (i%2 == 0)
        { s_or_f = 'b';  f_or_s = '#'; }
      else
        { s_or_f = '#';  f_or_s = 'b'; }      

    newline();
  }

  pipebar();
  spaces(1);  
    
}

/*****************************************/

void midLine()
{

  spaces(1);   
  printf("'===''==='  |  '===''===''==='  |"); 
    newline();
    
}

/*****************************************/

void whiteKeys()
{

int i, j;

  for (j=0; j<2; j++)
  {
    for(i=0; i<SW/4-2; i++)
      printf("|%4c", ' '); 
    newline();
  }
    
}

/*****************************************/

void bottomLine()
{

int i, j;

  for (i=0; i<SW/4-3; i++)
    printf("|____");     

   pipebar(); 
   newline();
   putchar('`');

  for (j=0; j<7; j++)
  {  
    for (i=0; i<4; i++)
      putchar('=');

    putchar('\'');
  }
    
}

/*****************************************/

void spaces(int num)
{

int i;

  for (i=0; i<num; i++)    
    putchar(' ');   
    
}

/*****************************************/

void pipebar()
{
      
  putchar('|');
      
}

/*****************************************/

void newline()
{
    
  putchar('\n');   
    
}

/*****************************************/