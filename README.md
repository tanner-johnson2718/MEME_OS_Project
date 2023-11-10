# MEME Project

The meme project is a set of repositories to capture my progress and projects in a self study of Embedded and Systems programming topics. This repo will act as indexer into the MEME repos that actually hold the content.

| Project | Description | Status |
| --- | --- | --- |
| [MEME OS 1](https://github.com/tanner-johnson2718/MEME_OS) | First Stab at buildroot .A collection of scripts and example that build a linux kernel using Build Root targeting Qemu. Attached debugger to linux kernel. | Done :heavy_check_mark: |
| [MEME OS 2](https://github.com/tanner-johnson2718/MEME_OS_2) | A bare bones, from scratch OS running on x86 Qemu. Purpose is to explore creating bare metal drivers and OS code, and to explore the hardware architecture of x86. | Not done, needs to wrapped up with what it has |
| [MEME OS 3](https://github.com/tanner-johnson2718/MEME_OS_3) | A report style project that covers linking, compilation, processes, some system call information, ELF format, etc.| Done :heavy_check_mark: |
| [Crypto](https://github.com/tanner-johnson2718/Crypto) | Repo for exploring cryptography | Very starting point, needs some love |
| [Layer 1 and 2 Ethernet Lab](https://github.com/tanner-johnson2718/MEME_ETH_LAB) | - | - |

# Up Next

* Other Embedded Topics
    * device trees
    * Linux start up
    * boot loaders
    * linux building
    * scheduler
    * dma
    * Whats all this shit running on my linux sys
    
* Targeting Real Hardware
    * BBB
    * Rpi
    * Arduino
    * ESP 32
    * etc

# Index and Key Deliverables

## MEME OS

* [Buildroot Doc and some Systems Textbooks](https://github.com/tanner-johnson2718/MEME_OS/tree/master/docs)
* [Buildroot Example kmod](https://github.com/tanner-johnson2718/MEME_OS/tree/master/kernel-modules/hellomod), [Buildroot Example Userspace App](https://github.com/tanner-johnson2718/MEME_OS/tree/master/user-apps/hello), [Buildroot Helper Scripts](https://github.com/tanner-johnson2718/MEME_OS/tree/master/scripts).
* [Some initial doc on buildroot](https://github.com/tanner-johnson2718/MEME_OS/tree/master#buildroot-and-linux-menuconfig)

## MEME OS 2

TODO

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