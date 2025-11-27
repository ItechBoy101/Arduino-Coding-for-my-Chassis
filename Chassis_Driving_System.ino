// Arduino code to control a 4WD robot using two L298N motor drivers

// Motor pins for L298N #1
int enA1 = 2;  // PWM 
int in1_1 = 22;
int in2_1 = 24;
int enB1 = 3;  // PWM
int in3_1 = 26;
int in4_1 = 28;

// Motor pins for L298N #2
int enA2 = 4;  // PWM
int in1_2 = 30;
int in2_2 = 32;
int enB2 = 5; // PWM
int in3_2 = 34;
int in4_2 = 36;

void setup() {
  pinMode(enA1, OUTPUT);
  pinMode(in1_1, OUTPUT);
  pinMode(in2_1, OUTPUT);
  pinMode(enB1, OUTPUT); 
  pinMode(in3_1, OUTPUT); 
  pinMode(in4_1, OUTPUT);

  pinMode(enA2, OUTPUT); 
  pinMode(in1_2, OUTPUT); 
  pinMode(in2_2, OUTPUT);
  pinMode(enB2, OUTPUT); 
  pinMode(in3_2, OUTPUT); 
  pinMode(in4_2, OUTPUT);
}

void loop() {

  moveForward();
  delay(3000);

  stopMotor();
  delay(2000);

  moveBackward();
  delay(1500);

  stopMotor();
  delay(2000);

  turnLeft();
  delay(1000);

  stopMotor();
  delay(1000);

  moveForward();
  delay(4000);

  stopMotor();
  delay(2000);

  diagonalRight();
  delay(2000);

  stopMotor();
  delay(3000);

  turnLeft();
  delay(1000);

  stopMotor();
  delay(3000);
}

//LEFT SIDE WHEEL
/// FRONT LEFT in1_1 & in2_1 - MOTOR 1
/// REAR RIGHT in3_1 & in4_1 - MOTOR 2

//RIGHT SIDE WHEEL
/// FRONT RIGHT in1_2 & in2_2 - MOTOR 3
/// REAR LEFT in3_2 & in4_2 - MOTOR 4

// DC motor enable pin is used for speed control; max_speed = 255,

void moveForward() {
  //ALL WHEELS FORWARD
  digitalWrite(in1_1, HIGH); digitalWrite(in2_1, LOW);
  digitalWrite(in3_1, HIGH); digitalWrite(in4_1, LOW);
  digitalWrite(in1_2, LOW); digitalWrite(in2_2, HIGH);
  digitalWrite(in3_2, LOW); digitalWrite(in4_2, HIGH);
  analogWrite(enA1, 128); analogWrite(enB1, 128);
  analogWrite(enA2, 128); analogWrite(enB2, 128);
}

void moveBackward() {
  //ALL WHEELS BACKWARD
  digitalWrite(in1_1, LOW); digitalWrite(in2_1, HIGH);
  digitalWrite(in3_1, LOW); digitalWrite(in4_1, HIGH);
  digitalWrite(in1_2, HIGH); digitalWrite(in2_2, LOW);
  digitalWrite(in3_2, HIGH); digitalWrite(in4_2, LOW);
  analogWrite(enA1, 128); analogWrite(enB1, 128);
  analogWrite(enA2, 128); analogWrite(enB2, 128);
}

void turnLeft() {
  // Left motors backward, right motors forward
  digitalWrite(in1_1, HIGH); digitalWrite(in2_1, LOW); // Motor 1
  digitalWrite(in3_1, HIGH); digitalWrite(in4_1, LOW); // Motor 2
  digitalWrite(in1_2, HIGH); digitalWrite(in2_2, LOW); // Motor 3
  digitalWrite(in3_2, HIGH); digitalWrite(in4_2, LOW); // Motor 4
  analogWrite(enA1,128); analogWrite(enB1, 128);
  analogWrite(enA2, 128); analogWrite(enB2, 128);
}

void turnRight() {
  // Left motors forward, right motors backward
  digitalWrite(in1_1, LOW); digitalWrite(in2_1, HIGH); // Motor 1
  digitalWrite(in3_1, LOW); digitalWrite(in4_1, HIGH); // Motor 2
  digitalWrite(in1_2, LOW); digitalWrite(in2_2, HIGH); // Motor 3
  digitalWrite(in3_2, LOW); digitalWrite(in4_2, HIGH); // Motor 4
  analogWrite(enA1,128); analogWrite(enB1, 128);
  analogWrite(enA2, 128); analogWrite(enB2, 128);
}

void diagonalLeft() {//moving forward
  //Front right wheel & rear right wheel
  digitalWrite(in1_1, LOW); digitalWrite(in2_1, LOW); // Motor 1
  digitalWrite(in3_1, LOW); digitalWrite(in4_1, HIGH); // Motor 2
  digitalWrite(in1_2, LOW); digitalWrite(in2_2, LOW); // Motor 3
  digitalWrite(in3_2, HIGH); digitalWrite(in4_2, LOW); // Motor 4
  analogWrite(enA1, 128); analogWrite(enB1, 128);
  analogWrite(enA2,128); analogWrite(enB2, 128);
}

void diagonalLeftBackward() {
  //Front right wheel & rear right wheel
  digitalWrite(in1_1, LOW); digitalWrite(in2_1, LOW); // Motor 1
  digitalWrite(in3_1, HIGH); digitalWrite(in4_1, LOW); // Motor 2
  digitalWrite(in1_2, LOW); digitalWrite(in2_2, LOW); // Motor 3
  digitalWrite(in3_2, LOW); digitalWrite(in4_2, HIGH); // Motor 4
  analogWrite(enA1, 128); analogWrite(enB1, 128);
  analogWrite(enA2,128); analogWrite(enB2, 128);
}

void diagonalRightBackward() {
  // Front left wheel & rear left wheel
  digitalWrite(in1_1, HIGH); digitalWrite(in2_1, LOW); // Motor 1
  digitalWrite(in3_1, LOW); digitalWrite(in4_1, LOW); // Motor 2
  digitalWrite(in1_2, LOW); digitalWrite(in2_2, HIGH); // Motor 3
  digitalWrite(in3_2, LOW); digitalWrite(in4_2, LOW); // Motor 4
  analogWrite(enA1, 128); analogWrite(enB1, 128);
  analogWrite(enA2,128); analogWrite(enB2, 128);
}

void diagonalRight() {//moving forwards
  // Front left wheel & rear left wheel
  digitalWrite(in1_1, LOW); digitalWrite(in2_1, HIGH); // Motor 1
  digitalWrite(in3_1, LOW); digitalWrite(in4_1, LOW); // Motor 2
  digitalWrite(in1_2, HIGH); digitalWrite(in2_2, LOW); // Motor 3
  digitalWrite(in3_2, LOW); digitalWrite(in4_2, LOW); // Motor 4
  analogWrite(enA1, 128); analogWrite(enB1, 128);
  analogWrite(enA2,128); analogWrite(enB2, 128);
}

void stopMotor() {
  analogWrite(enA1, 0); analogWrite(enB1, 0);
  analogWrite(enA2, 0); analogWrite(enB2, 0);
}
