/*
* This code is capable of runnig machine code as function
* usually used for wrapping shellcodes.
* Compile: gcc -m32 shellcode_wrapp.c -o shellcode
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/mman.h>

char payload[] = "\xeb\x0f\x6a\x04\x58\x6a\x01\x5b\x59\x6a\x0e\x5a\xcd\x80\x93\xcd"
                 "\x80\xe8\xec\xff\xff\xff\x48\x65\x6c\x6c\x6f\x2c\x20\x57\x6f\x72"
                 "\x6c\x64\x21\x0a";

int main() {    
    // Print the size of the shellcode.
    printf("Shellcode Size:  %d\n", sizeof(payload)-1);

    // Create a function pointer to the shellcode.
    void (*payload_point)() =  (void(*)())&payload;
    printf("Shellcode Address: 0x%08x\n", payload_point);

    // Calculate offset of the page.
    void *page_offset = (void *)((int)payload_point & ~(getpagesize()-1));
    printf("Shellcode page: 0x%08x\n", page_offset);

    // Use mprotect to mark that page of payload_point as RWX.
    mprotect(page_offset, getpagesize(), PROT_READ|PROT_WRITE|PROT_EXEC);
    payload_point();
    return 0;
}
