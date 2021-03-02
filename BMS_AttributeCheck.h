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

#ifndef BMS_AttributeCheck_h
#define BMS_AttributeCheck_h

#include <stdio.h>

/*
***************************************************************************************
* Definitions
***************************************************************************************
*/

struct attribute
{
    char attribute_name[20];
   float attribute_maxvalue;
   float attribute_minvalue;
   
}s_attribute;

struct attribute s_temperature ={"temperature",45,0};
struct attribute s_soc = {"soc",80,20};
struct attribute s_chargeRate = {"chargeRate",0.8,0};

/*
***************************************************************************************
* Declarations
***************************************************************************************
*/
int Check_Attributelow(float attribute_value,struct attribute s_attribute);
int Check_AttributeHigh(float attribute_value,struct attribute s_attribute);
int batteryIsOk(float temperature, float soc, float chargeRate);
#endif /* BMS_AttributeCheck_h */
