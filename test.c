// Unit tests for the emulator.

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "chip-8.h"

#define NUM_TESTS ( 2 )

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
        assert(chip->stack->values[i] == STACK_EMPTY);
    }

    return 0;
}

// Tests stack push and pop
int test1() {
    // Initialize CHIP8
    Chip* chip;
    chip_init(&chip);

    // Push values and check
    stack_push(&(chip->stack), 0x1A2B);
    stack_push(&(chip->stack), 0xFFFF);
    stack_push(&(chip->stack), 0x1010);
    assert(chip->stack->values[0] == 0x1A2B);
    assert(chip->stack->values[1] == 0xFFFF);
    assert(chip->stack->values[2] == 0x1010);

    // Pop values and check
    uint16_t val0 = stack_pop(&(chip->stack));
    uint16_t val1 = stack_pop(&(chip->stack));
    uint16_t val2 = stack_pop(&(chip->stack));
    assert(val0 == (uint16_t) 0x1010);
    assert(val1 == (uint16_t) 0xFFFF);
    assert(val2 == (uint16_t) 0x1A2B);

    return 0;
}

/*==============    Test Cases    ==============*/
/*==============       Main       ==============*/

/* main
 * Executes all of the tests and returns information on how many passed.
 */
int main() {
    int num_tests_passed = 0;
    int test_result;

    clock_t start, end;
    double cpu_time_used;

    int (*ptr[NUM_TESTS])();
    ptr[0] = test0;
    ptr[1] = test1;

    printf("\nBEGINNING TEST EXECUTION -- test.c\n");

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

/*==============       Main       ==============*/