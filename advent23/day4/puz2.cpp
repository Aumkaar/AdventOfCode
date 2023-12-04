// straighforward modification to puzzle 1

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int inSize = 198;
    vector<string> line(inSize);

    ifstream file("input.txt");
    if(!file)
    {
        cout << "Error opening file." << endl;
        return -1;
    }

    int winSize{10};
    int havSize{25};
    vector<vector<int>> winNum(inSize, vector<int>(winSize));
    vector<vector<int>> havNum(inSize, vector<int>(havSize));

    for(int i = 0; i < inSize; i++)
    {
        string strInput{};
        for(int j = 0; j < 2; j++)
            file >> strInput;
        
        for(int j = 0; j < winSize; j++)
        {
            file >> strInput;
            winNum[i][j] = stoi(strInput);
        }

        file >> strInput;

        for(int j = 0; j < havSize; j++)
        {
            file >> strInput;
            havNum[i][j] = stoi(strInput);
        }
    }

    file.close();

    vector<int> numOfCards(inSize, 1);
    int sum{};

    for(int i = 0; i < inSize; i++)
    {
        sort(winNum[i].begin(), winNum[i].end());
        sort(havNum[i].begin(), havNum[i].end());

        int cardNum{};
        for(int j = 0; j < winSize; j++)
        {
            if(binary_search(havNum[i].begin(), havNum[i].end(), winNum[i][j]))
                cardNum++;
        }

        for(int j = i+1; j <= i + cardNum; j++)
            numOfCards[j] += numOfCards[i];

        sum += numOfCards[i];
    }

    cout << sum << endl;

    return 0;
}