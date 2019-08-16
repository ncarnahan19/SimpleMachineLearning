#include <iostream>
#include <istream>
#include "Screen.h"
#include "Brain.h"
using namespace std;

double dot(double a[], double b[]);

void printScreen(double n[]);

char doubToOutChar(double n);

int TRAINING_CYCLES = 20000;
double neuralOutputs[4];

int main() {

	//Initialization 
	brain Brain;

	double Screen1[4] = { 0,1,1,0 };
	double Screen2[4] = { 1,0,0,1 };
	double Screen3[4] = { 1,0,0,1 };
	double Screen4[4] = { 0,1,1,0 };

	double inputs[4][4] = { {Screen1[0],Screen1[1],Screen1[2],Screen1[3]},
	{Screen2[0],Screen2[1],Screen2[2],Screen2[3]},
	{Screen3[0],Screen3[1],Screen3[2],Screen3[3]},
	{Screen4[0],Screen4[1],Screen4[2],Screen4[3],}
	};

	double outputs[4] = { 0, 1, 1, 0 };

	Brain.setSynapticWeights();

	cout << "Synaptic Weights:\n";
	Brain.printSynapticWeights();

	Brain.training(inputs, outputs);

	cout << "\n\nNeural outputs:\n";
	for (int i = 0; i < 4; i++) {
		cout << Brain.getNeuralOutput(i) << endl;
	}

	cout << "\n\n Translation to char:\n";

	for (int i = 0; i < 4; i++) {

		cout << doubToOutChar(Brain.getNeuralOutput(i)) << endl;
	}


	double Screen5[4] = { 1,0,0,1 };
	cout << "\n\nNew Situation: ";
	printScreen(Screen5);

	double n = Brain.think(Screen5);

	cout << "New situation output:" << doubToOutChar(n);

	char endLoop = ' ';

	std::cin >> endLoop;

	return 0;
} // End of main()



double pixelToDouble(char c) {

	if (c == 'r') {
		return 1;
	}

	return 0;
}

/*
	Translates 4-pixel screens (arrays of 1's and 0's) to back slashes and forward slashes.
*/

char doubArrayToChar(double n[]) {

	for (int i = 0; i < 4; i++) {

		if (n[i] >= 0.7 && i == 1) {
			return '\\';
		}
		else if (n[i] <= 0.35 && i == 1) {
			return '/';
		}
	}
	return 0;
}

/*
	Translates single digits (1's and 0's) to back slashes and forward slashes (0 = \, 1 = /).
*/

char doubToOutChar(double n) {



	if (n >= 0.7) {
		return '\\';
	}
	else if (n <= 0.35) {
		return '/';
	}

	return 0;

}

void printScreen(double n[]) {
	for (int i = 0; i < 4; i++) {

		cout << n[i] << " ";
	}
	cout << endl;
}
