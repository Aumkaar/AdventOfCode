ifstream file("trial.txt");

    string line;
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