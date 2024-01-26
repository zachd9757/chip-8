// Unit tests for the emulator.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "chip-8.h"

/*==============    Test Cases    ==============*/
int test1() {
    // Initialize CHIP8
    struct CHIP8* chip;
    init(&chip);
    assert(chip->memory[0x050] == 0xF0);
    assert(chip->memory[0x09F] == 0x80);

    return 0;
}


/*==============    Test Cases    ==============*/
/*============== Helper Functions ==============*/


/*============== Helper Functions ==============*/

/* main
 * Executes all of the tests and returns information on how many passed.
 */
int main() {
    int num_tests_passed, result = 0;

    clock_t start, end;
    double cpu_time_used;

    printf("Beginning test run -- test.c\n");

    // Record start time
    start = clock();
    if (start == (clock_t) -1) {
        perror("Failed to record start time");
        exit(EXIT_FAILURE);
    }

    // Execute tests
    if (test1() == 0) {
        num_tests_passed++;
    }

    // Record end time
    end = clock();
    if (end == (clock_t) -1) {
        perror("Failed to record end time");
        exit(EXIT_FAILURE);
    }

    // Calculate elapsed time
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print results
    printf("%d test(s) passed in %f seconds.\n", num_tests_passed, cpu_time_used);

    return 0;
}