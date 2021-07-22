/*
The idea is to use greedy approach, where we should start buying product from the day when the stock price is least and so on.

sort the pair of two values i.e { stock price, day } according to the stock price, and if stock prices are same, 
then we sort according to the day.

n=size of prize array
TC = O(nlogn) sorting
SC = O(2*n)

*/

#include<iostream>
#include<algorithm>  //to use sort()
   
using namespace std;

// A structure to represent a day wise share prices
struct Stock
{
   int day;   
   int price_that_day;    
};

// Customized sort() third agrument.
bool cmp(Stock a,Stock b)
{
	//sort the pair of two values i.e { stock price, day } according to the stock price in increasing order
	if(a.price_that_day != b.price_that_day)
	{
		return(a.price_that_day < b.price_that_day);
	}
	//if stock prices are same,then we sort according to the day.
	else if(a.price_that_day == b.price_that_day)
	{
		return(a.day < b.day);
	}
}

//to give number of stocks to purchase
int Decision(int i,struct Stock arr[],int money)
{
	int decision=0,money_remaining=money;
	
	//check if max purchase is possible
	if((arr[i].price_that_day*arr[i].day)<money_remaining)
	{
		decision=arr[i].day;
	}
	//agar max purchase possible ni to dekho kitne kharid sakte 
	else
	{
		decision=(money_remaining/arr[i].price_that_day);
	}
	
	return decision;
}

int No_of_Purchases(struct Stock arr[],int money,int n)
{
	int count=0,decision=0,money_remaining=money,purchased=0;
	
	//sort the prices daywisein increasing order
	sort(arr,arr+n,cmp);
	
	/*
	//test sort()
	cout<<"\n";
	for(int i=0;i<n;i++)
	{
		cout<<"\n"<<arr[i].price_that_day;
	}
	*/
	
	//tab tak purchase karo jab tak jeb khaali na ho
	int i=0;
	while(money_remaining>0 && i<n)
	{
		//decide kitne lene hai stock
		decision=Decision(i,arr,money);
		
		//count store karo ki kitne stock kharide
		count=count+decision;
		
		//purchase karo
		purchased=(arr[i].price_that_day*decision);
		money_remaining=money_remaining-purchased;
		purchased=0;
		i++;	
	}
	
	return count;
}

int main()
{
	//Static inputs
	int n=3;
	struct Stock arr[n]={
							{1,10},
							{2,7 },
							{3,19}
						};
						
	int money=45;
	
	cout<<"\n\nMinimum number of stocks bought => "<<No_of_Purchases(arr,money,n);
	
	return 0;
}
