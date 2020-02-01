#include <stdio.h>
#include <string.h>     // strlen()
#include <stdlib.h>    // exit()
#include <ctype.h>    // toupper()
#define SW 40        // screen width

/* inputs and displays a triad on a 
   piano keyboard (landscape view)
   programmed in C by antlerSphere

   format: [A-G][#|' '|b][M|m|o|+]
   ex. C +   GbM   A#m   Fbo   Bb+   E m

   enharmonic equivalents chord chart:

   |  M|  m| #M| #m| bM| bm|#ob|#+b|
  -+---+---+---+---+---+---+---+---+
  A| X | X | X | X | X | X |XXX|XXX|
  -+---+---+---+---+---+---+---+---+
  B| X | X | X | X | X | X |XXX|XXX|
  -+---+---+---+---+---+---+---+---+
  C| X | X | X | X | X | X |XXX|XXX|
  -+---+---+---+---+---+---+---+---+
  D| X | X | X | X | X | X |XXX|XXX|
  -+---+---+---+---+---+---+---+---+
  E| X | X | X | X | X | X |XXX|XXX|
  -+---+---+---+---+---+---+---+---+
  F| X | X | X | X | X | X |XXX|XXX|
  -+---+---+---+---+---+---+---+---+       
  G| X | X | X | X | X | X |XXX|XXX|
  -+---+---+---+---+---+---+---+---+
      x = partial  X = complete
*/

typedef struct
{

  int root, third, fifth;   
    
} Note;

Note note;

char checkInput(char pitch[], char s_or_f[], char chord[], char p, char sf, char cq1);
Note storeOutput(char caption[]);
void topLine();
void blackKeys(int height, Note note, char keyValues[], char caption[]);
int drawBlackKeys(int numKeys, Note note, char keyValues[], char keyPos[], char caption[], int height, int pos);
void midLine();
void blackKeyFronts(int numKeys);
void whiteKeys(int height, Note note, char keyValues[], char caption[]);
void bottomLine();
void whiteKeyFronts(int numKeys);
void spaces(int num);
void pipebar();
void newline();

int main() 
{

char p, sf, cq1; 
// pitch, sharp or flat, chord quality
char pitch[] = "ABCDEFG ";   // note name
char s_or_f[] = "#b ";     // accidental
char chord[] = " M m o +";     
                          // chord quality
char keyValues[] = "C C#D D#E F F#G G#A A#B C C#D D#E F F#G G#A A#B C C#D D#E F F#G G#A A#B";

char caption[4];

printf("ex. [A-G][#|' '|b][M|m|o|+]\n");
printf("Enter pitch, accidental, type of chord: ");

scanf("%c%c%c", &p, &sf, &cq1);

p = toupper(p); // capitalize pitch letter

cq1 = checkInput(pitch, s_or_f, chord, p, sf, cq1);                

caption[0] = p;        //  assemble chord
caption[1] = sf;
caption[2] = cq1;
caption[3] = '\0';

note = storeOutput(caption);
                             
puts(caption);

  topLine();
  blackKeys(6, note, keyValues, caption);
  midLine();
  whiteKeys(2, note, keyValues, caption); 
  bottomLine();

// 
/*

  newline();
  printf("root = %d third = %d fifth = %d\n", note.root, note.third, note.fifth);

  printf("kV[root] = %c%c kV[3rd] = %c%c kV[5th] = %c%c\n", keyValues[2*note.root], keyValues[2*note.root+1], keyValues[2*note.third], keyValues[2*note.third+1], keyValues[2*note.fifth], keyValues[2*note.fifth+1]);

//
*/

return 0;

}

/****************************************/

char checkInput(char pitch[], char s_or_f[], char chord[], char p, char sf, char cq1)

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

while (i<strlen(chord))
  {
    if (cq1 == chord[i])
      break;  // search for chord quality 
    i++;
  }

  if ((i == strlen(chord)) && (cq1 != chord[i]))
    {         // verify chord quality
      printf("\n\nError: invalid chord quality \'%c\' entered\n", cq1);
      printf("choose from\n");
      for (i=8; i<strlen(chord)-2; i+=2)
        printf("\'%c\', ", chord[i+1]);
      printf("or \'%c\'\n", chord[i+1]);        
      exit(-1);  
    }

return cq1;
     
}

/****************************************/

Note storeOutput(char caption[])
{

switch (caption[0])
  {
  
  case 'A':
    if (caption[1] == '#')
      note.root = 10;
    else if (caption[1] == 'b')
      note.root = 8;
    else
      note.root = 9;               
    break;

  case 'B':
    if (caption[1] == '#')
      note.root = 12;
    else if (caption[1] == 'b')
      note.root = 10;
    else
      note.root = 11;
    break;

  case 'C':
    if (caption[1] == '#')
      note.root = 13;
    else if (caption[1] == 'b')
      note.root = 11;
    else
      note.root = 12;
    break;

  case 'D':
    if (caption[1] == '#')
      note.root = 3;
    else if (caption[1] == 'b')
      note.root = 1;
    else
      note.root = 2;
    break; 

  case 'E':
    if (caption[1] == '#')
      note.root = 5;
    else if (caption[1] == 'b')
      note.root = 3;
    else 
      note.root = 4;
    break;

  case 'F':
    if (caption[1] == '#')
      note.root = 6;
    else if (caption[1] == 'b')
      note.root = 4;
    else
      note.root = 5;
    break;

  case 'G':
    if (caption[1] == '#')
      note.root = 8;
    else if (caption[1] == 'b')
      note.root = 6;
    else
      note.root = 7;
    break;

  default:
    break;
    
  }

  note.fifth = note.root + 7;

  if (caption[2] == 'M')
    note.third = note.root + 4;

  if (caption[2] == 'm')
    note.third = note.root + 3;
        
  if (caption[2] == '+')
  { note.third = note.root + 4;
    note.fifth++; }

  if (caption[2] == 'o')
  { note.third = note.root + 3;
    note.fifth--; }
     
return note;    
}

