#include <cstdio>
#include <string>
#include <cmath>
#include <map>
#include <functional>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*
 * Time complexity: TODO
 * Space complexity: TODO
 */

/*
 *
7123 4653 10
9288 6714 9S7RZV 30
2619 1434 HMH2YX 39
2588 3374 YWV0JQ 4
6284 8626 CQS1OZ 27
5099 1192 4GWLG6 19
6508 4507 Y5J0Q6 12
3161 2805 IQPY9F 36
47 8930 YC1FWC 44
751 2483 4O438H 29
3226 4983 LSPFA8 45

 */



struct Store {
    double store_x;
    double store_y;
    string name;
    int coupon_count;
    int dist;

    Store(int x, int y, string name, int coupon_count, double dist) : store_x(x), store_y(y), name(name), coupon_count(coupon_count), dist(dist) {};
};

bool compareStore(Store* a, Store* b)
{
    if (a->dist != b->dist)
        return a->dist < b->dist;

    if (a->coupon_count != b->coupon_count)
        return a->coupon_count > b->coupon_count;

    return a->name < b->name;
}


int main(int argc, const char *argv[]) {
    int N;
    double x, y;
    scanf("%lf %lf %d\n", &x, &y, &N);
    Store *storeArray[N];
    for (int i = 0; i < N; ++i) {
        char name[BUFSIZ];
        double shop_x, shop_y;
        int coupon_count;
        scanf("%lf %lf %s %d\n", &shop_x, &shop_y, name, &coupon_count);


        string strName = name;
        double dist_x = x - shop_x;
        double dist_y = y - shop_y;
        double dist = pow(dist_x, 2) + pow(dist_y, 2);

        //dist /= 100;
        //dist *= 100;
        dist = sqrt(dist);
        int newDist = int(dist);
        newDist /= 100;
        newDist *= 100;
        storeArray[i] = new Store(shop_x, shop_y, strName, coupon_count, newDist);
    }
    sort(storeArray, storeArray+N, compareStore);

    for (int i = 0; i < N; i++) {
        cout << storeArray[i]->store_x << " " << storeArray[i]->store_y << " " << storeArray[i]->name << " " << storeArray[i]->coupon_count << " "<< storeArray[i]->dist << endl;
    }



    return 0;
}
