#include <algorithm>
#include <cstdint>
#include <iostream>

extern void division_by_zero();
int32_t next();

namespace simplevm {
int32_t execute() {
    int32_t registers[4] = {0, 0, 0, 0};
    bool stop_flag = false;
    while (!stop_flag) {
        int32_t opcode = next();
        switch (opcode) {
            case 0: { // End of execution
                stop_flag = true;
                break;
            }
            case 10: {
                int ireg = next();
                int iimm = next();
                registers[ireg] = iimm;
                break;
            }
            case 20: {
                int ireg = next();
                registers[0] = registers[ireg];
                break;
            }
            case 21: {
                int ireg = next();
                registers[ireg] = registers[0];
                break;
            }
            case 22: {
                std::swap(registers[0], registers[1]);
                break;
            }
            case 50: { // addi
                registers[0] = static_cast<int32_t>(static_cast<uint32_t>(registers[0]) + static_cast<uint32_t>(registers[1]));
                break;
            }
            case 51: { // subi
                registers[0] = static_cast<int32_t>(static_cast<uint32_t>(registers[0]) - static_cast<uint32_t>(registers[1]));
                break;
            }
            case 53: { // muli
                registers[0] = static_cast<int32_t>(static_cast<uint32_t>(registers[0]) * static_cast<uint32_t>(registers[1]));
                break;
            }
            case 54: { // divi
                if (registers[1] == 0) {
                    division_by_zero();
                    return 0;
                }
                int32_t quotient = registers[0] / registers[1];
                int32_t remainder = registers[0] % registers[1];

                registers[0] = quotient;
                registers[1] = remainder;
                break;
            }
            default: {
                // default
                break;
            }
        }
    }
    return registers[0];
}
} // namespace simplevm
