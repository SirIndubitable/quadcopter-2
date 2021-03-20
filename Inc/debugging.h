#ifndef _LIS3DSH_H
#define _LIS3DSH_H

#ifdef __cplusplus
extern "C" {
#endif


#define _LONG_DELAY = 500;
void show_binary(uint16_t value)
{
    all_leds.On();
    delay(_LONG_DELAY);

    all_leds.Off();
    delay(_LONG_DELAY);

    for (uint16_t mask = 1; mask != 0; mask <<= 1)
    {
        if (value & mask)
        {
            red_led.On();
            green_led.Off();
        }
        else
        {
            red_led.Off();
            green_led.On();
        }
        delay(_LONG_DELAY);

        red_led.Off();
        green_led.Off();
        delay(200);
    }

    all_leds.Off();
}


#ifdef __cplusplus
}
#endif

#endif