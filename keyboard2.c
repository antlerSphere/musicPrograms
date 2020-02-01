#include <stdio.h>
#define SW 40

/* prints two octaves of a keyboard
  (landscape view)
   programmed in C by antlerSphere */

void topLine();
void blackKeys();
void midLine();
void whiteKeys();
void bottomLine();
void blackKeyEdge();
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

for (i=0; i<2*SW-11; i++)
    putchar('_');      

  newline();
    
}

/*****************************************/

void blackKeys()
{

int i, j, k;
char s_or_f = '#';
char f_or_s = 'b';

  for (i=0; i<5; i++)
  {
  
  pipebar();

for (k=0; k<2; k++)
{
spaces(2);

for (j=0; j<2; j++)
{
  pipebar();
  printf("%c%c%c", f_or_s, s_or_f, f_or_s);
  pipebar();
}
  spaces(2);
  pipebar();
  spaces(2);
for (j=0; j<3; j++)
{
  pipebar();
  printf("%c%c%c", f_or_s, s_or_f, f_or_s);
  pipebar();
}

    if (i%2 == 0)
        { s_or_f = 'b';  f_or_s = '#'; }
      else
        { s_or_f = '#';  f_or_s = 'b'; }      

    spaces(2);
    pipebar();
     
}  // end of k loop

    newline();

  }  // end of i loop

  pipebar();  
    
}

/*****************************************/

void midLine()
{

int i, j;

for(j=0; j<2; j++)
{
  spaces(2);

  for(i=0; i<2; i++)
    blackKeyEdge();

  spaces(2);
  pipebar();
  spaces(2);
  
  for(i=0; i<3; i++)
    blackKeyEdge();

  spaces(2);
  pipebar();
}

newline();
    
}

/*****************************************/

void whiteKeys()
{

int i, j;

  for (j=0; j<2; j++)
  {
    pipebar();
    for(i=0; i<2*SW/4-6; i++)
      printf("%4c|", ' '); 
    
    newline();
  }
    
}

/*****************************************/

void bottomLine()
{

int i, j;

  for (i=0; i<2*SW/4-6; i++)
    {
    pipebar();
    for (j=0; j<4; j++)
      putchar('_');      
    }

   pipebar(); 
   newline();
   putchar('`');

  for (j=0; j<14; j++)
  {  
    for (i=0; i<4; i++)
      putchar('=');

    putchar('\'');
  }
    
}

/*****************************************/

void blackKeyEdge()
{

  printf("\'===\'");
    
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