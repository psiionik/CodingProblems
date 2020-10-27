// #include "KaaviSpell.h"

// void generatePermutations(string A, int index, string S, string T, int &result) {
//     if (A.length() >= T.length() && A.compare(0, T.length(), T) == 0){
//         result++;
//     }

//     if (index == S.length()){
//         // cout << "The string is: " << A << endl;
//         return;
//     }

//     // cout << "The string is: " << A << endl;
//     generatePermutations(S[index] + A, index+1, S, T, result);
//     generatePermutations(A + S[index], index+1, S, T, result);
// }

// int KaaviSpell::getOperations(string T, string S){
//     int MODULO = 998244253;
//     int result = 0;

//     string A = "";
//     A += S[0];

//     if (T == A){
//         result++;
//     }

//     generatePermutations(A, 1, S, T, result);


//     return (result * 2) % MODULO;
// }

