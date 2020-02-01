#include <stdio.h>     // printf()
#include <stdlib.h>   // exit() on error
#include <ctype.h>   // toupper()
#include <string.h> // strlen()
#define SW 65      // screen width

/* generates two octaves (landscape view)
   from 1 out of 42 guitar scales
   programmed in C by antlerSphere 
   referenced from www.guitaristSource.com

format: [A-G | a-g][#|' '|b][M | m]
ex. A M   GbM   a#m   Fbm   bbM

enharmonic equivalents and the scales:
ex.
E#M      |  M|  m| #M| #m| bM| bm|  
F M     -+---+---+---+---+---+---|
        A| X | X | X | X | X | X |
        -+---+---+---+---+---+---| 
Cbm     B| X | X | X | X | X | X |
B m     -+---+---+---+---+---+---|
        C| X | X | X | X | X | X |
Abm     -+---+---+---+---+---+---|
G#m     D| X | X | X | X | X | X |
        -+---+---+---+---+---+---|
B#M     E| X | X | X | X | X | X |
C M     -+---+---+---+---+---+---|
        F| X | X | X | X | x | X |
        -+---+---+---+---+---+---|       
Fbm     G| X | X | X | X | X | X |
E m     -+---+---+---+---+---+---+
      X = referenced with website
          and tested on guitar
      x = offset alignment
*/

int checkInput(char pitch[], char s_or_f[], char Mm[], char p, char sf, char cq);
void transpose(char sf, int e[], int B[], int G[], int D[], int A[], int E[]);
void banner(char str[], int width);
void printFrets(int frets[], char cq);
void newline(int position);
void centerLine(char *str, int width);
void pipebar(int alignment);
void space();
void plus();
void line(int option); // 1 = '-', 2 = '='

int aString[3];  // global int arrays used
int gString[3];  // to adjust spacing
                 // when frets[0] == -2
                 // or frets[0] == -4
int main() {

int adj = 0;
char p, sf, cq;
// screen width adjustment
// pitch, sharp or flat, chord quality

  char caption[4];

  int e[4], B[4], G[4], D[4], A[4], E[4];
  
  char pitch[] = "ABCDEFG";
                         // pitch[p = 0-6]
  char s_or_f[] = "#b ";//           
                       // s_or_f[sf = 0-2]
  char Mm[] = "Mm";  
                     // Mm[cq = 0-1]

printf("ex. [A-G | a-g][#| \' \' |b][M | m]\n");
printf("Enter pitch, accidental, tonality of scale: ");

scanf("%1c%1c%1c", &p, &sf, &cq);

p = toupper(p);  // capitalize first entry

adj = checkInput(pitch, s_or_f, Mm, p, sf, cq);                       // string
                          // index
e[0] = -6; B[0] = -5; G[0] = -4;
D[0] = -3; A[0] = -2; E[0] = -1;

caption[0] = p;       //  assemble banner
caption[1] = sf;
caption[2] = cq;
caption[3] = '\0'; // end string with null
                  // display scale title 
banner(caption, SW+adj);

                              
              // encoding and selection
switch(p)    // of Major and minor scales
{           // and their enharmonic
           // transpositions
case 'A':        
         // negative numbers used as
        // labels for strings, -5's are
       // skipPrint placeholders

  if (cq == 'M')
  {
    e[1] = -5; e[2] = 4; e[3] = 5;
    B[1] = -5; B[2] = 5; B[3] = 7;
    G[1] = 4; G[2] = 6; G[3] = 7;
    D[1] = 4; D[2] = 6; D[3] = 7;
    A[1] = 4; A[2] = 5; A[3] = 7;
    E[1] = -5; E[2] = 5; E[3] = 7;
  }

  if (cq == 'm')
  {
    e[1] = -5; e[2] = 3; e[3] = 5;
    B[1] = -5; B[2] = 5; B[3] = 6;
    G[1] = 4; G[2] = 5; G[3] = 7;
    D[1] = 3; D[2] = 5; D[3] = 7;
    A[1] = 3; A[2] = 5; A[3] = 7;
    E[1] = -5; E[2] = 5; E[3] = 7;
  }

  break;

  case 'B':

  if (cq == 'M')
  {
    e[1] = -5; e[2] = 6; e[3] = 7;
    B[1] = -5; B[2] = 7; B[3] = 9;
    G[1] = 6; G[2] = 8; G[3] = 9;
    D[1] = 6; D[2] = 8; D[3] = 9;
    A[1] = 6; A[2] = 7; A[3] = 9;
    E[1] = -5; E[2] = 7; E[3] = 9;
  }

  if (cq == 'm')
  {
    e[1] = -5; e[2] = 5; e[3] = 7;
    B[1] = -5; B[2] = 7; B[3] = 8;
    G[1] = 6; G[2] = 7; G[3] = 9;
    D[1] = 5; D[2] = 7; D[3] = 9;
    A[1] = 5; A[2] = 7; A[3] = 9;
    E[1] = -5; E[2] = 7; E[3] = 9;
  }

  break;

  case 'C':

  if (cq == 'M')
  {
    e[1] = -5; e[2] = 7; e[3] = 8;
    B[1] = -5; B[2] = 8; B[3] = 10;
    G[1] = 7; G[2] = 9; G[3] = 10;
    D[1] = 7; D[2] = 9; D[3] = 10;
    A[1] = 7; A[2] = 8; A[3] = 10;
    E[1] = -5; E[2] = 8; E[3] = 10;
  }

  if (cq == 'm')
  {
    e[1] = -5; e[2] = 6; e[3] = 8;
    B[1] = -5; B[2] = 8; B[3] = 9;
    G[1] = 7; G[2] = 8; G[3] = 10;
    D[1] = 6; D[2] = 8; D[3] = 10;
    A[1] = 6; A[2] = 8; A[3] = 10;
    E[1] = -5; E[2] = 8; E[3] = 10;
  }

  break;

case 'D':

  if (cq == 'M')
  {
    e[1] = -5; e[2] = 9; e[3] = 10;
    B[1] = -5; B[2] = 10; B[3] = 12;
    G[1] = 9; G[2] = 11; G[3] = 12;
    D[1] = 9; D[2] = 11; D[3] = 12;
    A[1] = 9; A[2] = 10; A[3] = 12;
    E[1] = -5; E[2] = 10; E[3] = 12;
  }

  if (cq == 'm')
  {
    e[1] = -5; e[2] = 8; e[3] = 10;
    B[1] = -5; B[2] = 10; B[3] = 11;
    G[1] = 9; G[2] = 10; G[3] = 12;
    D[1] = 8; D[2] = 10; D[3] = 12;
    A[1] = 8; A[2] = 10; A[3] = 12;
    E[1] = -5; E[2] = 10; E[3] = 12;
  }

  break;

case 'E':

  if (cq == 'M')
  {
    e[1] = -5; e[2] = 11; e[3] = 12;
    B[1] = -5; B[2] = 12; B[3] = 14;
    G[1] = 11; G[2] = 13; G[3] = 14;
    D[1] = 11; D[2] = 13; D[3] = 14;
    A[1] = 11; A[2] = 12; A[3] = 14;
    E[1] = -5; E[2] = 12; E[3] = 14;
  }

  if (cq == 'm')
  {
    e[1] = -5; e[2] = 10; e[3] = 12;
    B[1] = -5; B[2] = 12; B[3] = 13;
    G[1] = 11; G[2] = 12; G[3] = 14;
    D[1] = 10; D[2] = 12; D[3] = 14;
    A[1] = 10; A[2] = 12; A[3] = 14;
    E[1] = -5; E[2] = 12; E[3] = 14;
  }
   
  break;

case 'F':

  if (cq == 'M')
  {
    e[1] = -5; e[2] = -5; e[3] = 1;
    B[1] = 1; B[2] = 3; B[3] = 5;
    G[1] = -5; G[2] = 2; G[3] = 3;
    D[1] = 2; D[2] = 3; D[3] = 5;
    A[1] = 1; A[2] = 3; A[3] = 5;
    E[1] = 1; E[2] = 3; E[3] = 5;
  }

  if (cq == 'm')
  {
    e[1] = -5; e[2] = -5; e[3] = 1;
    B[1] = 1; B[2] = 2; B[3] = 4;
    G[1] = -5; G[2] = 1; G[3] = 3;
    D[1] = 1; D[2] = 3; D[3] = 5;
    A[1] = 1; A[2] = 3; A[3] = 4;
    E[1] = 1; E[2] = 3; E[3] = 4;
  }
  
  break;

case 'G':

  if (cq == 'M')
  {
    e[1] = -5; e[2] = 2; e[3] = 3;
    B[1] = -5; B[2] = 3; B[3] = 5;
    G[1] = 2; G[2] = 4; G[3] = 5;
    D[1] = 2; D[2] = 4; D[3] = 5;
    A[1] = 2; A[2] = 3; A[3] = 5;
    E[1] = -5; E[2] = 3; E[3] = 5;
  }

  if (cq == 'm')
  {
    e[1] = -5; e[2] = 1; e[3] = 3;
    B[1] = -5; B[2] = 3; B[3] = 4;
    G[1] = 2; G[2] = 3; G[3] = 5;
    D[1] = 1; D[2] = 3; D[3] = 5;
    A[1] = 1; A[2] = 3; A[3] = 5;
    E[1] = -5; E[2] = 3; E[3] = 5;
  }
 
  break;
          
  }
                     // transpose up or
if (sf != ' ')       // down if # or b
{
  transpose(sf, e, B, G, D, A, E);
}

printFrets(e, cq);   // print ascending
printFrets(B, cq);   // and descending
printFrets(G, cq);   // scales in guitar
printFrets(D, cq);   // tablature format
printFrets(A, cq);  
printFrets(E, cq);  
// centerLine("|", SW+adj+1); // alignment

  return 0;

}

