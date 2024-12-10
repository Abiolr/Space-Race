/*
 * IKBD.H
 *
 * Purpose: Header file for handling keyboard input via the Atari IKBD controller.
 * STATUS: functions not implemented in game, only wrote potential functions and 
 *         documentation based on specifications.
 * Author: Patrick Dang, Abiola Raji
 * Date: December 9, 2024
 */

#include "IKBD.H"
#include <osbind.h>

typedef unsigned char UINT8;
typedef UINT8 SCANCODE;

volatile UINT8* const IKBD_control = 0xFFFC00;
volatile const UINT8* const IKBD_status = 0xFFFC00;
volatile const SCANCODE * const IKBD_RDR = 0xFFFC02;

#define DISABLE 0x16
#define ENABLE 0x96

#define RDR_FULL ((UINT8)0x01)
#define ESC_MAKE ((SCANCODE)0x01)
#define ESC_BREAK ((SCANCODE)0x81)

SCANCODE read_scancode();
void ikbd_isr();
void init_keyboard_isr();

/* 
 * Function: read_scancode
 * ------------------------
 * Reads a scan code from the IKBD receiver data register.
 *
 * Returns:
 *   The scan code of the key pressed or released.
 *
 * Details:
 *   - Waits until the receiver data register is full (RDR_FULL is set).
 *   - Retrieves the scan code from the IKBD_RDR register.
 */
SCANCODE read_scancode(){
    while (!(*IKBD_status & RDR_FULL))
        ;
    
    return *IKBD_RDR;
}