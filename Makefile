output:
	@as --32 src/boot/boot.S -o bin/boot.o
	@gcc -m32 -c src/main.c -o bin/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	@ld -m elf_i386 -T src/linker.ld bin/kernel.o bin/boot.o -o bin/HdbOS.bin -nostdlib
	@grub-file --is-x86-multiboot bin/HdbOS.bin
	@mkdir -p bin/boot/grub
	@cp bin/HdbOS.bin bin/boot/HdbOS.bin
	@cp src/boot/grub.cfg bin/boot/grub/grub.cfg
	@rm bin/kernel.o
	@rm bin/boot.o
	@rm bin/HdbOS.bin

ISO:
	@grub-mkrescue -o bin/HdbOS.iso bin

assembly:
	@gcc -S src/main.c -o bin/HdbOS.S

bins:
	@as --32 src/boot/boot.S -o bin/boot.o
	@gcc -m32 -c src/main.c -o bin/HdbOS.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
	@ld -m elf_i386 -T src/linker.ld bin/kernel.o bin/boot.o -o bin/HdbOS.bin -nostdlib

run:
	@qemu-system-x86_64 -cdrom bin/HdbOS.bin