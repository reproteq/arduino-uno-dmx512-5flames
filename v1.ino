//Arduino Uno Dmx512 Flame Controller for FireOne 32Cue With Arduino Shield DMX
//Author TT 2019 for PirotecniaTomás
//Version 1.0
//25-6-2019
#include <Conceptinetics.h>       // Pack to talk to my DMX Sheild
#define DMX_MASTER_CHANNELS   6   // The Number Of Channels going int my DMX Light
#define RXEN_PIN              2   // The Return Pin on Arduino

const int buttonPin1 = 5;       // Pin input 1
const int buttonPin2 = 6;       // Pin input 2
const int buttonPin3 = 7;     // Pin input 3
const int buttonPin4 = 8;     // Pin input 4
const int buttonPin5 = 9;     // Pin input 5
const int buttonPin6 = 10;     // Pin input 6
const int buttonPin7 = 11;     // Pin input 7
const int buttonPin8 = 12;     // Pin input 8
const int buttonPin9 = 13;     // Pin input 9
const int buttonPin10 = A0;        
const int buttonPin11 = A1;       
const int buttonPin12 = A2;                            
const int buttonPin13 = A3;       
const int buttonPin14 = A4;        
const int buttonPin15 = A5;        

int buttonState1 = 0; 
int buttonState2 = 0; 
int buttonState3 = 0;
int buttonState4 = 0; 
int buttonState5 = 0; 
int buttonState6 = 0; 
int buttonState7 = 0; 
int buttonState8 = 0; 
int buttonState9 = 0; 
int buttonState10 = 0; 
int buttonState11 = 0; 
int buttonState12 = 0;
int buttonState13 = 0; 
int buttonState14 = 0; 
int buttonState15= 0;  

              
DMX_Master        dmx_master ( DMX_MASTER_CHANNELS, RXEN_PIN );


void setup() 

{             
  
 pinMode(buttonPin1, INPUT);
 pinMode(buttonPin2, INPUT);
 pinMode(buttonPin3, INPUT);
 pinMode(buttonPin4, INPUT);
 pinMode(buttonPin5, INPUT);
 pinMode(buttonPin6, INPUT);
 pinMode(buttonPin7, INPUT);
 pinMode(buttonPin8, INPUT);
 pinMode(buttonPin9, INPUT);
 pinMode(buttonPin10, INPUT);
 pinMode(buttonPin11, INPUT);
 pinMode(buttonPin12, INPUT);
 pinMode(buttonPin13, INPUT);
 pinMode(buttonPin14, INPUT);
 pinMode(buttonPin15, INPUT);
 
  
 dmx_master.enable ();
 dmx_master.setChannelRange ( 1, 512, 255 );  


}

void loop() 

