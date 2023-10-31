#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <iterator>
#include <algorithm>
#include <string>
#include <cmath>
#include <unordered_set>
using namespace std;
void OnesMapPrint(map<int, vector<string>>& IMPG)
{
    map<int, vector<string>>::iterator IT;
    //cout << "Groups: " << endl;
    for (IT = IMPG.begin(); IT != IMPG.end(); IT++)
    {
        cout << IT->first << endl;
        for (int i = 0; i < IT->second.size(); i++)
        {
            cout << IT->second[i] << " ";
        }
        cout << endl;
    }
}
void SVectorPrint(vector<string>V) //prints a 1d string vector
{
    for (int i = 0; i < V.size(); i++)
    {
        cout << V[i] << endl;
    }
    //cout << "Print" << endl;
}
void SSetPrint(unordered_set<string>S) //orints a 1 d char set
{
    unordered_set<string>::iterator IT;
    for (IT = S.begin(); IT != S.end(); IT++)
    {
        cout << *IT << endl;
    }
}
void CSetPrint(set<char>S) //orints a 1 d char set
{
    set<char>::iterator IT;
    for (IT=S.begin();IT!=S.end();IT++)
    {
        cout << *IT << endl;
    }
}
void ISetPrint(set<int>S) //orints a 1 d char set
{
    set<int>::iterator IT;
    for (IT = S.begin(); IT != S.end(); IT++)
    {
        cout << *IT << endl;
    }
}
void GroupByOnesIMP(unordered_set<string> implicants, map<int, vector<string>>& IMPG)
{
    unordered_set<string>::iterator IT;
    string T = "";
    for (IT=implicants.begin(); IT != implicants.end(); IT++)
    {
        int count = 0;
        for (int j = 0; j < IT->size(); j++)
        {
            T = *IT;
            if (T[j] == '1')
            {
                count++;
            }
            else if (T[j] == '-')
            {
                count++;
            }
        }
        if (IMPG.find(count) != IMPG.end())
        {
            IMPG.find(count)->second.push_back(*IT);
        }
        else
        {
            vector<string> EMP;
            EMP.push_back(*IT);
            IMPG.emplace(count, EMP);
        }
    }
    OnesMapPrint(IMPG);
}
void ImplicantGroupComparison(map<int, vector<string>>& IMPG)
{
    map<int, vector<string>>::iterator IT1;
    map<int, vector<string>>::iterator IT2;
    unordered_set<string>EPI;
    unordered_set<string>PI;
    unordered_set<string>PIs;
    //unordered_set<string>PI;
    unordered_set<string>Found;
    while (IMPG.size() != 0)
    {
        for (IT1 = IMPG.begin(); IT1 != IMPG.end()--; IT1++)
        {
            // cout << "IT1" << " ";
            for (int i = 0; i < IT1->second.size(); i++)
            {
                //cout << "I" << " ";
                IT2 = IT1;
                IT2++;

                for (IT2; IT2 != IMPG.end(); IT2++)
                {
                    //cout << "IT2" << " ";

                    for (int j = 0; j < IT2->second.size(); j++)
                    {
                        //cout << "J" << " ";
                        int flag = 0;
                        bool flag2 = 0;
                        string NPI = IT1->second[i];
                        //cout << NPI << endl;
                        for (int k = 0; k < IT2->second[j].size(); k++)
                        {
                            //cout << "K" << " ";

                            if (IT1->second[i][k] == IT2->second[j][k])
                            {

                            }
                            else
                            {

                                    if (flag != 1)
                                    {
                                        NPI[k] = '-';
                                    }
                                    else if (k == IT2->second[j].size() - 1)
                                    {
                                        NPI[k] = '-';
                                    }

                                    flag++;
                            }


                        }
                        if (flag == 1)
                        {
                            flag2 = 1;
                        }
                        if (flag2 != 0)
                        {
                            //cout << "Found comparison" << endl;
                            //cout << IT1->second[i] << " " << NPI << " " << IT2->second[j] << " " << endl;
                            PI.emplace(NPI);
                            PIs.emplace(NPI);
                            Found.emplace(IT1->second[i]);
                            Found.emplace(IT2->second[j]);
                        }


                    }
                }
                if (Found.find(IT1->second[i]) == Found.end())
                {
                    EPI.emplace(IT1->second[i]);
                }
            }


        }
        //cout << "PIs: " << endl;
        //SSetPrint(PI);
        IMPG.clear();
        GroupByOnesIMP(PI,IMPG);
        //EPI.clear();
        PI.clear();
        //Store PIs
    }
    cout << "PIs: " << endl;
    SSetPrint(PIs);
    cout << "EPIs: " << endl;
    SSetPrint(EPI);
    
}
bool PoSValidation(vector<string>& maxterms, set<char>& var) //checks if the number of variables in a PoS in less than 11(+2 " ","+")
{
    set<char> varss;
    for (int i = 0; i < maxterms.size(); i++)
    {
        for (int j = 0; j < maxterms[i].size(); j++)
        {
            if (maxterms[i][j] == '\'')
            {

            }
            else if (maxterms[i][j] == '+')
            {

            }
            else
            {
                varss.emplace(maxterms[i][j]);
            }

        }
    }
    var = varss;
    //CSetPrint(varss);
    if (varss.size() < 11)
    {
        return true;
    }
    else
    {
        return false;
    }
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
void SoPtoBinaryString2(vector<string>& minterms, set<char>& var) //takes the minterm vector and number of variables and var set and creates the binary version of the minterms
{
    //minterm vars should be ascending
    //cout << "SOPBS" << endl;
    string BinaryT;
    vector<string>Bminterms;
    set<int>Cannoncial;
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
    for (int i = 0; i < Bminterms.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < Bminterms[i].size(); j++)
        {
            if (Bminterms[i][j] == '0')
            {
                
            }
            else
            {
                count = count + pow(2, Bminterms[i].size()-j-1);
            }
        }
        Cannoncial.emplace(count);
    }
    ISetPrint(Cannoncial);
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
void PrintCanonicalForms(vector<string>& Bminterms, vector<string>& Bmaxterms, set<char>& var) {
    vector<char> varVector(var.begin(), var.end());

    cout << "Canonical SOP: " << endl;
    for (int i = 0; i < Bminterms.size(); i++) {
        if (Bminterms[i].find('-') == string::npos) {
            cout << "(";
            for (int j = 0; j < Bminterms[i].size(); j++) {
                if (Bminterms[i][j] == '0') {
                    cout << varVector[j] << "' ";
                }
                else if (Bminterms[i][j] == '1') {
                    cout << varVector[j] << " ";
                }
            }
            cout << ") + ";
        }
    }

    cout << endl << "Canonical POS: " << endl;
    for (int i = 0; i < Bmaxterms.size(); i++) {
        if (Bmaxterms[i].find('-') == string::npos) {
            cout << "(";
            for (int j = 0; j < Bmaxterms[i].size(); j++) {
                if (Bmaxterms[i][j] == '1') {
                    cout << varVector[j] << "' ";
                }
                else if (Bmaxterms[i][j] == '0') {
                    cout << varVector[j] << " ";
                }
            }
            cout << ") + ";
        }
    }
}

void PoStoBinaryString(vector<string>& maxterms, vector<string>& Bmaxterms, set<char>& var)
{
    cout << "POSBS" << endl;

    for (int i = 0; i < maxterms.size(); i++)
    {
        string BinaryT;

        for (char ch : var)
        {
            if (maxterms[i].find(ch) != string::npos)
            {
                if (maxterms[i].find(ch) == maxterms[i].length() - 1)
                {
                    BinaryT += "0";  // Change "1" to "0" for PoS
                }
                else
                {
                    if (maxterms[i][maxterms[i].find(ch) + 1] == '\'')
                    {
                        BinaryT += "1";
                    }
                    else
                    {
                        BinaryT += "0";  // Change "1" to "0" for PoS
                    }
                }
            }
            else
            {
                BinaryT += "1";  // Change "-" to "1" for PoS
            }
        }

        Bmaxterms.push_back(BinaryT);
        cout << BinaryT << endl;
    }
}

void GroupByOnes(vector<string>&CmintermsB, map<int, vector<string>>&IMPG)
{
    for (int i = 0; i < CmintermsB.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < CmintermsB[i].size(); j++)
        {

            if (CmintermsB[i][j] == '1')
            {
                count++;
            }
        }
        if (IMPG.find(count)!=IMPG.end())
        {
            IMPG.find(count)->second.push_back(CmintermsB[i]);
        }
        else
        {
            vector<string> EMP;
            EMP.push_back(CmintermsB[i]);
            IMPG.emplace(count, EMP);
        }
    }
    OnesMapPrint(IMPG);
}
void PrintMinMaxterms(vector<vector<bool>>& TTable, set<char>& var,vector<string>&Cminterms)
{
    vector<string>SOPs;
    vector<string>POSs;
    for (int i = 0; i < TTable.size(); i++)
    {
        set<char>::iterator IT;
        IT = var.begin();
        string POS = "";
        string SOP = "";
        //cout << TTable[i][TTable[i].size() - 1] << endl;
        if (TTable[i][TTable[i].size()-1] == bool(1))
        {
            for (int j = 0; j < TTable[i].size() - 1; j++)
            {
                if (TTable[i][j] == bool(1))
                {
                    SOP.push_back(*IT);
                    IT++;
                }
                else
                {
                    SOP.push_back(*IT);
                    SOP.append("'");
                    IT++;
                }
            }
            //cout << SOP << endl;
            SOPs.push_back(SOP);
        }
        else
        {
            POS.append("(");
            for (int j = 0; j < TTable[i].size() - 1; j++)
            {
                if (TTable[i][j] == bool(1))
                {
                    POS.push_back(*IT);
                    POS.append("'");
                    IT++;
                }
                else
                {
                    POS.push_back(*IT);
                    IT++;
                }
                if (j != TTable[i].size() - 2)
                {
                    POS.append(" + ");
                }
                
            }
            POS.append(")");
            //cout << POS << endl;
            POSs.push_back(POS);
        }
    }
    cout << "Cannonical SoP: " << endl;
    for (int i = 0; i < SOPs.size(); i++)
    {
        cout << SOPs[i];
        if (i != SOPs.size() - 1)
        {
            cout<< " + ";
        }
    }
    cout << endl;
    SoPtoBinaryString2(SOPs, var);
    cout << "Cannonical PoS: " << endl;
    for (int i = 0; i < POSs.size(); i++)
    {
        cout << POSs[i];
    }
    cout << endl;
    //PoStoBinaryString2(POSs, var);
    //Needs to be fixed
    Cminterms = SOPs;
}
void FTTColFillSOP (vector<vector<bool>>&TTable, vector<string>& Bminterms)
{
    //cout << "FFTCOLFILL";
    for (int i = 0; i < Bminterms.size(); i++)
    {
        for (int j = 0; j < TTable.size(); j++)
        {
            int countBM = 0;
            for (int k = 0; k < TTable[j].size()-1; k++)
            {
                //cout << "CountBM: " << countBM << " i: " << i << " BMIN: " << Bminterms[i][countBM] << " TTABLE: " << TTable[j][k] << " j: " << j << endl;
                if (countBM< Bminterms[i].size())
                {
                    if (Bminterms[i][countBM] == '-')
                    {
                        countBM++;
                        if (countBM == Bminterms[i].size())
                        {
                            TTable[j][TTable[j].size() - 1] = 1;
                            //cout << "CountBM: " << countBM << " i: " << i << " TTABLE: " << TTable[j][TTable[j].size() - 1] << " j: " << j << endl;
                        }
                    }
                    else
                    {
                        if (bool(Bminterms[i][countBM]-'0') == TTable[j][k])
                        {
                            countBM++;
                            if (countBM == Bminterms[i].size())
                            {
                                TTable[j][TTable[j].size() - 1] = 1;
                                //cout << "CountBM: " << countBM << " i: " << i << " TTABLE: " << TTable[j][TTable[j].size() - 1] << " j: " << j << endl;
                            }

                        }
                        else
                        {
                            countBM = 0;
                            k = TTable[j].size();
                        }
                    }
                }
                else
                {
                        TTable[j][TTable[j].size() - 1] = 1;
                        //cout << "CountBM: " << countBM << " i: " << i << " TTABLE: " << TTable[j][TTable[j].size() - 1] << " j: " << j << endl;
                }
            }
        }
    }
}
void FTTColFillPOS (vector<vector<bool>>&TTable, vector<string>& Bmaxterms)
{
    //cout << "FFTCOLFILL";
    for (int i = 0; i < Bmaxterms.size(); i++)
    {
        for (int j = 0; j < TTable.size(); j++)
        {
            int countBM = 0;
            for (int k = 0; k < TTable[j].size()-1; k++)
            {
                //cout << "CountBM: " << countBM << " i: " << i << " BMIN: " << Bminterms[i][countBM] << " TTABLE: " << TTable[j][k] << " j: " << j << endl;
                if (countBM< Bmaxterms[i].size())
                {
                    if (Bmaxterms[i][countBM] == '-')
                    {
                        countBM++;
                        if (countBM == Bmaxterms[i].size())
                        {
                            //cout << "CountBM: " << countBM << " i: " << i << " TTABLE: " << TTable[j][TTable[j].size() - 1] << " j: " << j << endl;
                        }
                    }
                    else
                    {
                        if (bool(Bmaxterms[i][countBM]-'0') == TTable[j][k])
                        {
                            countBM++;
                            if (countBM == Bmaxterms[i].size())
                            {
                                //cout << "CountBM: " << countBM << " i: " << i << " TTABLE: " << TTable[j][TTable[j].size() - 1] << " j: " << j << endl;
                            }

                        }
                        else
                        {
                            countBM = 0;
                            TTable[j][TTable[j].size() - 1] = 1;
                            k = TTable[j].size();
                        }
                    }
                }
                else
                {

                    //cout << "CountBM: " << countBM << " i: " << i << " TTABLE: " << TTable[j][TTable[j].size() - 1] << " j: " << j << endl;
                }
            }
        }
    }
}
void TTableBuild(set<char>& var, vector<string>& Bminterms) //createsTruthTableForVariables
{
    vector<vector<bool>>TTable(pow(2,var.size()),vector<bool>(var.size()+1,0));
    set<char>::iterator IT;
    IT = var.begin();
    for (int i = 0; i < var.size(); i++)
    {
        //cout << "i: " << i << endl;
        int count = 0;
        for (int j = 0; j < pow(2, i); j++)
        {
            //cout << "Row: " << j << " ";
            //cout << "j: " << j << endl;
            for (int k = 0; k < pow(2, var.size() - i-1); k++)
            {
                count++;
            }
            //cout << "count: " << count<< endl;
            for (int k = count; k < count+pow(2,var.size()-i-1); k++)
            {
                //cout << "k: " << k << " i: " << i << endl;
                TTable[k][i]=1;
            }
            count = count + pow(2, var.size() - i - 1);
        }
        //IT++;
    }
    for (IT; IT != var.end(); IT++)
    {
        cout << *IT << " ";
    }
    cout << "F ";
    cout << endl;
    FTTColFillSOP(TTable, Bminterms);
    for (int i = 0; i < TTable.size(); i++)
    {
        //cout << *IT << "\t";
        for (int j = 0; j < TTable[i].size(); j++)
        {
            cout << TTable[i][j] << " ";
        }
        cout << endl;
    }
    vector<string>CMinterms;
    vector<string>CMintermsB;
    PrintMinMaxterms(TTable, var,CMinterms);
    SoPtoBinaryString(CMinterms, CMintermsB,var);
    //SVectorPrint(CMintermsB);
    map<int, vector<string>>IMPG;
    GroupByOnes(CMintermsB, IMPG);
    ImplicantGroupComparison(IMPG);

}
void PoSCleanUp(string PoS) //Removes the brackets from the PoS string and puts the terms in a vector
{
    vector<string> maxterms;
    for (int i = 0; i < PoS.length() - 1;)
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
            maxterms.push_back(PoS.substr(i + 1, PoS.find(")") - 1));
            //cout << SoP.substr(i, SoP.find(" + "))<<"DONE" << endl;
            PoS = PoS.substr(PoS.find(")") + 1);
            //cout << SoP << "after substr" << endl;
            //SoP.erase(0,SoP.find_first_not_of(" + "));
            //cout << SoP << "after erase" << endl;
        }
    }
    set<char>varss;
    PoSValidation(maxterms, varss);
    CSetPrint(varss);
    vector<string>Bmaxterms;
    PoStoBinaryString(maxterms, Bmaxterms, varss);
    //TTableBuild
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
    TTableBuild(var, Bminterms);
    
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
    // Things left: Pos not working, Turn cannocial sop to numbers. Save prime implicants, show minterms covered by them. Turn EPIS into booleans.
    //string PoST = "(a + b)(b + c)(c + d)";
    //PoSCleanUp(PoST);
    //string SopT = "abc + bcd + ac'e";
    //string SopT = "ac + ba + aab + ccc";
    //string SopT = "a";
    string SopT = "a + b' + c";
    cout << SoPValidation1(SopT) << endl;
    SoPCleanUp(SopT);
}