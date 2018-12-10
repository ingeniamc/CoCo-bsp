/**
 *   @file  cocoV2AM335x_ethernet_config.c
 *
 *   @brief
 *      This file contains the ICSS EMAC PHY configurations for cocoV2AM335x board
 *
 *      Board_icssEthConfig: This API configures 10/100 PHYs connected to two
 *      ICSS ports. Several configurations are needed for normal operation of
 *      the ICSS Ethernet PHYs which will be taken care by this function.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2017, Texas Instruments, Inc.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *  \par
*/


#include <ti/csl/soc.h>
#include <ti/csl/csl_gpio.h>

#include "board_internal.h"
#include "board_cfg.h"

#include <ti/starterware/include/device.h>
#include <ti/starterware/include/hw/hw_icss_mii_mdio.h>

/* Structure holding gpio pin configuration parameters. */
typedef struct gpioPinCfg
{
    uint32_t dir;
    /**< pin direction . */
    uint32_t debounceEnable;
    /**< Enable/disable debounce feature. */
    uint32_t debounceTime;
    /**< deboune timing control. */
    uint32_t intrEnable;
    /**< Interrupt enable/disable. */
    uint32_t intrType;
    /**< Interrupt type edge or level . */
    uint32_t intrLine;
    /**< Interrupt line number. */
    uint32_t wakeEnable;
    /**< Wake up enable/disable control. */
    uint32_t wakeLine;
    /**< Wakeup line number. */
}gpioPinCfg_t;

/* Structure holding the GPIO pin object data structure. */
typedef struct gpioPinObj
{
    uint32_t     pinNum;
    /**< GPIO pin number. */
    uint32_t     instNum;
    /**< GPIO instance number. */
    uint32_t     instAddr;
    /**< GPIO instance address. */
    gpioPinCfg_t pinCfg;
    /**< GPIO pin configuration structure.*/
}gpioPinObj_t;


/* Global structure holding the default GPIO IP configuration values. */
gpioPinObj_t gpioPinObjDefault =
{
    0U,  /* pin number */
    0U,  /* Instance number */
    0U,  /* Instance Address */
    {
        GPIO_DIR_OUTPUT, /* dir */
        FALSE,  /* debounceEnable */
        0U,     /* debounceTime */
        FALSE,  /* intrEnable */
        0U,     /* intrType */
        0U,     /* intrLine */
        FALSE,  /* wakeEnable */
        0U,     /* wakeLine */
    }
};

/**
 * \brief  Local Delay function
 *
 * \return  none
 */
static void Board_delay(uint32_t ix);/* for misra warning */
static void Board_delay(uint32_t ix)
{
    while (ix--) {
        asm("   NOP");
    }
}

/**
 * \brief Wrapper for GPIO pin configuration
            Such as direction, debounce, wakeup, interrupt.
 *
 * \return  none
 */
static void Board_GPIOPinConfig(uint32_t baseAddr, uint32_t pinNum, gpioPinCfg_t *pGpioPinConfig); /* for misra warning */
static void Board_GPIOPinConfig(uint32_t baseAddr, uint32_t pinNum, gpioPinCfg_t *pGpioPinConfig)
{
    /* Configure Pin as an Input/Output Pin. */
    GPIODirModeSet(baseAddr, pinNum, pGpioPinConfig->dir);

    /* Enable Debouncing feature for the GPIO Pin. */
    GPIODebounceFuncControl(baseAddr, pinNum, GPIO_DEBOUNCE_FUNC_ENABLE);

    if(TRUE == pGpioPinConfig->debounceEnable)
    {
        /*
         * Configure the Debouncing Time for all the input pins of
         * the selected GPIO instance.
         */
        GPIODebounceTimeConfig(baseAddr, pGpioPinConfig->debounceTime);
    }

    if(FALSE == pGpioPinConfig->intrEnable)
    {
        /* Enable interrupt for the specified GPIO Pin. */
        GPIOPinIntDisable(baseAddr, pGpioPinConfig->intrLine, pinNum);
    }
    else
    {
        /*
         * Configure interrupt generation on detection of a logic HIGH or
         * LOW levels or a rising or a falling edge.
         */
        GPIOIntTypeSet(baseAddr, pinNum, pGpioPinConfig->intrType);

        /* Enable interrupt for the specified GPIO Pin. */
        GPIOPinIntEnable(baseAddr, pGpioPinConfig->intrLine, pinNum);
    }

    if(FALSE == pGpioPinConfig->wakeEnable)
    {
        /* Enable wakeup generation for GPIO Module */
        GPIOWakeupGlobalDisable(baseAddr);

        /* Configure input GPIO Pin to wakeup */
        GPIOPinIntWakeUpDisable(baseAddr, pGpioPinConfig->intrLine, pinNum);
    }
    else
    {
        /* Configure input GPIO Pin to wakeup */
        GPIOPinIntWakeUpEnable(baseAddr, pGpioPinConfig->intrLine, pinNum);
    }
}
    
