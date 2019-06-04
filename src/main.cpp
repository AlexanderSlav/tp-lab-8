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
    //setlocale(LC_ALL, "Russian");

    map <prefixs, vector<string> > statetab;
    prefixs prefix, start_prefix;
    string pref, suff;
    vector<string> suffix_vector;

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


    }







}