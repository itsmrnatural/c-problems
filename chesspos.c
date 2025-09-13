#include <stdint.h>

typedef enum {
    CAN_NOT_ATTACK,
    CAN_ATTACK,
    INVALID_POSITION
} attack_status;

typedef struct {
    uint8_t row;
    uint8_t column;
} postion;

attack_status can_attack(postion queen1, postion queen2) {
    if (queen1.row > 7 || queen2.row > 7) {
        return INVALID_POSITION;
    } else if (queen1.column > 7 || queen2.column > 7) {
        return INVALID_POSITION;
    }

    if (queen1.row == queen2.row) {
        return CAN_ATTACK;
    } else if (queen1.column == queen2.column) {
        return CAN_ATTACK;
    } else if ((queen1.row - queen2.row) == (queen1.column - queen2.column)) {
        return CAN_ATTACK;
    } else {
        return CAN_NOT_ATTACK;
    }
}