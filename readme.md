- Cloned freeRTOS kernel from official github account 

- Included the required include paths and include source files in the cmakeLists.txt file

- FreeRTOS configuration options
https://www.freertos.org/Documentation/02-Kernel/03-Supported-devices/02-Customization

- Created a freeRTOSconfig.h file in the include folder and start populating all the required macros in it
- Created a new file called as portFunctions.c

- Refer to page 29 of the pdf manual on how to create a new project from scratch

- tasks.c file contains the vTaskStartScheduler() function and hence this should be included in the main.c file

- The portmacro.h file contains all the required functions which needed by the scheduler. These are ARM architecture specific

- Any macro that starts with config goes into the FreeRTOSConfig.h file 

- portfucntions.c file is added in the src file and add the memset function if there isn't a stddef.h file.

- Any function which starts with port should be written by the user

-In freertos priorities unlike ARM architecture where lower number means higher priority, in freertos higher number means higher priority

- For tasks creation a memory heap is required and you have to select which heap you want. from heaps 1-5. But you can use your own heap implementation  of you want to use it

- Idle hooks
In FreeRTOS, an idle hook function is a user-defined function that is executed repeatedly by the FreeRTOS idle task whenever no other application tasks are in the Ready state and eligible to run.
The idle hook is called when the RTOS scheduler determines that no higher-priority application tasks are active, allowing the idle task (which has the lowest priority) to run.

- Tick hooks
In FreeRTOS, a tick hook function is a user-defined function, named vApplicationTickHook(), that is called by the RTOS kernel every time the system tick interrupt fires. This provides a mechanism for the application to execute code periodically within the context of the tick interrupt service routine (ISR).

-vPortEnterCritical and vPortExitCritical are functions which are atomic operations which tells which tells only that current process can access that memory area and nothing else. The freertos kernel expects the user to program those functions. These functions are present in the port.c function of your specific ARM architecture H/W.
The default freertos implementation shows that when the critical part is entered the interrupts are disabled and then the critical section is executed. You are free to write your own code if needed


-Have commented out the systick, svc and the pendsv handlers from the HAL generated code as these are used in portasm.c


- A function which is to be made into a task should have the footprint of this type. It should return a void and should have a void pointer argument
    static void vTask1(void *pvParameters)


- configMINIMAL_STACK_SIZE is equal to 256 words which is nothing but 256*4 1KB, But totally there will be an extra 8 bytes allocated which might be used by the TCB to manage the task. so totally the size of the stack will be size_of_task +  8 bytes



DEBUG:
1. Make sure to have a separate timer for the FReertos and HAL. Leave the systick to freertos and for HAL operations, use something like a TIM

2. Make sure that the priority order of the execeptions are:(They are in the higher to lower priority order)
    SVC -> SYSTICK -> PENDSV

3. Make sure that the BASEPRI value is zero and if it is non zero(in the range of values of 1-5) then it might end up blocking svc or systick handlers

4. If the processor has group priority like M3 and above, then make sure that they have there is bits allocated for preemption priority and not all bits are allocated for subpriority