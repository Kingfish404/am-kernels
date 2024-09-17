#include <stdint.h>
#include <stdio.h>
#include "trap.h"

extern char _heap_start;

const int lenght = 0xff;

int data[0x10] = {'X'};
int data_zero[0x100];

int main()
{
    char c = data[0];
    data[10] = 'X';
    data_zero[10] = 'S';
    volatile uint8_t *mem = (uint8_t *)&_heap_start;
    for (int i = 0; i < lenght; i++)
    {
        uint8_t volatile u8 = ((uint8_t)(mem + i)) & 0xff;
        mem[i] = u8;
        check(mem[i] == u8);
    }
    for (int i = 0; i < (lenght / 2); i++)
    {
        uint16_t volatile u16 = (uint16_t)(mem + i) & 0xffff;
        ((uint16_t *)(mem))[i] = u16;
        check(((uint16_t *)(mem))[i] == u16);
    }
    for (int i = 0; i < (lenght / 4); i++)
    {
        uint32_t volatile u32 = (uint32_t)(mem + i) & 0xffffffff;
        ((uint32_t *)(mem))[i] = u32;
        check(((uint32_t *)(mem))[i] == u32);
    }
    for (int i = 0; i < (lenght / 8); i++)
    {
        uint64_t volatile u64 = (uint64_t)(mem + i) & 0xffffffffffffffff;
        ((uint64_t *)(mem))[i] = u64;
        check(((uint64_t *)(mem))[i] == u64);
    }
    for (int i = 0; i < lenght; i++)
    {
        uint8_t volatile u8 = ((uint8_t)(mem + i)) & 0xff;
        mem[i] = u8;
        check(mem[i] == u8);

        uint16_t volatile u16 = (uint16_t)(mem + i) & 0xffff;
        ((uint16_t *)(mem))[i] = u16;
        check(((uint16_t *)(mem))[i] == u16);

        uint32_t volatile u32 = (uint32_t)(mem + i) & 0xffffffff;
        ((uint32_t *)(mem))[i] = u32;
        check(((uint32_t *)(mem))[i] == u32);

        uint64_t volatile u64 = (uint64_t)(mem + i) & 0xffffffffffffffff;
        ((uint64_t *)(mem))[i] = u64;
        check(((uint64_t *)(mem))[i] == u64);
    }

    for (int i = 0; i < lenght; i++)
    {
        uint8_t volatile u8 = ((uint8_t)(mem + i)) & 0xff;
        mem[i] = u8;
    }
    for (int i = 0; i < lenght; i++)
    {
        uint8_t volatile u8 = ((uint8_t)(mem + i)) & 0xff;
        check(mem[i] == u8);
    }
    for (int i = 0; i < (lenght / 2); i++)
    {
        uint16_t volatile u16 = (uint16_t)(mem + i) & 0xffff;
        ((uint16_t *)(mem))[i] = u16;
    }
    for (int i = 0; i < (lenght / 2); i++)
    {
        uint16_t volatile u16 = (uint16_t)(mem + i) & 0xffff;
        check(((uint16_t *)(mem))[i] == u16);
    }
    for (int i = 0; i < (lenght / 4); i++)
    {
        uint32_t volatile u32 = (uint32_t)(mem + i) & 0xffffffff;
        ((uint32_t *)(mem))[i] = u32;
    }
    for (int i = 0; i < (lenght / 4); i++)
    {
        uint32_t volatile u32 = (uint32_t)(mem + i) & 0xffffffff;
        check(((uint32_t *)(mem))[i] == u32);
    }
    for (int i = 0; i < (lenght / 8); i++)
    {
        uint64_t volatile u64 = (uint64_t)(mem + i) & 0xffffffffffffffff;
        ((uint64_t *)(mem))[i] = u64;
    }
    for (int i = 0; i < (lenght / 8); i++)
    {
        uint64_t volatile u64 = (uint64_t)(mem + i) & 0xffffffffffffffff;
        check(((uint64_t *)(mem))[i] == u64);
    }
    for (int i = (lenght / 8) - 1; i >= 0; i--)
    {
        uint64_t volatile u64 = (uint64_t)(mem + i) & 0xffffffffffffffff;
        ((uint64_t *)(mem))[i] = u64;
    }
    for (int i = (lenght / 8) - 1; i >= 0; i--)
    {
        uint64_t volatile u64 = (uint64_t)(mem + i) & 0xffffffffffffffff;
        check(((uint64_t *)(mem))[i] == u64);
    }
    return 0;
}
