#include <stdio.h>
#include <ctype.h>    // toupper()
#include <stdlib.h>  // exit()
#include <string.h> // strlen()
#define SW 40      // screen width

/* generates 3 out of 42 bass arpeggios
   as I-IV-V or i-iv-V chord progressions
   programmed in C by antlerSphere 
   referenced from
https://tabs.ultimate-guitar.com/tab/lessons_-_scales/major_and_minor_scales_bass_42016

format: [A-G | a-g][#|' '|b][M | m]
ex. A M   GbM   a#m   Fbm   bbM

   enharmonic equivalents and arpeggios:
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
        F| X | X | X | X | X | X |
        -+---+---+---+---+---+---|       
Fbm     G| X | X | X | X | X | X |
E m     -+---+---+---+---+---+---+
         X = referenced with website
         and tested on bass

*/

void checkInput(char pitch[], char s_or_f[], char Mm[], char p, char sf, char cq);
void transpose(char sf, int G[], int D[], int A[], int E[]);
void banner(char str[], int width);
void printFrets(int frets[], char cq, char original_p, char original_sf);
void newline(int position);
void centerLine(char *str, int width);
void pipebar(int alignment);
void space();
void plus();
void line(int option); // 1 = '-', 2 = '='

int main() {

int i, prog;
char original_p, original_sf, p, sf, cq;
/* iterator, chord progression, original and current pitch, original and current accidental as a sharp, flat or natural, chord quality */

  char caption[4];

  int G[4], D[4], A[4], E[4];
  
  char pitch[] = "ABCDEFGABCDEFGA";
                        // pitch[p = 0-14]
  char s_or_f[] = "#b ";           
                      // s_or_f[sf = 0-2]
  char Mm[] = "Mm";  
                    // Mm[cq = 0-1]

printf("ex. [A-G | a-g][#| \' \' |b][M | m]\n");
printf("Enter pitch, accidental, tonality of arpeggio: ");

scanf("%1c%1c%1c", &p, &sf, &cq);

p = toupper(p);

checkInput(pitch, s_or_f, Mm, p, sf, cq);

original_p = p;
original_sf = sf;

if (cq == 'M')
  banner("I-IV-V", SW);
else
  if (cq == 'm')
    banner("i-iv-V", SW);

newline(0);
newline(0);

for (prog = 1; prog <=7; prog++)
{

if ((prog > 1) && (prog < 4))
  continue;

i = 0;

    if ((original_p == 'F') && (original_sf == 'b') && (prog == 5)) {
caption[0] = p;
caption[1] = sf;
caption[2] = sf;
caption[3] = cq;
caption[4] = '\0';
         }    

    else if ((original_p == 'B') && (original_sf == '#') && (prog == 7)) {
sf = 'x';
caption[0] = p;
caption[1] = sf;
caption[2] = cq;
caption[3] = '\0';
         }

    else {
caption[0] = p;      // assemble banner
caption[1] = sf;
caption[2] = cq;
caption[3] = '\0';
         }
                // display chosen arpeggio
banner(caption, SW);
                  
             // encoding and selection
switch(p)   // of Major and minor
           // arpeggios and their
{         // enharmonic transpositions
case 'A':        
        // negative numbers used as labels
       // for strings, -1 is the unused
      // bass string to aid transposition
     // -5's are skipPrint placeholders

  if (cq == 'M'){
G[0] = -1;
D[0] = -4; D[1] = -8; D[2] = -8; D[3] = 7;
A[0] = -3; A[1] = 4; A[2] = -8; A[3] = 7;
E[0] = -2; E[1] = -5; E[2] = 5; E[3] = -8;}

  if (cq == 'm'){
G[0] = -1;
D[0] = -4; D[1] = -5; D[2] = -8; D[3] = 7;
A[0] = -3; A[1] = -8; A[2] = 7; A[3] = -8;
E[0] = -2; E[1] = 5; E[2] = -8; E[3] = 8;}   

  break;

  case 'B':

  if (cq == 'M'){
G[0] = -4; G[1] = -8; G[2] = -8; G[3] = 4;
D[0] = -3; D[1] = 1; D[2] = -8; D[3] = 4;
A[0] = -2; A[1] = -5; A[2] = 2; A[3] = -8; 
E[0] = -1;}

  if (cq == 'm'){
G[0] = -4; G[1] = -5; G[2] = -8; G[3] = 4;
D[0] = -3; D[1] = -8; D[2] = 4; D[3] = -8;
A[0] = -2; A[1] = 2; A[2] = -8; A[3] = 5; 
E[0] = -1;}

  break;

  case 'C':

  if (cq == 'M'){
G[0] = -4; G[1] = -8; G[2] = -8; G[3] = 5;
D[0] = -3; D[1] = 2; D[2] = -8; D[3] = 5;
A[0] = -2; A[1] = -5; A[2] = 3; A[3] = -8; 
E[0] = -1;}

  if (cq == 'm'){
G[0] = -4; G[1] = -5; G[2] = -8; G[3] = 5;
D[0] = -3; D[1] = -8; D[2] = 5; D[3] = -8;
A[0] = -2; A[1] = 3; A[2] = -8; A[3] = 6; 
E[0] = -1;}

  break;

case 'D':

  if (cq == 'M'){
G[0] = -4; G[1] = -8; G[2] = -8; G[3] = 7;
D[0] = -3; D[1] = 4; D[2] = -8; D[3] = 7;
A[0] = -2; A[1] = -5; A[2] = 5; A[3] = -8; 
E[0] = -1;}

  if (cq == 'm'){
G[0] = -4; G[1] = -5; G[2] = -8; G[3] = 7;
D[0] = -3; D[1] = -8; D[2] = 7; D[3] = -8;
A[0] = -2; A[1] = 5; A[2] = -8; A[3] = 8; 
E[0] = -1;}

  break;

case 'E':

  if (cq == 'M'){
G[0] = -4; G[1] = -8; G[2] = -8; G[3] = 9;
D[0] = -3; D[1] = 6; D[2] = -8; D[3] = 9;
A[0] = -2; A[1] = -5; A[2] = 7; A[3] = -8; 
E[0] = -1;}

  if (cq == 'm'){
G[0] = -4; G[1] = -5; G[2] = -8; G[3] = 9;
D[0] = -3; D[1] = -8; D[2] = 9; D[3] = -8;
A[0] = -2; A[1] = 7; A[2] = -8; A[3] = 10;
E[0] = -1;}
   
  break;

case 'F':

  if (cq == 'M'){
G[0] = -4; G[1] = -8; G[2] = -8; G[3] = 10;
D[0] = -3; D[1] = 7; D[2] = -8; D[3] = 10;
A[0] = -2; A[1] = -5; A[2] = 8; A[3] = -8; 
E[0] = -1;}

  if (cq == 'm'){
G[0] = -1;
D[0] = -4; D[1] = -5; D[2] = -8; D[3] = 3;
A[0] = -3; A[1] = -8; A[2] = 3; A[3] = -8;
E[0] = -2; E[1] = 1; E[2] = -8; E[3] = 4;}
  
  break;

case 'G':

  if (cq == 'M'){
G[0] = -1;
D[0] = -4; D[1] = -8; D[2] = -8; D[3] = 5;
A[0] = -3; A[1] = 2; A[2] = -8; A[3] = 5;
E[0] = -2; E[1] = -5; E[2] = 3; E[3] = -8;}

  if (cq == 'm'){
G[0] = -1;
D[0] = -4; D[1] = -5; D[2] = -8; D[3] = 5;
A[0] = -3; A[1] = -8; A[2] = 5; A[3] = -8;
E[0] = -2; E[1] = 3; E[2] = -8; E[3] = 6;}
 
  break;
          
  }

  if (sf != ' ')
    transpose(sf, G, D, A, E);

if ((original_p == 'B') && (original_sf == '#') && (sf == 'x'))
  {
G[0] = -1;
D[0] = -4; D[1] = -8; D[2] = -8; D[3] = 5;
A[0] = -3; A[1] = 2; A[2] = -8; A[3] = 5;
E[0] = -2; E[1] = -5; E[2] = 3; E[3] = -8;          
  }

// print ascending and descending
// arpeggios in bass tablature format

printFrets(G, cq, original_p, original_sf);
printFrets(D, cq, original_p, original_sf);
printFrets(A, cq, original_p, original_sf);
printFrets(E, cq, original_p, original_sf);

while (i<strlen(pitch))
  {
    if (p == pitch[i])
      break;  // search for pitch 
    i++;
  }

switch (prog)
{
    case 1:
      prog = 4;
      p = pitch[i+3];
     
      if ((p == 'B') && (sf == '#'))
        sf = ' ';
      else if
         ((p == 'B') && (sf == ' '))
        sf = 'b';

       if ((original_p == 'F') && (original_sf == 'b') && (cq == 'M'))
        {
G[0] = -1;
D[0] = -4; D[1] = -8; D[2] = -8; D[3] = 8;
A[0] = -3; A[1] = 5; A[2] = -8; A[3] = 8;
E[0] = -2; E[1] = -5; E[2] = 6; E[3] = -8;
        }    // fixes BbbM as IV of FbM

     if ((original_p == 'F') && (original_sf == 'b') && (cq == 'm'))
        {
G[0] = -1;
D[0] = -4; D[1] = -5; D[2] = -8; D[3] = 8;
A[0] = -3; A[1] = -8; A[2] = 8; A[3] = -8;
E[0] = -2; E[1] = 6; E[2] = -8; E[3] = 9; 
        }    // fixes Bbbm as iv of Fbm
     
      break;
     
    case 4:
      prog = 5;
      p = pitch[i+4];    

      break;
     
    case 5:
      prog = 6;
      p = pitch[i+8];
      cq = 'M';
     
    if (original_sf == '#')
      sf = '#';

    if (original_sf == ' ')
      sf = ' ';

    if ((original_p == 'B') && (original_sf == ' '))
      sf = '#';

    if ((original_p == 'B') && (original_sf == 'b'))
    { sf = ' '; }
     
      break;

    default:
      break;
   
}

}  // end of chord progression loop

  return 0;

}

