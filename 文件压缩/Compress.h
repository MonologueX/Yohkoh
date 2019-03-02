#define __COMPRESS_H__
#ifdef __COMPRESS_H__
#include "Huffman.hpp"
#include <string>
typedef long long CountType;

struct CharInformation
{
	bool operator>(const CharInformation& information)
	{
		return m_count > information.m_count;
	}
	bool operator!=(const CharInformation& information)
	{
		return m_count != information.m_count;
	}
	bool operator==(const CharInformation& information)
	{
		return m_count == information.m_count;
	}
	CharInformation operator+(const CharInformation& information)
	{
		return m_count + information.m_count;
	}
	CharInformation(CountType count = 0)
		:m_count(count)
	{}

	// 汉字出错
	unsigned char m_ch;
	CountType m_count;
	std::string m_code;
};

class Compress
{
	typedef HuffmanNode<CharInformation>* Node;
public:
	Compress()
	{
		m_informations.resize(256);
		for (size_t i = 0; i < 256; ++i)
		{
			m_informations[i].m_ch = i;
		}
	}
	int compress(const std::string& CompressName);
	int uncompress(const std::string& CompressName);
	std::string GetFileExtensio(const std::string& CompressName);
private:
	int GetHuffmanCode(Node root);
	void WriteHead(FILE *fin, const std::string& CompressName);
	std::string GetFilepath(const std::string& CompressName);
	std::vector<CharInformation> m_informations;
};

void ReadLine(FILE*fin, std::string& StrInformation);
#endif
