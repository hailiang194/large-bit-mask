#include "large_bit_mask.h"
#include <string.h>

size_t getCapacitySize(size_t allocateBits)
{
    return (allocateBits >> 3) + ((allocateBits & 0x7) ? 1 : 0);
}

bitmask_t initBitMask(size_t allocatedBits, size_t* totalSize)
{
    *totalSize = getCapacitySize(allocatedBits);
    bitmask_t mask = (bitmask_t)malloc((*totalSize) * sizeof(bitmask_t));
    if(mask == NULL)
    {
        *totalSize = 0x0;
        return NULL;
    }
    memset(mask, 0x0, (*totalSize) * sizeof(bitmask_t));
    return mask;
}

void cleanBitMask(bitmask_t bitmask)
{
    if(bitmask != NULL)
    {
        free(bitmask);
    }
}

int setBit(bitmask_t bitmask, size_t capacityBytes, size_t position, bit_t value)
{
   if(position >= capacityBytes * 8)
    {
        return 0;
    }

    //Invalid value
    if(value > 1)
    {
        return 0;
    }   

    *(bitmask + (position >> 3)) |= (value << (position & 0x7));
    return 1;
}

bit_t getBit(bitmask_t bitmask, size_t capacityBytes, size_t position)
{
    if(position >= (capacityBytes << 3))
        return (bit_t)0xff;

    return *(bitmask + (position >> 3)) & (1 << (position & 0x7));
}