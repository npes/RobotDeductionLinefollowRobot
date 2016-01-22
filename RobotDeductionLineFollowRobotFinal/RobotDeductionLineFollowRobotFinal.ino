// sensors
//int leftSSensor=12;
//int rightSSensor=13;
int center = 8; //hvid
int centerLeftS = 7; //lilla
int centerRightS = 13; //grøn
int leftS = 4; //blå
int rightS = 2; //brun

// motor pins
int motorleftSA=6; // pin 6 på arduino forbunet til pin 2 på motor driver
int motorrightSA=10; // pin 10 på arduino forbunet til pin 10 på motor driver
int motorleftSB=9; // pin 9 på arduino forbunet til pin 7 på motor driver
int motorrightSB=3; // pin 3 på arduino forbunet til pin 15 på motor driver
int motorleftSSpeed=5; // pin 5 på arduino forbunet til pin 1 på motor driver
int motorrightSSpeed=11; // pin 11 på arduino forbunet til pin 9 på motor driver

// car light pins
int frontLeft = A0;
int frontRight = A1;
int backLeft = A2;
int backRight = A3;

// potentioMeter pin
int potentioMeter = A4;
int potValue;
int battery;

void setup() {
  
  // sensors
  pinMode (center, INPUT);
  pinMode (centerLeftS, INPUT);
  pinMode (centerRightS, INPUT);
  pinMode (leftS, INPUT);
  pinMode (rightS, INPUT);

  // motors
  pinMode (motorleftSA, OUTPUT);
  pinMode (motorrightSA, OUTPUT);
  pinMode (motorleftSB, OUTPUT);
  pinMode (motorrightSB, OUTPUT);
  pinMode (motorleftSSpeed, OUTPUT);
  pinMode (motorrightSSpeed, OUTPUT);

  // lights
  pinMode (frontLeft, OUTPUT);
  pinMode (frontRight, OUTPUT);
  pinMode (backLeft, OUTPUT);
  pinMode (backRight, OUTPUT);
}

