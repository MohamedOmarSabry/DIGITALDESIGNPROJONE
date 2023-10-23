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
void CSetPrint(set<char>S)
{
    set<char>::iterator IT;
    for (IT=S.begin();IT!=S.end();IT++)
    {
        cout << *IT << endl;
    }
}
bool PoSValidation(vector<string> maxterms)
{
    set<char> varss;
    for (int i = 0; i < maxterms.size(); i++)
    {
        for (int j = 0; j < maxterms[i].size(); j++)
        {
            varss.emplace(maxterms[i][j]);
        }
    }
    //CSetPrint(varss);
    if (varss.size() < 13)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void PoSCleanUp(string PoS)
{
    vector<string> maxterms;
    for (int i = 0; i < PoS.length()-1;)
    {
        if (PoS.find("(") == PoS.npos)
        {
            // i = SoP.length();
             //cout << "No more" << endl;
            //maxterms.push_back(PoS);
            //PoS = PoS.substr(i);
            //cout << SoP << endl;
            SVectorPrint(maxterms);
            i = PoS.length() - 1;
        }
        else
        {
            maxterms.push_back(PoS.substr(i+1, PoS.find(")")-1));
            //cout << SoP.substr(i, SoP.find(" + "))<<"DONE" << endl;
            PoS = PoS.substr(PoS.find(")") + 1);
            //cout << SoP << "after substr" << endl;
            //SoP.erase(0,SoP.find_first_not_of(" + "));
            //cout << SoP << "after erase" << endl;
        }
    }
    //PoSValidation(maxterms);
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
            i = SoP.length();
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
    if (SoP.find("(") != SoP.npos)
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
    //PoSCleanUp --> PoSValidation
    //string SopT = "abc + bcd + ace";
    //SoPCleanUp(SopT);
    string PoST = "(a + b)(b + c)(c + d)";
    PoSCleanUp(PoST);
}