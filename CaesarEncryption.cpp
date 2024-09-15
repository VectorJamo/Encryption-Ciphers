#include "CaesarEncryption.h"

#include <iostream>
#include <fstream>
#include <string>

EncryptionStatus Encrypt(const char* filepath, int keyOffset)
{
	std::ifstream file(filepath);

	if (!file.is_open())
	{
		std::cout << "Failed to open file!" << std::endl;
	}
	else {
		std::string line;

		std::string text;
		std::string encryptedText;

		while (std::getline(file, line)) 
		{
			text += (line + '\n');
		}

		std::cout << text << std::endl;

		std::cout << "---------------" << std::endl;

		// Encryption
		for (char c : text)
		{
			encryptedText += (char)getEncryptedChar(c, keyOffset);
		}

		std::cout << encryptedText << std::endl;
	}

	return EncryptionStatus();
}

EncryptionStatus Decrypt(const char* filepath, int keyOffset)
{
	return EncryptionStatus();
}

EncryptionStatus Encrypt(const char* filepath)
{
	return EncryptionStatus();
}

int getEncryptedChar(char c, int keyOffset)
{
	// For space and new line feed letters
	if (int(c) == 32) {
		return 32;
	}
	else if (int(c) == 10) {
		return 10;
	}

	int encryptedChar = int(c) + keyOffset;

	int overflow = encryptedChar;

	// ASCII : 97 - 122 inclusive -> 26
	if (encryptedChar > 122) {
		while (overflow > 122)
		{
			overflow -= 122;
		}

		encryptedChar = 96 + overflow;
	}

	return encryptedChar;
}
