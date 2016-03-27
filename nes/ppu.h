//
// Created by Blanboom on 16/3/22.
//

#ifndef BEMU_PPU_H
#define BEMU_PPU_H

#include <stdbool.h>
#include <stdint.h>

/* 存储像素的坐标和颜色 */
struct Pixel {
    int x, y;
    int color;
};
typedef struct Pixel Pixel;

/* PixelBuf, 存储 PPU 最终生成的图像信息，供 Allegro 之类的多媒体库使用 */
struct PixelBuf {
    Pixel buf[264*264];
    int size;
};
typedef struct PixelBuf PixelBuf;

extern PixelBuf bg, bbg, fg;  // 背景，背景后的 Sprite，背景前的 Sprite

void ppu_init();
uint8_t ppu_io_read(uint16_t address);
void ppu_io_write(uint16_t address, uint8_t data);
void ppu_sprram_write(uint8_t data);
void ppu_set_mirroring(uint8_t mirroring);
void ppu_copy(uint16_t address, uint8_t *source, int length);
void ppu_run(int cycles);
uint8_t ppu_ram_read(uint16_t address);
bool ppu_show_background();
bool ppu_show_sprites();
void pixelbuf_clean(PixelBuf pbuf);
void pixelbuf_add(PixelBuf pbuf, int x, int y, int color);

typedef struct _rgb {
	int r;
	int g;
	int b;
} color_rgb;

/* 对应的 RGB 色彩 */
static const color_rgb palette[64] = {
	{ 0x80, 0x80, 0x80 },
	{ 0x00, 0x00, 0xBB },
	{ 0x37, 0x00, 0xBF },
	{ 0x84, 0x00, 0xA6 },
	{ 0xBB, 0x00, 0x6A },
	{ 0xB7, 0x00, 0x1E },
	{ 0xB3, 0x00, 0x00 },
	{ 0x91, 0x26, 0x00 },
	{ 0x7B, 0x2B, 0x00 },
	{ 0x00, 0x3E, 0x00 },
	{ 0x00, 0x48, 0x0D },
	{ 0x00, 0x3C, 0x22 },
	{ 0x00, 0x2F, 0x66 },
	{ 0x00, 0x00, 0x00 },
	{ 0x05, 0x05, 0x05 },
	{ 0x05, 0x05, 0x05 },
	{ 0xC8, 0xC8, 0xC8 },
	{ 0x00, 0x59, 0xFF },
	{ 0x44, 0x3C, 0xFF },
	{ 0xB7, 0x33, 0xCC },
	{ 0xFF, 0x33, 0xAA },
	{ 0xFF, 0x37, 0x5E },
	{ 0xFF, 0x37, 0x1A },
	{ 0xD5, 0x4B, 0x00 },
	{ 0xC4, 0x62, 0x00 },
	{ 0x3C, 0x7B, 0x00 },
	{ 0x1E, 0x84, 0x15 },
	{ 0x00, 0x95, 0x66 },
	{ 0x00, 0x84, 0xC4 },
	{ 0x11, 0x11, 0x11 },
	{ 0x09, 0x09, 0x09 },
	{ 0x09, 0x09, 0x09 },
	{ 0xFF, 0xFF, 0xFF },
	{ 0x00, 0x95, 0xFF },
	{ 0x6F, 0x84, 0xFF },
	{ 0xD5, 0x6F, 0xFF },
	{ 0xFF, 0x77, 0xCC },
	{ 0xFF, 0x6F, 0x99 },
	{ 0xFF, 0x7B, 0x59 },
	{ 0xFF, 0x91, 0x5F },
	{ 0xFF, 0xA2, 0x33 },
	{ 0xA6, 0xBF, 0x00 },
	{ 0x51, 0xD9, 0x6A },
	{ 0x4D, 0xD5, 0xAE },
	{ 0x00, 0xD9, 0xFF },
	{ 0x66, 0x66, 0x66 },
	{ 0x0D, 0x0D, 0x0D },
	{ 0x0D, 0x0D, 0x0D },
	{ 0xFF, 0xFF, 0xFF },
	{ 0x84, 0xBF, 0xFF },
	{ 0xBB, 0xBB, 0xFF },
	{ 0xD0, 0xBB, 0xFF },
	{ 0xFF, 0xBF, 0xEA },
	{ 0xFF, 0xBF, 0xCC },
	{ 0xFF, 0xC4, 0xB7 },
	{ 0xFF, 0xCC, 0xAE },
	{ 0xFF, 0xD9, 0xA2 },
	{ 0xCC, 0xE1, 0x99 },
	{ 0xAE, 0xEE, 0xB7 },
	{ 0xAA, 0xF7, 0xEE },
	{ 0xB3, 0xEE, 0xFF },
	{ 0xDD, 0xDD, 0xDD },
	{ 0x11, 0x11, 0x11 },
	{ 0x11, 0x11, 0x11 }
};

#endif //BEMU_PPU_H
