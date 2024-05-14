int recup_joystick() {
  if (fenetre == 1) {scmin = -100; scmax = 100;}
  if (fenetre == 2) {scmin = -270; scmax = -180;}
  if (fenetre == 2 && rsc == 0) {counter = -225; rsc = 1;}
  int val = analogRead(A3);   // lecture valeur analogique du potentiometre axe X 
  int x = map(val, 525, 800, 300, 10);     // mappage pour gérer le temps de comptage
  int y = map(val, 240, 505, 10, 300);
  if (val > 525 && val <=800) {  // plage de positionnement maxi
      counter++;
      delay(x);  
  if (counter >= scmax) {                      // si dépassement de l’incrémentation
      counter = scmax;}  }
  if (val >240 && val <=505) {   // plage de positionnement mini
      counter--;
      delay(y);
  if (counter <= scmin) {                   // si dépassement de la décrémentation
      counter = scmin;}  }
  if (val >505 && val <=525) {    // plage de positionnement repos
      delay(100);} 
}
