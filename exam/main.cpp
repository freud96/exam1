#include "mbed.h"
#include "uLCD_4DGL.h"

AnalogOut aout(PA_4);
DigitalOut dout(LED1);
InterruptIn  up(PA_2);
InterruptIn down(PA_7);
InterruptIn selec(PA_6);
AnalogIn Ain(A0);
int _count = 0;
int i =0;
float freq[4] = {0.125, 0.25, 0.5, 1};

uLCD_4DGL uLCD(D1, D0, D2); 



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




int main(void)
{
   
    uLCD.text_width(1);
   
   uLCD.text_height(2);
   uLCD.color(BLUE);
   uLCD.textbackground_color(WHITE);
   uLCD.background_color(WHITE);

        up.rise(&Up);
        down.rise(&Down);
        selec.rise(&Selec);
      
      while(i==0)
      {
          ;
      }
    

}