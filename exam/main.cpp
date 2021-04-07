#include "mbed.h"
#include "uLCD_4DGL.h"
// Initialize a pins to perform analog and digital output functions
// Adjust analog output pin name to your board spec.
AnalogOut aout(PA_4);
DigitalOut dout(LED1);
InterruptIn  up(PA_2);
InterruptIn down(PA_7);
InterruptIn selec(PA_6);
AnalogIn Ain(A0);
int _count = 0;
int i =0;
float freq[4] = {0.125, 0.25, 0.5, 1};

uLCD_4DGL uLCD(D1, D0, D2); // serial tx, serial rx, reset pin;



void Up()
{
    uLCD.cls();
    if(_count<4&&_count>=0)
    {
        _count++;
    uLCD.printf("%f Hz\n", freq[_count]);
    }
      
}

void Down()
{
    uLCD.cls();
    if(_count>0&&_count<=4)
    {
    _count--;
    uLCD.printf("%f Hz\n", freq[_count]);
    }
    
}

void Selec()
{
    uLCD.cls();
    _count;
    uLCD.printf("%f Hz\n", freq[_count]);
    i=1;
}



void signal(const int freq)
{

   int s = 0;
   
   int sample = 1000;
 

   while (1)
   {
      if (freq == 0.125)
      {
         for (float i = 0.0f; i < 1.0f; i += 0.1f)
         {
            aout = i;
            dout = (aout > 0.5f) ? 1 : 0;
            wait_us(200);
         }

         for (float i = 1.0f; i > 0.0f; i -= 0.1f)
         {
            aout = i;
            dout = (aout > 0.5f) ? 1 : 0;
            wait_us(300);
         }
      }
      else if (freq == 0.25)
      {
         for (float i = 0.0f; i < 1.0f; i += 0.1f)
         {
            aout = i;
            dout = (aout > 0.5f) ? 1 : 0;
            wait_us(400);
         }

         for (float i = 1.0f; i > 0.0f; i -= 0.1f)
         {
            aout = i;
            dout = (aout > 0.5f) ? 1 : 0;
            wait_us(600);
         }
      }
      else if (freq == 0.5)
      {
         for (float i = 0.0f; i < 1.0f; i += 0.1f)
         {
            aout = i;
            dout = (aout > 0.5f) ? 1 : 0;
            ThisThread::sleep_for(4ms);
         }

         for (float i = 1.0f; i > 0.0f; i -= 0.1f)
         {
            aout = i;
            dout = (aout > 0.5f) ? 1 : 0;
            ThisThread::sleep_for(6ms);
         }
      }
      else
      {
         for (float i = 0.0f; i < 1.0f; i += 0.1f)
         {
            aout = i;
            dout = (aout > 0.5f) ? 1 : 0;
            ThisThread::sleep_for(60ms);
         }

         for (float i = 1.0f; i > 0.0f; i -= 0.1f)
         {
            aout = i;
            dout = (aout > 0.5f) ? 1 : 0;
            ThisThread::sleep_for(40ms);
         }
      }
      for(int i = 0; i< sample; i++)
      {
          ADCdata[i]= Ain;
   
         ThisThread::sleep_for(1ms/sample);
      }
        for(int i = 0; i< sample; i++)
      {
      
           printf("%f\r\n", ADCdata[i]);
         ThisThread::sleep_for(1ms);
      }
  
   }
}


int main(void)
{

  //_count = 0;


  


   
       uLCD.text_width(1); //4X size text
   
   uLCD.text_height(2);
   uLCD.color(BLUE);
   uLCD.textbackground_color(WHITE);
   uLCD.background_color(WHITE);
    //while(1)
    //{
        up.rise(&Up);
        down.rise(&Down);
        selec.rise(&Selec);
      
      while(i==0)
      {
          ;
      }
    signal(freq[_count]);

}