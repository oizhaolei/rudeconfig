
#include <rude/config.h>

#include <iostream>
#include <string>

using namespace std;
using namespace rude;

int main(void)
{
	char delimiter;
	char commentchar;

	string inputfile = "convert-messy.conf";
	string outputfile = "convert-clean.conf";

	
	cout << "Enter delimiter:(enter 0 for none)";
	cin >> delimiter;

	cout << "Enter Comment Character:(enter 0 for none)";
	cin >> commentchar;

	if(delimiter == '0')
	{
		delimiter = 0;
	} 

	if(commentchar == '0')
	{
		commentchar = 0;
	}
	
	Config config;

	if(config.load(inputfile.c_str()))
	{
		config.setCommentCharacter(commentchar);
		config.setDelimiter(delimiter);
		if(config.save(outputfile.c_str()))
		{
			cout << "Transformation Successful\n";
			return 0;
		}
		else
		{
			cout << "Error opening '" << outputfile << "' for writing\n";
			return 1;
		}
	}
	else
	{
		cout << "Error opening '" << inputfile << "' for reading\n";
		return 1;
	}

	




	return 0;
}



























