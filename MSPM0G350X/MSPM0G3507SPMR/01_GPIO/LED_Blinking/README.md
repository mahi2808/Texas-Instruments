In this project PORTB pin 22, 26 and 27 (RGB LEDS) will blink at a time after every 0.5 Sec.
<br>
We can find out DL function for every particular module in there .h file under driverlib folder(eg:- ti >> driverlib >> dl_gpio.h)
<br>
DL function arguments we can find in particular init function, means for LED Blink GPIO pin name.(eg:-  SYSCFG_DL_init(); >> SYSCFG_DL_GPIO_init();)

