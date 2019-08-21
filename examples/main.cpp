#include <MyGUI.h>
#include <MyGUI_OpenGL3Platform.h>
#include <MyGUI/SFML/Event.h>
#include <MyGUI/SFML/SFMLImageLoader.h>
#include <SFML/Graphics.hpp>

int main()
{
    constexpr auto WindowWidth = 800u;
    constexpr auto WindowHeight = 600u;

    sf::RenderWindow window(sf::VideoMode(WindowWidth, WindowHeight), "MyGUI-SFML");
    window.setFramerateLimit(60);

    // Initialize the OpenGL3Platform
    auto imageLoader = MyGUI::SFML::SFMLImageLoader();
    auto platform = MyGUI::OpenGL3Platform();
    platform.initialise(&imageLoader);

    // Add resources
    platform.getDataManagerPtr()->addResourceLocation("res/", true);

    // Initialize the GUI
    auto gui = MyGUI::Gui();
    gui.initialise();

    // Set the view size
    platform.getRenderManagerPtr()->setViewSize(WindowWidth, WindowHeight);

    // Load a layout
    MyGUI::LayoutManager::getInstance().loadLayout("Console.layout");

    // Use a flag to not destroy the context before the end of the loop
    bool running = true;
    while (running)
    {
        auto event = sf::Event();
        while (window.pollEvent(event))
        {
            MyGUI::SFML::injectEvent(event);
            if (event.type == sf::Event::Closed)
                running = false;
        }

        window.clear(sf::Color::Black);

        // Draw the GUI
        platform.getRenderManagerPtr()->drawOneFrame();

        window.display();
    }

    gui.shutdown();
    platform.shutdown();

    return 0;
}
