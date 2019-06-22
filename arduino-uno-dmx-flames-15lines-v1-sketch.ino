
//Arduino Uno Dmx512 Flame Controller for FireOne 32Cue With Arduino Shield DMX
//Author TT 2019 for PirotecniaTomás

#include <Bounce2.h>              // Bounce Buttons
#include <Conceptinetics.h>       // Pack to talk to my DMX Sheild

#define DMX_MASTER_CHANNELS   6   // The Number Of Channels going int my DMX Light
#define RXEN_PIN              2   // The Return Pin on Arduino

//Pins 2,3,4 are used to transmit DMX signals
//switch config arduino shield dmx EN DE TX-I0 RX-I0

const int button1Pin = 5;       // Pin input 1
const int button2Pin = 6;       // Pin input 2
const int button3Pin = 7;     // Pin input 3
const int button4Pin = 8;     // Pin input 4
const int button5Pin = 9;     // Pin input 5
const int button6Pin = 10;     // Pin input 6
const int button7Pin = 11;     // Pin input 7
const int button8Pin = 12;     // Pin input 8
const int button9Pin = 13;     // Pin input 9
const int button10Pin = A0;        
const int button11Pin = A1;       
const int button12Pin = A2;                            
const int button13Pin = A3;       
const int button14Pin = A4;        
const int button15Pin = A5;        

int buttonState = 0;              // variable for reading the pushbutton status

// Configure a DMX master controller, the master controller
// will use the RXEN_PIN to control its write operation 
// on the bus
DMX_Master        dmx_master ( DMX_MASTER_CHANNELS, RXEN_PIN );

// Instantiate a Bounce object
Bounce debouncer1 = Bounce(); 
Bounce debouncer2 = Bounce(); 
Bounce debouncer3 = Bounce(); 
Bounce debouncer4 = Bounce(); 
Bounce debouncer5 = Bounce(); 
Bounce debouncer6 = Bounce(); 
Bounce debouncer7 = Bounce(); 
Bounce debouncer8 = Bounce(); 
Bounce debouncer9 = Bounce(); 
Bounce debouncer10 = Bounce(); 
Bounce debouncer11 = Bounce(); 
Bounce debouncer12 = Bounce(); 
Bounce debouncer13 = Bounce(); 
Bounce debouncer14 = Bounce(); 
Bounce debouncer15 = Bounce(); 

void setup() 

{             
    
  pinMode(button1Pin, INPUT_PULLUP); 
  debouncer1.attach(button1Pin);
  debouncer1.interval(5); // interval in ms
  
  pinMode(button2Pin, INPUT_PULLUP);
  debouncer2.attach(button2Pin);
  debouncer2.interval(5); // interval in ms

  pinMode(button3Pin, INPUT_PULLUP);
  debouncer3.attach(button3Pin);
  debouncer3.interval(5); // interval in ms

  pinMode(button4Pin, INPUT_PULLUP);
  debouncer4.attach(button4Pin);
  debouncer4.interval(5); // interval in ms

  pinMode(button5Pin, INPUT_PULLUP);
  debouncer5.attach(button5Pin);
  debouncer5.interval(5); // interval in ms

  pinMode(button6Pin, INPUT_PULLUP); 
  debouncer6.attach(button6Pin);
  debouncer6.interval(5); // interval in ms
  
  pinMode(button7Pin, INPUT_PULLUP);
  debouncer7.attach(button7Pin);
  debouncer7.interval(5); // interval in ms

  pinMode(button3Pin, INPUT_PULLUP);
  debouncer8.attach(button8Pin);
  debouncer8.interval(5); // interval in ms

  pinMode(button9Pin, INPUT_PULLUP);
  debouncer9.attach(button9Pin);
  debouncer9.interval(5); // interval in ms

  pinMode(button10Pin, INPUT_PULLUP); // set pull-up on analog pin 0 
  debouncer10.attach(button10Pin);
  debouncer10.interval(5); // interval in ms
  
  pinMode(button11Pin, INPUT_PULLUP);  // set pull-up on analog pin 0 
  debouncer11.attach(button11Pin);
  debouncer11.interval(5); // interval in ms


  pinMode(button12Pin, INPUT_PULLUP);  // set pull-up on analog pin 0 
  debouncer12.attach(button12Pin);
  debouncer12.interval(5); // interval in ms


  pinMode(button13Pin, INPUT_PULLUP);  // set pull-up on analog pin 0 
  debouncer13.attach(button13Pin);
  debouncer13.interval(5); // interval in ms

  
  pinMode(button14Pin, INPUT_PULLUP);  // set pull-up on analog pin 0 
  debouncer14.attach(button14Pin);
  debouncer14.interval(5); // interval in ms


  pinMode(button15Pin, INPUT_PULLUP);  // set pull-up on analog pin 0 
  debouncer15.attach(button15Pin);
  debouncer15.interval(5); // interval in ms

  // Enable DMX master interface and start transmitting
  dmx_master.enable ();
  
  // Set channel 1 - 512 @ 100%
  dmx_master.setChannelRange ( 1, 512, 255 );  
  
 // dmx_master.setChannelRange ( 2, 25, 127 );

}

