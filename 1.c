#include <stdio.h>
#include <ctype.h>
int main() 
{
    int shift, i, mode;
    char message[100];
    char ch;
    printf("Enter the string: ");
    scanf("%s", message);
    printf("Enter the shift (1-25): ");
    scanf("%d", &shift);
    if (shift < 1 || shift > 25) 
	{
        printf("Invalid shift value! Please enter a value between 1 and 25.\n");
        return 1;
    }
    printf("Enter mode (1 for Encryption, 2 for Decryption): ");
    scanf("%d", &mode);
    if (mode != 1 && mode != 2) 
	{
        printf("Invalid mode! Please enter 1 for Encryption or 2 for Decryption.\n");
        return 1;
    }
    if (mode == 2) 
	{
        shift = -shift;
    }
    for (i = 0; message[i] != '\0'; i++) 
	{
        ch = message[i];
        if (isalpha(ch)) 
		{
            if (isupper(ch)) 
			{
                ch = 'A' + (ch - 'A' + shift + 26) % 26;
            } else {
                ch = 'a' + (ch - 'a' + shift + 26) % 26;
            }
        }
        message[i] = ch;
    }
    if (mode == 1) {
        printf("Encrypted Caesar Cipher: %s\n", message);
    } else {
        printf("Decrypted Caesar Cipher: %s\n", message);
    }
    return 0;
}
