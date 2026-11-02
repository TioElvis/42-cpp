#include <string>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <fstream>
#include <iostream>

std::string getReplaceContent(std::string originalContent, std::string s1, std::string s2)
{
    std::string replaceContent;

    int i = 0;
    int lenS1 = s1.length();
    int lenOriginalContent = originalContent.length();

    while (i < lenOriginalContent)
    {
        if (std::strncmp(&originalContent[i], s1.c_str(), lenS1) == 0)
        {
            replaceContent += s2;
            i += lenS1;
        }
        else
        {
            replaceContent += originalContent[i];
            i++;
        }
    }

    return replaceContent;
}

std::string getContentFile(std::ifstream &f)
{
    std::ostringstream buffer;

    buffer << f.rdbuf();

    std::string content = buffer.str();

    return content;
}

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Usage ./SedIsForLosers <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::string filename = argv[1];

    std::ifstream originalFile(filename.c_str());
    std::ofstream replaceFile((filename + ".replace").c_str());

    if (!originalFile.is_open() || !replaceFile.is_open())
    {
        std::cout << "Error opening the files" << std::endl;
        return 1;
    }

    std::string originalContent = getContentFile(originalFile);
    std::string replaceContent = getReplaceContent(originalContent, s1, s2);

    replaceFile.write(replaceContent.c_str(), replaceContent.length());

    replaceFile.close();
    originalFile.close();

    return 0;
}