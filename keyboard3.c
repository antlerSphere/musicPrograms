#include <stdio.h>
#define SW 40

/* displays two octaves of a piano keyboard 
  (landscape view)
   programmed in C by antlerSphere */

void topLine();
void blackKeys(int height);
void drawBlackKeys(int numKeys, char fs, char sf);
void midLine();
void blackKeyFronts(int numKeys);
void whiteKeys(int height);
void bottomLine();
void whiteKeyFronts(int numKeys);
void spaces(int num);
void pipebar();
void newline();

int main() 
{

  topLine();
  blackKeys(6);
  midLine();
  whiteKeys(2); 
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

void blackKeys(int height)
{

int i, j;
char sf = '#';  // sharp or flat
char fs = 'b';  // flat or sharp

  for (i=0; i<height; i++)
  {
  
    pipebar();

    for (j=0; j<2; j++)
    {

    spaces(2);

    drawBlackKeys(2, fs, sf);

    spaces(2);
    pipebar();
    spaces(2);

    drawBlackKeys(3, fs, sf);

    if (i%2 == 0)    // alternate pattern
        { sf = 'b';  fs = '#'; }
      else
        { sf = '#';  fs = 'b'; }      

    spaces(2);
    pipebar();
     
    }  // end of j loop

    newline();

  }  // end of i loop

  pipebar();  
    
}

/*****************************************/

void drawBlackKeys(int numKeys, char fs, char sf)
{

int i;

  for (i=0; i<numKeys; i++)
  {
    pipebar();
    if (i%2 == 0)
      printf("%c%c%c", fs, sf, fs);
    else
      printf("%c%c%c", sf, fs, sf);
    pipebar();
  }   
    
}

/*****************************************/

void midLine()
{

int i;

  for(i=0; i<2; i++)
  {
    spaces(2);

    blackKeyFronts(2);

    spaces(2);
    pipebar();
    spaces(2);
  
    blackKeyFronts(3);

    spaces(2);
    pipebar();
  }

newline();
    
}

/*****************************************/

void blackKeyFronts(int numKeys)
{

int i;

  for(i=0; i<numKeys; i++)
    printf("\'===\'");
    
}

/*****************************************/

void whiteKeys(int height)
{

int i, j;

  for (j=0; j<height; j++)
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
  whiteKeyFronts(14);
    
}

/*****************************************/

void whiteKeyFronts(int numKeys)
{

int i, j, width = 4;
char fwdSlash = '/';
  
  spaces(1);  
  putchar('\\');

  for (j=0; j<numKeys/2-1; j++)
  {  
    for (i=0; i<width; i++)
      putchar('_');

    putchar('\\');
  }  

  width = 3;

  for (j=0; j<numKeys/2+1; j++)
  {  
    for (i=0; i<width; i++)
      putchar('_');
    
    switch (j)
    {
      case 0:
        pipebar();
        width = 3;
        break;

      case 1:
        width = 4;
        break; 
    
      case 2:
        width = 3;
        break;
        
      case 3:
        width = 4;
        break;

      case 4:
        width = 4;
        break;

      case 5:
        width = 3;
        break;

      default:
        break;    
    }

    if (j!=0)
      printf("%s", &fwdSlash);

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