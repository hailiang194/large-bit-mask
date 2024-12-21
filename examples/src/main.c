#include <stdio.h>
#include <stdlib.h>
#include "large_bit_mask.h"

int main(void)
{
    bitmask_t bitmask;
    size_t totalSize;

    totalSize = 0x00;
    bitmask = initBitMask(8, &totalSize);
    if(bitmask == NULL)
    {
        fprintf(stderr, "Failed to initialize bitmask\n");
        return -1;
    }

    if(setBit(bitmask, totalSize, 0x7, 0x1))
    {
        fprintf(stdout, "Set bit successfully!\n");
    }
    else
    {
        fprintf(stderr, "Failed to set bit\n");
    }

    fprintf(stdout, "Value of set bit is 0x%2x\n", getBit(bitmask, totalSize, 0x7));

    cleanBitMask(bitmask);
    bitmask = NULL;
    return 0;
}