#include <iostream>	//cout
#include <sstream>	//ifstream
#include <fstream>	//ifstream
#include <string>	//string
#include <vector> 	//vector

//C++ namespace
using namespace std;


int main(int argc, char* argv[])
{
	// open it with a file other wise close it
	if (argc != 2) {
        cout << "ERROR: Wrong amount of arguments!" << endl;
        cout << "\n" << "Programm closed...\n\n" << endl;
        exit(1);

        return 0;
    }
	
	//open file
	ifstream myfile(argv[1]);

	//check if file is open
	if (myfile.is_open())
	{
		//create outputfile
		string outFileName = argv[1];
		outFileName = outFileName.substr(0, outFileName.size()-4);
		outFileName.append("_deltaImport");
		ofstream outFile(outFileName.append(".csv"));
		//write first line		
		outFile << "Date" << ',' << "Type" << ',' << "Exchange" << ',' << "Base amount" << ',' << "Base currency" << ',' << "Quote amount" << ',' << "Quote currency" << ',' << "Fee" << ','<< "Fee currency" << ',' << "Costs/Proceeds" << ',' << "Costs/Proceeds currency" << ',' << "Sync holdings" << ',' << "Sent/Received from" << ',' << "Sent to" << ',' << "Notes" << endl;

		//read and ignore first line
		string line;
		getline(myfile, line);
		//search line by line
		while (getline(myfile, line))
		{
			// put it in a stringstream (internal stream)
			stringstream sline( line );
			vector<string> data;
			string tmpString;
			int counter=0;
			//store line in vector with "," as seperator
			while(getline(sline, tmpString, ','))
			{
				data.push_back(tmpString);
			}
			//parse tradeing pair
			switch(data[1].back())
			{
				case 'C':
					data.push_back("BTC");	
					data[1] = data[1].substr(0, data[1].size()-data[8].size());
					break;
				case 'H':
					data.push_back("ETH");
					data[1] = data[1].substr(0, data[1].size()-data[8].size());
					break;
				case 'B':
					data.push_back("BNB");
					data[1] = data[1].substr(0, data[1].size()-data[8].size());
					break;
				case 'T':
					data.push_back("USDT");
					data[1] = data[1].substr(0, data[1].size()-data[8].size());
					break;
				default:
					data.push_back(" ");
			}
			//write parsed line in the format of Delta.IO
			outFile << data[0] << ',' << data[2] << ',' << "Binance" << ',' << data[4] << ',' << data[1] << ',' << data[5] << ',' << data[8] << ',' << data[6] << ','<< data[7] << ',' << ',' << ',' << '1' << ',' << ',' << ',' << "myTool" << endl;
		}
		//close file
		outFile.close();		
	}
	else
	{
		//just in case the file does not exist
		cout << "Unable to open file";
	}
	return 0;
}