/****************************************/

void checkInput(char pitch[], char s_or_f[], char Mm[], char p, char sf, char cq)

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
      printf("\n\nError: invalid pitch \'%c\' entered\n", p);
      printf("choose from ");
      for (i=0; i<strlen(pitch)/2; i++)
        printf("%c", pitch[i]);
      newline(0);
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
      printf("\n\nError: invalid accidental \'%c\' entered\n", sf);
      printf("choose from # for sharp, b for flat or space for natural"); 
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
      printf("\n\nError: invalid chord quality \'%c\' entered\n", cq);
      printf("choose from %c or %c for Major or minor", Mm[0], Mm[1]); 
      exit(-1); 
    }
    
}

/****************************************/

void transpose(char sf, int G[], int D[], int A[], int E[])
{

int i;

switch (G[0])
   {

   case -1:
// adjust if top string is not played
  
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

   if (sf == 'b')    // decrease frets -1
     for (i=1; i<4; i++)
       { G[i]--; D[i]--; A[i]--; } 
  
   break;

   }
      
}

/****************************************/

void printFrets(int frets[], char cq, char original_p, char original_sf)
{

      // variables used to adjust symmetry

int i = 0, j = 1, k = 0, l = 0, m = 0;

           // check for double digit frets

  if ((frets[3] > 9) || (frets[2] > 9))
    l = 1;

  if ((frets[3] > 9) && (frets[2] > 9))
    l = 3;

  if (frets[0] == -4)          // G string
    {
    pipebar(0);

   
  if ((frets[1] >= -6) && (frets[1] <= -4))
      {           // skipPrint placeholder
      j++; k = 1;
      } 

  if ((frets[2] >= -6) && (frets[2] <= -4))
      {           // skipPrint placeholder
      j++; k = 1;
      }

  if ((frets[3] >= -6) && (frets[3] <= -4))
      {           // skipPrint placeholder
      j++; k = 1;
      }

  if (cq == 'm')
    { k = 0; m = -1; }

  if ((cq == 'M') && (frets[1] == 7))
    m = 2;

  if ((cq == 'M') && (frets[3] > 9))
    m = 0;

  if ((cq == 'm') && (frets[2] == 8))
    m = 1;

  if ((cq == 'm') && (frets[3] > 9))
    m = 0;

  if ((original_p == 'F') && (original_sf == 'b') && (frets[1] == frets[2]) && frets[3] == 7)
    { m = 0; k = 0; }
    // fixes BbbM as IV of FbM

  if ((original_p == 'F') && (original_sf == 'b') && (frets[1] != frets[2]) && (frets[3] == 7))
    { m = -1; k = 0; }
    // fixes Bbbm as iv of Fbm


  if (l==1)
    line(1);
  for (i=0; i<10+j-m; i++)   
  { line(1); }

    for (i=j; i<4; i++)// skip +1 in frets
      if ((frets[i] >= -9) && (frets[i] <= -7))
        if (l!=0)
          printf("-");
        else
          printf("--");
    else
      printf("%d---", frets[i]);   

    if ((cq == 'm') && (frets[2] == 8))
      ;
    else
      for (i=0; i<k; i++)
        line(1);

    pipebar(0);

    if ((cq == 'm') && (frets[2] == 8))
      ;

   for (i=3; i>j-1; i--)
     if ((frets[i] >= -9) && (frets[i] <= -7))
       printf("--");
    else
      printf("---%d", frets[i]);

   if (cq == 'm')
     m = 2;

   if (cq == 'M')
     m = 0;

   if (l==3)
     line(1);  

   if ((cq == 'm') && (frets[2] == 8))
     m = 2;

   if ((original_p == 'F') && (original_sf == 'b') && (frets[1] == frets[2]) && frets[3] == 7)
    m = 0;
    // fixes BbbM as IV of FbM

   if ((original_p == 'F') && (original_sf == 'b') && (frets[1] != frets[2]) && (frets[3] == 7))
   { m = 2; }
    // fixes Bbbm as iv of Fbm
    
    for (i=0; i<10-l+m; i++)
      line(1);
    pipebar(0);
    }

  if (frets[0] == -3)          // D string
    {
    pipebar(0);

  if ((frets[1] >= -6) && (frets[1] <= -4))
      {           // skipPrint placeholder
      j++; k = 1;
      } 

  if ((frets[2] >= -6) && (frets[2] <= -4))
      {           // skipPrint placeholder
      j++; k = 1;
      }

  if ((frets[3] >= -6) && (frets[3] <= -4))
      {           // skipPrint placeholder
      j++; k = 1;
      }

  if ((cq == 'M') && (frets[1] == 8))
    m = -1;

  if (cq == 'm')
    m = 2;

  if ((frets[1] == 8) && (cq == 'm'))
  { m = 3; }

    if ((cq == 'm') && (frets[1] == 7) && (frets[3] == 10))
      m = 1;

  if ((original_p == 'F') && (original_sf == 'b') && (frets[2] == 7))
  { m = 2; }

    if ((frets[1] == 8) && (frets[3] == 11))
      m = 0;

    for (i=0; i<6-l+m; i++)   
      line(1);      

    for (i=1; i<4; i++)
      if ((frets[i] >= -9) && (frets[i] <= -7))
        printf("--");
    else
      printf("-%d", frets[i]);   

  if (cq == 'm')
    m = 2;

  if ((cq == 'm') && (frets[1] == 8))
  { m = 2; }

    if ((cq == 'm') && (frets[1] == 7) && (frets[3] == 10))
      m = 1;

    for (i=0; i<7-m; i++)
      line(1);

    pipebar(0);

    for (i=0; i<6-m; i++)
      line(1);

    for (i=3; i>0; i--)
      if ((frets[i] >= -9) && (frets[i] <= -7))
      printf("--");
    else
      printf("-%d", frets[i]);

    if ((cq == 'm') && (frets[1] == 8))
      m = 3;
    else
      if (cq == 'm')
        m = 2;

    if ((cq == 'm') && (frets[1] == 7) && (frets[3] == 10))
      m = 1;
               
    for (i=0; i<6-l+m; i++)
      line(1);
    pipebar(0);
    }

  if (frets[0] == -2)          // A string
    {
    pipebar(0);

  if ((frets[1] >= -6) && (frets[1] <= -4))
      {           // skipPrint placeholder
      if (l==0)
        line(1);
      j++; k = 2;
      }

  if ((frets[2] >= -6) && (frets[2] <= -4))
      {           // skipPrint placeholder
      if (l==0)
        line(1);
      j++; k = 2;
      }

  if ((frets[3] >= -6) && (frets[3] <= -4))
      {           // skipPrint placeholder
      if (l==0)
        line(1);
      j++; k = 2;
      }

  if ((cq == 'm') && (original_p != 'F') && (original_sf != 'b'))
    line(1);

  if ((cq == 'm') && (original_p == 'F') && (original_sf != 'b'))
    line(1);

  if (((original_p == 'F') &&
      (original_sf == 'b') &&
     ((frets[1] == 5) && (frets[3] == 8)))
       ||
     ((frets[1] == 0) && (frets[3] == 3))
       ||
     ((frets[1] == 4) && (frets[3] == 7)
   && (original_sf != '#') && (cq == 'm'))
       ||
     (((frets[1] == 6) && (frets[3] == 9)
   && (original_sf != '#') &&
      (cq == 'm')))
       ||
     ((frets[1] == 1) && (frets[3] == 4)
   && (original_p != 'F') &&
      (original_p != 'C') && (cq == 'm'))
       ||
     ((frets[1] == 2) && (frets[3] == 5)
   && (original_p != 'B') && (original_sf != '#') && (cq == 'm')))
    line(1);

  if ((cq == 'm') && (frets[1] == 8) && (frets[2] != -7))
    for (i=j; i<4; i++)
      printf("-%d", frets[i]);  
    else 
      for (i=j; i<4; i++)
        if ((frets[i] >= -9) && (frets[i] <= -7))
          if ((frets[1] == 8) && (frets[3] == 11))
            ;

          else

          if ((((frets[1] == 5) && (frets[3] == 8)) && (cq == 'm')) || ((frets[1] == 0) && (frets[3] == 3)) ||  ((frets[i] >= -9) && (frets[i] <= -7)))
            putchar('-');
          else
              printf("--");
        else
          printf("--%d", frets[i]);   
       

    if (cq == 'm')
      m = -1;

    if (cq == 'M')
      m = 0;

    if ((cq == 'm') && (frets[1] == 7))
      m = 0;

    if ((cq == 'm') && (frets[3] == 8))
      m = -1;

    if ((original_p == 'F') && (original_sf == 'b') && (frets[1] == 5) && (frets[3] == 8))
    m = -1;

    if ((cq == 'm') && (frets[3] > 9))
      m = -2;

    if ((frets[1] == 8) && (frets[3] == 11))
      m = -1;

    if ((frets[1] == 4) && (frets[3] == 7) && (cq == 'm'))
      m = -1;

    if ((frets[1] == 6) && (frets[3] == 9) && (cq == 'm'))
      m = -1;

    for (i=0; i<12+k+m; i++)
      line(1);

    pipebar(0);

    if (cq == 'm')
      m = 0;

    if ((cq == 'm') && (frets[3] > 9))
      m = -1;

    if (cq == 'M')
      m = 3;

    if (((original_p == 'F') && (original_sf == 'b') && (frets[1] == 5) && (frets[3] == 8)) || ((frets[1] == 0) && (frets[3] == 3)))
      m = 0;

    if ((original_p == 'F') && (original_sf == 'b') && (frets[2] == 5))
      m = 3;    // fixes FbM

    if ((frets[1] == 8) && (frets[3] == 11))
      m = 0;

    for (i=0; i<12+m-1; i++)
      line(1);

    for (i=3; i>j-1; i--)
      if ((frets[i] >= -9) && (frets[i] <= -7))
        if ((frets[1] == 8) && (frets[3] == 11))
          ;

        else
       
        if (((frets[1] == 5) && (frets[3] == 8)) || ((frets[1] == 0) && (frets[3] == 3)) || ((frets[i] >= -9) && (frets[i] <= -7)))
            putchar('-');
        else
          printf("--");
      else
        printf("%d--", frets[i]);

    pipebar(0);
    }

  if (frets[0] == -1)  // E string
      centerLine("|", SW);
          // central alignment measure bar

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

  printf("%s", str);   // print scale name

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
  for(i=0; i<margin-1; i++)
   line(1);

  printf("%s", str);
// align center on either open string

  if ((length % 2) == 0)
  { margin-=1;
  } else {
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