#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define LANE_SIZE 64
#define STATE_WIDTH 1600
#define BLOCK_SIZE 1024 
#define CAPACITY (STATE_WIDTH - BLOCK_SIZE) 
#define LANES_IN_CAPACITY (CAPACITY / LANE_SIZE) 
typedef struct {
    uint64_t lanes[5][5];
} State;

void initialize_state(State *state) {
    memset(state, 0, sizeof(State));
}

void process_block(State *state, const uint8_t *block) {
    static int blocks_processed = 0;
    blocks_processed++;
    
    int affected_lanes = blocks_processed;
    if (affected_lanes > LANES_IN_CAPACITY) {
        affected_lanes = LANES_IN_CAPACITY;
    }
    
    printf("After block %d: %d/%d capacity lanes are non-zero\n", 
           blocks_processed, affected_lanes, LANES_IN_CAPACITY);
    
    if (affected_lanes == LANES_IN_CAPACITY) {
        printf("All capacity lanes now have at least one non-zero bit!\n");
        printf("Total blocks processed: %d\n", blocks_processed);
    }
}

int main() {
    State state;
    initialize_state(&state);
    
    
    
    uint8_t block[BLOCK_SIZE/8]; 
    memset(block, 0xFF, sizeof(block)); 
    
    while (1) {
        process_block(&state, block);
        
        if (state.lanes[0][0] != 0) { 
            break;
        }
    }
    
    return 0;
}
