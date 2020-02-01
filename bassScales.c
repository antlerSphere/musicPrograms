#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SW 40      // screen width

// generates 1 of 42 bass guitar scales
// programmed in C by antlerSphere 
// referenced from www.bigBassTabs.com

/* some enharmonic scales and equivalents:

E#M
F M

Cbm
B m

B#M
C M

Fbm
E m

*/

char checkInput(char pitch[], char s_or_f[], char Mm[], char p, char sf, char cq);
void transpose(char sf, int G[], int D[], int A[], int E[]);
void banner(char str[], int width);
void printFrets(int frets[], char cq);
void newline(int position);
void centerLine(char *str, int width);
void pipebar(int alignment);
void space();
void plus();
void line(int option); // 1 = '-', 2 = '='

int main() {

int i = 0;
char p, sf, cq;
// iterator, pitch, sharp or flat, chord quality

  char caption[4];

  int G[4], D[4], A[4], E[4];
   
  char pitch[] = "ABCDEFG";
                         // pitch[p = 0-6
  char s_or_f[] = "#b ";//            
                       // s_or_f[sf = 0-3]
  char Mm[] = "Mm";   
                     //   Mm[cq = 0-1]

printf("ex. [A-G][#, \' \', b][M, m]\n");
printf("Enter pitch, accidental, type of scale: ");

scanf("%c%c%c", &p, &sf, &cq);

checkInput(pitch, s_or_f, Mm, p, sf, cq);

// to do:
// □ encode more types of scales

caption[0] = p;      // assemble banner
caption[1] = sf;
caption[2] = cq;
caption[3] = '\0';// display chosen scale

banner(caption, SW);
                   
              // encoding and selection
switch(p)    // of Major and minor scales
{           // and their enharmonic 
           // transpositions
case 'A':         
         // negative numbers used as labels
        // for strings, -1 is the unused
       // bass string to aid transposition
      // -5's are skipPrint placeholders

  if (cq == 'M'){
G[0] = -1;
D[0] = -4; D[1] = 4; D[2] = 6; D[3] = 7;
A[0] = -3; A[1] = 4; A[2] = 5; A[3] = 7; 
E[0] = -2; E[1] = -5; E[2] = 5; E[3] = 7;}

  if (cq == 'm'){
G[0] = -1;
D[0] = -4; D[1] = -5; D[2] = 5; D[3] = 7;
A[0] = -3; A[1] = 5; A[2] = 7; A[3] = 8; 
E[0] = -2; E[1] = 5; E[2] = 7; E[3] = 8;} 

  if (sf != ' ')
    transpose(sf, G, D, A, E);   

  break;

  case 'B':

  if (cq == 'M'){
G[0] = -4; G[1] = 1; G[2] = 3; G[3] = 4;
D[0] = -3; D[1] = 1; D[2] = 2; D[3] = 4; 
A[0] = -2; A[1] = -5; A[2] = 2; A[3] = 4;  
E[0] = -1;}

  if (cq == 'm'){
G[0] = -4; G[1] = -5; G[2] = 2; G[3] = 4;
D[0] = -3; D[1] = 2; D[2] = 4; D[3] = 5; 
A[0] = -2; A[1] = 2; A[2] = 4; A[3] = 5;  
E[0] = -1;}

  if (sf != ' ')
    transpose(sf, G, D, A, E);

  break;

  case 'C':

  if (cq == 'M'){
G[0] = -4; G[1] = 2; G[2] = 4; G[3] = 5;
D[0] = -3; D[1] = 2; D[2] = 3; D[3] = 5; 
A[0] = -2; A[1] = -5; A[2] = 3; A[3] = 5;  
E[0] = -1;}

  if (cq == 'm'){
G[0] = -4; G[1] = -5; G[2] = 3; G[3] = 5;
D[0] = -3; D[1] = 3; D[2] = 5; D[3] = 6; 
A[0] = -2; A[1] = 3; A[2] = 5; A[3] = 6;  
E[0] = -1;}

  if (sf != ' ')
    transpose(sf, G, D, A, E);

  break;

case 'D':

  if (cq == 'M'){
G[0] = -4; G[1] = 4; G[2] = 6; G[3] = 7;
D[0] = -3; D[1] = 4; D[2] = 5; D[3] = 7; 
A[0] = -2; A[1] = -5; A[2] = 5; A[3] = 7;  
E[0] = -1;}

  if (cq == 'm'){
G[0] = -4; G[1] = -5; G[2] = 5; G[3] = 7;
D[0] = -3; D[1] = 5; D[2] = 7; D[3] = 8; 
A[0] = -2; A[1] = 5; A[2] = 7; A[3] = 8;  
E[0] = -1;}

  if (sf != ' ')
    transpose(sf, G, D, A, E);

  break;

case 'E':

  if (cq == 'M'){
G[0] = -4; G[1] = 6; G[2] = 8; G[3] = 9;
D[0] = -3; D[1] = 6; D[2] = 7; D[3] = 9; 
A[0] = -2; A[1] = -5; A[2] = 7; A[3] = 9;  
E[0] = -1;}

  if (cq == 'm'){
G[0] = -4; G[1] = -5; G[2] = 7; G[3] = 9;
D[0] = -3; D[1] = 7; D[2] = 9; D[3] = 10; 
A[0] = -2; A[1] = 7; A[2] = 9; A[3] = 10;  
E[0] = -1;}

  if (sf != ' ')
    transpose(sf, G, D, A, E); 
    
  break;

case 'F':

  if (cq == 'M'){
G[0] = -4; G[1] = 7; G[2] = 9; G[3] = 10;
D[0] = -3; D[1] = 7; D[2] = 8; D[3] = 10; 
A[0] = -2; A[1] = -5; A[2] = 7; A[3] = 9;  
E[0] = -1;}

  if (cq == 'm'){
G[0] = -4; G[1] = -5; G[2] = 1; G[3] = 3;
D[0] = -3; D[1] = 1; D[2] = 3; D[3] = 4; 
A[0] = -2; A[1] = 1; A[2] = 3; A[3] = 4;  
E[0] = -1;}

  if (sf != ' ')
    transpose(sf, G, D, A, E);
   
  break;

case 'G':

  if (cq == 'M'){
G[0] = -4; G[1] = 2; G[2] = 4; G[3] = 5;
D[0] = -3; D[1] = 2; D[2] = 3; D[3] = 5; 
A[0] = -2; A[1] = -5; A[2] = 3; A[3] = 5;  
E[0] = -1;}

  if (cq == 'm'){
G[0] = -4; G[1] = -5; G[2] = 3; G[3] = 5;
D[0] = -3; D[1] = 3; D[2] = 5; D[3] = 6; 
A[0] = -2; A[1] = 3; A[2] = 5; A[3] = 6;  
E[0] = -1;}

  if (sf != ' ')
    transpose(sf, G, D, A, E);
  
  break;
           
  }

printFrets(G, cq);   // print ascending
printFrets(D, cq);   // and descending
printFrets(A, cq);   // scales in bass
printFrets(E, cq);   // tablature format

  return 0;

}

