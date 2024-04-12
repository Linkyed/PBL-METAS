#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>

//CODIGO QUE TESTA AS COORDENADAS DO MOUSE

#define MOUSEFILE "/dev/input/event0" // This might vary depending on your system

int main() {
    int fd;
    struct input_event ie;

    if ((fd = open(MOUSEFILE, O_RDONLY)) == -1) {
        perror("Cannot open mouse device");
        return 1;
    }

    printf("Reading from %s...\n", MOUSEFILE);

    while (1) {
        if (read(fd, &ie, sizeof(struct input_event)) != sizeof(struct input_event)) {
            perror("Error reading");
            return 1;
        }
        
        // Print X and Y values for all mouse events
        if (ie.type == EV_REL && (ie.code == REL_X || ie.code == REL_Y)) {
            printf("X=%d, Y=%d\n", ie.code == REL_X ? ie.value : 0, ie.code == REL_Y ? ie.value : 0);
        }
        
        // Check if event is a mouse button click event
        if (ie.type == EV_KEY && ie.code == BTN_LEFT && ie.value == 1) {
            printf("Left mouse button clicked!\n");
            sleep(1); // Sleep for 1 second
        }
    }

    close(fd);
    return 0;
}
