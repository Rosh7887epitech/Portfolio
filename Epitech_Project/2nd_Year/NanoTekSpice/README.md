# NanoTekSpice

## Description
NanoTekSpice is a digital circuit simulator written in C++, developed as part of the Epitech second year curriculum. This program reads circuit description files (`.nts`), parses the components and connections, and simulates the behavior of the circuit via an interactive command-line interface.

## Features
- Fully modular component system.
- Supports simple components:
    - Input
    - Output
    - Clock
    - True (constant high)
    - False (constant low)
- Supports logic gates:
    - AND
    - OR
    - XOR
    - NOT
    - NAND
    - NOR
- Supports multi-gate components:
    - 4001: Quad NOR gate
    - 4011: Quad NAND gate
    - 4030: Quad XOR gate
    - 4069: Hex Inverter gate
    - 4071: Quad OR gate
    - 4081: Quad AND gate
- Interactive CLI for simulation control.

## How to Use
### Build
```bash
make
```

### Run
```bash
./nanotekspice path/to/circuit.nts
```

### Commands
Once the program is running, you can use the following commands in the CLI:
- `simulate`: Run a simulation step.
- `display`: Show the state of all components.
- `input name=value`: Change the value of an input component.
- `exit`: Quit the program.
- `loop`: Run a simulation step & show the state of all components in loop (Stop with CTRL+C).

## File Format - `.nts`
The `.nts` file describes the components in the circuit and their connections.

### Example
```
.chipsets:
input in
input in1
and and
output out
.links:
in:1 and:1
in1:1 and:2
and:3 out:1
```

This example defines:
- Input `in`
- Input `in1`
- Output `out`
- Gate `and`
- Link input to `and:1 & and:2`
- Link Output to `out:1`



## Project Structure
```
src/
    baseComponent/
    simpleComponent/
    gateComponent/
    Main & structure
include/
    all .hpp
```

## Authors
- Titouan Bouillot Bachelier - Developer
- Robin Schuffenecker - Developer

## License
This project does not include a specific license.
