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
	if(argc > 0) {
		algorithm = argv[1];
	}
		
	//solve problem
	cerr << "using algorithm " << algorithm << endl;
	if(algorithm == "naive") {
		run(input);
	}
	else {
		cerr << "unknown algorithm" << endl;
		return 1;
	}
	
	//print output
	cout << input.answerColumn.size() << endl;
	for(int i = 0; i < input.answerColumn.size(); i++) {
		cout << input.answerRow[i].first << ' ';
		cout << input.answerColumn[i].first << ' ';
		cout << input.answerRow[i].second << ' ';
		cout << input.answerColumn[i].second << '\n';
	}
};
