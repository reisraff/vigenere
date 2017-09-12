#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char presentation_string[] =
    "Usage:\n"
    "  command key input\n"
    "\n"
    "Available commands:\n"
    "  encode   Encode\n"
    "  decode   Decode\n"
    ;

int shift(char *key, int c) {
    unsigned int i = c % strlen(key);
    if (key[i] < 65 || key[i] > 90) {
        puts("Key phrase must contain only capital letters");
        exit(1);
    }

    return key[i] - 65;
}

int main(int argc, char **argv) {
    if (argc != 4 || (strcmp(argv[1], "decode") && strcmp(argv[1], "encode"))) {
        printf("%s", presentation_string);
        exit(0);
    }

    unsigned short i;
    char result[strlen(argv[3])];

    for (i = 0; i < strlen(argv[3]); i++) {
        int c = ((int) argv[3][i]);

        if (!strcmp(argv[1], "decode")) {
            if (c < 65 || c > 90) {
                puts("Ciphertext must contain only capital letters");
                exit(1);
            }

            result[i] = c - shift(argv[2], i) < 65 ? c - shift(argv[2], i) + 26 : c - shift(argv[2], i);
        } else {
            if (c < 65 || c > 90) {
                puts("Open text must contain only capital letters");
                exit(1);
            }

            result[i] = c + shift(argv[2], i) > 90 ? c + shift(argv[2], i) - 26 : c + shift(argv[2], i);
        }
    }

    printf("%s\n", result);

    return 0;
}
