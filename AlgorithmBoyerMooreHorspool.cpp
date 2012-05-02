#include "StdAfx.h"
#include "limits.h"
#include "AlgorithmBoyerMooreHorspool.h"

AlgorithmBoyerMooreHorspool::AlgorithmBoyerMooreHorspool(void)
{
}


AlgorithmBoyerMooreHorspool::~AlgorithmBoyerMooreHorspool(void)
{
}


int AlgorithmBoyerMooreHorspool::search(SuperString *haystack, SuperString *needle){
	char *needleString = needle->getString();
	char *haystackString = haystack->getString();
	int haystackLength = haystack->getLength();
	int needleLength = needle->getLength();

	if(haystack == NULL || needle == NULL 
		|| needleLength > haystackLength
		|| needleLength < minMatchLength)
			return -1;

    /*if(needle->getLength() == 1) {
        //normal algo?
    }*/
 
    int pos = 0;
    int *bad_char_skip = new int[UCHAR_MAX + 1];
 
    /* ---- Preprocess ---- */
    /* Initialize the table to default value */
    /* When a character is encountered that does not occur
     * in the needle, we can safely skip ahead for the whole
     * length of the needle.
     */
    for (pos = 0; pos <= UCHAR_MAX; pos++)
        bad_char_skip[pos] = needleLength;
 
    /* C arrays have the first byte at [0], therefore:
     * [nlen - 1] is the last byte of the array. */
    int lastPos = needleLength - 1;
 
    /* Then populate it with the analysis of the needle */
    for (pos = 0; pos < lastPos; pos++)
        bad_char_skip[needleString[pos]] = lastPos - pos;
 
    /* ---- Do the matching ---- */
 
    /* Search the haystack, while the needle can still be within it. */
    while (haystackLength >= needleLength)
    {
        /* scan from the end of the needle */
        for (pos = lastPos; haystackString[pos] == needleString[pos]; pos--)
            if (pos == 0) /* If the first byte matches, we've found it. */
                return haystackLength;
 
        /* otherwise, we need to skip some bytes and start again.
           Note that here we are getting the skip value based on the last byte
           of needle, no matter where we didn't match. So if needle is: "abcd"
           then we are skipping based on 'd' and that value will be 4, and
           for "abcdd" we again skip on 'd' but the value will be only 1.
           The alternative of pretending that the mismatched character was
           the last character is slower in the normal case (Eg. finding
           "abcd" in "...azcd..." gives 4 by using 'd' but only
           4-2==2 using 'z'. */
        haystackLength -= bad_char_skip[haystackString[lastPos]];
        haystackString += bad_char_skip[haystackString[lastPos]];
    }
 
    return NULL;
}

OccurrenceList* AlgorithmBoyerMooreHorspool::searchAll(SuperString *haystack, SuperString *needle){
	return NULL;
}