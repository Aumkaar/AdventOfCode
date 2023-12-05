// Bug creeped in because of a poor check for end of file
// Worked after correcting that check

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

    vector<long long> seeds(0);
    string strInput{};
    for(int i = 0; i < 2; i++)
        file >> strInput;
    do
    {
        seeds.push_back(stoll(strInput));
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

    vector<long long> loc(seeds.size());
    for(int i = 0; i < seeds.size(); i++)
    {
        long long key = seeds[i];
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
        loc[i] = key;
        // cout << "Location obtained: " << key << endl << endl;
    }

    cout << *min_element(loc.begin(), loc.end()) << endl;

    return 0;
}