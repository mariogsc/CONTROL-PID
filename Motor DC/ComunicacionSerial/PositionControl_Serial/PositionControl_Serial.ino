
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
typedef union {
  float value;
  byte bytes[16];
} my_union;

my_union current_position;
float myVal;
const int buffer_size = 16;
byte buf[buffer_size];

float u;

void setup() {
  Serial.begin(115200, SERIAL_8N1);
  pinMode(ENCA, INPUT);
  pinMode(ENCB, INPUT);
  attachInterrupt(digitalPinToInterrupt(ENCA), readEncoder, RISING);
  
  pinMode(PWM, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  u = 0;
  pos = 0;
}

void loop() {
  // Leer entrada serial para actualizar el target
  if (Serial.available() > 0) {
    writeToMatlab(pos);

    delay(10);
    
    noInterrupts(); // Disable interrupts temporarily while reading
    pos = pulses * 360 / 1550; // Asegúrate de que 1550 es correcto
    interrupts(); // Turn interrupts back on
      
  
    // -------- send signal to the motor --------
    int dir = (u < 0) ? -1 : 1; // Motor direction
    u = constrain(u, 0, 255); // Limitar u para que esté en el rango 0-255
    setMotor(dir, u, PWM, IN1, IN2);

    u = readFromMatlab(); 
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

float readFromMatlab() {
  int reln = Serial.readBytesUntil('\n', buf, buffer_size);
  if (reln > 0) {
    for (int i = 0; i < reln && i < sizeof(current_position.bytes); i++) {
      current_position.bytes[i] = buf[i];
    }
  }
  return current_position.value;
}

void writeToMatlab(float number) {
  byte *b = (byte*)&number;
  Serial.write(b, 4);
  Serial.write(13); // '\r'
  Serial.write(10); // '\n'
}
