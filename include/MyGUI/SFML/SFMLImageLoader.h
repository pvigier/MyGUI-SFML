#pragma once

#include <string>
#include <MyGUI_OpenGL3ImageLoader.h>

namespace MyGUI
{

namespace SFML
{

class SFMLImageLoader : public MyGUI::OpenGL3ImageLoader
{
private:
    virtual void* loadImage(int& _width, int& _height, MyGUI::PixelFormat& _format,
        const std::string& _filename) override;
    virtual void saveImage(int _width, int _height, MyGUI::PixelFormat _format, void* _texture,
        const std::string& _filename) override;
};

}

}