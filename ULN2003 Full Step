int aPin = 8;
int cPin = 10;
int bPin = 9;
int dPin = 11;

int clockBtn = 2;
int counterBtn = 3;

int timeDelay = 1500; //Time recorded in microseconds, 1000 Microseconds = 1 Millisecond

int localLoop = 0; //Defines it as 0

int universalLoop = 13000; //How many times it will rotate.

bool isClockstate = false;

bool isCounterstate = false;

void setup() {
  pinMode(aPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(cPin, OUTPUT);
  pinMode(dPin, OUTPUT);
  pinMode(clockBtn, INPUT_PULLUP);
  pinMode(counterBtn, INPUT_PULLUP);
}

void loop() {

  if (digitalRead(clockBtn) == LOW) {
    localLoop = 0;
    isClockstate = true;
    isCounterstate = false;
    }
    
  else if (digitalRead(counterBtn) == LOW) {
    localLoop = 0;
    isClockstate = false;
    isCounterstate = true;
    }

  if(isClockstate == true) {
      clockLoop ();
      localLoop++;
  }

  else if(isCounterstate == true) {
      counterLoop ();
      localLoop++;
  }

  if (localLoop >= universalLoop) {
    shutOff();
    isClockstate = false;
    isCounterstate = false;
    localLoop = 0;
  }
}

void shutOff () {
  digitalWrite(aPin, LOW);
  digitalWrite(bPin, LOW);
  digitalWrite(cPin, LOW);
  digitalWrite(dPin, LOW);
}

void clockLoop () {
      
      // AC
      digitalWrite(aPin,HIGH);
      digitalWrite(bPin,LOW);
      digitalWrite(cPin,HIGH);
      digitalWrite(dPin,LOW);
      
      delayMicroseconds(timeDelay);
      
      // CB
      digitalWrite(aPin,LOW);
      digitalWrite(bPin,HIGH);
      digitalWrite(cPin,HIGH);
      digitalWrite(dPin,LOW);
  
      delayMicroseconds(timeDelay);
      
      // BD
      digitalWrite(aPin,LOW);
      digitalWrite(bPin,HIGH);
      digitalWrite(cPin,LOW);
      digitalWrite(dPin,HIGH);
  
      delayMicroseconds(timeDelay);
      
      // DA
      digitalWrite(aPin,HIGH);
      digitalWrite(bPin,LOW);
      digitalWrite(cPin,LOW);
      digitalWrite(dPin,HIGH);
      
      delayMicroseconds(timeDelay);
}

void counterLoop () {

  // DA
      digitalWrite(aPin,HIGH);
      digitalWrite(bPin,LOW);
      digitalWrite(cPin,LOW);
      digitalWrite(dPin,HIGH);
      
      delayMicroseconds(timeDelay);

  // BD
      digitalWrite(aPin,LOW);
      digitalWrite(bPin,HIGH);
      digitalWrite(cPin,LOW);
      digitalWrite(dPin,HIGH);
  
      delayMicroseconds(timeDelay);

  // CB
      digitalWrite(aPin,LOW);
      digitalWrite(bPin,HIGH);
      digitalWrite(cPin,HIGH);
      digitalWrite(dPin,LOW);
  
      delayMicroseconds(timeDelay);

  // AC
      digitalWrite(aPin,HIGH);
      digitalWrite(bPin,LOW);
      digitalWrite(cPin,HIGH);
      digitalWrite(dPin,LOW);
      
      delayMicroseconds(timeDelay);        
}

//Feburary 11th, 2026
//This was created for an engineering project for a ULN2003 motor, utilizing a full step
