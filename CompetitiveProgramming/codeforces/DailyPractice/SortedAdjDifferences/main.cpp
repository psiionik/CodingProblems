#include <iostream>
#include <algorithm>
#include "SortedDiff.h"

using namespace std;

int main() {

    SortedDiff s = SortedDiff();
    
    int test_num;

    cin >> test_num;

    for (int i = 0; i < test_num; i++){
        int arr_len = 0;
        vector<int> arr;
        cin >> arr_len;

        vector<int> v;
        copy_n(istream_iterator<int>(cin), arr_len, back_inserter(v));

        s.getSortedAnswer(arr_len, v);
    }
    
    return 0;
}

