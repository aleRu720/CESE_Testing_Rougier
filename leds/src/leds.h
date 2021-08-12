#ifndef _LEDS_H
#define _LEDS_H

#include <stdint.h>
#include <stdbool.h>

#define LEDS_ALL_OFF            0x0000
#define LEDS_ALL_ON             0xFFFF
#define LEDS_INDEX_OFFSET       1
#define LEDS_STATE_ON           1
#define LEDS_STATE_OFF          0

void LedsInit(uint16_t * direccion);

void LedsTurnOn(int led);

void LedsTurnOff(int led);

bool LedsGetState(int led);

void LedsTurnOnAllLeds(void);

void LedsTurnOffAllLeds(void);

#endif