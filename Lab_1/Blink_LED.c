
#include <stdint.h>
#include "inc/tm4c1294ncpdt.h"


//*****************************************************************************
//
// Blink the LED.
//
//*****************************************************************************
int main(void)
{
    volatile uint32_t ui32Loop;

    // Enable the GPIO port that is used for the PL0 port.
    SYSCTL_RCGCGPIO_R = SYSCTL_RCGCGPIO_R10;

    // Do a dummy read to insert a few cycles after enabling the peripheral.
    ui32Loop = SYSCTL_RCGCGPIO_R;

    GPIO_PORTL_DIR_R = 0x01; //Set the direction as outpu
    GPIO_PORTL_DEN_R = 0x01; //enable the GPIO pin

    // Infinite Loop
    while(1)
    {
        // Turn on the LED.
        GPIO_PORTL_DATA_R |= 0x01; //Send to the PL0 port 1 bit

        // Delay for a bit.
        for(ui32Loop = 0; ui32Loop < 2000000; ui32Loop++){
        }

        // Turn off the LED.
        GPIO_PORTL_DATA_R &= ~(0x01); //Send to the PL0 port 1 bit to turn it off

        // Delay for a bit more
        for(ui32Loop = 0; ui32Loop < 2000000; ui32Loop++){
        }
    }
}
