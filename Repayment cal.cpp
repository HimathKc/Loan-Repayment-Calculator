#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
int main()
{
	double pa,air,mir,pp,rb,tip,tm,ip;
	string lt; 
	int sf; 
	tip=0.0;
	
	cout<<"Enter principal loan amount:";
	cin>>pa;
	cout<<"Enter your total Number of Monthly Payments:";
	cin>>tm;
	cout<<"Enter your annual intrest rate:";
	cin>>air;
	
	mir=(air/100)/12;
	pp= pa/tm;
	rb=pa;
	
	cout<<"_____Repayment Schedule_____"<<endl;
cout << setw(8) << left << "Month"  << setw(15) << right << "Interest" << setw(15) << right << "Principal" << setw(15) << right << "Total"<< setw(15) << right << "Remaining" << endl;

cout<<"_____________________________________________________________________" << endl;

	for(int m=1;m<=tm;m++)
	{
		ip=rb*mir;
	    double tmp=pp+ip;
		rb=rb-pp;
		tip=tip+ip;
		
	cout << setw(8) << left << m << setw(15) << right << ip<< setw(15) << right << pp<< setw(15) << right << tmp<< setw(15) << right << rb << endl;
		}
	cout<<"\n_____Final Loan Summary_____"<<endl;
	
	if(pa<50000)
	{
	 lt="Micro Loan";
	 sf=100;
	}
	else if(pa>=50000 && pa<=1000000)
	{
		lt="Standard Loan";
		sf=500;
	}
	else
	{
		lt="Premium Loan";
		sf=1000;
	}
	double tamountp=pa+tip+sf;
	
	cout<<"Loan Classification:"<<lt<<endl;
    cout<<"Mandatory Service Fee: RS"<<sf<<endl;
	cout<<"Total Intrest Paid: RS"<<tip<<endl;
	cout<<"Total A mout Needed to settle the loan: RS"<<tamountp<<endl;
} 
