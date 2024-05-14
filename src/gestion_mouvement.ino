int gestion_mouvement() {
if(position_en_cours == 1){
  
  
  if(Agl_G < 90){
  dir1=1;
}
else {
  dir1=-1;
}
if(Agl_D < 90){
  dir2=-1;
}
else{
  dir2=1 ; 
}
long positions[2];                 
  
  positions[0] = ((2*(abs (90-Agl_G)*22450)/2520))*dir1;      
  positions[1] = ((2*(abs (90-Agl_D)*22450)/2520))*dir2;
  steppers.moveTo(positions);        
  steppers.runSpeedToPosition();    
  delay(10000);              
  
  positions[0] =0;     
  positions[1] =0;     
  steppers.moveTo(positions); 
  steppers.runSpeedToPosition();

  position_en_cours = 0;
  delay(1000); 
  
              
}


}

