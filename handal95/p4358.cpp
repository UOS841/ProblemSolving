#include<iostream>
#include<map>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cout.precision(4);
    cout << fixed;
    
    map<string, int> hash_map;
    string species;
    int N = 0;
    while(getline(cin, species)){
        if(species.length() == 0){
            break;
        }
        hash_map[species]++;
        N++;
    }
    
    for(auto species: hash_map){
        cout << species.first << " ";
        cout << (species.second / N) * 100.0 << "\n";
    }
}
 