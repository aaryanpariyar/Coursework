#include<stdio.h>
#include<string.h>
#include<ctype.h>
char convertlow(char txt);
void encrypt(char input[50],char base, int key,char output[50]);
void main()
{
    char input[50], output[50], dec[50];
    char base;
    int key;
    a:
    printf("Do you want to Encrypt or Decrypt?");
    scanf("%s",dec);
    b:
    printf("Enter the key (1-25): ");
    scanf("%d",&key);
    if(key<1 || key>25)
    {
        goto b;
    }
    for(int i = 0; i < strlen(dec); i++)
    {
        if(dec[i]>='A' && dec[i]<='Z')
            dec[i] = convertlow(dec[i]);
    }

    if(strcmp(dec,"encrypt")==0)
    {
        char encrypt[50];
        printf("Enter a message for encrypting: ");
        getchar();
        fgets(input,sizeeof(input),stdin);
        for(int i = 0; i < strlen(input); i++)
        {
            if(isalpha(input[i]))
            {
                if(input [i]>='a' && input[i]<='z')
                    base = 'a';
                else if (input [i]>='A' && input[i]<='Z')
                    base ='A';
                encrypt[i] = (input[i] -base + key) % 26 +base;
            }
            else
            encrypt[i] = input[i];
        }
    }
    else if(strcmp(dec,"decrypt")==0)
    {
        printf("Enter the message for decrypting: ");
        getchar();
        fgets(input,sizeof(input),stdin);
        for(int i = 0; i < strlen(input); i++)
        {
            if(isalpha(input[i]))
            {
                if(input [i]>='a' && input[i]<='z')
                    base = 'a';
                else if (input [i]>='A' && input[i]<='Z')
                    base ='A';
                output[i] = (input[i] -base - key + 26) % 26 +base;
            }
            else
                output[i] = input[i];
        }
        printf("The decrypted text will be ");
        for(int i = 0; i < strlen(input); i++)
        {
            printf("%c",output[i]);
        }
    }
    else
    {
        printf("It is an invalid input.\n");
        goto a;
    }
    printf("The encrypted text will be ");
        for(int i = 0; i < strlen(input); i++)
        {
            printf("%c",output[i]);
        }
}
char convertlow(char txt)
{
    return txt + ('a' - 'A');
}