/*****************************************/

char checkInput(char pitch[], char s_or_f[], char Mm[], char p, char sf, char cq)

{

int i = 0;

while (i<strlen(pitch))
  {
    if (p == pitch[i])
      break;  // search for pitch  
    i++;
  }

  if ((i == strlen(pitch)) && (p != pitch[i]))    // verify pitch
    {
      printf("\n\nError: invalid pitch entered\n");
      printf("choose from %s\n", pitch); 
      exit(-1);  
    }

i = 0;

while (i<strlen(s_or_f))
  {
    if (sf == s_or_f[i])
      break;  // search for accidental  
    i++;
  }

  if ((i == strlen(s_or_f)) && (sf != s_or_f[i]))   // verify accidental
    {
      printf("\n\nError: invalid accidental entered\n");
      printf("enter # for sharp, b for flat or space for natural");  
      exit(-1);  
    }

i = 0;

while (i<strlen(Mm))
  {
    if (cq == Mm[i])
      break;  // search for chord quality 
    i++;
  }

  if ((i == strlen(Mm)) && (cq != Mm[i]))
    {         // verify chord quality
      printf("\n\nError: invalid chord quality entered\n");
      printf("choose from %s for Major or minor", Mm);  
      exit(-1);  
    }
     
}

/*****************************************/

void transpose(char sf, int G[], int D[], int A[], int E[])
{

int i;

switch (G[0])
   {

   case -1:
   
   if (sf == '#')
    for (i=1; i<4; i++)
      { D[i]++; A[i]++; E[i]++; }

   if (sf == 'b')
    for (i=1; i<4; i++)
      { D[i]--; A[i]--; E[i]--; }
   
   break;
  

  default:
   
   if (sf == '#')    // increase frets +1
    for (i=1; i<4; i++)
      { G[i]++; D[i]++; A[i]++; }

  if (sf == 'b')     // decrease frets -1
    for (i=1; i<4; i++)
      { G[i]--; D[i]--; A[i]--; }  
   
   break;

   }
       
}

/*****************************************/

