# MEME Project

The meme project is a set of repositories to capture my progress and projects in a self study of Embedded and Systems programming topics. This repo will act as indexer into the MEME repos that actually hold the content.

| Project | Description | Status |
| --- | --- | --- |
| [MEME OS 1](https://github.com/tanner-johnson2718/MEME_OS) | First Stab at buildroot .A collection of scripts and example that build a linux kernel using Build Root targeting Qemu. Attached debugger to linux kernel. | Done :heavy_check_mark: |
| [MEME OS 2](https://github.com/tanner-johnson2718/MEME_OS_2) | A bare bones, from scratch OS running on x86 Qemu. Purpose is to explore creating bare metal drivers and OS code, and to explore the hardware architecture of x86. | Not done, needs to wrapped up with what it has |
| [MEME OS 3](https://github.com/tanner-johnson2718/MEME_OS_3) | A report style project that covers linking, compilation, processes, some system call information, ELF format, etc.| Done :heavy_check_mark: |
| [Crypto](https://github.com/tanner-johnson2718/Crypto) | Repo for exploring cryptography. Followed a set of challanges and used as guide for study. | Not really done but is wrapped up with what it has :heavy_check_mark: |
| [Layer 1 and 2 Ethernet Lab](https://github.com/tanner-johnson2718/MEME_ETH_LAB) | Ethernet lab style project using an RPI 4. Focus on code, scripts and other "hands on" style deliverables. | Done but should come back and finish what is annoatated in the next section  |
| [PI 4 JTAG Debugger](https://github.com/tanner-johnson2718/PI_JTAG_DBGR) | Run open OCD and use the rpi 4 as a JTAG debugger and programmer | In progress | 

# Up Next

* Wrapping Up Already Started
    * wrap up meme 2, boot process and irq focus 
    * MEME ETH
        * Track a packet
        * ARP

* Planned Labs
    * TCP/IP Lab
    * Virt mem lab
        * how a program is laid out in memory (including kernel stack, etc)
    * File
    * 802.11 wifi
    * Buildroot v3
    * Scheduler Lab

* Other Embedded Topics
    * device trees
    * Linux start up
        * Go line by line on boot and figure out what it all means
    * boot loaders
        * Specifically look at the PI or ESP32 boot loader
        * PI sd card layout
        * cmdlint.txt, config.txt, etc
    * dma
    * Whats all this shit running on my linux sys
    * pci and usb
    * container of
    * offset of
    * udev
    * namespace
    * signals
    * linker script
    * User accounts and perms

# Index and Key Deliverables

## MEME OS

* [Buildroot Doc and some Systems Textbooks](https://github.com/tanner-johnson2718/MEME_OS/tree/master/docs)
* [Buildroot Example kmod](https://github.com/tanner-johnson2718/MEME_OS/tree/master/kernel-modules/hellomod), [Buildroot Example Userspace App](https://github.com/tanner-johnson2718/MEME_OS/tree/master/user-apps/hello), [Buildroot Helper Scripts](https://github.com/tanner-johnson2718/MEME_OS/tree/master/scripts).
* [Some initial doc on buildroot](https://github.com/tanner-johnson2718/MEME_OS/tree/master#buildroot-and-linux-menuconfig)

## MEME OS 2

* [8250 serial driver](https://github.com/tanner-johnson2718/MEME_OS_2/blob/master/kernel/serial.c)
* [GDT Memory Segmentation](https://github.com/tanner-johnson2718/MEME_OS_2/blob/master/kernel/gdt.c)
* [PIC 8259 IRQ Driver](https://github.com/tanner-johnson2718/MEME_OS_2/blob/master/kernel/irq.c)
* [PS2 Key Board Driver](https://github.com/tanner-johnson2718/MEME_OS_2/blob/master/kernel/ps2.c)
* [VGA Textmode Driver](https://github.com/tanner-johnson2718/MEME_OS_2/blob/master/kernel/vga.c)
* [8254 PIT Driver](https://github.com/tanner-johnson2718/MEME_OS_2/blob/master/kernel/timer.c)

## MEME OS 3

* [GDB Cheat Sheet](https://github.com/tanner-johnson2718/MEME_OS_3/tree/main/Appendix/GDB#my-gdb-cheat-sheet)
* [Official ProcFS Doc](https://docs.kernel.org/filesystems/proc.html)
* [Dynamic Linking](https://github.com/tanner-johnson2718/MEME_OS_3/tree/main/Dynamic_Linking)
    * [syscall instruction and calling conventions](https://github.com/tanner-johnson2718/MEME_OS_3/tree/main/Dynamic_Linking#exercise-make-your-own-print-shared-library)
    * [Creating a Dynamic Library (.so)](https://github.com/tanner-johnson2718/MEME_OS_3/tree/main/Dynamic_Linking#exercise-make-your-own-print-shared-library)
    * [Making Program w/o the C-stdlib](https://github.com/tanner-johnson2718/MEME_OS_3/tree/main/Dynamic_Linking#exercise-make-your-own-print-shared-library)
    * [PLT and GOT](https://github.com/tanner-johnson2718/MEME_OS_3/tree/main/Dynamic_Linking#got-and-plt)
    * [Lazy Binding](https://github.com/tanner-johnson2718/MEME_OS_3/tree/main/Dynamic_Linking#lazy-binding)
    * [VA to PA code](https://github.com/tanner-johnson2718/MEME_OS_3/tree/main/Dynamic_Linking#physical-addresses-and-multiple-users)
    * `sudo awk '$NF!~/\.so/{next} {$0=$NF} !a[$0]++' /proc/*/maps` to dump all system dynamic libraries.
* [ELF File Standard](https://github.com/tanner-johnson2718/MEME_OS_3/tree/main/Hello_World#overview0)
* [Static Linking](https://github.com/tanner-johnson2718/MEME_OS_3/tree/main/Linking)
    * [Compiler Symbols](https://github.com/tanner-johnson2718/MEME_OS_3/tree/main/Linking#globals-locals-externs-functions-and-their-symbols)
    * [Relocation and PIC](https://github.com/tanner-johnson2718/MEME_OS_3/tree/main/Linking#relocation)
    * [440 byte hello world](https://github.com/tanner-johnson2718/MEME_OS_3/tree/main/Linking#exercise-create-a-minimal-hello-world)
* [Dynamic Loader (ld)](https://github.com/tanner-johnson2718/MEME_OS_3/tree/main/Loading)
    * [Process Image and How cmd line args and env args are passed](https://github.com/tanner-johnson2718/MEME_OS_3/tree/main/Loading#command-line-args-and-environment-variables)
    * [LibC Program call graph](https://github.com/tanner-johnson2718/MEME_OS_3/tree/main/Loading#libc-and-dynamic-linker-invocation)
* [Attempt at making my own LibC](https://github.com/tanner-johnson2718/MEME_OS_3/tree/main/MEME_Lib)
* [First Stab at diging into processes](https://github.com/tanner-johnson2718/MEME_OS_3/tree/main/Processes)
    * [Process State Machine](https://github.com/tanner-johnson2718/MEME_OS_3/tree/main/Processes#process-creation-manipulation-and-execution)
    * [Group and Thread IDs](https://github.com/tanner-johnson2718/MEME_OS_3/tree/main/Processes#ids)
    * [Clone](https://github.com/tanner-johnson2718/MEME_OS_3/tree/main/Processes#ids)
    * [rusage](https://github.com/tanner-johnson2718/MEME_OS_3/tree/main/Processes#runtime-stats)
    * [task struct](https://github.com/tanner-johnson2718/MEME_OS_3/tree/main/Processes#linux-proc--task-structure)
* [SysCall Doc](https://github.com/tanner-johnson2718/MEME_OS_3/blob/main/System_Calls/README.md#exercise-make-your-own-syscall)

## MEME Crypto

* [Art of Computer Programming and Crypto Books](https://github.com/tanner-johnson2718/Crypto)
* [AES](https://github.com/tanner-johnson2718/Crypto/tree/master/AES)
    * [AES Spec](https://github.com/tanner-johnson2718/Crypto/blob/master/AES/AES_FIPS197.pdf)
    * [AES Implementation](https://github.com/tanner-johnson2718/Crypto/blob/master/AES/aes.py)
    * [AES EBC Hack](https://github.com/tanner-johnson2718/Crypto/blob/master/AES/aes_ebc_break.py)
    * [AES CBC Hack](https://github.com/tanner-johnson2718/Crypto/blob/master/AES/cbc_bit_flip.py)
* [Number Theory](https://github.com/tanner-johnson2718/Crypto/tree/master/number_theory)
    * [Eucledian Algorithm](https://github.com/tanner-johnson2718/Crypto/blob/master/number_theory/Euclidean_Algo.pdf)
    * [Galois Fields](https://github.com/tanner-johnson2718/Crypto/blob/master/number_theory/galois.pdf)
* [Psedo RNG](https://github.com/tanner-johnson2718/Crypto/tree/master/prng)
* [XOR Cipher](https://github.com/tanner-johnson2718/Crypto/tree/master/xor_cipher)

## MEME ETH Lab

* [Raw Sockets](https://github.com/tanner-johnson2718/MEME_ETH_LAB/tree/master/external_packages/ethraw)
* [RPI Buildroot System](https://github.com/tanner-johnson2718/MEME_ETH_LAB/tree/master/P2.2).
    * [Scripts Associated with RPI buildroot system](https://github.com/tanner-johnson2718/MEME_ETH_LAB/tree/master/P2.2)
* [Using Sysfs to find Network HW info](https://github.com/tanner-johnson2718/MEME_ETH_LAB/tree/master/P2.1#using-sysfs-to-play-with-rpi-eth-devices)
    * [Sysfs Appendix](https://github.com/tanner-johnson2718/MEME_ETH_LAB/tree/master/P2.1#sysfs-appendix)
* [Hacking a PHY driver](https://github.com/tanner-johnson2718/MEME_ETH_LAB/blob/master/P2.2/README.md#hacking-the-bcm54213pe-driver)
    * [Raw Socket ETH Code](https://github.com/tanner-johnson2718/MEME_ETH_LAB/tree/master/extern_packages/ethraw)
    * [MDIO Bus and phytool](https://github.com/tanner-johnson2718/MEME_ETH_LAB/blob/master/P2.2/README.md#mdio-bus-hacking)
    * [kdb](https://github.com/tanner-johnson2718/MEME_ETH_LAB/blob/master/P2.2/README.md#setting-up-the-debug-environment)
    * [flickering the Eth port LEDs](https://github.com/tanner-johnson2718/MEME_ETH_LAB/blob/master/P2.2/README.md#messing-with-the-leds)
    * [kdb debug extentions](https://github.com/tanner-johnson2718/MEME_ETH_LAB/tree/master/extern_packages/kdbhelper)
* [Hacking a MAC Driver](https://github.com/tanner-johnson2718/MEME_ETH_LAB/tree/master/P2.3)
    * [pycparser scripts](https://github.com/tanner-johnson2718/MEME_ETH_LAB/tree/master/scripts/cpygdb)
        * This really didnt go anywhere but its a good starting point for any future C parsing projects
    * [KDMX and A Really Good Single COM Port debug system](https://github.com/tanner-johnson2718/MEME_ETH_LAB/blob/master/P2.3/gdb_revisited.md)
    * [GDB Cheat Sheet v2](https://github.com/tanner-johnson2718/MEME_ETH_LAB/blob/master/P2.3/gdb_revisited.md#gdb-cheat-sheet-20)
    * [Changing a MAC addr and Promiscious mode on a NIC](https://github.com/tanner-johnson2718/MEME_ETH_LAB/blob/master/P2.3/init_notes.md)
    * [VA to PA Sysfs based Kernel Module](https://github.com/tanner-johnson2718/MEME_ETH_LAB/tree/master/extern_packages/v2p)

## RPI 4 JTAG Debugger

* [Init Set up and getting a JTAG open on a ESP 32 using the Raspberry PI](https://github.com/tanner-johnson2718/PI_JTAG_DBGR/blob/master/Init_PI_JTAG_Test.md)
    * [PI JTAG Set up](https://github.com/tanner-johnson2718/PI_JTAG_DBGR/blob/master/Init_PI_JTAG_Test.md#init-pi-os-set-up)
    * [ESP 32 Hello World and Build Env Set up](https://github.com/tanner-johnson2718/PI_JTAG_DBGR/blob/master/Init_PI_JTAG_Test.md#esp-32-set-up)
    * [OpenOCD Cheat Sheet](https://github.com/tanner-johnson2718/PI_JTAG_DBGR/blob/master/Init_PI_JTAG_Test.md#openocd-and-remote-debugging)
* [Targeting an RPI4 via JTAG](https://github.com/tanner-johnson2718/PI_JTAG_DBGR/blob/master/RPI4_JTAG_Target.md)