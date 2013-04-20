#include <string>
#include <iostream>
 
std::string generateKey(std::string p, size_t j) {
	int i;
	std::string out = "";
	for (i = 0; i < j; ++i) {
		out += p[i % p.length()];
	}
	return out;
}

std::string encrypt(std::string m, std::string k) {
	int i;
	std::string c = "", a = "abcdefghijklmnopqrstuvwxyz";
	for (i = 0; i < m.length(); ++i) {
		c += a[(a.find(m[i]) + a.find(k[i]))  % 26];
	}

	return c;
}

std::string decrypt(std::string c, std::string k) {
	int i;
	std::string m = "", a = "abcdefghijklmnopqrstuvwxyz";	
	for (i = 0; i < c.length(); ++i) {
	
		if (a.find(k[i]) > a.find(c[i])) {
			m += a[26 - (a.find(k[i]) - a.find(c[i]))];
		}
		else {
			m += a[(a.find(c[i]) - a.find(k[i])) % 26];
		} 
	}

	return m;
} 

int main(int argc, const char *argv[]) {
	std::string plaintext, password, key;
	std::cout << "Give me a string to encrypt (remove all spaces):";
	std::cin >> plaintext;
	std::cout << "Give me a password:";
	std::cin >> password;

	key = generateKey(password, plaintext.length());

	std::cout << "The password '" << password << "' yields the key '" << key << "'" << std::endl; 
	std::cout << "The plaintext '" << plaintext << "' in the expression encrypt('"  << plaintext << "') is '" << encrypt(plaintext, key) << "' and the expression decrypt(encrypt('" << plaintext << "')) is '" << decrypt(encrypt(plaintext, key), key) << "'" << std::endl;
	return 0;
}

	
