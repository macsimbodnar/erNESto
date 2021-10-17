#pragma once
#include "mos6502.hpp"
#include "ppu.hpp"

class erNEStop {
public:
private:
  //----CPU
  MOS6502 cpu;
  std::array<uint8_t, 2 * 1024> cpu_ram;

  inline void cpu_write(uint16_t addr, uint8_t data) {
    if (addr >= 0x0000 && addr <= 0x1FFF) {
      // We mirror the ram locations every 2Kb
      cpu_ram[addr & 0x07FF] = data;
    } else if (addr >= 0x2000 && addr <= 0x3FFF) {
        // Write to ppu mem in just 8 address
        // ppu.write(addr & 0x0007, data);
    }
  }

  inline uint8_t cpu_read(uint16_t addr, bool read_only = false) {
    uint8_t data = 0x00;
    if (addr >= 0x0000 && addr <= 0x1FFF) {
      // We mirror the ram locations every 2Kb
      data = cpu_ram[addr & 0x07FF];
    } else if (addr >= 0x2000 && addr <= 0x3FFF) {
        // Read from ppu mem in just 8 address
        // data = ppu.read(addr & 0x0007, read_only);
    }

    return data;
  }

  PPU ppu;

  inline void ppu_write(uint16_t addr, uint8_t data) {
    if (addr >= 0x0000 && addr <= 0x1FFF) {
      // We mirror the ram locations every 2Kb
      cpu_ram[addr & 0x07FF] = data;
    }
  }

  inline uint8_t ppu_read(uint16_t addr, bool read_only = false) {
    uint8_t data = 0x00;
    if (addr >= 0x0000 && addr <= 0x1FFF) {
      // We mirror the ram locations every 2Kb
      return cpu_ram[addr & 0x07FF];
    }

    return 0x00;
  }
};