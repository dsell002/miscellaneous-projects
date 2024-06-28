#include <stdio.h>
#include <stdint.h>

#define GPIO_BASE 0x3F200000
#define GPIO_SET *(volatile uint32_t *)(GPIO_BASE + 0x1C)
#define GPIO_CLR *(volatile uint32_t *)(GPIO_BASE + 0x28)

int main() {
    // Set GPIO pin
    GPIO_SET = (1 << 17);
    printf("GPIO pin set\n");

    // Clear GPIO pin
    GPIO_CLR = (1 << 17);
    printf("GPIO pin cleared\n");

    return 0;
}
