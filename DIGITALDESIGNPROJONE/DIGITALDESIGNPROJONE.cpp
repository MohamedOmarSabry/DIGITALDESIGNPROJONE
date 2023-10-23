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
void CSetPrint(set<char>S) //orints a 1 d char set
{
    set<char>::iterator IT;
    for (IT=S.begin();IT!=S.end();IT++)
    {
        cout << *IT << endl;
    }
}
bool PoSValidation(vector<string> maxterms) //checks if the number of variables in a PoS in less than 11(+2 " ","+")
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
void PoSCleanUp(string PoS) //Removes the brackets from the PoS string and puts the terms in a vector
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
void SoPCleanUp(string SoP) //takes the SoP string and removes the " + " and stores minterms in a vector
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
bool SoPValidation2(vector<string> minterms) //validates number of variables is less than 11
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
    //flow: 
    //SoP: SoPVal1 --> SoPCleanUp --> SoPVal2 ?
    //PoS: PoSCleanUp --> PoSValidation ?
    //TODO 
    //validate that variables are letters (check from sets in SoPValidation2 and PoSValidation). 
    //POS not missing brackets. 
    //Process strings to create truth table and print PoS and SoP
    //KMAP up to 4. 
    //Print all PIs, show minterms, and binary. 
    //Get EPIs from PIs as booleans. 
    //Print minterms not covered by EPIs. 
    //Minimize using tabulation. 
    //10 test cases. 
    //Project Report. 
    //Use Github
    //Current validation: 
    //-No PoS in SoP 
    //-Number of variables not more than 10
    //TESTING:
    string PoST = "(a + b)(b + c)(c + d)";
    PoSCleanUp(PoST);
    //string SopT = "abc + bcd + ace";
   //SoPCleanUp(SopT);
}