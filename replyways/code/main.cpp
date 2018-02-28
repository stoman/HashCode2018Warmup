#include "util.cpp"
#include "part1.cpp"
#include "part2.cpp"

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
	if(algorithm == "naive") {
		astar(input);
	}
	else {
		cerr << "unknown algorithm" << endl;
		return 1;
	}
	
	//print output
	if(input.path.size() == 0) {
		cout << "IMPOSSIBLE" << endl;
	}
	else {
		cout << input.path.size() << endl;
		for(int i = input.path.size() - 1; i >= 0; i--) {
			cout << input.path[i].first << ' ' << input.path[i].second << endl;
		}
	}
};
