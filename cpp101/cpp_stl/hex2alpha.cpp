#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

// string to hex
string alphaToHex(const string &input)
{
    stringstream ss;
    for (char ch : input)
    {
        ss << hex << setw(2) << setfill('0') << static_cast<int>(ch);
    }
    return ss.str();
}

// hex to alpha
string hexToAlpha(const string &hexInput)
{
    string result;
    for (size_t i = 0; i < hexInput.length(); i += 2)
    {
        // take two char at a time
        string hexByte = hexInput.substr(i, 2);

        // convert hex to char
        char ch = static_cast<char>(stoi(hexByte, nullptr, 16));
        result.push_back(ch);
    }
    return result;
}

int main()
{
    string input, hexInput;

    // Alphanumeric to Hexadecimal Conversion
    cout << "Enter an alphanumeric string: ";
    cin >> input;
    string hexResult = alphaToHex(input);
    cout << "Hexadecimal Representation: " << hexResult << endl;

    // Hexadecimal to Alphanumeric Conversion
    cout << "Enter a hexadecimal string: ";
    cin >> hexInput;
    // Ensure input is valid hexadecimal
    if (hexInput.length() % 2 != 0 || !all_of(hexInput.begin(), hexInput.end(), ::isxdigit))
    {
        cerr << "Invalid hexadecimal string!" << endl;
    }
    else
    {
        string alphanumericResult = hexToAlpha(hexInput);
        cout << "Alphanumeric Representation: " << alphanumericResult << endl;
    }

    return 0;
}