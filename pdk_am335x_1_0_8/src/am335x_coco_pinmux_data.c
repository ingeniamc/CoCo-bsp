/**
 * Note: This file was auto-generated by TI PinMux on 8/28/2018 at 12:45:57 PM.
 *
 * \file  am335x_pinmux_data.c
 *
 * \brief  This file contains the pin mux configurations for the boards.
 *         These are prepared based on how the peripherals are extended on
 *         the boards.
 *
 * \copyright Copyright (CU) 2018 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/**
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
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "types.h"
#include "pinmux.h"
#include "am335x_pinmux.h"

/** Peripheral Pin Configurations */

#ifndef BUILDCFG_MOD_DCAN
#define BUILDCFG_MOD_DCAN
#endif /* BUILDCFG_MOD_DCAN */

#ifndef BUILDCFG_MOD_DEBUGSS
#define BUILDCFG_MOD_DEBUGSS
#endif /* BUILDCFG_MOD_DEBUGSS */

#ifndef BUILDCFG_MOD_EMIF
#define BUILDCFG_MOD_EMIF
#endif /* BUILDCFG_MOD_EMIF */

#ifndef BUILDCFG_MOD_GLUE
#define BUILDCFG_MOD_GLUE
#endif /* BUILDCFG_MOD_GLUE */

#ifndef BUILDCFG_MOD_GPIO
#define BUILDCFG_MOD_GPIO
#endif /* BUILDCFG_MOD_GPIO */

#ifndef BUILDCFG_MOD_I2C
#define BUILDCFG_MOD_I2C
#endif /* BUILDCFG_MOD_I2C */

#ifndef BUILDCFG_MOD_PRU_ICSS
#define BUILDCFG_MOD_PRU_ICSS
#endif /* BUILDCFG_MOD_PRU_ICSS */

#ifndef BUILDCFG_MOD_MMCSD
#define BUILDCFG_MOD_MMCSD
#endif /* BUILDCFG_MOD_MMCSD */

#ifndef BUILDCFG_MOD_OSC
#define BUILDCFG_MOD_OSC
#endif /* BUILDCFG_MOD_OSC */

#ifndef BUILDCFG_MOD_MCSPI
#define BUILDCFG_MOD_MCSPI
#endif /* BUILDCFG_MOD_MCSPI */

#ifndef BUILDCFG_MOD_UART
#define BUILDCFG_MOD_UART
#endif /* BUILDCFG_MOD_UART */

#ifndef BUILDCFG_MOD_USB
#define BUILDCFG_MOD_USB
#endif /* BUILDCFG_MOD_USB */


#if defined(BUILDCFG_MOD_DCAN)

