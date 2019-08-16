#pragma once
#ifndef BRAIN
#define BRAIN
#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <istream>
#include "Screen.h"
using namespace std;

class brain {
public:
	double brainRand() {
		double n = (double)rand() / RAND_MAX;
		return 0 + n * (1 - 0);
	}

	double sigmoid(double x) {
		return 1 / (1 + exp(-x));
	}

	double sigmoidDerivative(double x) {
		return 1 * (1 - x);
	}
	
	/* Dot product method */
	double dot(double a[], double b[]) {
		double product = 0;
		for (int i = 0; i < 4; i++) {
			product = product + a[i] * b[i];
		}
		return product;
	}

	/*Sets the synaptic weights to random numbers*/
	void setSynapticWeights() {
		for (int i = 0; i < 4; i++) {
			double n = 0;
			n = brainRand();
			synapticWeights[i] = n;
		}
	}

	void printSynapticWeights() {
		for (int i = 0; i < 4; i++) {

			cout << synapticWeights[i] << endl;
		}
	}

	/*Gets single double from array*/
	double getSynapticWeight(int i) {
		return synapticWeights[i];
	};

	/*Returns the entire synaptic weights array*/
	double* getSynapticWeights() {
		return synapticWeights;
	}

	/*Returns a signle neural output*/
	double getNeuralOutput(int i) {
		return neuralOutputs[i];
	};

	void training(double inputs[][4], double outputs[]) {

		for (int i = 0; i < TRAINING_CYCLES; i++) {

			double inputLayer[4][4];

			//copy into new container
			for (int j = 0; j < 4; j++) {
				for (int k = 0; k < 4; k++) {
					inputLayer[j][k] = inputs[j][k];
				}
			}

			for (int j = 0; j < 4; j++) {
				neuralOutputs[j] = sigmoid(dot(inputLayer[j], synapticWeights));

			}

			double error[4];

			for (int j = 0; j < 4; j++) {
				error[j] = outputs[j] - neuralOutputs[j];
			}

			double adjustments[4];

			for (int j = 0; j < 4; j++) {
				adjustments[j] = error[j] * sigmoidDerivative(neuralOutputs[j]);
			}

			for (int j = 0; j < 4; j++) {
				synapticWeights[j] += dot(inputLayer[j], adjustments);
			}
		}
	}

	double think(double Screen[]) {
		return sigmoid(dot(Screen, synapticWeights));
	}

private:

	double v1 = rand() % 1;
	double synapticWeights[4];
	double neuralOutputs[4];
	const double TRAINING_CYCLES = 20000;
};

#endif // !BRAIN