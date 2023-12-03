#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>

using namespace std;

int main()
{
    int inSize = 140;
    vector<string> line(inSize);

    ifstream file("input.txt");
    if(!file)
    {
        cout << "Error opening file." << endl;
        return -1;
    }

    for(int i = 0; i < inSize; i++)
    {
        getline(file, line[i]);
    }

    file.close();

    int sum{};

    // for the top row

    for(int j = 0; j < line[0].length(); j++)
    {
        if(isdigit(line[0][j]))
        {
            // Checking the the number's length
            
            int init = j == 0 ? j : j-1;
            int fin{};
            
            while(isdigit(line[0][j]))
            {
                j++;
                if(j == line[0].length())
                    break;
            }
            fin = j == line[0].length() ? j-1 : j;

            // Obtaining the number

            int numStart = isdigit(line[0][init]) ? init : init+1;
            int numEnd = isdigit(line[0][fin]) ? fin : fin-1;   

            int num = stoi(line[0].substr(numStart, numEnd-numStart+1));     

            // Checking the symbols around it

            if(!(isdigit(line[0][init])) && line[0][init] != '.')
            {
                sum += num;
                continue;
            }

            if(!(isdigit(line[0][fin])) && line[0][fin] != '.')
            {
                sum += num;
                continue;
            }

            for(int k = init; k <= fin; k++)
            {
                if(!(isdigit(line[1][k])) && line[1][k] != '.')
                {
                    sum += num;
                    break;
                }
            }    
        }        
    }

    // for middle rows

    for(int i = 1; i < inSize - 1; i++)
    {
        for(int j = 0; j < line[i].length(); j++)
        {
            if(isdigit(line[i][j]))
            {
                // Checking the the number's length
            
                int init = j == 0 ? j : j-1;
                int fin{};                
                
                while(isdigit(line[i][j]))
                {
                    j++;
                    if(j == line[i].length())
                        break;
                }
                fin = j == line[i].length() ? j-1 : j;

                // Obtaining the number

                int numStart = isdigit(line[i][init]) ? init : init+1;
                int numEnd = isdigit(line[i][fin]) ? fin : fin-1;   

                int num = stoi(line[i].substr(numStart, numEnd-numStart+1));     

                // Checking the symbols around it

                if(!(isdigit(line[i][init])) && line[i][init] != '.')
                {
                    sum += num;
                    continue;
                }

                if(!(isdigit(line[i][fin])) && line[i][fin] != '.')
                {
                    sum += num;
                    continue;
                }

                int flag = 0;

                for(int k = init; k <= fin; k++)
                {
                    if(!(isdigit(line[i+1][k])) && line[i+1][k] != '.')
                    {
                        sum += num;
                        flag = 1;
                        break;
                    }
                }

                if(flag) continue;

                for(int k = init; k <= fin; k++)
                {
                    if(!(isdigit(line[i-1][k])) && line[i-1][k] != '.')
                    {
                        sum += num;
                        break;
                    }
                }
            }  
        }
    }

    // for the last row

    for(int j = 0; j < line[inSize-1].length(); j++)
    {
        if(isdigit(line[inSize-1][j]))
        {
            // Checking the the number's length
        
            int init = j == 0 ? j : j-1;
            int fin{};
            
            while(isdigit(line[inSize-1][j]))
            {
                j++;
                if(j == line[inSize-1].length())
                    break;
            }
            fin = j == line[inSize-1].length() ? j-1 : j;

            // Obtaining the number

            int numStart = isdigit(line[inSize-1][init]) ? init : init+1;
            int numEnd = isdigit(line[inSize-1][fin]) ? fin : fin-1;   

            int num = stoi(line[inSize-1].substr(numStart, numEnd-numStart+1));     

            // Checking the symbols around it

            if(!(isdigit(line[inSize-1][init])) && line[inSize-1][init] != '.')
            {
                sum += num;
                continue;
            }

            if(!(isdigit(line[inSize-1][fin])) && line[inSize-1][fin] != '.')
            {
                sum += num;
                continue;
            }

            for(int k = init; k <= fin; k++)
            {
                if(!(isdigit(line[inSize-2][k])) && line[inSize-2][k] != '.')
                {
                    sum += num;
                    break;
                }
            }
        }
    }

    cout << sum << endl;

    return 0;
}