/****************************************/

int checkInput(char pitch[], char s_or_f[], char Mm[], char p, char sf, char cq)

{

int i = 0;
int adjust = 0;

// search for pitch
while (i<strlen(pitch))
  {
    if (p == pitch[i])
    {
      break;
    } 
    i++;
  }

// verify pitch
  if ( (i == strlen(pitch)) &&
      (p != pitch[i]) )
    {
      printf("\n\nError: invalid pitch \'%c\' entered\n", p);
      printf("choose from %s\n", pitch);
      exit(-1); 
    }

i = 0;

// search for accidental
while (i<strlen(s_or_f))
  {
    if (sf == s_or_f[i])
    {
      break;
    }
    i++;
  }

// verify accidental
  if ( (i == strlen(s_or_f)) &&
       (sf != s_or_f[i]) )
    {
      printf("\n\nError: invalid accidental \'%c\' entered\n", sf);
      printf("choose from # for sharp, b for flat or space for natural\n"); 
      exit(-1); 
    }

i = 0;

// search for chord quality
while (i<strlen(Mm))
  {
    if (cq == Mm[i])
    {
      break;
    }
    i++;
  }

// verify chord quality
  if ((i == strlen(Mm)) && (cq != Mm[i]))
    {
      printf("\n\nError: invalid chord quality \'%c\' entered\n", cq);
      printf("choose from M or m for Major or minor\n"); 
      exit(-1); 
    }

// center banner title based on width
if ((p == 'C') && (sf == 'b'))
{
  return adjust;
}

if ( ((p >= 'C') && (p <= 'E')) ||
     ((p == 'B') && (sf == '#')) )
{
  return 8;
}

return adjust;
    
}

/****************************************/

void transpose(char sf, int e[], int B[], int G[], int D[], int A[], int E[])
{

int i;
  
   if (sf == '#') {
    for (i=1; i<4; i++)
      { e[i]++; B[i]++; G[i]++;
        D[i]++; A[i]++; E[i]++; }
                  }

   if (sf == 'b') {
    for (i=1; i<4; i++)
      { e[i]--; B[i]--; G[i]--;
        D[i]--; A[i]--; E[i]--; }
                  }
      
}

/****************************************/

