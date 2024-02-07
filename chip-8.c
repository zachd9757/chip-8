// Author: Zach DeShaw
// A CHIP-8 interpreter based on this guide: https://tobiasvl.github.io/blog/write-a-chip-8-emulator/
// Specification reference: http://devernay.free.fr/hacks/chip8/C8TECH10.HTM#font

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

/* init
 * Initializes the interpreter.
 */
void chip_init(Chip** chip) {
    // Initialize memory
    *chip = (struct CHIP8*) malloc(sizeof(struct CHIP8*));
    if (*chip == NULL) {
        perror("Could not allocate memory");
        exit(EXIT_FAILURE);
    }

    // Store font in memory
    size_t num_font_hexes = sizeof(font) / sizeof(font[0]);

    for (size_t i = 0; i < num_font_hexes; i++) {
        sscanf(font[i], "%hhx", &(*chip)->memory[i + FONT_OFFSET]);
    }

    // Initialize stack
    (*chip)->stack = malloc(sizeof(Stack));
    (*chip)->stack->top = -1;
    
    for (size_t i = 0; i < STACK_SIZE; i++) {
        (*chip)->stack->values[i] = STACK_EMPTY;
    }

    //TODO: timers
    // Initialize timers
    if (pthread_mutex_init(&(*chip)->dt_mutex, NULL) != 0) { perror("Error initializing dt_mutex "); }
    if (pthread_mutex_init(&(*chip)->dt_mutex, NULL) != 0) { perror("Error initializing dt_mutex "); }
    
    (*chip)->dt = 0;
    (*chip)->st = 0;

    // Initialize threads to operate timers
    pthread_t dt_thread, st_thread;
    pthread_create(dt_thread, NULL, delay_timer, chip);
    pthread_create(st_thread, NULL, sound_timer, chip);
}

/* stack_pop
 * Returns and removes the top value in the stack.
 */
uint16_t stack_pop(Stack** stack) {
    // Grab value
    uint16_t result = (*stack)->values[(*stack)->top];

    // Remove element
    (*stack)->values[(*stack)->top] = STACK_EMPTY;

    // Update stack top
    (*stack)->top--;

    return result;
}

/* stack_push
 * Pushes value on to the top of the stack. Returns 0 on success and -1 on failure (overflow).
 */
int stack_push(Stack** stack, uint16_t value) {
    // Find index to place value
    for (size_t i = 0; i < STACK_SIZE; i++) {
        // If empty slot found, place the value
        if ((*stack)->values[i] == STACK_EMPTY) {
            (*stack)->values[i] = value;
            // Update stack top
            (*stack)->top++;
            return 0;
        }
    }

    // Stack overflow
    return -1;
}

/* delay_timer (thread function)
 * Decrements the delay timer approximately 60 times/second.
 */
int delay_timer(Chip** chip) {
    //TODO:
}

/* sound_timer (thread function)
 * Decrements the sound timer approximately 60 times/second. Produces a beep when timer > 0.
 */
int sound_timer(Chip** chip) {
    //TODO:
}