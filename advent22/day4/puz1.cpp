#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define vll vector<long long>
#define vi vector<int>
#define PB push_back
#define MOD 1000000007
using ll = long long;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll countPairs{};
    
    std::ifstream file("puz1.txt");
    std::string line;

    while(getline(file, line))
    {
        string start1 = line.substr(0, line.find('-'));
        line = line.substr(line.find('-') + 1, line.length()-line.find('-')-1);
        string end1 = line.substr(0, line.find(','));
        line = line.substr(line.find(',') + 1, line.length()-line.find(',')-1);
        string start2 = line.substr(0, line.find('-'));
        line = line.substr(line.find('-') + 1, line.length()-line.find('-')-1);
        string end2 = line;

        ll s1 = stoi(start1);
        ll e1 = stoi(end1);
        ll s2 = stoi(start2);
        ll e2 = stoi(end2);

        if(s1 <= s2 && e1 >= e2)
            countPairs++;
        else if(s1 >= s2 && e1 <= e2)
            countPairs++;
    }

    cout << countPairs << endl;

    return 0;
}