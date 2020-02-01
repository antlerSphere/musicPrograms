#include <stdio.h>
#include <string.h>          // strlen()
#define SW 40               // screen width

/* Accordion Bass Chord Chart with mirror 
   image reflection encoded with a 3D array
   v4.0 programmed in C by antlerSphere */

void banner(char *str, int width);
void chartHeader();
int  checkButton(int row, int col);
void newline(int position);
void pipebar(int alignment);
void space();
void plus();
void line();
   
int main()
{
              
//  initialize variables

  int row, col;
  char *pitch = "ADGCFBEADG ";
                         // pitch[0-10]
  char *s_or_f = "#bx ";
                       // s_or_f[0-3]
  char *o7mM = "o7mM ";   
                     // o7mM[0-4]

  char caption[] = "Accordion Bass Chord Chart";

// parallelogram with two blank triangles

int chart[][6][3] = {

{ {0,0,0}, {10,3,4}, {10,3,4},
  {10,3,4}, {10,3,4}, {10,3,4} },

{ {1,0,0}, {0,0,1}, {10,3,4},
  {10,3,4}, {10,3,4}, {10,3,4} },    

{ {2,0,0}, {1,0,1}, {0,0,2},
  {10,3,4}, {10,3,4}, {10,3,4} },
  
{ {3,0,0}, {2,0,1}, {1,0,2},
  {0,0,3}, {10,3,4}, {10,3,4} },
  
{ {4,0,0}, {3,0,1}, {2,0,2},
  {1,0,3}, {0,0,4}, {10,3,4} },
  
{ {5,3,0}, {4,0,1}, {3,0,2},
  {2,0,3}, {1,0,4}, {3,2,4} },

{ {6,3,0}, {5,3,1}, {4,0,2},
  {3,0,3}, {2,0,4}, {4,2,4} },
  
{ {0,3,0}, {6,3,1}, {5,3,2},
  {4,0,3}, {3,0,4}, {5,0,4} },

{ {1,3,0}, {0,3,1}, {6,3,2},
  {5,3,3}, {4,0,4}, {6,0,4} },
  
{ {2,3,0}, {1,3,1}, {0,3,2},
  {6,3,3}, {5,3,4}, {7,0,4} },
  
{ {3,3,0}, {2,3,1}, {1,3,2},
  {0,3,3}, {6,3,4}, {8,0,4} },
  
{ {4,3,0}, {3,3,1}, {2,3,2},
  {1,3,3}, {0,3,4}, {9,0,4} },

{ {5,1,0}, {4,3,1}, {3,3,2},
  {2,3,3}, {1,3,4}, {3,0,4} },

{ {6,1,0}, {5,1,1}, {4,3,2},
  {3,3,3}, {2,3,4}, {4,0,4} }, 

{ {0,1,0}, {6,1,1}, {5,1,2},
  {4,3,3}, {3,3,4}, {5,3,4} },

{ {1,1,0}, {0,1,1}, {6,1,2},
  {5,1,3}, {4,3,4}, {6,3,4} },

{ {2,1,0}, {1,1,1}, {0,1,2},
  {6,1,3}, {5,1,4}, {7,3,4} },

{ {3,1,0}, {2,1,1}, {1,1,2},
  {0,1,3}, {6,1,4}, {8,3,4} },

{ {4,1,0}, {3,1,1}, {2,1,2},
  {1,1,3}, {0,1,4}, {9,3,4} },

{ {5,11,0}, {4,1,1}, {3,1,2},
  {2,1,3}, {1,1,4}, {3,3,4} },

{ {10,3,4}, {5,11,1}, {4,1,2},
  {3,1,3}, {2,1,4}, {4,3,4} },

{ {10,3,4}, {10,3,4}, {5,11,2},
  {4,1,3}, {3,1,4}, {5,1,4} },

{ {10,3,4}, {10,3,4}, {10,3,4},
  {5,11,3}, {4,1,4}, {6,1,4} },

{ {10,3,4}, {10,3,4}, {10,3,4},
  {10,3,4}, {5,11,4}, {7,1,4} },

{ {10,3,4}, {10,3,4}, {10,3,4},
  {10,3,4}, {10,3,4}, {8,1,4} }
          
};

                   
banner(caption, SW);

newline(0);
chartHeader();
newline(0);

for (row=0; row<25; row++)
                         // go through rows
  {        

  pipebar(3);
     
  for (col=0; col<6; col++)
                      // go through columns         
    {  

    if (chart[row][col][1] == 11)
      printf("%1c%c%c%c",
       pitch[ chart[row][col][0] ],
       s_or_f[1], s_or_f[1],        
        o7mM[ chart[row][col][2] ]);
    else if (checkButton(row, col))
      printf("(%c%c)",
       pitch[ chart[row][col][0] ],
      s_or_f[ chart[row][col][1] ]);        
    else
      printf("%2c%c%c",
       pitch[ chart[row][col][0] ],
      s_or_f[ chart[row][col][1] ],
        o7mM[ chart[row][col][2] ]);  

    pipebar(3);
    
    }  // end of column loop

  newline(0);
  chartHeader();
  newline(0);
  
  }  // end of row loop

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
    {
    margin-=1;
    } 
  else
    {
    margin-=2;
    }

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

int checkButton(int row, int col)
{

if ((col == 4) && ( ((row == 10) ||
    (row == 14)) || (row == 18) ))
  return 1;
else
  return 0;
        
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
  printf(" |");
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