#include "src/leds.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"






static uint16_t ledsVirtuales;



void setUp(void){

    LedsInit(&ledsVirtuales);

}



void tearDown(){



}



void test_LedsOffAfterCreate(void){

    ledsVirtuales=0xFFFF;

    LedsInit(&ledsVirtuales);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_un_led(void){

    const int led=2;

    LedsTurnOn(led);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << (led-1))), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(42), UNITY_DISPLAY_STYLE_HEX16);

}





void test_apagar_un_led(void){

    const int led=2;

    LedsTurnOn(led);

    LedsTurnOff(led);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(50), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_y_apagar_varios_leds(void){

    const int led = 2;

    LedsTurnOn(led);

    LedsTurnOn(5);

    LedsTurnOff(5);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1 << (led-1))), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(59), UNITY_DISPLAY_STYLE_HEX16);

}





void test_determinar_si_led_esta_encendido(void){

    const int led = 2;

    LedsTurnOn(led);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((1)), (UNITY_INT)(UNITY_INT16)((LedsGetState(led))), (

   ((void *)0)

   ), (UNITY_UINT)(66), UNITY_DISPLAY_STYLE_HEX16);

}







void test_determinar_si_led_esta_apagado(void){

    const int led = 2;

    LedsTurnOn(led);

    LedsTurnOff(led);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0)), (UNITY_INT)(UNITY_INT16)((LedsGetState(led))), (

   ((void *)0)

   ), (UNITY_UINT)(75), UNITY_DISPLAY_STYLE_HEX16);

}





void test_prender_todos_los_led(void){

    const int led = 2;

    LedsTurnOn(led);

    LedsTurnOff(led);

    LedsTurnOnAllLeds();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(84), UNITY_DISPLAY_STYLE_HEX16);

}





void test_apagar_todos_los_led(void){

    const int led = 2;

    LedsTurnOn(led);

    LedsTurnOffAllLeds();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((ledsVirtuales)), (

   ((void *)0)

   ), (UNITY_UINT)(92), UNITY_DISPLAY_STYLE_HEX16);

}
