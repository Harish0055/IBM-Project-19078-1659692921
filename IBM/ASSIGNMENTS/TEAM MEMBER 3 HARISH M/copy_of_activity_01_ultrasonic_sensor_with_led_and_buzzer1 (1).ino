const int echoPin=2, triggerPin=3, red=4, green=5, blue=6;
const int buzz = 7;
int pulseValue;
float distance;

void setup( ) {
pinMode(echoPin, INPUT);
pinMode(triggerPin, OUTPUT);
pinMode(red, OUTPUT);
pinMode(green, OUTPUT);
pinMode(blue, OUTPUT);
pinMode(buzz, OUTPUT);
Serial.begin(9600);
}

void loop( )
{
 
digitalWrite(triggerPin, LOW);
delayMicroseconds(5);
digitalWrite(triggerPin, HIGH);
delayMicroseconds(10);
pulseValue=pulseIn(echoPin, HIGH);
distance=(pulseValue*0.0001657*39.37);
 


if (distance<=5)
{
  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
  tone(buzz, 500);
}
 
else if (distance<=10)
{
  digitalWrite(green, HIGH);
  digitalWrite(red, LOW);
  digitalWrite(blue, LOW);
  tone(buzz, 1000);
}

else 
{
  digitalWrite(blue, HIGH);
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  tone(buzz, 1500);
}
 
Serial.print(distance);
Serial.println(" inch/es");
delay(500);
}
