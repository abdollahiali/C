#include <stdio.h>

int main()
{
    enum {red, green, blue} color1;
    enum color_type {R, G, B};

    color1 = blue;
    enum color_type color2;
    color2 = R;

    switch (color1) {
    case red:
        printf("Color is red.\n");
        break;
    case green:
        printf("Color is green.\n");
        break;
    case blue:
        printf("Color is blue.\n");
        break;
    default:
        printf("Color is unknown.\n");
    }

    printf("The color1 number  is %d.\n\n", color1);
    
    switch (color2) {
    case red:
        printf("Color is red.\n");
        break;
    case green:
        printf("Color is green.\n");
        break;
    case blue:
        printf("Color is blue.\n");
        break;
    default:
        printf("Color is unknown.\n");
    }

    printf("The color2 number  is %d.\n", color2);

    return 0;
}