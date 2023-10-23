#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
void SVectorPrint(vector<string>V)
{
    for (int i = 0; i < V.size(); i++)
    {
        cout << V[i] << endl;
    }
    //cout << "Print" << endl;
}
void SoPCleanUp(string SoP)
{
    vector<string> minterms;
    for (int i=0;i<SoP.length();)
    {
        if (SoP.find(" ") == SoP.npos)
        {
           // i = SoP.length();
            //cout << "No more" << endl;
            minterms.push_back(SoP);
            SoP = SoP.substr(i);
            //cout << SoP << endl;
            SVectorPrint(minterms);
            return;
        }
        else
        {
            minterms.push_back(SoP.substr(i, SoP.find(" + ")));
            //cout << SoP.substr(i, SoP.find(" + "))<<"DONE" << endl;
            SoP = SoP.substr(SoP.find(" + ")+3);
            //cout << SoP << "after substr" << endl;
            //SoP.erase(0,SoP.find_first_not_of(" + "));
            //cout << SoP << "after erase" << endl;
        }
    }
   
}
bool SoPValidation(string SoP)
{
    if (SoP.find(" * ") != SoP.npos)
    {
        return false;
    }
    
}

int main()
{
    string SopT = "abc + bcd + ace";
    SoPCleanUp(SopT);
}