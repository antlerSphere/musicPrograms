/*
chordchart2.php --> JS by antlerSphere 
Generates a mirror reflected accordion 
bass chord chart. Highlights selected
buttons read from a string in the bass 
note columns.
*/

var h = 0;
var i = 0;
var j = 0;

var pitch = "ADGCFBEADG";                        
var s_or_f = "#bx ";                      
var o7mM = "o7mM ";   

// /*
var songName = "Magitek Factory";
var bassNotes = "D# E G# A C# F# C B ";
// */

// 
/*
var songName = "Fireman";
var bassNotes = "E# A# B D# G# A C# D F# B E F ";
// 
*/

/*****************************************/

function checkRows(row)
{
if ((row >= 0) && (row <= 4))    
  return 0;

if ((row >= 5) && (row <= 11))
  return 3;

if ((row >= 12) && (row <= 18))
  return 1;      
}

/*****************************************/

function checkCols(col)
{
if ((col >= 0) && (col <= 3))   
  return col;    
}

/*****************************************/

function checkColRow(col, row)
{    
if ((col == 5) && ((row == 0) || (row == 1)))  
  return 5;

if ((col == 4) && ((row >= 5) && (row <= 11)))
  return 4;    
}

/*****************************************/

function checkButton(col, row)
{
if ((col == 4) && (((row == 6) || (row == 10)) || (row == 14)))
  return 6;   
}

/*****************************************/

function checkBassRows(row)   
{
if ((row >= 2) && (row <= 8))
  return 2;

if ((row >= 9) && (row <= 15))
  return 9;
  
if ((row >= 16) && (row <= 18))
  return 16;   
}

/*****************************************/

document.write(songName + ":<br>");
document.write(bassNotes);

document.write("<center>");

for (row = 0; row < 20; row++)
{        
i = checkRows(row);

document.write("<table><tr>");
  
for (col = 0; col < 6; col++)
{   
j = checkCols(col);

if (j != col) 
  j = 4;        
      
if (col < 5)
  {
  if (row == 19)
    note = pitch[h] + s_or_f[1] + s_or_f[1] + o7mM[j];           
  else
    {       
    if (checkButton(col, row) == 6)
      {
      if (s_or_f[i] == ' ')
        note = '(' + pitch[h] + ')';
      else
        note = '(' + pitch[h] + s_or_f[i] + ')';     
      } 
    else
      if (checkColRow(col, row) == 4)
        note = pitch[h] + s_or_f[i];
      else
     note = pitch[h] + s_or_f[i] + o7mM[j]; 
    }
  }
    else 
    {
    if (checkColRow(col, row) == 5)
      note = pitch[h+3] + s_or_f[2];

    switch (checkBassRows(row))
    {
      case 2:
      note = pitch[h+3] + s_or_f[0];
      break;
      
      case 9:
      note = pitch[h+3] + s_or_f[3];
      break;
      
      case 16:
      note = pitch[h+3] + s_or_f[1];
      break;          
    }

    if (row == 19)
      note = pitch[h+3] + s_or_f[1];  
    }   

var Note = new RegExp(note);

if (Note.test(bassNotes))
  document.write("<th bgcolor=white><font color=black>");
else
  document.write("<th bgcolor=black><font color=white>");
    
document.write(note + "</th>");
}

h++;

if (h == 7)
  h = 0;  

document.write("</tr></table>");

}

document.write("</center>");

/*****************************************/