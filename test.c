// Unit tests for the emulator.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "chip-8.h"

#define NUM_TESTS ( 1 )

/*==============    Test Cases    ==============*/
// Tests chip_init
int test0() {
    // Initialize CHIP8
    Chip* chip;
    chip_init(&chip);

    // Check that font is set up properly
    assert(chip->memory[0x050] == 0xF0);
    assert(chip->memory[0x09F] == 0x80);

    // Check that stack is set up properly
    for (size_t i = 0; i < STACK_SIZE; i++) {
        assert(chip->stack->values[i] == EMPTY_VAL);
    }

    return 0;
}


/*==============    Test Cases    ==============*/
/*============== Helper Functions ==============*/


/*============== Helper Functions ==============*/

/* main
 * Executes all of the tests and returns information on how many passed.
 */
int main() {
    int num_tests_passed, test_result;

    clock_t start, end;
    double cpu_time_used;

    int (*ptr[NUM_TESTS])();
    ptr[0] = test0;
    // ptr[1] = test1;

    printf("Beginning test run -- test.c\n");

    // Record start time
    start = clock();
    if (start == (clock_t) -1) {
        perror("Failed to record start time");
        exit(EXIT_FAILURE);
    }

    // Execute tests
    for(int i = 0; i < NUM_TESTS; i++) {
        if ((test_result = (*ptr[i])()) == 0) {
            num_tests_passed++;
        }
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