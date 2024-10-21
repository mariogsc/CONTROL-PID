#include "PID_MOTOR.h"
#include "rtwtypes.h"
#include "MW_target_hardware_resources.h"

volatile int IsrOverrun = 0;
static boolean_T OverrunFlag = 0;
void rt_OneStep(void)
{
  /* Check for overrun. Protect OverrunFlag against preemption */
  if (OverrunFlag++) {
    IsrOverrun = 1;
    OverrunFlag--;
    return;
  }

#ifndef _MW_ARDUINO_LOOP_

  interrupts();

#endif;

  PID_MOTOR_step();

  /* Get model outputs here */
#ifndef _MW_ARDUINO_LOOP_

  noInterrupts();

#endif;

  OverrunFlag--;
}

volatile boolean_T stopRequested;
volatile boolean_T runModel;
int main(void)
{
  float modelBaseRate = 0.01;
  float systemClock = 0;

  /* Initialize variables */
  stopRequested = false;
  runModel = false;

#if defined(MW_MULTI_TASKING_MODE) && (MW_MULTI_TASKING_MODE == 1)

  MW_ASM (" SVC #1");

#endif

  ;
  init();
  MW_Arduino_Init();
  rtmSetErrorStatus(PID_MOTOR_M, 0);
  PID_MOTOR_initialize();
  noInterrupts();
  configureArduinoARMTimer();
  runModel = (rtmGetErrorStatus(PID_MOTOR_M) == (NULL)) && !rtmGetStopRequested
    (PID_MOTOR_M);

#ifndef _MW_ARDUINO_LOOP_

  interrupts();

#endif;

  interrupts();
  while (runModel) {
    stopRequested = !((rtmGetErrorStatus(PID_MOTOR_M) == (NULL)) &&
                      !rtmGetStopRequested(PID_MOTOR_M));
    MW_Arduino_Loop();
  }

  /* Terminate model */
  PID_MOTOR_terminate();
  MW_Arduino_Terminate();
  noInterrupts();
  return 0;
}
