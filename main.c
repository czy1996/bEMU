#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include "nes/disassembler.h"
#include "nes/nes.h"
#include "emulator.h"
#include "stdio.h"

int main(int argc, char *argv[]) {
    int tmp;

    /* 读入 NES ROM */
    tmp = nes_load_rom(argv[1]);
    if(tmp != 0) {
        printf("NES rom load failed, error code: %d", tmp);
        exit(0);
    }

    /* 显示 NES ROM 的相关信息 */
    //nes_print_rom_metadata();

    /* 反汇编 */
    //disasm(cartridge.prg_rom, cartridge.prg_rom_size);

    emu_init();
    emu_run();

    // TODO: 如果收到 SIGINT，也应该执行 nes_exit()
    nes_exit();
    return 0;
}
