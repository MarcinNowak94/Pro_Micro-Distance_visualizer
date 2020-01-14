
#include <HCSR04.h>
//This project uses Sparkfun Pro Micro
//https://cdn.sparkfun.com/assets/f/d/8/0/d/ProMicro16MHzv2.pdf
#define ECHO     14
#define TRIG     15
#define LED_PWM  10

UltraSonicDistanceSensor sensor(TRIG, ECHO);
double temperature=20;
double distance   =0;
int distance_pwm  =0;

int sensor_max   =400;
int pwm_write_max=255;
double ratio      =0.63;//(pwm_write_max*100)/sensor_max;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PWM, OUTPUT);

}

void loop() {  
  distance=sensor.measureDistanceCm();
  distance_pwm=int(distance*ratio);
  Serial.println(distance);
  analogWrite(LED_PWM, distance_pwm);
};
