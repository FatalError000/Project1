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
		if (((inputString[i] >= 'a') && (inputString[i] <= 'z')) ||
		    ((inputString[i] >= 'A') && (inputString[i] <= 'Z')))
		{
			if (((int)inputString[i] >= 65) && ((int)inputString[i] <= 90))
			{				
				result += (char)tempIndexCreate(65, 90, (int)inputString[i], encryptValue);
			}
			else if (((int)inputString[i] >= 97) && ((int)inputString[i] <= 122))
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

int easyEncryptValue(int encryptValue)
{
	int result = encryptValue;

	while (result > 26)
	{
		result -= 26;
	}

	return result;
}

int main()
{
	string inputString, outputString;
	int encryptValue;

	cout << "Enter your text" << endl;
	getline(cin, inputString);

	do
	{
		cout << "Enter the offset size for ENCRYPT." << endl;
		cin >> encryptValue;
	} while (encryptValue < 0);

	encryptValue = easyEncryptValue(encryptValue);

	outputString = encrypt_caesar(inputString, encryptValue);

	cout << endl << "Your encrypted text" << endl << outputString << endl;
	
	cout << endl << "Your decrypted text" << endl << decrypt_caesar(outputString, encryptValue) << endl;
	
	return 0;
}