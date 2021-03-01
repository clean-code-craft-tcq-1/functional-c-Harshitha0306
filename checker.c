#include <stdio.h>
#include <assert.h>

/*struct par_temperature
{
   char name[20];
   float min_temperature;
   float max_temperature;
}t = {"temperature",0,45};*/

int batteryIsOk(float temperature, float soc, float chargeRate)
{
    float a = temperature;
    float b = soc;
    float c = chargeRate;
    float reading[]= {a,b,c};
    
    char *batterypara[] = {"temperature","soc","chargeRate"};
    float  batterypara_min[] ={0,20,0};
    float  batterypara_max[] ={45,80,0.8};
    int i;
    int count = 3;
   for(i=0;i<3;i++)
   {
  
    if(reading[i] < batterypara_min[i])
    {
       printf(" %s is low!\n" ,batterypara[i]);
        count--;
    }
    if(reading[i] > batterypara_max[i])
    {
        printf(" %s is high!\n" ,batterypara[i]);
        count--;
    }
      
    }
    return((count < 3 )? 0 :1);
 }


int main() {

 assert(batteryIsOk(45,70,0.7));
 assert(!batteryIsOk(50, 85, 0));
}
