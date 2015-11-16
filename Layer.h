#include <vector>

using namespace std;

class Layer{
public:
	Layer();
	~Layer();
	void setNeuron(int );
private:
	vector<Neuron*> neurons;
};