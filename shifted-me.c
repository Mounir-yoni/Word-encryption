#include <stdio.h>
#include <string.h>
void shift_the_text(char text[], int number_shift);
void unshift_the_text(char text[], int number_shift);

int main()
{
    char text[100];
    int shift_number, state;

    printf("enter the text\n");
    gets(text);

    printf("enter the number of shift\n");
    scanf("%i", &shift_number);

    printf("chose:\n1. shift\n2. unshift \n");
    scanf("%d", &state);

    if (state == 1)
    {
        shift_the_text(text, shift_number);
        printf("النص المشفر: %s\n", text);
    }
    else if (state == 2)
    {
        unshift_the_text(text, shift_number);
        printf("النص المفكوك: %s\n", text);
    }
    else
    {
        printf("اختيار غير صالح.\n");
    }
}

void shift_the_text(char text[], int number_shift)
{

    for (int index = 0; text[index] != '\0'; index++)
    {
        char ch = text[index];

        if (ch >= 'a' && ch <= 'z')
        {
            ch = (ch - 'a' + number_shift) % 26 + 'a';
        }

        if (ch >= 'A' && ch <= 'Z')
        {
            ch = (ch - 'A' + number_shift) % 26 + 'A';
        }
        text[index] = ch;
    }
}

void unshift_the_text(char text[], int number_shift)
{
    shift_the_text(text, 26 - number_shift);
}