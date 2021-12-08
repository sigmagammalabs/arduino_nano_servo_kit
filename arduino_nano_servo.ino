
#include <Servo.h>
#include <avr/sleep.h>


#define SERVO_POS_PRESS_DOWN	10 
#define SERVO_POS_RELEASE		160

Servo 	servo;  

unsigned int servo_pos 			= 	0;    
unsigned int digital_input		= 	2;
unsigned int servo_supply 		= 	10;




void servo_control(){
	digitalWrite(servo_supply, HIGH);
	servo_pos = SERVO_POS_PRESS_DOWN;
	servo.write(servo_pos);              
	delay(800); 

	servo_pos = SERVO_POS_RELEASE;
	servo.write(servo_pos); 
}


void setup() {	
	servo.attach(9);  	
	pinMode(servo_supply, OUTPUT);	
	pinMode(digital_input, INPUT);
	digitalWrite(digital_input, LOW);
	pinMode(3, OUTPUT);	
	servo_pos = SERVO_POS_RELEASE;
	servo.write(servo_pos);  
	delay(1000);
}

void loop() {
    digitalWrite(servo_supply, HIGH);
    delay(200);
    servo_control();
    delay(500);
    digitalWrite(servo_supply, LOW);
    delay(5000);

  	while( digitalRead(digital_input) ){
  		delay(5);
  	} 
}
