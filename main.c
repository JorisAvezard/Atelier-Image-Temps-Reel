/*
Commande de servo-moteur par impulsion
Nanomaître 2015
Le servo est connecté au pin 3 de l'arduino
*/
//3 : horizontale; 4 : verticale
int pinServo_3=3;
int pinServo_4=4;
int difference = 30;
int angleZS = 0;
int angleQD = 0;
int v = 0;
int periode=20000;// période entre chaque début d'impulsion en microsecondes

void setup() {
  Serial.begin(9600); //début de la communication série
  pinMode(pinServo_3,OUTPUT);// on prépare le pin en mode OUTPUT
  digitalWrite(pinServo_3,LOW); // on l'initialise à l'état bas
  pinMode(pinServo_4,OUTPUT);// on prépare le pin en mode OUTPUT
  digitalWrite(pinServo_4,LOW); // on l'initialise à l'état bas
  setAngle(0, pinServo_3);
  setAngle(0, pinServo_4);
}

//boucle principale
void loop() {
  
  
  
  while (Serial.available()) { // tant que des caractères sont en attente d'être lus
    char c = Serial.read(); // on lit le charactère
    //Serial.print(c); // on l'écrit sur le moniteur
    
    switch(c) {
      case 'z': //Verticale
      Serial.print(c); // on l'écrit sur le moniteur
      v = difference;
      angleZS = newAngle(angleZS, v);
      Serial.print(angleZS);
      setAngle(angleZS, pinServo_4);
		Serial.print(" ");
      break;
      
      case 'q': //Horizontale
      Serial.print(c); // on l'écrit sur le moniteur
      v = 0 - difference;
      angleQD = newAngle(angleQD, v);
      Serial.print(angleQD);
      setAngle(angleQD, pinServo_3);
		Serial.print(" ");
      break;
 
      case 's': // Verticale
      Serial.print(c); // on l'écrit sur le moniteur
      v = 0 - difference;
      angleZS = newAngle(angleZS, v);
      Serial.print(angleZS);
      setAngle(angleZS, pinServo_4);
		Serial.print(" ");
      break;
      
      case 'd': //Horizontale
      Serial.print(c); // on l'écrit sur le moniteur
      v = difference;
      angleQD = newAngle(angleQD, v);
      Serial.print(angleQD);
      setAngle(angleQD, pinServo_3);
		Serial.print(" ");
      break;
    }
  }
}

//fonction setAngle pour envoyer les impulsions
void setAngle(int a, int pin){
  int duree=map(a,0,179,1000,2000);// on transforme l'angle en microsecondes et on stocke dans la variable duree
  digitalWrite(pin,LOW);//on met le pin à l'état bas
  
  // la boucle qui suit est nécessaire 
  // pour laisser le temps au servo d'aller à sa position
  for (int t=0;t<300;t++){ 
    digitalWrite(pin,HIGH);// on envoie l'impulsion
    delayMicroseconds(duree); // pendant la bonne durée
    digitalWrite(pin,LOW); // on stoppe l'impulsion
    delayMicroseconds(periode-duree); // on attend le temps restant pour atteindre la période
  }
}

int newAngle(int a, int v) {
   a += v;
   if(a < -90) a=-90;
   if(a > 180) a=180;
   return a;
}
