# HdbOS
HdbOS is a totally open source lightweight operative system, that only requires a few KB of memory and disk space. We want to say that HdbOS hasn't got any stable version, so please try it in QEMU, VirtualBox, VMware or any other virtualization system.

### Getting HdbOS
If you want to build HdbOS, you'll need an UNIX like OS (or an UNIX environment) and GNU/Make, GCC, QEMU and GNU/Binutils as software. First, clone this repository:
```bash
git clone https://github.com/HdbSoft/HdbOS.git
cd HdbOS
```

And then make the ISO image:
```bash
make && make ISO
```

### Dependencies
HdbOS requires a few libraries and dependencies, luckily these are already integrated into the source code of the operating system. Here is a list with all of them:
- [ginger](https://github.com/HdbSoft/ginger): The operating system kernel.
- [HdbUI](https://github.com/HdbSoft/HdbUI): The library that handles user interfaces.

### Contributing
If you want to contribute, you just need to fork this repository (you can do it by clicking in the fork button on the top of the page), then make your changes there (commits and other stuff) and finally send a pull request. You can also contribute by sending us your issues.

### [License](LICENSE.md)
HdbOS is licensed under the Mozilla Public License, you can see the hole license by clicking on this paragraph's title.

I hope you liked HdbOS, so please give it a ⭐, we will enjoy it.
