#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> Vec_1;

    vector<string> Vec_2;

    Vec_1.push_back(3);
    Vec_1.push_back(5);

    Vec_2.push_back("Science");
    Vec_2.push_back("Technology");


    cout<< "Content of vector 1: ";
    for(int i = 0; i< Vec_1.size(); i++)
    {
        cout<<Vec_1[i]<<" "<<endl;
    }

    cout<< "Content of Vector 2: ";
    for(int i = 0; i< Vec_2.size(); i++)
    {
        cout<<Vec_2[i]<<" "<<endl;
    }

    return 0;
}