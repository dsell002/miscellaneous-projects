#include <stdio.h>

#define SET_BIT(value, bit) ((value) |= (1U << (bit)))
#define CLEAR_BIT(value, bit) ((value) &= ~(1U << (bit)))
#define TOGGLE_BIT(value, bit) ((value) ^= (1U << (bit)))
#define CHECK_BIT(value, bit) (((value) >> (bit)) & 1U)

int main() {
    uint8_t value = 0b00001111;

    // Set bit 7
    SET_BIT(value, 7);
    printf("After setting bit 7: 0x%02X\n", value);

    // Clear bit 3
    CLEAR_BIT(value, 3);
    printf("After clearing bit 3: 0x%02X\n", value);

    // Toggle bit 2
    TOGGLE_BIT(value, 2);
    printf("After toggling bit 2: 0x%02X\n", value);

    // Check bit 7
    printf("Bit 7 is %s\n", CHECK_BIT(value, 7) ? "set" : "clear");

    return 0;
}
