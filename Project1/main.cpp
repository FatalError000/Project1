#include <iostream>
#include <string>
using namespace std;

int tempIndexCreate(int min, int max, int index, int encryptValue)
{
	int result;

	if ((index >= min) || (index <= max))
	{
		result = index + encryptValue;

		if (result < min)
		{
			result = max - (min - result) + 1;
		}
		if (result > max)
		{
			result = min + (result - max) - 1;
		}
	}

	return result;
}

string encrypt_caesar(string inputString, int encryptValue)
{
	string result;

	for (int i = 0; i < inputString.length(); i++)
	{
		if ((inputString[i] != ' ') || ((inputString[i] >= 'a') && (inputString[i] <= 'z')) 
		                            || ((inputString[i] >= 'A') && (inputString[i] <= 'Z')))
		{
			if (((int)inputString[i] >= 65) && ((int)inputString[i] <= 90))
			{				
				result += (char)tempIndexCreate(65, 90, (int)inputString[i], encryptValue);
			}

			if (((int)inputString[i] >= 97) && ((int)inputString[i] <= 122))
			{
				result += (char)tempIndexCreate(97, 122, (int)inputString[i], encryptValue);
			}
		}
		else
		{
			result += inputString[i];
		}
	}

	return result;
}

string decrypt_caesar(string inputString, int encryptValue)
{
	return encrypt_caesar(inputString, -1 * encryptValue);
}

int main()
{
	string inputString;
	int encryptValue, choice;

	cout << "Enter your text" << endl;
	getline(cin, inputString);

	cout << "Enter the offset size for DECRYPT." << endl;
	cin >> encryptValue;

	
	do
	{
		cout << "Dou you want to encrypt text? (Press 1)\nOr you want to decrypt text? (Press 2)" << endl;
		cin >> choice;
	} while((choice < 1) || (choice > 2));

	switch (choice)
	{
		case 1 : {
					cout << endl << "Your encrypted text" << endl << encrypt_caesar(inputString, encryptValue) << endl; 
					break;
				 }
		case 2 : {
					cout << endl << "Your decrypted text" << endl << decrypt_caesar(inputString, encryptValue) << endl; 
					break;
				 }
	}
	
	return 0;
}