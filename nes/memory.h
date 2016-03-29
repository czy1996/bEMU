//
// Created by Blanboom on 16/3/16.
//

#ifndef BEMU_MEMORY_H
#define BEMU_MEMORY_H

#include <stdint.h>

// TODO: 仅用于调试
extern int prg_rom_size;

void memory_init(uint8_t *prg_rom, int prg_rom_length);
uint8_t memory_read_byte(uint16_t address);
uint16_t memory_read_word(uint16_t address);
void memory_write_byte(uint16_t address, uint8_t data);
void memory_write_word(uint16_t address, uint16_t data);

#endif //BEMU_MEMORY_H
