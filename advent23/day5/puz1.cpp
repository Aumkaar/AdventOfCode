// first attempt: using maps, failed on actual input because of the large numbers
// will try doing using search now

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

    vector<map<long long, long long>> m(7);
    
    for(int i = 0; i < 7; i++)
    {
        cout << "debug\n";
        for(int j = 0; j < 2; j++)
            file >> strInput;
        while(isdigit(strInput[0]))
        {
            long long destStart = stoll(strInput);
            file >> strInput;
            long long sourceStart = stoll(strInput);
            file >> strInput;
            long long length = stoll(strInput);

            cout << strInput;

            for(int j = 0; j < length; j++)
                m[i].insert(pair<long long, long long>(sourceStart + j, destStart + j));            
            file >> strInput;
            cout << "debug2\n";            
            if(i == 6)
                break;
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
            if(m[j].find(key) != m[j].end())
                key = m[j][key];
        }
        loc[i] = key;
    }

    cout << *min_element(loc.begin(), loc.end()) << endl;

    return 0;
}