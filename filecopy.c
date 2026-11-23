#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp1, *fp2;
    int ch;
    char source[50], dest[50];

    printf("Enter source file name: ");
    scanf("%s", source);
    printf("Enter destination file name: ");
    scanf("%s", dest);

    fp1 = fopen(source, "r");
    if (fp1 == NULL)
    {
        printf("Cannot open source file\n");
        exit(1);
    }

    fp2 = fopen(dest, "w");
    if (fp2 == NULL)
    {
        printf("Cannot open destination file\n");
        fclose(fp1);
        exit(1);
    }

    while ((ch = fgetc(fp1)) != EOF)
    {
        fputc(ch, fp2);
    }

    printf("File copied successfully.\n");

    fclose(fp1);
    fclose(fp2);

    return 0;
}
