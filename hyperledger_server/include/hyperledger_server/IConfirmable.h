#ifndef ICONFIRMABLE_H
#define ICONFIRMABLE_H

namespace crypto
{

	class IConfirmable
	{
	public:
		virtual ~IConfirmable();
		int decryptRSA(char* data, char** enc, char** iv, char** p);
	protected:
		IConfirmable();
	};
}

#endif