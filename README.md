# stopwatch
This is stopwatch using internal Arduino clock, displaying time in seconds and milliseconds on LCD screen. 
# Components Used
- Arduino Uno
- 1602 lcd
- Press button
- 10k potentiometer
# How it works
The program uses the millis() function to measure time in milliseconds in the background. This approach does not interfere with the rest of the program or slow down its execution. The stopwatch is controlled by a single button. Pressing the button starts measuring time, and pressing it again stops the measurement. This cycle can be repeated as many time as needed.
![Arduino Stopwatch](stopwatch_image.jpg)
