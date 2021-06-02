#include "unity.h"
#include "leds.h"

#define LED 5
uint16_t ledsVirtuales;

void setUp(void){
   Leds_Create(&ledsVirtuales);
}

void tearDown(void) {
}

/*void test_LedsOffAfterCreate(void) {
   TEST_FAIL_MESSAGE("Empezamos");
}*/

//Despues de inicializar todos los leds deben quedar en 0
void test_LedsOffAfterCreate(void){
   uint16_t ledsVirtuales=0xFFFF; //puedo usar la variable local o directamente la global
   Leds_Create(&ledsVirtuales);
   TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales);
}

//Se puede prender un LED individual
void test_TurnOnOneLed(void){
   Led_TurnOn(LED);
   TEST_ASSERT_EQUAL_HEX16(1 << 4,ledsVirtuales);
 }

 //Se puede apagar un LED individual
void test_TurnOffOneLed(void){
   Led_TurnOn(LED);
   Led_TurnOff(LED);
   TEST_ASSERT_EQUAL_HEX16(0x0000,ledsVirtuales);
 }

//Se pueden prender y apagar multiples LEDs
void test_TurnOnAndOffManyLed(void){
   Led_TurnOn(3);
   Led_TurnOn(LED);
   Led_TurnOff(3);
   TEST_ASSERT_EQUAL_HEX16(1 << (LED-1),ledsVirtuales);
 }

 /*   TERMINAR */
//    Se pueden prender todos los LEDs de una vez.

void test_Leds_AllOn(void){
   Leds_AllOn(&ledsVirtuales);
   TEST_ASSERT_EQUAL_HEX16(0xFFFF, ledsVirtuales);
}

 //    Se pueden apagar todos los LEDs de una vez.
 void test_Leds_AllOff(void){

   TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales);
}

 //    Se puede consultar el estado de un LED apagado.
 void test_Led_Read_Off(void){
    //como los leds inician apagados la funcion debe retornar 0 
   Led_Read(LED);
   TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales);
}

 //    Se puede consultar el estado de un LED encendido 

void test_Led_Read_On(void){
   Led_TurnOn(LED);
   Led_Read(LED);
   TEST_ASSERT_EQUAL_HEX16(1 << (LED-1),ledsVirtuales);
 }

 //    Revisar limites de los parametros.
 
void test_Leds_CheckLimits(void){
   uint64_t  outOffLimits= 0xFFFF;//valores mayores a 0xFFFF deben dar erro
   uint8_t  check;
   check=Leds_CheckLimits(outOffLimits);
   TEST_ASSERT_EQUAL_HEX16(0x0001, check);      
}