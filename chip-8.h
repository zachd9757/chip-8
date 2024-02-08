// Author: Zach DeShaw
// chip-8.h - Defines the core interpreter struct, its methods, and its internal structs.
// A CHIP-8 interpreter based on this guide: https://tobiasvl.github.io/blog/write-a-chip-8-emulator/
// Specification reference: http://devernay.free.fr/hacks/chip8/C8TECH10.HTM#font


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <pthread.h>

/*==============    Constants     ==============*/

// Memory
#define MEM_START           ( 0x200 )   // CHIP-8 programs are to be loaded into memory here (originally, the interpreter was stored in the front of memory, creating a need for this offset)
#define FONT_OFFSET         ( 0x050 )   // Storage location of the font in memory

// Display
#define DISPLAY_WIDTH       ( 64 )
#define DISPLAY_HEIGHT      ( 32 )

// Stack
#define STACK_SIZE          ( (size_t) 16 )
#define STACK_EMPTY         ( 0x0000 )

// Timers
#define TIMER_ZERO          ( 0 )
// #define SIXTIETH_OF_SEC     ( (useconds_t) 16667 )

/*============== Global Variables ==============*/
/*==============      Structs     ==============*/

// Stack
typedef struct chipstack {
    uint16_t values[STACK_SIZE];        // Stack -- 16 16-bit entries
    int top;                            // Index of top of stack
} Stack;

// CHIP-8 interpreter
typedef struct CHIP8 {
    unsigned char memory[4096];         // RAM -- should be writeable
    uint16_t pc;                        // Program counter
    Stack* stack;
    // The delay timer is active whenever the delay timer register (DT)
    // is non-zero. This timer does nothing more than subtract 1 from the
    // value of DT at a rate of 60Hz. When DT reaches 0, it deactivates.
    int dt;
    // The sound timer is active whenever the sound timer register (ST) is
    // non-zero. This timer also decrements at a rate of 60Hz, however, as long
    // as ST's value is greater than zero, the Chip-8 buzzer will sound. When
    // ST reaches zero, the sound timer deactivates.
    int st;
} Chip;

/*==============      Structs     ==============*/
/*==============    Functions     ==============*/

// CHIP-8 emulator
void chip_init(struct CHIP8** chip);

// Stack
uint16_t stack_pop(Stack** stack);
int stack_push(Stack** stack, uint16_t value);

// Timers
void delay_timer(Chip** chip);
void sound_timer(Chip** chip);

/*==============    Functions     ==============*/