/****************************************/

void topLine()
{

int i;

  spaces(1);

  for (i=0; i<2*SW-11; i++)
     putchar('_');      

  newline();
    
}

/****************************************/

void blackKeys(int height, Note note, char keyValues[], char caption[])
{

int i, j, pos = 0;

char keyPos[] = {'C', 'D', 'F', 'G', 'A', 'C', 'D', 'F', 'G', 'A', 'C', 'D', 'F', 'G', 'A'};

  for (i=0; i<height; i++)
  {
            
    pipebar();

    for (j=0; j<2; j++)
    {

    spaces(2);

    pos = drawBlackKeys(2, note, keyValues, keyPos, caption, i, pos);

    spaces(2);
    pipebar();
    spaces(2);

    pos = drawBlackKeys(3, note, keyValues, keyPos, caption, i, pos);      

    spaces(2);
    pipebar();
     
    }  // end of j loop

    newline();

  }  // end of i loop

  pipebar();  
    
}

/****************************************/

int drawBlackKeys(int numKeys, Note note, char keyValues[], char keyPos[], char caption[], int height, int pos)
{

int i;

  for (i=0; i<numKeys; i++)
  {
    pipebar();

// print the root

    if ((height == 4) && (keyValues[2*note.root] == keyPos[pos++]) && (caption[1] != ' ') && (note.root != 1)  && (note.root != 3) && (note.root != 5) && (note.root != 6) && (note.root != 8) && (note.root != 10) && (note.root != 12))      
      printf(" %c%c", keyValues[2*note.root], caption[1]);

    else if ((height == 4) && (keyValues[2*note.root] == keyPos[pos+4]) && (caption[1] == 'b') && (note.root == 8))
      printf(" %cb", keyValues[2*note.root+2]);  // AbM

    else if ((height == 4) && (keyValues[2*note.root] == keyPos[pos+4]) && (caption[1] == '#') && (note.root == 10))
      printf(" %c#", keyValues[2*note.root]);  // A#M

    else if ((height == 4) && (keyValues[2*note.root] == keyPos[pos+4]) && (caption[1] == 'b') && (note.root == 10))
      printf(" %cb", keyValues[2*note.root+2]);  // BbM, Bbm, Bbo

    else if ((height == 4) && (keyValues[2*note.root] == keyPos[pos+4]) && (caption[1] == 'b') && (note.root == 1))
      printf(" %cb", keyValues[2*note.root+2]);  // DbM

    else if ((height == 4) && (keyValues[2*note.root] == keyPos[pos+4]) && (caption[1] == '#') && (note.root == 3))
      printf(" %c#", keyValues[2*note.root]);  // D#M, D#m

    else if ((height == 4) && (keyValues[2*note.root] == keyPos[pos+4]) && (caption[1] == 'b') && (note.root == 3))
      printf(" %cb", keyValues[2*note.root+2]);  // EbM

    else if ((height == 4) && (keyValues[2*note.root] == keyPos[pos+4]) && (caption[1] == '#') && (note.root == 6))
      printf(" %c#", keyValues[2*note.root]);  // F#M, F#m
      
    else if ((height == 4) && (keyValues[2*note.root] == keyPos[pos+4]) && (caption[1] == 'b') && (note.root == 6))
      printf(" %cb", keyValues[2*note.root+2]);  // GbM, Gbm

    else if ((height == 4) && (keyValues[2*note.root] == keyPos[pos+4]) && (caption[1] == '#') && (note.root == 8))
      printf(" %c#", keyValues[2*note.root]);  // G#M, G#m
            
// print the 3rd

    else if ((height == 4) && (keyValues[2*note.third] == keyPos[pos+4]) && (caption[2] == 'M') && (note.root != 1) && (note.root != 3) && (note.root != 4) && (note.root != 5) && (note.root != 6) && (note.root != 8) && (note.root != 10) && (note.root != 11) && (note.root != 13))
      printf(" %c#", keyValues[2*note.third]);

    else if ((height == 4) && (caption[2] == 'm') && (keyValues[2*note.third] == keyPos[pos+4]) && (note.root != 3) && (note.root != 4) && (note.root != 5) && (note.root != 6) && (note.root != 9) && (note.root != 10) && (note.root != 11) && (note.root != 12) && (note.third != 5))
      printf(" %cb", keyValues[2*note.third+2]);          

  else if ((height == 4) && (keyValues[2*note.third] == keyPos[pos+4]) && (caption[1] == ' ') && (caption[2] == '+') && (note.root == 9))
    printf(" %c#", keyValues[2*note.third]);  // A +

  else if ((height == 4) && (keyValues[2*note.third] == keyPos[pos+4]) && (caption[1] == '#') && ((caption[2] == 'm') || (caption[2] == 'o')) && (note.root == 10))
    printf(" %c#", keyValues[2*note.third]);  // A#m

  else if ((height == 4) && (keyValues[2*note.third] == keyPos[pos+4]) && (caption[1] == 'b') && (caption[2] == 'm') && (note.root == 10))
    printf(" %cb", keyValues[2*note.third+2]);  // Bbm
    
  else if ((height == 4) && (keyValues[2*note.third] == keyPos[pos+4]) && (caption[1] == 'b') && (caption[2] == 'o') && (note.root == 10))
    printf(" %cb", keyValues[2*note.third+2]);  // Bbo

  else if ((height == 4) && (keyValues[2*note.third] == keyPos[pos+4]) && (caption[1] == ' ') && ((caption[2] == 'M') || (caption[2] == '+')) && (note.root == 11))
    printf(" %c#", keyValues[2*note.third]);  // B M, B +
    
  else if ((height == 4) && (keyValues[2*note.third] == keyPos[pos+4]) && (caption[1] == 'b') && ((caption[2] == 'M') || (caption[2] == '+')) && (note.root == 11))
    printf(" %cb", keyValues[2*note.third+2]);  // CbM, Cb+

  else if ((height == 4) && (keyValues[2*note.third] == keyPos[pos+4]) && (caption[1] == ' ') && (caption[2] == 'o') && (note.root == 12))
    printf(" %cb", keyValues[2*note.third+2]);  // C o
    
  else if ((height == 4) && (keyValues[2*note.third] == keyPos[pos+4]) && (caption[1] == '#') && ((caption[2] == 'm') || (caption[2] == 'o')) && (note.root == 12))
    printf(" %c#", keyValues[2*note.third]);  // B#m, B#o

    else if ((height == 4) && (keyValues[2*note.root] == keyPos[pos+3]) && (caption[1] == ' ') && (caption[2] == 'm') && (note.root == 12))
      printf(" %cb", keyValues[2*note.root+8]);  // Cm

  else if ((height == 4) && (keyValues[2*note.third] == keyPos[pos+4]) && (caption[1] == '#') && ((caption[2] == 'm') || (caption[2] == 'o')) && (note.root == 3))
    printf(" %c#", keyValues[2*note.third]);  // D#m

  else if ((height == 4) && (keyValues[2*note.third] == keyPos[pos+4]) && (caption[1] == ' ') && (caption[2] == '+') && (note.root == 2))
    printf(" %c#", keyValues[2*note.third]);  // D +

  else if ((height == 4) && (keyValues[2*note.third] == keyPos[pos+4]) && (caption[1] == 'b') && ((caption[2] == 'm') || (caption[2] == 'o')) && (note.root == 3))
    printf(" %cb", keyValues[2*note.third+2]);  // Ebm, Ebo

  else if ((height == 4) && (keyValues[2*note.third] == keyPos[pos+4]) && (caption[1] == ' ') && ((caption[2] == 'M') || (caption[2] == '+')) && (note.root == 4))
    printf(" %c#", keyValues[2*note.third]);  // E M, E +

  else if ((height == 4) && (keyValues[2*note.third] == keyPos[pos+4]) && (caption[1] == '#') && ((caption[2] == 'm') || (caption[2] == 'o')) && (note.root == 5))
    printf(" %c#", keyValues[2*note.third]);  // E#m, E#o

  else if ((height == 4) && (keyValues[2*note.third] == keyPos[pos+4]) && (caption[1] == 'b') && ((caption[2] == 'M') || (caption[2] == '+')) && (note.root == 4))
    printf(" %cb", keyValues[2*note.third+2]);  // FbM

    else if ((height == 4) && (keyValues[2*note.third] == keyPos[pos+4]) && (caption[1] == ' ') && ((caption[2] == 'm') || (caption[2] == 'o')) && (note.root == 5)) 
      printf(" %cb", keyValues[2*note.third+2]);  // F m, F,o

  else if ((height == 4) && (keyValues[2*note.third] == keyPos[pos+4]) && (caption[1] == '#') && ((caption[2] == 'M') || (caption[2] == '+')) && (note.root == 6))
    printf(" %c#", keyValues[2*note.third]);  // F#M, F#+

  else if ((height == 4) && (keyValues[2*note.third] == keyPos[pos+4]) && (caption[1] == 'b') && ((caption[2] == 'M') || (caption[2] == '+')) && (note.root == 6))
    printf(" %cb", keyValues[2*note.third+2]);  // GbM, Gb+

  else if ((height == 4) && (keyValues[2*note.third] == keyPos[pos+4]) && (caption[2] == 'o') && (note.root == 7))
    printf(" %cb", keyValues[2*note.third+2]);  // G o
       
    else if ((height == 4) && (keyValues[2*note.third] == keyPos[pos+4]) && (caption[2] == 'm') && (note.third == 6) && (note.root != 3))
      printf(" %c#", keyValues[2*note.third]);

// print the 5th

    else if ((height == 4) && (keyValues[2*note.fifth] == keyPos[pos+4]) && (caption[1] == '#') && (caption[2] == '+') && (note.root == 10))
printf(" %cx",keyValues[2*note.fifth-4]);
// A#+

    else if ((height == 4) && (keyValues[2*note.fifth] == keyPos[pos+4]) && (caption[1] == ' ') && (caption[2] == '+') && (note.root == 11))
    printf("   ");  // B +

    else if ((height == 4) && (keyValues[2*note.fifth] == keyPos[pos+4]) && (caption[1] == 'b') && (caption[2] == 'o') && (note.root == 11))
    printf("   ");  // Cbo

    else if ((height == 4) && (keyValues[2*note.fifth] == keyPos[pos+4]) && (caption[1] == 'b') && (caption[2] == '+') && (note.root == 11))
    printf("   ");  // Cb+

   else if ((height == 4) && (keyValues[2*note.fifth] == keyPos[pos+4]) && (caption[1] == '#') && (caption[2] == 'o') && (note.root == 13))
    printf("   ");  // C#o

   else if ((height == 4) && (keyValues[2*note.fifth] == keyPos[pos+4]) && (caption[1] == '#') && (caption[2] == '+') && (note.root == 13))
    printf("   ");  // C#+

    else if ((height == 4) && (keyValues[2*note.fifth] == keyPos[pos+4]) && (caption[1] == '#') && (caption[2] == 'o') && (note.root == 3))
    printf("   ");  // D#o

    else if ((height == 4) && (keyValues[2*note.fifth] == keyPos[pos+4]) && (caption[1] == 'b') && (caption[2] == 'o') && (note.root == 1))
    printf("   ");  // Dbo

    else if ((height == 4) && (keyValues[2*note.fifth] == keyPos[pos+4]) && (caption[1] == 'b') && (caption[2] == '+') && (note.root == 1))
    printf("   ");  // Db+

    else if ((height == 4) && (keyValues[2*note.fifth] == keyPos[pos+4]) && (caption[1] == 'b') && (caption[2] == 'o') && (note.root == 3))
    printf("   ");  // Ebo

    else if ((height == 4) && (keyValues[2*note.fifth] == keyPos[pos+4]) && (caption[1] == '#') && (caption[2] == 'o') && (note.root == 6))
    printf("   ");  // F#o

    else if ((height == 4) && (keyValues[2*note.fifth] == keyPos[pos+4]) && (caption[1] == 'b') && ((caption[2] == 'o') || (caption[2] == '+')) && (note.root == 6))
    printf("   ");  // Gbo, Gb+

    else if ((height == 4) && (keyValues[2*note.fifth] == keyPos[pos+4]) && (caption[1] == '#') && (caption[2] == 'o') && (note.root == 8))
    printf("   ");  // G#o
       
    else if ((height == 4) && (keyValues[2*note.fifth] == keyPos[pos+4]) && (caption[1] != ' ') && (note.root != 1) && (note.root != 3) && (note.root != 4) && (note.root != 5) && (note.root != 6) && (note.root != 8) && (note.root != 10) && (note.root != 12) && (note.fifth != 18))
      printf(" %c%c",keyValues[2*note.fifth], caption[1]);

    else if ((height == 4) && (keyValues[2*note.fifth] == keyPos[pos+4]) && (caption[1] == 'b') && (note.root == 8) && (caption[2]) != 'o')
printf(" %cb",keyValues[2*note.fifth+2]);
// AbM, Abm

    else if ((height == 4) && (keyValues[2*note.fifth] == keyPos[pos+4]) && (caption[2] == 'o') && (note.root == 9))
printf(" %cb",keyValues[2*note.fifth+2]);
// A o

    else if ((height == 4) && (keyValues[2*note.fifth] == keyPos[pos+4]) && (caption[1] == 'b') && (caption[2] == '+') && (note.root == 10))
printf(" %c#",keyValues[2*note.fifth]);
// Bb+
    
    else if ((height == 4) && (keyValues[2*note.fifth] == keyPos[pos+4]) && (note.root == 11) && (caption[1] != 'b') && (caption[2] != 'o'))
    printf(" %c#", keyValues[2*note.fifth]); // B M, B m

    else if ((height == 4) && (keyValues[2*note.fifth] == keyPos[pos+4]) && (note.root == 12) && (caption[1] == '#') && (caption[2] == 'o'))
    printf(" %c#", keyValues[2*note.fifth]);  // B#o

    else if ((height == 4) && (keyValues[2*note.fifth] == keyPos[pos+4]) && (caption[1] != ' ') && (caption[2] == '+') && (note.root == 12))
printf("%c#x",keyValues[2*note.fifth-4]);
// B#+

    else if ((height == 4) && (keyValues[2*note.fifth] == keyPos[pos+4]) && (caption[2] == '+') && (note.root == 12))
printf(" %c#",keyValues[2*note.fifth]);
// C +
        
  else if ((height == 4) && (keyValues[2*note.fifth] == keyPos[pos+4]) && (caption[1] == 'b') && (note.root == 11))
    printf(" %cb", keyValues[2*note.fifth+2]);  // CbM, Cbm

  else if ((height == 4) && (keyValues[2*note.fifth] == keyPos[pos+4]) && (caption[1] == ' ') && (caption[2] == 'o') && (note.root == 12))
    printf(" %cb", keyValues[2*note.fifth+2]);  // C o

    else if ((height == 4) && (keyValues[2*note.fifth] == keyPos[pos+4]) && (caption[1] == 'b') && (note.root == 1))       
    printf(" %cb", keyValues[2*note.fifth+2]);  // DbM, Dbm   

  else if ((height == 4) && (keyValues[2*note.fifth] == keyPos[pos+4]) && (caption[2] == 'o') && (note.root == 2))
    printf(" %cb", keyValues[2*note.fifth+2]);  // D o

    else if ((height == 4) && (keyValues[2*note.fifth] == keyPos[pos+4]) && (caption[1] == ' ') && (caption[2] == '+') && (note.root == 2))
    printf(" %c#", keyValues[2*note.fifth]);  // D +

    else if ((height == 4) && (keyValues[2*note.fifth] == keyPos[pos+4]) && (caption[1] == '#') && ((caption[2] == 'M') || (caption[2] == 'm')) && (note.root == 3))
    printf(" %c#", keyValues[2*note.fifth]);  // D#M, D#m

    else if ((height == 4) && (keyValues[2*note.fifth] == keyPos[pos+4]) && (caption[1] == 'b') && (note.root == 3))
      printf(" %cb", keyValues[2*note.fifth+2]);  // EbM, Ebm

    else if ((height == 4) && (keyValues[2*note.fifth] == keyPos[pos+4]) && (caption[1] == ' ') && (caption[2] == 'o') && (note.root == 4))
      printf(" %cb", keyValues[2*note.fifth+2]);  // E o

    else if ((height == 4) && (keyValues[2*note.fifth] == keyPos[pos+4]) && (caption[1] == '#') && (caption[2] == '+') && (note.root == 5)) 
      printf(" %cx", keyValues[2*note.fifth-4]);  // E#+

    else if ((height == 4) && (keyValues[2*note.fifth] == keyPos[pos+4]) && (caption[1] == 'b') && (caption[2] == 'o') && (note.root == 4))
    printf("%cbb", keyValues[2*note.fifth+4]);// Fbo

    else if ((height == 4) && (keyValues[2*note.fifth] == keyPos[pos+4]) && (caption[1] == ' ') && (caption[2] == '+') && (note.root == 5)) 
      printf(" %c#", keyValues[2*note.fifth]);  // F +

    else if ((height == 4) && (keyValues[2*note.fifth] == keyPos[pos+4]) && (caption[1] == '#') && ((caption[2] == 'M') || (caption[2] == 'm')) && (note.root == 6)) 
      printf(" %c#", keyValues[2*note.fifth]);  // F#M, F#m

    else if ((height == 4) && (keyValues[2*note.fifth] == keyPos[pos+4]) && (caption[1] == 'b') && (note.root == 6))
      printf(" %cb", keyValues[2*note.fifth+2]);  // GbM, Gbm

    else if ((height == 4) && (keyValues[2*note.fifth] == keyPos[pos+4]) && (note.root == 8) && (caption[1] == '#'))
    printf(" %c#", keyValues[2*note.fifth]);  // G#M, G#m

    else if ((height == 4) && (keyValues[2*note.fifth] == keyPos[pos+4]) && (caption[2] == 'o') && (note.root == 7))
      printf(" %cb", keyValues[2*note.fifth+2]);  // G o

    else if ((height == 4) && (keyValues[2*note.fifth] == keyPos[pos+4]) && (caption[1] == ' ') && (caption[2] == '+') && (note.root == 7))
      printf(" %c#", keyValues[2*note.fifth-2]);  // G +

    else
      printf("   ");

    pipebar();
  }  

return pos;
    
}

