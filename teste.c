#include <stdio.h>

int main() {
    char ch;

    printf("Press 'N' to continue: ");

    // Loop until the user inputs 'N'
    while (1) {
        ch = getchar();

        // Check if the input character is 'N'
        if (ch == 'N') {
            break;
        }

        // Clear the buffer if the input is not 'N'
        while (getchar() != '\n');
        
        printf("Please press 'N' to continue: ");
    }

    // Print the message after 'N' is pressed
    printf("You pressed 'N'. Continuing...\n");

    return 0;
}