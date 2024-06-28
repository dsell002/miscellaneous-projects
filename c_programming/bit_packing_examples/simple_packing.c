#include <stdint.h>
#include <stdio.h>

typedef struct {
    uint8_t field1 : 3; // 3 bits
    uint8_t field2 : 5; // 5 bits
} HardwareRegister;

uint8_t read_register() {
    // Simulate reading a hardware register. In a real scenario, this would be a memory-mapped I/O register read.
    return 0b10100111; // Example value
}

HardwareRegister read_hardware_register() {
    uint8_t raw_value = read_register();

    HardwareRegister reg;
    reg.field1 = raw_value & 0x07; // Mask for 3 bits (0b00000111)
    reg.field2 = (raw_value >> 3) & 0x1F; // Mask for 5 bits (0b00011111)

    return reg;
}

void write_register(uint8_t value) {
    // Simulate writing to a hardware register. In a real scenario, this would be a memory-mapped I/O register write.
    printf("Register written with value: 0x%02X\n", value);
}

void write_hardware_register(HardwareRegister reg) {
    uint8_t raw_value = (reg.field2 << 3) | (reg.field1 & 0x07);
    write_register(raw_value);
}

int main() {
    HardwareRegister reg = read_hardware_register();
    printf("Read field1: %u, field2: %u\n", reg.field1, reg.field2);

    reg.field1 = 0x03; // Example modification
    reg.field2 = 0x15; // Example modification
    write_hardware_register(reg);

    return 0;
}
