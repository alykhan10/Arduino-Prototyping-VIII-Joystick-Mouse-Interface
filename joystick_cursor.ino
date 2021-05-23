/***********************************************************************************************************
 * 
 * Author:    Aly Khan Nuruddin
 * Date:      May 14, 2021
 * Purpose:   This program permits the user to track the transversal, sagittal, and frontal movements of
 *            a computer cursor using the point coordinates and switch states of an analog joystick module.
 *            
 **********************************************************************************************************/

int inputPin = 9;                                             // Define the Digital InputPin that "senses" the output voltage.
int previousState = 0;                                        // Initialize the previous state of the switch on the analog joystick.

int joystickX = A0;                                           // Define the Analog Pin connection for the x-axis of the analog joystick.
int joystickY = A1;                                           // Define the Analog Pin connection for the y-axis of the analog joystick.

int sensitivity = 10;                                         // Initialize the sensitivity of the analog joystick's movement.

void setup() 
{
  pinMode(inputPin,INPUT);                                    // Configure the Digital Pin to be recognized as an Input.  
  digitalWrite(inputPin,HIGH);                                // Set the ouput voltage value at the Digital Pin to 5 V.
  
  Serial.begin(9600);                                         // Initialize communication with the Serial Monitor at a baud rate of 9600.
}

void loop() {  
  int xPosition = analogRead(joystickX);                      // Read the position of the x-coordinate on the analog joystick.
  int yPosition = analogRead(joystickY);                      // Read the position of the y-coordinate on the analog joystick.
  
  if(xPosition >= 550)                                        // Define the condition when the analog joystick is moved upwards. 
  xPosition = map(xPosition, 550, 1023, 0, sensitivity);      // Map the position of the x-coordinate.
  
  if(xPosition <= 450)                                        // Define the condition when the analog joystick is moved downwards.
  xPosition = map(xPosition, 450, 0, 0, -sensitivity);        // Map the position of the x-coordinate.
  
  if(yPosition >= 550)                                        // Define the condition when the analog joystick is moved towards the right.
  yPosition = map(yPosition, 550, 1023, 0, sensitivity);      // Map the position of the y-coordinate.
  
  if(yPosition <= 450)                                        // Define the condition when the analog joystick is moved towards the left.
  yPosition = map(yPosition, 450, 0, 0, -sensitivity);        // Map the position of the y-coordinate.
  
  int currentState = digitalRead(inputPin);                   // Read the current state of the switch on the analog joystick.
  
  if(currentState == 1 && previousState == 0)                 // Define the condition when the switch on the analog joystick is pressed.
  int switchPosition = 1;                                     // Fix the position of the switch.
  
  else                                                        // Define the condition when the switch on the analog joystick is not pressed.
  int zPosition = 0;                                          // Fix the position of the switch.
  
  if(xPosition !=0 || yPosition!=0 || switchPosition == 1 )   // Define the condition when the analog joystick is moved from its stationary position.
  {
  Serial.print(xPosition);                                    // Print the position of the x-coordinate on the Serial Monitor.
  Serial.print(":");
  Serial.print(yPosition);                                    // Print the position of the y-coordinate on the Serial Monitor.
  Serial.print(":");
  Serial.println(switchPosition);                             // Print the position of the switch on the Serial Monitor.
  }
  
  previousState = currentState;                               // Assign the current state of the switch on the analog joystick to its previous state.
  
  delay(10);                                                  // Delay the execution of the program by 10 milliseconds.
}
