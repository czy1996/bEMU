#ifndef BEMU_EMULATOR_H
#define BEMU_EMULATOR_H


void emu_init();
void emu_run();
void emu_update_screen();
void set_bg_color(int c);
int get_key_state(int b);

#endif
