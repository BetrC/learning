#include <algorithm>
#include <iostream>
#include <string>

using namespace std;


int main() {

    string str = "sd";
    sort(str.begin(),str.end());

    while(next_permutation(str.begin(),str.end())){
        cout << str;
    }

    return 0;
}
