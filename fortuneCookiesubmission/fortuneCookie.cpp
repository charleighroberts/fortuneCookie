/*1. Fortune Teller

Using the "FORTUNES.txt" file in the modules tab, create a program that reads the fortunes from the text 
file into either a vector or an array (strings or characters).  Display a prompt for the user to enter the number of their birth month 
(1 == January, 2 == February, etc.), and then generate a random fortune, as being the current fortune for people born in the named month. 

Example:

Enter the number of your birth month: 8

Fortune for people born in August: "If it looks back at you from the plate, don't eat it."

INPUT VALIDATION:

Make sure that the program can find the file and read the contents prior to importing the information.
Do not accept numbers less than 1 or greater than 12 for the birth month. */

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath> 
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cctype>
using namespace std;

void showContents(fstream &);
bool openFileIn(fstream &, string);


int main()
{
    cout << "Hello World!\n";

    char again;
    int month = 0;
    int random = 5;
    fstream dataFile;
    string input;
    string STARTBYTE[60];

    if (openFileIn(dataFile, "FORTUNES.txt"))
    {

        cout << "File opened successfully\n";
        //determine # of bytese
        dataFile.seekg(0L, ios::end);
        int numBytes = dataFile.tellg();
        cout << "this file has " << numBytes << endl;
        //go back to beginning
        dataFile.seekg(0L, ios::beg);

        if (dataFile)
        {
            //for loop to read data
            for (int i = 0; i < 60; i++)
            {
                // inputFile >> eightBall[i];
                getline(dataFile, STARTBYTE[i]);
            }

            // test eightBall array
           /* for (int j = 0; j < 60; j++)
            {
                cout << STARTBYTE[j] << endl;
            }
                //read name from file
                //getline(dataFile, input);
                //while the last read operation was successful, continue
               // while (dataFile < numBytes)
              //  {
                 //   int counter = 0;

                //    STARTBYTE[counter] = input;
                //    //getline(dataFile, input);
               // }

                //close file
                dataFile.close();
        }*/


            do
            {


                srand(time(NULL));

                string months[] = { "January", "Febrary","March" , "April", "May",
                                 "June", "July", "August", "September",
                                 "October", "November", "December" };

                cout << "What your birth month?\n";
                cin >> month;
                //validatemonth
                // months must be between 1 and 12 
                while (month == 0 || month < 1 || month > 12)
                {
                    cout << "There are only 12 months in a year. Please type in a number between 1 and 12\n";
                    cin >> month;
                }

                int random = 1 + (rand() % 16);
                cout << "Fortune for people born in " << months[month - 1] << ". \"" << STARTBYTE[random] << ". \"" << endl;



                //does the user wna to try again?

                cout << "Do it again? ";
                cin >> again;


                /* //read name from file
                 getline(dataFile, input);
                 //while the last read operation was successful, continue
                 while (dataFile.seekg(random, ios::end))
                 {
                     //Display last item read
                     cout << input << endl;

                     //read next item
                     //getline(dataFile, input);
                 }*/

                 //close file
                dataFile.close();
            } while (again == 'Y' || again == 'y');
        }

    }
    else
    {
        cout << "File open error.\n";

    }
}

bool openFileIn(fstream &file, string name)
{
    file.open(name, ios::in);
    if (file.fail())
        return false;
    else
        return true;
}

void showContents(fstream &file)
{
    string line;
    while (file >> line)
    {
        cout << line << endl;
    }

}

/*            if (dataFile)
            {
                //read name from file
                getline(dataFile, input);
                //while the last read operation was successful, continue
                while (dataFile)
                {
                    //Display last item read
                    cout << input << endl;

                    //read next iten
                    //getline(dataFile, input);
                }

                //close file
                dataFile.close();
            }
*/