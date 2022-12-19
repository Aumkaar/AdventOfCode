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
    vector<string> lines(2);

    ll count = 0;

    while(getline(file, line))
    {
        count++;
        sort(line.begin(), line.end());
        unique(line.begin(), line.end());

        if(count % 3)
        {
            lines[count % 3 - 1] = line;
        }
        else
        {
            for(char ch : line)
            {
                if(lines[0].find(ch) != string::npos && lines[1].find(ch) != string::npos)
                {
                    if(ch >= 'a' && ch <= 'z')
                        sumPriority += ch - 'a' + 1;
                    else if(ch >= 'A' && ch <= 'Z')
                        sumPriority += ch - 'A' + 27;
                    break;
                }
            }
        }  

        
    }

    cout << sumPriority << endl;

    return 0;
}