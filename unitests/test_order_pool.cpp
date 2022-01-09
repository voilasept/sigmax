#include "../order.h"
#include "../pool_mgr.h"
#include <vector>

#include "gtest/gtest.h"

using namespace std;


TEST(pool_mgr, order){
    ostringstream oss {};

    PoolMgr<Order> orders {3, 1, 1};
    Order& order1 = orders.dispense();
    order1.price = 111;

    Order& order2 = orders.dispense();
    order2.price = 112;

    Order& order3 = orders.dispense();
    order3.price = 113;

    orders.recycle(move(order1));
    orders.recycle(move(order3));

    Order& order4 = orders.dispense();
    order4.price = 114;



    Order& order5 = orders.dispense();
    order5.price = 115;

    orders.recycle(move(order4));

    Order& last_order = orders.dispense();
    last_order.price = 116;

    orders.dispense().price = 117;
    orders.dispense().price = 118;

    orders.recycle(move(last_order));
    orders.dump(oss);

    orders.clear();
    orders.dump(oss);


    Order& order11 = orders.dispense();
    order11.price = 111;

    Order& order12 = orders.dispense();
    order12.price = 112;

    Order& order13 = orders.dispense();
    order13.price = 113;

    orders.recycle(move(order11));
    orders.recycle(move(order13));

    Order& order14 = orders.dispense();
    order14.price = 114;

    Order& order15 = orders.dispense();
    order15.price = 115;

    orders.recycle(move(order14));

    Order& last_order1 = orders.dispense();
    last_order1.price = 116;

    orders.dispense().price = 117;
    orders.dispense().price = 118;

    orders.recycle(move(last_order1));

    orders.dump(oss);

    string golden
            = " ----------------\n"
              " PoolMgrType::dump() len(pids):8 len(data):8 capacity:8\n"
              " cur_id:4\n"
              " 2 1 5 4 \n"
              " Dumping Pool:\n"
              " pid:1 prev_pid:0 next_pid:0 is_buy:0 price:112 shares:0 attr_int64: [0 ]  attr_float: [0 ] \n"
              " pid:2 prev_pid:0 next_pid:0 is_buy:0 price:115 shares:0 attr_int64: [0 ]  attr_float: [0 ] \n"
              " pid:3 prev_pid:0 next_pid:0 is_buy:0 price:118 shares:0 attr_int64: [0 ]  attr_float: [0 ] \n"
              " pid:4 prev_pid:0 next_pid:0 is_buy:0 price:117 shares:0 attr_int64: [0 ]  attr_float: [0 ] \n"
              " ----------------\n"
              " ----------------\n"
              " PoolMgrType::dump() len(pids):8 len(data):8 capacity:8\n"
              " cur_id:0\n"
              " \n"
              " Dumping Pool:\n"
              " ----------------\n"
              " ----------------\n"
              " PoolMgrType::dump() len(pids):8 len(data):8 capacity:8\n"
              " cur_id:4\n"
              " 2 1 5 4 \n"
              " Dumping Pool:\n"
              " pid:1 prev_pid:0 next_pid:0 is_buy:0 price:112 shares:0 attr_int64: [0 ]  attr_float: [0 ] \n"
              " pid:2 prev_pid:0 next_pid:0 is_buy:0 price:115 shares:0 attr_int64: [0 ]  attr_float: [0 ] \n"
              " pid:3 prev_pid:0 next_pid:0 is_buy:0 price:118 shares:0 attr_int64: [0 ]  attr_float: [0 ] \n"
              " pid:4 prev_pid:0 next_pid:0 is_buy:0 price:117 shares:0 attr_int64: [0 ]  attr_float: [0 ] \n"
              " ----------------\n";
    EXPECT_EQ(golden, oss.str());
}