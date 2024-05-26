/*
 *  setup.cpp
 */

#include "debug_fns.h"
#include "SerSrvMnu_fns.h"
#define RXD2 16
#define TXD2 17

/*
 *  setup()
 */
void setup()
    {
    pinMode(LED_BUILTIN, OUTPUT);   // Initialise LED pin

     Serial.begin(115200);   // Initialise serial monitor/console port
    
    delay(5000);            // wait for Serial to come up so we don't miss initial messages
    enableDebugging(Serial);// enable my debugging print functions

    Serial.println("Pulsar MAVLink Tester");

    // Serial2.begin(57600);
    Serial2.begin(57600, SERIAL_8N1, RXD2, TXD2);   // Initialise Serial2 port at 57600bps
                            // Arduino 2nd serial port (a.k.a Serial2) is wired to AutoPilot GPS2 port (see README.md for additional details)

    menuExit(); // display a message telling user how to open the menus.
    }
