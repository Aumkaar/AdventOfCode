// combine the first and last numeral in a line and sum up all such numbers in the file

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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

    int first{}, last{}, sum{}, flag{};    

    for(int i = 0; i < 1000; i++)
    {
        flag = 0;
        for(int j = 0; j < line[i].length(); j++)
        {
            if(line[i][j] >= 48 && line[i][j] <= 57)
            {
                if(flag == 0)
                {
                    first = last = line[i][j] - 48;
                    flag++;
                }
                else
                {
                    last = line[i][j] - 48;
                }
            }
        }
        sum += 10*first + last;
    }

    cout << sum << endl;    
    return 0;
}