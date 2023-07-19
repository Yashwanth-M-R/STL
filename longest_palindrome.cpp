#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to check if a string is a palindrome
int isPalindrome(string str)
{
    int n = str.length();

    for (int i = 0; i < n / 2; i++)
    {
        if (str[i] != str[n - i - 1])
        {
            return 0;
        }
    }
    return 1;
}

// This Function iterates through all substrings to find the longest substring
string Longest_Palindrome(string input)
{
    string longest_palindrome;

    for (int i = 0; i < input.length(); i++)
    {
        for (int j = i + 1; j <= input.length(); j++)
        {
            string sub = input.substr(i, j - i);
            longest_palindrome = isPalindrome(sub) && sub.length() > longest_palindrome.length() ? sub : longest_palindrome;
        }
    }
    return longest_palindrome;
}

int main()
{
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    string longestPalindrome = Longest_Palindrome(input);
    if (longestPalindrome.length() > 1) // Condition to check the palindrome length, without this it will print single alphabets as output.
    {
        cout << longestPalindrome << endl;
    }
    else
    {
        cout << "There are no palindromes in this string";
    }

    return 0;
}
