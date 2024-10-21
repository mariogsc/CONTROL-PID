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
float pos = 0; 

// Serial comunication
typedef union{
  float value;
  byte bytes[16];
}my_union;

my_union current_position;
float myVal;
const int buffer_size = 16;
byte buf[buffer_size];

// control parameters
  // PID constants
  float kp = 19.5;
  float kd = 6.0;
  float ki = 10.25;

  
void setup() {
  Serial.begin(115200,SERIAL_8N1);
  pinMode(ENCA,INPUT);
  pinMode(ENCB,INPUT);
  attachInterrupt(digitalPinToInterrupt(ENCA),readEncoder,RISING);
  
  pinMode(PWM,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);

}

void loop() {

  // Leer entrada serial para actualizar el target
  if (Serial.available() > 0) {
    target = readFromMatlab(); 
    delay(0.1);

    // time difference
    long currT = micros();
    float deltaT = ((float) (currT - prevT)) / (1.0e6);
    prevT = currT;

    
    noInterrupts(); // disable interrupts temporarily while reading
    pos = pulses*360/(1550); // 1 Vuelta completa son 1600 pulsos
    interrupts(); // turn interrupts back on
      
    writeToMatlab(pos);
    
  
    // ---------- pid computation ------
    // error
    int e = pos - target;
    // derivative
    float dedt = (e - eprev) / deltaT;
    // integral
    eintegral = eintegral + e * deltaT;
    // control signal
    float u = kp * e + kd * dedt + ki * eintegral;
  
  
  // -------- send signal to the motor --------
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

  }
  // Serial.println(pos);  // debug
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

float readFromMatlab(){
  int reln = Serial.readBytesUntil('\n',buf,buffer_size);
  for(int i=0;i<buffer_size;i++){
    current_position.bytes[i] = buf[i];
  }

  float output = current_position.value;
  return output;
}

void writeToMatlab(float number){
  byte *b = (byte*) &number;
  Serial.write(b,4);
  Serial.write(13); // '\r'
  Serial.write(10); // '\n'
  
}
