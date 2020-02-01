<?php

/* chordchart4.c --> PHP v4.0 by antlerSphere 
   Accordion Bass Chord Chart with mirror 
   reflection encoded with a 3D array */

$pitch = "ADGCFBEADG ";                        
$s_or_f = "#bx ";                      
$o7mM = "o7mM "; 

$chart = array
(

array( array(0,0,0), array(10,3,4),     
       array(10,3,4), array(10,3,4), 
       array(10,3,4), array(10,3,4) ),

array( array(1,0,0), array(0,0,1),           
       array(10,3,4), array(10,3,4), 
       array(10,3,4), array(10,3,4) ),   

array( array(2,0,0), array(1,0,1), 
       array(0,0,2), array(10,3,4), 
       array(10,3,4), array(10,3,4) ),
  
array( array(3,0,0), array(2,0,1), 
       array(1,0,2), array(0,0,3), 
       array(10,3,4), array(10,3,4) ),
  
array( array(4,0,0), array(3,0,1), 
       array(2,0,2), array(1,0,3), 
       array(0,0,4), array(10,3,4) ),
  
array( array(5,3,0), array(4,0,1), 
       array(3,0,2), array(2,0,3), 
       array(1,0,4), array(3,2,4) ),

array( array(6,3,0), array(5,3,1), 
       array(4,0,2), array(3,0,3), 
       array(2,0,4), array(4,2,4) ),
  
array( array(0,3,0), array(6,3,1), 
       array(5,3,2), array(4,0,3), 
       array(3,0,4), array(5,0,4) ),

array( array(1,3,0), array(0,3,1), 
       array(6,3,2), array(5,3,3), 
       array(4,0,4), array(6,0,4) ),
  
array( array(2,3,0), array(1,3,1), 
       array(0,3,2), array(6,3,3), 
       array(5,3,4), array(7,0,4) ),
  
array( array(3,3,0), array(2,3,1), 
       array(1,3,2), array(0,3,3), 
       array(6,3,4), array(8,0,4) ),
  
array( array(4,3,0), array(3,3,1), 
       array(2,3,2), array(1,3,3), 
       array(0,3,4), array(9,0,4) ),

array( array(5,1,0), array(4,3,1), 
       array(3,3,2), array(2,3,3), 
       array(1,3,4), array(3,0,4) ),

array( array(6,1,0), array(5,1,1), 
       array(4,3,2), array(3,3,3), 
       array(2,3,4), array(4,0,4) ),

array( array(0,1,0), array(6,1,1), 
       array(5,1,2), array(4,3,3), 
       array(3,3,4), array(5,3,4) ),

array( array(1,1,0), array(0,1,1), 
       array(6,1,2), array(5,1,3), 
       array(4,3,4), array(6,3,4) ),

array( array(2,1,0), array(1,1,1), 
       array(0,1,2), array(6,1,3), 
       array(5,1,4), array(7,3,4) ),

array( array(3,1,0), array(2,1,1), 
       array(1,1,2), array(0,1,3), 
       array(6,1,4), array(8,3,4) ),

array( array(4,1,0), array(3,1,1), 
       array(2,1,2), array(1,1,3), 
       array(0,1,4), array(9,3,4) ),

array( array(5,11,0), array(4,1,1), 
       array(3,1,2), array(2,1,3), 
       array(1,1,4), array(3,3,4) ),

array( array(10,3,4), array(5,11,1), 
       array(4,1,2), array(3,1,3), 
       array(2,1,4), array(4,3,4) ),

array( array(10,3,4), array(10,3,4), 
       array(5,11,2), array(4,1,3), 
       array(3,1,4), array(5,1,4) ),

array( array(10,3,4), array(10,3,4), 
       array(10,3,4), array(5,11,3), 
       array(4,1,4), array(6,1,4) ),

array( array(10,3,4), array(10,3,4), 
       array(10,3,4), array(10,3,4), 
       array(5,11,4), array(7,1,4) ),

array( array(10,3,4), array(10,3,4), 
       array(10,3,4), array(10,3,4), 
       array(10,3,4), array(8,1,4) )          
);

/*****************************************/

function checkButton($row, $col)
{

if (($col == 4) && ( (($row == 10) ||
    ($row == 14)) || ($row == 18) ))
  return 1;
else
  return 0;
        
}

/*****************************************/

echo "<style>th { border: 1px solid black; empty-cells: hide; border-collapse: separate; border-radius: 20px; font-weight: normal; height: 42px; width: 42px; }
</style>";

echo "<center>";

for ($row=0; $row<25; $row++)
                         // go through rows
  {       

  echo "<table><tr>";
     
  for ($col=0; $col<6; $col++)
                      // go through columns         
    { 

    echo "<th>";

    if ($chart[$row][$col][1] == 11)
      echo $pitch[$chart[$row][$col][0]].$s_or_f[1].$s_or_f[1].$o7mM[$chart[$row][$col][2]];
    else if (checkButton($row, $col))
      echo '('.$pitch[$chart[$row][$col][0]].$s_or_f[$chart[$row][$col][1]].')';        
    else
      echo $pitch[$chart[$row][$col][0]].$s_or_f[$chart[$row][$col][1]].$o7mM[$chart[$row][$col][2]];  

    echo "</th>";
    
    }    // end of column loop

  echo "</tr></table>";
  
  }  // end of row loop

echo "</center>";

?>