#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream filestream("testout.txt");
    if (filestream.is_open())
    {
        filestream << "Welcome to CPP Tutorial!" << endl;
        filestream << "Author: Avijit Biswas";
        filestream.close();
    }
    else
        cout << "File opening is fail.";
    return 0;
}