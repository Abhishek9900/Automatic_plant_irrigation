#include <math.h>
#include "DHT.h"
#define DHTPIN A1
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);
int led1 =2,led2 =3,led3 =4,led4 =11,led5 =12;
int motor =8;
void setup() 
{
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  dht.begin();
}

void loop() 
{
  int moisture=0;
  moisture=analogRead(A0);
  int temperature = dht.readTemperature();
  int humidity = dht.readHumidity();
  Serial.print(moisture);
  Serial.print(",");
  Serial.print(temperature);
  Serial.print(",");
  Serial.println(humidity);
  if (moisture > 800)
 {
  digitalWrite(motor, HIGH);
 digitalWrite(led1, HIGH);
 digitalWrite(led2, LOW);
 digitalWrite(led3, LOW);
 digitalWrite(led4, LOW);
 digitalWrite(led5, LOW);
}
else if (moisture >= 690  && moisture < 800)
 {
  digitalWrite(motor, HIGH);
 digitalWrite(led1, HIGH);
 digitalWrite(led2, HIGH);
 digitalWrite(led3, LOW);
 digitalWrite(led4, LOW);
 digitalWrite(led5, LOW);
}  
else if (moisture >= 385 && moisture < 690)
 {
  digitalWrite(motor, LOW);
 digitalWrite(led1, HIGH);
 digitalWrite(led2, HIGH);
 digitalWrite(led3, HIGH);
 digitalWrite(led4, LOW);
 digitalWrite(led5, LOW);
}    
else if (moisture >= 300 && moisture < 385)
 {
  digitalWrite(motor, LOW);
 digitalWrite(led1, HIGH);
 digitalWrite(led2, HIGH);
 digitalWrite(led3, HIGH);
 digitalWrite(led4, HIGH);
 digitalWrite(led5, LOW);
}
else if (moisture >= 0 && moisture < 300)
 {
  digitalWrite(motor, LOW);
 digitalWrite(led1, HIGH);
 digitalWrite(led2, HIGH);
 digitalWrite(led3, HIGH);
 digitalWrite(led4, HIGH);
 digitalWrite(led5, HIGH);
}
  delay(2000);
}
