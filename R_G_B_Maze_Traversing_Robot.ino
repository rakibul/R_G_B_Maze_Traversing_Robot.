/**
 * 
 * @name R-G-B Maze Traversing Robot
 * @author Mohammad Rakibul Haider
 * @version 0.2
 * @description Interface Arduino with two D.C. Motors. In this phase
 *  we will implement basic movement (turn left-right, move forward-background) and control
 *  speed (using P.W.M.). Drive our robot from Arduino Serial Terminal.
 */
 
int M1Pin_1 = 3; //PWM pin 3
int M1Pin_2 = 5; //PWM pin 5

int M2Pin_1 = 6; //PWM pin 6
int M2Pin_2 = 9; //PWM pin 9

byte input;      //variable for keyboard input

static int Speed = 200; //Robot Speed variable

/**
 * 
 * @param none
 * @return void
 */
void increaseSpeed(){
  if(Speed <256){
    Speed += 5;
  }  
}

/**
 * 
 * @param none
 * @return void
 */
void decreaseSpeed(){
  if(Speed > 0){
    Speed -= 5;
  }  
}


/**
 * 
 * @param int mPin1
 * @param int mPin2
 * @param int mPin3
 * @param int mPin4
 * @return void
 */

void turnLeft(int mPin1, int mPin2, int mPin3, int mPin4){
    stop(mPin3, mPin4);
    analogWrite(mPin1, Speed);
    analogWrite(mPin2, 0);
}

/**
 * 
 * @param int mPin1
 * @param int mPin2
 * @param int mPin3
 * @param int mPin4
 * @return void
 */
void turnRight(int mPin1, int mPin2, int mPin3, int mPin4){
    stop(mPin3, mPin4);
    analogWrite(mPin1, Speed);
    analogWrite(mPin2, 0);
}

/**
 * 
 * @param int mPin1
 * @param int mPin2
 * @return void
 */
void stop(int mPin1, int mPin2){
    digitalWrite(mPin1, LOW);
    digitalWrite(mPin2, LOW);   
}

/**
 * 
 * @param int mPin1
 * @param int mPin2
 * @return void
 */
void forward(int mPin1, int mPin2){
    analogWrite(mPin1, Speed);
    analogWrite(mPin2, 0);
}

/**
 * 
 * @param int mPin1
 * @param int mPin2
 * @return void
 */
void reverse(int mPin1, int mPin2){
    analogWrite(mPin2, Speed);
    analogWrite(mPin1, 0);
}


void setup(){
   pinMode(M1Pin_1, OUTPUT);
   pinMode(M1Pin_2, OUTPUT);
   pinMode(M2Pin_1, OUTPUT);
   pinMode(M2Pin_2, OUTPUT);
   Serial.begin(9600); //initialize serial input
}

void loop(){   
  //Serial.println(Speed);
    if(Serial.available() > 0) {
        input = Serial.read();
        switch(input) {
           case 'f':
             forward(M1Pin_1, M1Pin_2);
             forward(M2Pin_1, M2Pin_2);
             delay(1000);
             break;
           case 'b':
             reverse(M1Pin_1, M1Pin_2);
             reverse(M2Pin_1, M2Pin_2);
             delay(1000);
             break;
           case 's':
             stop(M1Pin_1, M1Pin_2);
             stop(M2Pin_1, M2Pin_2);
             delay(1000);
             break;
           case 'i':
             increaseSpeed();
             delay(1000);
             break;
           case 'd':
             decreaseSpeed();
             delay(1000);
             break;
           case 'r':
             turnRight(M2Pin_1, M2Pin_2, M1Pin_1, M1Pin_2);
             break;
           case 'l':
             turnLeft(M1Pin_1, M1Pin_2, M2Pin_1, M2Pin_2);
             break; 
        }
    }
}
