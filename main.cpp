#include "Layer.h"
#include <stdio.h>

int main(int argc,char** argv){
	Layer l,m,n,o,p;
	l.setNeuron(2);
	m.setNeuron(10);
	n.setNeuron(5);
	o.setNeuron(1);
	l.setNextLayer(&m);
	m.setNextLayer(&n);
	n.setNextLayer(&o);
	for(int t=0;t<100000;t++){
		l.reset();
		l.getNeuron(0)->input(1);
		l.getNeuron(1)->input(1);
		l.flush();

		o.getNeuron(0)->setError(1);

		o.backPropagation();
		l.reset();

		l.getNeuron(0)->input(0);
		l.getNeuron(1)->input(0);

		l.flush();
	
		o.getNeuron(0)->setError(0);
	
		o.backPropagation();
	}
	l.reset();
	l.getNeuron(0)->input(1);
	l.getNeuron(1)->input(1);
	l.flush();
	l.print();
	m.print();
	n.print();
	o.print();
	printf("~~~~~~~~~~~~~\n");
	l.reset();

	l.getNeuron(0)->input(0);
	l.getNeuron(1)->input(0);
	
	l.flush();
	l.print();
	m.print();
	n.print();
	o.print();
}