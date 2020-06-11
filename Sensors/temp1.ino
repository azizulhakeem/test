/*TO COMPILE, TEST AND RUN BOTH TEMPERATURE AND HUMIDITY SENSORS AT THE SAME TIME*/

#define SensorPin A1
float temp; //variable to hold temperature sensor value
float soil; // variable to hold the soil humidity sensor value
float reading; // variable to read the actual value of temperature
float sensorValue = 0; // soil humidity sensor initial value
int sensor = 0; // temperature sensor initial value
long tm,t,d; //variables to record time in seconds

void setup()
{
  Serial.begin(9600);
  pinMode(0,INPUT);//temperature sensor connected to analog 0
  analogReference(DEFAULT);
}

void loop()
{
  for (int i = 0; i <= 100; i++)
  {
    sensorValue = sensorValue + analogRead(SensorPin);
    delay(1);
  }

  //required for converting time to seconds
  tm = millis();
  t = tm/1000;
  d = tm%1000;

   //printing time in seconds
  Serial.print("Time: ");
  Serial.print(t);
  Serial.print(".");
  Serial.print(d);
  Serial.print("s\t");

  Serial.flush();
  
  sensorValue = sensorValue / 100.0;
  Serial.print("Humidity: ");
  Serial.print(sensorValue);
  Serial.print("\t");
  
  temp = analogRead(sensor); //analog reading temperature sensor values
  reading = temp * 0.0322265625; 

  //printing temperature sensor values
  Serial.print("Temperature: ");
  Serial.print(reading);
  Serial.println("C");
  
  delay(2000);//delay of 2 seconds
}
