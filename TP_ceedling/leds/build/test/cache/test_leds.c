#include "src/leds.h"
#include "/var/lib/gems/2.7.0/gems/ceedling-0.31.0/vendor/unity/src/unity.h"




uint16_t ledsVirtuales;



void setUp(void){

   Leds_Create(&ledsVirtuales);

}



void tearDown(void) {

}













void test_LedsOffAfterCreate(void){

   uint16_t ledsVirtuales=0xFFFF;

   Leds_Create(&ledsVirtuales);

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

  ((void *)0)

  ), (UNITY_UINT)(22), UNITY_DISPLAY_STYLE_HEX16);

}





void test_TurnOnOneLed(void){

   Led_TurnOn(5);

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << 4)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

  ((void *)0)

  ), (UNITY_UINT)(28), UNITY_DISPLAY_STYLE_HEX16);

 }





void test_TurnOffOneLed(void){

   Led_TurnOn(5);

   Led_TurnOff(5);

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

  ((void *)0)

  ), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_HEX16);

 }





void test_TurnOnAndOffManyLed(void){

   Led_TurnOn(3);

   Led_TurnOn(5);

   Led_TurnOff(3);

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << (5 -1))), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

  ((void *)0)

  ), (UNITY_UINT)(43), UNITY_DISPLAY_STYLE_HEX16);

 }









void test_Leds_AllOn(void){

   Leds_AllOn(&ledsVirtuales);

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

  ((void *)0)

  ), (UNITY_UINT)(51), UNITY_DISPLAY_STYLE_HEX16);

}





 void test_Leds_AllOff(void){



   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

  ((void *)0)

  ), (UNITY_UINT)(57), UNITY_DISPLAY_STYLE_HEX16);

}





 void test_Led_Read_Off(void){



   Led_Read(5);

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

  ((void *)0)

  ), (UNITY_UINT)(64), UNITY_DISPLAY_STYLE_HEX16);

}







void test_Led_Read_On(void){

   Led_TurnOn(5);

   Led_Read(5);

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << (5 -1))), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

  ((void *)0)

  ), (UNITY_UINT)(72), UNITY_DISPLAY_STYLE_HEX16);

 }







void test_Leds_CheckLimits(void){

   uint64_t outOffLimits= 0xFFFF;

   uint8_t check;

   check=Leds_CheckLimits(outOffLimits);

   UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0001)), (UNITY_INT)(UNITY_INT16)((check)), (

  ((void *)0)

  ), (UNITY_UINT)(81), UNITY_DISPLAY_STYLE_HEX16);

}
