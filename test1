#include <Conceptinetics.h>       // Pack to talk to my DMX Sheild
#define DMX_MASTER_CHANNELS   6   // The Number Of Channels going int my DMX Light
#define RXEN_PIN              2   // The Return Pin on Arduino

const int buttonPin1 = 5;       // Pin input one (Pins 2,3,4 are used to transmit DMX signals)
const int buttonPin2 = 6;       // Pin input two
const int buttonPin3 = 7;     // Pin input three

const int ledPin = 13;     // Pin input three

int buttonState1 = 0; 
int buttonState2 = 0; 
int buttonState3 = 0;              
DMX_Master        dmx_master ( DMX_MASTER_CHANNELS, RXEN_PIN );


void setup() 

{             
 pinMode(ledPin, OUTPUT);    
 pinMode(buttonPin1, INPUT);
 pinMode(buttonPin2, INPUT);
 pinMode(buttonPin3, INPUT);
  
 dmx_master.enable ();
 dmx_master.setChannelRange ( 1, 512, 255 );  


}

void loop() 

{
 buttonState1 = digitalRead(buttonPin1);
 buttonState2 = digitalRead(buttonPin2);
 buttonState3 = digitalRead(buttonPin3);
 
  
// Button 1   encender piloto
{
    if (buttonState1 == LOW)  
      { 
      digitalWrite(ledPin, HIGH); 
      dmx_master.setChannelValue ( 6, 255 );  //canal 6 , valor entre 201-255  encender piloto
      digitalWrite(ledPin, LOW);
      }
}
// Button 2 secuencia 1
  {    
    if (buttonState2 == LOW)  
      {
      digitalWrite(ledPin, HIGH); 


      // secuencia abrir-cerrar uno a uno 
      dmx_master.setChannelValue ( 1, 255 );
      delay (600 );
      dmx_master.setChannelValue ( 1, 0 );

      dmx_master.setChannelValue ( 2, 255 ); 
      delay (600 );
      dmx_master.setChannelValue ( 2, 0 );  

      dmx_master.setChannelValue ( 3, 255 );  
      delay (600 );
      dmx_master.setChannelValue ( 3, 0 ); 

      dmx_master.setChannelValue ( 4, 255 ); 
      delay (600 );  
      dmx_master.setChannelValue ( 4, 0 );  

      dmx_master.setChannelValue ( 5, 255 );  
      delay (600 );
      dmx_master.setChannelValue ( 5, 0 );  

      //fin secuencia abrir cerrar uno a uno

              
      // abrir todos los inyectores 
      dmx_master.setChannelValue ( 1, 255 );
      dmx_master.setChannelValue ( 2, 255 );  
      dmx_master.setChannelValue ( 3, 255 );  
      dmx_master.setChannelValue ( 4, 255 );  
      dmx_master.setChannelValue ( 5, 255 );  
  
      delay (600 );
      
      // cerrar todos los inyectores
      dmx_master.setChannelValue ( 1, 0 );  
      dmx_master.setChannelValue ( 2, 0 );  
      dmx_master.setChannelValue ( 3, 0 );  
      dmx_master.setChannelValue ( 4, 0 );  
      dmx_master.setChannelValue ( 5, 0 );  
      
       digitalWrite(ledPin, LOW);
         
      } 

       
  }
// Button 3  apagar piloto
  {
    
    if (buttonState3 == LOW)  
      {
      digitalWrite(ledPin, HIGH);
      dmx_master.setChannelValue ( 6, 0 );  //canal 6 , valor entre 0-199  apagar piloto
      digitalWrite(ledPin, LOW);
      }   
  }


}
