### Custom remote switch for Xantrex Inverters

Xantrex sells a remote switch that connects over an RJ11 outlet to the inverter. It allows you to turn the inverter on and off if it's in an inconvenient location. Instead of pay $50 for that and be forced to physically push a button, I figured why not build my own that could be controlled via the internet. This is a basic Arduino sketch illustrating the possiblility. A TIP120 NPN transistor is connected to pin 3. RJ11 pins 3 and 5 are connected to the collector/emitter of the transistor. 3 is +ve and 5 is -ve, and it's best to put a diode on 3 so you don't burn up an Arduino (I may have done this). Pins 2 and 4 of the RJ11 cable can go to an LED to show the status or you can bring it into an analog input of the arduino to determine if the inverter is on or off.

Next steps are getting it on a Raspberry Pi, which should't be difficult becuase the circuit is really the hard part.
