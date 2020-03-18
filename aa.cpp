#include <fstream>
#include <iostream>
using namespace std;
const int cutoff = 6000;
const float rate1 = 0.3;
const float rate2 = 0.6;
int main()
{
    ifstream infile;
    ofstream outfile;
    int income, tax;
    infile.open("income.in");
    outfile.open("tax.out");
    if(!infile)
    {
        cerr << "income.in文件打开失败";
        
        exit(0);
    }
    if(!outfile)
    {
        cerr << "tax.out文件打开失败";
        exit(0);
    }
    while (infile >> income)
    {
        if (income < cutoff)
            tax = rate1 * income;
        else
            tax = rate2 * income;
        outfile << "Income = " << income << " greenbacks\n"
                << "Tax = " << tax << " greenbacks\n";
    }
    infile.close();
    outfile.close();
    return 0;
}