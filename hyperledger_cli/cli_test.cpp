#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

int main() {
	string input;
	cout << "Hyperledger CLI" << endl;
	cout << "Available commands: " << endl;
	cout << "createuser\t[ledgerId]\t[public key]" << endl;
	cout << "createledger\t[public key]" << endl;
	cout << "transfer\t[public key 1]\t[public key 2]\t[amount]  [signature]" << endl;
	while (true)
	{
		cout << ">";
		getline(cin, input);
		auto space_position = input.find_first_of(' ');
		string request = "";
		string params = "";
		if (space_position == string::npos)
		{
			request = input;
		}
		else
		{
			request = input.substr(0, space_position);
			if (space_position + 1 != input.length())
			{
				params = input.substr(space_position + 1);
			}
		}

		if (request == "createuser") {
			space_position = params.find_first_of(' ');
			if (space_position != params.find_last_of(' ') || space_position == string::npos || space_position == params.length() - 1)
			{
				printf("Input error.\n");
				continue;
			}

			auto ledger_id = params.substr(0, space_position);
			auto pub_key = params.substr(space_position + 1);

			// todo serialize
		}
		else if (request == "createledger") {
			auto pub_key = params;
			if (params == "")
			{
				printf("Input error.\n");
				continue;
			}

			// todo serialize
		}
		else if (request == "transfer") {
			string paramsArr[3];
			for (size_t i = 0; i < 3; i++)
			{
				space_position = params.find_first_of(' ');
				if (space_position == 0 || space_position == params.length() - 1 || space_position == string::npos)
				{
					printf("Input error.\n");
					continue;
				}

				paramsArr[i] = params.substr(0, space_position);
				params = params.substr(space_position + 1);
			}

			string pubKey1 = paramsArr[0];
			string pubKey2 = paramsArr[1];
			string amount = paramsArr[2];
			string signature = params;

			// todo serialize
		}
		else if (input == "exit")
		{
			break;
		}
		else
		{
			printf("Invalid input.\n");
		}
	}

	return 0;
}