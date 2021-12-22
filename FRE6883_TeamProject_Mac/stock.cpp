//
//  stock.cpp
//  New_try
//
//  Created by Yipei Zhang on 12/10/21.
//

#include "stock.hpp"
#include<iostream>
#include<vector>
#include<string>
using namespace std;


map<string, double> stock::cal_return()
{
    //set_N(N_);
    map<string, double> stock_price = stock::get_price();
    double last = 0.0;
    int index = 0;
    

    for (map<string, double>::iterator itr1 = stock_price.begin(); itr1 != stock_price.end(); itr1++)
    {
        if (itr1 == stock_price.begin())
        {
            daily_return[itr1->first] = 0;
            index = index + 1;
            last = itr1->second;
        }
        else
        {
            daily_return[itr1->first] = ((itr1->second - last) / last);
            index = index + 1;
            last = itr1->second;
        }

    }
    
    return daily_return;
}



void stock::cal_ARIT(stock IWB)
{
    map<string, double> benchmark = IWB.get_return();
    map<string, double> benchmark_2N_1;

    for (map<string, double>::iterator i = daily_return.begin(); i != daily_return.end(); i++) {

        benchmark_2N_1[i->first] = benchmark.find(i->first)->second;
    }
    vector<double> stock_return_vector;
    vector<double> benchmark_vector;

    for (map<string, double>::iterator i = daily_return.begin(); i != daily_return.end(); i++) {
        stock_return_vector.push_back(i->second);
    }
    for (map<string, double>::iterator i = benchmark_2N_1.begin(); i != benchmark_2N_1.end(); i++) {
        benchmark_vector.push_back(i->second);
    }

    ARIT = stock_return_vector - benchmark_vector;
}

