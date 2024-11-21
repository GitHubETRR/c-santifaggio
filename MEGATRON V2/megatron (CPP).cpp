#include "megatron.h"


void Robot::Avanzar()  {
  digitalWrite(MOTOR1_A, LOW);
  digitalWrite(MOTOR1_B, HIGH);
  digitalWrite(MOTOR2_A, LOW);
  digitalWrite(MOTOR2_B, HIGH);
};
void Robot::Atras()    {
  digitalWrite(MOTOR1_A, HIGH);
  digitalWrite(MOTOR1_B, LOW);
  digitalWrite(MOTOR2_A, HIGH);
  digitalWrite(MOTOR2_B, LOW);
};
void Robot::Derecha()  {
  digitalWrite(MOTOR1_A, HIGH);
  digitalWrite(MOTOR1_B, LOW);
  digitalWrite(MOTOR2_A, LOW);
  digitalWrite(MOTOR2_B, HIGH);
};
void Robot::Izquierda(){
  digitalWrite(MOTOR1_A, LOW);
  digitalWrite(MOTOR1_B, HIGH);
  digitalWrite(MOTOR2_A, HIGH);
  digitalWrite(MOTOR2_B, LOW);
};
void Robot::Frenado()  {
  digitalWrite(PWM_1, LOW);
  digitalWrite(PWM_2, LOW);
  digitalWrite(MOTOR1_A, LOW);
  digitalWrite(MOTOR1_B, LOW);
  digitalWrite(MOTOR2_A, LOW);
  digitalWrite(MOTOR2_B, LOW);
};

void Robot::Trigger_on(){
  digitalWrite(TRIGGER_1, HIGH);
  digitalWrite(TRIGGER_2, HIGH);
  delayMicroseconds(MICRO_SEG);//Pulso de 10us
  digitalWrite(TRIGGER_1, LOW); 
  digitalWrite(TRIGGER_2, LOW);
};

void Robot::Echo_on(){
  time_frontal_1 = pulseIn(ECHO_1, HIGH); //obtenemos el ancho del pulso
  dist_frontal_1 = time_frontal_1/59; 
  time_frontal_2 = pulseIn(ECHO_2, HIGH);
  dist_frontal_2 = time_frontal_2/59;
};