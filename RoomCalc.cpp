#include "RoomCalc.h"
#include <iostream>
#include <string>     // std::string, std::to_string

using namespace std;


/*************************************************************************************************************************/
/* Author: Andrew J. May    Date: 14/12/2017                                                                             */

int main()
{
  /* The program's purpose is to calculate values for a rectangular room:
	 Area of the floor.
	 Amount of paint required to paint the walls for a single coat.
	 Volume of the room.


	 The user will be asked to enter 3 dimensions in meters:
	 Length,  Width  and  Height of the room.
  */

	// Variables
	float m_Length = 0.0;
	float m_Width = 0.0;
	float m_Height = 0.0;

	float m_FloorArea = 0.0;
	float m_WallsArea = 0.0;
	float m_Volume = 0.0;

	bool b_ExitProg = false;
	char c_RunAgain = 'x';

	while (b_ExitProg == false)                 /* Keep running the program until the user decides to exit.*/
	{                                           /* Since a 0 dimension value is not a valid for a 3D room 0 will be the user's early quitting option.*/

	cout << "============================================================================\n";
		cout << "The program's purpose is to calculate values for a rectangular room:\n";
		cout << "     Area of the floor.\n";
		cout << "     Amount of paint required to paint the walls for a single coat.\n";
		cout << "     Volume of the room.\n";
		cout << "\n\n";
		cout << "The user will be asked to enter 3 dimensions in meters:\n";
		cout << " Length,  Width  and  Height of the room.\n";
		cout << "\n\n";


		// Ask user for the room Length.
		cout << "Please enter the room's Length(m),  or 0 to quit: " << flush;

		while (!(cin >> m_Length) or (m_Length < 0) )                // If not a positive number loop until the Length input is a valid floating number.
		{
			cout << "You did not enter a positive number.        Please enter the room's Length(m),  or 0 to quit : " << flush;
			cin.clear();                                            // Clear out previous user's input.
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		if (m_Length == 0) /* The user has aborted the program. So exit */
		{
			return 0;
		}


		// Ask user for the room Width.
		cout << "\n\n";
		cout << "Please enter the room's Width(m),  or 0 to quit  : " << flush;

		while (!(cin >> m_Width) or (m_Width < 0) )                 //  If not a positive number loop until the Width input is a valid floating number.
		{
			cout << "You did not enter a positive number.        Please enter the room's  Width(m),  or 0 to quit : " << flush;
			cin.clear();                                            // Clear out previous user's input.
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		if (m_Width == 0)                                           // The user has aborted the program. So exit.
		{
			return 0;
		}


		// Ask user for the room Height.
		cout << "\n\n";
		cout << "Please enter the room's Height(m),  or 0 to quit : " << flush;

		while (!(cin >> m_Height) or (m_Height < 0))               //  If not a positive number loop until the Height input is a valid floating number.
		{
			cout << "You did not enter a positive number.        Please enter the room's  Height(m),  or 0 to quit : " << flush;
			cin.clear();                                           // Clear out previous user's input.
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		cout << "\n";
		cout << "============================================================================\n";

		if (m_Height == 0) /* The user has aborted the program. So exit */
		{
			return 0;
		}

		m_FloorArea = CalcFloorArea(m_Length, m_Width);

		m_WallsArea = CalcWallsArea(m_Length, m_Width, m_Height);

		m_Volume = CalcVolume(m_Length, m_Width, m_Height);

		DisplayResults(m_Length, m_Width, m_Height, m_FloorArea, m_WallsArea, m_Volume);


		cout << "\n";
		cout << "Do you want to run again? 'N' to exit: ";
		cin >> c_RunAgain;

		c_RunAgain = toupper(c_RunAgain);  // Make sure the user's input is uppercase before comparison to allow upper and lower case input.
		cout << "\n";
		cout << "============================================================================";

		if (c_RunAgain == 'N')
		{
			b_ExitProg = true;
		}

	} // End of while (exitProg == false)

	return 0;
}


/***********************************************************************************/
/* Purpose: Calculate the floor area.*/

float CalcFloorArea(float m_Length, float m_Width)
{
	float f_Area = 0.0;

	f_Area = m_Length * m_Width;

	return f_Area;
}


/***********************************************************************************/
/* Purpose: Calculate the all four walls surface area.*/
float CalcWallsArea(float m_Length, float m_Width, float m_Height)

{
	float f_WallArea = 0.0;

	f_WallArea = (m_Length * m_Height * 2) + (m_Width * m_Height * 2);

	return f_WallArea;
}

/***********************************************************************************/
/* Purpose: Calculate the internal volume of the room.*/

float CalcVolume(float m_Length, float m_Width, float m_Height)
{
	float f_Volume = 0.0;

	f_Volume = m_Length * m_Width * m_Height;

	return f_Volume;
}

/***********************************************************************************/
/* Purpose: Display the calculated results. */

void DisplayResults(float m_Length, float m_Width, float m_Height, float m_FloorArea, float m_WallsArea, float m_Volume)
{
	cout << " For the room of dimensions:  Length: " + std::to_string(m_Length) + " m    Width: " + std::to_string(m_Width) + " m    Height: " + std::to_string(m_Height) + " m";
	cout << "\n";
	cout << " The Floor area is: " + std::to_string(m_FloorArea) + " m2"<< endl; 
	cout << "\n";
	cout << " The Wall area is: " + std::to_string(m_WallsArea) + " m2" << endl;
	cout << "\n";
	cout << " The Volume is: " + std::to_string(m_Volume) + " m3" << endl;
	cout << "****************************************************************************";
}


