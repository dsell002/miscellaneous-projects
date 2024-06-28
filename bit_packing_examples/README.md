# Bit Packing Examples

This directory contains examples demonstrating how to handle bit packing in C to interface with hardware registers. These examples address issues related to structure padding, memory alignment, and ensuring that no extraneous data is copied when reading from or writing to hardware registers.

## Files

1. **simple_packing.c**
   - Demonstrates how to define a simple bit-packed structure, read from a hardware register, and write to a hardware register.
   - Ensures that only the relevant bits are manipulated, avoiding unintended manipulation of surrounding memory.

2. **simple_packing_precompiler.c**
   - Similar to `simple_packing.c` but uses precompiler directives (`#pragma pack`) to ensure no padding is added by the compiler.

3. **complex_packing.c**
   - Extends the concept to a more complex structure with multiple fields.
   - Shows how to handle larger data sizes and multiple bit-fields within a single register.

4. **complex_packing_precompiler.c**
   - Similar to `complex_packing.c` but uses precompiler directives (`#pragma pack`) to ensure no padding is added by the compiler.

## Overview

### `simple_packing.c`

This example defines a structure `HardwareRegister` with two bit-fields and demonstrates how to:
- Read from a simulated hardware register.
- Mask the relevant bits and populate the structure fields.
- Write the structure back to the simulated hardware register.

### `simple_packing_precompiler.c`

This example is similar to `simple_packing.c` but includes precompiler directives to ensure the structure is packed without any padding.

### `complex_packing.c`

This example defines a more complex structure `ComplexHardwareRegister` with four bit-fields and demonstrates how to:
- Read from a simulated hardware register with multiple fields.
- Mask and shift the relevant bits to populate the structure fields.
- Write the structure back to the simulated hardware register, ensuring only the intended bits are modified.

### `complex_packing_precompiler.c`

This example is similar to `complex_packing.c` but includes precompiler directives to ensure the structure is packed without any padding.

## Usage

To compile and run these examples, use the following commands:

```bash
gcc -o simple_packing simple_packing.c
./simple_packing

gcc -o simple_packing_precompiler simple_packing_precompiler.c
./simple_packing_precompiler

gcc -o complex_packing complex_packing.c
./complex_packing

gcc -o complex_packing_precompiler complex_packing_precompiler.c
./complex_packing_precompiler
