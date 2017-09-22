#import <iostream>
#import <fstream>
#import <sstream>
#import <string>
#import <vector>
using namespace std;

vector<string> getNextLineAndSplitIntoTokens(ifstream& str);
void write_vcf(ofstream& file, vector<string>& contact_info);

int main(void)
{
	cout << "PROGRAM ACCEPTS CSV WITH DATA IN THESE COLUMS, IN ORDER:" << endl;
	cout << "FIRST_NAME | LAST_NAME | CELL | EMAIL | COMPANY/ORGANIZATION" << endl;
	cout << "Please do not provide titles in the csv file." << endl;
	cout << "------------------------------------------------------------" << endl;

	string csvfile_name;
	cout << "enter name of input csv file: ";
	cin >> csvfile_name;

	string vcffile_name;
	cout << "enter name of output vcf file: ";
	cin >> vcffile_name;

	string ext1 = csvfile_name.substr(csvfile_name.size()-4, 4); // ".csv"
	string ext2 = vcffile_name.substr(vcffile_name.size()-4, 4); // ".vcf"

	if (ext1 != ".csv" || ext2 != ".vcf") {
		cout << "Error: you must provide a csv file input and a vcf file output." << endl;
		cout << "Aborting..." << endl;
		return -1;
	}

	ifstream csvfile(csvfile_name);
	ofstream vcffile(vcffile_name);

	if (csvfile.fail() || vcffile.fail()) {
		cout << "Error opening files." << endl;
		cout << "Aborting..." << endl;
		return -2;
	}

	while (!csvfile.eof()) {
		vector<string> contact_info = getNextLineAndSplitIntoTokens(csvfile);
		write_vcf(vcffile, contact_info);
	}


	csvfile.close();
	vcffile.close();
	return 0;
}

vector<string> getNextLineAndSplitIntoTokens(ifstream& str)
{
    vector<string> result;
    string line;
    getline(str,line);

    stringstream lineStream(line);
    string cell;

    while(getline(lineStream,cell, ','))
    {
        result.push_back(cell);
    }
    // This checks for a trailing comma with no data after it.
    if (!lineStream && cell.empty())
    {
        // If there was a trailing comma then add an empty element.
        result.push_back("");
    }
    return result;
}

void write_vcf(ofstream& file, vector<string>& contact_info)
{
	string first = contact_info.at(0);
	string last = contact_info.at(1);
	string cell = contact_info.at(2);
	string email = contact_info.at(3);
	string organization = contact_info.at(4);

	file << "BEGIN:VCARD" << endl
		 <<	"VERSION:3.0" << endl
		 <<	"N;CHARSET=utf-8:" << last << ";" << first << ";;;;" << endl
		 << "FN;CHARSET=utf-8:" << first << " " << last << endl
		 << "ORG:" << organization << endl
		 << "TEL;TYPE=WORK,MOBILE:" << cell << endl
		 << "EMAIL:" << email << endl
		 << "END:VCARD" << endl;

	return;
}