#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "dlinar.h"

char* itoa(int val, int base){

	static char buf[32] = {0};

	int i = 30;

	for(; val && i ; --i, val /= base)

		buf[i] = "0123456789abcdef"[val % base];

	return &buf[i+1];

}

int main(int argc, char *argv[])
{int b, a = 0x0801;
b=0x0001;
char s[100] = "AA";
//char str[5] = "";
strcat(s, itoa(0xffff,16));
//strcat(s, str);
//strcat(&s, &str);
printf("%s\n", s);//strcat(s,str));
	return 0;
}
