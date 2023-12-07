// easy straightforward

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

int handType(string hand)
{
    map<char, int> m;

    for(auto ch : hand)
    {
        m[ch]++;
    }

    int numKeys = m.size();

    if (numKeys == 5)
        return 1;
    else if (numKeys == 4)
        return 2;
    else if (numKeys == 3)
    {
        for(auto it = m.begin(); it != m.end(); it++)
        {
            if(it->second == 3)
                return 4;
        }
        return 3;
    }
    else if (numKeys == 2)
    {
        for(auto it = m.begin(); it != m.end(); it++)
        {
            if(it->second == 4)
                return 6;
        }
        return 5;
    }
    else
        return 7;
    
    return -1;
}

int tieBreak(string hand)
{
    map<char, int> m;

    for(int i = 0; i < 9; i++)
    {
        m[static_cast<char>(50+i)] = i;
    }
    m['T'] = 8; m['J'] = 9; m['Q'] = 10; m['K'] = 11; m['A'] = 12;

    int val = 0;
    
    for(auto ch : hand)
    {
        val = val*13 + m[ch];
    }

    return val;
}

int main()
{
    ifstream file("input2.txt");
    if(!file)
    {
        cout << "Error opening file." << endl;
        return -1;
    }

    int setSize{19};
    string strInput{};

    vector<vector<int>> data(0);
    int id = 0;
    map<int, string> m;
    
    file >> strInput;
    do
    {
        m[id] = strInput;
        
        vector<int> dataChhotu(0);
        dataChhotu.push_back(handType(strInput));
        dataChhotu.push_back(tieBreak(strInput));
        dataChhotu.push_back(id++);

        file >> strInput;
        int bid = stoi(strInput);
        dataChhotu.push_back(bid);

        data.push_back(dataChhotu);

        file >> strInput;
    } while (!file.eof());   
    
    sort(data.begin(), data.end());

    int sum{};

    for(int i = 0; i < data.size(); i++)
    {
        sum += (i+1) * data[i][3];
    }

    cout << sum << endl;

    return 0;
}