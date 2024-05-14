int gestion_pages() {        
  if (valide >= 1) {lcd.clear();}
  if (valide == 1) {   // Si appui 1ière fois sur BP de "VALIDATION"
    lcd.setCursor(0,0);              // Positionnement du curseur
    lcd.print("Saisir position");    // affichage ligne du haut
    lcd.setCursor(0,2);              // Positionnement du curseur 2eme ligne
    lcd.print("en X et en Y");       // affichage ligne du bas
  }
  if (valide == 2) {   // Si appui 2ième fois sur BP de "VALIDATION"
    fenetre = 1;                     // gestion des fenetres
    lcd.setCursor(0,0); lcd.print("Saisir position");
    //sprintf(message,"en X : ",(int)counter) ;  
    //lcd.write(message);              // Affichage du message 2eme ligne.
    lcd.setCursor(0,1); lcd.print("en X :");
    lcd.setCursor(7,1); lcd.print(counter);
  }
  if (fenetre == 1 && valide == 3)   // Si appui 3ième fois sur BP de "VALIDATION"
    {valeur_X = counter;             //  Mémorisation de la valeur en X
    fenetre = 2;                     // autorisation  affichage fenetre 2
    counter = 0;                     // Mise à 0 variable counter
  } 
  if (fenetre == 2 ) {      
    lcd.setCursor(0,0); lcd.print("Saisir position");
    //sprintf(message,"en Y : ",(int)counter) ;  
    //lcd.write(message);              // Affichage du message 2eme ligne.
    lcd.setCursor(0,1); lcd.print("en Y :");
    lcd.setCursor(7,1); lcd.print(counter);
  }
  if (fenetre == 2 && valide == 4)   // Si appui 4ième fois sur BP de "VALIDATION"
    {valeur_Y = counter;             //  Mémorisation de la valeur en Y
    fenetre = 3;                     // autorisation  affichage fenetre 3
    counter = -225;                     // Mise à 0 variable counter
  }
  if (fenetre == 3){
    if (valide == 5){fenetre = 4;}
    lcd.setCursor(0,0); lcd.print("Position validee.");
    //sprintf(message," X =", (int)valeur_X, "Y =",(int)valeur_Y); 
    //lcd.write(message);              // Affichage du message 2eme ligne.
    lcd.setCursor(0,1); lcd.print("X = ");
    lcd.setCursor(4,1); lcd.print(valeur_X);
    lcd.setCursor(8,1); lcd.print("Y =");
    lcd.setCursor(12,1); lcd.print(valeur_Y);
  }
  if (fenetre == 4 && valide == 5) {      
    lcd.setCursor(0,0); lcd.print("Angles : ");
    lcd.setCursor(0,1); lcd.print("G:");
    lcd.setCursor(2,1); lcd.print(Agl_G, 1);
    lcd.setCursor(8,1); lcd.print("D:");
    lcd.setCursor(10,1); lcd.print(Agl_D, 1);
  }
  if (valide == 6){fenetre = 5;}
  if (fenetre == 5) {  // Si appui 5 ou 6ième fois sur BP à vérifier     
    //lcd.home();                        // Positionnement du curseur
    lcd.setCursor(0,0);                // Positionnement du curseur 2eme ligne
    lcd.print("Positionnement");      // affichage ligne du haut
    lcd.setCursor(0,1);                // Positionnement du curseur 2eme ligne
    lcd.print("en cours");      // Affichage du message 2eme ligne.
    lcd.setCursor(9,1); lcd.print("   ");
    delay(400);
    lcd.setCursor(9,1); lcd.print(".  ");
    delay(400);
    lcd.setCursor(9,1); lcd.print(".. ");
    delay(400);
    lcd.setCursor(9,1); lcd.print("...");
    delay(400);
    if (rsc2 == 0){position_en_cours = 1; rsc2 = 1;}          // Mettre variable à vrai
    if (position_en_cours == 0){fenetre = 6;lcd.clear();}                     
}
  if (fenetre == 6) {  // Si position effectuée
    fenetre = 7;                     
    lcd.home();                      // Positionnement du curseur 
    lcd.print("Positionnement");      // affichage ligne du haut
    lcd.setCursor(0,1);              // Positionnement du curseur 2eme ligne
    lcd.print("effectue");     // Affichage du message 2eme ligne.
    delay(2000) ;
  }
  if (fenetre == 7) {                 // Si fenetre 7
    position_initiale = true;    // Mettre variable à vrai
    lcd.home();                      // Positionnement du curseur 
    lcd.print("Retour position");    // affichage ligne du haut
    lcd.setCursor(0,1);              // Positionnement du curseur 2eme ligne
    lcd.print("initiale");    // Affichage du message 2eme ligne.
    delay(2000) ;
    valide = 1 ;                 // Remise à 1 variable valide pour revenir à page acceuil
    fenetre = 0;
    rsc = 0;
    rsc2 = 0;
    counter = 0;
  }
}
