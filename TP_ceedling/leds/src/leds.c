#include "leds.h"

#define ALL_LEDS_OFF    0x000
#define ALL_LEDS_ON     0xFFFF
#define LED_ON          1
#define LED_OFFSET      1

static uint16_t *puerto;

uint16_t led_to_bit(uint8_t led){
    return (LED_ON << (led -LED_OFFSET));
}

void Leds_Create(uint16_t * puntero){
    puerto=puntero;
    * puerto = ALL_LEDS_OFF;

}

void Led_TurnOn(uint8_t led){
    *puerto|=led_to_bit(led);
}

void Led_TurnOff(uint8_t led){
    *puerto &= ~led_to_bit(led);
}

void Leds_AllOn(uint16_t * puntero){
    puerto=puntero;
    * puerto = ALL_LEDS_ON;

}

void Leds_AllOff(uint16_t * puntero){
    Leds_Create(puntero);

}

uint8_t Led_Read(uint8_t led){
    *puerto &= led_to_bit(led);
    return *puerto;
}

int8_t Leds_CheckLimits(uint64_t limite){
    if( limite>=ALL_LEDS_OFF && limite<=ALL_LEDS_ON)
        return 1;
    else
        return -1;
}