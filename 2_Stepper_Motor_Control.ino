#include <AccelStepper.h>

#define MOTOR_INTERFACE_TYPE 1

#define step1_Pin 42
#define dir1_Pin 44
#define step2_Pin 46
#define dir2_Pin 48

AccelStepper stepper1(MOTOR_INTERFACE_TYPE, step1_Pin, dir1_Pin);
AccelStepper stepper2(MOTOR_INTERFACE_TYPE, step2_Pin, dir2_Pin);

const int stepsPerRevolution = 200;
const int degreeToGo = 90;
const float stepsPerDegree = (float)stepsPerRevolution / 360.0;
const int targetSteps = round(degreeToGo * stepsPerDegree);
const int initialDegree = 45;            // initial reverse move
const int initialSteps = round(initialDegree * stepsPerDegree);

void setup() {
  stepper1.setMaxSpeed(500);
  stepper1.setAcceleration(100);
  stepper2.setMaxSpeed(500);
  stepper2.setAcceleration(100);

  stepper1.moveTo(-initialSteps);
  stepper2.moveTo(initialSteps);

  while (stepper1.distanceToGo() != 0 || stepper2.distanceToGo() != 0) {
    stepper1.run();
    stepper2.run();
  }
  delay(1000);
//   unsigned long startTime = millis();
//   while (millis() - startTime < 1000) {  // run for ~1 second
//     stepper1.run();
//     stepper2.run(); 
//   }
//   stepper1.stop();
//   stepper2.stop();
//   delay(1000);  // short pause before main loop starts 

}

void loop() {
  // Move to 135 degrees
  stepper1.moveTo(targetSteps);
  stepper2.moveTo(-targetSteps);

  while (stepper1.distanceToGo() != 0 || stepper2.distanceToGo() != 0) {
    stepper1.run();
    stepper2.run();
  }

  delay(3000);

  // Move back to 0 degrees
  stepper1.moveTo(0);
  stepper2.moveTo(0);

  while (stepper1.distanceToGo() != 0 || stepper2.distanceToGo() != 0) {
    stepper1.run();
    stepper2.run();
  }

  // Stop here (hold position)
  while (1);
}
