#include <stdint.h>
#include <stdlib.h>

typedef enum {
    CAN_NOT_ATTACK,
    CAN_ATTACK,
    INVALID_POSITION
} attack_status;

typedef struct {
    uint8_t row;
    uint8_t column;
} position;

attack_status can_attack(position queen1, position queen2) {
    if (queen1.row > 7 || queen2.row > 7) {
        return INVALID_POSITION;
    } else if (queen1.column > 7 || queen2.column > 7) {
        return INVALID_POSITION;
    } else if (queen1.row == queen2.row && queen1.column == queen2.column) {
        return INVALID_POSITION;
    }

    if (queen1.row == queen2.row) {
        return CAN_ATTACK;
    } else if (queen1.column == queen2.column) {
        return CAN_ATTACK;
    } else if (abs(queen1.row - queen2.row) == abs(queen1.column - queen2.column)) {
        return CAN_ATTACK;
    } else {
        return CAN_NOT_ATTACK;
    }
}