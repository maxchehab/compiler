#!/bin/bash
nasm -f elf64 -o output.o output.nasm && ld -o output output.o && ./output
