/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_LedsOffAfterCreate(void);
extern void test_TurnOnOneLed(void);
extern void test_TurnOffOneLed(void);
extern void test_TurnOnAndOffManyLed(void);
extern void test_Leds_AllOn(void);
extern void test_Leds_AllOff(void);
extern void test_Led_Read_Off(void);
extern void test_Led_Read_On(void);
extern void test_Leds_CheckLimits(void);


/*=======Mock Management=====*/
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
}
static void CMock_Verify(void)
{
}
static void CMock_Destroy(void)
{
}

/*=======Test Reset Options=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  CMock_Verify();
  CMock_Destroy();
  CMock_Init();
  setUp();
}
void verifyTest(void);
void verifyTest(void)
{
  CMock_Verify();
}

/*=======Test Runner Used To Run Each Test=====*/
static void run_test(UnityTestFunction func, const char* name, UNITY_LINE_TYPE line_num)
{
    Unity.CurrentTestName = name;
    Unity.CurrentTestLineNumber = line_num;
#ifdef UNITY_USE_COMMAND_LINE_ARGS
    if (!UnityTestMatches())
        return;
#endif
    Unity.NumberOfTests++;
    UNITY_CLR_DETAILS();
    UNITY_EXEC_TIME_START();
    CMock_Init();
    if (TEST_PROTECT())
    {
        setUp();
        func();
    }
    if (TEST_PROTECT())
    {
        tearDown();
        CMock_Verify();
    }
    CMock_Destroy();
    UNITY_EXEC_TIME_STOP();
    UnityConcludeTest();
}

/*=======MAIN=====*/
int main(void)
{
  UnityBegin("test_leds.c");
  run_test(test_LedsOffAfterCreate, "test_LedsOffAfterCreate", 14);
  run_test(test_TurnOnOneLed, "test_TurnOnOneLed", 26);
  run_test(test_TurnOffOneLed, "test_TurnOffOneLed", 32);
  run_test(test_TurnOnAndOffManyLed, "test_TurnOnAndOffManyLed", 39);
  run_test(test_Leds_AllOn, "test_Leds_AllOn", 49);
  run_test(test_Leds_AllOff, "test_Leds_AllOff", 55);
  run_test(test_Led_Read_Off, "test_Led_Read_Off", 61);
  run_test(test_Led_Read_On, "test_Led_Read_On", 69);
  run_test(test_Leds_CheckLimits, "test_Leds_CheckLimits", 77);

  return UnityEnd();
}