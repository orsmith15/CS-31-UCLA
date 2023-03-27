//  cdplayer.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include <cassert>
#include<cmath>
#include <cctype>

using namespace std;
bool isValidCDPlayerString(string cdstring);
bool isOpen(string cdstring);
bool hasCD(string cdstring);
int totalTracksPlayed(string cdstring);
int currentTrack(string cdstring);
string cdstring;

int main() {
	const string green_text = "\033[32m";
	const string blue_text = "\033[34m";
	const string reset_text = "\033[0m";
	const string valid_tests[] = { "OICP123SP456SORICP123",
								  "OIRICP123SOR",
								  "OICP123ORICP123",
								  "OICPO",
								  "OICPOR",
								  "OICP123O",
								  "OICP123SOCP456S",
								  "OICP123P456SOR",
								  "OICPP123SOR",
								  "OICP123SORICP123456SOR",
								  "OICP123OC",
								  "OICP123OCP",
								  "OICP123OCP456",
								  "OC",
								  "OCOIC",
								  "OCOICO",
								  "OICP123OS",
								  "OICP123ORS",
								  "OICP123ORCS",
								  "OICP123ORIS",
								  "OICPS",
								  "OICPSPSPS",
								  "OICP123SP456",
								  "OICP123OCS",
								  "OCOICP1234SOCOCP5678",
								  "OCOCOCOC",
								  "OICP123ORICS",
								  "OICP1P23SOR",
								  "OIC",
								  "OICORIRIC",
								  "OIRIR",
								  "OIRICORIC",
								  "OICORICPOCPOCPORIRICP",
								  "OICP",
								  "OICOCORI",
								  "OICP1",
								  "OICP123456789",
								  "OICP123SP",
								  "OICP123",
								  "OICP12345SOC",
								  "OICP123SOR",
								  "OICP123SORI",
								  "OIRC",
								  "OICOCOCOCOCO",
								  "OICORIRCOICPSO",
								  "OICPP12PPPPPPPPPPS" };
	const string invalid_tests[] = { "xyz",
									"oic",
									"OIC xyz",
									"P123S",
									"OCIP123S",
									"OICR",
									"OCOICC",
									"OCOICOO",
									"OIP123",
									"OCP123",
									"OICS",
									"OP123C",
									"OIR123",
									"OIR123P",
									"OC123P",
									"OICP123ORICP456",
									"OICP147S",
									"OICP123SOCP123S",
									"OICP123P123456SOR",
									"OICS123OC",
									"OICP123ORIC123",
									"OICP123OC456",
									"",
									"    ",
									"OICOI",
									"OOOOcyf",
									"OICP123P45OC6",
									"OIP" };

	std::cerr << boolalpha;
	for (const string& test : valid_tests) {
		std::cerr << test << "\t"
			<< (isValidCDPlayerString(test) ? green_text : blue_text)
			<< isValidCDPlayerString(test) << reset_text << "\t"
			<< isOpen(test) << "\t" << hasCD(test) << "\t"
			<< totalTracksPlayed(test) << "\t" << currentTrack(test)
			<< endl;
	}
	std::cerr << "\n==========\n" << endl;
	for (const string& test : invalid_tests) {
		std::cerr << test << "\t"
			<< (isValidCDPlayerString(test) ? green_text : blue_text)
			<< isValidCDPlayerString(test) << reset_text << "\t"
			<< isOpen(test) << "\t" << hasCD(test) << "\t"
			<< totalTracksPlayed(test) << "\t" << currentTrack(test)
			<< endl;
	}

	std::cerr << "End of tests" << endl;
	return 0;
}

