#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    string filename;
    cout << "Enter file name: ";
    cin >> filename;

    ofstream file;
    file.open(filename, ios::app);
    if (file.is_open())
    {
        string line;
        cout << "Enter text (type 'exit' to finish):\n";

        while (getline(cin, line))
        {
            if (line == "exit")
            {
                break;
            }
            file << line << endl;
        }

        file.close();
        cout << "Text saved to file." << endl;
    }
    else
    {
        cout << "Error: could not open file." << endl;
    }

    return 0;
}