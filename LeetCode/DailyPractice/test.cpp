/**
 * Given undirected graph, Police officer is at one node, and theif is at another node. They move in turns.
 * During each turn they have to move one adjacent node
 * Can always see each other
 * They move optimally
 * See if police can catch theif.
 */

bool catchTheif(UndirectedGraph *graph, Node *police, Node *theif){

}

/**
 * Find longest ascending subsequence in an given array.
 */
int longest_subsequence(vector<int> &array){
    // Creating 2d table
    vector<vector<int>> dp_matrix = size;

    // Finding the longest ascending subsequence
    int running_max = array.at(0);
    dp_matrix[0][0] = 1
    for (int i = 1; i < array.size(); i++){
        if (array.at(i) > running_max){
            dp_matrix[i][i] = dp_matrix[i-1][i-1] + 1;
            running_max = array.at(i);
        }
        else{
            dp_matrix[i][i] = dp_matrix[i-1][i-1];
        }
    }   

    return dp_matrix[array.size() - 1][array.size() -1];
}
