#include "leds.h"
#include <stdbool.h>
#include <stdint.h>

static uint16_t *puerto;

static uint16_t LedsIndexToMask(int led)
{
    return (LEDS_STATE_ON << (led - LEDS_INDEX_OFFSET));
}

void LedsInit(uint16_t * direccion)
{
    puerto = direccion;
    *direccion = LEDS_ALL_OFF ;
}

void LedsTurnOn(int led)
{
    *puerto |= LedsIndexToMask(led);
}

void LedsTurnOff(int led)
{
    *puerto &= ~LedsIndexToMask(led);
}

bool LedsGetState(int led)
{
    uint16_t ledMask = LEDS_ALL_OFF;
    ledMask |= LedsIndexToMask(led);
    return (*puerto & ledMask);
}

void LedsTurnOnAllLeds(void)
{
    *puerto = LEDS_ALL_ON; 
}

void LedsTurnOffAllLeds(void)
{
    *puerto = LEDS_ALL_OFF; 
}