{
 buttonState1 = digitalRead(buttonPin1);
 buttonState2 = digitalRead(buttonPin2);
 buttonState3 = digitalRead(buttonPin3);
 buttonState4 = digitalRead(buttonPin4);
 buttonState5 = digitalRead(buttonPin5);
 buttonState6 = digitalRead(buttonPin6);
 buttonState7 = digitalRead(buttonPin7);
 buttonState8 = digitalRead(buttonPin8);
 buttonState9 = digitalRead(buttonPin9);
 buttonState10 = digitalRead(buttonPin10);
 buttonState11 = digitalRead(buttonPin11);
 buttonState12 = digitalRead(buttonPin12);
 buttonState13 = digitalRead(buttonPin13);
 buttonState14 = digitalRead(buttonPin14);
 buttonState15 = digitalRead(buttonPin15);
  
  
//canales 1-6 =>>> canal 1- flama 1 , canal 2 flama 2 , canal 3 flama 3, canal 4 flama 4 , canal 5 flama 5, canal 6 flama piloto
// piloto encendido i disparos valor <200

// Button 1   
{
    if (buttonState1 == LOW)  
      { 
      //secuencia  1,2,3,4,5 cada una 200ms
      dmx_master.setChannelValue ( 6, 255 );  //canal 6 , valor entre 201-255  encender piloto  
         
      dmx_master.setChannelValue ( 1, 255 );
      delay (200 );
      dmx_master.setChannelValue ( 1, 0 );     

      dmx_master.setChannelValue ( 2, 255 );
      delay (200 );
      dmx_master.setChannelValue ( 2, 0 ); 
      
      dmx_master.setChannelValue ( 3, 255 );
      delay (200 );
      dmx_master.setChannelValue ( 3, 0 );       
      
      dmx_master.setChannelValue ( 4, 255 );
      delay (200 );
      dmx_master.setChannelValue ( 4, 0 );    

      dmx_master.setChannelValue ( 5, 255 );
      delay (200 );
      dmx_master.setChannelValue ( 5, 0 );  

      dmx_master.setChannelValue ( 6, 0 );  //canal 6 , valor entre 0<200  apagar piloto             
      }
}
// Button 2  
  {    
    if (buttonState2 == LOW)  
      {
      //secuencia  1,2,3,4,5 cada una 600ms
      dmx_master.setChannelValue ( 6, 255 );  //canal 6 , valor entre 201-255  encender piloto  
         
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

      dmx_master.setChannelValue ( 6, 0 );  //canal 6 , valor entre 0<200  apagar piloto        
      } 

       
  }
// Button 3   
  {
    
    if (buttonState3 == LOW)  
      {
      // simultanea  2,4  600ms
      dmx_master.setChannelValue ( 6, 255 );  //canal 6 , valor entre 201-255  encender piloto  
         
      dmx_master.setChannelValue ( 2, 255 );
      dmx_master.setChannelValue ( 4, 255 );
      delay (600 );  
      dmx_master.setChannelValue ( 2, 0 );   
      dmx_master.setChannelValue ( 4, 0 );
      
      dmx_master.setChannelValue ( 6, 0 );  //canal 6 , valor entre 0<200  apagar piloto      
      }   
  }

// Button 4  
{
    if (buttonState4 == LOW)  
      { 
      // simultanea  1,3,5  600ms       
      dmx_master.setChannelValue ( 6, 255 );  //canal 6 , valor entre 201-255  encender piloto  
         
      dmx_master.setChannelValue ( 1, 255 );
      dmx_master.setChannelValue ( 3, 255 );
      dmx_master.setChannelValue ( 5, 255 );
      delay (600 );  
      dmx_master.setChannelValue ( 1, 0 );   
      dmx_master.setChannelValue ( 3, 0 );
      dmx_master.setChannelValue ( 5, 0 );
      
      dmx_master.setChannelValue ( 6, 0 );  //canal 6 , valor entre 0<200  apagar piloto           
      }
}

// Button 5  
{
    if (buttonState5 == LOW)  
      { 
      // simultanea 1,2,3,4,5 600ms  
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

// Button 6  
{
    if (buttonState6 == LOW)  
      { 
      //consecutivas 1,2,3,4,5 200ms
      dmx_master.setChannelValue ( 6, 255 );  //canal 6 , valor entre 201-255  encender piloto
      // abrir cerrar uno a uno 
      dmx_master.setChannelValue ( 1, 255 );
      delay (200 ); 
      dmx_master.setChannelValue ( 1, 0 ); 
      dmx_master.setChannelValue ( 2, 255 );
      delay (200 );        
      dmx_master.setChannelValue ( 2, 0 );  
      dmx_master.setChannelValue ( 3, 255 );  
      delay (200 ); 
      dmx_master.setChannelValue ( 3, 0 );      
      dmx_master.setChannelValue ( 4, 255 );  
      delay (200 );  
      dmx_master.setChannelValue ( 4, 0 );          
      dmx_master.setChannelValue ( 5, 255 );
      delay (200 );    
      dmx_master.setChannelValue ( 5, 0 );   
      
      dmx_master.setChannelValue ( 6, 0 );  //canal 6 , valor entre 0<200  apagar piloto      
      }
}

// Button 7  
{
    if (buttonState7 == LOW)  
      { 
      //consecutivas 5,4,3,2,1 200ms
      dmx_master.setChannelValue ( 6, 255 );  //canal 6 , valor entre 201-255  encender piloto
      // abrir cerrar uno a uno 
      dmx_master.setChannelValue ( 5, 255 );
      delay (200 ); 
      dmx_master.setChannelValue ( 5, 0 ); 
      dmx_master.setChannelValue ( 4, 255 );
      delay (200 );        
      dmx_master.setChannelValue ( 4, 0 );  
      dmx_master.setChannelValue ( 3, 255 );  
      delay (200 ); 
      dmx_master.setChannelValue ( 3, 0 );      
      dmx_master.setChannelValue ( 2, 255 );  
      delay (200 );  
      dmx_master.setChannelValue ( 2, 0 );          
      dmx_master.setChannelValue ( 1, 255 );
      delay (200 );    
      dmx_master.setChannelValue ( 1, 0 );   
      
      dmx_master.setChannelValue ( 6, 0 );  //canal 6 , valor entre 0<200  apagar piloto  
      }
}

// Button 8  
{
    if (buttonState8 == LOW)  
      { 
      //consecutivas 1,2,3,4,5,4,3,2,1 200ms 
      dmx_master.setChannelValue ( 6, 255 );  //canal 6 , valor entre 201-255  encender piloto
      // abrir cerrar uno a uno 
      dmx_master.setChannelValue ( 1, 255 );
      delay (200 ); 
      dmx_master.setChannelValue ( 1, 0 ); 
      dmx_master.setChannelValue ( 2, 255 );
      delay (200 );        
      dmx_master.setChannelValue ( 2, 0 );  
      dmx_master.setChannelValue ( 3, 255 );  
      delay (200 ); 
      dmx_master.setChannelValue ( 3, 0 );      
      dmx_master.setChannelValue ( 4, 255 );  
      delay (200 );  
      dmx_master.setChannelValue ( 4, 0 );          
      dmx_master.setChannelValue ( 5, 255 );
      delay (200 );    
      dmx_master.setChannelValue ( 5, 0 );   
      dmx_master.setChannelValue ( 4, 255 );
      delay (200 );        
      dmx_master.setChannelValue ( 4, 0 );  
      dmx_master.setChannelValue ( 3, 255 );  
      delay (200 ); 
      dmx_master.setChannelValue ( 3, 0 );      
      dmx_master.setChannelValue ( 2, 255 );  
      delay (200 );  
      dmx_master.setChannelValue ( 2, 0 );          
      dmx_master.setChannelValue ( 1, 255 );
      delay (200 );    
      dmx_master.setChannelValue ( 1, 0 );   
      
      dmx_master.setChannelValue ( 6, 0 );  //canal 6 , valor entre 0<200  apagar piloto       
      }
}

// Button 9  
{
    if (buttonState9 == LOW)  
      { 
      //consecutivas 5,4,3,2,1,2,3,4,5  200ms  
      dmx_master.setChannelValue ( 6, 255 );  //canal 6 , valor entre 201-255  encender piloto
      // abrir cerrar uno a uno 
      dmx_master.setChannelValue ( 5, 255 );
      delay (200 ); 
      dmx_master.setChannelValue ( 5, 0 ); 
      dmx_master.setChannelValue ( 4, 255 );
      delay (200 );        
      dmx_master.setChannelValue ( 4, 0 );  
      dmx_master.setChannelValue ( 3, 255 );  
      delay (200 ); 
      dmx_master.setChannelValue ( 3, 0 );      
      dmx_master.setChannelValue ( 2, 255 );  
      delay (200 );  
      dmx_master.setChannelValue ( 2, 0 );          
      dmx_master.setChannelValue ( 1, 255 );
      delay (200 );    
      dmx_master.setChannelValue ( 1, 0 );   
      dmx_master.setChannelValue ( 2, 255 );
      delay (200 );        
      dmx_master.setChannelValue ( 2, 0 );  
      dmx_master.setChannelValue ( 3, 255 );  
      delay (200 ); 
      dmx_master.setChannelValue ( 3, 0 );      
      dmx_master.setChannelValue ( 4, 255 );  
      delay (200 );  
      dmx_master.setChannelValue ( 4, 0 );          
      dmx_master.setChannelValue ( 5, 255 );
      delay (200 );    
      dmx_master.setChannelValue ( 5, 0 );   
      
      dmx_master.setChannelValue ( 6, 0 );  //canal 6 , valor entre 0<200  apagar piloto  
      }
}

// Button 10 
{
    if (buttonState10 == LOW)  
      { 
      //consecutivas 3,2-4, 1-5, 2-4, 3  200ms  
      dmx_master.setChannelValue ( 6, 255 );  //canal 6 , valor entre 201-255  encender piloto
      // abrir cerrar uno a uno 
      dmx_master.setChannelValue ( 3, 255 );
      delay (200 ); 
      dmx_master.setChannelValue ( 3, 0 ); 
      dmx_master.setChannelValue ( 2, 255 );
      dmx_master.setChannelValue ( 4, 255 );
      delay (200 );  
      dmx_master.setChannelValue ( 2, 0 );
      dmx_master.setChannelValue ( 4, 0 );
      dmx_master.setChannelValue ( 1, 255 );
      dmx_master.setChannelValue ( 5, 255 );
      delay (200 ); 
      dmx_master.setChannelValue ( 1, 0 );
      dmx_master.setChannelValue ( 5, 0 );
      dmx_master.setChannelValue ( 2, 255 );
      dmx_master.setChannelValue ( 4, 255 );
      delay (200 );  
      dmx_master.setChannelValue ( 2, 0 );
      dmx_master.setChannelValue ( 4, 0 );                       
      dmx_master.setChannelValue ( 3, 255 );
      delay (200 );  
      dmx_master.setChannelValue ( 3, 0 );
      
      dmx_master.setChannelValue ( 6, 0 );  //canal 6 , valor entre 0<200  apagar piloto       
      }
}

// Button 11  
{
    if (buttonState11 == LOW)  
      { 
      
      //consecutivas 1-5, 2-4, 3, 2-4, 1-5  200ms  
      dmx_master.setChannelValue ( 6, 255 );  //canal 6 , valor entre 201-255  encender piloto
      // abrir cerrar uno a uno 
      dmx_master.setChannelValue ( 1, 255 );
      dmx_master.setChannelValue ( 5, 255 );
      delay (200 ); 
      dmx_master.setChannelValue ( 1, 0 ); 
      dmx_master.setChannelValue ( 5, 0 );
      dmx_master.setChannelValue ( 2, 255 );
      dmx_master.setChannelValue ( 4, 255 );
      delay (200 );  
      dmx_master.setChannelValue ( 2, 0 );
      dmx_master.setChannelValue ( 4, 0 );
      dmx_master.setChannelValue ( 3, 255 );
      delay (200 ); 
      dmx_master.setChannelValue ( 3, 0 );
      dmx_master.setChannelValue ( 2, 255 );
      dmx_master.setChannelValue ( 4, 255 );
      delay (200 );  
      dmx_master.setChannelValue ( 2, 0 );
      dmx_master.setChannelValue ( 4, 0 );                        
      dmx_master.setChannelValue ( 1, 255 );
      dmx_master.setChannelValue ( 5, 255 );
      delay (200 ); 
      dmx_master.setChannelValue ( 1, 0 ); 
      dmx_master.setChannelValue ( 5, 0 );
      dmx_master.setChannelValue ( 6, 0 );  //canal 6 , valor entre 0<200  apagar piloto         
      }
}

// Button 12  
{
    if (buttonState12 == LOW)  
      { 
 
      //consecutivas 1-5, 2-4, 3, 2-4, 1-5  200ms  
      dmx_master.setChannelValue ( 6, 255 );  //canal 6 , valor entre 201-255  encender piloto
      // abrir cerrar uno a uno 
      dmx_master.setChannelValue ( 1, 255 );
      dmx_master.setChannelValue ( 5, 255 );
      delay (100 ); 
      dmx_master.setChannelValue ( 1, 0 ); 
      dmx_master.setChannelValue ( 5, 0 );
      dmx_master.setChannelValue ( 2, 255 );
      dmx_master.setChannelValue ( 4, 255 );
      delay (100 );  
      dmx_master.setChannelValue ( 2, 0 );
      dmx_master.setChannelValue ( 4, 0 );
      dmx_master.setChannelValue ( 3, 255 );
      delay (100 ); 
      dmx_master.setChannelValue ( 3, 0 );
      dmx_master.setChannelValue ( 2, 255 );
      dmx_master.setChannelValue ( 4, 255 );
      delay (100 );  
      dmx_master.setChannelValue ( 2, 0 );
      dmx_master.setChannelValue ( 4, 0 );                        
      dmx_master.setChannelValue ( 1, 255 );
      dmx_master.setChannelValue ( 5, 255 );
      delay (100 ); 
      dmx_master.setChannelValue ( 1, 0 ); 
      dmx_master.setChannelValue ( 5, 0 );
      dmx_master.setChannelValue ( 6, 0 );  //canal 6 , valor entre 0<200  apagar piloto              
      
      }
}

// Button 13  
{
    if (buttonState13 == LOW)  
      { 
  
      }
}

// Button 14  
{
    if (buttonState14 == LOW)  
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
    if (buttonState15 == LOW)  
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
