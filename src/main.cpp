#include <iostream>
#include "cartridge.hpp"
#include "mos6502.hpp"
#include "pixello.hpp"
#include "ppu.hpp"

constexpr int32_t pixel_size = 20;

class pixel : public pixello
{
public:
  pixel()
      : pixello(pixel_size,
                600,
                400,
                "erNESto",
                60,
                "assets/font/PressStart2P.ttf",
                10)
  {}

private:
  void on_init(void*) override {}

  void on_update(void*) override
  {
    // clear({0xFF000000});

    for (uint32_t i = 0; i < 1000; i++) {
      const uint32_t x = (rand() % (pixel_size - 2)) + 1;
      const uint32_t y = (rand() % (pixel_size - 2)) + 1;

      pixel_t p;
      p.r = rand() % 255;
      p.g = rand() % 255;
      p.b = rand() % 255;
      p.a = 255;

      draw_pixel(x, y, p);
    }

    pixel_t p;
    p.a = 255;

    p.r = 255;
    p.g = 0;
    p.b = 0;
    draw_pixel(0, 0, p);  // top left red

    p.r = 0;
    p.g = 255;
    p.b = 0;
    draw_pixel(pixel_size - 1, 0, p);  // top tight green

    p.r = 0;
    p.g = 0;
    p.b = 255;
    draw_pixel(pixel_size - 1, pixel_size - 1, p);  // bottom right blu

    p.r = 255;
    p.g = 0;
    p.b = 255;
    draw_pixel(0, pixel_size - 1, p);  // bottom left purple
  }
};

#define TEST_START_LOCATION 0xC000

static void log_clb(const std::string& log)
{
  std::cout << "[CPU] " << log << std::endl;
}

static void mem_callback(void* usr_data,
                         const uint16_t address,
                         const access_mode_t read_write,
                         uint8_t& data)
{}

int main()
{
  MOS6502 cpu(mem_callback, nullptr);
  cpu.set_log_callback(log_clb);
  cpu.reset();
  cpu.set_PC(TEST_START_LOCATION);

  pixel p;

  if (p.run()) { return EXIT_FAILURE; }

  return EXIT_SUCCESS;
}