void loop() 

{
  debouncer1.update();
  debouncer2.update();
  debouncer3.update();
  debouncer4.update();
  debouncer5.update();
  debouncer6.update();
  debouncer7.update();
  debouncer8.update();
  debouncer9.update();
  debouncer10.update();
  debouncer11.update();
  debouncer12.update();
  debouncer13.update();
  debouncer14.update();
  debouncer15.update();
 
  int uno = debouncer1.fell();
  int dos = debouncer2.fell();
  int tres = debouncer3.fell();
  int cuatro = debouncer4.fell();
  int cinco = debouncer5.fell();
  int seis = debouncer6.fell();
  int siete = debouncer7.fell();
  int ocho = debouncer8.fell();
  int nueve = debouncer9.fell();
  int diez = debouncer10.fell();
  int once = debouncer11.fell();
  int doce = debouncer12.fell();
  int trece = debouncer13.fell();
  int catorce = debouncer14.fell();
  int quince = debouncer15.fell();
 
  
//canales 1-6 =>>> canal 1- flama 1 , canal 2 flama 2 , canal 3 flama 3, canal 4 flama 4 , canal 5 flama 5, canal 6 flama piloto
// piloto encendido i disparos valor <200

// Button 1   encender piloto
{
    if (uno == LOW)  
      { 
      dmx_master.setChannelValue ( 6, 255 );  //canal 6 , valor entre 201-255  encender piloto     
      dmx_master.setChannelValue ( 1, 255 );
      delay (200 );
      dmx_master.setChannelValue ( 1, 0 );     
      dmx_master.setChannelValue ( 6, 0 );  //canal 6 , valor entre 0<200  apagar piloto
      }
}
// Button 2 secuencia 1
  {    
    if (dos == LOW)  
      {
      dmx_master.setChannelValue ( 6, 255 );  //canal 6 , valor entre 201-255  encender piloto    
      dmx_master.setChannelValue ( 2, 255 );
      delay (200 );
      dmx_master.setChannelValue ( 2, 0 );    
      dmx_master.setChannelValue ( 6, 0 );  //canal 6 , valor entre 0<200  apagar piloto       
      } 

       
  }
// Button 3  apagar piloto
  {
    
    if (tres == LOW)  
      {
      dmx_master.setChannelValue ( 6, 255 );  //canal 6 , valor entre 201-255  encender piloto    
      dmx_master.setChannelValue ( 3, 255 );
      delay (200 );
      dmx_master.setChannelValue ( 3, 0 );    
      dmx_master.setChannelValue ( 6, 0 );  //canal 6 , valor entre 0<200  apagar piloto    
      }   
  }

// Button 4  
{
    if (cuatro == LOW)  
      { 
      dmx_master.setChannelValue ( 6, 255 );  //canal 6 , valor entre 201-255  encender piloto    
      dmx_master.setChannelValue ( 4, 255 );
      delay (200 );
      dmx_master.setChannelValue ( 4, 0 );    
      dmx_master.setChannelValue ( 6, 0 );  //canal 6 , valor entre 0<200  apagar piloto
      }
}

// Button 5  
{
    if (cinco == LOW)  
      { 
      dmx_master.setChannelValue ( 6, 255 );  //canal 6 , valor entre 201-255  encender piloto    
      dmx_master.setChannelValue ( 5, 255 );
      delay (200 );
      dmx_master.setChannelValue ( 5, 0 );    
      dmx_master.setChannelValue ( 6, 0 );  //canal 6 , valor entre 0<200  apagar piloto
      }
}

// Button 6  
{
    if (seis == LOW)  
      { 
      dmx_master.setChannelValue ( 6, 255 );  //canal 6 , valor entre 201-255  encender piloto     
      dmx_master.setChannelValue ( 1, 255 );
      delay (600 );
      dmx_master.setChannelValue ( 1, 0 );     
      dmx_master.setChannelValue ( 6, 0 );  //canal 6 , valor entre 0<200  apagar piloto
      }
}

// Button 7  
{
    if (siete == LOW)  
      { 
      dmx_master.setChannelValue ( 6, 255 );  //canal 6 , valor entre 201-255  encender piloto     
      dmx_master.setChannelValue ( 2, 255 );
      delay (600 );
      dmx_master.setChannelValue ( 2, 0 );     
      dmx_master.setChannelValue ( 6, 0 );  //canal 6 , valor entre 0<200  apagar piloto
      }
}

// Button 8  
{
    if (ocho == LOW)  
      { 
      dmx_master.setChannelValue ( 6, 255 );  //canal 6 , valor entre 201-255  encender piloto     
      dmx_master.setChannelValue ( 3, 255 );
      delay (600 );
      dmx_master.setChannelValue ( 3, 0 );     
      dmx_master.setChannelValue ( 6, 0 );  //canal 6 , valor entre 0<200  apagar piloto
      }
}

// Button 9  
{
    if (nueve == LOW)  
      { 
      dmx_master.setChannelValue ( 6, 255 );  //canal 6 , valor entre 201-255  encender piloto     
      dmx_master.setChannelValue ( 4, 255 );
      delay (600 );
      dmx_master.setChannelValue ( 4, 0 );     
      dmx_master.setChannelValue ( 6, 0 );  //canal 6 , valor entre 0<200  apagar piloto
      }
}

// Button 10 
{
    if (diez == LOW)  
      { 
      dmx_master.setChannelValue ( 6, 255 );  //canal 6 , valor entre 201-255  encender piloto     
      dmx_master.setChannelValue ( 5, 255 );
      delay (600 );
      dmx_master.setChannelValue ( 5, 0 );     
      dmx_master.setChannelValue ( 6, 0 );  //canal 6 , valor entre 0<200  apagar piloto
      }
}

// Button 11  
{
    if (once == LOW)  
      { 
      dmx_master.setChannelValue ( 6, 255 );  //canal 6 , valor entre 201-255  encender piloto
      // secuencia abrir-cerrar 1 a 5 durante 600ms
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
     dmx_master.setChannelValue ( 6, 0 );  //canal 6 , valor entre 0<200  apagar piloto

      
      }
}

// Button 12  
{
    if (doce == LOW)  
      { 
      dmx_master.setChannelValue ( 6, 255 );  //canal 6 , valor entre 201-255  encender piloto
      // secuencia abrir-cerrar 1 a 5 durante 600ms
      dmx_master.setChannelValue ( 5, 255 );
      delay (600 );
      dmx_master.setChannelValue ( 5, 0 );

      dmx_master.setChannelValue ( 4, 255 ); 
      delay (600 );
      dmx_master.setChannelValue ( 4, 0 );  

      dmx_master.setChannelValue ( 3, 255 );  
      delay (600 );
      dmx_master.setChannelValue ( 3, 0 ); 

      dmx_master.setChannelValue ( 2, 255 ); 
      delay (600 );  
      dmx_master.setChannelValue ( 2, 0 );  

      dmx_master.setChannelValue ( 1, 255 );  
      delay (600 );
      dmx_master.setChannelValue ( 1, 0 );  

      //fin secuencia abrir cerrar uno a uno
     dmx_master.setChannelValue ( 6, 0 );  //canal 6 , valor entre 0<200  apagar piloto

      
      }
}

// Button 13  
{
    if (trece == LOW)  
      { 
      dmx_master.setChannelValue ( 6, 255 );  //canal 6 , valor entre 201-255  encender piloto
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
      dmx_master.setChannelValue ( 6, 0 );  //canal 6 , valor entre 0<200  apagar piloto
            
      }
}

// Button 14  
{
    if (catorce == LOW)  
      {      
      dmx_master.setChannelValue ( 6, 255 );  //canal 6 , valor entre 201-255  encender piloto
      // abrir todos los inyectores 
      dmx_master.setChannelValue ( 1, 255 );
      dmx_master.setChannelValue ( 2, 255 );  
      dmx_master.setChannelValue ( 3, 255 );  
      dmx_master.setChannelValue ( 4, 255 );  
      dmx_master.setChannelValue ( 5, 255 );       
      }
}

// Button 15  
{
    if (quince == LOW)  
      { 
      // cerrar todos los inyectores
      dmx_master.setChannelValue ( 1, 0 );  
      dmx_master.setChannelValue ( 2, 0 );  
      dmx_master.setChannelValue ( 3, 0 );  
      dmx_master.setChannelValue ( 4, 0 );  
      dmx_master.setChannelValue ( 5, 0 );   
      dmx_master.setChannelValue ( 6, 0 );  //canal 6 , valor entre 0<200  apagar piloto
      }
}


}