/****************************************/

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

/****************************************/

void blackKeyFronts(int numKeys)
{

int i;

  for(i=0; i<numKeys; i++)
    printf("\'===\'");
    
}

/****************************************/

void whiteKeys(int height, Note note, char keyValues[], char caption[])
{

int i, j;

char keyPos[] = {'C', 'D', 'E', 'F', 'G', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'A', 'B'};

  for (j=0; j<height; j++)
  {
  pipebar();

  for(i=0; i<14; i++)

// print the root

    if ((j == 1) && (keyValues[2*note.root] == keyPos[i]) && (caption[1] == ' '))
      printf(" %c  |", keyValues[2*note.root]);

    else if ((j) && (keyValues[2*note.root] == keyPos[i]) &&  (caption[1] == '#') && (note.root == 12)) 
      printf(" %c# |", keyValues[2*note.root-2]);  // B#M, B#m

    else if ((j) && (keyValues[2*note.root] == keyPos[i]) &&  (caption[1] == 'b') && (note.root == 11)) 
      printf(" %cb |", keyValues[2*note.root+2]);  // CbM, Cbm

    else if ((j) && (keyValues[2*note.root] == keyPos[i]) &&  (caption[1] == '#') && (note.root == 5)) 
      printf(" %c# |", keyValues[2*note.root-2]);  // E#M, E#m

    else if ((j) && (keyValues[2*note.root] == keyPos[i]) && (caption[1] == 'b') && (note.root == 4)) 
      printf(" %cb |", keyValues[2*note.root+2]);  // FbM, Fbm

// print the 3rd

    else if ((j) && (keyValues[2*note.third] == keyPos[i]) && (caption[1] != '#') && (caption[2] == 'M') && (keyValues[2*note.third+1] == '#'))
      printf("    |");  // DM, EM, AM, BM

    else if ((j) && (keyValues[2*note.third] == keyPos[i]) && (caption[1] == '#') && ((caption[2] == 'M') || (caption[2] == '+')) && (note.root == 10)) 
      printf(" %cx |", keyValues[2*note.third-2]);  // A#M

    else if ((j) && (keyValues[2*note.third] == keyPos[i]) && (caption[1] == ' ') && ((caption[2] == 'm') || (caption[2] == 'o')) && (note.root == 9)) 
      printf(" %c  |", keyValues[2*note.third]);  // A m, A o

    else if ((j) && (keyValues[2*note.third] == keyPos[i]) && (caption[1] == 'b') && (caption[2] == '+') && (note.root == 8)) 
      printf(" %c  |", keyValues[2*note.third]);  // Ab+
      
    else if ((j) && (keyValues[2*note.third] == keyPos[i]) && (caption[1] == 'b') && ((caption[2] == 'm') || (caption[2] == 'o')) && (note.root == 8)) 
      printf(" %cb |", keyValues[2*note.third+2]);  // Abm, Abo

    else if ((j) && (keyValues[2*note.third] == keyPos[i]) && (caption[1] == 'b') && ((caption[2] == 'M') || (caption[2] == '+')) && (note.root == 10)) 
      printf(" %c  |", keyValues[2*note.third]);  // BbM, Bb+

    else if ((j) && (keyValues[2*note.third] == keyPos[i]) && (caption[1] == ' ') && ((caption[2] == 'm') || (caption[2] == 'o')) && (note.root == 11)) 
      printf(" %c  |", keyValues[2*note.third]);  // Bm, Bo

    else if ((j) && (keyValues[2*note.third] == keyPos[i]) && (caption[1] == '#') && ((caption[2] == 'M') || (caption[2] == '+')) && (note.root == 12)) 
      printf(" %cx |", keyValues[2*note.third-2]);  // B#M

  else if ((j) && (keyValues[2*note.third] == keyPos[i]) && (caption[1] == 'b') && ((caption[2] == 'm') || (caption[2] == 'o')) && (note.root == 11))
    printf("%cbb |", keyValues[2*note.third+4]);  // Cbm, Cbo

    else if ((j) && (keyValues[2*note.third] == keyPos[i]) && (caption[1] == ' ') && (caption[2] == '+') && (note.root == 12)) 
      printf(" %c  |", keyValues[2*note.third]);  // C +
      
    else if ((j) && (keyValues[2*note.third] == keyPos[i]) && (caption[1] == '#') && ((caption[2] == 'M') || (caption[2] == '+')) && (note.root == 13)) 
      printf(" %c# |", keyValues[2*note.third-2]);  // C#M, C#+

    else if ((j) && (keyValues[2*note.third] == keyPos[i]) && (caption[1] == '#') && (caption[2] == 'o') && (note.root == 13)) 
      printf(" %c  |", keyValues[2*note.third]);  // C#o

    else if ((j) && (keyValues[2*note.third] == keyPos[i]) && (caption[1] == ' ') && ((caption[2] == 'm') || (caption[2] == 'o')) && (note.root == 2)) 
      printf(" %c  |", keyValues[2*note.third+2]);  // Dm, Do

    else if ((j) && (keyValues[2*note.third] == keyPos[i]) && (caption[1] == 'b') && ((caption[2] == 'm') || (caption[2] == 'o')) && (note.root == 1)) 
      printf(" %cb |", keyValues[2*note.third+2]);  // Dbm

    else if ((j) && (keyValues[2*note.third] == keyPos[i]) && (caption[1] == 'b') && (caption[2] == '+') && (note.root == 1)) 
      printf(" %c  |", keyValues[2*note.third]);  // Db+

    else if ((j) && (keyValues[2*note.third] == keyPos[i]) && (caption[1] == '#') && ((caption[2] == 'M') || (caption[2] == '+')) && (note.root == 3)) 
      printf(" %cx |", keyValues[2*note.third-2]);  // D#M

    else if ((j) && (keyValues[2*note.third] == keyPos[i]) && (caption[1] == 'b') && (caption[2] == '+') && (note.root == 3)) 
      printf(" %c  |", keyValues[2*note.third]);  // Eb+

  else if ((j) && (keyValues[2*note.third] == keyPos[i]) && (caption[1] == ' ') && ((caption[2] == 'm') || (caption[2] == 'o')) && (note.root == 4))
    printf(" %c  |", keyValues[2*note.third]);  // Em, E o

    else if ((j) && (keyValues[2*note.third] == keyPos[i]) && (caption[1] == '#') && ((caption[2] == 'M') || (caption[2] == '+')) && (note.root == 5)) 
      printf(" %cx |", keyValues[2*note.third-2]);  // E#M

    else if ((j) && (keyValues[2*note.third] == keyPos[i]) && (caption[1] == ' ') && (caption[2] == '+') && (note.root == 5)) 
      printf(" %c  |", keyValues[2*note.third]);  // F +

    else if ((j) && (keyValues[2*note.third] == keyPos[i]) && (caption[1] == '#') && ((caption[2] == 'm') || (caption[2] == 'o')) && (note.root == 6)) 
      printf(" %c  |", keyValues[2*note.third]);  // F#m

    else if ((j) && (keyValues[2*note.third] == keyPos[i]) && (caption[1] == 'b') && ((caption[2] == 'm') || (caption[2] == 'o')) && (note.root == 4)) 
      printf("%cbb |", keyValues[2*note.third+4]);  // Fbm

    else if ((j) && (keyValues[2*note.third] == keyPos[i]) && (caption[1] == 'b') && ((caption[2] == 'm') || (caption[2] == 'o')) && (note.root == 6)) 
      printf("%cbb |", keyValues[2*note.third+4]);  // Gbm, Gbo

    else if ((j) && (keyValues[2*note.third] == keyPos[i]) && (caption[1] == '#') && ((caption[2] == 'M') || (caption[2] == '+')) && (note.root == 8)) 
      printf(" %c# |", keyValues[2*note.third-2]);  // G#M, G#+

    else if ((j) && (keyValues[2*note.third] == keyPos[i]) && (caption[1] == ' ') && ((caption[2] == 'M') || (caption[2] == '+')) && (note.root == 7)) 
      printf(" %c  |", keyValues[2*note.third]);  // G M, G +
      
    else if ((j) && (keyValues[2*note.third] == keyPos[i]) && (caption[1] == '#') && ((caption[2] == 'm') || (caption[2] == 'o')) && (note.root == 8)) 
      printf(" %c  |", keyValues[2*note.third]);  // G#m
            
    else if ((j) && (keyValues[2*note.third] == keyPos[i]) && (caption[1] != '#') && (caption[2] == 'M'))
      printf(" %c  |", keyValues[2*note.third]);

    else if ((j) && (keyValues[2*note.third] == keyPos[i]) && (caption[1] == '#') && (caption[2] == 'm') && (note.root == 13))
      printf(" %c  |", keyValues[2*note.third]);

    else if ((j) && (keyValues[2*note.third] == keyPos[i]) && (caption[2] == 'm') && (note.third != 4))   
   printf("    |");           

// print the 5th

    else if ((j) && (keyValues[2*note.fifth] == keyPos[i]) && (caption[1] == ' ') && ((note.root >= 11) || (note.root <= 23)) && (note.fifth != 18) && (caption[2] != 'o') && (caption[2] != '+'))
      printf(" %c  |", keyValues[2*note.fifth]);

    else if ((j) && (keyValues[2*note.fifth] == keyPos[i]) && (caption[1] == ' ') && (caption[2] == '+') && (note.root == 9)) 
      printf(" %c# |", keyValues[2*note.fifth-2]);  // A +

    else if ((j) && (keyValues[2*note.fifth] == keyPos[i]) && (caption[1] == '#') && (note.root == 10) && (caption[2] != 'o') && (caption[2] != '+')) 
      printf(" %c# |", keyValues[2*note.fifth-2]);  // A#M, A#m

    else if ((j) && (keyValues[2*note.fifth] == keyPos[i]) && (caption[1] == '#') && (caption[2] == 'o') && (note.root == 10)) 
      printf(" %c  |", keyValues[2*note.fifth]);  // A#o

    else if ((j) && (keyValues[2*note.fifth] == keyPos[i]) && (caption[1] == 'b') && (caption[2] == 'o') && (note.root == 8)) 
      printf("%cbb |", keyValues[2*note.fifth+4]);  // Abo

    else if ((j) && (keyValues[2*note.fifth] == keyPos[i]) && (caption[1] == 'b') && (caption[2] == '+') && (note.root == 8)) 
      printf(" %c  |", keyValues[2*note.fifth]);  // Ab+

    else if ((j) && (keyValues[2*note.fifth] == keyPos[i]) && (caption[1] == '#') && (caption[2] != 'o') && (caption[2] != '+') && (note.root == 12)) 
      printf(" %cx |", keyValues[2*note.fifth-2]);  // B#M, B#m

    else if ((j) && (keyValues[2*note.fifth] == keyPos[i]) && (caption[1] == 'b') && (caption[2] == '+') && (note.root == 10)) 
      printf("    |", keyValues[2*note.fifth]);  // Bb+

    else if ((j) && (keyValues[2*note.fifth] == keyPos[i]) && (caption[1] == ' ') && (caption[2] == 'o') && (note.root == 11)) 
      printf(" %c  |", keyValues[2*note.fifth]);  // B o

    else if ((j) && (keyValues[2*note.fifth] == keyPos[i]) && (caption[1] == ' ') && (caption[2] == '+') && (note.root == 11)) 
      printf(" %cx |", keyValues[2*note.fifth-2]);  // B +

    else if ((j) && (keyValues[2*note.fifth] == keyPos[i]) && (caption[1] == 'b') && (caption[2] == 'o') && (note.root == 10)) 
      printf(" %cb |", keyValues[2*note.fifth+2]);  // Bbo
      
    else if ((j) && (keyValues[2*note.fifth] == keyPos[i]) && (caption[1] == 'b') && (note.root == 10)) 
      printf(" %c  |", keyValues[2*note.fifth]);

    else if ((j) && (keyValues[2*note.fifth] == keyPos[i]) && (caption[1] == 'b') && (caption[2] == 'o') && (note.root == 11)) 
      printf("%cbb |", keyValues[2*note.fifth+4]);  // Cbo

    else if ((j) && (keyValues[2*note.fifth] == keyPos[i]) && (caption[1] == 'b') && (caption[2] == '+') && (note.root == 11)) 
      printf(" %c  |", keyValues[2*note.fifth]);  // Cb+
      
  else if ((j) && (keyValues[2*note.fifth] == keyPos[i]) && (caption[1] == '#') && (caption[2] == 'o') && (note.root == 13))
    printf(" %c  |", keyValues[2*note.fifth]);  // C#o

  else if ((j) && (keyValues[2*note.fifth] == keyPos[i]) && (caption[1] == '#') && (caption[2] == '+') && (note.root == 13))
    printf(" %cx |", keyValues[2*note.fifth-2]);  // C#+

    else if ((j) && (keyValues[2*note.fifth] == keyPos[i]) && (caption[1] == '#') && (caption[2] == 'o') && (note.root == 3)) 
      printf(" %c  |", keyValues[2*note.fifth]);  // D#o

    else if ((j) && (keyValues[2*note.fifth] == keyPos[i]) && (caption[1] == '#') && (caption[2] == '+') && (note.root == 3)) 
      printf(" %cx |", keyValues[2*note.fifth-2]);  // D#+

    else if ((j) && (keyValues[2*note.fifth] == keyPos[i]) && (caption[2] == 'o') && (note.root == 1)) 
      printf("%cbb |", keyValues[2*note.fifth+4]);  // Dbo

    else if ((j) && (keyValues[2*note.fifth] == keyPos[i]) && (caption[1] == 'b') && (caption[2] == '+') && (note.root == 1)) 
      printf(" %c  |", keyValues[2*note.fifth]);  // Db+

    else if ((j) && (keyValues[2*note.fifth] == keyPos[i]) && (caption[1] == ' ') && (caption[2] == '+') && (note.root == 4))
      printf(" %c# |", keyValues[2*note.fifth-2]);  // E +

    else if ((j) && (keyValues[2*note.fifth] == keyPos[i]) && (caption[1] == '#') && (caption[2] == 'o') && (note.root == 5)) 
      printf(" %c  |", keyValues[2*note.fifth]);  // E#o

    else if ((j) && (keyValues[2*note.fifth] == keyPos[i]) && (caption[1] == '#') && (caption[2] == '+') && (note.root == 5)) 
      printf("    |");  // E#+
                
    else if ((j) && (keyValues[2*note.fifth] == keyPos[i]) && (caption[1] == '#') && (caption[2] != 'o') && (note.root == 5)) 
      printf(" %c# |", keyValues[2*note.fifth-2]);  // E#M, E#m

    else if ((j) && (keyValues[2*note.fifth] == keyPos[i]) && (caption[2] == 'o') && (note.root == 3)) 
      printf("%cbb |", keyValues[2*note.fifth+4]);  // Ebo

    else if ((j) && (keyValues[2*note.fifth] == keyPos[i]) && (caption[1] == 'b') && (caption[2] == '+') && (note.root == 3)) 
      printf(" %c  |", keyValues[2*note.fifth]);  // Eb+

    else if ((j) && (keyValues[2*note.fifth] == keyPos[i]) && (caption[1] == 'b') && (caption[2] != 'o') && (caption[2] != '+') && (note.root == 4)) 
      printf(" %cb |", keyValues[2*note.fifth+2]);  // FbM, Fbm

    else if ((j) && (keyValues[2*note.fifth] == keyPos[i]) && (caption[1] == 'b') && (caption[2] == '+') && (note.root == 4)) 
      printf(" %c  |", keyValues[2*note.fifth]);  // Fb+
      
    else if ((j) && (keyValues[2*note.fifth] == keyPos[i]) && (caption[2] == 'o') && (note.root == 5)) 
      printf(" %cb |", keyValues[2*note.fifth+2]);  // F o

    else if ((j) && (keyValues[2*note.fifth] == keyPos[i]) && (caption[1] == '#') && (caption[2] == 'o') && (note.root == 6)) 
      printf(" %c  |", keyValues[2*note.fifth]);  // F#o

    else if ((j) && (keyValues[2*note.fifth] == keyPos[i]) && (caption[1] == '#') && (caption[2] == '+') && (note.root == 6)) 
      printf(" %cx |", keyValues[2*note.fifth-2]);  // F#+

    else if ((j) && (keyValues[2*note.fifth] == keyPos[i]) && (caption[1] == '#') && (caption[2] == 'o') && (note.root == 8)) 
      printf(" %c  |", keyValues[2*note.fifth]);  // G#o

    else if ((j) && (keyValues[2*note.fifth] == keyPos[i]) && (caption[1] == '#') && (caption[2] == '+') && (note.root == 8)) 
      printf(" %cx |", keyValues[2*note.fifth-2]);  // G#+

    else if ((j) && (keyValues[2*note.fifth] == keyPos[i]) && (caption[1] == 'b') && (caption[2] == 'o') && (note.root == 6)) 
      printf(" %cbb|", keyValues[2*note.fifth+4]);  // Gbo

    else if ((j) && (keyValues[2*note.fifth] == keyPos[i]) && (caption[1] == 'b') && (caption[2] == '+') && (note.root == 6)) 
      printf(" %c  |", keyValues[2*note.fifth]);  // Gb+

    else        
      printf("%4c|", ' '); 
   
  newline();
  }
    
}

/****************************************/

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

/****************************************/

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

/****************************************/

void spaces(int num)
{

int i;

  for (i=0; i<num; i++)    
    putchar(' ');   
    
}

/****************************************/

void pipebar()
{
      
  putchar('|');
      
}

/****************************************/

void newline()
{
    
  putchar('\n');   
    
}

/****************************************/