int M1Pin_1 = 3;
int M1Pin_2 = 5;

int M2Pin_1 = 6;
int M2Pin_2 = 9;

byte input;

static int Speed= 200;

void increaseSpeed(){
  if(Speed <256){
    Speed += 5;
  }  
}

void decreaseSpeed(){
  if(Speed > 0){
    Speed -= 5;
  }  
}

void stop(int mPin1, int mPin2){
    digitalWrite(mPin1, LOW);
    digitalWrite(mPin2, LOW);   
}

void forward(int mPin1, int mPin2){
    analogWrite(mPin1, Speed);
    analogWrite(mPin2, 0);
}

void reverse(int mPin1, int mPin2){
    analogWrite(mPin2, Speed);
    analogWrite(mPin1, 0);
}


void setup(){
   pinMode(M1Pin_1, OUTPUT);
   pinMode(M1Pin_2, OUTPUT);
   pinMode(M2Pin_1, OUTPUT);
   pinMode(M2Pin_2, OUTPUT);
     Serial.begin(9600);
}

void loop(){   
  Serial.println(Speed);
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
        }
    }
}
