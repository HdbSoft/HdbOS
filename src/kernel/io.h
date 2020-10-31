#ifndef GINGER_IO_H
#define GINGER_IO_H

Ui8 __read_port(Ui16 port) {
	Ui8 ret;
	asm volatile("inb %1, %0" : "=a"(ret) : "d"(port));
	return ret;
}

void __print_port(Ui16 port, Ui8 data) {
	asm volatile("outb %0, %1" : "=a"(data) : "d"(port));
}

char __kernel_input() {
	char character = 0;
	while ((character = __read_port(KEYBOARD_PORT)) != 0) {
		if (character > 0)
			return character;
	}

	return character;
}

String __keyboard_input() {
	while (__kernel_input() != ' ') {
		commands[command_num][command_char_num] = __kernel_input();
		command_char_num++;

	} if (__kernel_input() == ' ') {
		command_char_num = 0;
		command_num++;

		return commands[command_num + 1];
	}
}
//ginger input

void __new_line() {
	if (next_line >= 55) {
		next_line = 0;
		clear_vga_buffer(&vga_buffer, __def_fore_color, __def_back_color);
	}

	vga_index = 80 * next_line;
	next_line++;
}

void __char_log(char character, Ui8 fore_color, Ui8 back_color) {
	vga_buffer[vga_index] = vga_entry(character, fore_color, back_color);
	vga_index++;
}

void __string_log(String str, Ui8 fore_color, Ui8 back_color) {
	Ui32 index = 0;

	while (str[index]) {
		__char_log(str[index], fore_color, back_color);
		index++;
	}
}

void __integer_log(int num, Ui8 fore_color, Ui8 back_color) {
	char str_num[digits(num) + 1];
	ItoA(num, str_num);
	__string_log(str_num, fore_color, back_color);
}

void gotoxy(Ui16 x, Ui16 y) {
	vga_index = 80 * y;
	vga_index += x;
}

void __clear(Ui8 fore_color, Ui8 back_color) {
	clear_vga_buffer(&vga_buffer, fore_color, back_color);
}
//ginger output

void sleep(Ui32 timer_count) {
	while (1) {
		asm volatile("nop");
		timer_count--;
		if (timer_count <= 0)
			break;
	}
}

#endif
//ginger I/O header