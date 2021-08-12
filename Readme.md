## Repositorio para Testing de Software Trabajo Práctico 3

Se agrega en el repositorio los archivos del trabajo hecho en clases y los requerimientos del TP3:
- Determinar si un led esta prendido
- Determinar si un led esta apagado
- Prender todos los led en una operación
- Apagar todos los led en una operación

Se agregaron 4 pruebas a tal efecto:

- Determinar si un led esta prendido
    ```c++
    void test_determinar_si_led_esta_encendido(void){
        const int led = 2;
        LedsTurnOn(led);
        TEST_ASSERT_EQUAL_HEX16(LEDS_STATE_ON, LedsGetState(led));
    }
    ```

- Determinar si un led esta apagado
    ```c++
    void test_determinar_si_led_esta_apagado(void){
        const int led = 2;
        LedsTurnOn(led);
        LedsTurnOff(led);
        TEST_ASSERT_EQUAL_HEX16(LEDS_STATE_OFF, LedsGetState(led));
    }
    ```

- Prender todos los led en una operación
    ```c++
    void test_prender_todos_los_led(void){
        const int led = 2;
        LedsTurnOn(led);
        LedsTurnOff(led);
        LedsTurnOnAllLeds();
        TEST_ASSERT_EQUAL_HEX16(LEDS_ALL_ON , ledsVirtuales);
    }
    ```

- Apagar todos los led en una operación
    ```c++
    void test_apagar_todos_los_led(void){
        const int led = 2;
        LedsTurnOn(led);
        LedsTurnOffAllLeds();
        TEST_ASSERT_EQUAL_HEX16(LEDS_ALL_OFF , ledsVirtuales);
    }
    ```

Se hicieron fallar las pruebas y se agregó el mínimo código indispensable en cada paso para salvar cada error que se presentó.




