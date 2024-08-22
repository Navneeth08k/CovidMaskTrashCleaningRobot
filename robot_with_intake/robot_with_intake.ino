// code for robot with intake. Check if working when new HC05 comes
// probably doesn't work but idk

int enableA = 9;
int in1 = 4;
int in2 = 3;
int in3 = 2;
int in4 = 8;
int enableB = 6;

int enableC = 10; // intake enableA
int in5 = 11;     // intake inp 1
int in6 = 12;     // intake inp2

void forward()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(in5, LOW);
  digitalWrite(in6, LOW);
}

void backward()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(in5, LOW);
  digitalWrite(in6, LOW);
}
void left()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(in5, LOW);
  digitalWrite(in6, LOW);
}
void right()
{
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(in5, LOW);
  digitalWrite(in6, LOW);
}
void runIntake()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
}
void Stop()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(in5, LOW);
  digitalWrite(in6, LOW);
}

int val;
void setup()
{
  Serial.begin(9600);

  //for motor 1 (wheel)
  pinMode(enableA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  //for motor 2(Wheel)
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);  
  pinMode(enableB, OUTPUT);

  //for motor 3 (Intake)
  pinMode(enableC, OUTPUT);
  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);

  analogWrite(enableA, 255);
  analogWrite(enableB, 255);
  analogWrite(enableC, 255);
  Stop();
}

void loop()
{

  val = Serial.read();
  // Serial.print(val);
  delay(100); // can remove? maybe try later?
  Stop();

  if (val == '1') // when the bluetooth module recieves 1 the car moves forward
  {
    forward();
  }

  if (val == '2') // when the bluetooth module recieves 2 the car moves backward
  {
    backward();
  }

  if (val == '3') // when the bluetooth module recieves 3 the car moves left
  {
    left();
  }

  if (val == '4') // when the bluetooth module recieves 4 the car moves right
  {
    right();
  }

  if (val == '5') // when the bluetooth module recieves 5 the car stops
  {
    Stop();
  }

  if (val == '6')
  { // when the bluetooth module recieves 6 the intake runs
    runIntake();
  }
}