int relay = 15;
int sensor_pin = 35;
int output_value ;
int moisturelevel;

void setup() {
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
  Serial.println("Reading From the Sensor ...");
  delay(2000);
}
void loop() {
  output_value= analogRead(sensor_pin);
  moisturelevel = constrain ( map(output_value, 1000, 4095, 200, 0), 0, 100);
  Serial.print("Mositure : ");
  Serial.print(moisturelevel);
  Serial.println("%");
  delay(1000);
  if(moisturelevel<25){ //If moisture is less than 25, motor will turn on.
    digitalWrite(relay, HIGH); //Motor ON
  }
  else{
    digitalWrite(relay, LOW); //Motor OFF
  }
}
