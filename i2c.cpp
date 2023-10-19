
#include <Arduino.h>
#include "Wire.h"
#include "i2c.h"
//#include "teensy_map.h"

uint8_t busScan(uint8_t bus, uint8_t* addresses)
{   
    uint8_t deviceCount = 0;
    switch (bus)
    {
    case 0:
        {
        
        Wire.begin();
        Wire.setTimeout(10000);
        for(uint8_t target = 1; target <= 0x7F; target++)
        {
            Wire.beginTransmission(target);
            if(Wire.endTransmission() == 0X00)
            {
                //Found a device
                addresses[deviceCount] = target;
                deviceCount++;
            }
            return deviceCount;
        }
        break;
        }
    case 1:
        {
            Wire1.begin();
            Wire1.setTimeout(10000);
            for(uint8_t target = 1; target <= 0x7F; target++)
            {
                Wire1.beginTransmission(target);
                if(Wire1.endTransmission() == 0X00)
                {
                    //Found a device
                    addresses[deviceCount] = target;
                    deviceCount++;
                }
                return deviceCount;
            }
        break;
        }
    case 2:
        {
            Wire2.begin();
            Wire2.setTimeout(10000);
            //debug.printf("Testing Adress: 0x%x",*addresses);
            for(uint8_t target = 1; target <= 0x7F; target++)
            {
                Wire2.beginTransmission(target);
                if(Wire2.endTransmission() == 0X00)
                {
                    //Found a device
                    //addresses[deviceCount] = target;
                    addresses[deviceCount] = target;
                    debug.printf("Found Device at Adress: 0x%x\n",target);
                    //debug.printf("Found Device at Adress: 0x%x\n",addresses[deviceCount] );
                    deviceCount++;
                }
                
            }
            return deviceCount;
            break;
        }
    default:
        break;
    }
}