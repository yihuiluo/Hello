/*
 Programme pour thermometre electronique

 Ecrit le 19 fevrier 2016
 par Yi Hui Luo 403

 Note : les phrases precedees de "//" ou de "/*" sont ignorees par l'Arduino
        elles servent a communiquer avec d'autres humains qui lisent le programme
        je les ai ecrites pour expliquer l'utilite de chaque ligne de programme
 
 */

// inclure les fonctions de l'ecran LCD:
#include <LiquidCrystal.h>
#include <Wire.h>

// indiquer les prises par lesquels l'ecran est connecte
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Quelques variables pour memoriser la temperature
int sensorVal = 0;


// Programme pour demarrer
void setup() {
  // demarrer une communication avec l'ordinateur a 9600 bits par seconde
  Serial.begin(9600);
  
  // designer le mode de la prise A0 (entree)
  pinMode(A0,INPUT);

  // Afficher le message de bienvenue
  lcd.begin(16, 2);
  lcd.print("Yi Hui Luo 403");
  delay(5000);
  lcd.clear();
  lcd.print("Yi Hui Luo vous");
  lcd.setCursor(0, 1);
  lcd.print("souhaite la");
  delay(2000);
  lcd.clear();
  lcd.print("bienvenue!");
  delay(2000);
  lcd.clear();
  
}


// Programme repete sans arret pour faire fonctionner le thermometre
void loop() {
  // lire le signal sur A0 et enregistrer sous la variable sensorVal
  // la fonction int permet d'enregistrer des nombres entiers
  int sensorVal = analogRead(A0);
  // afficher cette valeur sur l'ordinateur (lorsqu'il est connecte par USB)
  Serial.print("sensor Value: ");
  Serial.print(sensorVal);

  // convertir le signal ADC (analog to digital) en voltage et enregistrer sous la variable "voltage"
  // la fonction float permet d'enregistrer des nombres ayant des decimales
  float voltage = (sensorVal / 1024.0) * 5.0;
  // afficher le voltage sur l'ordinateur
  Serial.print(", Volts: ");
  Serial.print(voltage);

  // convertir le voltage en temperature en degres Celsius et enregistrer sous la variable "temperatureC"
  // selon les tables de donnees du TMP36, le voltage peut etre convertit en degres C avec la fonction T = 100(voltage - 0.5)
  float temperatureC = (voltage - .5) * 100;
  // afficher la temperature en C sur l'ordinateur
  Serial.print(", degres C: ");
  Serial.println(temperatureC);

  // convertir la temperature en Celsius en Fahrenheit avec la fonction T(F) = 1,8*T(C) + 32 et enregistrer sous la variable "temperatureF"
  float temperatureF = 1.8 * temperatureC + 32;
  // afficher la temperature en F sur l'ordinateur
  Serial.print(", degres F: ");
  Serial.println(temperatureF);

  // convertir la temp en C en kelvin avec la fonction T(K) = T(C) = 273,15 et enregistrer sous la variable "temperatureK"
  float temperatureK = temperatureC + 273.15;
  // afficher la temperature en K sur l'ordinateur
  Serial.print(", degres K: ");
  Serial.println(temperatureK);

  // afficher les temperatures sur l'ecran LCD
  lcd.print("Temp.:");
  // celsius
  lcd.setCursor(8,0);
  lcd.print(temperatureC);
  lcd.print(" C");
  // fahrenheit
  lcd.setCursor(0,1);
  lcd.print(temperatureF);
  lcd.print(" F");
  // kelvin
  lcd.setCursor(8,1);
  lcd.print(temperatureK);
  lcd.print(" K");

  // afficher pour 1 secondes
  delay(1000);


}
