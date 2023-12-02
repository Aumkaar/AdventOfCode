#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>

using namespace std;

int main()
{
    vector<string> line(1000);

    ifstream file("puz.txt");
    if(!file)
    {
        cout << "Error opening file." << endl;
        return -1;
    }

    for(int i = 0; i < 1000; i++)
    {
        getline(file, line[i]);
    }

    file.close();

    map<string, int> m;
    m["zero"] = 0;
    m["one"] = 1;
    m["two"] = 2;
    m["three"] = 3;
    m["four"] = 4;
    m["five"] = 5;
    m["six"] = 6;
    m["seven"] = 7;
    m["eight"] = 8;
    m["nine"] = 9;

    int first{}, last {}, sum{}, flag{};

    for(int i = 0; i < 1000; i++)
    {
        flag = 0;

        int firstIndex{INT_MAX}, lastIndex{INT_MIN};

        // record the first and last index of each numeral word in the line
        for(auto it = m.begin(); it!=m.end(); it++)
        {
            int firstChhotu = line[i].find(it->first);
            int lastChhotu = line[i].rfind(it->first);

            if(firstChhotu != string::npos && firstChhotu < firstIndex)
            {
                firstIndex = firstChhotu;
                first = it->second;
            }
            if(lastChhotu != string::npos && lastChhotu > lastIndex)
            {
                lastIndex = lastChhotu;
                last = it->second;
            }
        }

        for(int j = 0; j < line[i].length(); j++)
        {
            if(line[i][j] >= 48 && line[i][j] <= 57)
            {
                if(flag == 0)
                {
                    if(j < firstIndex)
                    {
                        firstIndex = j;
                        first = line[i][j] - 48;
                    }
                    flag++;
                }
                if(j > lastIndex)
                {
                    lastIndex = j;
                    last = line[i][j] - 48;
                    
                }
            }
        }
        sum += 10*first + last;
        cout << sum << endl;
    }

    cout << sum << endl;
    return 0;
}