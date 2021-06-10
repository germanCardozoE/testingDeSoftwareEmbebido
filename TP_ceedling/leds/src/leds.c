//=====  INCLUDES  ============//
#include "leds.h"

//=====  END OF INCLUDES  =====//


//=====  DEFINES  =============//
#define ALL_LEDS_OFF    0x000
#define ALL_LEDS_ON     0xFFFF
#define LED_ON          1
#define LED_OFF         0
#define LED_OFFSET      1
#define ERROR_NUM_LED   -1 //retorno de led fuera de rango
#define NUMERO_MAX_LED  8
#define NUMERO_MIN_LED  1
#define OK              0 //retorno de funcion generico si no hay error

//=====  END OF DEFINES  ======//


//=====  VARIABLES  ===========//
static uint16_t *puerto;

//=====  END OF VARIABLES  ====//


//=====  FUNCTIONS  ===========//
uint16_t led_to_bit(uint8_t led){
    return (LED_ON << (led -LED_OFFSET));
}


void Leds_Create(uint16_t * puntero){
    puerto=puntero;
    * puerto = ALL_LEDS_OFF;
}


uint8_t Led_TurnOn(uint8_t led){
    if(led>NUMERO_MAX_LED||led<NUMERO_MIN_LED)
        return ERROR_NUM_LED;
    
    *puerto|=led_to_bit(led);
    return OK;
}


uint8_t Led_TurnOff(uint16_t led){
    if(led>NUMERO_MAX_LED||led<NUMERO_MIN_LED)
        return ERROR_NUM_LED;

    *puerto &= ~led_to_bit(led);
    return OK;
}


void Leds_AllOn(uint16_t * puntero){
    puerto=puntero;
    * puerto = ALL_LEDS_ON;
}


void Leds_AllOff(uint16_t * puntero){
    Leds_Create(puntero);
}


uint8_t Led_IsOn(uint16_t led){
    if(led>NUMERO_MAX_LED||led<NUMERO_MIN_LED)
        return ERROR_NUM_LED;

    *puerto &= led_to_bit(led);
    if(*puerto==0)
        return LED_OFF;
    else
        return LED_ON;
}
//=====  END OF FUNCTIONS  ====//
//=====  END OF FILE  =========//