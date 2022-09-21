// C++ program to display all permutations
// of an array using STL in C++

#include <bits/stdc++.h>
using namespace std;

deque<deque<int>> z;

void findPermutations(deque<int> a, int n)
{


sort(a.begin(), a.end());

// Find all possible permutations
// cout << "Possible permutations are:\n";
do {
	z.push_back(a);
} while (next_permutation(a.begin(), a.end()));
}

// Driver code
int main()
{

deque<int> a;
for(int i = 10; i<=40; i+=10){
    a.push_back(i);
}

findPermutations(a, 4);

for(int i = 0; i < z.size(); i++){
    for(int j= 0; j < 4; i++){
        cout << z[i][j]<<" ";
    }
    cout<<"\n";
}

return 0;
}
