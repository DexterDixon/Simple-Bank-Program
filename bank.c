
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
# define MAXCREDIT 4500

void Greeting();
void BankMenu(int *choice);
void AccountBalance(double account, char letter);
void TransactionDecision(int num, double *cPtr, double *sPtr, double *xPtr);
void DepositMoney(double *accountPtr);
void WithdrawMoney(double *accountPtr, char letter);

int main(void)
{
	int selection = 0;
	double checkings = 256.00;
	double savings = 1024.00;
	double credit = -2048.00;

	Greeting(); //greets the user
	AccountBalance(checkings, 'C'); //displays the	current	balance	of	the	account	
	AccountBalance(savings, 'S'); //displays	the	current	balance	of	the	account	
	AccountBalance(credit, 'X'); //displays	the	current	balance	of	the	account	
	
	for (int i = 0; i != -1; i = selection) // For loop for Bank Menu selections
	{
		BankMenu(&selection); //Displays the list of options available 
		TransactionDecision(selection, &checkings, &savings, &credit);
		//Makes	the	decision	of	which	transaction	should	be	done
	}
	return (0);
}

void Greeting()
{
	printf("*******************************\n\n");
	printf("Welcome to the Bank\n\n");
	printf("It is a pleasure to manage your checking, savings, and credit accounts\n\n");

}

void BankMenu(int *choice)
{
	printf("------------------------\n\n");
	printf("(1) to DEPOSIT to CHECKING\n");
	printf("(2) to WITHDRAW from CHECKING\n");
	printf("(3) to DEPOSIT to SAVINGS\n");
	printf("(4) to WITHDRAW from SAVINGS\n");
	printf("(5) to DEPOSIT to CREDIT\n");
	printf("(6) to TAKE an ADVANCE from CREDIT\n");
	printf("(7) to Check all acount balances\n");
 	printf("(-1) QUITE\n\n");
	printf("Select and option: ");
	scanf("%d", &*choice);
	printf("The selection you choose was %d\n", *choice);
}

void AccountBalance(double account, char letter)
{
	if (letter == 'C')
		printf("You currently have $%.2f in your checking account\n", account);
	
	if (letter == 'S')
		printf("You currently have $%.2f in your savings account\n", account);
	
	if (letter == 'X')
		printf("You currently have $%.2f credit balance\n\n", account);


}

void TransactionDecision(int num, double *cPtr, double *sPtr, double *xPtr)
{
	if (num == 1)
	{
		AccountBalance(*cPtr, 'C');
		DepositMoney(cPtr);
		AccountBalance(*cPtr, 'C');
	}
	
	if (num == 2)
	{
		AccountBalance(*cPtr, 'C');
		WithdrawMoney(cPtr, 'C');
		AccountBalance(*cPtr, 'C');
	}
	
	if (num == 3)
	{
		AccountBalance(*sPtr, 'S');
		DepositMoney(sPtr);
		AccountBalance(*sPtr, 'S');
	}
	
	if (num == 4)
	{
		AccountBalance(*sPtr, 'S');
		WithdrawMoney(sPtr, 'S');
		AccountBalance(*sPtr, 'S');
	}
	
	if (num == 5)
	{
		AccountBalance(*xPtr, 'X');
		DepositMoney(xPtr);
		AccountBalance(*xPtr, 'X');
	}
	
	if (num == 6)
	{
		AccountBalance(*xPtr, 'X');
		WithdrawMoney(xPtr, 'X');
		AccountBalance(*xPtr, 'X');
	}
	if (num == 7)
	{
		AccountBalance(*cPtr, 'C');
		AccountBalance(*sPtr, 'S');
		AccountBalance(*xPtr, 'X');
	}
}

void DepositMoney(double *accountPtr)
{
	double depositeamount = 0;
	printf("Enter the amount you would like to deposite into this acount:");
	scanf("%lf", &depositeamount);
	*accountPtr = *accountPtr + depositeamount;
}

void WithdrawMoney(double *accountPtr, char letter){	double withdrawamount = 0;
	if (letter == 'C' || letter == 'S')
	{
		printf("Enter the amount you would like to withdraw from this acount:");
		scanf("%lf", &withdrawamount);
		printf("\n\n$%.2f Will be withdrawn from this account\n\n");
		*accountPtr = *accountPtr - withdrawamount;		if (*accountPtr - withdrawamount < 0)		{			printf("\n*** You do not have sufficient funds to make this transactoin\n");		}	}	if (letter == 'X')
	{
		printf("Enter the amount you would like to withdraw from this acount:");
		scanf("%lf", &withdrawamount);
		if (*accountPtr - withdrawamount < -MAXCREDIT)		{			printf("\n*** There is not enough credit available for this transaction\n");			printf("*** The Maximum credit allowed is $ -4500.00\n");			printf("*** Contact customer service about raising your Credit Line\n");		}		if (*accountPtr - withdrawamount > -MAXCREDIT)			*accountPtr = *accountPtr - withdrawamount;	}}