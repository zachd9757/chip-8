// Author: Zach DeShaw
// A CHIP-8 emulator (interpreter) based on this guie: https://tobiasvl.github.io/blog/write-a-chip-8-emulator/

#include <stdio.h>
#include <stdlib.h>
#include "chip-8.h"

const char* font[] = {
    "0xF0", "0x90", "0x90", "0x90", "0xF0", // 0
    "0x20", "0x60", "0x20", "0x20", "0x70", // 1
    "0xF0", "0x10", "0xF0", "0x80", "0xF0", // 2
    "0xF0", "0x10", "0xF0", "0x10", "0xF0", // 3
    "0x90", "0x90", "0xF0", "0x10", "0x10", // 4
    "0xF0", "0x80", "0xF0", "0x10", "0xF0", // 5
    "0xF0", "0x80", "0xF0", "0x90", "0xF0", // 6
    "0xF0", "0x10", "0x20", "0x40", "0x40", // 7
    "0xF0", "0x90", "0xF0", "0x90", "0xF0", // 8
    "0xF0", "0x90", "0xF0", "0x10", "0xF0", // 9
    "0xF0", "0x90", "0xF0", "0x90", "0x90", // A
    "0xE0", "0x90", "0xE0", "0x90", "0xE0", // B
    "0xF0", "0x80", "0x80", "0x80", "0xF0", // C
    "0xE0", "0x90", "0x90", "0x90", "0xE0", // D
    "0xF0", "0x80", "0xF0", "0x80", "0xF0", // E
    "0xF0", "0x80", "0xF0", "0x80", "0x80"  // F
};

/* 
 * Initializes the interpreter.
 */
void init(struct CHIP8* chip) {
    // Init memory
    chip = (struct CHIP8*) malloc(sizeof(struct CHIP8*));
    if (chip == NULL) {
        perror("Could not allocate memory");
    }

    // Store font in memory
    size_t num_font_hexes = sizeof(font) / sizeof(font[0]);

    for (size_t i = 0; i < num_font_hexes; i++) {
        //TODO: Find out why the type of memory[x] is wrong type
        sscanf(font[i], "%hhx", chip->memory[i + FONT_OFFSET]);
    }
}

/* 
 * Entry point of the emulator.
 */
int main() {
    // Initialize CHIP8
    struct CHIP8* chip;
    init(chip);
    printf("%x\n", chip->memory[0x050]);
}