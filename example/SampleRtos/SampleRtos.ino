//#include <wirish/wirish.h>
//#include "libraries/FreeRTOS/MapleFreeRTOS.h"
#include <MapleFreeRTOS900.h>

uint8_t BOARD_LED_PIN = PC13;
static void vLEDFlashTask(void *pvParameters) {
    for (;;) {
        vTaskDelay(1000);
        digitalWrite(PC13, HIGH);
        vTaskDelay(500);
        digitalWrite(PC13, LOW);
    }
}
int a=0;
static void vSerialPrintTask(void *pvParameters) {
    for (;;) {
        Serial.println(a++);
        vTaskDelay(5000);
   }
}

static void vSerialPrintTask2(void *pvParameters) {
    for (;;) {
        Serial.println(millis());
        vTaskDelay(10000);
   }
}

void setup() {
    // initialize the digital pin as an output:
    pinMode(BOARD_LED_PIN, OUTPUT);

    xTaskCreate(vLEDFlashTask,
                "Task1",
                configMINIMAL_STACK_SIZE,
                NULL,
                tskIDLE_PRIORITY + 2,
                NULL);
    xTaskCreate(vSerialPrintTask,
                "Task2",
                configMINIMAL_STACK_SIZE,
                NULL,
                tskIDLE_PRIORITY + 2,
                NULL);
    xTaskCreate(vSerialPrintTask2,
                "Task3",
                configMINIMAL_STACK_SIZE,
                NULL,
                tskIDLE_PRIORITY + 2,
                NULL);
    vTaskStartScheduler();
}

void loop() {
    // Insert background code here
}
