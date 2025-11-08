#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/* Here is where your FreeRTOS configuration macros would go.
   You may want to add specific configurations for your project. */

// systick timer is of 24 bits, hence we will have a register of 32 bits
#define configTICK_TYPE_WIDTH_IN_BITS TICK_TYPE_WIDTH_32_BITS

#define configENABLE_MPU 0

#define configUSE_PREEMPTION 1

//Hooks are user defined functions which is called when the CPU is idle instead of executing the idle function. It can be something like a function which keeps toggling the LED when the CPU is idle
#define configUSE_IDLE_HOOK 0

#define configUSE_TICK_HOOK 0

#define configMINIMAL_STACK_SIZE  0x100

//In freertos priorities unlike ARM architecture where lower number means higher priority, in freertos higher number means higher priority
#define configMAX_SYSCALL_INTERRUPT_PRIORITY   1
//You can also choose a number lesser than this
#define configMAX_PRIORITIES   5

#define configTOTAL_HEAP_SIZE  0x1000

//The systick is a part of ARM architecture and this might not be present in the RISC-V CPU. Hence these macros are a part of port.c file
//configure the systick timer to tick every 1ms
#define configTICK_RATE_HZ  1000
//This is the SYSCLK value of the micro
#define configSYSTICK_CLOCK_HZ 12000000

#endif /* FREERTOS_CONFIG_H */
