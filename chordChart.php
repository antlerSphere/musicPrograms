<?php

/* chordchart2.c --> PHP by antlerSphere 
Generates a mirror reflected accordion 
bass chord chart. Ghost switch options 
are for normal buttons or gray diamonds 
optical illusion. */

$h = 0;

$pitch = "ADGCFBEADG";                        
$s_or_f = "#bx ";                      
$o7mM = "o7mM ";  

// option # 1 - normal chart with buttons

// /*
echo "<style>th {border: 1px solid black;border-collapse: separate; border-radius: 20px; font-weight: normal; height: 42px; width: 42px</style>";
// */

/* option #2 - thick rounded borders create an optical illusion where there are gray diamonds at all intersections except the one you are looking at */

// 
/*
echo "<style> th {border: 7px solid black; border-collapse: collapse; border-radius: 5px; font-weight: normal; width:350px</style>";
// 
*/

/*****************************************/

function checkRows($row)
{
if (($row >= 0) && ($row <= 4))    
  return 0;

if (($row >= 5) && ($row <= 11))
  return 3;

if (($row >= 12) && ($row <= 18))
  return 1;      
}

/*****************************************/

function checkCols($col)
{
if (($col >= 0) && ($col <= 3))   
  return $col;    
}

/*****************************************/

function checkColRow($col, $row)
{    
if (($col == 5) && (($row == 0) || ($row == 1)))  
  return 5;

if (($col == 4) && (($row >= 5) && ($row <= 11)))
  return 4;    
}

/*****************************************/

function checkButton($col, $row)
{
if (($col == 4) && ((($row == 6) || ($row == 10)) || ($row == 14)))
  return 6;   
}

/*****************************************/

function checkBassRows($row)   
{
if (($row >= 2) && ($row <= 8))
  return 2;

if (($row >= 9) && ($row <= 15))
  return 9;
  
if (($row >= 16) && ($row <= 18))
  return 16;   
}

/*****************************************/

echo "<center>";

for ($row = 0; $row < 20; $row++)
{         
$i = checkRows($row);

echo "<table><tr>";
  
for ($col = 0; $col < 6; $col++)
{   
$j = checkCols($col);

echo "<th>";

if ($j != $col) 
  $j = 4;        
      
if ($col < 5)
  {
  if ($row == 19)
  {
  if ($col == 0)
    echo $pitch[$h].$s_or_f[1].$s_or_f[1].$o7mM[$j];
  if ($col >= 1)
    echo $pitch[$h].$s_or_f[1].$s_or_f[1].$o7mM[$j];           
  }
    else
    {       
    if (checkButton($col, $row) == 6)
      echo "(".$pitch[$h].$s_or_f[$i].")"; 
    elseif (checkColRow($col, $row) == 4)
      echo $pitch[$h];
    else
     echo $pitch[$h].$s_or_f[$i].$o7mM[$j]; 
    }
  }
    else 
    {
    if (checkColRow($col, $row) == 5)
      echo $pitch[$h+3].$s_or_f[2];

    switch (checkBassRows($row))
    {
      case 2:
      echo $pitch[$h+3].$s_or_f[0];
      break;
      
      case 9:
      echo $pitch[$h+3];
      break;
      
      case 16:
      echo $pitch[$h+3].$s_or_f[1];
      break;          
    }

    if ($row == 19)
      echo $pitch[$h+3].$s_or_f[1];  
    }  

echo "</th>";

}

$h++;

if ($h == 7)
  $h = 0;  

echo "</tr></table>";
}

echo "</center>";

?>