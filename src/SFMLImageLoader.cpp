#include "MyGUI/SFML/SFMLImageLoader.h"
#include <MyGUI_OpenGL3DataManager.h>
#include <SFML/Graphics/Image.hpp>

namespace MyGUI
{

namespace SFML
{

void* SFMLImageLoader::loadImage(int& _width, int& _height, MyGUI::PixelFormat& _format,
    const std::string& _filename)
{
    auto fullname = MyGUI::OpenGL3DataManager::getInstance().getDataPath(_filename);

    auto image = sf::Image();
    if (!image.loadFromFile(fullname))
        return nullptr;

    _width = image.getSize().x;
    _height = image.getSize().y;
    _format = MyGUI::PixelFormat::R8G8B8A8;

    auto size = _width * _height * 4;
    auto data = new unsigned char[size];
    memcpy(data, image.getPixelsPtr(), size);

    // Swap red and blue channels
    for (auto i = 0; i < size; i += 4)
        std::swap(data[i], data[i + 2]);

    return data;
}

void SFMLImageLoader::saveImage(int _width, int _height, MyGUI::PixelFormat _format, void* _texture,
    const std::string& _filename)
{
    // TODO: test this function
    auto image = sf::Image();
    image.loadFromMemory(_texture, _width * _height);
    image.saveToFile(_filename);
}

}

}