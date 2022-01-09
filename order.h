#ifndef SIGMAX_POOL_DATA_H
#define SIGMAX_POOL_DATA_H

#include <vector>
#include <iostream>
#include <sstream>
#include "common.h"
using namespace std;

class Order {
public:
    PID pid {}, prev_pid {}, next_pid {};
    bool is_buy {};
    int64_t price {}, shares {};
    vector<int64_t> attr_int;
    vector<float> attr_float;
    Order(int num_int, int num_float)
            : attr_int(vector<int64_t>(num_int)),
              attr_float(vector<float>(num_float)){}
    ~Order(){
        attr_int.clear();  attr_float.clear();
    }
    void dump(ostream& oss) const;
};

void Order::dump(ostream& oss) const{
    oss << "pid:" << pid << " prev_pid:" << prev_pid <<
         " next_pid:" << next_pid << " is_buy:" << is_buy <<
         " price:" << price << " shares:" << shares;
    oss << " attr_int64: [";
    for(auto& attr : attr_int){
        oss << attr << " ";
    }
    oss << "] ";
    oss << " attr_float: [";
    for(auto& attr : attr_float){
        oss << attr << " ";
    }
    oss << "] ";
    oss << endl;
}

#endif //SIGMAX_POOL_DATA_H
