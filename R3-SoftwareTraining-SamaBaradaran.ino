// Motor A connections, assigning them as integer variables
int inputA = 8; //We're saying that this input is connected to pin 8
int in1A = 7;
int in2A = 6;
// Motor B connections like in Motor A
int inputB = 3;
int in1B = 5;
int in2B = 4;
//int dipswich = ???//

// Void is used to declare that there will be no info returned
// Setup() is used to step up the variables that we need to make it start
void setup() 
{
	// Set all the motor control pins to outputs for now
	pinMode(inputA, OUTPUT);
	pinMode(inputB, OUTPUT);
	pinMode(in1A, OUTPUT);
	pinMode(in2A, OUTPUT);
	pinMode(in1B, OUTPUT);
	pinMode(in2B, OUTPUT);
  	//pinMode(dipswitch, INPUT_PULLUP);
	
	// DitigalWrite = 
  	// Setting to LOW with digitalwrite makes the voltage 0 = off or no power
	digitalWrite(in1A, LOW);
	digitalWrite(in2A, LOW);
	digitalWrite(in1B, LOW);
	digitalWrite(in2B, LOW);
}

void directionControl() 
{
	//0 to 255, 255 max
	analogWrite(inputA, 255);
	analogWrite(inputB, 255);

	// Turn on motors
	digitalWrite(in1A, HIGH);
	digitalWrite(in2A, LOW);
	digitalWrite(in1B, HIGH);
	digitalWrite(in2B, LOW);
	delay(5000); //Delay of 5000 millisec just to see if its all working right
	
	// Now change motor directions, opposite of what is above
	digitalWrite(in1A, LOW);
	digitalWrite(in2A, HIGH);
	digitalWrite(in1B, LOW);
	digitalWrite(in2B, HIGH);
	delay(5000);
	
	// Turn off motors
	digitalWrite(in1A, LOW);
	digitalWrite(in2A, LOW);
	digitalWrite(in1B, LOW);
	digitalWrite(in2B, LOW);
}

void loop()
{
  int potenValue = analogRead(A0); //This is supposed to adjust potent meter values
//the Potentiometer was supposed to adjust the speed, I just couldnt figure it out in time
  if(potenValue == HIGH) //If value read was high, then spin fast
  {
    digitalWrite(in1A, LOW);
	digitalWrite(in2A, HIGH);
	digitalWrite(in1B, LOW);
	digitalWrite(in2B, HIGH);
  }
  else //If not high, then spin slow
  {
    digitalWrite(in1A, HIGH);
	digitalWrite(in2A, LOW);
	digitalWrite(in1B, HIGH);
	digitalWrite(in2B, LOW);
  }
  	// Turn off motors once done
	digitalWrite(in1A, LOW);
	digitalWrite(in2A, LOW);
	digitalWrite(in1B, LOW);
	digitalWrite(in2B, LOW);
}