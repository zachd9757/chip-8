// Author: Zach DeShaw
// Header file for chip-8.c

/*============== Global Variables ==============*/
// Memory
#define MEM_START ( 0x200 )         // CHIP-8 programs are to be loaded into memory here (originally, the interpreter was stored in the front of memory, creating a need for this offset)
#define FONT_OFFSET  ( 0x050 )      // Storage location of the font in memory

// Display
#define DISPLAY_WIDTH ( 64 )
#define DISPLAY_HEIGHT ( 32 )

/*==============      Structs     ==============*/
struct CHIP8 {
    unsigned char memory[4096];     // RAM, should be writeable
    int pc;                         // Program counter
};

/*==============    Functions     ===============*/
void init(struct CHIP8** chip);