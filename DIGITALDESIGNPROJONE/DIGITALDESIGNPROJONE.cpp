#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <iterator>
using namespace std;
void SVectorPrint(vector<string>V) //prints a 1d string vector
{
    for (int i = 0; i < V.size(); i++)
    {
        cout << V[i] << endl;
    }
    //cout << "Print" << endl;
}
void SoPCleanUp(string SoP) //takes the SoP string and isolates the minterms
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
bool SoPValidation1(string SoP) //checks if SoP has a PoS
{
    if (SoP.find("*") != SoP.npos)
    {
        return false;
    }
    else
    {
        return true;
    }
}
bool SoPValidation2(vector<string> minterms) //validates number of variables
{
    set<char> var;
    for (int i = 0; i < minterms.size(); i++)
    {
        for (int j = 0; j < minterms[i].size(); j++)
        {
            var.emplace(minterms[i][j]);
        }
    }
    if (var.size() < 11)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    //flow: SoPVal1 --> SoPCleanUp --> SoPVal2
    string SopT = "abc + bcd + ace";
    SoPCleanUp(SopT);
}