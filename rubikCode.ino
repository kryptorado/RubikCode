
#include <AFMotor.h>

#include <Servo.h> 
AF_DCMotor motor(2, MOTOR12_64KHZ); // create motor #2, 64KHz pwm

// DC motor on M2

// DC hobby servo
Servo servo1;
Servo servo2;


// Stepper motor on M3+M4 48 steps per revolution
int i = 0;
long num;

int f = 1;
int b = 2;
int u = 3;
int d = 4;
int l = 5;
int r = 6;


void setup() {
  servo1.attach(10);//Attach servo 1 to pin 9 
  servo2.attach(9);//Attach servo 1 to pin 9 

  servo1.write(0); //Resets the servo position to 0
  servo2.write(0); //Resets the servo position to 0
  
  motor.setSpeed(70);     // set the speed to 200/255
}



//a0

void liftDown(){
  servo1.write(0);
  delay(160); 
  }

void liftUp(){
  servo1.write(180);
  delay(160);
  
  }

void grab(){
  servo2.write(100);
  delay(160);
  }

void unGrab(){
  servo2.write(180);
  delay(160);
  }


void runMotor(){

  motor.run(FORWARD);      // turn it on going forward
  delay(170);
 
//  Serial.print("tock");
//  motor.run(BACKWARD);     // the other way
//  delay(1000);
//  
  Serial.print("tack");
  motor.run(RELEASE);      // stopped
  delay(2000);
  }

void loop() {
  //runMotor();
  liftUp();
  liftDown();
  
  int dir = random(1,6);
  int turnNum = random (1,3);
  
  if(dir == f){
    
    liftUp();
    unGrab();
    liftDown();
    grab();
    runMotor();
    liftUp();
    unGrab();
    liftUp();
    grab(); 
    for (int j = 0; j <= turnNum; j++){
      runMotor();
    }  
  }
  
  if(dir == b){
    
    liftUp();
    unGrab();
    liftDown();
    grab();
    for (int j = 0; j <= turnNum; j++){
      runMotor();
    }  
  }
  
  if(dir == u){
    
    liftUp();
    unGrab();
    liftDown();
    grab();
    liftUp();
    unGrab();
    liftDown();
    liftUp();
    for (int j = 0; j <= turnNum; j++){
      runMotor();
    }    }

  if(dir == d){
    runMotor();
  }

  if(dir == l){
    
    unGrab();
    runMotor();
    runMotor();
    runMotor();
    grab();
    liftUp();
    unGrab();
    liftDown();
    grab();
    for (int j = 0; j <= turnNum; j++){
      runMotor();
    }    }

    else{
    unGrab();
    runMotor();
    liftDown();
    liftUp();
    unGrab();
    liftDown();
    grab();
    for (int j = 0; j <= turnNum; j++){
      runMotor();
    }    
}

}
 

