/*
 * TongSheng TSDZ2 motor controller firmware/
 *
 * Copyright (C) Casainho, 2018.
 *
 * Released under the GPL License, Version 3
 */

#include <stdint.h>
#include "platform.h"
#include "main.h"
#include "interrupts.h"
#include "brake.h"
#include "motor.h"

// Brake signal
void EXTI_PORTC_IRQHandler(void) __interrupt(EXTI_PORTC_IRQHANDLER)
{
  if (brake_is_set())
  {
    motor_controller_set_state (MOTOR_CONTROLLER_STATE_BRAKE);
  }
  else
  {
    motor_controller_reset_state (MOTOR_CONTROLLER_STATE_BRAKE);
  }
}

void brake_init (void)
{
  //brake pin as external input pin interrupt
  //initialize the Interrupt sensitivity
  ATTACH_INTERRUPT(BRAKE__PORT, BRAKE__PIN, EXTI_SENSITIVITY_RISE_FALL, EXTI_PORT_GPIOC, EXTI_PORTC_IRQHandler);
}

BitStatus brake_is_set(void)
{
  if (READ_DIGITAL(BRAKE__PORT, BRAKE__PIN) == 0)
    return 1;
  else
    return 0;
}
