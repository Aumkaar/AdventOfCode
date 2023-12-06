// solve quadratic equation, sorting out edge cases took time

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

    int numCases{4};
    string strInput{};
    vector<int> times(numCases);
    vector<int> records(numCases);
    
    for(int i = 0; i < 2; i++)
        file >> strInput;
    
    for(int i = 0; i < numCases; i++)
    {
        times[i] = stoi(strInput);
        file >> strInput;
    }

    file >> strInput;
    for(int i = 0; i < numCases; i++)
    {
        records[i] = stoi(strInput);
        file >> strInput;
    }

    vector<int> numWays(numCases);
    int prod{1};

    for(int i = 0; i < numCases; i++)
    {
        double preDet = times[i] * times[i] - 4 * records[i];
        if(preDet < 0)
        {
            numWays[i] = 0;
            prod = 0;
            break;
        }
        double det = sqrt(preDet);

        double intpart;
        int flag = 0;
        if(modf(times[i] + det, &intpart) == 0 && (times[i] + (int)det) % 2 == 0)
            flag = 1;
        
        // cout << "debug" << endl;

        int lowBound = max(0, (int)ceil(double(times[i] - det) / 2));
        int highBound = max(0, (int)floor(double(times[i] + det) / 2));
        if(highBound == 0)
        {
            prod = 0;
            break;
        }
        numWays[i] = highBound - lowBound + 1;

        if(flag == 1)
            numWays[i] -= 2;

        cout << numWays[i] << endl;
        prod *= numWays[i];
    }
    
    cout << prod << endl;

    return 0;
}