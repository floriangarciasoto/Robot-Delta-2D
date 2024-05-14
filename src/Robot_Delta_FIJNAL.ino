//***** Bibliothèques. *****//
#include <Wire.h>
#include "rgb_lcd.h"
#include "Math.h"

//***** Variables globales du lcd. *****//
rgb_lcd lcd;               // Création du composant LCD 
const int colorR = 255;    // Configuration de la couleur
const int colorG = 255;      // A modifier éventuellement
const int colorB = 255;

//***** Variables globales de gestion_pages(). *****//
int fenetre = 0;        // Variable de verrouillage fenêtre.
char message[16];
int counter = 0;        // Variable counter utilisée avec le joystick et gestion_page
int valeur_X = 0;       // Variable  de recuperation de la valeur en X
int valeur_Y = 0;       // Variable  de recuperation de la valeur en Y
float Angle_G;   // Variable  de recuperation de l’angle moteur1 ou gauche
float Angle_D;   // Variable  de recuperation de l’angle moteur2 ou droit
int position_en_cours = 0;
int position_initiale = 0;
int rsc = 0;
int rsc2 = 0;

//***** Variable globale de gestion_BP(). *****//
int valide = 0;

//***** Variable globale de recup_joystick(). *****//
int scmin = 0;
int scmax = 0;

//***** Variable globale de calcul_angle(). *****//
float Agl_D;
float Agl_G;
int dir1;
int dir2;

#include <AccelStepper.h>
#include <MultiStepper.h>



#define STEPPER1_DIR_PIN 9     
#define STEPPER1_PUL_PIN 10
#define STEPPER2_DIR_PIN 12      
#define STEPPER2_PUL_PIN 13          


AccelStepper stepper1 (AccelStepper::DRIVER, STEPPER1_PUL_PIN, STEPPER1_DIR_PIN);
AccelStepper stepper2 (AccelStepper::DRIVER, STEPPER2_PUL_PIN, STEPPER2_DIR_PIN);
MultiStepper steppers;

void setup()  {
  Serial.begin(9600);
  lcd.begin(16, 2);         // initialisation du LCD en 16 sur 2 lignes    
  lcd.setRGB(colorR, colorG, colorB);
  lcd.setCursor(4,0);              // Positionnement du curseur  à remplir
  lcd.print("Bonjour,");               // Ecriture d’un message sur le LCD.
  lcd.setCursor(1,1);              // Positionnement du curseur  à remplir
  lcd.print("tout le monde!");
   stepper1.setMaxSpeed(400);
   stepper2.setMaxSpeed(400);     
   steppers.addStepper(stepper1); 
   steppers.addStepper(stepper2);

}


void loop() {
  recup_joystick();      // Appel de la fonction pour récupérer les données du joystick
  gestion_BP() ;         // Appel de la fonction ou sous-programme gestion_BP
  gestion_pages() ;      // Appel de la fonction gérant l’affichage des pages
  calcul_angle() ;       // Appel de la fonction ou sous-programme de calcul des angles
  gestion_mouvement() ;  // Appel de la fonction gérant le positionnement
}
