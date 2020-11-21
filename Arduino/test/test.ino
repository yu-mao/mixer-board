int voltageValue = 0; // Voltage read from buttons
int pinToReadVoltage = A0; // select the input pin to read incoming voltage to Arduino
enum buttonsCanBePressed = {
  button0 = 0,
  button1 = 1,
  button2 = 2,
  button3 = 3
}; // buttons on the bread board
int voltageRanges[5] = {100, 200, 300, 400, 500};
int buttonPressed = 0;

enum track_button(enum buttonsCanBePressed, int voltageRanges, int voltageValue) {
  for (i = 0; i < 4; i ++) {
    if voltageValue >= voltageRanges[i] and voltageValue < voltageRanges[i+1]:
      printf("Yay! Button %d is pressed down!", i)
      return buttonsCanBePressed[i];
  }
  printf("Error: voltage read from the circuit is out of range!");
  return NULL;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(pinToReadVoltage, INPUT);
  voltageValue_last = analogRead(pinToReadVoltage);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the voltage value from the button circuit
  voltageValue_current = analogRead(pinToReadVoltage);
  if voltageValue_current != voltageValue_last:
     buttonPressed = track_button(buttonsCanBePressed, voltageRanges, voltageValue_current);
}
