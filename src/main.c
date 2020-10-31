#include "kernel/kernel.h"
#include "graphics/hdbui.h"

void __kernel_init() {
	puts("GINGER KERNEL READY!!");
	sleep(2000);
	puts("HDBUI LIBRARY READY!!");
	sleep(2000);
	clear;

	puts("Hello, World!");
}