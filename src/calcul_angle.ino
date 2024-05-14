int calcul_angle() { 

int x = 0;
int y = -225;

x = valeur_X;
y = valeur_Y;

int a = 165;
int b = 187;
int aa = 27225;
int bb = 34969;

float x_d = (float) (x - 125);  
float y_d = (float) (y);
float xx_d = (float) (x_d) * (x_d);
float yy_d = (float) (y_d) * (y_d);
float K_D = (float) ((xx_d) + (yy_d) + (34969) - (aa))/(2*b);
float a_Delta_D = (float) (K_D) + (x_d);
float b_Delta_D = (float) (-2) * (y_d);
float c_Delta_D = (float) (K_D) - (x_d);
float bb_Delta_D = (float) (b_Delta_D) * (b_Delta_D);
float Delta_D = (float) (bb_Delta_D) - (4*(a_Delta_D)) * (c_Delta_D);
float T_D = (float) ((-b_Delta_D - sqrt(Delta_D))/ (2* a_Delta_D));
float Betta_D = (float) (2 * atan(T_D)); 
float Alpha_D = (float) -acos((x_d - (b*cos(Betta_D))) / a);
float Angle_D = (float) (180-(abs(((Alpha_D * 180) / PI))));

float x_g = (float) (x + 125);  
float y_g = (float) (y);
float xx_g = (float) (x_g) * (x_g);
float yy_g = (float) (y_g) * (y_g);
float K_G = (float) ((xx_g) + (yy_g) + (34969) - (aa))/(2*b);
float a_Delta_G = (float) (K_G) + (x_g);
float b_Delta_G = (float) (-2) * (y_g);
float c_Delta_G = (float) (K_G) - (x_g);
float bb_Delta_G = (float) (b_Delta_G) * (b_Delta_G);
float Delta_G = (float) (bb_Delta_G) - (4*(a_Delta_G)) * (c_Delta_G);
float T_G = (float) ((-b_Delta_G + sqrt(Delta_G))/ (2* a_Delta_G));
float Betta_G = (float) (2 * atan(T_G)); 
float Alpha_G = (float) acos((x_g - (b*cos(Betta_G))) / a);
float Angle_G = (float) (abs((-1 * Alpha_G * 180) / PI));

Agl_D = Angle_D;
Agl_G = Angle_G;
Serial.println(Agl_G);
Serial.println(Agl_D);
}
