#include <Bounce2.h>              // Bounce Buttons
#include <Conceptinetics.h>       // Pack to talk to my DMX Sheild

#define DMX_MASTER_CHANNELS   6   // The Number Of Channels going int my DMX Light
#define RXEN_PIN              2   // The Return Pin on Arduino

const int buttononePin = 5;       // Pin input one (Pins 2,3,4 are used to transmit DMX signals)
const int buttontwoPin = 6;       // Pin input two
const int buttonthreePin = 7;     // Pin input three
int buttonState = 0;              // variable for reading the pushbutton status

// Configure a DMX master controller, the master controller
// will use the RXEN_PIN to control its write operation 
// on the bus
DMX_Master        dmx_master ( DMX_MASTER_CHANNELS, RXEN_PIN );

// Instantiate a Bounce object
Bounce debouncer1 = Bounce(); 
Bounce debouncer2 = Bounce(); 
Bounce debouncer3 = Bounce(); 

void setup() 

{             
    
  pinMode(buttononePin, INPUT_PULLUP); 
  debouncer1.attach(buttononePin);
  debouncer1.interval(5); // interval in ms
  
  pinMode(buttontwoPin, INPUT_PULLUP);
  debouncer2.attach(buttontwoPin);
  debouncer2.interval(5); // interval in ms

  pinMode(buttonthreePin, INPUT_PULLUP);
  debouncer3.attach(buttonthreePin);
  debouncer3.interval(5); // interval in ms
  
  // Enable DMX master interface and start transmitting
  dmx_master.enable ();  
  dmx_master.setChannelRange ( 2, 25, 127 );

}

void loop() 

{
  debouncer1.update();
  debouncer2.update();
  debouncer3.update();
 
  int one = debouncer1.fell();
  int two = debouncer2.fell();
  int three = debouncer3.fell();
  
//canales 1-6 =>>> canal 1- flama 1 , canal 2 flama 2 , canal 3 flama 3, canal 4 flama 4 , canal 5 flama 5, canal 6 flama piloto
// piloto encendido i disparos valor <200
// Button 1   encender
{
    if (one == LOW)  
      { 
      dmx_master.setChannelValue ( 6, 255 );  //canal 6 , valor entre 201-255  encendido 
      }
}
// Button 2 secuencia 1
  {    
    if (two == LOW)  
      {
      dmx_master.setChannelValue ( 2, 255 );  
      dmx_master.setChannelValue ( 3, 255 );  
      dmx_master.setChannelValue ( 4, 255 );  
      dmx_master.setChannelValue ( 5, 255 );  
      dmx_master.setChannelValue ( 6, 255 ); 
      delay (3000 );
      dmx_master.setChannelValue ( 2, 0 );  
      dmx_master.setChannelValue ( 3, 0 );  
      dmx_master.setChannelValue ( 4, 0 );  
      dmx_master.setChannelValue ( 5, 0 );  
      dmx_master.setChannelValue ( 6, 0 );  
      } 

       
  }
// Button 3  apagar
  {
    
    if (three == LOW)  
      {
      dmx_master.setChannelValue ( 1, 0 );  // apagar valor no superior a 200
      }   
  }


}
