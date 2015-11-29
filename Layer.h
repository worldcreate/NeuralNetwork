#ifndef _LAYER_H_
#define _LAYER_H_

#include "Neuron.h"
#include <vector>

using namespace std;

class Layer{
public:
	Layer();
	~Layer();
	void setNeuron(int );
	void setNextLayer(Layer*);
	void setPrevLayer(Layer*);
	void setNeuronWeight(int);
	void print();
	int getSize();
	void flush();
	void backPropagation();
	void reset();
	Neuron* getNeuron(int);
private:
	vector<Neuron*> mNeurons;
	Layer* next;
	Layer* prev;
};

#endif