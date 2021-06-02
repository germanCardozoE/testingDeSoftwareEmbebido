# Testing De Software Embebido

## Repositorio para el TP3. TDD.

A continuación se detallan los test realizados:

- Despues de inicializar todos los leds deben quedar en 0
  void test_LedsOffAfterCreate(void);
- Se puede prender un LED individual
  void test_TurnOnOneLed(void);
- Se puede apagar un LED individual
  void test_TurnOffOneLed(void);
- Se pueden prender y apagar multiples LEDs
  void test_TurnOnAndOffManyLed(void);
- Se pueden prender todos los LEDs de una vez.
  void test_Leds_AllOn(void);
- Se pueden apagar todos los LEDs de una vez.
  void test_Leds_AllOff(void);
- Se puede consultar el estado de un LED apagado.
  void test_Led_Read_Off(void);
- Se puede consultar el estado de un LED encendido 
  void test_Led_Read_On(void);
- Revisar limites de los parametros.
  void test_Leds_CheckLimits(void);
  
