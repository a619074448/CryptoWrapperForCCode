#ifndef AES_WRAPPER_H
#define AES_WRAPPER_H

///************* AES ���ܡ����ܡ���ȡ��Կ**************//
//Ĭ�����ԣ�AES/ECB/PKCS5Padding mode
//��Կ���ȣ�password must 16 bytes, 128 bits
//****************************************************//


#ifdef CRYPTO_EXPORTS
#define CRYPTO_API __declspec(dllexport)
#else
#ifdef CRYPTO_IMPORTS
#define CRYPTO_API __declspec(dllimport)
#else 
#define CRYPTO_API extern
#endif
#endif

/********************************************************************************
description:
	��ȡ AES ��Կ
input: 
	buffer_len����Կ����ĳ��ȣ��� buff_password ����
output:
	buff_password����Կ���棬����Ҫ����16���ֽ�
return:
	0��ʧ�ܣ���0:���յõ������볤��
********************************************************************************/
CRYPTO_API unsigned int CreateSecretKeyAES(unsigned char* buff_password, const unsigned int buffer_len);

/********************************************************************************
description:
����Ƿ�Ϊ��������
input:
input_data����Ҫ����������
input_length����Ҫ��������ݵĳ���
output:
return:
0���������ݣ���0:�Ǽ�������
********************************************************************************/
CRYPTO_API int CheckEncrypted(const unsigned char *input_data, const size_t &input_length);

/********************************************************************************
description:
	ʹ�� AES ��������
input:
	password����Կ
	input_data����Ҫ�����ܵ�����
	input_length�����������ݵĳ���
output:
	out_data������ļ������ݣ���Ҫ���ⲿʵ�ַ���ã��ҳ�������Ϊ input_length + 32
	output_length������ļ������ݳ���
return:
	0���ɹ�����0:ʧ��
********************************************************************************/
CRYPTO_API int EncryptAES(const unsigned char *password, const unsigned char *input_data, const size_t &input_length, unsigned char *out_data, size_t &output_length);

/********************************************************************************
description:
	ʹ�� AES ��������
input:
	password����Կ
	input_data����Ҫ�����ܵ�����
	input_length�����������ݵĳ���
output:
	out_data������Ľ��ܺ��ԭʼ���ݣ���Ҫ���ⲿʵ�ַ���ã��ҳ�������Ϊ input_length + 32
	output_length������Ľ������ݳ���
return:
	0���ɹ�����0:ʧ��
********************************************************************************/
CRYPTO_API int DecryptAES(const unsigned char *password, const unsigned char *input_data, const size_t &input_length, unsigned char *out_data, size_t &output_length);

#endif								