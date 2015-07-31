# MSP430-Telegraph-Project-

This project is based on a microcontroller TI MSP430

An input that generates high/low signals is required (could be a telegraph key, a button)

The code already does consider the button as an iuput, so you can try it out with out additional circuit set up

Once the we press the button, meaning input is 0, a square wave output will be produced.

The code already sets the RED LED as an output, so a pressing will light up the LED (it blinks so fast that you cannot see it's 
    actually a periodic wave).

Port P2.0 is also set as an output, so you can connect a circuit to it. 
  e.g. connect a microphone to it , the square wave output will produce a sound.
  
