#include <AFMotor.h>
#include <Smoothed.h>

Smoothed <float> mySensor;
AF_DCMotor motor(4);

const int kp = A0;
const int ki = A1;
const int kd = A2;
const int ref = A3;
const int cikis = A4;

float dkp;
float dki;
float dkd;
float dki1;
float dkd1;

int dref;
int derror;
int dcikis;
int spd;
int hata1 = 0;
int hata2 = 255;
int dpkontrol;
int dpikontrol;
int dpdkontrol;
int u;

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  Serial.begin(9600);
  mySensor.begin(SMOOTHED_EXPONENTIAL, 10);
}

void loop() {
  dkp = analogRead(kp);
  dki1 = analogRead(ki);
  dkd1 = analogRead(kd);
  dref = analogRead(ref);
  dcikis = analogRead(cikis);

  dkp = map(dkp, 0, 1023, 0, 5);
  dki = dki1 / 10000;
  dkd = dkd1 / 5000;

  dref = map(dref, 0, 1023, 0, 255);
  dcikis = map(dcikis, 0, 1023, 0, 255);
  derror = dref - dcikis;
  hata1 = hata1 + derror;
  hata2 = derror - hata2;
  dpkontrol = derror * dkp;
  dpikontrol = dki * hata1;
  dpdkontrol = dkd * hata2;
  u = dpkontrol + dpikontrol + dpdkontrol;

  if (u > 1200) {
    u = 1200;
  }

  mySensor.add(u);
  float smoothedSensorValueAvg = mySensor.get();

  motor.run(FORWARD);
  spd = map(smoothedSensorValueAvg, 0, 1200, 0, 255);
  motor.setSpeed(spd);
  hata2 = derror;
  Serial.print(" u: ");
  Serial.println(smoothedSensorValueAvg);
  float lastValueStoredAvg = mySensor.getLast();
}
