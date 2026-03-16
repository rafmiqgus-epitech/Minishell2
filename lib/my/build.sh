#!/usr/bin/env sh
##
## EPITECH PROJECT, 2025
##
## File description:
## build.sh
##

OBJ_DIR=obj
CFLAGS='-I../../include -I.'

rm -rf "$OBJ_DIR"
mkdir -p "$OBJ_DIR"

for src in *.c my_printf/my_printf.c my_printf/parsers/*.c my_printf/length/*.c my_printf/specifiers/*.c my_printf/precision/*.c; do
    [ -f "$src" ] || continue
    obj="$OBJ_DIR/${src%.c}.o"
    mkdir -p "$(dirname "$obj")"
    clang $CFLAGS -c "$src" -o "$obj"
done

ar rc libmy.a $(find "$OBJ_DIR" -type f -name '*.o')
rm -f ./*.o
