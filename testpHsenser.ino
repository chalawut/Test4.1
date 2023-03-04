int pH_Value;
float Voltage;
float PHLevel;
int ValueAnalog;

void setup()
{
  Serial.begin(115200);
  //pinMode(pH_Value, INPUT);
}

void loop()
{
  /*int measuringVal = analogRead(A0);
    double vltValue = 5 / 1023.0 * measuringVal;
    float PHLevel = 7 + ((2.5 - vltValue) / 0.18);*/

  ValueAnalog = analogRead(A0);
  PHLevel = mapfloat(ValueAnalog , 1024, 639, 2.0, 12.0);//  364, 493, 4.0, 10.0
  //int measuringVal = analogRead(A0);
  //double vltValue = 5 / 1024.0 * measuringVal;
  //PHLevel = 9 + ((2.5 - vltValue));
  //Serial.print("measuringVal = ");
  //Serial.println(measuringVal);
  //Serial.print("vltValue = ");
  //Serial.println(vltValue);
  Serial.print("ValueAnalog = ");
  Serial.println(ValueAnalog);
  Serial.print("pH = ");
  Serial.println(PHLevel);
  Serial.println("============");
  delay(3000);
}
float mapfloat(int x, int in_min, int in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
