// Created by 星记 on 25-6-15.
#include <stdio.h>
#include <unistd.h>
#include "ohos_init.h"
#include "cmsis_os2.h"
static void *example_task1_entry(void *data)
{
    data = data;
    for (int i = 0; i < 10; i++)
    {
        sleep(1);
        printf("example_task1_entry: %d!\r\n", i);
    }

    return data;
}
static void *example_task2_entry(void *data)
{
    data = data;
    for (int i = 0; i < 10; i++)
    {
        usleep(800000);
        printf("\n\r\nexample_task2_entry: %d!\r\n", i);
    }

    return data;
}
void example_task_init(void)
{
    osThreadAttr_t attr1;
    osThreadAttr_t attr2;

    attr1.name = "example_task1";
    attr1.attr_bits = 0U;
    attr1.cb_mem = NULL;
    attr1.cb_size = 0U;
    attr1.stack_mem = NULL;
    attr1.stack_size = 1024;
    attr1.priority = osPriorityNormal;

    attr2.name = "example_task2";
    attr2.attr_bits = 0U;
    attr2.cb_mem = NULL;
    attr2.cb_size = 0U;
    attr2.stack_mem = NULL;
    attr2.stack_size = 1024;
    attr2.priority = osPriorityNormal;

    if (osThreadNew((osThreadFunc_t)example_task1_entry, NULL, &attr1) == NULL)
    {
        printf("Example_task1 create failed!\n");
    }

    if (osThreadNew((osThreadFunc_t)example_task2_entry, NULL, &attr2) == NULL)
    {
        printf("Example_task2 create failed!\n");
    }
}
APP_FEATURE_INIT(example_task_init);