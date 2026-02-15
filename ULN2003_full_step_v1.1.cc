//Defines pin holes
int aPin = 8;
int cPin = 10;
int bPin = 9;
int dPin = 11;

int clockBtn = 2;
int counterBtn = 3;

//------------------------------------

//Time delay between each step, the smaller the delay, the faster the motor
int timeDelay = 1000; //Time recorded in microseconds, 1000 Microseconds = 1 Millisecond

//Local variable to track rotation
int localLoop = 0; //Defines it as 0

//Universal number to allow a certain number of rotations
//Calculated with math I don't know at the current moment :P
//Long is used for the big BIG numbers
long universalLoop = 15000; //How many times it will rotate.

//------------------------------------

//Defines the initial state of the motor and the direction
bool isClockstate = false;

bool isCounterstate = false;

//------------------------------------
//Constants, controlling the stepped acceleration and time duration of the speed.
int slowStart = 2000;
int slowDelay = 1800;

int medStart = 5000;
int medDelay = 1300;

int maxDelay = 1000;
//------------------------------------

//Defines the inputs and outputs (motor and buttons)
void setup() {
  pinMode(aPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(cPin, OUTPUT);
  pinMode(dPin, OUTPUT);
  pinMode(clockBtn, INPUT_PULLUP);
  pinMode(counterBtn, INPUT_PULLUP);
}

void loop() {
  //If the motor reaches limit, it will stop. 
  if (localLoop >= universalLoop) {
    shutOff();
    isClockstate = false;
    isCounterstate = false;
    localLoop = 0;
  }
  //If pressed for clockwise, it will spin clockwise (Or at least in the opposite direction)
  if (digitalRead(clockBtn) == LOW) {
    localLoop = 0;
    isClockstate = true;
    isCounterstate = false;
    delay(150);
    }
  //If pressed for counterclockwise, it will spin counterclockwise (Or at least in the opposite direction as clockwise)
  else if (digitalRead(counterBtn) == LOW) {
    localLoop = 0;
    isClockstate = false;
    isCounterstate = true;
    delay(150);
    }

  //Stepped Acceleration logic
  //Initially slow to overcome the initial struggle of weight
  if (localLoop < slowStart) {
    timeDelay = slowDelay;
  }

  //Increase the speed and delay
  else if (localLoop < medStart) {
    timeDelay = medDelay;
  }

  //Max speed and min delay
  else {
    timeDelay = maxDelay;
  }


  //Runs clockwise
  if(isClockstate == true) {
      clockLoop ();
      localLoop++;
  }

  //Runs counterclockwise
  else if(isCounterstate == true) {
      counterLoop ();
      localLoop++;
  }

  else {
    shutOff();
  }
}

void shutOff () {
  digitalWrite(aPin, LOW);
  digitalWrite(bPin, LOW);
  digitalWrite(cPin, LOW);
  digitalWrite(dPin, LOW);
}


//Logic for clockwise loop
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


//Same logic for clockwise loop, but in reverse order.
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

//Feburary 14th, 2026
//ULN2003 stepper motor
