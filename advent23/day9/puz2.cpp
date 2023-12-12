#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

long long firstNumAdd(vector<long long>& v)
{
    int flag = 0;
    for(int i = 0; i < v.size(); i++)
    {
        // cout  << v[i] << " " << endl;
        if(v[i] != 0)
        {
            flag = 1;
            // cout << "break\n";
            break;
        }
    }

    if(flag == 0)
        return 0;
    
    int n = v.size();
    vector<long long> v2(n-1);
    for(int i = 1; i < n; i++)
    {
        v2[i-1] = v[i] - v[i-1];
    }

    long long firstNum = firstNumAdd(v2);
    // cout << "n = " << n << " lastNum: ";
    // cout << lastNum << endl;
    return v[0] - firstNum;
}

int main()
{
    ifstream file("test.txt");
    if(!file)
    {
        // cout << "Error opening file." << endl;
        return -1;
    }

    string strInput{};

    int vecSize{21};
    int linNum{200};
    vector<vector<long long>> v(0);

    for(int i = 0; i < linNum; i++)
    {
        vector<long long> v2(0);
        for(int j = 0; j < vecSize; j++)
        {
            long long num{};
            file >> strInput;
            num = stoll(strInput);
            v2.push_back(num);
        }
        v.push_back(v2);
    }

    long long sum{};
    for(int i = 0; i < linNum; i++)
    {
        // for(int j = 0; j < vecSize; j++)
            // cout << v[i][j] << " ";
        // cout << endl;
        long long firstNum = firstNumAdd(v[i]);
        sum += firstNum;
        // cout << "Last num being added: " << lastNum << endl << endl;
    }

    cout << sum << endl;

    return 0;
}