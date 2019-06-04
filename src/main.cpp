//
// Created by Александр Славутин on 2019-06-04.
//
#include <time.h>
#include <iostream>
#include <deque>
#include <map>
#include <vector>
#include <fstream>

using namespace std;

typedef  deque<string> prefixs;
const int NPREF = 2;
const int MAXGEN = 1000;

int main()
{
    setlocale(LC_ALL, "Russian");

    map <prefixs, vector<string> > statetab;
    prefixs prefix, start_prefix;
    vector<string> suffix_vector;
    string pref, suff;
    int suffix_number = 1;


    ifstream file;
    file.open("/Users/AlexSlav/Shtanuk/tp-lab-8/files/simonov");

    if (file.is_open()){
        cout<<"Check passed";
    } else {
        cout << "Error! Can not find file!";
    }


    for (auto i = 0; i < NPREF; ++i )
    {
        file >> pref;
        prefix.push_back(pref);
    }

    start_prefix = prefix;

    while(file >> suff)
    {
        if (statetab.find(prefix) == statetab.end())
        {
            suffix_vector.push_back(suff);
            statetab.insert(make_pair(prefix,suffix_vector));
            suffix_vector.clear();
        }
        else
            {
                statetab[prefix].push_back(suff);
            }
        prefix.push_back(suff);
        prefix.pop_front();

    }
    prefix = start_prefix;
    ofstream file_out;
    file_out.open("/Users/AlexSlav/Shtanuk/tp-lab-8/files/generated_text");
    for (auto & pref :prefix)
        file_out << pref << ' ';


    srand(time(NULL));

    for(auto i = 0; i < MAXGEN; ++i)
    {
        if (statetab.find(prefix) == statetab.end())
            break;

        suffix_number = rand() % statetab[prefix].size();
        file_out << statetab[prefix][suffix_number] << ' ';
        prefix.push_back(statetab[prefix][suffix_number]);
        prefix.pop_front();
        if (i % 5 == 0)
            file_out << endl;

    }






}