static pinmuxPerCfg_t gDcan0PinCfg[] =
{
    {
       /* CAN -> dcan0_rx -> E16 */
       PIN_UART0_TXD, 0, \
       ( \
           PIN_MODE(2) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* CAN -> dcan0_tx -> E15 */
       PIN_UART0_RXD, 0, \
       ( \
           PIN_MODE(2) | \
           ((PIN_PULL_UD_EN) & (~PIN_PULL_TYPE_SEL & ~PIN_RX_ACTIVE)) \
       ) \
    },
    {PINMUX_INVALID_PIN}
};

static pinmuxModuleCfg_t gDcanPinCfg[] =
{
    {0, TRUE, gDcan0PinCfg},
    {CHIPDB_INVALID_INSTANCE_NUM}
};

#endif /* if defined(BUILDCFG_MOD_DCAN) */

#if defined(BUILDCFG_MOD_DEBUGSS)

static pinmuxPerCfg_t gDebugss0PinCfg[] =
{
    {
       /* JTAG -> TMS -> C11 */
       PIN_TMS, 0, \
       ( \
           PIN_MODE(0) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* JTAG -> TDI -> B11 */
       PIN_TDI, 0, \
       ( \
           PIN_MODE(0) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* JTAG -> TDO -> A11 */
       PIN_TDO, 0, \
       ( \
           PIN_MODE(0) | \
           ((PIN_PULL_UD_EN) & (~PIN_PULL_TYPE_SEL & ~PIN_RX_ACTIVE)) \
       ) \
    },
    {
       /* JTAG -> TCK -> A12 */
       PIN_TCK, 0, \
       ( \
           PIN_MODE(0) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* JTAG -> nTRST -> B10 */
       PIN_NTRST, 0, \
       ( \
           PIN_MODE(0) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* JTAG -> EMU0 -> C14 */
       PIN_EMU0, 0, \
       ( \
           PIN_MODE(0) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* JTAG -> EMU1 -> B14 */
       PIN_EMU1, 0, \
       ( \
           PIN_MODE(0) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {PINMUX_INVALID_PIN}
};

static pinmuxModuleCfg_t gDebugssPinCfg[] =
{
    {0, TRUE, gDebugss0PinCfg},
    {CHIPDB_INVALID_INSTANCE_NUM}
};

#endif /* if defined(BUILDCFG_MOD_DEBUGSS) */

#if defined(BUILDCFG_MOD_EMIF)

static pinmuxPerCfg_t gEmif4PinCfg[] =
{
    {PINMUX_INVALID_PIN}
};

static pinmuxModuleCfg_t gEmifPinCfg[] =
{
    {4, TRUE, gEmif4PinCfg},
    {CHIPDB_INVALID_INSTANCE_NUM}
};

#endif /* if defined(BUILDCFG_MOD_EMIF) */

#if defined(BUILDCFG_MOD_GLUE)

static pinmuxPerCfg_t gGlue0PinCfg[] =
{
    {PINMUX_INVALID_PIN}
};

static pinmuxModuleCfg_t gGluePinCfg[] =
{
    {0, TRUE, gGlue0PinCfg},
    {CHIPDB_INVALID_INSTANCE_NUM}
};

#endif /* if defined(BUILDCFG_MOD_GLUE) */

#if defined(BUILDCFG_MOD_GPIO)

static pinmuxPerCfg_t gGpio3PinCfg[] =
{
    {
       /* GPIOs3 -> gpio3[0] -> H16 */
       PIN_GMII1_COL, 0, \
       ( \
           PIN_MODE(7) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* GPIOs3 -> gpio3[1] -> H17 */
       PIN_GMII1_CRS, 1, \
       ( \
           PIN_MODE(7) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* GPIOs3 -> gpio3[2] -> J15 */
       PIN_GMII1_RXER, 2, \
       ( \
           PIN_MODE(7) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* GPIOs3 -> gpio3[3] -> J16 */
       PIN_GMII1_TXEN, 3, \
       ( \
           PIN_MODE(7) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* GPIOs3 -> gpio3[4] -> J17 */
       PIN_GMII1_RXDV, 4, \
       ( \
           PIN_MODE(7) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* GPIOs3 -> gpio3[9] -> K18 */
       PIN_GMII1_TXCLK, 9, \
       ( \
           PIN_MODE(7) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* GPIOs3 -> gpio3[10] -> L18 */
       PIN_GMII1_RXCLK, 10, \
       ( \
           PIN_MODE(7) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* GPIOs3 -> gpio3[13] -> F15 */
       PIN_USB1_DRVVBUS, 13, \
       ( \
           PIN_MODE(7) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* GPIOs3 -> gpio3[18] -> B12 */
       PIN_MCASP0_ACLKR, 18, \
       ( \
           PIN_MODE(7) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* GPIOs3 -> gpio3[19] -> C13 */
       PIN_MCASP0_FSR, 19, \
       ( \
           PIN_MODE(7) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* GPIOs3 -> gpio3[20] -> D13 */
       PIN_MCASP0_AXR1, 20, \
       ( \
           PIN_MODE(7) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {PINMUX_INVALID_PIN}
};

static pinmuxPerCfg_t gGpio0PinCfg[] =
{
    {
       /* GPIOs0 -> gpio0[0] -> M17 */
       PIN_MDIO_DATA, 0, \
       ( \
           PIN_MODE(7) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* GPIOs0 -> gpio0[1] -> M18 */
       PIN_MDIO_CLK, 1, \
       ( \
           PIN_MODE(7) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* GPIOs0 -> gpio0[7] -> C18 */
       PIN_ECAP0_IN_PWM0_OUT, 7, \
       ( \
           PIN_MODE(7) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* GPIOs0 -> gpio0[16] -> J18 */
       PIN_GMII1_TXD3, 16, \
       ( \
           PIN_MODE(7) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* GPIOs0 -> gpio0[17] -> K15 */
       PIN_GMII1_TXD2, 17, \
       ( \
           PIN_MODE(7) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* GPIOs0 -> gpio0[18] -> F16 */
       PIN_USB0_DRVVBUS, 18, \
       ( \
           PIN_MODE(7) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* GPIOs0 -> gpio0[19] -> A15 */
       PIN_XDMA_EVENT_INTR0, 19, \
       ( \
           PIN_MODE(7) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* GPIOs0 -> gpio0[20] -> D14 */
       PIN_XDMA_EVENT_INTR1, 20, \
       ( \
           PIN_MODE(7) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* GPIOs0 -> gpio0[21] -> K16 */
       PIN_GMII1_TXD1, 21, \
       ( \
           PIN_MODE(7) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* GPIOs0 -> gpio0[22] -> U10 */
       PIN_GPMC_AD8, 22, \
       ( \
           PIN_MODE(7) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* GPIOs0 -> gpio0[26] -> T11 */
       PIN_GPMC_AD10, 26, \
       ( \
           PIN_MODE(7) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* GPIOs0 -> gpio0[27] -> U12 */
       PIN_GPMC_AD11, 27, \
       ( \
           PIN_MODE(7) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* GPIOs0 -> gpio0[28] -> K17 */
       PIN_GMII1_TXD0, 28, \
       ( \
           PIN_MODE(7) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* GPIOs0 -> gpio0[29] -> H18 */
       PIN_RMII1_REFCLK, 29, \
       ( \
           PIN_MODE(7) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {PINMUX_INVALID_PIN}
};

static pinmuxPerCfg_t gGpio1PinCfg[] =
{
    {
       /* GPIOs1 -> gpio1[0] -> U7 */
       PIN_GPMC_AD0, 0, \
       ( \
           PIN_MODE(7) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* GPIOs1 -> gpio1[1] -> V7 */
       PIN_GPMC_AD1, 1, \
       ( \
           PIN_MODE(7) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* GPIOs1 -> gpio1[8] -> E18 */
       PIN_UART0_CTSN, 8, \
       ( \
           PIN_MODE(7) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* GPIOs1 -> gpio1[12] -> T12 */
       PIN_GPMC_AD12, 12, \
       ( \
           PIN_MODE(7) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* GPIOs1 -> gpio1[13] -> R12 */
       PIN_GPMC_AD13, 13, \
       ( \
           PIN_MODE(7) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* GPIOs1 -> gpio1[29] -> V6 */
       PIN_GPMC_CSN0, 29, \
       ( \
           PIN_MODE(7) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* GPIOs1 -> gpio1[30] -> U9 */
       PIN_GPMC_CSN1, 30, \
       ( \
           PIN_MODE(7) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {PINMUX_INVALID_PIN}
};

static pinmuxPerCfg_t gGpio2PinCfg[] =
{
    {
       /* GPIOs2 -> gpio2[5] -> T6 */
       PIN_GPMC_BE0N_CLE, 5, \
       ( \
           PIN_MODE(7) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* GPIOs2 -> gpio2[18] -> L17 */
       PIN_GMII1_RXD3, 18, \
       ( \
           PIN_MODE(7) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* GPIOs2 -> gpio2[19] -> L16 */
       PIN_GMII1_RXD2, 19, \
       ( \
           PIN_MODE(7) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* GPIOs2 -> gpio2[20] -> L15 */
       PIN_GMII1_RXD1, 20, \
       ( \
           PIN_MODE(7) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* GPIOs2 -> gpio2[21] -> M16 */
       PIN_GMII1_RXD0, 21, \
       ( \
           PIN_MODE(7) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* GPIOs2 -> gpio2[23] -> R5 */
       PIN_LCD_HSYNC, 23, \
       ( \
           PIN_MODE(7) | \
           ((PIN_PULL_TYPE_SEL | PIN_RX_ACTIVE) & (~PIN_PULL_UD_EN)) \
       ) \
    },
    {PINMUX_INVALID_PIN}
};

static pinmuxModuleCfg_t gGpioPinCfg[] =
{
    {3, TRUE, gGpio3PinCfg},
    {0, TRUE, gGpio0PinCfg},
    {1, TRUE, gGpio1PinCfg},
    {2, TRUE, gGpio2PinCfg},
    {CHIPDB_INVALID_INSTANCE_NUM}
};

#endif /* if defined(BUILDCFG_MOD_GPIO) */

#if defined(BUILDCFG_MOD_I2C)

static pinmuxPerCfg_t gI2c0PinCfg[] =
{
    {
       /* I2C ECAT EEPROM -> I2C0_SCL -> C16 */
       PIN_I2C0_SCL, 0, \
       ( \
           PIN_MODE(0) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* I2C ECAT EEPROM -> I2C0_SDA -> C17 */
       PIN_I2C0_SDA, 0, \
       ( \
           PIN_MODE(0) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {PINMUX_INVALID_PIN}
};

static pinmuxPerCfg_t gI2c2PinCfg[] =
{
    {
       /* I2C EXT -> I2C2_SCL -> D17 */
       PIN_UART1_RTSN, 0, \
       ( \
           PIN_MODE(3) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* I2C EXT -> I2C2_SDA -> D18 */
       PIN_UART1_CTSN, 0, \
       ( \
           PIN_MODE(3) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {PINMUX_INVALID_PIN}
};

static pinmuxModuleCfg_t gI2cPinCfg[] =
{
    {0, TRUE, gI2c0PinCfg},
    {2, TRUE, gI2c2PinCfg},
    {CHIPDB_INVALID_INSTANCE_NUM}
};

#endif /* if defined(BUILDCFG_MOD_I2C) */

#if defined(BUILDCFG_MOD_PRU_ICSS)

static pinmuxPerCfg_t gPru_icss1PinCfg[] =
{
    {
       /* MyMDIO_PRUSS12 -> pr1_mdio_mdclk -> V12 */
       PIN_GPMC_CLK, (uint16_t)PINMUX_SS_PRU_ICSS_MDIO, \
       ( \
           PIN_MODE(5) | \
           ((PIN_PULL_UD_EN) & (~PIN_PULL_TYPE_SEL & ~PIN_RX_ACTIVE)) \
       ) \
    },
    {
       /* MyMDIO_PRUSS12 -> pr1_mdio_data -> T13 */
       PIN_GPMC_CSN3, (uint16_t)PINMUX_SS_PRU_ICSS_MDIO, \
       ( \
           PIN_MODE(5) | \
           ((PIN_PULL_TYPE_SEL | PIN_RX_ACTIVE) & (~PIN_PULL_UD_EN)) \
       ) \
    },
    {
       /* PHY0 -> pr1_mii_mt0_clk -> R1 */
       PIN_LCD_DATA0, (uint16_t)PINMUX_SS_PRU_ICSS_MII0, \
       ( \
           PIN_MODE(2) | \
           ((PIN_RX_ACTIVE) & (~PIN_PULL_UD_EN & ~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* PHY0 -> pr1_mii0_txd0 -> T2 */
       PIN_LCD_DATA5, (uint16_t)PINMUX_SS_PRU_ICSS_MII0, \
       ( \
           PIN_MODE(2) | \
           ((PIN_PULL_UD_EN) & (~PIN_PULL_TYPE_SEL & ~PIN_RX_ACTIVE)) \
       ) \
    },
    {
       /* PHY0 -> pr1_mii0_txd1 -> T1 */
       PIN_LCD_DATA4, (uint16_t)PINMUX_SS_PRU_ICSS_MII0, \
       ( \
           PIN_MODE(2) | \
           ((PIN_PULL_UD_EN) & (~PIN_PULL_TYPE_SEL & ~PIN_RX_ACTIVE)) \
       ) \
    },
    {
       /* PHY0 -> pr1_mii0_txd2 -> R4 */
       PIN_LCD_DATA3, (uint16_t)PINMUX_SS_PRU_ICSS_MII0, \
       ( \
           PIN_MODE(2) | \
           ((PIN_PULL_UD_EN) & (~PIN_PULL_TYPE_SEL & ~PIN_RX_ACTIVE)) \
       ) \
    },
    {
       /* PHY0 -> pr1_mii0_txd3 -> R3 */
       PIN_LCD_DATA2, (uint16_t)PINMUX_SS_PRU_ICSS_MII0, \
       ( \
           PIN_MODE(2) | \
           ((PIN_PULL_UD_EN) & (~PIN_PULL_TYPE_SEL & ~PIN_RX_ACTIVE)) \
       ) \
    },
    {
       /* PHY0 -> pr1_mii0_rxd0 -> U4 */
       PIN_LCD_DATA11, (uint16_t)PINMUX_SS_PRU_ICSS_MII0, \
       ( \
           PIN_MODE(5) | \
           ((PIN_PULL_TYPE_SEL | PIN_RX_ACTIVE) & (~PIN_PULL_UD_EN)) \
       ) \
    },
    {
       /* PHY0 -> pr1_mii0_rxd1 -> U3 */
       PIN_LCD_DATA10, (uint16_t)PINMUX_SS_PRU_ICSS_MII0, \
       ( \
           PIN_MODE(5) | \
           ((PIN_RX_ACTIVE) & (~PIN_PULL_UD_EN & ~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* PHY0 -> pr1_mii0_rxd2 -> U2 */
       PIN_LCD_DATA9, (uint16_t)PINMUX_SS_PRU_ICSS_MII0, \
       ( \
           PIN_MODE(5) | \
           ((PIN_RX_ACTIVE) & (~PIN_PULL_UD_EN & ~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* PHY0 -> pr1_mii0_rxd3 -> U1 */
       PIN_LCD_DATA8, (uint16_t)PINMUX_SS_PRU_ICSS_MII0, \
       ( \
           PIN_MODE(5) | \
           ((PIN_PULL_TYPE_SEL | PIN_RX_ACTIVE) & (~PIN_PULL_UD_EN)) \
       ) \
    },
    {
       /* PHY0 -> pr1_mii0_txen -> R2 */
       PIN_LCD_DATA1, (uint16_t)PINMUX_SS_PRU_ICSS_MII0, \
       ( \
           PIN_MODE(2) | \
           ((PIN_PULL_UD_EN) & (~PIN_PULL_TYPE_SEL & ~PIN_RX_ACTIVE)) \
       ) \
    },
    {
       /* PHY0 -> pr1_mii_mr0_clk -> V4 */
       PIN_LCD_DATA14, (uint16_t)PINMUX_SS_PRU_ICSS_MII0, \
       ( \
           PIN_MODE(5) | \
           ((PIN_PULL_TYPE_SEL | PIN_RX_ACTIVE) & (~PIN_PULL_UD_EN)) \
       ) \
    },
    {
       /* PHY0 -> pr1_mii0_rxdv -> T5 */
       PIN_LCD_DATA15, (uint16_t)PINMUX_SS_PRU_ICSS_MII0, \
       ( \
           PIN_MODE(5) | \
           ((PIN_RX_ACTIVE) & (~PIN_PULL_UD_EN & ~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* PHY0 -> pr1_mii0_rxer -> V3 */
       PIN_LCD_DATA13, (uint16_t)PINMUX_SS_PRU_ICSS_MII0, \
       ( \
           PIN_MODE(5) | \
           ((PIN_RX_ACTIVE) & (~PIN_PULL_UD_EN & ~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* PHY0 -> pr1_mii0_rxlink -> V2 */
       PIN_LCD_DATA12, (uint16_t)PINMUX_SS_PRU_ICSS_MII0, \
       ( \
           PIN_MODE(5) | \
           ((PIN_RX_ACTIVE) & (~PIN_PULL_UD_EN & ~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* PHY0 -> pr1_mii0_crs -> V5 */
       PIN_LCD_PCLK, (uint16_t)PINMUX_SS_PRU_ICSS_MII0, \
       ( \
           PIN_MODE(2) | \
           ((PIN_PULL_TYPE_SEL | PIN_RX_ACTIVE) & (~PIN_PULL_UD_EN)) \
       ) \
    },
    {
       /* PHY0 -> pr1_mii0_col -> T10 */
       PIN_GPMC_AD9, (uint16_t)PINMUX_SS_PRU_ICSS_MII0, \
       ( \
           PIN_MODE(5) | \
           ((PIN_PULL_TYPE_SEL | PIN_RX_ACTIVE) & (~PIN_PULL_UD_EN)) \
       ) \
    },
    {
       /* PHY1 -> pr1_mii_mt1_clk -> R13 */
       PIN_GPMC_A0, (uint16_t)PINMUX_SS_PRU_ICSS_MII1, \
       ( \
           PIN_MODE(5) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* PHY1 -> pr1_mii1_txd0 -> R14 */
       PIN_GPMC_A4, (uint16_t)PINMUX_SS_PRU_ICSS_MII1, \
       ( \
           PIN_MODE(5) | \
           ((PIN_PULL_UD_EN) & (~PIN_PULL_TYPE_SEL & ~PIN_RX_ACTIVE)) \
       ) \
    },
    {
       /* PHY1 -> pr1_mii1_txd1 -> T14 */
       PIN_GPMC_A3, (uint16_t)PINMUX_SS_PRU_ICSS_MII1, \
       ( \
           PIN_MODE(5) | \
           ((PIN_PULL_UD_EN) & (~PIN_PULL_TYPE_SEL & ~PIN_RX_ACTIVE)) \
       ) \
    },
    {
       /* PHY1 -> pr1_mii1_txd2 -> U14 */
       PIN_GPMC_A2, (uint16_t)PINMUX_SS_PRU_ICSS_MII1, \
       ( \
           PIN_MODE(5) | \
           ((PIN_PULL_UD_EN) & (~PIN_PULL_TYPE_SEL & ~PIN_RX_ACTIVE)) \
       ) \
    },
    {
       /* PHY1 -> pr1_mii1_txd3 -> V14 */
       PIN_GPMC_A1, (uint16_t)PINMUX_SS_PRU_ICSS_MII1, \
       ( \
           PIN_MODE(5) | \
           ((PIN_PULL_UD_EN) & (~PIN_PULL_TYPE_SEL & ~PIN_RX_ACTIVE)) \
       ) \
    },
    {
       /* PHY1 -> pr1_mii1_rxd0 -> V16 */
       PIN_GPMC_A8, (uint16_t)PINMUX_SS_PRU_ICSS_MII1, \
       ( \
           PIN_MODE(5) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* PHY1 -> pr1_mii1_rxd1 -> T15 */
       PIN_GPMC_A7, (uint16_t)PINMUX_SS_PRU_ICSS_MII1, \
       ( \
           PIN_MODE(5) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* PHY1 -> pr1_mii1_rxd2 -> U15 */
       PIN_GPMC_A6, (uint16_t)PINMUX_SS_PRU_ICSS_MII1, \
       ( \
           PIN_MODE(5) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* PHY1 -> pr1_mii1_rxd3 -> V15 */
       PIN_GPMC_A5, (uint16_t)PINMUX_SS_PRU_ICSS_MII1, \
       ( \
           PIN_MODE(5) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* PHY1 -> pr1_mii1_txen -> U17 */
       PIN_GPMC_WPN, (uint16_t)PINMUX_SS_PRU_ICSS_MII1, \
       ( \
           PIN_MODE(5) | \
           ((PIN_PULL_UD_EN) & (~PIN_PULL_TYPE_SEL & ~PIN_RX_ACTIVE)) \
       ) \
    },
    {
       /* PHY1 -> pr1_mii_mr1_clk -> U16 */
       PIN_GPMC_A9, (uint16_t)PINMUX_SS_PRU_ICSS_MII1, \
       ( \
           PIN_MODE(5) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* PHY1 -> pr1_mii1_rxdv -> T16 */
       PIN_GPMC_A10, (uint16_t)PINMUX_SS_PRU_ICSS_MII1, \
       ( \
           PIN_MODE(5) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* PHY1 -> pr1_mii1_rxer -> V17 */
       PIN_GPMC_A11, (uint16_t)PINMUX_SS_PRU_ICSS_MII1, \
       ( \
           PIN_MODE(5) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* PHY1 -> pr1_mii1_rxlink -> U18 */
       PIN_GPMC_BE1N, (uint16_t)PINMUX_SS_PRU_ICSS_MII1, \
       ( \
           PIN_MODE(5) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* PHY1 -> pr1_mii1_crs -> R6 */
       PIN_LCD_AC_BIAS_EN, (uint16_t)PINMUX_SS_PRU_ICSS_MII1, \
       ( \
           PIN_MODE(2) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* PHY1 -> pr1_mii1_col -> T17 */
       PIN_GPMC_WAIT0, (uint16_t)PINMUX_SS_PRU_ICSS_MII1, \
       ( \
           PIN_MODE(5) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {PINMUX_INVALID_PIN}
};

static pinmuxModuleCfg_t gPru_icssPinCfg[] =
{
    {1, TRUE, gPru_icss1PinCfg},
    {CHIPDB_INVALID_INSTANCE_NUM}
};

#endif /* if defined(BUILDCFG_MOD_PRU_ICSS) */

#if defined(BUILDCFG_MOD_MMCSD)

static pinmuxPerCfg_t gMmcsd0PinCfg[] =
{
    {
       /* SDCARD -> mmc0_clk -> G17 */
       PIN_MMC0_CLK, 0, \
       ( \
           PIN_MODE(0) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* SDCARD -> mmc0_cmd -> G18 */
       PIN_MMC0_CMD, 0, \
       ( \
           PIN_MODE(0) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* SDCARD -> mmc0_dat0 -> G16 */
       PIN_MMC0_DAT0, 0, \
       ( \
           PIN_MODE(0) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* SDCARD -> mmc0_dat1 -> G15 */
       PIN_MMC0_DAT1, 0, \
       ( \
           PIN_MODE(0) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* SDCARD -> mmc0_dat2 -> F18 */
       PIN_MMC0_DAT2, 0, \
       ( \
           PIN_MODE(0) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* SDCARD -> mmc0_dat3 -> F17 */
       PIN_MMC0_DAT3, 0, \
       ( \
           PIN_MODE(0) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {PINMUX_INVALID_PIN}
};

static pinmuxModuleCfg_t gMmcsdPinCfg[] =
{
    {0, TRUE, gMmcsd0PinCfg},
    {CHIPDB_INVALID_INSTANCE_NUM}
};

#endif /* if defined(BUILDCFG_MOD_MMCSD) */

#if defined(BUILDCFG_MOD_OSC)

static pinmuxPerCfg_t gOsc0PinCfg[] =
{
    {PINMUX_INVALID_PIN}
};

static pinmuxModuleCfg_t gOscPinCfg[] =
{
    {0, TRUE, gOsc0PinCfg},
    {CHIPDB_INVALID_INSTANCE_NUM}
};

#endif /* if defined(BUILDCFG_MOD_OSC) */

#if defined(BUILDCFG_MOD_MCSPI)

static pinmuxPerCfg_t gMcspi1PinCfg[] =
{
    {
       /* MCB SPI -> spi1_sclk -> A13 */
       PIN_MCASP0_ACLKX, 0, \
       ( \
           PIN_MODE(3) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* MCB SPI -> spi1_d0 -> B13 */
       PIN_MCASP0_FSX, 0, \
       ( \
           PIN_MODE(3) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* MCB SPI -> spi1_d1 -> D12 */
       PIN_MCASP0_AXR0, 0, \
       ( \
           PIN_MODE(3) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* MCB SPI -> spi1_cs0 -> C12 */
       PIN_MCASP0_AHCLKR, 0, \
       ( \
           PIN_MODE(3) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {PINMUX_INVALID_PIN}
};

static pinmuxPerCfg_t gMcspi0PinCfg[] =
{
    {
       /* FLASH SPI -> spi0_sclk -> A17 */
       PIN_SPI0_SCLK, 0, \
       ( \
           PIN_MODE(0) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* FLASH SPI -> spi0_d0 -> B17 */
       PIN_SPI0_D0, 0, \
       ( \
           PIN_MODE(0) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* FLASH SPI -> spi0_d1 -> B16 */
       PIN_SPI0_D1, 0, \
       ( \
           PIN_MODE(0) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* FLASH SPI -> spi0_cs0 -> A16 */
       PIN_SPI0_CS0, 0, \
       ( \
           PIN_MODE(0) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* FLASH SPI -> spi0_cs1 -> C15 */
       PIN_SPI0_CS1, 0, \
       ( \
           PIN_MODE(0) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {PINMUX_INVALID_PIN}
};

static pinmuxModuleCfg_t gMcspiPinCfg[] =
{
    {1, TRUE, gMcspi1PinCfg},
    {0, TRUE, gMcspi0PinCfg},
    {CHIPDB_INVALID_INSTANCE_NUM}
};

#endif /* if defined(BUILDCFG_MOD_MCSPI) */

#if defined(BUILDCFG_MOD_UART)

static pinmuxPerCfg_t gUart1PinCfg[] =
{
    {
       /* UART1 -> uart1_rxd -> D16 */
       PIN_UART1_RXD, 0, \
       ( \
           PIN_MODE(0) | \
           ((PIN_PULL_UD_EN | PIN_RX_ACTIVE) & (~PIN_PULL_TYPE_SEL)) \
       ) \
    },
    {
       /* UART1 -> uart1_txd -> D15 */
       PIN_UART1_TXD, 0, \
       ( \
           PIN_MODE(0) | \
           ((PIN_PULL_UD_EN) & (~PIN_PULL_TYPE_SEL & ~PIN_RX_ACTIVE)) \
       ) \
    },
    {PINMUX_INVALID_PIN}
};

static pinmuxModuleCfg_t gUartPinCfg[] =
{
    {1, TRUE, gUart1PinCfg},
    {CHIPDB_INVALID_INSTANCE_NUM}
};

#endif /* if defined(BUILDCFG_MOD_UART) */

#if defined(BUILDCFG_MOD_USB)

static pinmuxPerCfg_t gUsb0PinCfg[] =
{
    {PINMUX_INVALID_PIN}
};

static pinmuxModuleCfg_t gUsbPinCfg[] =
{
    {0, TRUE, gUsb0PinCfg},
    {CHIPDB_INVALID_INSTANCE_NUM}
};

#endif /* if defined(BUILDCFG_MOD_USB) */


pinmuxBoardCfg_t gCocoPinmuxData[] =
{
#if defined(BUILDCFG_MOD_DCAN)
    {CHIPDB_MOD_ID_DCAN, gDcanPinCfg},
#endif /* if defined(BUILDCFG_MOD_DCAN) */
#if defined(BUILDCFG_MOD_DEBUGSS)
    {CHIPDB_MOD_ID_DEBUGSS, gDebugssPinCfg},
#endif /* if defined(BUILDCFG_MOD_DEBUGSS) */
#if defined(BUILDCFG_MOD_EMIF)
    {CHIPDB_MOD_ID_EMIF, gEmifPinCfg},
#endif /* if defined(BUILDCFG_MOD_EMIF) */
#if defined(BUILDCFG_MOD_GLUE)
    {CHIPDB_MOD_ID_GLUE, gGluePinCfg},
#endif /* if defined(BUILDCFG_MOD_GLUE) */
#if defined(BUILDCFG_MOD_GPIO)
    {CHIPDB_MOD_ID_GPIO, gGpioPinCfg},
#endif /* if defined(BUILDCFG_MOD_GPIO) */
#if defined(BUILDCFG_MOD_I2C)
    {CHIPDB_MOD_ID_I2C, gI2cPinCfg},
#endif /* if defined(BUILDCFG_MOD_I2C) */
#if defined(BUILDCFG_MOD_PRU_ICSS)
    {CHIPDB_MOD_ID_PRU_ICSS, gPru_icssPinCfg},
#endif /* if defined(BUILDCFG_MOD_PRU_ICSS) */
#if defined(BUILDCFG_MOD_MMCSD)
    {CHIPDB_MOD_ID_MMCSD, gMmcsdPinCfg},
#endif /* if defined(BUILDCFG_MOD_MMCSD) */
#if defined(BUILDCFG_MOD_OSC)
    {CHIPDB_MOD_ID_OSC, gOscPinCfg},
#endif /* if defined(BUILDCFG_MOD_OSC) */
#if defined(BUILDCFG_MOD_MCSPI)
    {CHIPDB_MOD_ID_MCSPI, gMcspiPinCfg},
#endif /* if defined(BUILDCFG_MOD_MCSPI) */
#if defined(BUILDCFG_MOD_UART)
    {CHIPDB_MOD_ID_UART, gUartPinCfg},
#endif /* if defined(BUILDCFG_MOD_UART) */
#if defined(BUILDCFG_MOD_USB)
    {CHIPDB_MOD_ID_USB, gUsbPinCfg},
#endif /* if defined(BUILDCFG_MOD_USB) */
    {CHIPDB_MOD_ID_INVALID}
};
