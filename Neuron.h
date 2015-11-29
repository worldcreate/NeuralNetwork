#ifndef _NEURON_H_
#define _NEURON_H_

#include <vector>

using namespace std;

class Layer;

class Neuron{
public:
	Neuron();
	void print();
	void setWeightSize(int n);
	void setJoint(Layer*);
	double ignition(int);
	void input(double);
	double backPropagation();
	double sigmoid();
	void setError(double);
	double getSigma();
	void modify(double,int);
	void reset();
	~Neuron();
private:
	vector<double> mWeights;
	vector<Neuron*> mJoints;
	double buffer;
	double sigma;
	double delta;
};

#endif