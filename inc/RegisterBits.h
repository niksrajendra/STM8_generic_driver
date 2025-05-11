#ifndef REGISTER_BITS_H
#define REGISTER_BITS_H
#include <stdint.h>

//#pragma pack(1)
typedef struct
{
    uint8_t         HSEEN:      1u;
    const uint8_t   HSERDY:     1u;
    const uint8_t   RESERVED:   6u;
}_CLK_ECKRbits;

//#pragma pack(0)

#define CLK_ECKRbits    (*(volatile _CLK_ECKRbits *)0x50C1);

//union
//{
//    CLK_ECKR        (*(volatile uint8_t *)0x50C1);
//    CLK_ECKRbits   (*(volatile _CLK_ECKRbits *)0x50C1);
//};

#endif // REGISTER_BITS_H