bool isValidCDPlayerString(string cdstring)
{

	cout.setf(ios::boolalpha);
	bool empty = true;
	bool Open = false;
	bool playS = false;//two plays because of the weird way the professor coded the solution 
	bool playO = false;//based off of discussion posts
	bool valid = false;
	int currentTrack;
	currentTrack = 0;
	if (cdstring == "")
		return (false);//denies an empty string
	else if (cdstring.at(0) != 'O') //must start with O
		return (false);
	else if (cdstring.at(0) == 'O')
	{
		for (int pos = 0; pos != cdstring.size(); pos++)//loops the string
		{
			char c = cdstring.at(pos);
			valid = false;//resets each character to false 
			if (c == 'O' && Open == false)//checks conditions for O to be valid
			{
				Open = true;//if valid these execute
				valid = true;
				playO = false;
			}
			else if (c == 'C' && Open == true)//checks conditions for C to be valid
			{
				Open = false;
				valid = true;
			}
			else if (c == 'I' && empty == true && Open == true)//checks conditions for I to be valid
			{
				empty = false;
				valid = true;
			}
			else if (c == 'R' && empty == false && Open == true)//checks R
			{
				empty = true;
				currentTrack = 0;//resets to 0 if disk removed, makes sure that new disks restart at 1
				valid = true;
			}
			else if (c == 'P' && empty == false && Open == false)//checks P
			{
				playS = true;
				playO = true;
				valid = true;
			}
			else if (c == 'S' && playS == true)//checks S
			{
				playS = false;
				playO = false;
				valid = true;
			}
			else if ((playO == true && playS == true) && (c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9'))
			{//checks numbers and sees if they are sequential
				int track;
				track = 0;
				currentTrack++;
				track = (c - '0');
				if (track == currentTrack)
					valid = true;
				else if (track != currentTrack)
					return (false);

			}
			else if (valid == false)//if no conditions are met returns false 
				return (false);

		}
		if (valid == true)//if all conditions met the end result should be valid=true
			return (true);
		else
			return (false);//to catch any stragglers 

	}
	else
		return (false);//to catch anything else
}

bool isOpen(string cdstring) {
	bool OpenEnd = false;
	string openClose;
	cout.setf(ios::boolalpha);
	if (isValidCDPlayerString(cdstring) == false)
		return (false);
	else {
		for (int pos = 0; pos != cdstring.size(); pos++)//loops through cdstring
		{
			if (cdstring[pos] == 'O' || cdstring[pos] == 'C')
			{
				openClose += cdstring[pos];//creates string of exlusively Os and Cs from the original string
			}
		}
		for (int pos = 0; pos != openClose.size(); pos++)//loops through new string
		{
			char c = openClose.at(pos);//checks if O and Cs alternate, and starts with O
			if (c == 'O' && OpenEnd == false)
			{
				OpenEnd = true;
			}
			else if (c == 'C' && OpenEnd == true)
			{
				OpenEnd = false;
			}
			else
				return (false);//if none of the conditions are met --> false (redundant because should be caught in the isvalidcdstring)
		}

		if (OpenEnd == true)//if success returns what needed 
			return (true);
		else
			return (false);
	}
}
bool hasCD(string cdstring) {
	bool emptyEnd = true;
	cout.setf(ios::boolalpha);
	if (isValidCDPlayerString(cdstring) == false) {
		return (false);
	}
	{ {for (int pos = 0; pos != cdstring.size(); pos++)
	{
		char c = cdstring.at(pos);
		if (c == 'I' && emptyEnd == true)//runs through Is and Rs to toggle the variable empty end
		{
			emptyEnd = false;
		}
		else if (c == 'R' && emptyEnd == false)
		{
			emptyEnd = true;
		}
	}
		}
	if (emptyEnd == false)
		return (true);
	else
		return (false); }

}
int totalTracksPlayed(string cdstring) {
	//need to work on sequential 
	cout.setf(ios::boolalpha);
	if (isValidCDPlayerString(cdstring) == false) {
		return (-1);
	}
	else {
		int Tracks = 0;
		for (int pos = 0; pos != cdstring.size(); pos++)
		{
			char c = cdstring.at(pos);
			if (c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9')
			{
				Tracks++;//increases track number if any numbers are met 
			}
		}
		return(Tracks);
	}

}
int currentTrack(string cdstring) {
	int track;
	track = 0;

	if (isValidCDPlayerString(cdstring) == false) {
		return (-1);
	}
	else if (hasCD(cdstring) == false) {
		return (-1);
	}
	else {
		for (int pos = 0; pos != cdstring.size(); pos++) {

			char c = cdstring.at(pos);
			if (c == 'I')//will reset to 0 if a new disk is put in 
				track = 0;
			if (c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9')

				track = (c - '0');//makes track equal to any numbers 


		}//last number should be the highest track number and should reset to 0 if a new disk is inserted
		track++;//increases track by 1 to get current track 
		return (track);
	}

}