#include <stdlib.h>
#include <unistd.h>

#include "lvgl/lvgl.h"

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{

static const wchar_t * title = L"LVGL port Windows CodeBlocks.      https://lvgl.io | https://docs.lvgl.io";
    /*Initialize LVGL*/
    lv_init();

    /*Initialize the HAL for LVGL*/
    lv_display_t * display = lv_windows_create_display(title, 800, 480, 100, FALSE, FALSE);
    lv_windows_acquire_pointer_indev(display);

    /*Output prompt information to the console, you can also use printf() to print directly*/
    LV_LOG_USER("LVGL initialization completed!");


    lv_obj_t * label = lv_label_create(lv_screen_active());

    // Set the label text
    lv_label_set_text(label, "Hello, LVGL!");

    // Align the label in the center
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

    while (1) {
        /* Periodically call the lv_task handler.
         * It could be done in a timer interrupt or an OS task too.*/
        lv_task_handler();
        usleep(5000);       /*Just to let the system breath*/
    }
    return 0;
}

