#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream myFile("file1.txt");

    myFile << "Hello. This is my first file!";

    myFile.close();

    string myText;

    ifstream readFile("file1.txt");

    while (getline(readFile, myText))
    {
        cout << myText;
    }

    readFile.close();
}