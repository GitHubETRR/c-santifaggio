#include "megatron.h"

uint8_t dist_vision = 150;

int time_frontal_1 = 0;
int dist_frontal_1 = 0;
int time_frontal_2 = 0;
int dist_frontal_2 = 0;

Robot megatron;

void setup(){ 
  pinMode(IR_FD,INPUT);
  pinMode(IR_FI,INPUT);
  pinMode(MOTOR1_A,OUTPUT);
  pinMode(MOTOR1_B,OUTPUT);
  pinMode(MOTOR2_A,OUTPUT);
  pinMode(MOTOR2_B,OUTPUT);
  pinMode(TRIGGER_1,OUTPUT);
  pinMode(TRIGGER_2,OUTPUT);
  pinMode(LUZ_SEGURIDAD,OUTPUT);

  digitalWrite(TRIGGER_1, LOW);
  digitalWrite(TRIGGER_2, LOW);
  digitalWrite(LUZ_SEGURIDAD, LOW);

  for(int i=0;i<TIME_SEGURIDAD;i++){
    digitalWrite(LUZ_SEGURIDAD,HIGH);
    delay(500);
    digitalWrite(LUZ_SEGURIDAD,LOW);
    delay(500);
  }
  digitalWrite(LUZ_SEGURIDAD,LOW);
}

void loop(){ 
  megatron.Trigger_on();
  megatron.Echo_on();
    
  //caso 1
  while(dist_frontal_1 > dist_vision && dist_frontal_2 > dist_vision && digitalRead(IR_FD)= NEGRO && digitalRead(IR_FI)= NEGRO) {
    analogWrite(PWM_1,VEL_GIRO);
    analogWrite(PWM_2,VEL_GIRO);
    megatron.Derecha();
    delay(TIME_GIRO);
  };

    //caso 2
  if(dist_frontal_1<=dist_vision && dist_frontal_2<=dist_vision){
    while(dist_frontal_1<=dist_vision && dist_frontal_2<=dist_vision && digitalRead(IR_FD)=NEGRO && digitalRead(IR_FI)=NEGRO){ //si distancia frontal es la menor
      analogWrite(PWM_1,VELOCIDAD);
      analogWrite(PWM_2,VELOCIDAD);
      megatron.Avanzar();
      delay(FRENO);
      megatron.Frenado();
    }

  //caso 3
  if(digitalRead(IR_FD)= BLANCO || digitalRead(IR_FI)= BLANCO){
      while(digitalRead(IR_FD)=BLANCO || digitalRead(IR_FI)=BLANCO){
        analogWrite(PWM_1,VELOCIDAD);
        analogWrite(PWM_2,VELOCIDAD);
        megatron.Atras();
      }
      analogWrite(PWM_1,VEL_GIRO);
      analogWrite(PWM_2,VEL_GIRO);
      megatron.Derecha();
      delay(FRENO);
      megatron.Frenado();
    }
  }
}