# Questions

## What's `stdint.h`?

It's a header file included on C, it can increases the portability of the program, specially for embedded systems, giving us the ha-
bility of setting up fixed sizes for variables.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

That's used because some machines interprets a int as 16 bit, and others as 32 bit or another value, so stdint.h give us the possi-
bility of stablish a fixed size to a variable and with that we increase the safety and compatibility of our program.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

1, 4, 4, 2

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

The first two bytes are the file format identification, a program always read that 2 bytes in order to make sure that the file is
not damaged and that it's actually a BMP file (That 2 bytes generally must be the characters BM).

## What's the difference between `bfSize` and `biSize`?

bfSize represents the bitmap file size itself, on the other hand, biSize its just the size of the "BITMAPINFOHEADER", which is fixed
to be always 40 bytes.

## What does it mean if `biHeight` is negative?

If biHeight is negative, then the bitmap image will showed from top to bottom, starting from upper-left corner, so, if a file has
already a possitive value, and it becomes negative, the image should be showed upside down.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

It might return NULL if for example, the infile doesn't exist.

## Why is the third argument to `fread` always `1` in our code?

1 means the quantity of information that should be readed from the file (The whole infoheader and fileheader once in all cases).

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

3

## What does `fseek` do?

It jumps over different positions of a file, on the case of copy.c, if there's no padding then the fseek do nothing.

## What is `SEEK_CUR`?

It's a fseek parameter, it means 'current position of the file pointer', where the indicator will start.

## Whodunit?

It was professor Plum with the candlestick in the library
