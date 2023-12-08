// was not in the mood to solve today
// solved both of them in the same file by mistake
// aaaaaaaa

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

    string strInput{};

    file >> strInput;
    string direction = strInput;
    int directionSize = direction.length();
    cout << direction << endl;

    map<string, vector<string>> m;
    vector<string> curr(0);
    vector<string> end(0);
    file >> strInput;
    do
    {
        string key = strInput;
        if(key[2] == 'A')
            curr.push_back(key);
        if(key[2] == 'Z')
            end.push_back(key);
        
        file >> strInput;
        file >> strInput;
        vector<string> v;
        v.push_back(strInput.substr(1, 3));
        file >> strInput;
        v.push_back(strInput.substr(0, 3));
        file >> strInput;

        m[key] = v;
        // cout << key << " " << m[key][0] << " " << m[key][1] << endl;
    } while (!file.eof());

    for(int i = 0; i < curr.size(); i++)
    {
        cout << curr[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < end.size(); i++)
    {
        cout << end[i] << " ";
    }
    cout << endl;
    
    vector<int> count(curr.size(), 0);

    for(int i = 0; i < curr.size(); i++)
    {
        while(1)
        {            
            if(direction[count[i] % directionSize] == 'L')
                curr[i] = m[curr[i]][0];
            else
                curr[i] = m[curr[i]][1];

            count[i]++;

            if(curr[i][2] == 'Z')
            {
                cout << count[i] << " " << curr[i] << " ";
                break;
            }
        }
    }
    cout << endl;

    // calculate lcm online

    return 0;
}