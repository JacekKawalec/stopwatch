#include <Arduino.h>
#include <Debounce.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

const uint8_t  PIN_BUTTON = 13;

const uint16_t INTERVAL_BLINK    = 1000;  // Heartbeat blink interval (ms)
const uint16_t INTERVAL_DEBOUNCE = 1;     // Debounce update interval (ms)

unsigned long myTime;
long progress; // takes part with time displaying while measuring
int counter = 0;
long starttime;
long stoptime;
float totaltime;
int refreshingtime = 100; // time between counter refreshes (ms)

uint32_t timeDebounce   = 0;
Debounce myButton(PIN_BUTTON, HIGH);

void setup() {
  
  Serial.begin(9600);

  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("STOPWATCH TIME:"); 
}

void loop() {
  
  myTime = millis();

  if (myTime - timeDebounce >= INTERVAL_DEBOUNCE)
    {
      timeDebounce = myTime;
      myButton.update();
    }

  if (myButton.isPressed())
  {
    counter++;
  }

  if (counter == 1){
    starttime = myTime;
    progress = starttime;
    counter++;
  }

  if(counter == 2){
    if (refreshingtime <= (myTime - progress)){
      progress = myTime;
      totaltime = progress - starttime;
      totaltime = totaltime / 1000;
      lcd.setCursor(0, 1);
      lcd.print("               ");
      lcd.setCursor(0, 1);
      lcd.print(totaltime, 1);
      lcd.print(" s");
    }
  }

  if (counter == 3){
    stoptime = myTime;
    totaltime = stoptime - starttime;

    totaltime = totaltime / 1000;

    lcd.setCursor(0, 1);
    lcd.print("             ");
    lcd.setCursor(0, 1);
    lcd.print(totaltime, 3);
    lcd.print(" s");
    counter = 0;
  }
  
}
