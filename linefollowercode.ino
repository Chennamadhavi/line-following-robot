// Arduino Line Follower Robot Code

#define enA 3 // Enable1 L293 Pin enA 
#define in1 6 // Motor1 L293 Pin in1 
#define in2 7 // Motor1 L293 Pin in1 
#define in3 10 // Motor2 L293 Pin in1 
#define in4 11 // Motor2 L293 Pin in1 
#define enB 9 // Enable2 L293 Pin enB 
#define R_S 4 // ir sensor Right
#define L_S 2 // ir sensor Left

void setup() {
  Serial.begin(9600);
  pinMode(R_S, INPUT);
  pinMode(L_S, INPUT);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);
}

void loop() {
  if (digitalRead(R_S) == 0 && digitalRead(L_S) == 0) {
    forward(); // Both sensors on white (off the line), move forward to find the line
  } else if (digitalRead(R_S) == 1 && digitalRead(L_S) == 0) {
    turnRight(); // Right sensor on black, left on white, turn right
  } else if (digitalRead(R_S) == 0 && digitalRead(L_S) == 1) {
    turnLeft(); // Right sensor on white, left on black, turn left
  } else if (digitalRead(R_S) == 1 && digitalRead(L_S) == 1) {
    forward(); // Both sensors on black (on the line), stop to prevent overshooting
  }
}

void forward() {
  analogWrite(enA, 150); // Increased speed for straight movement
  analogWrite(enB, 150);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void turnRight() {
  analogWrite(enA, 120); // Adjusted speed for better turning accuracy
  analogWrite(enB, 120);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void turnLeft() {
  analogWrite(enA, 120); // Adjusted speed for better turning accuracy
  analogWrite(enB, 120);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void Stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}