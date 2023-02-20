#include <iostream>
#include <math.h>
using namespace std;

struct average
{
	float x2;
	float y2;
};

float ED(float x1, float x2, float y1, float y2)
{
	float x, y, dist, ed;
	x = x2 - x1;
	y = y2 - y1;
	dist = pow(x, 2) + pow(y, 2);
	ed = sqrt(dist);
	return ed;
}

int index_sort(float arr[], float order[], int x)
{
	int pos = 0;
	for (int i = 0; i < x; i++)
	{
		int temp = 1000;
		for (int j = 0; j < x; j++)
		{
			if (arr[j] != -1 && temp > arr[j])
			{
				temp = arr[j];
				pos = j;
			}
		}
		order[i] = pos;
		arr[pos] = -1;
		cout << order[i] << " ";
		return order[i];
	}
}

void check(int order[], int label[], int k)
{
	int batsman = 0, bowler = 0, allrounder = 0;
	for (int index = 0; index < k; index++)
	{
		if (label[order[index]] == 0)
		{
			batsman++;
		}
		else if (label[order[index]] == 1)
		{
			bowler++;
		}
		else if (label[order[index]] == 2)
		{
			allrounder++;
		}
	}

	if (batsman > bowler && batsman > allrounder)
	{
		cout << "\tNew Player is Batsman" << endl;
	}
	else if (bowler > batsman && bowler > allrounder)
	{
		cout << "\tNew Player is Bowler" << endl;
	}
	else if (allrounder > bowler && allrounder > batsman)
	{
		cout << "\tNew Player is All-rounder" << endl;
	}
	cout << endl << endl;
}

void setup()
{

	system("color 3");
	int a;
	cout << "\n\t\t\t\t\t\tWelcome to PT K-Nearest Neighbors Project " << endl;
	cout << "\n\n\n\n\n\tFALL-2020 BSCS" << endl << "\tSECTION B" << endl << "\tGroup 2" << endl << endl << "\tGroup Members: " << endl << endl << "\tMuhammad Abdur-Rehman-022" << endl << "\tMuhammad Ammar Zaid-014" << endl << "\tMohammad Ali-052" << endl;
	cout << "\n\n\n\n\tPress 1 to Start Program: ";
	cin >> a;
	cout << endl << endl << endl;

	system("cls");

}

int main()
{
	setup();

	float x1, x2 = 0, y1, y2 = 0;
	average arr[15];
	int label[15] = { 0, 1, 0, 1, 1, 2, 2, 2, 1, 2, 0, 2, 0, 1, 1 };
	float newuser[15];
	int batavg[15] = { 50, 45, 48, 62, 48 ,15, 12, 12, 5, 6, 35, 34, 55, 26, 31 };
	int bowlavg[15] = { 50, 50, 58, 65, 43 ,21, 20, 15, 12, 23, 29, 26, 29, 41, 28 };


	cout << "\n\n\n\tNew Player Batting Average: ";
	cin >> x1;
	cout << endl << endl;
	cout << "\n\tNew Player Bowling Average: ";
	cin >> y1;
	cout << endl << endl;
	cout << "\n\t----------------------------------------------------------" << endl << endl;


	cout << "\t\t\tEuclidean Distance " << endl << endl << endl;
	for (int i = 0; i < 15; i++)
	{
		arr[i].x2 = batavg[i];
		arr[i].y2 = bowlavg[i];
		newuser[i] = ED(x1, arr[i].x2, y1, arr[i].y2);
		cout << "\tEuclidean Distance form Points: " << "(" << x1 << "," << y1 << ") " << "(" << arr[i].x2 << "," << arr[i].y2 << ") : " << newuser[i] << endl;
	}
	cout << endl;
	cout << "\t----------------------------------------------------------" << endl << endl;


	cout << "\tEuclidean Distance at Euclidean Distance Array Index " << endl << endl << endl;
	for (int i = 0; i < 15; i++)
	{
		if (newuser[i] < 10000)
		{
			cout << "\tAt index " << i << " The Distance is: " << newuser[i] << endl;
		}
	}
	cout << endl;
	cout << "\t----------------------------------------------------------" << endl << endl;


	cout << "\t\tLabel at Label Array Index " << endl << endl << endl;
	cout << "\t0=Batsman" << endl << "\t1=Bowler" << endl << "\t2=All-rounder" << endl << endl;
	for (int i = 0; i < 15; i++)
	{
		if (label[i] < 10000)
		{
			cout << "\tAt index " << i << " The Label is: " << label[i] << endl;
		}
	}
	cout << endl;
	cout << "\t----------------------------------------------------------" << endl << endl;


	int k;
	int order[15];
	float copy[15];
	cout << "\tSorting an Euclidean Distance Array Index in Ascending Order: " << endl << endl;
	cout << endl;
	cout << "\t";
	for (int index = 0; index < 15; index++)
	{

		order[index] = index_sort(newuser, copy, 15);

	}
	cout << endl << endl;
	cout << "\t----------------------------------------------------------" << endl << endl;
	cout << "\tEnter the K Number to Check Whether New Player is Batsman, Bowler or All-rounder: ";
	cin >> k;
	cout << endl << endl;
	check(order, label, k);
	cout << "\tEnter the K Number Again to Check Whether New Player is Batsman, Bowler or All-rounder: ";
	cin >> k;
	cout << endl << endl;
	check(order, label, k);
	cout << "\tEnter the K Number Again to Check Whether New Player is Batsman, Bowler or All-rounder: ";
	cin >> k;
	cout << endl << endl;
	check(order, label, k);

}