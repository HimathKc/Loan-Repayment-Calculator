#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    double principalAmount, annualInterestRate, monthlyInterestRate;
    double principalPayment, remainingBalance, totalInterestPaid = 0.0;
    double interestPayment, totalMonthlyPayment;
    int totalMonths;
    string loanType;
    int serviceFee;

    cout << "Enter principal loan amount: ";
    cin >> principalAmount;

    cout << "Enter your total number of monthly payments: ";
    cin >> totalMonths;

    cout << "Enter your annual interest rate: ";
    cin >> annualInterestRate;

    monthlyInterestRate = (annualInterestRate / 100) / 12;
    principalPayment = principalAmount / totalMonths;
    remainingBalance = principalAmount;

    cout << fixed << setprecision(2);

    cout << endl;
    cout << "_____ Repayment Schedule _____" << endl;

    cout << setw(8) << left << "Month"
         << setw(15) << right << "Interest"
         << setw(15) << right << "Principal"
         << setw(15) << right << "Total"
         << setw(15) << right << "Remaining" << endl;

    cout << "_____________________________________________________________________" << endl;

    for (int month = 1; month <= totalMonths; month++)
    {
        interestPayment = remainingBalance * monthlyInterestRate;
        totalMonthlyPayment = principalPayment + interestPayment;
        remainingBalance = remainingBalance - principalPayment;

        if (remainingBalance < 0.01 && remainingBalance > -0.01)
        {
            remainingBalance = 0;
        }

        totalInterestPaid = totalInterestPaid + interestPayment;

        cout << setw(8) << left << month
             << setw(15) << right << interestPayment
             << setw(15) << right << principalPayment
             << setw(15) << right << totalMonthlyPayment
             << setw(15) << right << remainingBalance << endl;
    }

    cout << endl;
    cout << "_____ Final Loan Summary _____" << endl;

    if (principalAmount < 50000)
    {
        loanType = "Micro Loan";
        serviceFee = 100;
    }
    else if (principalAmount >= 50000 && principalAmount <= 1000000)
    {
        loanType = "Standard Loan";
        serviceFee = 500;
    }
    else
    {
        loanType = "Premium Loan";
        serviceFee = 1000;
    }

    double totalAmountNeeded = principalAmount + totalInterestPaid + serviceFee;

    cout << "Loan Classification: " << loanType << endl;
    cout << "Mandatory Service Fee: RS " << serviceFee << endl;
    cout << "Total Interest Paid: RS " << totalInterestPaid << endl;
    cout << "Total Amount Needed to Settle the Loan: RS " << totalAmountNeeded << endl;

    return 0;
}
