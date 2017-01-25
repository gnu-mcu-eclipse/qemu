/*
 * STM32- AFIO(Alternate function I/O) emulation.
 *
 * Copyright (c) 2016 Liviu Ionescu.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef STM32_AFIO_H_
#define STM32_AFIO_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_AFIODEVICE_PATH_STM32"AFIO"

// ----------------------------------------------------------------------------

#define TYPE_STM32_AFIOTYPE_STM32_PREFIX "afio" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_AFIO_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32AFIOParentClass;
typedef PeripheralState STM32AFIOParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_AFIO_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32AFIOClass, (obj), TYPE_STM32_AFIO)
#define STM32_AFIO_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32AFIOClass, (klass), TYPE_STM32_AFIO)

typedef struct {
    // private: 
    STM32AFIOParentClass parent_class;
    // public: 

    // None, so far.
} STM32AFIOClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_AFIO_STATE(obj) \
    OBJECT_CHECK(STM32AFIOState, (obj), TYPE_STM32_AFIO)

typedef struct {
    // private:
    STM32AFIOParentState parent_obj;
    // public:

    const STM32Capabilities *capabilities;

    // TODO: remove this if the peripheral is always enabled.
    // Points to the bitfield that enables the peripheral.
    Object *enabling_bit;

union {
      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----

      // DO NOT REMOVE FIELDS! Automatically generated!
      // Merge fields from different family members.
      struct {
        // F1AFIO(Alternate function I/O) registers.
        struct { 
Object *evcr; // 0x0(Event Control Register (AFIO_EVCR)) 
Object *mapr; // 0x4(AF remap and debug I/O configuration register (AFIO_MAPR)) 
Object *exticr1; // 0x8(External interrupt configuration register 1 (AFIO_EXTICR1)) 
Object *exticr2; // 0xC(External interrupt configuration register 2 (AFIO_EXTICR2)) 
Object *exticr3; // 0x10(External interrupt configuration register 3 (AFIO_EXTICR3)) 
Object *exticr4; // 0x14(External interrupt configuration register 4 (AFIO_EXTICR4)) 
Object *mapr2; // 0x1C(AF remap and debug I/O configuration register) 
} reg;

        struct { 
// EVCR(Event Control Register (AFIO_EVCR)) bitfields.
          struct { 
Object *pin; // [0:3] Pin selectionObject *port; // [4:6] Port selectionObject *evoe; // [7:7] Event Output Enable} evcr; 
// MAPR(AF remap and debug I/O configuration register (AFIO_MAPR)) bitfields.
          struct { 
Object *spi1_remap; // [0:0] SPI1 remappingObject *i2c1_remap; // [1:1] I2C1 remappingObject *usart1_remap; // [2:2] USART1 remappingObject *usart2_remap; // [3:3] USART2 remappingObject *usart3_remap; // [4:5] USART3 remappingObject *tim1_remap; // [6:7] TIM1 remappingObject *tim2_remap; // [8:9] TIM2 remappingObject *tim3_remap; // [10:11] TIM3 remappingObject *tim4_remap; // [12:12] TIM4 remappingObject *can_remap; // [13:14] CAN1 remappingObject *pd01_remap; // [15:15] Port D0/Port D1 mapping on OSCIN/OSCOUTObject *tim5ch4_iremap; // [16:16] Set and cleared by softwareObject *adc1_etrginj_remap; // [17:17] ADC 1 External trigger injected conversion remappingObject *adc1_etrgreg_remap; // [18:18] ADC 1 external trigger regular conversion remappingObject *adc2_etrginj_remap; // [19:19] ADC 2 external trigger injected conversion remappingObject *adc2_etrgreg_remap; // [20:20] ADC 2 external trigger regular conversion remappingObject *swj_cfg; // [24:26] Serial wire JTAG configuration} mapr; 
// EXTICR1(External interrupt configuration register 1 (AFIO_EXTICR1)) bitfields.
          struct { 
Object *exti0; // [0:3] EXTI0 configurationObject *exti1; // [4:7] EXTI1 configurationObject *exti2; // [8:11] EXTI2 configurationObject *exti3; // [12:15] EXTI3 configuration} exticr1; 
// EXTICR2(External interrupt configuration register 2 (AFIO_EXTICR2)) bitfields.
          struct { 
Object *exti4; // [0:3] EXTI4 configurationObject *exti5; // [4:7] EXTI5 configurationObject *exti6; // [8:11] EXTI6 configurationObject *exti7; // [12:15] EXTI7 configuration} exticr2; 
// EXTICR3(External interrupt configuration register 3 (AFIO_EXTICR3)) bitfields.
          struct { 
Object *exti8; // [0:3] EXTI8 configurationObject *exti9; // [4:7] EXTI9 configurationObject *exti10; // [8:11] EXTI10 configurationObject *exti11; // [12:15] EXTI11 configuration} exticr3; 
// EXTICR4(External interrupt configuration register 4 (AFIO_EXTICR4)) bitfields.
          struct { 
Object *exti12; // [0:3] EXTI12 configurationObject *exti13; // [4:7] EXTI13 configurationObject *exti14; // [8:11] EXTI14 configurationObject *exti15; // [12:15] EXTI15 configuration} exticr4; 
// MAPR2(AF remap and debug I/O configuration register) bitfields.
          struct { 
Object *tim9_remap; // [5:5] TIM9 remappingObject *tim10_remap; // [6:6] TIM10 remappingObject *tim11_remap; // [7:7] TIM11 remappingObject *tim13_remap; // [8:8] TIM13 remappingObject *tim14_remap; // [9:9] TIM14 remappingObject *fsmc_nadv; // [10:10] NADV connect/disconnect} mapr2; 
} fld;
      } f1;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32AFIOState;

// ----------------------------------------------------------------------------

#endif /* STM32_AFIO_H_ */