void printFrets(int frets[], char cq)
{

       // iterators used to adjust symmetry

int i = 0, j = 1, k = 0, l = 0, m = 0;

            // check for double digit frets

  if ((frets[3] > 9) || (frets[2] > 9))
    l = 1;

  if ((frets[3] > 9) && (frets[2] > 9))
    l = 3;

  if (frets[0] == -4)           // G string
    {
    pipebar(0);
    
  if ((frets[1] >= -6) && (frets[1] <= -4))
      {            // skipPrint placeholder
      j++; k = 1;
      } 

  if ((cq == 'M') && (frets[1] == 7))
    m = 2;

  if ((cq == 'M') && (frets[3] == 11))
    m = 2;

  if ((cq == 'm') && (frets[2] == 8))
    m = 1;

  if (l==1)
    line(1);
  for (i=0; i<12+j-m; i++)    
    line(1);      

    for (i=j; i<4; i++) // skip +1 in frets
      printf("%d-", frets[i]);   

    if ((cq == 'm') && (frets[2] == 8))
      printf("");
    else
      for (i=0; i<k; i++)
        line(1);

    pipebar(0);

    if ((cq == 'm') && (frets[2] == 8))
      printf("");
    else
      if (cq == 'm')
        line(1);

   for (i=3; i>j-1; i--)
      printf("-%d", frets[i]);

   if (cq == 'm')
     m = 1;

   if (cq == 'M')
     m = 0;

   if (l==3)
     line(1);  

   if ((cq == 'm') && (frets[2] == 8))
     m = 2;
     
    for (i=0; i<12-l+m; i++)
      line(1);
    pipebar(0);
    }

  if (frets[0] == -3)           // D string
    {
    pipebar(0);
  if ((cq == 'M') && (frets[1] == 8))
    m = -1;

  if (cq == 'm')
    m = 0;

  if ((cq == 'm') && (frets[1] == 8))
    m = 3;

    for (i=0; i<6-l+m; i++)    
      line(1);      

    for (i=1; i<4; i++)
      printf("-%d", frets[i]);   

  if (cq == 'm')
    m = 0;

  if ((cq == 'm') && (frets[1] == 8))
    m = 2;

    for (i=0; i<7-m; i++)
      line(1);

    pipebar(0);

    for (i=0; i<7-m; i++)
      line(1);

    for (i=3; i>0; i--)
      printf("%d-", frets[i]);

    if ((cq == 'm') && (frets[1] == 8))
      m = 3;
    else
      if (cq == 'm') 
        m = 0;
          
    for (i=0; i<5-l+m; i++)
      line(1);
    pipebar(0);
    }

  if (frets[0] == -2)           // A string
    {
    pipebar(0);
  if ((frets[1] >= -6) && (frets[1] <= -4))
      {            // skipPrint placeholder
      if (l==0)
        line(1);
      j++; k = 2;
      }

  if ((cq == 'm') && (frets[1] == 8))
    for (i=j; i<4; i++)
      printf("%d-", frets[i]);   
    else    
      for (i=j; i<4; i++)
        printf("-%d", frets[i]);    
  

    if (cq == 'm')
      m = 1;

    if (cq == 'M')
      m = 0;

    if ((cq == 'm') && (frets[1] == 7))
      m = 0;

    if ((cq == 'm') && (frets[1] == 8))
      m = -1;

    for (i=0; i<12+k+m; i++)
      line(1);

    pipebar(0);

    if ((cq == 'm') && (frets[3] == 10))
      m = 0;

    if (cq == 'M')
      m = 1;

    for (i=0; i<12+m-1; i++)
      line(1);

    for (i=3; i>j-1; i--)
      printf("-%d", frets[i]);

    for (i=0; i<k-l; i++)
      line(1);

    pipebar(0);
    }

  if (frets[0] == -1)  // E string
      centerLine("|", SW);
           // central alignment measure bar

  newline(0);
}

/*****************************************/

void banner(char str[], int width)
{

  int length = strlen(str);
  int i, margin = width/2-length/2;
    
  newline(2);
  for(i=0; i<width-2; i++)
    line(2);
  newline(1);
  
  pipebar(0);
  
  for(i=0; i<margin-1; i++)
   space(); 

  printf("%s", str);    // print scale name

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
  for(i=0; i<width-2; i++)
    line(2);
  newline(1);
     
}

/*****************************************/

void centerLine(char *str, int width)
{

  int length = strlen(str);
  int i, margin = (width/2)-(length/2);
  
  pipebar(0);
  for(i=0; i<margin-1; i++)
   line(1);

  printf("%s", str);
// align center on either open string

  if ((length % 2) == 0)
    margin-=1;
  else
    margin-=2;

    for(i=0; i<margin; i++)
      line(1);

  pipebar(0);  
     
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
  plus();
  printf("\n");
  break;
  
  case 2:
  printf("\n");
  plus();
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
  putchar('|');
  space();
  break;

  case 2:
  space();
  putchar('|');
  space();
  break;
  
  case 3:
  space();
  space();
  putchar('|');
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

void line(int option)
{
  if (option == 1)
    putchar('-');

  if (option == 2)
    putchar('=');      
}

/*****************************************/