/**
 * \brief Initializes GPIO instance as specified by object passed in.
 *
 * \return  none
 */
static void Board_initGPIO(gpioPinObj_t *pGpioObj);  /* for misra warning */
static void Board_initGPIO(gpioPinObj_t *pGpioObj)
{
   /* Enabling the GPIO module. */
    GPIOModuleEnable(pGpioObj->instAddr);

    /* GPIO pin characteristics configuration */
    Board_GPIOPinConfig(pGpioObj->instAddr, pGpioObj->pinNum, &pGpioObj->pinCfg);
}

/**
 * \brief  Resets the ICSS Ethernet PHYs
 *
 * \return  none
 */
static void Board_phyReset(void);  /* for misra warning */
static void Board_phyReset(void)
{
    gpioPinObj_t tGpioPhyReset = gpioPinObjDefault;

    tGpioPhyReset.instAddr = SOC_GPIO_2_REGS;
    tGpioPhyReset.pinNum = 5;

    Board_initGPIO(&tGpioPhyReset);
    GPIOPinWrite(tGpioPhyReset.instAddr, tGpioPhyReset.pinNum, 0);
    Board_delay(10000);
    GPIOPinWrite(tGpioPhyReset.instAddr, tGpioPhyReset.pinNum, 1);
    Board_delay(10000);
}


/**
 * \brief  Board specific configurations for ICSS  Ethernet PHYs
 *
 *  This function takes care of making several board level configurations
 *  required for ICSS EMAC PHY as listed below.
 *   - Enable Phy buffers
 *   - Resetting the PHYs for proper address latching
 *
 * \return  none
 */
