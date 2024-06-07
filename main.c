#include "header.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define DEVICE_PATH "/dev/gpu_device"


int main () {

    int fd = open(DEVICE_PATH, O_WRONLY);

    if (fd < 0) {
        perror("Failed to open the device");
        return -1;
    }

    set_background_color(7, 0, 0, fd);

    close(fd);
    return 0;
}