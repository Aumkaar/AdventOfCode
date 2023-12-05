// Shameless brute force lmao, took 2-3 min to run.

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int main()
{
    ifstream file("input.txt");
    if(!file)
    {
        cout << "Error opening file." << endl;
        return -1;
    }

    vector<vector<long long>> seedsRange(0);
    string strInput{};
    for(int i = 0; i < 2; i++)
        file >> strInput;
    do
    {
        long long seedStart = stoll(strInput);
        file >> strInput;
        long long length = stoll(strInput);
        seedsRange.push_back({seedStart, length});
        file >> strInput;
    } while (isdigit(strInput[0]));         // now at seed-to-soil

    // a 3D vector, each plane stores 2D vector of each mapping
    vector<vector<vector<long long>>> table(7, vector<vector<long long>>(0));
    
    for(int i = 0; i < 7; i++)
    {
        // cout << "debug\n";
        for(int j = 0; j < 2; j++)
            file >> strInput;
        while(isdigit(strInput[0]))
        {
            long long destStart = stoll(strInput);
            file >> strInput;
            long long sourceStart = stoll(strInput);
            file >> strInput;
            long long length = stoll(strInput);
            long long sourceEnd = sourceStart + length - 1;

            table[i].push_back({destStart, sourceStart, sourceEnd});
                        
            file >> strInput;

            if(file.eof())
                break;
            // cout << "debug2\n";            
        }
    }

    file.close();

    // cout << "has exited the input loop \n";

    long long minLoc{LLONG_MAX};
    for(int i = 0; i < seedsRange.size(); i++)
    {
        for(long long p = seedsRange[i][0]; p < seedsRange[i][0] + seedsRange[i][1]; p++)
        {
            long long key = p;
            for(int j = 0; j < 7; j++)
            {
                // cout << "At table plane " << j << ": " << key << endl;   
                for(int k = 0; k < table[j].size(); k++)
                {
                    if(key >= table[j][k][1] && key <= table[j][k][2])
                    {
                        key = table[j][k][0] + (key - table[j][k][1]);
                        break;
                    }
                }
            }
            minLoc = min(minLoc, key);
        }
        // cout << "Location obtained: " << key << endl << endl;
    }

    cout << minLoc << endl;

    return 0;
}