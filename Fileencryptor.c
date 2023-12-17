// file_encryptor.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_KEY_LENGTH 32

void encryptFile(const char *filename, const char *key) {
    // Implement file encryption logic using the provided key.
    // For simplicity, you can use a basic algorithm like XOR.
    // Remember to handle errors and edge cases.

    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file for encryption.\n");
        return;
    }

    // Open a new file for writing the encrypted content.
    char encryptedFilename[MAX_FILENAME_LENGTH + 10];  // +10 for appending "_encrypted"
    sprintf(encryptedFilename, "%s_encrypted", filename);

    FILE *encryptedFile = fopen(encryptedFilename, "wb");
    if (encryptedFile == NULL) {
        printf("Error creating encrypted file.\n");
        fclose(file);
        return;
    }

    int ch;
    size_t keyIndex = 0;

    // Iterate through the file character by character and encrypt.
    while ((ch = fgetc(file)) != EOF) {
        // XOR encryption for simplicity.
        // In a real-world scenario, consider stronger encryption algorithms.
        fputc(ch ^ key[keyIndex], encryptedFile);

        // Move to the next character in the key.
        keyIndex = (keyIndex + 1) % strlen(key);
    }

    fclose(file);
    fclose(encryptedFile);

    printf("File encrypted successfully. Encrypted file: %s\n", encryptedFilename);
}

void decryptFile(const char *filename, const char *key) {
    // Implement file decryption logic using the provided key.
    // For simplicity, use the same XOR logic as in encryption.
    // Handle errors and edge cases.

    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file for decryption.\n");
        return;
    }

    // Open a new file for writing the decrypted content.
    char decryptedFilename[MAX_FILENAME_LENGTH + 10];  // +10 for appending "_decrypted"
    sprintf(decryptedFilename, "%s_decrypted", filename);

    FILE *decryptedFile = fopen(decryptedFilename, "wb");
    if (decryptedFile == NULL) {
        printf("Error creating decrypted file.\n");
        fclose(file);
        return;
    }

    int ch;
    size_t keyIndex = 0;

    // Iterate through the file character by character and decrypt.
    while ((ch = fgetc(file)) != EOF) {
        // XOR decryption for simplicity.
        // In a real-world scenario, consider stronger encryption algorithms.
        fputc(ch ^ key[keyIndex], decryptedFile);

        // Move to the next character in the key.
        keyIndex = (keyIndex + 1) % strlen(key);
    }

    fclose(file);
    fclose(decryptedFile);

    printf("File decrypted successfully. Decrypted file: %s\n", decryptedFilename);
}

int main() {
    const char *filename = "example.txt";
    const char *key = "mysecretkey";

    encryptFile(filename, key);
    decryptFile(filename, key);

    return 0;
}

