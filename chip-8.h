// Author: Zach DeShaw
// Header file for chip-8.c

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*============== Global Variables ==============*/
// Memory
#define MEM_START       ( 0x200 )       // CHIP-8 programs are to be loaded into memory here (originally, the interpreter was stored in the front of memory, creating a need for this offset)
#define FONT_OFFSET     ( 0x050 )       // Storage location of the font in memory

// Display
#define DISPLAY_WIDTH   ( 64 )
#define DISPLAY_HEIGHT  ( 32 )

// Stack
#define STACK_SIZE      ( (size_t)16 )
#define EMPTY_VAL       ( -1 )

/*==============      Structs     ==============*/
// CHIP-8 emulator
struct CHIP8 {
    unsigned char memory[4096];     // RAM -- should be writeable
    uint16_t pc;                    // Program counter
    struct chipstack stack;         //TODO: Make this ptr?
};

struct chipstack {
    uint16_t values[STACK_SIZE];    // Stack -- 16 16-bit entries
    size_t* top;                    // Pointer to top of stack
};

/*==============      Structs     ==============*/
/*==============    Functions     ==============*/
// CHIP-8 emulator
void chip_init(struct CHIP8** chip);

// Stack
uint16_t stack_pop(uint16_t** stack);
int stack_push(struct chipstack** stack, uint16_t value);