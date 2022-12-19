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

    ll sumPriority{};
    
    std::ifstream file("puz1.txt");

    std::string line;
    while(getline(file, line))
    {
        int n = line.length();
        string r1 = line.substr(0, n/2);
        string r2 = line.substr(n/2, n/2);

        sort(r1.begin(), r1.end());
        sort(r2.begin(), r2.end());

        unique(r1.begin(), r1.end());
        unique(r2.begin(), r2.end());

        for(char ch : r1)
        {
            if(r2.find(ch) != string::npos)
            {
                if(ch >= 'a' && ch <= 'z')
                    sumPriority += ch - 'a' + 1;
                else if(ch >= 'A' && ch <= 'Z')
                    sumPriority += ch - 'A' + 27;
                break;
            }
        }
    }

    cout << sumPriority << endl;

    return 0;
}