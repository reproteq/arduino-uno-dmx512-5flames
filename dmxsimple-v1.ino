#include <DmxSimple.h>
// https://github.com/PaulStoffregen/DmxSimple

const int buttonPin1 = 5;       // Pin input one (Pins 2,3,4 are used to transmit DMX signals)
const int buttonPin2 = 6;       // Pin input two
const int buttonPin3 = 7;     // Pin input three
const int ledPin = 13;     // Pin input three

int buttonState1 = 0; 
int buttonState2 = 0; 
int buttonState3 = 0;    

void setup() {

int buttonState1 = 0; 
int buttonState2 = 0; 
int buttonState3 = 0;    
  
pinMode(2, OUTPUT);
digitalWrite(2, HIGH);
DmxSimple.usePin(4);
DmxSimple.maxChannel(8); //my number of channels

}



void loop() 

{
 buttonState1 = digitalRead(buttonPin1);
 buttonState2 = digitalRead(buttonPin2);
 buttonState3 = digitalRead(buttonPin3);
 
  

    if (buttonState1 == LOW)  
      { 
      digitalWrite(ledPin, HIGH); 
      
       DmxSimple.write(6,255);  //canal 6 , valor entre 201-255  encender piloto
      
      digitalWrite(ledPin, LOW);
      }

    if (buttonState2 == LOW)  
      { 
      digitalWrite(ledPin, HIGH); 

// secuencia abrir-cerrar uno a uno 
       DmxSimple.write( 1, 255 );
       delay(200);
       DmxSimple.write( 1, 0 );

       DmxSimple.write( 2, 255 ); 
       delay(200);
       DmxSimple.write( 2, 0 );  

       DmxSimple.write( 3, 255 );  
       delay(200);
       DmxSimple.write( 3, 0 ); 

       DmxSimple.write( 4, 255 ); 
       delay(200);  
       DmxSimple.write( 4, 0 );  

       DmxSimple.write( 5, 255 );  
       delay(200);
       DmxSimple.write( 5, 0 );  

      //fin secuencia abrir cerrar uno a uno

              
      // abrir todos los inyectores 
       DmxSimple.write( 1, 255 );
       DmxSimple.write( 2, 255 );  
       DmxSimple.write( 3, 255 );  
       DmxSimple.write( 4, 255 );  
       DmxSimple.write( 5, 255 );  
  
       delay(600);
      
      // cerrar todos los inyectores
       DmxSimple.write( 1, 0 );  
       DmxSimple.write( 2, 0 );  
       DmxSimple.write( 3, 0 );  
       DmxSimple.write( 4, 0 );  
       DmxSimple.write( 5, 0 );  
      
       digitalWrite(ledPin, LOW);
     
 
      }

    if (buttonState3 == LOW)  
      { 
      digitalWrite(ledPin, HIGH); 
      
       DmxSimple.write(6,0);  //canal 6 , valor entre 0 apaga piloto
      
       digitalWrite(ledPin, LOW);
      }
}
