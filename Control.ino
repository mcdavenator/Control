#include <PID_v1.h>

//    setpoint, input, output
double pot, tacho, matsomoto;
double kp, ki, kd;

double tacho_pin = A7;
double pot_pin = A5;
double matsomoto_pin = 5;

PID piddles(&tacho,&matsomoto,&pot,0,1,0.10175,P_ON_E,DIRECT);

void setup() {
  // put your setup code here, to run once:

  




//
//double kp = 10;
//double ki = 10;
//double kd = 10;

pinMode(tacho_pin, INPUT);
pinMode(pot_pin, INPUT);
pinMode(matsomoto_pin, OUTPUT);

pinMode(2, OUTPUT);  //For use with the chip
pinMode(6, OUTPUT);

digitalWrite(2,HIGH);
digitalWrite(6,LOW); 

Serial.begin(9600);
Serial.println("Heyo, bucko");

piddles.SetMode(AUTOMATIC);

}

void loop() {
  // put your main code here, to run repeatedly:

pot=map(analogRead(pot_pin),0,1023,0,255);
tacho=map(analogRead(matsomoto_pin),0,1023,0,255);


piddles.Compute();

analogWrite(5,matsomoto);

Serial.print(pot);
Serial.print("    ");
Serial.print(tacho);
Serial.print("    ");
Serial.print(matsomoto);
Serial.println("    ");
}
