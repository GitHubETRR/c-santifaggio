#include <Arduino.h>

#define TRIGGER_1 2
#define ECHO_1    3

#define TRIGGER_2 4
#define ECHO_2    5

#define IR_FD    A2
#define IR_FI    A3
#define NEGRO     0
#define BLANCO    1

#define VELOCIDAD    200
#define FRENO        200
#define TIME_GIRO     50
#define VEL_GIRO     150
#define MICRO_SEG     10

#define MOTOR1_A       8
#define MOTOR1_B       9
#define MOTOR2_A       7
#define MOTOR2_B      12
#define PWM_1         10
#define PWM_2         11
#define LUZ_SEGURIDAD 13
#define TIME_SEGURIDAD 5

extern int time_frontal_1;
extern int dist_frontal_1;
extern int time_frontal_2;
extern int dist_frontal_2;


class Robot {  
  public: 
  void Trigger_on();
  void Avanzar();
  void Atras();
  void Derecha();
  void Izquierda();
  void Frenado();
  void Echo_on();
};