#include "Cow.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

Cow::Cow(const string& tongue, const string& fname, const string& eyeStyle)
    : ASCIIPicture("./cows/" + fname + ".cow"), tongue(tongue), eyeStyle(eyeStyle)
{
}

Cow::~Cow() {}

void Cow::print(unsigned int left, char fill, unsigned int width)
{
    unsigned int cowWidth = getWidth();

    // Создаём копию картинки, чтобы не портить оригинал
    std::vector<std::string> displayPicture = picture;

    // Меняем глаза в первой строке (где обычно ^__^)
    if (!displayPicture.empty()) {
        string& firstLine = displayPicture[0];

        // Ищем шаблон ^__^ или подобный
        size_t pos = firstLine.find('^');
        if (pos != string::npos && pos + 2 < firstLine.size()) {
            if (eyeStyle == "surprised") {
                firstLine[pos] = '*';
                if (pos + 2 < firstLine.size()) firstLine[pos + 2] = '*';
            }
            else if (eyeStyle == "angry") {
                firstLine[pos] = '>';
                if (pos + 2 < firstLine.size()) firstLine[pos + 2] = '<';
            }
            else if (eyeStyle == "sad") {
                firstLine[pos] = 'T';
                if (pos + 2 < firstLine.size()) firstLine[pos + 2] = 'T';
            }
            else if (eyeStyle == "shocked") {
                firstLine[pos] = 'O';
                if (pos + 2 < firstLine.size()) firstLine[pos + 2] = 'O';
            }
            // "normal" ничего не меняет
        }
    }

    // Вывод с заменой $t
    for (int i = 0; i < displayPicture.size(); i++)
    {
        // Левый отступ
        for (unsigned int j = 0; j < width - cowWidth - left; j++)
            cout << fill;

        for (int j = 0; j < displayPicture[i].size(); j++)
        {
            if (j + 1 < displayPicture[i].size() && displayPicture[i][j] == '$'
                && displayPicture[i][j + 1] == 't')
            {
                cout << tongue;
                j++;
            }
            else
            {
                cout << displayPicture[i][j];
            }
        }

        // Правый отступ
        for (unsigned int j = width - cowWidth - left + displayPicture[i].size(); j < width; j++)
            cout << fill;
        cout << endl;
    }

    // Нижняя линия
    for (unsigned int i = 0; i < width; i++)
        cout << fill;
    cout << endl;
    std::cout << "\n";
    for (unsigned int i = 0; i < width; i++) std::cout << "=";
    std::cout << "\n>>> КОРОВА БЫЛА ЗДЕСЬ <<<\n";
    for (unsigned int i = 0; i < width; i++) std::cout << "=";
    std::cout << "\n";
}