void loop() {

// Sensor state
int stateCenter = digitalRead (center);
int stateCenterLeftS = digitalRead (centerLeftS);
int stateCenterRightS = digitalRead (centerRightS);
int stateLeftS = digitalRead (leftS);
int stateRightS = digitalRead (rightS);

// potentiometer for spped regulation
  // read the analog in value:
  potValue = analogRead(potentioMeter);
  // map it to the range of the analog out:
  battery = map(potValue, 0, 1023, 0, 70);

// Motor speeds
//int battery = 40; //60=new battery
int middle = 160-battery;
int slow = 140-battery;
//int slow reverse = 70;
int fast = 200-battery;
int off = 0;
//delay (20);
if (stateLeftS==0&&stateCenterLeftS==0&&stateCenter==0&&stateCenterRightS==0&&stateRightS==0) //1
    { //reverse
    DriveReverseLeftWheel(slow);
    DriveReverseRightWheel(slow);
    carLight(0, 0, 1, 1);
    delay(200);
    }
else if (stateLeftS==0&&stateCenterLeftS==0&&stateCenter==0&&stateCenterRightS==0&&stateRightS==1) //2
    { //right sharp
    DriveForwardLeftWheel(slow); // middle to slow
    DriveReverseRightWheel(slow);
    carLight(0, 1, 0, 1);
    }
else if (stateLeftS==0&&stateCenterLeftS==0&&stateCenter==0&&stateCenterRightS==1&&stateRightS==0) //3
    { //right
    DriveForwardLeftWheel(fast);
    DriveForwardRightWheel(slow);
    carLight(0, 1, 0, 0);
    }
else if (stateLeftS==0&&stateCenterLeftS==0&&stateCenter==0&&stateCenterRightS==1&&stateRightS==1) //4
    { //right
    DriveForwardLeftWheel(fast);
    DriveForwardRightWheel(slow);
    carLight(0, 1, 0, 0);
    }
else if (stateLeftS==0&&stateCenterLeftS==0&&stateCenter==1&&stateCenterRightS==0&&stateRightS==0) //5    
    { //straight
    DriveForwardLeftWheel(middle);
    DriveForwardRightWheel(middle);
    carLight(1, 1, 0, 0);
    delay(50);
    }
else if (stateLeftS==0&&stateCenterLeftS==0&&stateCenter==1&&stateCenterRightS==0&&stateRightS==1) //6
    { //right
    DriveForwardLeftWheel(fast);
    DriveForwardRightWheel(slow);
    carLight(0, 1, 0, 0);
    }
else if (stateLeftS==0&&stateCenterLeftS==0&&stateCenter==1&&stateCenterRightS==1&&stateRightS==0) //7
    { //right
    DriveForwardLeftWheel(fast);
    DriveForwardRightWheel(slow);
    carLight(0, 1, 0, 0);
    }
else if (stateLeftS==0&&stateCenterLeftS==0&&stateCenter==1&&stateCenterRightS==1&&stateRightS==1) //8
    { //right sharp
    DriveForwardLeftWheel(slow); //middle to slow
    DriveReverseRightWheel(slow);
    carLight(0, 1, 0, 1);
    }
else if (stateLeftS==0&&stateCenterLeftS==1&&stateCenter==0&&stateCenterRightS==0&&stateRightS==0) //9
    { //left
    DriveForwardLeftWheel(slow);
    DriveForwardRightWheel(fast);
    carLight(1, 0, 0, 0);
    }
else if (stateLeftS==0&&stateCenterLeftS==1&&stateCenter==0&&stateCenterRightS==0&&stateRightS==1) //10
    { //left
    DriveForwardLeftWheel(slow);
    DriveForwardRightWheel(fast);
    carLight(1, 0, 0, 0);
    }
else if (stateLeftS==0&&stateCenterLeftS==1&&stateCenter==0&&stateCenterRightS==1&&stateRightS==0) //11
    { //straight
    DriveForwardLeftWheel(middle);
    DriveForwardRightWheel(middle);
    carLight(1, 1, 0, 0);
    }
else if (stateLeftS==0&&stateCenterLeftS==1&&stateCenter==0&&stateCenterRightS==1&&stateRightS==1) //12
    { //straight
    DriveForwardLeftWheel(middle);
    DriveForwardRightWheel(middle);
    carLight(1, 1, 0, 0);
    }
else if (stateLeftS==0&&stateCenterLeftS==1&&stateCenter==1&&stateCenterRightS==0&&stateRightS==0) //13
    { //left
    DriveForwardLeftWheel(slow);
    DriveForwardRightWheel(fast);
    carLight(1, 0, 0, 0);
    }
else if (stateLeftS==0&&stateCenterLeftS==1&&stateCenter==1&&stateCenterRightS==0&&stateRightS==1) //14
    { //straight
    DriveForwardLeftWheel(middle);
    DriveForwardRightWheel(middle);
    carLight(1, 1, 0, 0);
    }
else if (stateLeftS==0&&stateCenterLeftS==1&&stateCenter==1&&stateCenterRightS==1&&stateRightS==0) //15
    { //straight
    DriveForwardLeftWheel(middle);
    DriveForwardRightWheel(middle);
    carLight(1, 1, 0, 0);
    }
else if (stateLeftS==0&&stateCenterLeftS==1&&stateCenter==1&&stateCenterRightS==1&&stateRightS==1) //16
    { //right shaerp
    DriveForwardLeftWheel(slow); //middle to slow
    DriveReverseRightWheel(slow);
    carLight(0, 1, 0, 1);
    }
else if (stateLeftS==1&&stateCenterLeftS==1&&stateCenter==1&&stateCenterRightS==1&&stateRightS==1) //17
    { //straight
    DriveForwardLeftWheel(middle);
    DriveForwardRightWheel(middle);
    carLight(1, 1, 0, 0);
    }
else if (stateLeftS==1&&stateCenterLeftS==1&&stateCenter==1&&stateCenterRightS==1&&stateRightS==0) //18
    { //left sharp
    DriveReverseLeftWheel(slow);
    DriveForwardRightWheel(slow); //middle to slow
    carLight(1, 0, 1, 0);
    }
else if (stateLeftS==1&&stateCenterLeftS==1&&stateCenter==1&&stateCenterRightS==0&&stateRightS==1) //19
    { //left
    DriveForwardLeftWheel(slow);
    DriveForwardRightWheel(fast);
    carLight(1, 0, 0, 0);
    }
else if (stateLeftS==1&&stateCenterLeftS==1&&stateCenter==1&&stateCenterRightS==0&&stateRightS==0) //20
    { //left sharp
    DriveReverseLeftWheel(slow);
    DriveForwardRightWheel(slow); //middle to slow
    carLight(1, 0, 1, 0);
    }
else if (stateLeftS==1&&stateCenterLeftS==1&&stateCenter==0&&stateCenterRightS==1&&stateRightS==1) //21
    { //straight
    DriveForwardLeftWheel(middle);
    DriveForwardRightWheel(middle);
    carLight(1, 1, 0, 0);
    }
else if (stateLeftS==1&&stateCenterLeftS==1&&stateCenter==0&&stateCenterRightS==1&&stateRightS==0) //22
    { //left
    DriveForwardLeftWheel(slow);
    DriveForwardRightWheel(fast);
    carLight(1, 0, 0, 0);
    }
else if (stateLeftS==1&&stateCenterLeftS==1&&stateCenter==0&&stateCenterRightS==0&&stateRightS==1) //23
    { //left
    DriveForwardLeftWheel(slow);
    DriveForwardRightWheel(fast);
    carLight(1, 0, 0, 0);
    }
else if (stateLeftS==1&&stateCenterLeftS==1&&stateCenter==0&&stateCenterRightS==0&&stateRightS==0) //24
    { //left
    DriveForwardLeftWheel(slow);
    DriveForwardRightWheel(fast);
    carLight(1, 0, 0, 0);
    }
else if (stateLeftS==1&&stateCenterLeftS==0&&stateCenter==1&&stateCenterRightS==1&&stateRightS==1) //25
    { //right sharp
    DriveForwardLeftWheel(slow); //middle to slow
    DriveReverseRightWheel(slow);
    carLight(0, 1, 0, 1);
    }
else if (stateLeftS==1&&stateCenterLeftS==0&&stateCenter==1&&stateCenterRightS==1&&stateRightS==0) //26
    { //right
    DriveForwardLeftWheel(fast);
    DriveForwardRightWheel(slow);
    carLight(0, 1, 0, 0);
    }
else if (stateLeftS==1&&stateCenterLeftS==0&&stateCenter==1&&stateCenterRightS==0&&stateRightS==1) //27
    { //straight
    DriveForwardLeftWheel(middle);
    DriveForwardRightWheel(middle);
    carLight(1, 1, 0, 0);
    }
else if (stateLeftS==1&&stateCenterLeftS==0&&stateCenter==1&&stateCenterRightS==0&&stateRightS==0) //28
    { //left
    DriveForwardLeftWheel(slow);
    DriveForwardRightWheel(fast);
    carLight(1, 0, 0, 0);
    }
else if (stateLeftS==1&&stateCenterLeftS==0&&stateCenter==0&&stateCenterRightS==1&&stateRightS==1) //29
    { //right sharp
    DriveForwardLeftWheel(slow); //middle to slow
    DriveReverseRightWheel(slow);
    carLight(0, 1, 0, 1);
    }
else if (stateLeftS==1&&stateCenterLeftS==0&&stateCenter==0&&stateCenterRightS==1&&stateRightS==0) //30
    { //straight
    DriveForwardLeftWheel(middle);
    DriveForwardRightWheel(middle);
    carLight(1, 1, 0, 0);
    }
else if (stateLeftS==1&&stateCenterLeftS==0&&stateCenter==0&&stateCenterRightS==0&&stateRightS==1) //31
    { //straight
    DriveForwardLeftWheel(middle);
    DriveForwardRightWheel(middle);
    carLight(1, 1, 0, 0);
    }
else if (stateLeftS==1&&stateCenterLeftS==0&&stateCenter==0&&stateCenterRightS==0&&stateRightS==0) //32
    { //left sharp
    DriveReverseLeftWheel(slow);
    DriveForwardRightWheel(middle);
    carLight(1, 0, 1, 0);
    }
}


