struct CHIP8 {
    char memory[4096];  // RAM, should be writeable
    int pc;             // Program counter
};

//TODO: global variable for memory start (address 200)