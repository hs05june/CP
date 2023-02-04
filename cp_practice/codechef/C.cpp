#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	
	while(t--){
	    string a;
	    cin >> a;
	    bool ans = false;
	    for(int i = 0; i < a.length()-2;i++){
	        if((a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u') && (a[i+1]=='a' || a[i+1]=='e' || a[i+1]=='i' || a[i+1]=='o' || a[i+1]=='u') && (a[i+2]=='a' || a[i+2]=='e' || a[i+2]=='i' || a[i+2]=='o' || a[i+2]=='u')){
	            ans = true;
	            break;
	        }
	    }
	    
	    ans ? cout <<"Happy\n" : cout << "Sad\n"; 
	}
	return 0;
}
