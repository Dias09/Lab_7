#include <iostream>
#include <algorithm>
#include <crypt.h>
#include <string>
#include <fstream>


using namespace std;
void findPass(string pass, const string& hash)
{
 crypt_data *pCryptData = new crypt_data;
 size_t pos = hash.find_last_of('$');
 string hashHead = hash.substr(0,pos);
 do {
		string newHash(crypt_r(pass.data(),hashHead.data(),pCryptData));
		if (newHash == hash) {

			cout << "Hash: " << hash << endl <<"Pass: " << pass << endl;
			break;
		}
	} while (next_permutation (pass.begin(),pass.end()));
	delete pCryptData;
}


int main()
{
	int quan;
	cout << "Введите число хэшей (1, 2, 4, 8): ";
	cin >> quan;
	ifstream
	hash_2("hash.txt");
	string *hash_3 = new string [quan];
	for (int i = 0; i < quan; i++) {
		hash_2 >> hash_3[i];
	}
	string s = "123456789";
	for (int i = 0; i < quan; i++)
		findPass(s, hash_3[i]);
	return 0;
}
