#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "Hello";

    // Concat
    // char s1[100] = "Hello ";
    // strcat(s1, "World!");
    // puts(s1);
    // char s2[100] = "World!";
    // strcat(s1, s2);
    // puts(s1);

    // finding a character in string
    char word[100] = "This is my Code";
    char *pointer;
    pointer = strchr(word, 'h');
    cout << substr(pointer, 1);
    return 0;
}