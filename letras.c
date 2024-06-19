/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
// codigo para compilar -> gcc -o main exemplo_main.c gpu_lib.c
#include <stdio.h>
#include "gpu_lib.h"

int main()
{   
    if (open_gpu_device() == 0)
        return 0;


    // LETRA P EM VERDE
    set_sprite_pixel_color(11265, 0, 7, 0);
    set_sprite_pixel_color(11266, 0, 7, 0);
    set_sprite_pixel_color(11267, 0, 7, 0);
    set_sprite_pixel_color(11268, 0, 7, 0);
    set_sprite_pixel_color(11269, 0, 7, 0);
    set_sprite_pixel_color(11270, 0, 7, 0);
    set_sprite_pixel_color(11271, 0, 7, 0);
    set_sprite_pixel_color(11272, 0, 7, 0);
    set_sprite_pixel_color(11273, 0, 7, 0);
    set_sprite_pixel_color(11274, 0, 7, 0);
    set_sprite_pixel_color(11275, 0, 7, 0);
    set_sprite_pixel_color(11276, 0, 7, 0);
    set_sprite_pixel_color(11285, 0, 7, 0);
    set_sprite_pixel_color(11286, 0, 7, 0);
    set_sprite_pixel_color(11287, 0, 7, 0);
    set_sprite_pixel_color(11288, 0, 7, 0);
    set_sprite_pixel_color(11289, 0, 7, 0);
    set_sprite_pixel_color(11290, 0, 7, 0);
    set_sprite_pixel_color(11291, 0, 7, 0);
    set_sprite_pixel_color(11292, 0, 7, 0);
    set_sprite_pixel_color(11293, 0, 7, 0);
    set_sprite_pixel_color(11294, 0, 7, 0);
    set_sprite_pixel_color(11295, 0, 7, 0);
    set_sprite_pixel_color(11296, 0, 7, 0);
    set_sprite_pixel_color(11305, 0, 7, 0);
    set_sprite_pixel_color(11306, 0, 7, 0);
    set_sprite_pixel_color(11315, 0, 7, 0);
    set_sprite_pixel_color(11316, 0, 7, 0);
    set_sprite_pixel_color(11325, 0, 7, 0);
    set_sprite_pixel_color(11326, 0, 7, 0);
    set_sprite_pixel_color(11335, 0, 7, 0);
    set_sprite_pixel_color(11336, 0, 7, 0);
    set_sprite_pixel_color(11345, 0, 7, 0);
    set_sprite_pixel_color(11346, 0, 7, 0);
    set_sprite_pixel_color(11355, 0, 7, 0);
    set_sprite_pixel_color(11356, 0, 7, 0);
    set_sprite_pixel_color(11365, 0, 7, 0);
    set_sprite_pixel_color(11366, 0, 7, 0);
    set_sprite_pixel_color(11375, 0, 7, 0);
    set_sprite_pixel_color(11376, 0, 7, 0);
    set_sprite_pixel_color(11385, 0, 7, 0);
    set_sprite_pixel_color(11386, 0, 7, 0);
    set_sprite_pixel_color(11387, 0, 7, 0);
    set_sprite_pixel_color(11388, 0, 7, 0);
    set_sprite_pixel_color(11389, 0, 7, 0);
    set_sprite_pixel_color(11390, 0, 7, 0);
    set_sprite_pixel_color(11391, 0, 7, 0);
    set_sprite_pixel_color(11392, 0, 7, 0);
    set_sprite_pixel_color(11393, 0, 7, 0);
    set_sprite_pixel_color(11394, 0, 7, 0);
    set_sprite_pixel_color(11395, 0, 7, 0);
    set_sprite_pixel_color(11396, 0, 7, 0);
    set_sprite_pixel_color(11405, 0, 7, 0);
    set_sprite_pixel_color(11406, 0, 7, 0);
    set_sprite_pixel_color(11407, 0, 7, 0);
    set_sprite_pixel_color(11408, 0, 7, 0);
    set_sprite_pixel_color(11409, 0, 7, 0);
    set_sprite_pixel_color(11410, 0, 7, 0);
    set_sprite_pixel_color(11411, 0, 7, 0);
    set_sprite_pixel_color(11412, 0, 7, 0);
    set_sprite_pixel_color(11413, 0, 7, 0);
    set_sprite_pixel_color(11414, 0, 7, 0);
    set_sprite_pixel_color(11415, 0, 7, 0);
    set_sprite_pixel_color(11416, 0, 7, 0);
    set_sprite_pixel_color(11425, 0, 7, 0);
    set_sprite_pixel_color(11426, 0, 7, 0);
    set_sprite_pixel_color(11445, 0, 7, 0);
    set_sprite_pixel_color(11446, 0, 7, 0);
    set_sprite_pixel_color(11465, 0, 7, 0);
    set_sprite_pixel_color(11466, 0, 7, 0);
    set_sprite_pixel_color(11485, 0, 7, 0);
    set_sprite_pixel_color(11486, 0, 7, 0);
    set_sprite_pixel_color(11505, 0, 7, 0);
    set_sprite_pixel_color(11506, 0, 7, 0);
    set_sprite_pixel_color(11525, 0, 7, 0);
    set_sprite_pixel_color(11526, 0, 7, 0);
    set_sprite_pixel_color(11545, 0, 7, 0);
    set_sprite_pixel_color(11546, 0, 7, 0);

    // LETRA M EM AZUL
    set_sprite_pixel_color(11665, 0, 0, 7);
    set_sprite_pixel_color(11676, 0, 0, 7);
    set_sprite_pixel_color(11685, 0, 0, 7);
    set_sprite_pixel_color(11686, 0, 0, 7);
    set_sprite_pixel_color(11695, 0, 0, 7);
    set_sprite_pixel_color(11696, 0, 0, 7);
    set_sprite_pixel_color(11705, 0, 0, 7);
    set_sprite_pixel_color(11706, 0, 0, 7);
    set_sprite_pixel_color(11707, 0, 0, 7);
    set_sprite_pixel_color(11714, 0, 0, 7);
    set_sprite_pixel_color(11715, 0, 0, 7);
    set_sprite_pixel_color(11716, 0, 0, 7);
    set_sprite_pixel_color(11725, 0, 0, 7);
    set_sprite_pixel_color(11726, 0, 0, 7);
    set_sprite_pixel_color(11727, 0, 0, 7);
    set_sprite_pixel_color(11728, 0, 0, 7);
    set_sprite_pixel_color(11733, 0, 0, 7);
    set_sprite_pixel_color(11734, 0, 0, 7);
    set_sprite_pixel_color(11735, 0, 0, 7);
    set_sprite_pixel_color(11736, 0, 0, 7);
    set_sprite_pixel_color(11745, 0, 0, 7);
    set_sprite_pixel_color(11746, 0, 0, 7);
    set_sprite_pixel_color(11747, 0, 0, 7);
    set_sprite_pixel_color(11748, 0, 0, 7);
    set_sprite_pixel_color(11749, 0, 0, 7);
    set_sprite_pixel_color(11752, 0, 0, 7);
    set_sprite_pixel_color(11753, 0, 0, 7);
    set_sprite_pixel_color(11754, 0, 0, 7);
    set_sprite_pixel_color(11755, 0, 0, 7);
    set_sprite_pixel_color(11756, 0, 0, 7);
    set_sprite_pixel_color(11765, 0, 0, 7);
    set_sprite_pixel_color(11766, 0, 0, 7);
    set_sprite_pixel_color(11768, 0, 0, 7);
    set_sprite_pixel_color(11769, 0, 0, 7);
    set_sprite_pixel_color(11770, 0, 0, 7);
    set_sprite_pixel_color(11771, 0, 0, 7);
    set_sprite_pixel_color(11772, 0, 0, 7);
    set_sprite_pixel_color(11773, 0, 0, 7);
    set_sprite_pixel_color(11775, 0, 0, 7);
    set_sprite_pixel_color(11776, 0, 0, 7);
    set_sprite_pixel_color(11785, 0, 0, 7);
    set_sprite_pixel_color(11786, 0, 0, 7);
    set_sprite_pixel_color(11789, 0, 0, 7);
    set_sprite_pixel_color(11790, 0, 0, 7);
    set_sprite_pixel_color(11791, 0, 0, 7);
    set_sprite_pixel_color(11792, 0, 0, 7);
    set_sprite_pixel_color(11795, 0, 0, 7);
    set_sprite_pixel_color(11796, 0, 0, 7);
    set_sprite_pixel_color(11805, 0, 0, 7);
    set_sprite_pixel_color(11806, 0, 0, 7);
    set_sprite_pixel_color(11810, 0, 0, 7);
    set_sprite_pixel_color(11811, 0, 0, 7);
    set_sprite_pixel_color(11815, 0, 0, 7);
    set_sprite_pixel_color(11816, 0, 0, 7);
    set_sprite_pixel_color(11825, 0, 0, 7);
    set_sprite_pixel_color(11826, 0, 0, 7);
    set_sprite_pixel_color(11835, 0, 0, 7);
    set_sprite_pixel_color(11836, 0, 0, 7);
    set_sprite_pixel_color(11845, 0, 0, 7);
    set_sprite_pixel_color(11846, 0, 0, 7);
    set_sprite_pixel_color(11855, 0, 0, 7);
    set_sprite_pixel_color(11856, 0, 0, 7);
    set_sprite_pixel_color(11865, 0, 0, 7);
    set_sprite_pixel_color(11866, 0, 0, 7);
    set_sprite_pixel_color(11875, 0, 0, 7);
    set_sprite_pixel_color(11876, 0, 0, 7);
    set_sprite_pixel_color(11885, 0, 0, 7);
    set_sprite_pixel_color(11886, 0, 0, 7);
    set_sprite_pixel_color(11895, 0, 0, 7);
    set_sprite_pixel_color(11896, 0, 0, 7);
    set_sprite_pixel_color(11905, 0, 0, 7);
    set_sprite_pixel_color(11906, 0, 0, 7);
    set_sprite_pixel_color(11915, 0, 0, 7);
    set_sprite_pixel_color(11916, 0, 0, 7);
    set_sprite_pixel_color(11925, 0, 0, 7);
    set_sprite_pixel_color(11926, 0, 0, 7);
    set_sprite_pixel_color(11935, 0, 0, 7);
    set_sprite_pixel_color(11936, 0, 0, 7);
    set_sprite_pixel_color(11945, 0, 0, 7);
    set_sprite_pixel_color(11946, 0, 0, 7);
    set_sprite_pixel_color(11955, 0, 0, 7);
    set_sprite_pixel_color(11956, 0, 0, 7);

    // LETRA D EM BRANCO
    set_sprite_pixel_color(12065, 7, 7, 7);
    set_sprite_pixel_color(12066, 7, 7, 7);
    set_sprite_pixel_color(12067, 7, 7, 7);
    set_sprite_pixel_color(12068, 7, 7, 7);
    set_sprite_pixel_color(12069, 7, 7, 7);
    set_sprite_pixel_color(12070, 7, 7, 7);
    set_sprite_pixel_color(12071, 7, 7, 7);
    set_sprite_pixel_color(12085, 7, 7, 7);
    set_sprite_pixel_color(12086, 7, 7, 7);
    set_sprite_pixel_color(12087, 7, 7, 7);
    set_sprite_pixel_color(12088, 7, 7, 7);
    set_sprite_pixel_color(12089, 7, 7, 7);
    set_sprite_pixel_color(12090, 7, 7, 7);
    set_sprite_pixel_color(12091, 7, 7, 7);
    set_sprite_pixel_color(12092, 7, 7, 7);
    set_sprite_pixel_color(12093, 7, 7, 7);
    set_sprite_pixel_color(12105, 7, 7, 7);
    set_sprite_pixel_color(12106, 7, 7, 7);
    set_sprite_pixel_color(12112, 7, 7, 7);
    set_sprite_pixel_color(12113, 7, 7, 7);
    set_sprite_pixel_color(12114, 7, 7, 7);
    set_sprite_pixel_color(12115, 7, 7, 7);
    set_sprite_pixel_color(12125, 7, 7, 7);
    set_sprite_pixel_color(12126, 7, 7, 7);
    set_sprite_pixel_color(12134, 7, 7, 7);
    set_sprite_pixel_color(12135, 7, 7, 7);
    set_sprite_pixel_color(12145, 7, 7, 7);
    set_sprite_pixel_color(12146, 7, 7, 7);
    set_sprite_pixel_color(12155, 7, 7, 7);
    set_sprite_pixel_color(12156, 7, 7, 7);
    set_sprite_pixel_color(12165, 7, 7, 7);
    set_sprite_pixel_color(12166, 7, 7, 7);
    set_sprite_pixel_color(12175, 7, 7, 7);
    set_sprite_pixel_color(12176, 7, 7, 7);
    set_sprite_pixel_color(12185, 7, 7, 7);
    set_sprite_pixel_color(12186, 7, 7, 7);
    set_sprite_pixel_color(12195, 7, 7, 7);
    set_sprite_pixel_color(12196, 7, 7, 7);
    set_sprite_pixel_color(12205, 7, 7, 7);
    set_sprite_pixel_color(12206, 7, 7, 7);
    set_sprite_pixel_color(12215, 7, 7, 7);
    set_sprite_pixel_color(12216, 7, 7, 7);
    set_sprite_pixel_color(12225, 7, 7, 7);
    set_sprite_pixel_color(12226, 7, 7, 7);
    set_sprite_pixel_color(12235, 7, 7, 7);
    set_sprite_pixel_color(12236, 7, 7, 7);
    set_sprite_pixel_color(12245, 7, 7, 7);
    set_sprite_pixel_color(12246, 7, 7, 7);
    set_sprite_pixel_color(12255, 7, 7, 7);
    set_sprite_pixel_color(12256, 7, 7, 7);
    set_sprite_pixel_color(12265, 7, 7, 7);
    set_sprite_pixel_color(12266, 7, 7, 7);
    set_sprite_pixel_color(12275, 7, 7, 7);
    set_sprite_pixel_color(12276, 7, 7, 7);
    set_sprite_pixel_color(12285, 7, 7, 7);
    set_sprite_pixel_color(12286, 7, 7, 7);
    set_sprite_pixel_color(12294, 7, 7, 7);
    set_sprite_pixel_color(12295, 7, 7, 7);
    set_sprite_pixel_color(12296, 7, 7, 7);
    set_sprite_pixel_color(12305, 7, 7, 7);
    set_sprite_pixel_color(12306, 7, 7, 7);
    set_sprite_pixel_color(12312, 7, 7, 7);
    set_sprite_pixel_color(12313, 7, 7, 7);
    set_sprite_pixel_color(12314, 7, 7, 7);
    set_sprite_pixel_color(12315, 7, 7, 7);
    set_sprite_pixel_color(12325, 7, 7, 7);
    set_sprite_pixel_color(12326, 7, 7, 7);
    set_sprite_pixel_color(12327, 7, 7, 7);
    set_sprite_pixel_color(12328, 7, 7, 7);
    set_sprite_pixel_color(12329, 7, 7, 7);
    set_sprite_pixel_color(12330, 7, 7, 7);
    set_sprite_pixel_color(12331, 7, 7, 7);
    set_sprite_pixel_color(12332, 7, 7, 7);
    set_sprite_pixel_color(12333, 7, 7, 7);
    set_sprite_pixel_color(12345, 7, 7, 7);
    set_sprite_pixel_color(12346, 7, 7, 7);
    set_sprite_pixel_color(12347, 7, 7, 7);
    set_sprite_pixel_color(12348, 7, 7, 7);
    set_sprite_pixel_color(12349, 7, 7, 7);
    set_sprite_pixel_color(12350, 7, 7, 7);
    set_sprite_pixel_color(12351, 7, 7, 7);

    set_sprite(13, 0, 480, 28, 1);
    set_sprite(14, 20, 480, 29, 1);
    set_sprite(15, 40, 480, 30, 1);


    close__gpu_devide();


    return 0;
}
