// easier than puz1

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
        std::cout << "Error opening file." << endl;
        return -1;
    }

    int numCases{4};
    string strInput{};
    string timeStr{}, recordStr{};
    
    for(int i = 0; i < 2; i++)
        file >> strInput;
    
    for(int i = 0; i < numCases; i++)
    {
        timeStr += strInput;
        file >> strInput;
    }

    file >> strInput;
    for(int i = 0; i < numCases; i++)
    {
        recordStr += strInput;
        file >> strInput;
    }

    long long timeVal = stoll(timeStr);
    long long recordVal = stoll(recordStr);
    
    long long numWays{};

    double preDet = timeVal * timeVal - 4 * recordVal;
    if(preDet < 0)
    {
        numWays = 0;
    }
    else
    {
        double det = sqrt(preDet);

        double intpart;
        int flag = 0;
        if(modf(timeVal + det, &intpart) == 0 && (timeVal + (long long)det) % 2 == 0)
            flag = 1;
        
        // cout << "debug" << endl;

        long lowBound = max(0ll, (long long)ceil(double(timeVal - det) / 2));
        long highBound = max(0ll, (long long)floor(double(timeVal + det) / 2));
        if(highBound == 0)
        {
            numWays = 0;
        }
        else
        {
            numWays = highBound - lowBound + 1;

            if(flag == 1)
                numWays -= 2;
        }
    }

    std::cout << numWays << endl;

    return 0;
}