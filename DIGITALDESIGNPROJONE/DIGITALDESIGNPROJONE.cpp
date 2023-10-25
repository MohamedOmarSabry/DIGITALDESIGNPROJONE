#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <iterator>
#include <algorithm>
#include <string>
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
bool PoSValidation(vector<string>& maxterms) //checks if the number of variables in a PoS in less than 11(+2 " ","+")
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
bool SoPValidation2(vector<string>& minterms,set<char>& var) //validates number of variables is less than 11
{
    
    for (int i = 0; i < minterms.size(); i++)
    {
        for (int j = 0; j < minterms[i].size(); j++)
        {
            //cout << minterms[i][j];
            if (minterms[i][j]=='\'')
            {
                //cout << "Apostrophe detected" << endl;
            }
            else
            {
                var.emplace(minterms[i][j]);
            }
            
        }
    }
    //cout << endl;
    //CSetPrint(var);
    if (var.size() < 11)
    {
        return true;
    }
    else
    {
        return false;
    }
   
}
void SoPtoBinaryString(vector<string>& minterms, vector<string>&Bminterms, set<char>& var) //takes the minterm vector and number of variables and var set and creates the binary version of the minterms
{
    //minterm vars should be ascending
    cout << "SOPBS" << endl;
    string BinaryT;
    set<char>::iterator IT;
    for (int i = 0; i < minterms.size(); i++)
    {
        for (IT = var.begin(); IT != var.end(); IT++)
        {
            if (minterms[i].find(*IT) != minterms[i].npos)
            {
                if (minterms[i].find(*IT) == minterms[i].length() - 1)
                {
                    BinaryT.append("1");
                }
                else
                {
                    if (minterms[i][minterms[i].find(*IT) + 1] == '\'')
                    {
                        BinaryT.append("0");
                    }
                    else
                    {
                        BinaryT.append("1");
                    }
                }
            }
            else
            {
                BinaryT.append("-");
            }
        }
        Bminterms.push_back(BinaryT);
        cout << BinaryT << endl;
        BinaryT.clear();
    }
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
    set<char> var;
    cout << SoPValidation2(minterms, var) << endl;
    CSetPrint(var);
    vector<string>Bminterms;
    SoPtoBinaryString(minterms, Bminterms, var);
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
    //test
    //string PoST = "(a + b)(b + c)(c + d)";
    //PoSCleanUp(PoST);
    string SopT = "abc + bcd + ac'e";
    cout << SoPValidation1(SopT) << endl;
    SoPCleanUp(SopT);
}