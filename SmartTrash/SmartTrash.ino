#include <NewPing.h>
#include <Servo.h>

// pins
#define SERVO_PIN 3
#define TRIGGER_PIN 11
#define ECHO_PIN 12

// configuration
#define MAX_DISTANCE 200
#define MAX_DISTANCE_TO_OPEN_LID 60
#define SERVO_LID_CLOSED_POSITION 90
#define SERVO_LID_OPEN_POSITION 10
#define SERVO_MOVEMENT_INCREMENT 5

// ultrasonic sensor
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

// servo
Servo servo;

// state of trash can
bool isLidOpen = false;
int servoPosition = SERVO_LID_CLOSED_POSITION;

void setup() {
  Serial.begin(9600);
  Serial.println("running setup");
  servo.attach(SERVO_PIN);
  servo.write(SERVO_LID_CLOSED_POSITION);
}

void loop() {
    unsigned int distance = sonar.ping_cm();
    Serial.print("distance from sensor: ");
    Serial.print(distance);
    Serial.println("cm");

    if (!isLidOpen && distance > 0 && distance <= MAX_DISTANCE_TO_OPEN_LID) {
      Serial.println("opening lid");
      isLidOpen = true;

      // open lid gradually
      while (servoPosition > SERVO_LID_OPEN_POSITION) {
        servoPosition -= SERVO_MOVEMENT_INCREMENT;
        servo.write(servoPosition);
        delay(100);
      }

      while(true) {
        delay(3000);
        distance = sonar.ping_cm();
        Serial.print("distance from sensor: ");
        if (distance == 0 || distance > MAX_DISTANCE_TO_OPEN_LID) {
          break;
        } else {
          Serial.println("keeping lid open");
        }
      }

      Serial.println("closing lid");
      isLidOpen = false;
      // open lid gradually
      while (servoPosition < SERVO_LID_CLOSED_POSITION) {
        servoPosition += SERVO_MOVEMENT_INCREMENT;
        servo.write(servoPosition);
        delay(100);
      }
    }

    // Check every half a second
    delay(500);
}
