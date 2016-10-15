/*
 * This file is part of Cleanflight.
 *
 * Cleanflight is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Cleanflight is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Cleanflight.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdint.h>

#include <platform.h>
#include "drivers/io.h"

#include "drivers/timer.h"

const timerHardware_t timerHardware[USABLE_TIMER_CHANNEL_COUNT] = {
    // PPM Pad
#ifdef SPRACINGF3MINI_MKII_REVA
    { TIM3,  IO_TAG(PB5),  TIM_Channel_2, TIM3_IRQn,               0, IOCFG_AF_PP, }, // PPM - PB5
    // PB4 / TIM3 CH1 is connected to USBPresent
#else
    { TIM3,  IO_TAG(PB4),  TIM_Channel_1, TIM3_IRQn,               0, IOCFG_AF_PP, }, // PPM - PB4
    // PB5 / TIM3 CH2 is connected to USBPresent
#endif

    { TIM16, IO_TAG(PA6),  TIM_Channel_1, TIM1_UP_TIM16_IRQn,      1, IOCFG_AF_PP, },  // PWM1 - PA6
    { TIM17, IO_TAG(PA7),  TIM_Channel_1, TIM1_TRG_COM_TIM17_IRQn, 1, IOCFG_AF_PP, },  // PWM2 - PA7
    { TIM4,  IO_TAG(PB8),  TIM_Channel_3, TIM4_IRQn,               1, IOCFG_AF_PP, },  // PWM3 - PB8
    { TIM4,  IO_TAG(PB9),  TIM_Channel_4, TIM4_IRQn,               1, IOCFG_AF_PP, },  // PWM4 - PB9
    { TIM15, IO_TAG(PA2),  TIM_Channel_1, TIM1_BRK_TIM15_IRQn,     1, IOCFG_AF_PP, },  // PWM5 - PA2
    { TIM15, IO_TAG(PA3),  TIM_Channel_2, TIM1_BRK_TIM15_IRQn,     1, IOCFG_AF_PP, },  // PWM6 - PA3
    { TIM2,  IO_TAG(PA0),  TIM_Channel_1, TIM2_IRQn,               1, IOCFG_AF_PP, },  // PWM7 - PA0
    { TIM2,  IO_TAG(PA1),  TIM_Channel_2, TIM2_IRQn,               1, IOCFG_AF_PP, },  // PWM8 - PA1

    // UART3 RX/TX
    { TIM2,  IO_TAG(PB10), TIM_Channel_3, TIM2_IRQn,               1, IOCFG_AF_PP, }, // PWM9  - PB10 - TIM2_CH3 / UART3_TX (AF7)
    { TIM2,  IO_TAG(PB11), TIM_Channel_4, TIM2_IRQn,               1, IOCFG_AF_PP, }, // PWM10 - PB11 - TIM2_CH4 / UART3_RX (AF7)

    // LED Strip Pad
    { TIM1,  IO_TAG(PA8),  TIM_Channel_1, TIM1_CC_IRQn,            1, IOCFG_AF_PP, },  // GPIO_TIMER / LED_STRIP
};

