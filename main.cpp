#include <iostream>
#include <stdlib.h>
using namespace std;

int main () {

	int uniqueOrderNumbers, currentOrderNumber, trips;

	// This will hold information about which numbers have been ordered
	int data [98];

	// Get from the user the number of simulations to run
	cout << "Welcome to the (unofficial) In-n-Out Challenge calculator!";
	cout << endl;
	cout << "How many simulations of the challenge would you like to run? ";
	int n;
	cin >> n;

	int total = 0;
	int min = 10000;
	int max = 0;

	// Run n simulations
	for (int i = 0; i < n; i++) {

		trips = 0;
		uniqueOrderNumbers = 0;

		// Reset the data array at the beginning of each simulation
		for (int a = 0; a < 98; a++) {
			data[a] = 0;
		}

		// Continue simulating trips to In-n-Out until all 98 unique
		// order numbers have been acquired
		while (uniqueOrderNumbers < 98) {
			currentOrderNumber = rand() % 98;
			if (data[currentOrderNumber] != 1) {
				uniqueOrderNumbers++;
				data[currentOrderNumber] = 1;
			}
			trips++;
		}

		total += trips;
		if (trips > max)
			max = trips;
		if (trips < min)
			min = trips;

		cout << "Simulation " << (i + 1) << " took " << trips << " trips";
		cout << endl;
	}

	cout << "It took an average of " << (total / n)
			<< " trips to complete the challenge." << endl;
	cout << "The maximum number of trips it took was " << max << ".";
	cout << endl;
	cout << "The minimum number of trips it took was " << min << ".";
	cout << endl;
}
