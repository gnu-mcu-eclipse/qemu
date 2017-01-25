/*
 * STM32- PWR(Power control) emulation.
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

#ifndef STM32_PWR_H_
#define STM32_PWR_H_

#include "qemu/osdep.h"

#include <hw/cortexm/peripheral.h>
#include <hw/cortexm/stm32/capabilities.h>

// ----------------------------------------------------------------------------

#define DEVICE_PATH_STM32_PWRDEVICE_PATH_STM32"PWR"

// ----------------------------------------------------------------------------

#define TYPE_STM32_PWRTYPE_STM32_PREFIX "pwr" TYPE_PERIPHERAL_SUFFIX

// ----------------------------------------------------------------------------

// Parent definitions.
#define TYPE_STM32_PWR_PARENT TYPE_PERIPHERAL
typedef PeripheralClass STM32PWRParentClass;
typedef PeripheralState STM32PWRParentState;

// ----------------------------------------------------------------------------

// Class definitions.
#define STM32_PWR_GET_CLASS(obj) \
    OBJECT_GET_CLASS(STM32PWRClass, (obj), TYPE_STM32_PWR)
#define STM32_PWR_CLASS(klass) \
    OBJECT_CLASS_CHECK(STM32PWRClass, (klass), TYPE_STM32_PWR)

typedef struct {
    // private: 
    STM32PWRParentClass parent_class;
    // public: 

    // None, so far.
} STM32PWRClass;

// ----------------------------------------------------------------------------

// Instance definitions.
#define STM32_PWR_STATE(obj) \
    OBJECT_CHECK(STM32PWRState, (obj), TYPE_STM32_PWR)

typedef struct {
    // private:
    STM32PWRParentState parent_obj;
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
        // F4PWR(Power control) registers.
        struct { 
Object *cr; // 0x0(Power control register) 
Object *csr; // 0x4(Power control/status register) 
} reg;

        struct { 
// CR(Power control register) bitfields.
          struct { 
Object *lpds; // [0:0] Low-power deep sleepObject *pdds; // [1:1] Power down deepsleepObject *cwuf; // [2:2] Clear wakeup flagObject *csbf; // [3:3] Clear standby flagObject *pvde; // [4:4] Power voltage detector enableObject *pls; // [5:7] PVD level selectionObject *dbp; // [8:8] Disable backup domain write protectionObject *fpds; // [9:9] Flash power down in Stop modeObject *lpuds; // [10:10] Low-Power Regulator Low Voltage in deepsleepObject *mruds; // [11:11] Main regulator low voltage in deepsleep modeObject *adcdc1; // [13:13] ADCDC1Object *vos; // [14:15] Regulator voltage scaling output selectionObject *oden; // [16:16] Over-drive enableObject *odswen; // [17:17] Over-drive switching enabledObject *uden; // [18:19] Under-drive enable in stop mode} cr; 
// CSR(Power control/status register) bitfields.
          struct { 
Object *wuf; // [0:0] Wakeup flagObject *sbf; // [1:1] Standby flagObject *pvdo; // [2:2] PVD outputObject *brr; // [3:3] Backup regulator readyObject *ewup; // [8:8] Enable WKUP pinObject *bre; // [9:9] Backup regulator enableObject *vosrdy; // [14:14] Regulator voltage scaling output selection ready bitObject *odrdy; // [16:16] Over-drive mode readyObject *odswrdy; // [17:17] Over-drive mode switching readyObject *udrdy; // [18:19] Under-drive ready flag} csr; 
} fld;
      } f4;

      // ----- 8< ----- 8< -----  8< ----- 8< ----- 8< ----- 8< ----- 8< -----
    } u;

} STM32PWRState;

// ----------------------------------------------------------------------------

#endif /* STM32_PWR_H_ */
