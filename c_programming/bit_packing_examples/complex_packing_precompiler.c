#include <stdint.h>
#include <stdio.h>

// Ensure the compiler does not add padding
#pragma pack(push, 1)
typedef struct {
    uint8_t field1 : 3; // 3 bits
    uint8_t field2 : 5; // 5 bits
    uint8_t field3 : 4; // 4 bits
    uint8_t field4 : 4; // 4 bits
} ComplexHardwareRegister;
#pragma pack(pop)

uint16_t read_complex_register() {
    // Simulate reading a hardware register. In a real scenario, this would be a memory-mapped I/O register read.
    return 0b1010011101111001; // Example value
}

ComplexHardwareRegister read_complex_hardware_register() {
    uint16_t raw_value = read_complex_register();

    ComplexHardwareRegister reg;
    reg.field1 = raw_value & 0x07; // Mask for 3 bits (0b0000000000000111)
    reg.field2 = (raw_value >> 3) & 0x1F; // Mask for 5 bits (0b0000000000011111)
    reg.field3 = (raw_value >> 8) & 0x0F; // Mask for 4 bits (0b0000000011110000)
    reg.field4 = (raw_value >> 12) & 0x0F; // Mask for 4 bits (0b0000111100000000)

    return reg;
}

void write_complex_register(uint16_t value) {
    // Simulate writing to a hardware register. In a real scenario, this would be a memory-mapped I/O register write.
    printf("Complex register written with value: 0x%04X\n", value);
}

void write_complex_hardware_register(ComplexHardwareRegister reg) {
    uint16_t raw_value = ((reg.field4 & 0x0F) << 12) |
                         ((reg.field3 & 0x0F) << 8)  |
                         ((reg.field2 & 0x1F) << 3)  |
                         (reg.field1 & 0x07);
    write_complex_register(raw_value);
}

int main() {
    ComplexHardwareRegister reg = read_complex_hardware_register();
    printf("Read field1: %u, field2: %u, field3: %u, field4: %u\n",
           reg.field1, reg.field2, reg.field3, reg.field4);

    reg.field1 = 0x03; // Example modification
    reg.field2 = 0x15; // Example modification
    reg.field3 = 0x09; // Example modification
    reg.field4 = 0x0A; // Example modification
    write_complex_hardware_register(reg);

    return 0;
}
