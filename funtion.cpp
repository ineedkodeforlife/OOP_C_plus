#include "funtion.h"

vector<string> split(const string& str, char delim)
{
    vector<string> tokens;

    if (!str.empty())
    {
        size_t start = 0, end;
        do {
            end = str.find(delim, start);
            tokens.push_back(str.substr(start, (end - start)));

            start = end + 1;
        } while (end != string::npos);
    }

    return tokens;
}

