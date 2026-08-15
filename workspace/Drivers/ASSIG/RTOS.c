/*
 * RTOS.c
 *
 *  Requirement:
 *      Use I2C communication to store a value in EEPROM and retrieve it every
 *      time the microcontroller is reset using the RTOS driver.
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/TWI/TWI_int.h"
#include "../RTOS/RTOS_int.h"

#define EEPROM_SLA     0x50U
#define EEPROM_ADDR    0x10U
#define EEPROM_VALUE   0xABU

static volatile u8 g_u8EEPROMValue = 0;

static void vEEPROM_WriteValue(void)
{
    u8 L_u8Status = 0;

    L_u8Status = MTWI_u8SendStartCondition();
    if(L_u8Status != 0x08U)
    {
        return;
    }

    L_u8Status = MTWI_u8SendSLA_RW(EEPROM_SLA, TWI_WRITE);
    if(L_u8Status != 0x18U)
    {
        MTWI_u8SendEndCondition();
        return;
    }

    L_u8Status = MTWI_u8SendByte(EEPROM_ADDR);
    if(L_u8Status != 0x28U)
    {
        MTWI_u8SendEndCondition();
        return;
    }

    L_u8Status = MTWI_u8SendByte(EEPROM_VALUE);
    if(L_u8Status != 0x28U)
    {
        MTWI_u8SendEndCondition();
        return;
    }

    MTWI_u8SendEndCondition();
}

static void vEEPROM_ReadValue(void)
{
    u8 L_u8Status = 0;
    u8 L_u8Data = 0;

    L_u8Status = MTWI_u8SendStartCondition();
    if(L_u8Status != 0x08U)
    {
        return;
    }

    L_u8Status = MTWI_u8SendSLA_RW(EEPROM_SLA, TWI_WRITE);
    if(L_u8Status != 0x18U)
    {
        MTWI_u8SendEndCondition();
        return;
    }

    L_u8Status = MTWI_u8SendByte(EEPROM_ADDR);
    if(L_u8Status != 0x28U)
    {
        MTWI_u8SendEndCondition();
        return;
    }

    L_u8Status = MTWI_u8ReSendStartCondition();
    if(L_u8Status != 0x10U)
    {
        MTWI_u8SendEndCondition();
        return;
    }

    L_u8Status = MTWI_u8SendSLA_RW(EEPROM_SLA, TWI_READ);
    if(L_u8Status != 0x40U)
    {
        MTWI_u8SendEndCondition();
        return;
    }

    L_u8Status = MTWI_u8RecevieByte(&L_u8Data, TWI_NACK);
    if(L_u8Status != 0x58U)
    {
        MTWI_u8SendEndCondition();
        return;
    }

    MTWI_u8SendEndCondition();
    g_u8EEPROMValue = L_u8Data;
}

static void vStore_EEPROM_Task(void)
{
    static u8 L_u8FirstRun = 1;

    if(L_u8FirstRun == 1U)
    {
        L_u8FirstRun = 0U;
        vEEPROM_WriteValue();
    }
}

static void vRead_EEPROM_Task(void)
{
    vEEPROM_ReadValue();
}

int main(void)
{
    MTWI_vInit();

    RTOS_u8CreateTask(vStore_EEPROM_Task, 1, 0, 0);
    RTOS_u8CreateTask(vRead_EEPROM_Task, 1, 1, 1);

    RTOS_vStartOS();

    while(1)
    {
    }

    return 0;
}
