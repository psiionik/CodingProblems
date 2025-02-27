// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <cstdlib>

// using namespace std;


// void getSorted(int arr_len, vector<int> arr){
//    // Sort the list first
//     sort(arr.begin(), arr.end());

//     int mid = arr.size() / 2;

//     int left_pointer = mid - 1;
//     int right_pointer = mid;
//     int even_odd = 0;
//     while (left_pointer >= 0 || right_pointer < arr.size()){
//         if (even_odd % 2 == 0){
//             cout << arr[left_pointer] << " ";
//             left_pointer--;
//             even_odd += 1;
//         }
//         else {
//             cout << arr[right_pointer] << " ";
//             right_pointer++;
//             even_odd += 1;
//         }
//     }

//     cout << endl;
// }

// int main() {

    
//     int test_num;

//     cin >> test_num;

//     for (int i = 0; i < test_num; i++){
//         int arr_len = 0;
//         cin >> arr_len;

//         vector<int> v;
//         copy_n(istream_iterator<int>(cin), arr_len, back_inserter(v));

//         getSorted(arr_len, v);
//     }
    
//     return 0;
// }

