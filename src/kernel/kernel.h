#ifndef GINGER_KERNEL_H
#define GINGER_KERNEL_H

#define VGA_ADDRESS 0xB8000
#define BUFSIZE     2200

#define TRUE        1
#define FALSE       0

#define NULL        0
//ginger consts

#include "types.h"

static String* commands;

static Ui32    command_char_num = 0;
static Ui32    command_num = 0;

static Ui16*   vga_buffer;
static Ui32    vga_index;
static Ui32    next_line = 1;

int __ascii_numbers[10] = { 
    0x30,
    0x31,
    0x32,
    0x33,
    0x34,
    0x35,
    0x36,
    0x37,
    0x38,
    0x39
};


#include "vga.h"
#define __def_back_color BLACK
#define __def_fore_color WHITE

#include "stdfn.h"
#include "keys.h"
#include "io.h"
#include "aliases.h"
//ginger kernel modules

#endif
//ginger kernel header