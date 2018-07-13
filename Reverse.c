// C Programming
//
//
//  Reverses character string s (Pointer and Non-Pointer Versions)
//  Exercise_1-19
//
//  Created by Louie Shi on 7/10/18.
//  Copyright © 2018 Louie Shi. All rights reserved.
//

#include <stdio.h>

#define MAXLINE 1000

int mgetline(char s[], int lim);
void pointerReverse(char s[]);
void nonPointerReverse(char s[]);

// mgetline: read a line into s, return length
// getline code from the c textbook

int mgetline(char s[], int lim)
{
    int c, i;
    
    for(i=0; i < lim - 1 && (c = getchar())!=EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }
    
    if(c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    
    return i;
}

void pointerReverse(char s[])
{
    char* ptr1 = &s[0];
    char* ptr2 = &s[strlen(s) - 1];
    char temp;
    
    while(ptr1 < ptr2)
    {
        temp = *ptr1;
        *ptr1 = *ptr2;
        *ptr2 = temp;
        
        ptr1++;
        ptr2--;
    }
}

void nonPointerReverse(char s[])
{
    int i, j;
    char temp = ' ';
    int length = strlen(s);
    
    
    for(i = 0, j = (strlen(s) - 1); i < j; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

int main(int argc, const char * argv[])
{
    char line[MAXLINE];
    char line2[MAXLINE];
    
    int lineSize = mgetline(line, MAXLINE);
    int lineSize2 = mgetline(line2, MAXLINE);
    
    // Removes the extra \n in the input
    line[lineSize - 1] = '\0';
    line2[lineSize2 - 1] = '\0';
    
    pointerReverse(line);
    printf("Pointer Reverse:%s\n", line);
    
    nonPointerReverse(line2);
    printf("non-Pointer Reverse:%s\n", line2);
    
    return 0;
}
