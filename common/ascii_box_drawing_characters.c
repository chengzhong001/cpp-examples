/*
Print boxed characters of string in the terminal
this is just an excersize in C manipulation
of the few remaining box drawing single line ASCII
characters available in Unix like OS.

Edited using Code Blocks IDE Kubuntu 12.04
and compiled ucing GCC
*/

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>  // for future trials with wide chars
#include <locale.h> // to set Unicode locale
#include <string.h>

#define RB "\e(0\x6a\e(B" // 188 Right Bottom corner
#define RT "\e(0\x6b\e(B" // 187 Right Top corner
#define LT "\e(0\x6c\e(B" // 201 Left Top cornet
#define LB "\e(0\x6d\e(B" // 200 Left Bottom corner
#define MC "\e(0\x6e\e(B" // 206 Midle Cross
#define HL "\e(0\x71\e(B" // 205 Horizontal Line
#define LC "\e(0\x74\e(B" // 204 Left Cross
#define RC "\e(0\x75\e(B" // 185 Right Cross
#define BC "\e(0\x76\e(B" // 202 Bottom Cross
#define TC "\e(0\x77\e(B" // 203 Top Cross
#define VL "\e(0\x78\e(B" // 186 Vertical Line
#define SP " "            // space string

#define TRUE 1
#define FALSE 0

// Move the whole box to the right 'RIGHT' number of spaces
#define RIGHT 8

// IF DBL_BOX TRUE draw a second box around
#define DBL_BOX TRUE

/*

*/
// print number of box chars - two string variables
//  if different able to print mixed box chars
//  eg. first right cross, horizontal, right cross ect
//  'i' times.
void box_print(char *def_str1, char *def_str2, int i);

void print_nl(int i); // print 'i' number of newlines

// print string cgars within box characters
void box_letters(char *letters);

int top_out_line(int bars); // if DBL_BOX true draw top outline
int top_line(int bars);     // draw top line of a box
int mid_line(int bars);     // draw middle line ob a box
int bot_line(int bars);     // draw bottol line of a box
int bot_out_line(int bars); // if DBL_BOX true draw second bottom line

int main(int n_args, char *args[])
{
    // setlocale(LC_ALL, "pl_PL.utf8"); //local na utf8-Polish type

    int ltrs;
    char *str1, *str2, *str3, *str4, *str5, *str6;

    // Sample strings for boxed printing
    str1 = "abggdfrtfdxzX\0";
    str2 = "BAGIHMTKBDXDe\0";
    str3 = "^%#*%^$)v^>jy\0";
    str4 = ",./';|@8&5~12\0";
    str5 = "+=+()8(7>>54B\0";
    str6 = "hfH*Ongf^^r_-\0";

    print_nl(3); // print 3 newlines

    top_line(strlen(str1)); // print top line of str1 length

    box_letters(str1); // print boxed letters

    mid_line(strlen(str1)); // print middle box line

    box_letters(str2);

    mid_line(strlen(str2));

    box_letters(str3);

    mid_line(strlen(str3));

    box_letters(str4);

    mid_line(strlen(str6));

    box_letters(str5);

    mid_line(strlen(str5));

    box_letters(str6);

    bot_line(strlen(str4)); // print the bottom line of the box

    print_nl(5);

    exit(0);
}
// ===============================================
void box_print(char *gr1, char *gr2, int repeat)
{
   
    if (repeat > 1)
    {
        for (int i = 1; i < repeat; i++)
        {
            printf("%s", gr1);
            printf("%s", gr2);
        }
    }
    printf("%s", gr1);
    return;
}
//==================
void print_nl(count)
{
    int i;
    if (count > 1)
    {
        for (i = 0; i < count; i++)
            printf("\n");
    }
    else
        printf("\n");
    return;
}
//=============================
void box_letters(char *letters)
{
    int i = 0;
    int j = 0;
    print_nl(1);
    if (RIGHT)
    {
        if (DBL_BOX)
        {
            for (j = 1; j < RIGHT; j++)
                putchar(' ');
            box_print(VL, VL, 1);
        }
        else
        {
            for (j = 0; j < RIGHT; j++)
                putchar(' ');
        }
    }
    box_print(VL, VL, 1);
    while (letters[i])
    {
        printf("%c", letters[i++]);
        box_print(VL, VL, 1);
    }
    if (DBL_BOX)
        box_print(VL, VL, 1);
    print_nl(1);
}
//================
int top_line(bars)
{
    int i;
    if (DBL_BOX)
    {
        top_out_line(bars + 1);
        print_nl(1);
    }
    if (RIGHT)
    {
        if (DBL_BOX)
        {
            for (i = 1; i < RIGHT; i++)
                putchar(' ');
            box_print(VL, VL, 1);
        }
        else
        {
            for (i = 0; i < RIGHT; i++)
                putchar(' ');
        }
    }
    box_print(LT, LT, 1);
    box_print(HL, TC, bars);
    box_print(RT, RT, 1);
    if (DBL_BOX)
        box_print(VL, VL, 1);
    return (0);
}
//=================
int bot_line(bars)
{
    int i;
    if (RIGHT)
    {
        if (DBL_BOX)
        {
            for (i = 1; i < RIGHT; i++)
                putchar(' ');
            box_print(VL, VL, 1);
        }
        else
        {
            for (i = 0; i < RIGHT; i++)
                putchar(' ');
        }
    }
    box_print(LB, LB, 1);
    box_print(HL, BC, bars);
    box_print(RB, RB, 1);
    if (DBL_BOX)
    {
        box_print(VL, VL, 1);
        print_nl(1);
        bot_out_line(bars + 1);
    }
    return (0);
}
//================
int mid_line(bars)
{
    int i;
    if (RIGHT)
    {
        if (DBL_BOX)
        {
            for (i = 1; i < RIGHT; i++)
                putchar(' ');
            box_print(VL, VL, 1);
        }
        else
        {
            for (i = 0; i < RIGHT; i++)
                putchar(' ');
        }
    }
    box_print(LC, LC, 1);
    box_print(HL, MC, bars);
    box_print(RC, RC, 1);
    if (DBL_BOX)
        box_print(VL, VL, 1);
    return (0);
}
//====================
int top_out_line(bars)
{
    int i;
    if (RIGHT)
    {
        for (i = 0; i < RIGHT - 1; i++)
            putchar(' ');
    }
    box_print(LT, LT, 1);
    box_print(HL, HL, bars);
    box_print(RT, RT, 1);
    return (0);
}
//====================
int bot_out_line(bars)
{
    int i;
    if (RIGHT)
    {
        for (i = 0; i < RIGHT - 1; i++)
            putchar(' ');
    }
    box_print(LB, LB, 1);
    box_print(HL, HL, bars);
    box_print(RB, RB, 1);
    return (0);
}