//**** functions ****//
  int DriveForwardLeftWheel(int spd) {
    int spdsetting = spd;
    analogWrite(motorleftSSpeed, spdsetting);
    digitalWrite(motorleftSA, 1);
    digitalWrite(motorleftSB, 0);
  }
  int DriveForwardRightWheel(int spd) {
    int spdsetting = spd;  
    digitalWrite(motorrightSA, 1);
    digitalWrite(motorrightSB, 0);
    analogWrite(motorrightSSpeed, spdsetting);    
  }
  int DriveReverseLeftWheel(int spd) {
    int spdsetting = spd;
    analogWrite(motorleftSSpeed, spdsetting);
    digitalWrite(motorleftSA, 0);
    digitalWrite(motorleftSB, 1);
  }
  int DriveReverseRightWheel(int spd) {
    int spdsetting = spd;
    digitalWrite(motorrightSA, 0);
    digitalWrite(motorrightSB, 1);
    analogWrite(motorrightSSpeed, spdsetting);    
  }

  int carLight(int FL, int FR, int BL, int BR){
    /*if(FL == true && FR == true && FL == true && FR == true){// all light up
      digitalWrite(frontLeft, 1);
      digitalWrite(frontRight, 1);
      digitalWrite(backLeft, 1);
      digitalWrite(backRight, 1);
    }else*/ 
    if(FL == true && FR == true && BL == false && BR == false){ // front light up
      digitalWrite(frontLeft, 1);
      digitalWrite(frontRight, 1);
      digitalWrite(backLeft, 0);
      digitalWrite(backRight, 0);
    }else if(FL == true && FR == false && BL == false && BR == false){ // left front light up
      digitalWrite(frontLeft, 1);
      digitalWrite(frontRight, 0);
      digitalWrite(backLeft, 0);
      digitalWrite(backRight, 0);
    }else if(FL == false && FR == true && BL == false && BR == false){ // right front ligth up
      digitalWrite(frontLeft, 0);
      digitalWrite(frontRight, 1);
      digitalWrite(backLeft, 0);
      digitalWrite(backRight, 0);
    }else if(FL == false && FR == false && BL == true && BR == false){ // back left light up 
      digitalWrite(frontLeft, 0);
      digitalWrite(frontRight, 0);
      digitalWrite(backLeft, 1);
      digitalWrite(backRight, 0);
    }else if(FL == false && FR == false && BL == false && BR == true){ // back right light up
      digitalWrite(frontLeft, 0);
      digitalWrite(frontRight, 0);
      digitalWrite(backLeft, 0);
      digitalWrite(backRight, 1);
    }else if(FL == false && FR == false && BL == true && BR == true){ // back light up
      digitalWrite(frontLeft, 0);
      digitalWrite(frontRight, 0);
      digitalWrite(backLeft, 1);
      digitalWrite(backRight, 1);
    }else if(FL == true && FR == false && BL == true && BR == false){ // light left side up
      digitalWrite(frontLeft, 1);
      digitalWrite(frontRight, 0);
      digitalWrite(backLeft, 1);
      digitalWrite(backRight, 0);
    }else if(FL == false && FR == true && BL == false && BR == true){ // light right side up
      digitalWrite(frontLeft, 0);
      digitalWrite(frontRight, 1);
      digitalWrite(backLeft, 0);
      digitalWrite(backRight, 1);
    }else if(FL == false && FR == true && BL == false && BR == true){ // light right side up
      digitalWrite(frontLeft, 0);
      digitalWrite(frontRight, 1);
      digitalWrite(backLeft, 0);
      digitalWrite(backRight, 1);
    }else if(FL == false && FR == false && BL == false && BR == false){ // lights out
      digitalWrite(frontLeft, 0);
      digitalWrite(frontRight, 0);
      digitalWrite(backLeft, 0);
      digitalWrite(backRight, 0);
    }
  }

