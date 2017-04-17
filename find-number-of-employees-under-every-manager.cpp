#include<bits/stdc++.h>
using namespace std;

void populateMap(map <char, char> positions, map <char, vector<char> > &mp){
    map <char, char>::iterator it;
    for(it = positions.begin(); it != positions.end(); it++){
        char parent = it->second;
        char child = it->first;
        
        if(mp.find(parent) != mp.end()){
            mp[parent].push_back(child);
        } else {
            vector<char> temp;
            temp.push_back(child);

            mp[parent] = temp;
        }
    }
}

int getEmployees(map <char, vector<char> > mp, char index){
    if(mp.find(index) == mp.end()){
        return 0;
    } else {
        vector <char> temp = mp[index];
        int ans = 0;
        for(int i=0; i<temp.size(); i++){
            if(index != temp[i])
                ans += getEmployees(mp, temp[i]) + 1;
        }
        return ans;
    }
}

int main(){
    map <char, char> positions;
    map <char, char>::iterator it;

    map <char, vector<char> > mp;

    positions['A'] = 'C';
    positions['B'] = 'C';
    positions['F'] = 'F';
    positions['D'] = 'E';
    positions['C'] = 'F';
    positions['E'] = 'F';

    populateMap(positions, mp);

    for(it = positions.begin(); it != positions.end(); it++){
        cout<<it->first<<" "<<getEmployees(mp, it->first)<<"\n";
    }

    return 0;
}
