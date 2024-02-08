// Author: Zach DeShaw
// main.c - Entry point for the interpreter. Executes the main loop.
// A CHIP-8 interpreter based on this guide: https://tobiasvl.github.io/blog/write-a-chip-8-emulator/
// Specification reference: http://devernay.free.fr/hacks/chip8/C8TECH10.HTM#font

#include "chip-8.h"
#include <unistd.h>

pthread_mutex_t dt_mutex, st_mutex;

/* main
 * Entry point of the interpreter.
 */
int main() {
    // Init mutexes
    pthread_mutex_init(&dt_mutex, NULL);
    pthread_mutex_init(&st_mutex, NULL);

    // Init interpreter
    Chip* chip;
    chip_init(&chip);

    // Spawn threads to handle timers
    pthread_t dt_thread, st_thread;
    pthread_create(&dt_thread, NULL, delay_timer, &chip); //TODO: fix compile errors
    pthread_create(&st_thread, NULL, sound_timer, &chip); //TODO: fix compile errors

    return 0;
}

/* delay_timer (thread function)
 * Decrements the delay timer approximately 60 times/second.
 */
void delay_timer(Chip** chip) {
    while (1) {
        pthread_mutex_lock(&dt_mutex);
        if ((*chip)->dt > 0) {
            (*chip)->dt--;
            usleep(16667);  // Sleep for 1/60 second
        }
    }
}

/* sound_timer (thread function)
 * Decrements the sound timer approximately 60 times/second. Produces a beep when timer > 0.
 */
void sound_timer(Chip** chip) {
    while (1) {
        pthread_mutex_lock(&dt_mutex);
        if ((*chip)->st > 0) {
            (*chip)->st--;
            // system("aplay sound.mp3"); TODO: Figure out sound
            usleep(16667);  // Sleep for 1/60 second
        }
    }
}