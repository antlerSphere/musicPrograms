#include <stdio.h>

// original file for Online C Compiler
// title ascew, chart text screenwraps
// button indentations out of adjustment
// programmed in C by antlerSphere 
   
int main()     {
              
//  initialize variables
  int h = 0, i = 0, j = 0;
  int col, row;
  char *pitch = "ADGCFBEADG";
                          // pitch[h = 0-6]
  char *s_or_f = "#bx ";
                        // s_or_f[i = 0-3]   
  char *o7mM = "o7mM ";   
                      //  o7mM[j = 0-4]

//  print chart title
printf("\t\t+===========================+\n");
printf("\t\t|  Mirrored Accordion Chord Chart    |\n");
printf("\t\t+===========================+\n"); 
printf("\n");

// print chart based on input with optional borders
// printf("\nInput song to display:\n\n");

/* print top of border
if (loop == 0)
   printf("\t+");
  for (loop=0;loop<9;loop++)
    printf("-");
  printf("+\n");  */

  for (row=0; row<20; row++)  // go through rows
    {         

// printf("\t");

      for (col=0; col<6; col++)    // go through columns
        { 

     
        if ((row >= 0) && (row <= 4))
          i = 0;                                       // make it sharp

        if ((row >= 5) && (row <= 11))  // pitch without
          i = 3;                                      // an accidental
          
        if ((row >= 12) && (row <= 18))
          i = 1;                                      // make it flat


        if ((col >= 0) && (col <= 3))
           j = col;       // shift chord quality with column
        else
          j = 4;          // except for the bass note column

     
    if (col < 5)         // is it not yet the last column?
    {
     if (row == 19)  // print double flat row at the end
           printf("\t%1c%1c%1c%1c%3c", pitch[h], s_or_f[1], s_or_f[1], o7mM[j], ' '); 
     else                // or print current chord lined up
           {
// show button indentations with ( ) 's
if (((col == 4) && (row == 6)) || (row == 10) || (row == 14))
      printf("%3s%1c%1c%s", "( ", pitch[h], s_or_f[i], ")\t  "); 
else
    if (i == 3) //  adjust spacing if there's no accidental 
             printf("\t%1c%1c%1c%6c", pitch[h], s_or_f[i], o7mM[j], ' '); 
      else
           printf("\t%1c%1c%1c%5c", pitch[h], s_or_f[i], o7mM[j], ' ');
           
           }
    }
     else             // exception handling for last column
    {                   // print double sharp exceptions
    if ((col == 5) && (row == 0))
       printf("%1c%1c", pitch[h+3], s_or_f[2]);
    if ((col == 5) && (row == 1))
      printf("%1c%1c", pitch[h+3], s_or_f[2]);
     
    // print a sharp for upper bass notes    
    if ((row >= 2) && (row <= 8))
      printf("%1c%1c", pitch[h+3], s_or_f[0]); 
   
    // print just the pitch for middle bass notes
    if ((row >= 9) && (row <= 15))
      printf("%1c", pitch[h+3]);

    // print a flat for lower bass notes
    if ((row >= 16) && (row <= 19))
      printf("%1c%1c", pitch[h+3], s_or_f[1]);
    
    }
    
        }  // end of row for loop

printf("\n");

// determine if any chords in the grid were selected
// and print lower border respectively



printf("\n");

h++;     // rotate through seven pitches to print chart

if (h == 7)
   h = 0;
   
    }     // end of row for loop

return 0;
}