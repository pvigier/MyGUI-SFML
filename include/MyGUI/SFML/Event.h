#pragma once

namespace sf
{

class Event;

}

namespace MyGUI
{

namespace SFML
{

bool injectEvent(const sf::Event& event);

}

}