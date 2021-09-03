/*
Prendo un led
Apago un led
    Determinar si un led esta prendido
    Determinar si un led esta apagado
    Prender todos los led en una operación
    Apagar todos los led en una operación
Ver si todos los indices corresponden con los leds
Secuencia del primero al último
Prender un led sin afectar el resto
Valores de borde para los parámetros
Verificar que funcionan con logica positiva
Valores invalidos para los parámetros
*/


#include "unity.h"
#include "leds.h"
#include <stdint.h>

#define LEDS_ALL_ON_TEST  0xFFFF
#define LEDS_ALL_OFF_TEST 0x0000


static uint16_t ledsVirtuales;

void setUp(void){
    LedsInit(&ledsVirtuales);
}

void tearDown(){

}
/* Cuando inicializo el controlador todos los leds quedan apagados*/
void test_LedsOffAfterCreate(void){
    ledsVirtuales=0xFFFF;
    LedsInit(&ledsVirtuales);
    TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales);
}

/*Prender un led*/
void test_prender_un_led(void){
    const int led=2;
    LedsTurnOn(led);
    TEST_ASSERT_EQUAL_HEX16(1 << (led-1), ledsVirtuales);
}

/*Apagar un led*/
void test_apagar_un_led(void){
    const int led=2;
    LedsTurnOn(led);
    LedsTurnOff(led);
    TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales);
}

/*Prender un led sin afectar al resto */
void test_prender_y_apagar_varios_leds(void){
    const int led = 2;
    LedsTurnOn(led);
    LedsTurnOn(5);
    LedsTurnOff(5);
    TEST_ASSERT_EQUAL_HEX16(1 << (led-1), ledsVirtuales);
}

/*Determinar si un led esta prendido*/
void test_determinar_si_led_esta_encendido(void){
    const int led = 2;
    LedsTurnOn(led);
    TEST_ASSERT_EQUAL_HEX16(LEDS_STATE_ON, LedsGetState(led));
}


/*Determinar si un led esta apagado*/
void test_determinar_si_led_esta_apagado(void){
    const int led = 2;
    LedsTurnOn(led);
    LedsTurnOff(led);
    TEST_ASSERT_EQUAL_HEX16(LEDS_STATE_OFF, LedsGetState(led));
}

/*Prender todos los leds en una operacion*/
void test_prender_todos_los_led(void){
    const int led = 2;
    LedsTurnOn(led);
    LedsTurnOff(led);
    LedsTurnOnAllLeds();
    TEST_ASSERT_EQUAL_HEX16(LEDS_ALL_ON_TEST , ledsVirtuales);
}

/*Apagar todos los leds en una operación*/
void test_apagar_todos_los_led(void){
    const int led = 2;
    LedsTurnOn(led);
    LedsTurnOffAllLeds();
    TEST_ASSERT_EQUAL_HEX16(LEDS_ALL_OFF_TEST , ledsVirtuales);
}
