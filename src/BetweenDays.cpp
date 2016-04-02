/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};

int leaps(int date[])
{
	if (date[1] <= 2)
		date[2]--;
	return((date[2] / 4) - (date[2] / 100) + (date[2] / 400));
}

int between_days(struct node *date1head, struct node *date2head){
	int mon[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int i, date1[3] = { 0 }, date2[3] = { 0 },v1=0,v2=0,flag=0,days1=0,days2=0;
	struct node *temp1=date1head, *temp2=date2head;
	if (date1head==NULL||date2head==NULL)
		return -1;
	for (i = 0; i < 8 && temp1; i++)
	{
		date1[flag] *= 10;
		date1[flag] += temp1->data;
		temp1 = temp1->next;
		if (i == 1 || i == 3)
			flag++;
	}
	flag = 0;
	for (i = 0; i < 8 && temp2; i++)
	{
		date2[flag] *= 10;
		date2[flag] += temp2->data;
		temp2 = temp2->next;
		if (i == 1 || i == 3)
			flag++;
	}
	days1 += date1[2] * 365 + date1[0];
	for (i = 0; i < date1[1] - 1; i++)
		days1 += mon[i];
	days1 += leaps(date1);
	days2 += date2[2] * 365 + date2[0];
	for (i = 0; i < date2[1] - 1; i++)
		days2 += mon[i];
	days2 += leaps(date2);
	return abs(days2 - days1)-1;
}