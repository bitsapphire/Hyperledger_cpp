#ifndef ISIGNABLE_H
#define ISIGNABLE_H

namespace crypto
{
	class ISignable
	{
	public:
		virtual ~ISignable();
		int encryptRSA(char* data, char** enc, char** iv, char** p);
	protected:
		ISignable();
	};
}
#endif
