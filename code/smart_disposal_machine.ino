
#define BLYNK_TEMPLATE_ID "TMPL3nGKzbcT2"
#define BLYNK_TEMPLATE_NAME "dustbin"
#define BLYNK_AUTH_TOKEN "f6qVqF6R8hfhr7vjOXG9O03h-rD5xPMD"

#define BLYNK_PRINT Serial
#include <Arduino.h>
#include <Ultrasonic.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>
#include <wiFi.h>

// Blynk Auth Token, WiFi credentials
char auth[] = "f6qVqF6R8hfhr7vjOXG9O03h-rD5xPMD";
char ssid[] = "Your WiFi name";
char pass[] = "Password";

// Ultrasonic Sensor Pins
#define TRIG_PIN1 23
#define ECHO_PIN1 22
#define TRIG_PIN2 21
#define ECHO_PIN2 19
#define TRIG_PIN3 18
#define ECHO_PIN3 5
#define TRIG_PIN4 4
#define ECHO_PIN4 25

// LED Pins
#define LED1 15
#define LED2 13
#define LED3 12
#define LED4 14

// Servo Pin
#define SERVO_PIN 2

// Blynk Virtual Pins
#define DISTANCE_VP V0
#define ALERT_VP V1
#define SERVO_BUTTON_VP V2

// Objects
Ultrasonic ultrasonic1(TRIG_PIN1, ECHO_PIN1);
Ultrasonic ultrasonic2(TRIG_PIN2, ECHO_PIN2);
Ultrasonic ultrasonic3(TRIG_PIN3, ECHO_PIN3);
Ultrasonic ultrasonic4(TRIG_PIN4, ECHO_PIN4);
Servo myServo;

// Variables
float distance1, distance2, distance3, distance4;
float averageDistance;
bool servoState = false; // Track servo state

BlynkTimer timer;

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  myServo.attach(SERVO_PIN);

  timer.setInterval(2000L, sendData);
}

void loop() {
  Blynk.run();
  timer.run();
}

void sendData() {
  long microsec1 = ultrasonic1.timing();
  long microsec2 = ultrasonic2.timing();
  long microsec3 = ultrasonic3.timing();
  long microsec4 = ultrasonic4.timing();

  distance1 = ultrasonic1.convert(microsec1, Ultrasonic::CM);
  distance2 = ultrasonic2.convert(microsec2, Ultrasonic::CM);
  distance3 = ultrasonic3.convert(microsec3, Ultrasonic::CM);
  distance4 = ultrasonic4.convert(microsec4, Ultrasonic::CM);

  averageDistance = (36 - (distance1 + distance2 + distance3 + distance4)/4)*100/36;


  Blynk.virtualWrite(DISTANCE_VP, averageDistance);

  updateLeds(averageDistance);

  if (averageDistance > 75 ) {
    Blynk.virtualWrite(ALERT_VP, "High Fill Level Detected!");
    Blynk.logEvent("fill_alert", "Dustbin filleed more than 75%!");
    Serial.print("75% filled!");
  } else {
    Blynk.virtualWrite(ALERT_VP, "");
  }

  Serial.print("Distances: ");
  Serial.print(distance1); Serial.print(", ");
  Serial.print(distance2); Serial.print(", ");
  Serial.print(distance3); Serial.print(", ");
  Serial.print(distance4);  
  Serial.print(", Average: "); Serial.println(averageDistance);
   if (averageDistance >= 83){
    myServo.write(120);
    delay(8000);
    myServo.write(92);
}
}

void updateLeds(float distance) {
  float percentage = (distance / 100.0) * 100; // Adjust 100 if needed

  digitalWrite(LED1, percentage >= 0 ? HIGH : LOW);
  digitalWrite(LED2, percentage >= 25 ? HIGH : LOW);
  digitalWrite(LED3, percentage >= 50 ? HIGH : LOW);
  digitalWrite(LED4, percentage >= 75 ? HIGH : LOW);
}

BLYNK_WRITE(V4)
{
 int pos1 = param.asInt(); // Get value from slider

  myServo.write(pos1); // Set servo 1 position
  Blynk.virtualWrite(V3, pos1);
  }
