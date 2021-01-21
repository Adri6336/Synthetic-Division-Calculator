#include <iostream>
#include <vector>
#include <algorithm>
#include <Windows.h>
using namespace std;

// Funct. Proto.
void calcIt(vector<int> drop, vector<int> product, int divBy, int sizeFX, vector<int> fOfX, int highDeg, int remainder);



int main()
{
	// Console
	system("color 1f");



	// Principal Variables =========================================
	int highDeg; // Following values will be highDeg - 1
	int divBy = 0; // divBy = X
	int remainder = -401; // this is = drop.at(size-1)
	int temp;
	int sizeFX;
	int tempMid, tempProd, tempDrop;
	int newHD;

	vector<int> fOfX;
	vector<int> drop;
	vector<int> product;


	// Prompt =========================================
	cout << "What is the highest degree?\n";
	cout << "Highest Degree: ";
	cin >> highDeg;
	cout << endl << endl;
	highDeg += 1;

	

	// Get full function filled =========================================
	for (int i = 0; i < highDeg; i++)
	{

		if (i > 0)
			cout << "What is the value for X^" << i << "?\n  >>> ";
		else if (i == 0)
			cout << "What is the value of the constant term?\n  >>> ";

		cin >> temp;
		fOfX.push_back(temp);
		cout << endl;


	}

	sizeFX = fOfX.size();
	product.push_back(0);
	reverse(fOfX.begin(), fOfX.end()); // This reverses the values with the vector so that the end becomes the beginning and vice versa

	// Calculations =========================================
	
	calcIt(drop, product, divBy, sizeFX, fOfX, highDeg, remainder); // This is the calculating function

	

	// Try again or quit?? ====================================
	bool quit = false;

	while (quit == false)
	{
		cout << "\n\n------------------\nDo you want to quit (1) or try a different divBy(0)?\n  >>> ";
		cin >> quit;

		if (quit == true)
			continue;
		calcIt(drop, product, divBy, sizeFX, fOfX, highDeg, remainder);


	}

	bool quit2 = false;
	cout << "Would you like to try another function(y = 0, n = 1)?\n  >>> ";
	cin >> quit2;
	if (quit2 == false)
	{
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		main();

	}

	//END =========================================
	return 0;
}



void calcIt(vector<int> drop, vector<int> product, int divBy, int sizeFX, vector<int> fOfX, int highDeg, int remainder)
{

	cout << "\n===============\nWhat is the X you want to divide by?\nX = ";
	cin >> divBy;
	cout << "\n\n";


	int tempDrop, newHD, tempProd;

	for (int h = 0; h < sizeFX; h++)
	{
		tempDrop = fOfX.at(h) + product.at(h); // drop at h
		drop.push_back(tempDrop);


		tempProd = drop.at(h) * divBy; // product at h + 1
		product.push_back(tempProd);

	}

	remainder = drop.at(sizeFX - 1);
	newHD = highDeg - 1;

	// Display =========================================
	int countX = sizeFX - 2;
	cout << "=========================================\n";
	cout << "New function: ";

	cout << "\n\n";
	cout << "Remainder: " << remainder;
	cout << "\n\n";

	for (int o = 0; o < sizeFX - 1; o++)
	{
		if (countX > 0)
			cout << "X^" << countX << ": ";
		else if (countX == 0)
			cout << " CT: ";

		cout << drop.at(o) << endl;  // 2\n, 3\n, -2\n == output
		countX--;
	}

}