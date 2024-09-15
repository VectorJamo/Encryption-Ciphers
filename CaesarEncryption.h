#pragma once
struct EncryptionStatus {
	bool success;
	char keyOffset;
};

int getEncryptedChar(char c, int keyOffset);

// For encryption and decryption by giving a key beforehand
EncryptionStatus Encrypt(const char* filepath, int keyOffset);
EncryptionStatus Decrypt(const char* filepath, int keyOffset);

// For encryption using a random key offset value, returns the 
EncryptionStatus Encrypt(const char* filepath);