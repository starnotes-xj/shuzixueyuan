// Created by 星记 on 25-6-7.
#include <stdio.h>
#include <unistd.h>
#include "../../../../../../utils/native/lite/include/ohos_init.h"
#include "../../../../../../third_party/cmsis/CMSIS/RTOS2/Include/cmsis_os2.h"
#include "../../../../../../base/iot_hardware/interfaces/kits/wifiiot_lite/wifiiot_gpio.h"
#include "../../../../../../base/iot_hardware/interfaces/kits/wifiiot_lite/wifiiot_gpio_ex.h"

void init(void)
{
    GpioInit();
    IoSetFunc(WIFI_IOT_IO_NAME_GPIO_10, WIFI_IOT_IO_FUNC_GPIO_10_GPIO);
    GpioSetDir(WIFI_IOT_IO_NAME_GPIO_10, WIFI_IOT_GPIO_DIR_OUT);

    IoSetFunc(WIFI_IOT_IO_NAME_GPIO_11, WIFI_IOT_IO_FUNC_GPIO_11_GPIO);
    GpioSetDir(WIFI_IOT_IO_NAME_GPIO_11, WIFI_IOT_GPIO_DIR_OUT);

    IoSetFunc(WIFI_IOT_IO_NAME_GPIO_12, WIFI_IOT_IO_FUNC_GPIO_12_GPIO);
    GpioSetDir(WIFI_IOT_IO_NAME_GPIO_12, WIFI_IOT_GPIO_DIR_OUT);
}
static void StartTrafficLightTask(void)
{
    init();
    while (1)
    {
        GpioSetOutputVal(WIFI_IOT_IO_NAME_GPIO_11, WIFI_IOT_GPIO_VALUE1);
        usleep(3000 * 1000);
        GpioSetOutputVal(WIFI_IOT_IO_NAME_GPIO_11, WIFI_IOT_GPIO_VALUE0);
        GpioSetOutputVal(WIFI_IOT_IO_NAME_GPIO_12, WIFI_IOT_GPIO_VALUE1);
        usleep(1000 * 1000);
        GpioSetOutputVal(WIFI_IOT_IO_NAME_GPIO_12, WIFI_IOT_GPIO_VALUE0);
        GpioSetOutputVal(WIFI_IOT_IO_NAME_GPIO_10, WIFI_IOT_GPIO_VALUE1);
        usleep(3000 * 1000);
        GpioSetOutputVal(WIFI_IOT_IO_NAME_GPIO_10, WIFI_IOT_GPIO_VALUE0);
    }
}

APP_FEATURE_INIT(StartTrafficLightTask);

