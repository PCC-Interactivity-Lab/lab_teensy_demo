/*
 Demo code for PCC Interactivity Lab Teensies

 This is the default code that we keep on all lab Teensies for demoing sensor to midi behavior

 2017 Nolan Thomas and Jesse Mejia
 */


int sensorPin = 15;
int sensorReading = 0;
int sensorScaled = 0;
int ambient_light = 0;
int potScaled = 0;
int potPin = 16;
int potReading = 0;

void setup(){
  Serial.begin(9600);
  ambient_light = analogRead(sensorPin);
}

void loop(){
  sensorReading = analogRead(sensorPin);
  sensorScaled = map(sensorReading, 0, ambient_light, 0, 127); //500 was low range of the photocell i tested
  potReading = analogRead(potPin);
  potScaled = map(potReading, 0, 1023, 0, 127);


  usbMIDI.sendControlChange(1, sensorScaled, 1);
  usbMIDI.sendControlChange(2, potScaled, 1);  

  delay(100); //just here to slow down the output for easier reading
  Serial.println(potScaled);
  Serial.println(sensorScaled);

}
