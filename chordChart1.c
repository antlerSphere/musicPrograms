#include <stdio.h>
#include <string.h>
#define SW 40    // screen width

//  accordion chord chart, mirror reflected
//  Added banner and functions, realigned 
//  partially modularized functions
//  chordchart2.c has improved checks
//  programmed in C by antlerSphere 

void banner(char *str, int width);
void chartHeader();
void newline(int position);
void pipebar(int alignment);
void space();
void plus();
void line();

   
int main()
{
              
//  initialize variables
  int h = 0, i = 0, j = 0;
  int col, row;
  char *pitch = "ADGCFBEADG";
                         // pitch[h = 0-6,
  char *s_or_f = "#bx ";//            h+3]
                       // s_or_f[i = 0-3]
  char *o7mM = "o7mM ";   
                     //   o7mM[j = 0-4]

  
banner("Accordion Bass Chord Chart", SW);


  for (row=0; row<20; row++)
                         // go through rows
    {         

chartHeader();
newline(0);
pipebar(2);

      for (col=0; col<6; col++)
                      // go through columns
        { 

        if ((row >= 0) && (row <= 4))
          i = 0;           // make it sharp

        if ((row >= 5) && (row <= 11))
                           // pitch without
          i = 3;           // an accidental
          
        if ((row >= 12) && (row <= 18))
          i = 1;                                     
         // make it flat


        if ((col >= 0) && (col <= 3))
           j = col;
        // shift chord quality with column
        else
          j = 4;
        // except for the bass note columns

     
    if (col < 5)// not yet the last column?
    {
     if (row == 19)
     {
     // lastly print double flat row..
        if (col == 0)
            printf("%c%c%c%c%c", pitch[h], s_or_f[1], s_or_f[1], o7mM[j], ' ');
        if (col >= 1)
            printf("%2c%c%c%c%c", pitch[h], s_or_f[1], s_or_f[1], o7mM[j], ' '); 
          
     }
     else
     
     // ..or print current lined up chord
           {
    // show button indentations with ( )
if ((col == 4) && ((row == 6) ||
(row == 10) || (row == 14)))
      printf("%c%c%c%s", '(', pitch[h], s_or_f[i], ")  "); 
else
    if (i == 3)
//  adjust spacing if there's no accidental 
             printf("%c%c%c%3c", pitch[h], s_or_f[i], o7mM[j], ' '); 
      else
        if (i == 0)
        // adjust spacing for sharp
             printf("%c%c%c%3c", pitch[h], s_or_f[i], o7mM[j], ' ');
           else
             printf("%c%c%c%3c", pitch[h], s_or_f[i], o7mM[j], ' '); 
           
           }
    }
     else 
      // exception handling for last column
    {      // print double sharp exceptions
    if ((col == 5) && (row == 0))
       printf("%c%c", pitch[h+3], s_or_f[2]);
    if ((col == 5) && (row == 1))
      printf("%c%c", pitch[h+3], s_or_f[2]);
     
    // print a sharp for upper bass notes    
    if ((row >= 2) && (row <= 8))
    {
      if ((row >= 2) && (row <= 4))
        printf("%c%c", pitch[h+3], s_or_f[0]);
      else
        printf("%c%c", pitch[h+3], s_or_f[0]); 
    }
   
   // print the pitch for middle bass notes
    if ((row >= 9) && (row <= 15))
      printf(" %c", pitch[h+3]);

    // print a flat for lower bass notes
    if ((row >= 16) && (row <= 18))
      printf("%c%c", pitch[h+3], s_or_f[1]);

    if (row == 19)
      printf(" %c%c", pitch[h+3], s_or_f[1]);
    
    }
    // end of exception handling else block
    
        }  // end of column for loop

pipebar(3); 
newline(0);

h++;
// rotate through pitches to print chart

if (h == 7)
   h = 0;
   
    }     // end of row for loop

chartHeader();

return 0;
}

/*****************************************/

void banner(char *str, int width)
{
  int length = strlen(str);
  int i, margin = width/2-length/2;
  
  
  newline(2);
  for(i=0; i<width-3; i++)
    line();
  newline(1);
  
  pipebar(0);
  
  for(i=0; i<margin-2; i++)
   space();

  printf("%s", str);

  if (length % 2 == 0)
  { margin-=1;
  } else {
    margin-=2; }

    for(i=0; i<margin; i++)
      space();

  pipebar(0);

  newline(2);
  for(i=0; i<width-3; i++)
    line();
  newline(1);
     
}

/*****************************************/

void chartHeader()
{

int loop, pool;

space();   
plus();

for (pool=0;pool<6;pool++)
  {
  for (loop=0;loop<5;loop++)
    line();
  plus();
  }   
    
}

/*****************************************/

void newline(int position)
{

switch (position)
  {
  
  case 0:    
  printf("\n");
  break;
  
  case 1:
  printf("+\n");
  break;
  
  case 2:
  printf("\n+");
  break;
  
  default:
  break; 

  }
    
}

/*****************************************/

void pipebar(int alignment)
{

switch (alignment)
  {
     
  case 0:
  putchar('|');
  break;

  case 1:
  printf("| ");
  break;

  case 2:
  printf(" | ");
  break;
  
  case 3:
  printf("  |");
  break;  

  default:
  break;
    
  }

}

/*****************************************/

void space()
{
    
putchar(' ');   
    
}

/*****************************************/

void plus()
{
    
putchar('+');  
    
}

/*****************************************/

void line()
{
    
putchar('=');   
    
}

/*****************************************/