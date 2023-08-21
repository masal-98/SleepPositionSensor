/* ===============================================
 *
 * Alfonzo Massimo, Canavate Chloé, Franke Patrick
 * Project 05 - Sleep Position Classifier
 * Electronic Technologies and Biosensor Laboratory
 * Academic year 2021 - 2022
 * LIS3DH.h file
 * \brief Addresses and Hex value settings
 *
 * =============================================== */

#ifndef __LIS3DH_H
    #define __LIS3DH_H

    /**
    *   \brief 7-bit I2C address of the 1st accelerometer
    */
    #define LIS3DH_1_DEVICE_ADDRESS 0x18
    
    /**
    *   \brief 7-bit I2C address of the 2nd accelerometer
    */
    #define LIS3DH_2_DEVICE_ADDRESS 0x19

    /**
    *   \brief Address of the WHO AM I register
    */
    #define LIS3DH_WHO_AM_I_REG_ADDR 0x0F
    
    /**
    *   \brief WHOAMI return value
    */
    #define LIS3DH_WHOAMI_RETVAL     0x33

    /**
    *   \brief Address of the Status register
    */
    #define LIS3DH_STATUS_REG 0x27

    /**
    *   \brief Address of the Control register 1
    */
    #define LIS3DH_CTRL_REG1 0x20
    
    /**
    *   \brief Address of the Control register 5
    */
    #define LIS3DH_CTRL_REG5 0x24
    
    /**
    *   \brief Address of the FIFO Control register
    */
    #define LIS3DH_FIFO_CTRL_REG 0x2E
    
    /**
    *   \brief Address of the FIFO SRC register
    */
    #define LIS3DH_FIFO_SRC_REG 0x2F

    /**
    *   \brief Hex value to set normal mode to the accelerator
    */
    #define LIS3DH_NORMAL_MODE_CTRL_REG1 0x47
    
    /**
    *   \brief Hex value to enable FIFO to the accelerator
    */
    #define LIS3DH_FIFO_ENABLED_CTRL_REG5 0x40
    
    /**
    *   \brief Hex value to set FIFO mode to the accelerator
    */
    #define LIS3DH_NORMAL_MODE_CTRL_REG5 0x40
    
    /**
    *   \brief Hex value to set FIFO mode to the accelerator
    */
    #define LIS3DH_BYPASS_MODE 0x00
    
    /**
    *   \brief Hex value to set normal mode (powered off)
    **/
    #define LIS3DH_FIFO_MODE_CTRL_REG_MODE 0x40
 
    /**
    *   \brief Addresses of the accelerometers' low and high bits for X, Y and Z coordinates
    **/
    #define LIS3DH_OUT_X_L 0x28
    
    #define LIS3DH_OUT_X_H 0x29
    
    #define LIS3DH_OUT_Y_L 0x2A
    
    #define LIS3DH_OUT_Y_H 0x2B
    
    #define LIS3DH_OUT_Z_L 0x2C
    
    #define LIS3DH_OUT_Z_H 0x2D
    
#endif


/* [] END OF FILE */
