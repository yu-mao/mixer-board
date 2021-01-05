// #include <string.h>

int PIN_TO_READ = A0;  //This selects A0 as the pin to read

int button_pressed[4] = {1, 2, 3 4};  //This creates an array to call for what button is pressed
int voltage_value = 0; //This sets an initial value for the integer which is later 
//used to read the voltage on the pin
  //float voltage_value_previous = 0;
int VOLTAGE_RANGES[5] = {161, 197, 563, 722, 923}; //This are the ranges for each button
//int VOLTAGE_READING_TOLERANCE = 10;

//  sound_player = SoundPlayer(sound_files_path) ;//This is a function to play the sound
                        //on the PC

//}

void setup() {
  Serial.begin(9600)
  pinMode(PIN_READING_VOLTAGE, INPUT)
  Serial.println("...Arduino waking up...")
  voltage_value = 0;  //Does this have to be both in setup and beforehand?
  //sound_files_path[4] = (Path1 Path2 Path3 Path4);
  //sound_player = SoundPlayer(sound_files_path);
}

void loop() {
  int voltage_value = analogRead(PIN_READING_VOLTAGE);

  if voltage_value /= voltage_value_previous
    if voltage_value < VOLTAGE_RANGES[0]
      cout << 'Out of range'
      end
    else if voltage_value > VOLTAGE_RANGES[4]
      cout << 'Out of range'
      end
    else if voltage_value >= VOLTAGE_RANGES[0] && < VOLTAGE_RANGES[1]
      //play_sound(1) //What integer should we call play_sond with?
    cout << 'Button 1'
    end
    else if voltage_value >= VOLTAGE_RANGES[1] && < VOLTAGE_RANGES[2]
      //play_sound(2)
    cout << 'Button 2'
    end
    else if voltage_value >= VOLTAGE_RANGES[2] && < VOLTAGE_RANGES[3]
      //play_sound(3)
    cout << 'Button 3'
    end
    else if voltage_value >= VOLTAGE_RANGES[3] && < VOLTAGE_RANGES[4]
      //play_sound(4)
    cout << 'Button 4'
    end
    voltage_value_previous = voltage_value;

}
