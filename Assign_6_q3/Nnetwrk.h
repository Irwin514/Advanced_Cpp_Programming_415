Const int N_MAX = 50;

void calculate_outputs(layer &Layer, Layer &layer_p);

class Layer
{	public:
	int N_node; 
	double Output[N_MAX]; 
	double w[N_MAX][N_MAX]; 
	Layer(int n_node);
};

