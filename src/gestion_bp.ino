int gestion_BP() {  
  //Lecture de l'état des entrées de boutons du BP.
  int val = analogRead(A2);   // lecture valeur analogique du potentiometre axe X 
  if (val == 1023) { //Si variable entrée à l’état haut
    valide++;                //Incrémentation de la variable de validation
    delay(350);     //Temporisation de filtrage des appuis (anti-rebond).
    return 1;                //Renvoie de la valeur 1 = Bouton de "VALIDATION" valide.
  }
}
