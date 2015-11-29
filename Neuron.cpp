#include "Neuron.h"
#include "Layer.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

Neuron::Neuron():buffer(0.0),sigma(0.0),delta(0.8){
	
}

void Neuron::setWeightSize(int n){
	mWeights.resize(n);
	for(int i=0;i<n;i++){
		mWeights[i]=(double)rand()/(double)RAND_MAX;
	}
}

void Neuron::print(){
	printf("[%lf ",buffer);
	printf("weight(");
	for(int i=0;i<mWeights.size();i++)
		printf("%lf ",mWeights[i]);
	printf(")sigma(%lf)]",sigma);
}

void Neuron::setJoint(Layer* layer){
	for(int i=0;i<mWeights.size();i++)
		mJoints.push_back(layer->getNeuron(i));
}

void Neuron::input(double v){
	buffer+=v;
}

double Neuron::ignition(int n){
	return mWeights[n]*sigmoid();
}

double Neuron::backPropagation(){
	if((int)sigma==0)
		for(int i=0;i<mJoints.size();i++)
			sigma+=mJoints[i]->getSigma()*mWeights[i];
	return sigma*sigmoid()*(1-sigmoid());
}

void Neuron::modify(double error,int i){
	mWeights[i]+=-sigmoid()*error*delta;
}

double Neuron::getSigma(){
	return sigma;
}

double Neuron::sigmoid(){
	return 1/(1+exp(buffer));
}

void Neuron::setError(double error){
	sigma=buffer-error;
}

void Neuron::reset(){
	buffer=0;
	sigma=0;
}

Neuron::~Neuron(){
	
}