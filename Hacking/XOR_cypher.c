// An algorithm created to encrypt and decrypt files with XOR logic.
// Usage method: 
// a.out <key> <file to encrypt/decrypt> <file to write>
// Mo not use this encryption in real life, it is easily broken.
#include <stdio.h>

// Main function
// The function will receive the arguments.
// passed on the command line.
int main(int args, char *argv[]) {
  // Declaring two file pointers.
  FILE *arq1, *arq2;
  // Declaring the key.
  char *chave;
  // Integer to index the key.
  int c;

  // Store the key, the first atgument given on command line.
  chave = argv[1];
  // Check that the key is not null.
  if (*chave != '\0') {
    // Open the file in read binary mode.
    arq1 = fopen(argv[2], "rb");
    // Check if the file is not null.
    if (arq1 != NULL) {
      // Open the second file in write binary mode.
      arq2 = fopen(argv[3],"wb");
      // Check if the file can be handed.
      // Check if there is no permission conflict.
      if (arq2 != NULL) {
        // Get the characters until finish the file.
        while ((c = getc(arq1)) != EOF) {
          // Reference the key pointer used in the first argument.
          if (!*chave) chave = argv[1];
          // Use the XOR operation on the characters.
          c ^= *(chave++);
          // Includes the characters in the encrypted file.
          putc(c, arq2);
        }
        // Close the encrypted file.
        fclose(arq2);
      }
      // Close the encrypting file.
      fclose(arq1);
    }
  }
  // return true.
  return 1;
}