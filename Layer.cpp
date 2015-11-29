#include "Layer.h"
#include <stdio.h>

Layer::Layer():next(NULL),prev(NULL){

}

void Layer::setNeuron(int num){
	mNeurons.resize(num);
	for(int i=0;i<num;i++){
		mNeurons[i]=new Neuron();
	}
}

void Layer::setNextLayer(Layer* next){
	this->next=next;
	next->setPrevLayer(this);
	setNeuronWeight(next->getSize());
	for(int i=0;i<mNeurons.size();i++){
		mNeurons[i]->setJoint(next);
	}
}

void Layer::setNeuronWeight(int n){
	for(int i=0;i<mNeurons.size();i++){
		mNeurons[i]->setWeightSize(n);
	}
}

int Layer::getSize(){
	return mNeurons.size();
}

void Layer::setPrevLayer(Layer* prev){
	this->prev=prev;
}

void Layer::flush(){
	if(next==NULL)
		return;
	for(int j=0;j<mNeurons.size();j++){
		for(int i=0;i<next->getSize();i++){
			next->getNeuron(i)->input(mNeurons[j]->ignition(i));
		}
	}
	next->flush();
}

Neuron* Layer::getNeuron(int n){
	return mNeurons[n];
}

void Layer::print(){
	printf("Layer\n");
	for(int i=0;i<mNeurons.size();i++){
		mNeurons[i]->print();
		printf(" ");
	}
	printf("\n");
}

void Layer::backPropagation(){
	if(prev==NULL)
		return;
	for(int i=0;i<prev->getSize();i++)
		for(int j=0;j<mNeurons.size();j++)
			prev->getNeuron(i)->modify(mNeurons[j]->backPropagation(),j);
	prev->backPropagation();
}

void Layer::reset(){
	for(int i=0;i<mNeurons.size();i++){
		mNeurons[i]->reset();
	}
	if(next!=NULL)
		next->reset();
}

Layer::~Layer(){
	for(int i=0;i<mNeurons.size();i++)
		delete mNeurons[i];
}