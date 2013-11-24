#include <Servo.h>

/*
 * Define our servo motors
 * Serv1 is on pin 10
 * Serv2 is on pin 9
 */

Servo right_servo;
int right_servo_pin = 9; // connect to serv2
Servo left_servo;
int left_servo_pin = 10; // connect to serv1
int serial_speed = 9600; // your call here ;)
int pos;

void setup() {
  right_servo.attach(right_servo_pin);
  left_servo.attach(left_servo_pin);
  Serial.begin(serial_speed);
  stop();
}

/*
 * We want to use continuous rotation servos to control each wheel
 *
 * Pass in the value for pos, sent directly to the servos so be careful
 *
 */
int move_servos_together(int pos) {
  right_servo.write(pos);
  left_servo.write(pos);
}

/*
 * Turns left, 
 *   left motor is sent positive pos
 *   right motor is sent negative pos
 *
 */
int turn_left(int pos) {
  right_servo.write(pos);
  left_servo.write(-pos);
}

/*
 * Turns right, 
 *   right motor is sent positive pos
 *   left motor is sent negative pos
 *
 */
int turn_right(int pos) {
  right_servo.write(-pos);
  left_servo.write(pos);
}

// Simple little demo - helpful for motor orientation and debugging
void walk_demo() {
  Serial.println("Walk forward full speed");
  move_servos_together(180);
  delay(3000);
  stop();
  delay(3000);
  Serial.println("Walk backward full speed");
  move_servos_together(0);
}

void circle_ish() {

}

/*
 * Note, for the servos I'm using I had to adjust the stop value.
 * There are little pots behind the power/data connectors - just set the 
 * servos to the 90/90 and then turn one  direction or the other until the
 * servo stops completely.
 * I'm using Parallax Continuous rotation servos. http://www.adafruit.com/products/154
 */
void stop() {
  right_servo.write(90);
  left_servo.write(90);
}

void servo_status() {
  Serial.print("Current readings, right: ");
  Serial.print(right_servo.read());
  Serial.print(" Current readings, left: ");
  Serial.println(left_servo.read());
}

void loop() {  
  walk_demo;
  servo_status;
  delay(3000);
}
