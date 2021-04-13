#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1;
    vector<string> v2;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v2.push_back("ABC");
    v2.push_back("DEF");
    
    unsigned int i;
    for (i = 0; i < v1.size(); i++) {
        cout << "v1[" << i << "]=" << v1[i] << endl;
    }

    for (i = 0; i < v2.size(); i++) {
        cout << "v2[" << i << "]=" << v2[i] << endl;
    }

    cout << "Size:" << v1.size() << endl;
    cout << "Capacity:" << v1.capacity() << endl;
    cout << "Is empty?:" << v1.empty() << endl;
    v1.clear();
    cout << "Is empty?:" << v1.empty() << endl;


    return 0;
}



