//Programmer: Sterling Gerard
//Date: 3/13/22
//Objective: Create a struct variable of type studentType,
// Contain at least the following functions:read students data
// assign the relevant grade to each student
//find the highest test grade, print the student with the highest grade

// Header Files
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>

// standard namespace
using namespace std;

// cconst int arr = 20;

// define structure studentType
struct studentType {

	//define required variables
	string studentFName;
	string studentLName;
	int	   testScore;
	char   grade;
};

/**Define the function readData() to read
data of the students data into the array*/
void readData(ifstream &file_object, struct studentType arr[])
{
	int student = 0;

	while (!file_object.eof())
	{
		file_object >> arr[student].studentFName;
		file_object >> arr[student].studentLName;
		file_object >> arr[student].testScore;
		student++;
	}
}

/*Define function Grade() to assign the relevant grade each student*/
void Grade(struct studentType arr[])
{
	for (int i = 0; i < 20; i++)
	{
		int score = arr[i].testScore;

		if (score >= 90)
		{
			arr[i].grade = 'A';
		}
		else if (score >= 80)
		{
			arr[i].grade = 'B';
		}
		else if (score >= 70)
		{
			arr[i].grade = 'C';
		}
		else if (score >= 60)
		{
			arr[i].grade = 'D';
		}
		else
		{
			arr[i].grade = 'F';
		}
	}
}


/*Define the function to find the highest test score*/
int findHighScore(struct studentType arr[])
{
	int highestScore = -1;
	for (int i = 0; i < 20; i++)
	{
		if (arr[i].testScore > highestScore)
		{
			highestScore = arr[i].testScore;
		}
		return highestScore;
	}
}

/*Define a function to print the names of the students
having the highest test score*/
void printHighestScore(ofstream &outfile, struct studentType arr[], double highScore)
{
	outfile << "the highest test scores:" << endl;

	for (int i = 0; i < 20; i++)
	{
		if (arr[i].testScore == highScore)
		{
			outfile << left << arr[i].studentLName + ", " + arr[i].studentFName << endl;
		}
	}
}

/*Define funtion to  printData() to write 
the data of the students to the out file*/
void printData(ofstream &outfile, struct studentType arr[])
{
	outfile << left << setw(30) << "Student Name";
	outfile << "\t";
	outfile << "Test Score";
	outfile << "\t";
	outfile << " Grade";

	for (int i = 0; i, 20; i++)
	{
		outfile << left << setw(30) << arr[i].studentLName + ", " + arr[i].studentFName;
		outfile << right << setw(10) << arr[i].testScore;
		outfile << right << setw(6) << arr[i].grade;
		outfile << endl;
	}
	outfile << endl;
}


//+++++++++++++++++++++Define Main Program+++++++++++++++++++++++++++
int main()
{
	//Define object of ifstream class to open the input file
	ifstream file_object;
	file_object.open("inputdata.txt");

	//Define object of the ofstream class to open the output file
	ofstream out_file_object;
	out_file_object.open("output.txt");

	//Array structure of studentType to store data of 20 students
	struct studentType arr[20];

	// call required functions
	readData(file_object, arr);
	Grade(arr);
	printData(out_file_object, arr);
	findHighScore(arr);
	printHighestScore(out_file_object, arr, highScore);

	//close the file objects
	file_object.close();
	out_file_object.close();


	//Return from the main() function
	return 0;


}
