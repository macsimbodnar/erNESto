#include "pixello.hpp"
#include "mos6502.hpp"
#include "ppu.hpp"
#include "cartridge.hpp"
#include <iostream>

constexpr uint32_t w = 60;
constexpr uint32_t h = 40;

class pixel : public pixello {
public:
  pixel() : pixello({w, h, 600, 400, 100, 100, "Test pixello", 60}) {}

private:
  void log(const std::string &msg) override { std::cout << msg << std::endl; }

  void on_update() override {
    // clear({0xFF000000});

    for (uint32_t i = 0; i < 1000; i++) {
      const uint32_t x = (rand() % (w - 2)) + 1;
      const uint32_t y = (rand() % (h - 2)) + 1;

      pixel_t p;
      p.r = rand() % 255;
      p.g = rand() % 255;
      p.b = rand() % 255;
      p.a = 255;

      draw(x, y, p);
    }

    pixel_t p;
    p.a = 255;

    p.r = 255;
    p.g = 0;
    p.b = 0;
    draw(0, 0, p); // top left red

    p.r = 0;
    p.g = 255;
    p.b = 0;
    draw(w - 1, 0, p); // top tight green

    p.r = 0;
    p.g = 0;
    p.b = 255;
    draw(w - 1, h - 1, p); // bottom right blu

    p.r = 255;
    p.g = 0;
    p.b = 255;
    draw(0, h - 1, p); // bottom left purple
  }
};

#define TEST_START_LOCATION 0xC000

static void log_clb(const std::string &log) {
  std::cout << "[CPU] " << log << std::endl;
}

static void mem_callback(void *usr_data, const uint16_t address,
                         const access_mode_t read_write, uint8_t &data) {}

int main() {

  MOS6502 cpu(mem_callback, nullptr);
  cpu.set_log_callback(log_clb);
  cpu.reset();
  cpu.set_PC(TEST_START_LOCATION);

  pixel p;

  p.run();

  return 0;
}