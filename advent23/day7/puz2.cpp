// dumb bug wasted 30 mins

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

    int numKeys{};
    int flag{};
    if(m.find('J') == m.end())
    {
        numKeys = m.size();
    }
    else
    {
        numKeys = m.size() - 1;
        flag = 1;
    }

    if(flag)
    {
        if (numKeys == 0 || numKeys == 1)
            return 7;
        else if (numKeys == 2)
        {
            if(m['J'] == 3 || m['J'] == 2)
                return 6;
            else
            {
                for(auto it = m.begin(); it != m.end(); it++)
                {
                    if(it->second == 3)
                        return 6;
                }
                return 5;
            }
        }
        else if (numKeys == 3)
        {
            return 4;
        }
        else
            return 2;    
    }
    else
    {
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
    }
    
    cout << "RROR!\n";
    return -1;
}

int tieBreak(string hand)
{
    map<char, int> m;

    for(int i = 0; i < 9; i++)
    {
        m[static_cast<char>(50+i)] = i + 1;
    }
    m['T'] = 9; m['J'] = 0; m['Q'] = 10; m['K'] = 11; m['A'] = 12;

    int val = 0;
    
    for(auto ch : hand)
    {
        val = val*13 + m[ch];
    }

    return val;
}

int main()
{
    ifstream file("input.txt");
    if(!file)
    {
        cout << "Error opening file." << endl;
        return -1;
    }

    int setSize{1000};
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

    long long sum{};

    for(int i = 0; i < data.size(); i++)
    {
        // cout << m[data[i][2]] << " " << data[i][0] << " " << data[i][1] << " " << data[i][3] << endl;
        sum += (i+1) * (long long)data[i][3];
    }

    cout << sum << endl;

    return 0;
}