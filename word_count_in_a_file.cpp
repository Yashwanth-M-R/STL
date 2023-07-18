#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <cctype> //This header file contains the method tolower

using namespace std;

int main()
{
    // checking if the file exists, can change file along with path incase it needs to be used for an other file
    ifstream file("some_file.txt");
    if (!file.is_open())
    {
        cout << "Can't Open File" << endl;
    }

    // using map to store word and it's occurace like key value pair
    map<string, int> occurrence;

    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string word;
        while (ss >> word)
        {
            // removing unwanted characters

            // Convert the word to lowercase, to avoid treating "THIS" and "this" as differnt words
            for (char &c : word)
            {
                c = tolower(c);
            }
            ++occurrence[word]; // incrementing the word counter
        }
    }

    file.close();

    // display function
    cout << "Word Counts:" << endl;
    for (auto &i : occurrence)
    {
        cout << i.first << " -> " << i.second << endl;
    }

    return 0;
}
