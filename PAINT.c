#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<string> a;
    vector<char> p;
    int n;
    cin >> n;
    p.resize(n);
    cin.ignore();
    for(int i = 0; i < n; i++){
        string tmp;
        getline(cin, tmp);
        a.push_back(tmp);
        if(tmp[0] == '1'){
            p.at((int)(tmp[2]- 97)) = tmp[2];
        }
    }
    
    for(int i = n - 1; i >= 0; i--){
        if(a.at(i)[0] == '2'){
            p.at((int)(a.at(i)[2]- 97)) = p.at((int)(a.at(i)[4]- 97));
        }else{
            a.at(i)[2] = p.at((int)(a.at(i)[2]- 97));
        }
    }
    for(int i = 0; i < n; i++){
        if(a.at(i)[0] == '1')
            cout << a.at(i)[2];
    }
    return 0;
}
