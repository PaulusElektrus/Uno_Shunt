#include <Arduino.h>

int read_value;
int repetition = 10;
float u;
float i;
float u_in = 5.001 ;
float i_faktor = 10.4 ;
String incomingString;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available() > 0){
    incomingString = Serial.readString();

    if (incomingString.equals("m")){
      read_value = 0;
      for(int j = 0; j < repetition; j++){
        read_value+=analogRead(A0);}
        delay(50);
      read_value=read_value/repetition;
      Serial.print("A0: ");
      Serial.print(read_value);
      u=(u_in/1023.000)*read_value;
      Serial.print(" - U: ");
      Serial.print(u, 3 );
      i = u * i_faktor; 
      Serial.print(" - I: ");
      Serial.println(i, 3);
}}}