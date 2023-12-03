// just embarrassed by this attempt

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
    int lineLen = line[0].length();

    // for the four corners

    // top left
    if(!isdigit(line[0][0]) && line[0][0] != '.')
    {
        vector<int> flag(3);

        flag[0] = isdigit(line[0][1]);
        flag[1] = isdigit(line[1][0]);
        flag[2] = isdigit(line[1][1]);
        
        if(flag[0] && (flag[1] || flag[2]))
        {
            // obtain the numbers

            // number on right
            int numStart{}, numEnd{};
            int num1{};

            numStart = 1;
            numEnd = line[0].find('.', numStart);
            num1 = stoi(line[0].substr(numStart, numEnd-numStart));

            // number below
            int num2{};

            if(flag[1])
                numStart = 0;
            else    
                numStart = 1;
            
            numEnd = line[1].find('.', numStart);
            num2 = stoi(line[1].substr(numStart, numEnd-numStart));

            sum += num1*num2;
        }
    }

    // top right
    if(!isdigit(line[0][lineLen-1]) && line[0][lineLen-1] != '.')
    {
        vector<int> flag(3);

        flag[0] = isdigit(line[0][lineLen-2]);
        flag[1] = isdigit(line[1][lineLen-1]);
        flag[2] = isdigit(line[1][lineLen-2]);
        
        if(flag[0] && (flag[1] || flag[2]))
        {
            // obtain the numbers

            // number on left
            int numStart{}, numEnd{};
            int num1{};

            numEnd = lineLen-2;
            numStart = line[0].rfind('.', numEnd);
            num1 = stoi(line[0].substr(numStart+1, numEnd-numStart));

            // number below
            int num2{};

            if(flag[1])
                numEnd = lineLen-1;
            else    
                numEnd = lineLen-2;
            
            numStart = line[1].rfind('.', numEnd);
            num2 = stoi(line[1].substr(numStart+1, numEnd-numStart));

            sum += num1*num2;
        }
    }

    // bottom left
    if(!isdigit(line[inSize-1][0]) && line[inSize-1][0] != '.')
    {
        vector<int> flag(3);

        flag[0] = isdigit(line[inSize-1][1]);
        flag[1] = isdigit(line[inSize-2][0]);
        flag[2] = isdigit(line[inSize-2][1]);
        
        if(flag[0] && (flag[1] || flag[2]))
        {
            // obtain the numbers

            // number on right
            int numStart{}, numEnd{};
            int num1{};

            numStart = 1;
            numEnd = line[inSize-1].find('.', numStart);
            num1 = stoi(line[inSize-1].substr(numStart, numEnd-numStart));

            // number above
            int num2{};

            if(flag[1])
                numStart = 0;
            else    
                numStart = 1;
            
            numEnd = line[inSize-2].find('.', numStart);
            num2 = stoi(line[inSize-2].substr(numStart, numEnd-numStart));

            sum += num1*num2;
        }
    }

    // bottom right
    if(!isdigit(line[inSize-1][lineLen-1]) && line[inSize-1][lineLen-1] != '.')
    {
        vector<int> flag(3);

        flag[0] = isdigit(line[inSize-1][lineLen-2]);
        flag[1] = isdigit(line[inSize-2][lineLen-1]);
        flag[2] = isdigit(line[inSize-2][lineLen-2]);
        
        if(flag[0] && (flag[1] || flag[2]))
        {
            // obtain the numbers

            // number on left
            int numStart{}, numEnd{};
            int num1{};

            numEnd = lineLen-2;
            numStart = line[inSize-1].rfind('.', numEnd);
            num1 = stoi(line[inSize-1].substr(numStart+1, numEnd-numStart));

            // number above
            int num2{};

            if(flag[1])
                numEnd = lineLen-1;
            else    
                numEnd = lineLen-2;
            
            numStart = line[inSize-2].rfind('.', numEnd);
            num2 = stoi(line[inSize-2].substr(numStart+1, numEnd-numStart));

            sum += num1*num2;
        }
    }

    // for the four edges, exluding the corners

    // for the top edge
    for(int j = 1; j < lineLen-1; j++)
    {
        if(!isdigit(line[0][j]) && line[0][j] != '.')
        {
            vector<int> flag(5);

            flag[0] = isdigit(line[0][j-1]);
            flag[1] = isdigit(line[0][j+1]);
            flag[2] = isdigit(line[1][j-1]);
            flag[3] = isdigit(line[1][j]);
            flag[4] = isdigit(line[1][j+1]);

            vector<int> num(4, 1);

            if(flag[0])
            {
                int numStart{}, numEnd{};
                numEnd = j-1;
                numStart = line[0].rfind('.', numEnd);
                num[0] = stoi(line[0].substr(numStart+1, numEnd-numStart));
            }

            if(flag[1])
            {
                int numStart{}, numEnd{};
                numStart = j+1;
                numEnd = line[0].find('.', numStart);
                num[1] = stoi(line[0].substr(numStart, numEnd-numStart));
            }

            if(flag[0] && flag[1] && !(flag[2] || flag[3] || flag[4]))
            {
                sum += num[0]*num[1];
                continue;
            }

            // calculate numbers that might occur in the row below

            int count{};
            
            if(flag[2])
            {
                int numStart{}, numEnd{};
                count = 1;
                numEnd = line[1].find('.', j-1);
                numStart = line[1].rfind('.', numEnd-1);
                num[2] = stoi(line[1].substr(numStart+1, numEnd-numStart-1));

                if(!flag[3] && flag[4])
                {    
                    count++;

                    numStart = j+1;
                    numEnd = line[1].find('.', numStart);
                    num[3] = stoi(line[1].substr(numStart, numEnd-numStart));
                }
            }
            else
            {
                if(flag[3] || flag[4])
                {
                    count = 1;

                    int numStart{}, numEnd{};
                    numStart = line[1].rfind('.', j+1);
                    numEnd = line[1].find('.', numStart);
                    num[3] = stoi(line[1].substr(numStart+1, numEnd-numStart-1));
                }
            }

            if(count + flag[0] + flag[1] == 2)
            {
                int prod{1};
                for(int k = 0; k < 4; k++)
                {
                    prod *= num[k];
                }
                sum += prod;
            }
        }
    }

    // for the bottom edge
    for(int j = 1; j < lineLen-1; j++)
    {
        if(!isdigit(line[inSize-1][j]) && line[inSize-1][j] != '.')
        {
            vector<int> flag(5);

            flag[0] = isdigit(line[inSize-1][j-1]);
            flag[1] = isdigit(line[inSize-1][j+1]);
            flag[2] = isdigit(line[inSize-2][j-1]);
            flag[3] = isdigit(line[inSize-2][j]);
            flag[4] = isdigit(line[inSize-2][j+1]);

            vector<int> num(4, 1);

            if(flag[0])
            {
                int numStart{}, numEnd{};
                numEnd = j-1;
                numStart = line[inSize-1].rfind('.', numEnd);
                num[0] = stoi(line[inSize-1].substr(numStart+1, numEnd-numStart));
            }

            if(flag[1])
            {
                int numStart{}, numEnd{};
                numStart = j+1;
                numEnd = line[inSize-1].find('.', numStart);
                num[1] = stoi(line[inSize-1].substr(numStart, numEnd-numStart));
            }

            if(flag[0] && flag[1] && !(flag[2] || flag[3] || flag[4]))
            {
                sum += num[0]*num[1];
                continue;
            }

            // calculate numbers that might occur in the row above

            int count{};
            
            if(flag[2])
            {
                int numStart{}, numEnd{};
                count = 1;
                numEnd = line[inSize-2].find('.', j-1);
                numStart = line[inSize-2].rfind('.', numEnd-1);
                num[2] = stoi(line[inSize-2].substr(numStart+1, numEnd-numStart-1));

                if(!flag[3] && flag[4])
                {    
                    count++;

                    numStart = j+1;
                    numEnd = line[inSize-2].find('.', numStart);
                    num[3] = stoi(line[inSize-2].substr(numStart, numEnd-numStart));
                }
            }
            else
            {
                if(flag[3] || flag[4])
                {
                    count = 1;

                    int numStart{}, numEnd{};
                    numStart = line[inSize-2].rfind('.', j+1);
                    numEnd = line[inSize-2].find('.', numStart);
                    num[3] = stoi(line[inSize-2].substr(numStart+1, numEnd-numStart-1));
                }

    cout << sum << endl;
    return 0;
}
