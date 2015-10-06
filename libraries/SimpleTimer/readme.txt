SimpleTimer Library for Arduino
Author:  Marcello Romani
Contact: mromani@ottotecnica.com
License: GNU LGPL 2.1+


Description

This is (yet another) simple library to launch timed actions.

It's based on millis(), thus it has 1 ms resolution.

It uses polling, so no guarantee can be made about the exact time when a callback is fired. For example, if you setup the library so that it calls a function every 2ms, but this function requires 5ms to complete, then you'll have an invocation every 5ms.

For applications where non-strict timing is enough, not using interrupts avoids potential problems with global variables shared between the interrupt service routine and the main program, and doesn't consune a hardware timer. 


Installation

1. Create a folder named SimpleTimer in you sketchbook/libraries folder.
2. Copy-n-paste the code for SimpleTimer.h and SimpleTimer.cpp into your favourite text editor, and save those two files under the SimpleTimer folder you just created.
3. Launch or restart the Arduino IDE to let it detect the new library.
4. Copy-n-paste the example code (see below) to get you started with the library. 


Usage

#include <SimpleTimer.h>

// the timer object
SimpleTimer timer;

// a function to be executed periodically
void repeatMe() {
    Serial.print("Uptime (s): ");
    Serial.println(millis() / 1000);
}

void setup() {
    Serial.begin(9600);
    timer.setInterval(1000, repeatMe);
}

void loop() {
    timer.run();
}


Theory

The base goal is to be able to execute a particular piece of code every n milliseconds, without using interrupts.

The algorithm looks like this:

lastMillis = 0
forever do:
    if (millis() - lastMillis > n)
        call the particular piece of code
        lastMillis = millis()
    end
end


Links

See also http://playground.arduino.cc/Code/SimpleTimer