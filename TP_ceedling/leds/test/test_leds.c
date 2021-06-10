//=====  INCLUDES  ============//
#include "unity.h"
#include "leds.h"

//=====  END OF INCLUDES  =====//


//=====  DEFINES  =============//
#define LED             5              //valor valido de 1 a 8
#define LED2            4              //valor valido de 1 a 8
#define CHECK_LED       (1 << (LED-1))

#define LED_IS_ON       1
#define LED_IS_OFF      0
#define DATA_OK         0
//=====  END OF DEFINES  ======//


//=====  VARIABLES  ===========//
uint16_t ledsVirtuales;

//=====  END OF VARIABLES  ====//


//=====  FUNCTIONS  ===========//
void setUp(void){
   Leds_Create(&ledsVirtuales);
}


void tearDown(void) {
}


//Despues de inicializar todos los leds deben quedar en 0
void test_LedsOffAfterCreate(void){
   uint16_t ledsVirtuales=0xFFFF; 
   Leds_Create(&ledsVirtuales);
   TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales);
}


//Se puede prender un LED individual
void test_TurnOnOneLed(void){
   uint8_t isLedOn;
   isLedOn=Led_TurnOn(LED);
   TEST_ASSERT_EQUAL_HEX16(DATA_OK,isLedOn);
   TEST_ASSERT_EQUAL_HEX16(CHECK_LED,ledsVirtuales);
}


//Se puede apagar un LED individual
void test_TurnOffOneLed(void){
   uint8_t isLedOff;
   Led_TurnOn(LED);
   isLedOff=Led_TurnOff(LED);
   TEST_ASSERT_EQUAL_HEX16(DATA_OK,isLedOff);
   TEST_ASSERT_EQUAL_HEX16(0x0000,ledsVirtuales);
 }


//Se pueden prender y apagar multiples LEDs
void test_TurnOnAndOffManyLed(void){
   uint8_t isLedOff;
   uint8_t isLedOn;
   Led_TurnOn(LED2);
   isLedOn=Led_TurnOn(LED);
   isLedOff=Led_TurnOff(LED2);
   TEST_ASSERT_EQUAL_HEX16(DATA_OK,isLedOn);
   TEST_ASSERT_EQUAL_HEX16(DATA_OK,isLedOff);
   TEST_ASSERT_EQUAL_HEX16(CHECK_LED,ledsVirtuales);
 }


void test_Leds_AllOn(void){
   Leds_AllOn(&ledsVirtuales);
   TEST_ASSERT_EQUAL_HEX16(0xFFFF, ledsVirtuales);
}


 //Se pueden apagar todos los LEDs de una vez.
 void test_Leds_AllOff(void){
   TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales);
}


 //Se puede consultar el estado de un LED apagado.
 void test_Led_ReadOff(void){
   Led_TurnOff(LED);
   TEST_ASSERT_EQUAL_HEX16(LED_IS_OFF, Led_IsOn(LED));
}


 //    Se puede consultar el estado de un LED encendido 
void test_Led_ReadOn(void){
   Led_TurnOn(LED);
   TEST_ASSERT_EQUAL_HEX16(LED_IS_ON, Led_IsOn(LED));
 }

//=====  END OF FUNCTIONS  ====//
//=====  END OF FILE  =========//