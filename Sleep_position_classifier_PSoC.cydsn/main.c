/* ===============================================
 *
 * Alfonzo Massimo, Canavate Chloé, Franke Patrick
 * Project 05 - Sleep Position Classifier
 * Electronic Technologies and Biosensor Laboratory
 * Academic year 2021 - 2022
 * main.c file
 *
 * =============================================== */


#include <stdio.h>
#include "project.h"
#include "I2C_Interface.h"
#include "LIS3DH.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    I2C_Peripheral_Start();
    UART_BT_Start();

    CyDelay(5); // The boot procedure is complete about 5 ms after device power-up.

    // Bluetooth communication check
    UART_BT_PutString("UART BT: Communication started.\r\n");

    
    // CyDelay(100);
    
    // String to print out messages on the UART_BT
    char message[50] = {'\0'};
    
    // Read and write all the registers 
        // CTRL REG 1   (0x20)
    uint8_t ctrl_reg_1_acc_1;
    uint8_t ctrl_reg_1_acc_2;
    
    ErrorCode error_acc1 = I2C_Peripheral_ReadRegister(LIS3DH_1_DEVICE_ADDRESS, 
                                                    LIS3DH_CTRL_REG1,
                                                    &ctrl_reg_1_acc_1);
    ErrorCode error_acc2 = I2C_Peripheral_ReadRegister(LIS3DH_2_DEVICE_ADDRESS, 
                                                    LIS3DH_CTRL_REG1,
                                                    &ctrl_reg_1_acc_2);
        
            // Acc 1 reading
    if (error_acc1 == NO_ERROR) 
    {
        sprintf(message, "CTRL REG 1 value - Accelerometer 1: 0x%02X\r\n", ctrl_reg_1_acc_1);
        UART_BT_PutString(message);
    }
    else
    {
        UART_BT_PutString("I2C error while reading CTRL REG 1 - Accelerometer 1\r\n");
    }
            // Acc 2 reading
    if (error_acc2 == NO_ERROR) 
    {
        sprintf(message, "CTRL REG 1 value - Accelerometer 2: 0x%02X\r\n", ctrl_reg_1_acc_2);
        UART_BT_PutString(message);
    }
    else
    {
        UART_BT_PutString("I2C error while reading CTRL REG 1 - Accelerometer 2\r\n");
    }
    
            // Acc 1 writing if necessary
    if (ctrl_reg_1_acc_1 != LIS3DH_NORMAL_MODE_CTRL_REG1)
    {
        ctrl_reg_1_acc_1 = LIS3DH_NORMAL_MODE_CTRL_REG1;
        
        error_acc1 = I2C_Peripheral_WriteRegister(LIS3DH_1_DEVICE_ADDRESS,
                                                  LIS3DH_CTRL_REG1,
                                                  ctrl_reg_1_acc_1);
        
        if (error_acc1 == NO_ERROR)
        {
            sprintf(message, "\r\nCTRL REG 1 - Accelerometer 1 successfully written as: 0x%02X\r\n", ctrl_reg_1_acc_1);
            UART_BT_PutString(message);
        }
        else
        {
            UART_BT_PutString("\r\nI2C error while writing CTRL REG 1 - Accelerometer 1\r\n");
        }
    }

            // Acc 2 writing if necessary
    if (ctrl_reg_1_acc_2 != LIS3DH_NORMAL_MODE_CTRL_REG1)
    {
        ctrl_reg_1_acc_2 = LIS3DH_NORMAL_MODE_CTRL_REG1;
        
        error_acc2 = I2C_Peripheral_WriteRegister(LIS3DH_2_DEVICE_ADDRESS,
                                                  LIS3DH_CTRL_REG1,
                                                  ctrl_reg_1_acc_2);
        
        if (error_acc2 == NO_ERROR)
        {
            sprintf(message, "\r\nCTRL REG 1 - Accelerometer 2 successfully written as: 0x%02X\r\n", ctrl_reg_1_acc_2);
            UART_BT_PutString(message);
        }
        else
        {
            UART_BT_PutString("\r\nI2C error while writing CTRL REG 1 - Accelerometer 2\r\n");
        }
    }
    
        // CTRL REG 5   (0x24)
    uint8_t ctrl_reg_5_acc_1;
    uint8_t ctrl_reg_5_acc_2;
    
    error_acc1 = I2C_Peripheral_ReadRegister(LIS3DH_1_DEVICE_ADDRESS, 
                                             LIS3DH_CTRL_REG5,
                                             &ctrl_reg_5_acc_1);
    error_acc2 = I2C_Peripheral_ReadRegister(LIS3DH_2_DEVICE_ADDRESS, 
                                             LIS3DH_CTRL_REG5,
                                             &ctrl_reg_5_acc_2);
    
            // Acc 1 reading
    if (error_acc1 == NO_ERROR) 
    {
        sprintf(message, "CTRL REG 5 value - Accelerometer 1: 0x%02X\r\n", ctrl_reg_5_acc_1);
        UART_BT_PutString(message);
    }
    else
    {
        UART_BT_PutString("I2C error while reading CTRL REG 5 - Accelerometer 1\r\n");
    }
            // Acc 2 reading
    if (error_acc2 == NO_ERROR) 
    {
        sprintf(message, "CTRL REG 5 value - Accelerometer 2: 0x%02X\r\n", ctrl_reg_5_acc_2);
        UART_BT_PutString(message);
    }
    else
    {
        UART_BT_PutString("I2C error while reading CTRL REG 5 - Accelerometer 2\r\n");
    }
    
            // Acc 1 writing if necessary
    if (ctrl_reg_5_acc_1 != LIS3DH_NORMAL_MODE_CTRL_REG5)
    {
        ctrl_reg_5_acc_1 = LIS3DH_NORMAL_MODE_CTRL_REG5;
        
        error_acc1 = I2C_Peripheral_WriteRegister(LIS3DH_1_DEVICE_ADDRESS,
                                                  LIS3DH_CTRL_REG5,
                                                  ctrl_reg_5_acc_1);
        
        if (error_acc1 == NO_ERROR)
        {
            sprintf(message, "\r\nCTRL REG 5 - Accelerometer 1 successfully written as: 0x%02X\r\n", ctrl_reg_5_acc_1);
            UART_BT_PutString(message);
        }
        else
        {
            UART_BT_PutString("\r\nI2C error while writing CTRL REG 5 - Accelerometer 1\r\n");
        }
    }
            // Acc 2 writing if necessary
    if (ctrl_reg_5_acc_2 != LIS3DH_NORMAL_MODE_CTRL_REG5)
    {
        ctrl_reg_5_acc_2 = LIS3DH_NORMAL_MODE_CTRL_REG5;
        
        error_acc2 = I2C_Peripheral_WriteRegister(LIS3DH_2_DEVICE_ADDRESS,
                                                  LIS3DH_CTRL_REG5,
                                                  ctrl_reg_5_acc_2);
        
        if (error_acc2 == NO_ERROR)
        {
            sprintf(message, "\r\nCTRL REG 5 - Accelerometer 2 successfully written as: 0x%02X\r\n", ctrl_reg_5_acc_2);
            UART_BT_PutString(message);
        }
        else
        {
            UART_BT_PutString("\r\nI2C error while writing CTRL REG 5 - Accelerometer 2\r\n");
        }
    }
    
        //FIFO CTRL REG     (0x2E)
    uint8_t fifo_ctrl_reg_acc_1;
    uint8_t fifo_ctrl_reg_acc_2;
    error_acc1 = I2C_Peripheral_ReadRegister(LIS3DH_1_DEVICE_ADDRESS, 
                                             LIS3DH_FIFO_CTRL_REG,
                                             &fifo_ctrl_reg_acc_1);
    error_acc2 = I2C_Peripheral_ReadRegister(LIS3DH_2_DEVICE_ADDRESS, 
                                             LIS3DH_FIFO_CTRL_REG,
                                             &fifo_ctrl_reg_acc_2);
    
            // Acc 1 reading
    if (error_acc1 == NO_ERROR)
    {
        sprintf(message, "FIFO CTRL REG value - Accelerometer 1: 0x%02X\r\n", fifo_ctrl_reg_acc_1);
        UART_BT_PutString(message);
    }
    else
    {
        UART_BT_PutString("I2C error while reading FIFO CTRL REG - Accelerometer 1\r\n");
    }
            // Acc 2 reading
    if (error_acc2 == NO_ERROR )
    {
        sprintf(message, "FIFO CTRL REG value - Accelerometer 2: 0x%02X\r\n", fifo_ctrl_reg_acc_2);
        UART_BT_PutString(message);
    }
    else
    {
        UART_BT_PutString("I2C error while reading FIFO CTRL REG - Accelerometer 2\r\n");
    }
    
            // Acc 1 writing if necessary
    if (fifo_ctrl_reg_acc_1 != LIS3DH_BYPASS_MODE)
    {
        fifo_ctrl_reg_acc_1 = LIS3DH_BYPASS_MODE;
        
        error_acc1 = I2C_Peripheral_WriteRegister(LIS3DH_1_DEVICE_ADDRESS,
                                                  LIS3DH_FIFO_CTRL_REG,
                                                  fifo_ctrl_reg_acc_1);
            
        if (error_acc1 == NO_ERROR)
        {
            sprintf(message, "\r\nFIFO CTRL REG - Accelerometer 1 successfully written as: 0x%02X\r\n", fifo_ctrl_reg_acc_1);
            UART_BT_PutString(message);
        }
        else
        {
            UART_BT_PutString("\r\nI2C error while writing FIFO CTRL REG - Accelerometer 1\r\n");
        }
    }
            // Acc 2 writing if necessary
    if (fifo_ctrl_reg_acc_2 != LIS3DH_BYPASS_MODE)
    {
        fifo_ctrl_reg_acc_2 = LIS3DH_BYPASS_MODE;
        
        error_acc2 = I2C_Peripheral_WriteRegister(LIS3DH_2_DEVICE_ADDRESS,
                                                  LIS3DH_FIFO_CTRL_REG,
                                                  fifo_ctrl_reg_acc_2);
        
        if (error_acc2 == NO_ERROR)
        {
            sprintf(message, "\r\nFIFO CTRL REG - Accelerometer 2 successfully written as: 0x%02X\r\n", fifo_ctrl_reg_acc_2);
            UART_BT_PutString(message);
        }
        else
        {
            UART_BT_PutString("\r\nI2C error while writing FIFO CTRL REG - Accelerometer 2\r\n");
        }
    }


    // Sample the data
    int16_t register_count = 192;
    uint8_t Acc1_data[192];
    uint8_t Acc2_data[192];
    uint8_t fifo_full_2;
    uint8_t fifo_full_1;

        // Switch the 2 accelerometers to FIFO mode
    error_acc2 = I2C_Peripheral_WriteRegister(LIS3DH_2_DEVICE_ADDRESS,
                                              LIS3DH_FIFO_CTRL_REG,
                                              LIS3DH_FIFO_MODE_CTRL_REG_MODE);
    error_acc1 = I2C_Peripheral_WriteRegister(LIS3DH_1_DEVICE_ADDRESS,
                                              LIS3DH_FIFO_CTRL_REG,
                                              LIS3DH_FIFO_MODE_CTRL_REG_MODE);
    for(;;)
    {
        CyDelay(500); // highly needed to get stable data

        error_acc1 = I2C_Peripheral_ReadRegister(LIS3DH_1_DEVICE_ADDRESS,
                                                 LIS3DH_FIFO_SRC_REG,
                                                 &fifo_full_1);
        
        error_acc2 = I2C_Peripheral_ReadRegister(LIS3DH_2_DEVICE_ADDRESS,
                                                 LIS3DH_FIFO_SRC_REG,
                                                 &fifo_full_2);
        
        if (error_acc1 == NO_ERROR && error_acc2 == NO_ERROR)
        {
            CyDelay(50);
            uint8_t OVRN_FIFO_2 = (fifo_full_2 & 0x40) >> 6;
            uint8_t OVRN_FIFO_1 = (fifo_full_1 & 0x40) >> 6;
            
            // Check if the FIFO of both accelerometers are full
            if (OVRN_FIFO_1 == 0x01 && OVRN_FIFO_2 == 0x01)
            {
                I2C_Peripheral_ReadRegisterMulti(LIS3DH_2_DEVICE_ADDRESS,
                                                 LIS3DH_OUT_X_L,
                                                 register_count,
                                                 Acc2_data);
                
                I2C_Peripheral_ReadRegisterMulti(LIS3DH_1_DEVICE_ADDRESS,
                                                 LIS3DH_OUT_X_L,
                                                 register_count,
                                                 Acc1_data);
                
                // Accelerometer 1 (0x18)
                int16_t x1 = 0;
                int16_t y1 = 0;
                int16_t z1 = 0;
                
                // Empty and store the 32 samples of the FIFO
                for (int i = 0; i < 32; i++)
                {
                    x1 += (int16)(Acc1_data[i*6] | (Acc1_data[i*6+1] << 8)) >> 6;
                    y1 += (int16)(Acc1_data[i*6+2] | (Acc1_data[i*6+3] << 8)) >> 6;
                    z1 += (int16)(Acc1_data[i*6+4] | (Acc1_data[i*6+5] << 8)) >> 6;
                }
                
                // Compute the mean
                int16_t x1_mean = x1 / 32;
                int16_t y1_mean = y1 / 32;
                int16_t z1_mean = z1 / 32;
                
                // Accelerometer 2 (0x19)
                int16_t x2 = 0;
                int16_t y2 = 0;
                int16_t z2 = 0;
                
                // Empty and store the 32 samples of the FIFO
                for (int i = 0; i < 32; i++)
                {
                    x2 += (int16)(Acc2_data[i*6] | (Acc2_data[i*6+1] << 8)) >> 6;
                    y2 += (int16)(Acc2_data[i*6+2] | (Acc2_data[i*6+3] << 8)) >> 6;
                    z2 += (int16)(Acc2_data[i*6+4] | (Acc2_data[i*6+5] << 8)) >> 6;
                }
                
                // Compute the mean
                int16_t x2_mean = x2 / 32;
                int16_t y2_mean = y2 / 32;
                int16_t z2_mean = z2 / 32;
                
                // Send message to BT module containing start (S) and end (E) characterers, along with the 6 acc means
                sprintf(message, "S %d,%d,%d,%d,%d,%d E", x1_mean, y1_mean, z1_mean, x2_mean, y2_mean, z2_mean);
                UART_BT_PutString(message);
                
                
                CyDelay(200);
                
                // Bypass mode followed by FIFO mode to reset the FIFO
                error_acc2 = I2C_Peripheral_WriteRegister(LIS3DH_2_DEVICE_ADDRESS,
                                                          LIS3DH_FIFO_CTRL_REG,
                                                          LIS3DH_BYPASS_MODE);
                
                error_acc2 = I2C_Peripheral_WriteRegister(LIS3DH_2_DEVICE_ADDRESS,
                                                          LIS3DH_FIFO_CTRL_REG,
                                                          LIS3DH_FIFO_MODE_CTRL_REG_MODE);
                
                error_acc1 = I2C_Peripheral_WriteRegister(LIS3DH_1_DEVICE_ADDRESS,
                                                          LIS3DH_FIFO_CTRL_REG,
                                                          LIS3DH_BYPASS_MODE);
                
                error_acc1 = I2C_Peripheral_WriteRegister(LIS3DH_1_DEVICE_ADDRESS,
                                                          LIS3DH_FIFO_CTRL_REG,
                                                          LIS3DH_FIFO_MODE_CTRL_REG_MODE);
            }
        }
    }
}

/* [] END OF FILE */
