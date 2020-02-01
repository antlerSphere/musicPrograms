/*
Accordion Bass Chord Chart
v3.0 by antlerSphere 
Generates a mirror reflected chord chart. 
Highlights selected buttons read from a 
song menu.
*/

var h = 0;
var i = 0;
var j = 0;

var pitch = "ADGCFBEADG";                        
var s_or_f = "#bx ";                      
var o7mM = "o7mM ";  

var songName = "";
var bassNotes = "";

changeTable(bassNotes);

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

function changeTable(bassNotes)
{

h = i = j = 0;

var innerHTML = "<br>";

innerHTML += "<form>";
innerHTML += "<select onchange='document.location.reload(); changeTable(this.value);'>";

innerHTML += "<option name=bassNotes value= ' E G# A C# F# C B '>Magitek Factory</option>";

innerHTML += "<option name=bassNotes value= 'F# B D# E G# C# '>Terra</option>";

innerHTML += "<option name=bassNotes value= 'F# A# B E A G '>Sephiroth</option>";

innerHTML += "<option name=bassNotes value='E# A# B D# G# A C# D F# B E F '>Fireman</option>";

innerHTML += "<option name=bassNotes value='F# B E A C# D F# G '>Wily's Showdown</option>";

innerHTML += "<option name=bassNotes value='G C F A Bb D Eb '>Castle Halls</option>";

innerHTML += "<option name=bassNotes value='D G C F Bb '>Lightning Rod</option>";

innerHTML += "<option name=bassNotes value='D# G# A D F# G B C E F Bb Eb Ab '>Brinstar</option>";

innerHTML += "<option name=bassNotes value=' E A D F# G B C F Bb Eb Db '>Norfair</option>";

innerHTML += "<option name=bassNotes value=' E A C# D F# G B C E '>Kraid's Hideout</option>";

innerHTML += "<option name=bassNotes value='A# Em E AM A Dm D CM FM F '>Song of the Storms</option>";

innerHTML += "<option name=bassNotes value=' E D F# G C F Bb Eb Ab '>Ecco the Dolphin</option>";

innerHTML += "<option name=bassNotes value='Cm CM C Fm F EbM Eb AbM Ab DbM Db GbM Gb '>Daedel's Organ</option>";

innerHTML += "<option name=bassNotes value='Bb F Eb Ab Db '>Luna</option>";

innerHTML += "<option name=bassNotes value='A# D# G# D G '>Ceremony</option>";

innerHTML += "<option name=bassNotes value='F# B F Bb D Eb Ab Db Gb '>Marble Madness</option>"; 

innerHTML += "<option name=bassNotes value='A# B D# E A F# C '>Sewer Battle</option>";

innerHTML += "<option selected hidden>Choose a song</option>";
innerHTML += "</select>";
innerHTML += "</form><br>";

innerHTML += "<center>";

for (row = 0; row < 20; row++)
{        
i = checkRows(row);

innerHTML += "<table><tr>";
  
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
        note = "( " + pitch[h] + " )";
      else
        note = '(' + pitch[h] + s_or_f[i] + ')';     
      } 
    else
      if (checkColRow(col, row) == 4)
        note = pitch[h] + s_or_f[i];
      else
   if (s_or_f[i] != ' ')
     note = pitch[h] + s_or_f[i] + o7mM[j]; 
   else
     note = pitch[h] + o7mM[j];
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

var thStyle = "style='border: 1px solid black;border-collapse: separate; border-radius: 20px; font-weight: normal; height: 42px; width: 42px'><font color=";

var Note = new RegExp(note);

if (Note.test(bassNotes))
  innerHTML += "<th bgcolor=white " + thStyle + "black>";
else
  innerHTML += "<th bgcolor=black " + thStyle + "white>";
    
innerHTML += note + "</th>";
}

h++;

if (h == 7)
  h = 0;  

innerHTML += "</tr></table>";

}

innerHTML += "</center>";

document.write(innerHTML);

}

/*****************************************/