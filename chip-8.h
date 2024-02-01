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
#define STACK_EMPTY     ( 0x0000 )

/*============== Global Variables ==============*/
/*==============      Structs     ==============*/

// Stack
typedef struct chipstack {
    uint16_t values[STACK_SIZE];    // Stack -- 16 16-bit entries
    int top;                        // Index of top of stack
} Stack;

// CHIP-8 emulator
typedef struct CHIP8 {
    unsigned char memory[4096];     // RAM -- should be writeable
    uint16_t pc;                    // Program counter
    Stack* stack;
} Chip;

/*==============      Structs     ==============*/
/*==============    Functions     ==============*/

// CHIP-8 emulator
void chip_init(struct CHIP8** chip);

// Stack
uint16_t stack_pop(Stack** stack);
int stack_push(Stack** stack, uint16_t value);

/*==============    Functions     ==============*/