Board_STATUS Board_icssEthConfig(void);  /* for misra warning */
Board_STATUS Board_icssEthConfig(void)
{
    HWREG(SOC_CONTROL_REGS + 0x824) |= 0x7; /* (T10) (COL) pin set to gpio0_23 */
    HWREG(SOC_CONTROL_REGS + 0x8CC) |= 0x7; /* (U4) (RX_D0) pin set to gpio2_17 */
    HWREG(SOC_CONTROL_REGS + 0x8C8) |= 0x7; /* (U3) (RX_D1) pin set to gpio2_16 */
    HWREG(SOC_CONTROL_REGS + 0x8C4) |= 0x7; /* (U2) (RX_D2) pin set to gpio2_15 */
    HWREG(SOC_CONTROL_REGS + 0x8C0) |= 0x7; /* (U1) (RX_D3) pin set to gpio2_14 */
    HWREG(SOC_CONTROL_REGS + 0x8D0) |= 0x7; /* (V2) (LED0) pin set to gpio0_8 */
    HWREG(SOC_CONTROL_REGS + 0x8E8) |= 0x7; /* (V5) (CRS) pin set to gpio2_24 */
    HWREG(SOC_CONTROL_REGS + 0x8D4) |= 0x7; /* (V3) (RX_ERR) pin set to gpio0_9 */
    HWREG(SOC_CONTROL_REGS + 0x8DC) |= 0x7; /* (T5) (RX_DV) pin set to gpio0_11 */

    gpioPinObj_t tGpioBufsEnable, tGpioCol, tGpioRxD0, tGpioRxD1, tGpioRxD2, tGpioRxD3, tGpioLed, tGpioCrs, tGpioRxErr, tGpioRxDv;
    tGpioBufsEnable = tGpioCol = tGpioRxD0 = tGpioRxD1 = tGpioRxD2 = tGpioRxD3 = tGpioLed = tGpioCrs = tGpioRxErr = tGpioRxDv = gpioPinObjDefault;

    tGpioBufsEnable.instAddr = SOC_GPIO_2_REGS;
    tGpioBufsEnable.pinNum =  23;
    Board_initGPIO(&tGpioBufsEnable);
    GPIOPinWrite(tGpioBufsEnable.instAddr, tGpioBufsEnable.pinNum, GPIO_PIN_HIGH);  
    
    tGpioCol.instAddr = SOC_GPIO_0_REGS;
    tGpioCol.pinNum =  23;
    Board_initGPIO(&tGpioCol);
    GPIOPinWrite(tGpioCol.instAddr, tGpioCol.pinNum, GPIO_PIN_HIGH);

    tGpioRxD0.instAddr = SOC_GPIO_2_REGS;
    tGpioRxD0.pinNum =  17;
    Board_initGPIO(&tGpioRxD0);
    GPIOPinWrite(tGpioRxD0.instAddr, tGpioRxD0.pinNum, GPIO_PIN_LOW); 

    tGpioRxD1.instAddr = SOC_GPIO_2_REGS;
    tGpioRxD1.pinNum =  16;
    Board_initGPIO(&tGpioRxD1);
    GPIOPinWrite(tGpioRxD1.instAddr, tGpioRxD1.pinNum, GPIO_PIN_LOW); 

    tGpioRxD2.instAddr = SOC_GPIO_2_REGS;
    tGpioRxD2.pinNum =  15;
    Board_initGPIO(&tGpioRxD2);
    GPIOPinWrite(tGpioRxD2.instAddr, tGpioRxD2.pinNum, GPIO_PIN_LOW); 

    tGpioRxD3.instAddr = SOC_GPIO_2_REGS;
    tGpioRxD3.pinNum =  14;
    Board_initGPIO(&tGpioRxD3);
    GPIOPinWrite(tGpioRxD3.instAddr, tGpioRxD3.pinNum, GPIO_PIN_LOW); 

    tGpioLed.instAddr = SOC_GPIO_0_REGS;
    tGpioLed.pinNum =  8;
    Board_initGPIO(&tGpioLed);
    GPIOPinWrite(tGpioLed.instAddr, tGpioLed.pinNum, GPIO_PIN_HIGH); 

    tGpioCrs.instAddr = SOC_GPIO_2_REGS;
    tGpioCrs.pinNum =  24;
    Board_initGPIO(&tGpioCrs);
    GPIOPinWrite(tGpioCrs.instAddr, tGpioCrs.pinNum, GPIO_PIN_LOW); 

    tGpioRxErr.instAddr = SOC_GPIO_0_REGS;
    tGpioRxErr.pinNum =  9;
    Board_initGPIO(&tGpioRxErr);
    GPIOPinWrite(tGpioRxErr.instAddr, tGpioRxErr.pinNum, GPIO_PIN_HIGH); 

    tGpioRxDv.instAddr = SOC_GPIO_0_REGS;
    tGpioRxDv.pinNum =  11;
    Board_initGPIO(&tGpioRxDv);
    GPIOPinWrite(tGpioRxDv.instAddr, tGpioRxDv.pinNum, GPIO_PIN_LOW); 
    
    Board_phyReset();

    Board_delay(10000);

    HWREG(SOC_CONTROL_REGS + 0x824) &= 0xFFFFFFF8; /* (T10) (COL) pin set to gpio0_23 */
    HWREG(SOC_CONTROL_REGS + 0x824) |= 0x5;
    HWREG(SOC_CONTROL_REGS + 0x8CC) &= 0xFFFFFFF8; /* (U4) (RX_D0) pin set to gpio2_17 */
    HWREG(SOC_CONTROL_REGS + 0x8CC) |= 0x5;
    HWREG(SOC_CONTROL_REGS + 0x8C8) &= 0xFFFFFFF8; /* (U3) (RX_D1) pin set to gpio2_16 */
    HWREG(SOC_CONTROL_REGS + 0x8C8) |= 0x5;
    HWREG(SOC_CONTROL_REGS + 0x8C4) &= 0xFFFFFFF8; /* (U2) (RX_D2) pin set to gpio2_15 */
    HWREG(SOC_CONTROL_REGS + 0x8C4) |= 0x5;
    HWREG(SOC_CONTROL_REGS + 0x8C0) &= 0xFFFFFFF8; /* (U1) (RX_D3) pin set to gpio2_14 */
    HWREG(SOC_CONTROL_REGS + 0x8C0) |= 0x5;
    HWREG(SOC_CONTROL_REGS + 0x8D0) &= 0xFFFFFFF8; /* (V2) (LED0) pin set to gpio0_8 */
    HWREG(SOC_CONTROL_REGS + 0x8D0) |= 0x5;
    HWREG(SOC_CONTROL_REGS + 0x8E8) &= 0xFFFFFFF8; /* (V5) (CRS) pin set to gpio2_24 */
    HWREG(SOC_CONTROL_REGS + 0x8E8) |= 0x5;
    HWREG(SOC_CONTROL_REGS + 0x8D4) &= 0xFFFFFFF8; /* (V3) (RX_ERR) pin set to gpio0_9 */
    HWREG(SOC_CONTROL_REGS + 0x8D4) |= 0x5;
    HWREG(SOC_CONTROL_REGS + 0x8DC) &= 0xFFFFFFF8; /* (T5) (RX_DV) pin set to gpio0_11 */
    HWREG(SOC_CONTROL_REGS + 0x8DC) |= 0x5;

    Board_delay(10000);

    return BOARD_SOK;
}

