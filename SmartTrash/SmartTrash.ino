#include <Servo.h>

Servo servo;

int servoPosition = 0;

void setup() {
  servo.attach(3);
}

void loop() {
    if (servoPosition == 0) {
        servoPosition = 30;
    } else {
        servoPosition = 0;
    }
    servo.write(servoPosition);
    delay(5000);
    
}
