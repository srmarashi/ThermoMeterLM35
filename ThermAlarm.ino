// ThermAarm   LM35
// three buttons, RESET UP DOWN to reset and tune ALARM from 40Degree
// By: Seyed Roohollah Marashi
// Iran - Tehran 2020

int lmPin = A0; //
int Z =30;
void setup() //
{
  Serial.begin(9600); //
  pinMode(2, OUTPUT);    //Buzzer
  pinMode(3, OUTPUT);   //Green LED
  pinMode(4, OUTPUT);   //RED LED
  pinMode(5, INPUT);    //UP
  pinMode(6, INPUT);   //Down
  pinMode(7, INPUT);   //reset
  pinMode(8, OUTPUT);   //output
  pinMode(9, OUTPUT);   //output
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);

}
float tempC() //
{
  float raw = analogRead(lmPin); //
  float percent = raw / 1023.0; //
  float volts = percent * 5.0; //
  return 100.0 * volts; //

}
void loop() //
{
  digitalWrite(3, HIGH);


  int UP = digitalRead(5);
  int DOWN = digitalRead(6);
  int RESET = digitalRead(7);

//  Serial.print(UP);
//  Serial.print("-");
//  Serial.print(DOWN);
//  Serial.print("-");
//  Serial.print(RESET);
//  Serial.print("-");
    Serial.println(Z);  


  if (RESET == 0)
   {
    digitalWrite(2, HIGH);
    delay(100);
    digitalWrite(2, LOW);
    delay(100);
     Z = 30;
   }
  if (UP == 0) Z = Z + 1;
  if (DOWN == 0) Z = Z - 1;
  Serial.println(tempC() - 1.2); // 1.2 is calibration number after compare with precision Thermometer ite-tools
  if (tempC() >= Z)
  {
    digitalWrite(2, HIGH);
    digitalWrite(4, HIGH);
    delay(100);
    digitalWrite(2, LOW);
    digitalWrite(4, LOW);
    delay(100);
  }
  delay(200); // ms //
}
