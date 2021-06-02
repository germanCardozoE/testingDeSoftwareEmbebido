#include <stdint.h>


void Leds_Create(uint16_t *);

void Led_TurnOn(uint8_t);

void Led_TurnOff(uint8_t);

void Leds_AllOn(uint16_t * );

void Leds_AllOff(uint16_t * );

uint8_t Led_Read(uint8_t);

int8_t Leds_CheckLimits(uint64_t );