void printFrets(int frets[], char cq)
{

      // variables used to adjust symmetry

int i = 0, j = 1;
int l = 0, m = 0, o = 0;

if (frets[0] == -2)// store A frets
  {                // in aString[]
    aString[1] = (frets[1]);
    aString[2] = (frets[2]);
    aString[3] = (frets[3]);        
  }

if (frets[0] == -4)// store G frets
  {                // in gString[]
    gString[1] = (frets[1]);
    gString[2] = (frets[2]);
    gString[3] = (frets[3]);        
  }
           // check for double digit frets

  if ((frets[3] > 9) || (frets[2] > 9))
  { l = 1; m = 0; o = 2; }
  else
  { m = 1; }

if (frets[0] == -6)            // e string
{

pipebar(0);
 

  if ((frets[1] >= -6) &&
      (frets[1] <= -4))
  { j++; }        // skipPrint placeholder

  if ((frets[2] >= -6) &&
      (frets[2] <= -4))
  { j = 3; o = 2; }
                  // skipPrint placeholder

  if (frets[3] == 1)
  {
    for (i=0; i<4; i++)
    { line(1); }  // F M, F m
  }

  if ((frets[3] == 8) && (cq == 'M'))
  {
    for(i=0; i<5; i++)
    { line(1); }  // C M, B#M
  }

  if (frets[3] == 2)
  {
    for(i=0; i<2; i++)
    { line(1); }  // GbM, Gbm, F#M, F#m
  }

  if (frets[2] == 9)
  { line(1); }  // Ebm, D M, D#m

  if (frets[2] == 5)
  {
    for (i=0; i<SW/2-5; i++)
    { line(1); }  // A#M, BbM, B m, Cbm
  }

  if ((frets[2] == 6) && (cq == 'm'))
  {
    for (i=0; i<SW/2-1; i++)
    { line(1); }  // B#m, C m
  }

  if ((frets[2] == 7) && (cq == 'm'))
  {
    for (i=0; i<SW/2; i++)
    { line(1); }  // C#m, Dbm
  }

  if ((frets[2] == 8) && (frets[3] == 10))
  { line(1); }  // D m
         
  if ((frets[2] == 7) && (cq == 'M'))
  {
    for (i=0; i<SW/2-5; i++)
    { line(1); }  // C M, B#M
  }

  if ((frets[2] == 6) && (cq == 'M'))
  {
     for (i=0; i<SW/2-5; i++)
     { line(1); }  // CbM, B M
  }

  if (frets[2] >= 8)
  {
    for (i=0; i<SW/2-3; i++)
    { line(1); }  // C#M, DbM, D M, D m,
                  // D#m, E*M, E*m
  }

  if ((frets[2] == 8) && (frets[3] == 9))
  {
    for (i=0; i<3; i++)
    { line(1); }  // C#M, DbM
  }

  if (frets[3] == 0)
  {
    for (i=0; i<4; i++)
    { line(1); }  // FbM, Fbm
  }

  if ((frets[2] != 1) && (frets[3] == 2))
  {
    for (i=0; i<2; i++)
    { line(1); }  // F#M, F#m, Gbm
  }

  if ((frets[2] == 1) && (frets[3] == 2))
  { o = 2; }  // GbM

  if ((frets[2] == 0) && (frets[3] == 2))
  { o = 4; }  // Gbm
       
  if (frets[2] <= 4)
  {
    for (i=0; i<SW/2-5-o; i++) {
      line(1); }  // A M, AbM, A*m, Bbm,
  }               // G*M, G*m

for (i=j; i<4; i++)  //skip +1 in frets
{ printf("%d-", frets[i]); }  

  if ((frets[2] == 6) && (cq == 'm'))
  { line(1); }  // B#m, C m

pipebar(0);

  if ((frets[2] == 6) && (cq == 'm'))
  { line(1); }  // B#m, C m

for (i=3; i>j-1; i--)
{ printf("-%d", frets[i]); }

  if (frets[3] == 0)
  {
    for (i=0; i<SW/2-3; i++)
    { line(1); }  // FbM, Fbm
  }

  if ((frets[2] == 1) && (frets[3] == 2))
  { o = -2; }  // GbM

  if ((frets[1] == -4) && (frets[3] == 2))
  { o = 0; }  // F#M, F#m
   
  if ((frets[3] == 2) && (cq == 'M'))
  {
    for (i=0; i<SW/2-3+o; i++)
    { line(1); }  // F#M, GbM
  }

  if ((frets[2] == 2) && (frets[3] == 3))
  {
    for (i=0; i<SW/2-5; i++)
    { line(1); }  // G M
  }
     
  if ((frets[2] == 1) && (frets[3] == 3))
  {
    for (i=0; i<SW/3-5; i++)
    { line(1); }  // G m
  }

  if ((frets[2] == 9) && (frets[3] == 10))
  {
    for (i=0; i<SW/2-3; i++)
    { line(1); }  // D M
  }
     
  if ((frets[2] == 9) && (frets[3] == 11))
  {
    for (i=0; i<SW/2-3; i++)
    { line(1); }  // D#m, Ebm
  }

  if ((frets[2] == 12) && (frets[3] == 13))
  {
    for (i=0; i<SW/2-3; i++)
    { line(1); }  // E#M
  }

  if ((frets[2] == 4) && (frets[3] == 6))
  {
    for (i=0; i<SW/2-5; i++)
    { line(1); }  // A#m, Bbm
  }
     
  if ((frets[2] == 2) && (frets[3] == 4))
  {
    for (i=0; i<SW/2-5; i++)
    { line(1); }  // Abm, G#m
  }
     
  if ((frets[2] == 3) && (frets[3] == 4))
  {
    for (i=0; i<SW/2-5; i++)
    { line(1); }  // AbM, G#M
  }

  if ((frets[2] == 8) && (frets[3] == 9))
  {
    for (i=0; i<SW/2-3; i++)
    { line(1); }  // C#M, DbM
  }
     
  if ((frets[2] == 8) && (frets[3] == 10))
  {
    for (i=0; i<SW/2-3; i++)
    { line(1); }  // D m
  }

  if ((frets[2] == 5) || (frets[3] == 5))
  {
    for (i=0; i<SW/2-5; i++)
    { line(1); }  // A M, A m, A#M, BbM,
                  // B m, Cbm
  }

// reevaluate using independant offset
  o = 1;

  
  if ((frets[2] == 7) && (frets[3] == 9))
  { o = 2; }  // C#m, Dbm

  if ((frets[2] == 7) && (cq == 'm'))
  {
    for (i=0; i<SW/2-o; i++)
    { line(1); }  // C#m, Dbm
  }
      
  if ((frets[3] == 8) && (cq == 'M'))
  {
    for(i=0; i<4; i++)
    { line(1); }  // B#M, C M
  }

  if ((frets[2] == 6) && (cq == 'M'))
  {
    for (i=0; i<SW/2-5; i++)
    { line(1); }  // B M, CbM
  }

  if ((frets[2] == 6) && (frets[3] == 8))
  { o = -1; }  // B#m, C m
       
  if ((frets[2] == 6) && (cq == 'm'))
  {
    for (i=0; i<SW/2-2+o; i++)
    { line(1); }  // B#m, C m
  }

  if ((frets[2] == 8) && (frets[3] == 10))  
  { line(1); }  // D m

// reevaluate using independant offset
  o = 0;

 
  if ((frets[2] == 4) && (frets[3] == 6))
  { o = -2; }  // A#m, Bbm

  if ((frets[2] == 2) && (frets[3] == 4))
  { o = -2; }  // Abm, G#m

  if ((frets[2] == 1) && (frets[3] == 3))
  { o = -2; }  // G m
        
  if ((frets[2] == 7) && (cq == 'M'))
  {
    for (i=0; i<SW/2-6; i++)
    { line(1); }  // B#M, C M
  }
     
  if ((frets[2] == 10) && (frets[3] == 11))
  {
    for (i=0; i<SW/2-3; i++)
    { line(1); }  // D#M, EbM
  }

  if ((frets[2] == 11) && (frets[3] == 12))
  {
    for (i=0; i<SW/2-3; i++)
    { line(1); }  // E M
  }
     
  if ((frets[2] == 11) && (frets[3] == 13))
  {
    for (i=0; i<SW/2-3; i++)
    { line(1); }  // E#m
  }
     
  if ((frets[2] == 10) && (frets[3] == 12))
  {
    for (i=0; i<SW/2-3; i++)
    { line(1); }  // E m
  }
     
  if (frets[2] == 9)
  { line(1); }  // D M, D#m, Ebm

  if ((frets[3] == 1) && (cq == 'M'))
  {
    for (i=0; i<2; i++)
    { line(1); }  // F M, F m
  }

// reevaluate using independant offset
  o = 0;

  if ((frets[3] == 1) && (cq == 'm'))
  { o = 2; }  // F m

  if ((frets[3] == 2) && (cq == 'm'))
  { o = 2; }  // F#m, Gbm

  if ((frets[2] == 0) && (frets[3] == 2))
  { o = 0; }  // Gbm

  if (((frets[3] == 1) || (frets[3] == 2)) && (cq == 'm'))
  {
    for (i=0; i<SW/2-5+o; i++)
    { line(1); }  // F m, F#m, Gbm
  }

  if ((frets[2] == 1) && (frets[3] == 3))
  {
    for (i=0; i<SW/3-10; i++)
    { line(1); }  // G m
  }

  if ((frets[3] == 1) && (cq == 'M'))
  {
    for (i=0; i<SW/2-5; i++)
    { line(1); }  // F M
  }
      
  if ((frets[2] == 8) && (frets[3] == 9))
  { line(1); }  // C#M, DbM

     
pipebar(0);

}
 

if (frets[0] == -5)            // B string
{

pipebar(0);

   
  if ((frets[1] >= -6) &&
      (frets[1] <= -4))
  { j++; }        // skipPrint placeholder
   

  if ((frets[1] == 1) || ((frets[2] == 9) && (frets[3] == 11)))
  { o = 2; }  // F M, F m, C#M, DbM
 
  if (l>0)
  {
    for(i=0; i<2; i++)
    { line(1); }
  }

  if ((frets[2] == 11) && (frets[3] == 12))
  {
    for (i=0; i<2; i++)
    { line(1); }  // D#m, Ebm
  }

  if ((frets[1] == 2) && (frets[3] == 6))
  { o = 0; }  // F#M

  if (frets[2] == 8)
  {
    for (i=0; i<SW/2-7; i++)   
    { line(1); }  // B#M, B#m, C M, C m
  }
  else
  {
    for (i=0; i<SW/2-9-o; i++)   
    { line(1); }
  }

  if ((frets[2] == 9) && (frets[3] == 11))
  {
    for (i=0; i<4; i++)
    { line(1); }  // C#M, DbM
  }

  if ((frets[2] == 11) && (frets[3] == 13))
  { line(1); }  // D#M, EbM

  if ((frets[2] == 9) && (frets[3] != 11) && (cq == 'M'))
  { line(1); }  // C#m, Dbm by exclusion

  if (frets[1] == 1)
  {
    for (i=0; i<2; i++)
    { line(1); }  // F M, F m
  }

  if ((frets[2] == 8) && (frets[3] == 9))
  {
    for (i=0; i<2; i++)
    { line(1); }  // B#m, C m
  }

  if ((frets[2] == 9) && (frets[3] == 10))
  {
    for (i=0; i<4; i++)
    { line(1); }  // C#m, Dbm
  }

  if ((frets[2] == 10) && (frets[3] == 12))
  {
    for (i=0; i<2; i++)
    { line(1); }  // D M
  }

  if ((frets[2] == 10) && (frets[3] == 11))
  {
    for (i=0; i<2; i++)
    { line(1); }  // D m
  }

  if ((frets[2] == 12) || (frets[3] == 14))
  {
    for (i=0; i<2; i++)
    { line(1); }  // E M, E m, E#m
  }

  if ((frets[2] == 13) && (frets[3] == 15))
  {
    for (i=0; i<2; i++)
    { line(1); }  // E#M
  }

          
for (i=j; i<4; i++)  // skip +1 in frets
{ printf("%d-", frets[i]); }

  if ((frets[2] == 12) || (frets[3] == 14))
  {
    for (i=0; i<2; i++)
    { line(1); }  // E M, E m, E#m
  }

  if ((frets[2] == 13) && (frets[3] == 15))
  {
    for (i=0; i<2; i++)
    { line(1); }  // E#M
  }

  if ((frets[2] == 10) && (frets[3] == 11))
  {
    for (i=0; i<2; i++)
    { line(1); }  // D m
  }

  if ((frets[2] == 10) && (frets[3] == 12))
  {
    for (i=0; i<2; i++)
    { line(1); }  // D M
  }

  if ((frets[2] == 9) && (frets[3] == 11))
  { line(1); }  // DbM, C#M

  if ((frets[2] == 9) && (frets[3] == 10))
  {
    for (i=0; i<2; i++)
    { line(1); }  // C#m, Dbm
  }

  if ((frets[2] == 11) && (frets[3] == 12))
  {
    for (i=0; i<2; i++)
    { line(1); }  // D#m, Ebm
  }

  if ((frets[2] == 8) && (frets[3] == 9))
  { line(1); }  // B#m, C m

  if ((frets[2] == 8) && (frets[3] == 10))
  {
    for (i=0; i<2; i++)
    { line(1); }  // B#M, C M
  }

  if ((frets[2] == 11) && (frets[3] == 13))
  {
    for (i=0; i<3; i++)
    { line(1); }  // D#M, EbM
  }

  if ((frets[1] == 2) && (frets[3] == 6))
  { o = 4; }  // F#M

  if ((frets[1] == 2) && (frets[2] == 3) && (frets[3] == 5))
  { o = 4; }  // F#m

  if ((frets[1] == 0) && (frets[3] == 4))
  { o = 2; }  // FbM

  if ((frets[1] == 0) && (frets[2] == 1) && (frets[3] == 3))
  { o = 2; }  // Fbm

  if ((frets[2] == 9) && (cq == 'M'))
  {
    for (i=0; i<SW/8-5; i++)
    { line(1); }  // C#M, C#m, DbM, Dbm
  }
  else
  {
    for (i=0; i<SW/8-4-o; i++)
    { line(1); }
  }

  if (frets[1] == 2)
  {
     for (i=0; i<2; i++)
     { line(1); }  // F#M, F#m
  }

pipebar(0);

  if (frets[1] == 1)
  { o = 4; }  // F M, F m

  if ((frets[2] == 13) && (frets[3] == 15))
  {
    for (i=0; i<2; i++)
    { line(1); }  // E#M
  }

  if ((frets[2] == 12) || (frets[3] == 14))
  {
    for (i=0; i<2; i++)
    { line(1); }  // E M, E m, E#m
  }
     
  if ((frets[2] == 10) && (frets[3] == 12))
  {
    for (i=0; i<2; i++)
    { line(1); }  // D M
  }
     
  if ((frets[2] == 9) && (frets[3] == 11))
  { line(1); }  // DbM, C#M

  if ((frets[2] == 9) && (frets[3] == 10))
  {
    for (i=0; i<2; i++)
    { line(1); }  // C#m, Dbm
  }
                   
  if ((frets[2] == 8) && (frets[3] == 9))
  { line(1); }  // B#m, C m

  if ((frets[2] == 9) && (cq == 'M'))
  {
    for (i=0; i<SW/8-5; i++)
    { line(1); }  // C#M, C#m, DbM, Dbm
  }
  else
  {
    for (i=0; i<SW/8-4-o; i++)
    { line(1); }
  }

  if ((frets[1] == 1) && (cq == 'M'))
  {
    for (i=0; i<2; i++)
    { line(1); }  // F M
  }

  if (frets[1] == 2)
  {
    for (i=0; i<2; i++)
    { line(1); }  // F#M, F#m
  }

  if ((frets[2] == 8) && (frets[3] == 10))
  {
    for (i=0; i<2; i++)
    { line(1); }  // B#M, C M
  }

  if ((frets[2] == 11) && (frets[3] == 13))
    {
    o = -1;
    for (i=0; i<3; i++)
    { line(1); }  // D#M, EbM
    }

  if ((frets[2] == 11) && (frets[3] == 12))
  {
    for (i=0; i<2; i++)
    { line(1); }  // D#m, Ebm
  }

  if ((frets[1] == 1) && (frets[3] == 4))
  {
    for (i=0; i<2; i++)
    { line(1); }  // F m
  }

  if ((cq == 'm') && (frets[2] == 10) && (frets[3] == 11))
  {
    for (i=0; i<2; i++)
    { line(1); }  // D m
  }

  for (i=3; i>j-1; i--)
    printf("-%d", frets[i]);

  if ((frets[1] == 0) && (frets[3] == 4))
  {
    for (i=0; i<2; i++)
    { line(1); }  // FbM
  }

  if ((frets[2] == 8) && (frets[3] == 9) && (cq == 'm'))
  {
    for (i=0; i<2; i++)
    { line(1); }  // B#m, C m
  }

  if ((frets[2] == 8) && (frets[3] == 10))
  {
    for (i=0; i<2; i++)
    { line(1); }  // B#M, C M
  }
                 
  if ((frets[2] == 9) && (frets[3] == 11))
  {
     for (i=0; i<2; i++)
       line(1);  // C#M, DbM
  }

  if (l>0)
    for (i=0; i<3; i++)
      line(1);

  if ((frets[2] == 2) && (frets[3] != 3) && (cq == 'M'))
  {
    for (i=0; i<SW/3+2; i++)
      line(1);  // FbM
  }

  if ((frets[1] == 0) && (frets[2] == 1) && (frets[3] == 3) && (cq == 'm'))
    for (i=0; i<SW/3+2; i++)
      line(1);
     
  if ((frets[1] == 2) && (frets[2] == 3) && (frets[3] == 5) && (cq == 'm'))
    o = 23;
   
  if ((cq == 'm') && (frets[2] == 3) && (frets[3] != 4))
    for (i=0; i<SW/3+2-o; i++)
      line(1);

  if ((cq == 'M') && (frets[2] == 5))
    for (i=0; i<SW/3+2; i++)
      line(1);

  if ((cq == 'm') && (frets[2] == 5))
    for (i=0; i<SW/3+2; i++)
      line(1);

  if ((cq == 'M') && (frets[2] == 6))
    for (i=0; i<SW/8-9; i++)
      line(1);

  if ((cq == 'm') && (frets[2] == 6))
    for (i=0; i<SW/3+2; i++)
      line(1);

  if (((cq == 'M') || (cq == 'm')) && (frets[2] == 7))           
    for (i=0; i<SW/8-9; i++)
      line(1);

  if ((cq == 'm') && ((frets[2] >= 7) && (frets[2] <= 13)))           
    for (i=0; i<SW/3+1+m; i++)
      line(1);

  if (frets[1] == 1)
    o = 2;
           
  if (((frets[2] >= 1) && (frets[2] <= 4)) && (cq == 'M'))
    for (i=0; i<SW/3+2-o; i++)
       line(1);

  if (((frets[2] >= 2) && (frets[2] <= 4)) && (cq == 'm') && (frets[3] != 4))
    for (i=0; i<SW/3+2; i++)
      line(1);

  if ((frets[2] == 3) && (frets[3] == 4) && (cq == 'm'))
    for (i=0; i<SW/3+2; i++)
      line(1);

  if ((frets[2] == 10) && (frets[3] == 12) && (cq == 'M'))
    o = 0;

  if (((frets[2] >= 6) && (frets[2] <= 9)) && (cq == 'M'))
    for (i=0; i<SW/3+1-o; i++)
      line(1);

  if (((cq == 'M') || (cq == 'm')) && ((frets[2] == 12) || (frets[3] == 14)))   
     o = 0;

  if ((frets[2] == 13) && (frets[3] == 15) && (cq == 'M'))
    o = 0;
     
  if (((cq == 'M') && frets[2] >= 9) && (frets[3] != 11))
    for (i=0; i<SW/3+1+o; i++)
      line(1);

  if ((frets[1] == 2) && (frets[3] == 6) && (cq == 'M'))
    o = -15;

  if ((cq == 'M') && (frets[1] == 2))           
    for (i=0; i<SW/3-2+o; i++)
      line(1);

  if ((cq == 'M') && ((frets[2] == 6) || (frets[2] == 7)))
    line(1);

  if ((frets[1] == 1) && (cq == 'M'))
    for (i=0; i<2; i++)
      line(1);

pipebar(0);

}

if (frets[0] == -4)            // G string

{
   
pipebar(0);
   
  if ((frets[1] >= -6) &&
      (frets[1] <= -4))
    { j++; }      // skipPrint placeholder
   

  if ((frets[1] == 1) && (frets[3] == 4) && (cq == 'M'))
    o = -2;

  if ((frets[2] == 2) && (frets[3] == 4) && (cq == 'm'))
    o = 2;

  if ((frets[2] == 0) && (frets[3] == 2) && (cq == 'm'))
    o = 2;

  if ((frets[1] == 10) && (frets[3] == 13))
    o = 0;

  if ((frets[1] == 11) && (frets[3] == 14))
    o = 0;

  if ((frets[1] == 12) && (frets[3] == 15))
    o = 0;

  if ((frets[1] == 1) && (frets[2] == 2) && (frets[3] == 4) && (cq == 'm'))
    o = 0;

  if (((cq == 'M') || (cq == 'm')) && frets[1] == 9)
    for (i=0; i<SW/4+2; i++)
      line(1);
  else
    for (i=0; i<SW/4+1+o; i++)   
      line(1);

  if ((frets[1] == 8) && (frets[3] == 11) && (cq == 'm'))
      line(1);

  if ((cq == 'm') && (frets[1] == 2) && (frets[3] != 5))
    for (i=0; i<SW/4-1; i++)
      line(1);    

  if ((frets[1] == 8) && (frets[2] == 10) && (frets[3] == 11))
    o = 3;

  if (((cq == 'M') && (frets[1] == 8)) || (frets[1] == 7))
    for(i=0; i<3-o; i++)
      line(1);

  if ((frets[2] == 2) && (cq == 'M'))
    for (i=0; i<2; i++)
      line(1);

  if (((frets[2] == 2) && (frets[3] == 3)) && (cq == 'm'))
    for (i=0; i<2; i++)
      line(1);

  if ((frets[2] == 1) && (frets[3] == 3) && (cq == 'm'))
    for (i=0; i<2; i++)
      line(1);

  if ((frets[2] == 1) && (frets[3] == 2) && (cq == 'M'))
    for (i=0; i<2; i++)
      line(1);

  if ((frets[2] == 3) && (frets[3] == 4) && (cq == 'M'))
    for (i=0; i<2; i++)
      line(1);

for (i=j; i<4; i++) //skip +1 in frets
{ printf("%d-", frets[i]); } 

  if (l>0)
    line(1);

  if ((cq == 'M') && (frets[1] == 8))
    for (i=0; i<SW/8-8; i++)
      line(1);

  if ((cq == 'm') && (frets[1] == 2) && (frets[3] != 5))
    for (i=0; i<4; i++)
      line(1);
  else
    for (i=0; i<SW/8; i++)
      line(1);

pipebar(0);

  if (l>0)
    line(1);
 
  if ((cq == 'm') && (frets[1] == 2) && (frets[3] != 5))
    for (i=0; i<SW/8-4; i++)
      line(1);

  if ((cq == 'M') && (frets[1] == 8))   
    for (i=0; i<SW/8-1; i++)
      line(1);
  else
    for (i=0; i<SW/8; i++)
      line(1);

for (i=3; i>j-1; i--)
{ printf("-%d", frets[i]); }

  if ((frets[2] == 1) && (frets[3] == 2) && (cq == 'M'))
    for (i=0; i<2; i++)
      line(1);

  if ((frets[2] == 1) && (frets[3] == 3) && (cq == 'm'))
    for (i=0; i<2; i++)
      line(1);
     
  if ((frets[2] == 2) && (cq == 'M'))
    for (i=0; i<2; i++)
      line(1);

  if ((frets[2] == 3) && (frets[3] == 4) && (cq == 'M'))
    for (i=0; i<2; i++)
      line(1);

  if ((frets[1] == 8) && (frets[2] == 10) && (frets[3] == 11) && (cq == 'M'))
    o = 1;

  if ((frets[1] == 8) && (frets[2] == 9) && (frets[3] == 11) && (cq == 'm'))
    o = 1;

  if ((frets[1] == 1) && (frets[3] == 4) && (cq == 'M'))
    o = -2;

  if ((frets[1] == 7) && (frets[2] == 9) && (frets[3] == 10))
    o = 1;

  if ((frets[1] == 7) && (frets[2] == 8) && (frets[3] == 10))
    o = 1;

  if ((frets[1] == 9) && (frets[2] == 11) && (frets[3] == 12))
    o = 1;
   
  if ((frets[1] == 9) && (frets[2] == 10) && (frets[3] == 12))
    o = 1;  
     
  if ((cq == 'm') && (frets[1] == 2) && (frets[3] != 5))
    for (i=0; i<SW/4-1; i++)
      line(1);
    else    
      for (i=0; i<SW/4+1+o; i++)
        line(1);       

pipebar(0);

}

if (frets[0] == -3)            // D string
{

pipebar(0);

// reevaluate use of one independant line
  line(1);

  if ((frets[1] == 1) && (frets[2] == 3) && (frets[3] == 5) && (cq == 'm'))
   m = 1;

  if ((frets[1] == 1) && (frets[2] == 3) && (frets[3] == 5) && (cq == 'm') && (gString[1] == 2))
   m = -1;  // fixes G m

  if ((frets[1] == 1) && (frets[2] == 3) && (frets[3] == 4) && (cq == 'M'))
   m = -1;

if ((frets[1] == 0) && (frets[2] == 2) && (frets[3] == 4) && (cq == 'm'))
   m = 1;

if ((frets[1] == 2) && (frets[2] == 4) && (frets[3] == 6) && (cq == 'm'))
   m = -1;

  if ((frets[1] == 2) && (frets[2] == 4) && (frets[3] == 6) && (cq == 'm') && (gString[2] == 2))
   m = 1;  // fixes F#m

  if ((frets[1] == 0) && (frets[2] == 2) && (frets[3] == 4) && (cq == 'm') && (gString[1] == 1))
   m = -1;  // fixes Gbm
        
  for (i=0; i<SW/8+m; i++)   
    line(1);    

  if ((frets[1] == 7) && (frets[3] == 11) && (cq == 'm'))
    for (i=0; i<3; i++)
      line(1);

  if ((frets[1] == 2) && (frets[2] != 4) && (frets[3] == 5) && ((cq == 'M')))
    for (i=0; i<2; i++)
      line(1);

  if ((frets[1] == 2) && (frets[2] == 4) && (frets[3] == 6) && ((cq == 'm')))
    for (i=0; i<2; i++)
      line(1);

  if ((frets[1] == 6) && (frets[3] == 10) && ((cq == 'm')))
    for (i=0; i<3; i++)
      line(1);
       
  if ((cq == 'M') && ((frets[1] == 8) || (frets[1] == 9)))
    line(1);     

  if ((cq == 'M') && (frets[1] == 7))
    for (i=0; i<3; i++)
      line(1);

  if ((frets[1] == 9) && (frets[3] == 13) && (cq == 'm'))
    line(1);

  if ((frets[1] == 1) && (frets[2] == 3) && (frets[3] == 5) && (cq == 'm'))
    {
    o = 2;
    for (i=0; i<2; i++)
      line(1);
    }

  if ((frets[1] == 1) && (frets[3] == 4) && (cq == 'M'))
    {
    o = 2;
    for (i=0; i<2; i++)
      line(1);
    }

  if ((frets[1] == 3) && (frets[2] == 4) && (frets[3] == 6) && (cq == 'M'))
    for (i=0; i<2; i++)
      line(1);

  if ((cq == 'm') && (frets[1] == 8) && (frets[3] == 12))
    for (i=0; i<2; i++)
      line(1);

  if ((cq == 'm') && (frets[1] == 0) && (frets[2] == 2) && (frets[3] == 4))
    {
    o = 2;
    for (i=0; i<2; i++)
      line(1);
    }

                       
for (i=1; i<4; i++)
{ printf("-%d", frets[i]); }

  if ((frets[1] == 0) && (frets[2] == 2) && (frets[3] == 4) && (cq == 'm'))
    o = 2;

  if ((frets[1] == 3) && (frets[3] == 6) && (cq == 'M'))
    o = 2;
     
  if ((frets[1] == 1) && (frets[2] == 3) && (frets[3] == 4) && (cq == 'M'))
    for (i=0; i<2; i++)
      line(1);
   
  if (((cq == 'M') || (cq == 'm')) && ((frets[1] == 11) || (frets[3] == 14)))   
    for (i=0; i<2; i++)
      line(1);
      
  if ((frets[1] == 9) && (frets[3] == 12) && (cq == 'M'))
    for (i=0; i<2; i++)
      line(1);

  if ((frets[1] == 7) && (frets[3] == 10) && (cq == 'M'))
    for (i=0; i<2; i++)
      line(1);

  if ((frets[1] == 8) && (frets[3] == 11) && (cq == 'M'))
    for (i=0; i<2; i++)
      line(1);
       
  if ((frets[1] == 7) && (frets[3] == 11) && (cq == 'm'))
    for (i=0; i<2; i++)
      line(1);

  if ((frets[1] == 10) && (frets[3] == 13) && (cq == 'M'))
    for (i=0; i<2; i++)
      line(1);
             
  if ((cq == 'M') && (frets[1] == 8))
    line(1);

  if ((frets[1] == 2) && (frets[2] != 4) && (frets[3] == 5) && ((cq == 'M')))
    o = 2;

  if ((frets[1] == 2) && (frets[2] == 4) && (frets[3] == 6) && ((cq == 'm')))
    o = 0;  // fixes Abm

  if ((frets[1] == 1) && (frets[2] == 3) && (frets[3] == 5) && (cq == 'm') && (gString[1] == 2))
   o = 0;  // fixes G m

  if ((frets[1] == 2) && (frets[2] == 4) && (frets[3] == 6) && (cq == 'm') && (gString[2] == 2))
   o = 2;  // fixes F#m

  if ((frets[1] == 0) && (frets[2] == 2) && (frets[3] == 4) && (cq == 'm') && (gString[1] == 1))
   o = 0;  // fixes Gbm
            
  for (i=0; i<SW/4-1-o; i++)
    line(1);

  if (l>0)
    for(i=0; i<2; i++)
      line(1);

  if ((frets[1] == 6) && (frets[3] == 10) && ((cq == 'm')))
    for (i=0; i<2; i++)
      line(1);

  if ((frets[1] == 9) && (frets[3] == 13) && (cq == 'm'))
    {
    o = 1;
    for (i=0; i<2; i++)
      line(1);
    } 

  if ((cq == 'm') && (frets[1] == 8) && (frets[3] == 12))
    {
    o = 1;
    line(1);
    }

  if ((frets[1] == 3) && (frets[2] == 5) && (frets[3] == 6) && (cq == 'M'))
    for (i=0; i<2; i++)
      line(1);  

   if ((frets[1] == 12) && (frets[3] == 15) && (cq == 'M')) {
    for (i=0; i<2; i++)
      line(1); }                 

pipebar(0);

  if ((frets[1] == 1) && (frets[2] == 3) && (frets[3] == 4) && (cq == 'M'))
    for (i=0; i<2; i++)
      line(1);
     
  if ((frets[1] == 7) && (frets[3] == 11) && (cq == 'm'))
    o = 2;

  if (l>0)
    for(i=0; i<2+o; i++)
      line(1);

  if ((frets[1] == 3) && (frets[2] == 5) && (frets[3] == 6) && (cq == 'M'))
    for (i=0; i<2; i++)
      line(1);
        
  if ((frets[1] == 6) && (frets[3] == 10) && ((cq == 'm')))
    for (i=0; i<2; i++)
      line(1);

  if ((frets[1] == 1) && (frets[2] == 3) && (frets[3] == 5) && (cq == 'm'))
    o = 4;
 
  if ((frets[1] == 8) && (frets[3] == 11) && (cq == 'M'))
    o = 3;

  if ((frets[1] == 7) && (frets[2] == 9) && (frets[3] == 10) && (cq == 'M'))
    o = 4;

  if ((frets[1] == 6) && (frets[2] == 8) && (frets[3] == 10) && (cq == 'm'))
    o = 4;

  if ((frets[1] == 1) && (frets[2] == 3) && (frets[3] == 5) && (cq == 'm') && (gString[1] == 2))
   o = 2;  // fixes G m
             
  for (i=0; i<SW/4-1-o; i++)
    line(1);

  if ((frets[1] == 7) && (frets[3] == 10) && (cq == 'M'))
    {
    o = 0;
    for (i=0; i<2; i++)
      line(1);
    }

  if ((frets[1] == 8) && (frets[3] == 11) && (cq == 'M'))
    {
    o = -2;
    line(1);
    }

  if ((frets[1] == 1) && (frets[2] == 3) && (frets[3] == 5) && (cq == 'm'))
    {
    o = 0;
    for (i=0; i<2; i++)
      line(1);
    }

           
for (i=3; i>0; i--)
{ printf("%d-", frets[i]); }

  if ((cq == 'm') && (frets[1] == 0) && (frets[2] == 2) && (frets[3] == 4))
    o = 2;
   
  if ((frets[1] == 7) && (frets[3] == 11) && (cq == 'm'))
    o = 1;

  if ((frets[1] == 6) && (frets[3] == 10) && ((cq == 'm')))
    o = 1;

  if ((frets[1] == 10) && (frets[3] == 13) && (cq == 'M'))
    o = 0;

  if ((frets[1] == 9) && (frets[3] == 12) && (cq == 'M'))
    o = 0;

  if (((cq == 'M') || (cq == 'm')) && ((frets[1] == 11) || (frets[3] == 14)))   
    o = 0;               

  if ((frets[1] == 12) && (frets[3] == 15) && (cq == 'M'))
    o = 0;

  if ((frets[1] == 1) && (frets[3] == 4) && (cq == 'M'))
    o = 2;

// fixes Abm
  if ((cq == 'm') && (frets[1] == 2) && (frets[2] == 4) && (frets[3] == 6))
    o = 2;
   
  if ((frets[1] == 1) && (frets[2] == 3) && (frets[3] == 5) && (cq == 'm'))
    o = 2;

// fixes F#M
  if ((frets[1] == 3) && (frets[2] == 4) && (frets[3] == 6) && (cq == 'M'))
    {
    o = -2;
    for (i=0; i<4; i++)
      line(1);
    }

// fixes AbM
  if ((frets[1] == 3) && (frets[2] == 5) && (frets[3] == 6) && (cq == 'M'))
    {
    o = -4;
    for (i=0; i<4; i++)
      line(1);
    }

  for (i=0; i<SW/8+m+o; i++)
    line(1);

  if ((cq == 'M') && (frets[1] == 8))   
    for (i=0; i<2; i++)
      line(1);

  if ((cq == 'M') && ((frets[1] == 7) || (frets[1] == 9)))
    line(1);

// reevaluate use of one line
  line(1);

pipebar(0);
   
}

if (frets[0] == -2)            // A string
{

pipebar(0);

  if ((frets[1] >= -6) &&
      (frets[1] <= -4))
    { j++; }      // skipPrint placeholder

  if ((cq == 'M') || (cq == 'm'))
    line(1);

  for (i=0; i<SW/14-o-m; i++)
    line(1);

  if ((frets[1] == 9) && (frets[3] == 13) && (cq == 'm'))
    line(1);
       
  if ((frets[1] == 1) && (frets[3] == 5) && (cq == 'M'))
    for (i=0; i<2; i++)
      line(1);

  if ((frets[1] == 9) && (cq == 'M'))
      line(1);

  if ((frets[1] == 7) && (cq == 'M'))
    for (i=0; i<2; i++)
      line(1);

  if ((frets[1] == 7) && (frets[3] == 11) && (cq == 'm'))
    for (i=0; i<2; i++)
      line(1);

  if ((frets[1] == 6) && (frets[3] == 10) && ((cq == 'm')))
    for (i=0; i<2; i++)
      line(1);

  if ((frets[1] == 0) && (frets[3] == 4) && (cq == 'M'))
    {
    o = 2;
    for (i=0; i<2; i++)
      line(1);
    }

  if ((frets[1] == 1) && (frets[3] == 4) && (cq == 'm'))
    {
    o = 4;
    for (i=0; i<2; i++)
      line(1);
    }

  if ((frets[1] == 2) && (frets[3] == 6) && (cq == 'M'))
    {
    o = 2;
    for (i=0; i<2; i++)
      line(1);
    }

  if ((frets[1] == 2) && (frets[2] == 4) && (frets[3] == 5) && (cq == 'm'))
    {
    o = 2;
    for (i=0; i<2; i++)
      line(1);
    }

  if ((cq == 'm') && (frets[1] == 0) && (frets[2] == 2) && (frets[3] == 3))
    {
    o = 1;
    for (i=0; i<2; i++)
      line(1);
    }
   
  if ((cq == 'm') && (frets[1] == 8) && (frets[3] == 12))
    line(1);     

for (i=j; i<4; i++)
{ printf("-%d", frets[i]); }

  if ((frets[1] == 12) && (frets[3] == 15) && (cq == 'M'))
    for (i=0; i<3; i++)
      line(1);

  if ((frets[1] == 9) && (frets[3] == 12) && (cq == 'M'))
    for (i=0; i<3; i++)
      line(1);

  if ((frets[1] == 6) && (frets[3] == 10) && ((cq == 'm')))
    for (i=0; i<4; i++)
      line(1);

  if ((frets[1] == 3) && (frets[2] == 5) && (frets[3] == 7) && (cq == 'm'))
    line(1);
             
  if ((frets[1] == 7) && (frets[3] == 10) && (cq == 'M'))
    for (i=0; i<3; i++)
      line(1);

  if ((frets[1] == 7) && (frets[3] == 11) && (cq == 'm'))
    for (i=0; i<4; i++)
      line(1);

  if ((frets[1] == 8) && (frets[3] == 11) && (cq == 'M'))
    for (i=0; i<6; i++)
      line(1);

  if ((frets[1] == 10) && (frets[3] == 13) && (cq == 'M'))
    for (i=0; i<3; i++)
      line(1);
       
  if (((cq == 'M') || (cq == 'm')) && ((frets[1] == 5) || (frets[3] == 8)))
    line(1);

  if (l>0)
    for(i=0; i<2; i++)
      line(1);

  if (((frets[1] == 6) && (frets[3] == 9)) || ((frets[1] == 4) && (frets[3] == 7)))
    line(1);

  if (((frets[1] == 3) && (frets[3] == 6)) || ((frets[1] == 0) && (frets[3] == 4)))
    line(1);

  if ((frets[1] == 1) && (frets[3] == 4))
    for (i=0; i<2; i++)
      line(1);
    
  if ((frets[1] == 1) && (cq == 'M'))
    { line(1); o = 2; }

  for (i=0; i<SW/3-1-o; i++)
    line(1);

  if ((frets[1] == 2) && (cq == 'M'))
    line(1);

  if (((frets[1] == 1) || (frets[1] == 2)) && (cq == 'm'))
    line(1);

  if ((frets[1] == 7) && (cq == 'M'))
    line(1);

  if ((frets[1] == 9) && (frets[3] == 13) && (cq == 'm'))
    for (i=0; i<3; i++)
      line(1);

  if ((cq == 'm') && (frets[1] == 8) && (frets[3] == 12))
    for (i=0; i<3; i++)
      line(1);

  if (((cq == 'M') || (cq == 'm')) && ((frets[1] == 11) || (frets[3] == 14)))   
     for (i=0; i<3; i++)
       line(1);

   
pipebar(0);

  if (l>0)
    for(i=0; i<2; i++)
      line(1);

  if ((cq == 'm') && (frets[1] == 0) && (frets[2] == 2) && (frets[3] == 3))
    o = 2;
   
  if ((cq == 'M') && (frets[1] == 8))
    for (i=0; i<SW/3-2; i++)
      line(1);
  else
    for (i=0; i<SW/3-1-o; i++)
      line(1);

  if ((frets[1] == 1) && (frets[3] == 4))
    {
    o = 0;
    for (i=0; i<2; i++)
      line(1);
    }

  if ((frets[1] == 7) && (frets[3] == 10) && (cq == 'M'))
    {
    o = 0;
    for (i=0; i<2; i++)
      line(1);
    }

  if ((frets[1] == 6) && (frets[3] == 10) && ((cq == 'm')))
    {
    o = 1;
    for (i=0; i<2; i++)
      line(1);
    }

  if ((frets[1] == 7) && (frets[3] == 11) && (cq == 'm'))
    {
    o = 1;
    for (i=0; i<2; i++)
      line(1);
    }

  if ((frets[1] == 8) && (frets[3] == 11) && (cq == 'M'))
    {
    o = -1;
    for (i=0; i<2; i++)
      line(1);
    }

  if ((frets[1] == 9) && (frets[3] == 13) && (cq == 'm'))
    {
    o = 0;
    for (i=0; i<2; i++)
      line(1);
    }

  if ((frets[1] == 9) && (frets[3] == 12) && (cq == 'M'))
    {
    o = -1;
    for (i=0; i<2; i++)
      line(1);
    }

  if ((frets[1] == 10) && (frets[3] == 13) && (cq == 'M'))
    {
    o = 0;
    for (i=0; i<2; i++)
      line(1);
    }

  if ((frets[1] == 12) && (frets[3] == 15) && (cq == 'M'))
    {
    o = 0;
    for (i=0; i<2; i++)
      line(1);
    }
   
  if ((cq == 'm') && (frets[1] == 8) && (frets[3] == 12))
    line(1);

  if (((cq == 'M') || (cq == 'm')) && ((frets[1] == 11) || (frets[3] == 14)))   
    {
    o = 0;
    for (i=0; i<2; i++)
      line(1);
    }
                            
for (i=3; i>j-1; i--)
{ printf("-%d", frets[i]); }

  if ((frets[1] == 1) && (frets[3] == 4) && (cq == 'm'))
    for (i=0; i<2; i++)
      line(1);
           
  if ((frets[1] == 7) && (cq == 'M'))
    line(1);

  if (((cq == 'M') && (frets[1] == 8)) || (frets[1] == 9))   
    line(1);

  if ((frets[1] == 9) && (frets[3] == 12) && (cq == 'M'))
    o = 0;

// reevaliate use of one line
  line(1);
       
  for (i=0; i<4-l+o; i++)
  { line(1); }

pipebar(0);
   
}

 
if (frets[0] == -1)           // E string
{

pipebar(0);

 
  if ((frets[1] >= -6) &&
      (frets[1] <= -4))
    { j++; }      // skipPrint placeholder

for (i=j; i<4; i++)
{ printf("-%d", frets[i]); }

  if (l>0)
    for(i=0; i<2; i++)
      line(1);   

  if ((frets[2] == 13) && (frets[3] == 15) && (cq == 'm'))
    for (i=0; i<2; i++)
      line(1);

  if ((frets[2] == 13) && (frets[3] == 15) && (cq == 'M'))
    for (i=0; i<4; i++)
      line(1);

  if (((cq == 'M') || (cq == 'm')) && ((frets[2] == 12) || (frets[3] == 14)))   
     for (i=0; i<2; i++)
       line(1);
      
  if ((frets[2] == 10) && (frets[3] == 12) && ((cq == 'M') || (cq == 'm')))
    for (i=0; i<2; i++)
      line(1);
   
  if ((frets[2] == 8) && (frets[3] == 10) && (cq == 'M'))
    for (i=0; i<2; i++)
      line(1);

  if ((frets[2] == 8) && (frets[3] == 10) && (cq == 'm')) {
    o = 0; }
 
  if ((frets[1] == 2) || (frets[2] == 8))
     for (i=0; i<2; i++)
       line(1);

  if (((frets[1] == 1) || (frets[1] == 0)) && (cq == 'm'))
    o = 4;

  if (((frets[1] == 1) || (frets[1] == 0)) && (cq == 'M'))
    o = 2;

  if ((frets[2] == 6) && (frets[3] == 8) && (cq == 'M'))
  { o = 0; }  // A#M
   
  if ((frets[2] == 6) && (frets[3] == 8) && (cq == 'm') && (aString[1] == 4))
  { o = 4; }  // A#m, Bbm

  if ((frets[2] == 7) && (frets[3] == 9) && (cq == 'm'))
  { o = 0; }  // B m, Cbm
   
   if ((frets[2] == 9) && (frets[3] == 11) && (cq == 'm'))
   { o = 2; }  // C#m, Dbm

   if ((frets[2] == 10) && (frets[3] == 12) && (cq == 'm'))
    o = 6;

  if ((frets[2] == 11) && (frets[3] == 13) && (cq == 'm'))
    o = 4;  

   if ((frets[2] == 13) && (frets[3] == 15) && (cq == 'M'))
    o = 4;
   
  if ((frets[1] == 2) && (frets[3] == 6) && (cq == 'M'))
    o = 4;

  if ((frets[2] == 2) && (frets[3] == 4) && (cq == 'm'))
    o = 4;

  if ((frets[1] == 2) && (frets[2] == 4) && (frets[3] == 5) && (cq == 'm'))
    o = 8;

  if ((frets[1] == 1) && (frets[2] == 3) && (frets[3] == 4) && (cq == 'm')) {
    o = 2; }  // F m

  if ((frets[1] == 0) && (frets[2] == 2) && (frets[3] == 3) && (cq == 'm'))
    o = 6;

  if ((frets[2] == 5) && (frets[3] == 7) && (cq == 'm') && (aString[1] == 3))
  { o = 0; }  // A m

  if ((frets[2] == 6) && (frets[3] == 8) && (cq == 'm') && (aString[1] == 4))
  { o = 0; }  // A#m, Bbm

  if ((frets[2] == 4) && (frets[3] == 6) && (cq == 'm') && (aString[1] == 2))
  { o = 0; }  // Abm, G#m

  if ((frets[2] == 10) && (frets[3] == 12) && (cq == 'm') && (aString[1] == 8))
  { o = 2; }  // D m

  if ((frets[2] == 11) && (frets[3] == 13) && (cq == 'm') && (aString[1] == 9))
  { o = 0; }  // D#m

  if ((frets[2] == 12) && (frets[3] == 14) && (cq == 'm') && (aString[1] == 10))
  { o = 2; }  // E m

  if ((frets[2] == 13) && (frets[3] == 15) && (cq == 'm') && (aString[1] == 11))
    o = 2;  // E#m

  if ((frets[1] == 2) && (frets[2] == 4) && (frets[3] == 5) && (cq == 'm') && (aString[3] == 5))
    o = 4;  // F#m

  if ((frets[1] == 0) && (frets[2] == 2) && (frets[3] == 3) && (cq == 'm') && (aString[3] == 3))
  { o = 2; }  // Fbm

  if ((frets[2] == 3) && (frets[3] == 5) && (cq == 'm') && (aString[1] == 1))
  { o = 0; }  // G m

  if ((frets[2] == 2) && (frets[3] == 4) && (cq == 'm') && (aString[1] == 0))
  { o = 0; }  // Gbm
        
  for (i=0; i<SW/2-5-o; i++) {
    line(1); }

  if ((frets[2] == 9) && (frets[3] == 11) && ((cq == 'M') || (cq == 'm')))
    for (i=0; i<4; i++)
      line(1);

  if ((frets[2] == 11) && (frets[3] == 13) && (cq == 'M'))
    for (i=0; i<2; i++)
      line(1);
 
       
pipebar(0);

  if (l>0)
    for(i=0; i<2; i++)
      line(1);

  if ((frets[2] == 4) && (frets[3] == 6) && (cq == 'M'))
  { o = 2; }  // AbM
   
  if ((frets[2] == 6) && (frets[3] == 8) && (cq == 'M'))
  { o = 2; }  // A#M

  if ((frets[2] == 7) && (frets[3] == 9) && (cq == 'M'))
  { o = 2; }  // B M

  if ((frets[2] == 5) && (frets[3] == 7) && (cq == 'm'))
    o = 0;  // A m

  if ((frets[2] == 5) && (frets[3] == 7) && (cq == 'M') && (aString[1] == 4))
    o = 0;  // A M

  if ((frets[1] == 0) && (frets[2] == 2) && (frets[3] == 4) && (cq == 'M'))
    o = 4;

  if ((frets[1] == 0) && (frets[2] == 2) && (frets[3] == 3) && (cq == 'm')) {
    o = 2; }  // Fbm
       
  if ((frets[1] == 1) && (frets[2] == 3) && (frets[3] == 4) && (cq == 'm')) {
    o = 2; }  // F m
   
  if ((frets[1] == 1) && (frets[2] == 3) && (frets[3] == 5) && (cq == 'M'))
    o = 4;

  if ((frets[1] == 2) && (frets[2] == 4) && (frets[3] == 6) && (cq == 'M'))
    o = 6;

  if ((frets[1] == 2) && (frets[2] == 4) && (frets[3] == 5) && (cq == 'm'))
    o = 6;

  if ((frets[2] == 6) && (frets[3] == 8) && (cq == 'M') && (aString[1] == 5))
    o = 0;  // A#M

  if ((frets[2] == 6) && (frets[3] == 8) && (cq == 'm') && (aString[1] == 4))
    o = 0;  // A#m

  if ((frets[2] == 4) && (frets[3] == 6) && (cq == 'M') && (aString[1] == 3))
    o = 0;  // AbM

  if ((frets[2] == 7) && (frets[3] == 9) && (cq == 'M') && (aString[1] == 6)) {
    o = 0; }  // B M

  if ((frets[2] == 8) && (frets[3] == 10) && (cq == 'M') && (aString[1] == 7)) {
    o = 0; }  // B#M

  if ((frets[2] == 8) && (frets[3] == 10) && (cq == 'm') && (aString[1] == 6)) {
    o = 0; }  // B#m

  if ((frets[2] == 6) && (frets[3] == 8) && (cq == 'M') && (aString[1] == 5)) {
    o = 0; }  // BbM

  if ((frets[2] == 9) && (frets[3] == 11) && (cq == 'm') && (aString[1] == 7)) {
    o = 0; }  // C#m, Dbm

  if ((frets[2] == 10) && (frets[3] == 12) && (cq == 'm') && (aString[1] == 8)) {
    o = 2; }  // D m

  if ((frets[2] == 11) && (frets[3] == 13) && (cq == 'M') && (aString[1] == 10)) {
    o = 0; }  // D#M

  if ((frets[2] == 11) && (frets[3] == 13) && (cq == 'm') && (aString[1] == 9)) {
    o = 2; }  // D#m

  if ((frets[2] == 12) && (frets[3] == 14) && (cq == 'M') && (aString[1] == 11))
    o = 0;  // E M

  if ((frets[2] == 13) && (frets[3] == 15) && (cq == 'M') && (aString[1] == 12))
  { o = 2; }  // E#M

  if ((frets[2] == 13) && (frets[3] == 15) && (cq == 'm') && (aString[1] == 11))
  { o = 2; }  // E#m

  if ((frets[1] == 1) && (frets[2] == 3) && (frets[3] == 5) && (cq == 'M') && (aString[3] == 5))
  { o = 2; }  // F M

  if ((frets[1] == 2) && (frets[2] == 4) && (frets[3] == 6) && (cq == 'M') && (aString[3] == 6))
  { o = 4; }  // F#M

  if ((frets[1] == 0) && (frets[2] == 2) && (frets[3] == 4) && (cq == 'M') && (aString[3] == 4))
  { o = 2; }  // FbM

                   
  for (i=0; i<SW/2-5-o; i++)
    line(1);

  if ((frets[2] == 9) && (frets[3] == 11) && (cq == 'M'))
    for (i=0; i<2; i++)
      line(1);
     
  if ((frets[2] == 11) && (frets[3] == 13) && (cq == 'm'))
    for (i=0; i<2; i++)
      line(1);
    
  if ((frets[2] == 10) && (frets[3] == 12))
  {
    for (i=0; i<2; i++)
    { line(1); }  // D M, D m
  }

  if (((cq == 'm')) && ((frets[2] == 12) || (frets[3] == 14)))   
     for (i=0; i<2; i++)
       line(1);

  if ((frets[2] == 13) && (frets[3] == 15))
  {
    for (i=0; i<2; i++)
    { line(1); }  // E#M, E#m
  }

  if ((frets[1] == 2) && (frets[3] == 6) && (cq == 'M'))
    for (i=0; i<2; i++)
      line(1);

  if ((frets[1] == 2) && (frets[2] == 4) && (frets[3] == 5) && (cq == 'm')) {
    for (i=0; i<4; i++){
      line(1);} }  // F#m

for (i=3; i>j-1; i--)
{ printf("%d-", frets[i]); }

    
pipebar(0);
   
}

newline(0);
 
}

/****************************************/

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

                       // print scale name
if ((((str[0] == 'B') || (str[0] == 'C')) && (str[1] == '#')) || ((str[0] == 'D') && (str[1] == 'b')))
  printf(" %s", str);  
else
  if ((str[0] == 'C') && (str[1] == ' '))
    printf(" %s", str);
else {
  printf("%s ", str); }

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

/****************************************/

void centerLine(char *str, int width)
{

  int length = strlen(str);
  int i, margin = (width/2)-(length/2);
 
  pipebar(0);
  for(i=0; i<margin-2; i++)
   line(1);

  printf("%s", str);
// used to guide measure bar alignment

  if ((length % 2) == 0)
    margin-=0;
  else {
    margin-=2; }

    for(i=0; i<margin; i++)
      line(1);

  pipebar(0); 
    
}

/****************************************/

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

/****************************************/

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

/****************************************/

void space()
{
   
putchar(' ');  
   
}

/****************************************/

void plus()
{
   
putchar('+');

}

/****************************************/

void line(int option)
{
  if (option == 1)
    putchar('-');

  if (option == 2)
    putchar('=');     
}

/****************************************/