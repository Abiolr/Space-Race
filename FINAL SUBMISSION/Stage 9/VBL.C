/*
 * VBL.H
 *
 * Purpose: Header file for custom Vertical Blank (VBL) Interrupt Service Routine (ISR)
 *          and related utilities for handling synchronous events and timer updates.
 * STATUS: functions not implemented in game, only wrote potential functions and 
 *         documentation based on specifications.
 * Author: Patrick Dang, Abiola Raji
 * Date: December 9, 2024
 */

#include "VBL.H"
#include <stdio.h>
#include <osbind.h>
#include "TYPES.H"
#define VBL 28

typedef void (*Vector)();
volatile int timer = 0;
volatile int seconds = 0;
int render_request = TRUE;

Vector install_vector(int num, Vector vector);
void process_synchronus_events();
void vbl_isr();
void do_VBL_ISR();

/* 
 * Function: install_vector
 * ------------------------
 * Replaces the system interrupt vector with a custom ISR.
 *
 * Parameters:
 *   num: The vector number to replace (e.g., VBL vector).
 *   vector: A pointer to the custom ISR function.
 *
 * Returns:
 *   The original vector address, allowing restoration upon exit.
 */
Vector install_vector(int num, Vector vector)
{
    Vector orig;
    Vector *vectp = (Vector *)((long)num << 2);
    long old_ssp = Super(0);
    orig = *vectp;
    *vectp = vector;
    Super(old_ssp);
    return orig;
}

/* 
 * Function: do_VBL_ISR
 * --------------------
 * A helper function to handle the core operations of the custom VBL ISR.
 * Updates the timer and seconds counters.
 */
void do_VBL_ISR()
{
    timer++;
    if (timer % 70 == 0)
    {
        seconds++;
    }
}

/* 
 * Function: process_synchronus_events
 * -----------------------------------
 * Placeholder for handling synchronous events during the VBL ISR.
 * Intended to be defined with game-specific logic for events like model updates.
 */
void process_synchronus_events()
{

}

/* 
 * Function: vbl_isr
 * -----------------
 * Custom Vertical Blank ISR function.
 * Handles timing, synchronous event updates, and flags for rendering.
 *
 * Details:
 * - Increments the timer variable on each VBL tick.
 * - Tracks seconds by counting VBL ticks (70 per second).
 * - Sets the global render_request flag.
 */
void vbl_isr()
{

}
