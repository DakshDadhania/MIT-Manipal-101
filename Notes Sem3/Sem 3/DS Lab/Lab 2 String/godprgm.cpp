#include <iostream>
#include "stdio.h"
using namespace std;
int strlenn(char str[])
{
    int Count = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        // if (str[i] == ' ')
        //     continue;

        // else
        Count++;
    }
    return Count;
}
void strconcat(char s1[], char s2[])
{
    int j = strlenn(s1) + 2;
    s1[j - 1] = ' ';
    for (int i = 0; s2[i] != '\0'; i++)
    {
        s1[j++] = s2[i];
    }
    s1[j++] = '\0';
}

int strcomp(char s1[], char s2[])
{
    int i = 0;
    if (strlenn(s1) - strlenn(s2) != 0)
    {
        cout << "Different Lengths" << endl;
    }
    while (s1[i] != '\0' || s2[i] != '\0')
    {
        if (s1[i] - s2[i] != 0)
        {
            return s1[i] - s2[i];
        }
        i++;
    }
    return 0;
}
void insert_substring(char s1[], char s2[], int pos)
{
    // char temp[100];
    // int n = strlenn(s1), m = strlenn(s2);
    // for (int i = pos; i < n; i++) {
    //     temp[i - pos] = s1[i];
    // }
    // for (int i = 0; s2[i] != '\0'; i++) {
    //     s1[pos + i] = s2[i];
    // }
    // int j = 0;
    // for (int i = pos + m; i < m + n; i++) {
    //     s1[i] = temp[j];
    //     j++;
    // }
    // s1[m + n] = '\0';
    char s3[100];
    int l1 = strlenn(s1);

    int l2 = strlenn(s2);

    int j = 0, j2 = 0;
    for (int i = 0; i < pos; i++)
    {
        s3[i] = s1[j2++];
    }
    for (int i = pos; i < pos + l2; i++)
    {
        s3[i] = s2[j++];
    }
    s3[pos + l2] = ' ';
    for (int i = pos + l2 + 1; i <= l1 + l2 + 2; i++)
    {
        s3[i] = s1[j2++];
    }
    s3[l1 + l2 + 3] = '\0';

    for (int i = 0; s3[i] != 0; i++)
    {
        s1[i] = s3[i];
    }
}
void delete_substring(char s1[], int start, int end)
{
    char temp[100];
    int n = strlenn(s1);
    int new_length = n - (end - start);
    int i = 0;
    while (s1[end + i] != '\0')
    {
        s1[start + i] = s1[end + i];
        i++;
    }
    s1[new_length] = '\0';
}
int main()
{
    int ans;
    cout << "What would u like to perform from below functions \n";
    cout << "1.length of the string \n";
    cout << "2.string concatenation \n";
    cout << "3.string comparison \n";
    cout << "4.to insert a sub string  \n";
    cout << "5.to delete a substring  \n";
    cin >> ans;
    if (ans == 1)
    {
        char str[100];
        cout << "Enter a string: \n";
        fflush(stdin);
        gets(str);
        fflush(stdin);
        cout << "You entered: " << str << "\n";
        cout << "Length of string : \n " << strlenn(str);
    }
    else if (ans == 2)
    {

        char s1[100], s2[100], s3[100];
        int n;
        cout << "Enter substring 1  ";
        fflush(stdin);
        gets(s1);
        fflush(stdin);
        cout << "Enter substring 2  ";
        gets(s2);

        strconcat(s1, s2);
        puts(s1);
    }
    else if (ans == 3)
    {
        char s1[100], s2[100], s3[100];
        int n;
        cout << "Enter substring 1  ";
        fflush(stdin);
        gets(s1);

        fflush(stdin);
        cout << "Enter substring 2  ";
        gets(s2);
        strcomp(s1, s2) ? cout << "no" : cout << "yes";
    }
    else if (ans == 4)
    {
        char s1[100], s2[100], s3[100];
        int n;
        cout << "Enter substring 1  ";
        fflush(stdin);
        gets(s1);
        fflush(stdin);
        cout << "Enter the string to be inserted" << endl;
        gets(s2);
        cout << "Enter position" << endl;
        int pos;
        cin >> pos;
        cout << "After Insertion" << endl;
        insert_substring(s1, s2, pos);
        cout << s1 << endl;
    }
    else if (ans == 5)
    {
        int start, end;
        char s1[100], s2[100], s3[100];
        int n;
        cout << "Enter substring 1  ";
        fflush(stdin);
        gets(s1);
        fflush(stdin);
        cout << "Enter the starting and the ending positions of the substring to be deleted" << endl;
        cin >> start >> end;
        delete_substring(s1, start, end);
        cout << "After Deletion : ";
        cout << s1 << endl;
    }
    return 0;
}
