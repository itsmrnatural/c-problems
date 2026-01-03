#include <stdint.h>
#include <stdlib.h>

typedef enum { CAN_NOT_ATTACK, CAN_ATTACK, INVALID_POSITION } atk_status;

typedef struct {
    uint8_t row;
    uint8_t col;
} position;

atk_status can_attack(position queen1, position queen2) {
    if (queen1.row > 7 || queen2.row > 7) {
        return INVALID_POSITION;
    } else if (queen1.col > 7 || queen2.col > 7) {
        return INVALID_POSITION;
    } else if (queen1.row == queen2.row && queen1.col == queen2.col) {
        return INVALID_POSITION;
    }

    if (queen1.row == queen2.row) {
        return CAN_ATTACK;
    } else if (queen1.col == queen2.col) {
        return CAN_ATTACK;
    } else if (abs(queen1.row - queen2.row) == abs(queen1.col - queen2.col)) {
        return CAN_ATTACK;
    } else {
        return CAN_NOT_ATTACK;
    }
}