/*
 * COMP 2659 PSG File
 * 
 * Purpose: To handle low-level interactions with the Programmable Sound Generator (PSG),
 *          including register operations, tone generation, volume control, and channel management.
 * Authors: Patrick Dang, Abiola Raji
 * Date: November 18, 2024
 */

#include "psg.h"

volatile char *PSG_reg_select = 0xFF8800;
volatile char *PSG_reg_write  = 0xFF8802;

/*
 * Function: write_psg
 * Purpose: Writes a value to a specified PSG register.
 * Parameters:
 *      reg - The register number (0-15) to write to.
 *      val - The 8-bit value to write to the register.
 * Returns:
 *      None.
 */
void write_psg(int reg, UINT8 val)
{
    if(reg >= 0 && reg <= 15 && val >= 0 && val <= 255)
    {    
        *PSG_reg_select = reg;
        *PSG_reg_write  = val;
    }
}

/*
 * Function: read_psg
 * Purpose: Reads the current value from a specified PSG register.
 * Parameters:
 *      reg - The register number (0-15) to read from.
 * Returns:
 *      The 8-bit value read from the specified register.
 */
UINT8 read_psg(int reg)
{
    UINT8 val;  

    if(reg >= 0 && reg <= 15)
    {   
        *PSG_reg_select = reg;
        val = *PSG_reg_select;
    }
    return val;
}

/*
 * Function: set_tone
 * Purpose: Sets the tone frequency for a specified channel.
 * Parameters:
 *      channel - The channel to set (CHANNEL_A, CHANNEL_B, or CHANNEL_C).
 *      tuning - 12-bit value determining the tone frequency.
 * Returns:
 *      None.
 */
void set_tone(int channel, int tuning)
{
    UINT8 fine_tuning = tuning & 0x00FF;
    UINT8 coarse_tuning = (tuning & 0x0F00) >> 8;

    switch(channel)
    {
        case CHANNEL_A:
            write_psg(A_FINE, fine_tuning);
            write_psg(A_COARSE, coarse_tuning);
            break;

        case CHANNEL_B:
            write_psg(B_FINE, fine_tuning);
            write_psg(B_COARSE, coarse_tuning);
            break;

        case CHANNEL_C:
            write_psg(C_FINE, fine_tuning);
            write_psg(C_COARSE, coarse_tuning);
            break;

        default:
            break;
    }
}

/*
 * Function: set_volume
 * Purpose: Sets the volume level for a specified channel.
 * Parameters:
 *      channel - The channel to set (CHANNEL_A, CHANNEL_B, or CHANNEL_C).
 *      vol - Volume level (0-31).
 * Returns:
 *      None.
 */
void set_volume(int channel, int vol)
{
    UINT8 volume = vol & 0x001F;

    switch(channel)
    {
        case CHANNEL_A:
            write_psg(A_VOL, volume);
            break;

        case CHANNEL_B:
            write_psg(B_VOL, volume);
            break;

        case CHANNEL_C:
            write_psg(C_VOL, volume);
            break;

        default:
            break;  
    }
}

/*
 * Function: enable_channel
 * Purpose: Enables or disables tone and noise for a specified channel.
 * Parameters:
 *      channel - The channel to configure (CHANNEL_A, CHANNEL_B, or CHANNEL_C).
 *      tone_on - Flag to enable (1) or disable (0) tone.
 *      noise_on - Flag to enable (1) or disable (0) noise.
 * Returns:
 *      None.
 */
void enable_channel(int channel, int tone_on, int noise_on)
{
    UINT8 mixer_val = read_psg(MIXER_REG);

    switch (channel)
    {
        case CHANNEL_A:

            if(tone_on == 1 && noise_on == 1){
                mixer_val &= TONE_A & NOISE_A;
            }
            else if(tone_on == 1 && noise_on == 0){
                mixer_val &= TONE_A;
            }
            else if(tone_on == 0 && noise_on == 1){
                mixer_val &= NOISE_A;
            }
            break;

        case CHANNEL_B:

            if(tone_on == 1 && noise_on == 1){
                mixer_val &= TONE_B & NOISE_B;
            }
            else if(tone_on == 1 && noise_on == 0){
                mixer_val &= TONE_B;
            }
            else if(tone_on == 0 && noise_on == 1){
                mixer_val &= NOISE_B;
            }
            break;

        case CHANNEL_C:

            if(tone_on == 1 && noise_on == 1){
                mixer_val &= TONE_C & NOISE_C;
            }
            else if(tone_on == 1 && noise_on == 0){
                mixer_val &= TONE_C;
            }
            else if(tone_on == 0 && noise_on == 1){
                mixer_val &= NOISE_C;
            }
            break;

        default:
            break;
    }

    write_psg(MIXER_REG, mixer_val);
}

/*
 * Function: stop_sound
 * Purpose: Stops all sound output by disabling all channels and resetting PSG registers.
 * Parameters:
 *      None.
 * Returns:
 *      None.
 */
void stop_sound()
{
    long oldssp = Super(0);
    write_psg(MIXER_REG, MIXER_NONE);  

    write_psg(NOISE_FREQ_REG, 0x00);

    write_psg(ENV_FINE, 0x00);
    write_psg(ENV_ROUGH, 0x00);
    write_psg(ENV_SHAPE_CONTROL, 0x00);

    set_volume(CHANNEL_A, 0);
    set_volume(CHANNEL_B, 0);
    set_volume(CHANNEL_C, 0);

    Super(oldssp);
}