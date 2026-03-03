#ifndef COW_HPP
#define COW_HPP

#include <string>
#include <vector>
#include "ASCIIPicture.hpp"

class Cow : public ASCIIPicture {
private:
    std::string tongue;
    std::string eyeStyle;  // "normal", "surprised", "angry", etc.

public:
    Cow(const std::string& tongue, const std::string& fname, const std::string& eyeStyle = "normal");
    virtual ~Cow();

    void setEyeStyle(const std::string& style) { eyeStyle = style; }
    void print(unsigned int left, char fill, unsigned int width);
};

#endif