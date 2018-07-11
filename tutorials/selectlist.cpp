
#include <string>
#include <iostream>
#include <rude/config.h>


int main(void)
{

	rude::Config config;

	// Determine which country should be highlighted 
	// Within the select list
	//
	std::string selectedCountryCode="US";

	// Load the countries into the config object
	//
	if(config.load("countrycodes.ini"))
	{
		// Start the SELECT section 
		//
		std::cout << "<SELECT name=\"country_code\">\n";
		
		int numCountries = config.getNumDataMembers();
		for(int x=0; x< numCountries; x++)
		{
			const char *countryCode=config.getDataNameAt(x);
			const char *countryName=config.getStringValue(countryCode);

			// Start the option tag, with the field name in 'quotes'
			//
			std::cout << "<OPTION value='" << countryCode << "'";

			if(selectedCountryCode == countryCode)
			{
				// If we find the name of the field we want selected, 
				// then the option tag will look like:
				// <OPTION value='somevalue' SELECTED>somecountry</OPTION>
				// 
                          std::cout << " SELECTED";
			}
			
			// Finish the OPTION Tag (>), then write the visible text (the country name)
			// and the closing /OPTION tag
			//
			std::cout << ">" << countryName << "</OPTION>\n";
		}
		
		// End the SELECT section
		//
		std::cout << "</SELECT>";
	}
	else
	{
		std::cout << "Error opening country codes file: " << config.getError() << "\n";
	}
	return 0;
}
