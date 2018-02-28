#include "util.cpp"
#include "part1.cpp"
#include "part2.cpp"
#include "part3.cpp"

//input/output code
int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	srand(time(NULL));

	//read input
	Input input;
	readInput(input, cin);

	//read command line args
	string algorithm = "";
	if(argc > 1) {
		algorithm = argv[1];
	}
		
	//solve problem
	cerr << "using algorithm " << algorithm << endl;
	if(algorithm == "grid50") {
		input.gridsize = 50;
		astar(input);
	}
	else if(algorithm == "grid100") {
		input.gridsize = 100;
		astar(input);
	}
	else if(algorithm == "grid500") {
		input.gridsize = 500;
		astar(input);
	}
	else {
		cerr << "unknown algorithm" << endl;
		return 1;
	}
	
	//print output
	if(input.path.size() <= 1) {
		cout << "IMPOSSIBLE" << endl;
	}
	else {
		cout << input.path.size() << endl;
		for(int i = input.path.size() - 1; i >= 0; i--) {
			cout << input.path[i].first << ' ' << input.path[i].second << endl;
		}
	}
};
