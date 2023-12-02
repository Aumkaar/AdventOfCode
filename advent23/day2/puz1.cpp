// String manipulation

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main()
{
    vector<string> line(100);

    ifstream file("input.txt");
    if(!file)
    {
        cout << "Error opening file." << endl;
        return -1;
    }

    for(int i = 0; i < 100; i++)
    {
        getline(file, line[i]);
    }

    file.close();

    vector<int> cap{12, 13, 14};    // number of r, g, b cubes
    int sum{};

    for(int i = 0; i < 100; i++)
    {
        // convert id substring into integer
        int indLen = line[i].find(":") - 4;
        int ind = stoi(line[i].substr(5, indLen));

        int flag{}; // flag to check if any max value of colour exceeds the actual number of cubes
        int maxRed{}, maxGreen{}, maxBlue{};

        // loop though all the occurrences of "red"
        int pos = line[i].find("red");
        while(pos != string::npos)
        {
            // convert the associated numeral into integer
            int numLen = (pos-2) - line[i].rfind(" ", pos-2);
            int num = stoi(line[i].substr(pos-1-numLen, numLen));

            maxRed = max(maxRed, num);
            if(maxRed > cap[0])
            {
                flag = 1;
                break;
            }

            pos = line[i].find("red", pos+1);
        }

        // repeat the above process for "green" and "blue"
        pos = line[i].find("green");
        while(pos != string::npos)
        {
            int numLen = (pos-2) - line[i].rfind(" ", pos-2);
            int num = stoi(line[i].substr(pos-1-numLen, numLen));

            maxGreen = max(maxGreen, num);
            if(maxGreen > cap[1])
            {
                flag = 1;
                break;
            }

            pos = line[i].find("green", pos+1);
        }

        pos = line[i].find("blue");
        while(pos != string::npos)
        {
            int numLen = (pos-2) - line[i].rfind(" ", pos-2);
            int num = stoi(line[i].substr(pos-1-numLen, numLen));

            maxBlue = max(maxBlue, num);
            if(maxBlue > cap[2])
            {
                flag = 1;
                break;
            }

            pos = line[i].find("blue", pos+1);
        }

        if(flag)
        {
            continue;
        }

        sum += ind;
    }

    cout << sum << endl;

    return 0;
}