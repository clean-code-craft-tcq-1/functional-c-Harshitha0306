/*
 *
 ***************************************************************************************************
 * Author:             Harshitha Subramani
 * Date:               23/02/2020  
 * Filename:           telecolor_test.h
 *
 ****************************************************************************************************
*
***************************************************************************************
* Includes
***************************************************************************************
*/

#include <stdio.h>
#include <assert.h>
#include "BMS_AttributeCheck.h"

/*
***************************************************************************************
* Methods
***************************************************************************************
*
 *This Function Checks if the Battery attribute value read is less than the defined Minimum limit
 * \param     attribute_value             Battery reading
 * \param     attribute                   This structure states attribute name , minimum and maximum limit
 * \return                                returns 1 if the Battery reading is less then the defined Minimum limit else returns 0     */         

int Check_Attributelow(float attribute_value,struct attribute s_attribute){
    
    if(attribute_value < s_attribute.attribute_minvalue)
    {
        printf("%s is low\n",s_attribute.attribute_name);
    }
    
    return(attribute_value < s_attribute.attribute_minvalue);
}

 /*This Function Checks if the Battery attribute value read is greater than the defined Maximum limit
 * \param     attribute_value             Battery reading
 * \param     attribute                   This structure states attribute name , minimum and maximum limit
 * \return                                returns 1 if the Battery reading is greater then the defined Maximum limit else returns 0     */    

int Check_AttributeHigh(float attribute_value,struct attribute s_attribute){
    if(attribute_value > s_attribute.attribute_maxvalue){
    printf("%s is high\n",s_attribute.attribute_name);
    }
    
    return(attribute_value > s_attribute.attribute_maxvalue);
}

 /*This Function Checks if the Battery is normal or abnormal based on defined Maximum and Minimum limts of each attribute
 * \param     temperature, soc,chargeRate   Input Attributes
  * \return                                 returns 1 if the Battery reading is normal else returns 0                           */   

int batteryIsOk(float temperature, float soc, float chargeRate)
{
    int temperature_check,soc_check,chargeRate_check =0;
    
    temperature_check = Check_Attributelow(temperature,s_temperature) + Check_AttributeHigh(temperature,s_temperature);
    soc_check = Check_Attributelow(soc,s_soc) + Check_AttributeHigh(soc,s_soc);
    chargeRate_check = Check_AttributeHigh(chargeRate,s_chargeRate);
    
    if((temperature_check + soc_check + chargeRate_check)==0)
    {
        printf("Battery is ok\n");
    }
    
    return!(temperature_check + soc_check + chargeRate_check);
   
}

int main() {
assert(batteryIsOk(45,70,0.7));   
assert(!batteryIsOk(50, 70, 0.7));
assert(!batteryIsOk(45, 85, 0.7));
assert(!batteryIsOk(45, 30, 1));
assert(!batteryIsOk(0, 10, 0));
assert(!batteryIsOk(50, 85, 0.9));
}
