#include <iostream>
#include <iterator>
#include <map>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	for(int i = 0; i < t; i++){
	    cin >> n;
	    int arr[61] = {0};
	    int temp;
	    for(int j = 0; j < n; j++){
	        cin >> temp;
	        arr[temp]++;
	    }
        //for(int j = 1; j < 11; j++) cout << arr[j] << " ";
	    multimap<int, int> m;
	    multimap<int, int> :: iterator it;
	    for(int j = 60; j > 0; j--){
	        if(arr[j] != 0){
	            m.insert(pair<int, int>(arr[j], j));
	        }
	    }
	    for(auto it = m.rbegin(); it != m.rend(); it++){
	        for(int k = 0; k < it->first; k++){
	            cout << it->second << " ";
	        }
	    }
	    cout << endl;
	}
	return 0;
}