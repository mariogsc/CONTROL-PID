#define ENCA 2 // YELLOW
#define ENCB 3 // WHITE
#define PWM 8
#define IN2 7
#define IN1 6

volatile int pulses = 0; 
long prevT = 0;
float eprev = 0;
float eintegral = 0;
int target = 0; // Valor predeterminado

void setup() {
  Serial.begin(9600);
  pinMode(ENCA,INPUT);
  pinMode(ENCB,INPUT);
  attachInterrupt(digitalPinToInterrupt(ENCA),readEncoder,RISING);
  
  pinMode(PWM,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  
  Serial.println("Ingrese la pulsesción objetivo (target) por el Serial Monitor:");
}

void loop() {

  // Leer entrada serial para actualizar el target
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    target = input.toInt(); // Convertir a entero
    Serial.print("Nueva pulsesción objetivo establecida: ");
    Serial.println(target);
  }

  // PID constants
  float kp = 8.5;
  float kd = 3.0;
  float ki = 10.25;

  // time difference
  long currT = micros();
  float deltaT = ((float) (currT - prevT)) / (1.0e6);
  prevT = currT;

  // Read the pulsestion
  int pos = 0; 
  noInterrupts(); // disable interrupts temporarily while reading
  pos = pulses*360/(1550); // 1 Vuelta completa son 1600 pulsos
  interrupts(); // turn interrupts back on
  
  // error
  int e = pos - target;

  // derivative
  float dedt = (e - eprev) / deltaT;

  // integral
  eintegral = eintegral + e * deltaT;

  // control signal
  float u = kp * e + kd * dedt + ki * eintegral;

  // motor power
  float pwr = fabs(u);
  if (pwr > 255) {
    pwr = 255;
  }

  // motor direction
  int dir = 1;
  if (u < 0) {
    dir = -1;
  }

  // signal the motor
  setMotor(dir, pwr, PWM, IN1, IN2);

  // store previous error
  eprev = e;

  // Imprimir valores para monitorear
  Serial.print(target);
  Serial.print(" ");
  Serial.print(pos);
  Serial.print(" ");
  Serial.println(pwr);
}

void setMotor(int dir, int pwmVal, int pwm, int in1, int in2) {
  analogWrite(pwm, pwmVal);
  if (dir == 1) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
  } else if (dir == -1) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
  } else {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
  }  
}

void readEncoder() {
  int b = digitalRead(ENCB);
  if (b > 0) {
    pulses++;
  } else {
    pulses--;
  }
}
