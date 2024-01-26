// A CHIP-8 emulator (interpreter) based on this guie: https://tobiasvl.github.io/blog/write-a-chip-8-emulator/
// Author: Zach DeShaw
#include "chip-8.h"

// Initializes the interpreter
void init(struct CHIP8* chip) {
    // Init memory
    chip = (struct CHIP8*) calloc(1, sizeof(struct CHIP8*));

    //TODO: init
}

int main() {
    // Initialize CHIP8
    struct CHIP8* chip;
    init(&chip);

}