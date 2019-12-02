#include "MyGUI/SFML/Event.h"
#include <MyGUI_InputManager.h>
#include <SFML/Window/Event.hpp>

namespace MyGUI
{

namespace SFML
{

MyGUI::MouseButton getMouseButton(sf::Mouse::Button button);
MyGUI::KeyCode getKeyCode(sf::Keyboard::Key code);

bool injectEvent(const sf::Event& event)
{
    static auto mouseZ = 0.0f;
    auto& inputManager = MyGUI::InputManager::getInstance();
    switch (event.type)
    {
        case sf::Event::KeyPressed:
            return inputManager.injectKeyPress(getKeyCode(event.key.code));
        case sf::Event::KeyReleased:
            return inputManager.injectKeyRelease(getKeyCode(event.key.code));
        case sf::Event::TextEntered:
            // Must filter some codes to have correct behavior
            if (event.text.unicode != 8 && // Backspace
                event.text.unicode != 13 && // Return
                event.text.unicode != 127) // Delete
                return inputManager.injectKeyPress(MyGUI::KeyCode::None, event.text.unicode);
            break;
        case sf::Event::MouseButtonPressed:
            return inputManager.injectMousePress(event.mouseButton.x, event.mouseButton.y,
                getMouseButton(event.mouseButton.button));
        case sf::Event::MouseButtonReleased:
            return inputManager.injectMouseRelease(event.mouseButton.x, event.mouseButton.y,
                getMouseButton(event.mouseButton.button));
        case sf::Event::MouseMoved:
            return inputManager.injectMouseMove(event.mouseMove.x, event.mouseMove.y, mouseZ);
        case sf::Event::MouseWheelScrolled:
            mouseZ += event.mouseWheelScroll.delta;
            return inputManager.injectMouseMove(event.mouseWheelScroll.x, event.mouseWheelScroll.y, mouseZ);
        default:
            break;
    }
    return false;
}

MyGUI::MouseButton getMouseButton(sf::Mouse::Button button)
{
    switch (button)
    {
        case sf::Mouse::Left: return MyGUI::MouseButton::Left; break;
        case sf::Mouse::Right: return MyGUI::MouseButton::Right; break;
        case sf::Mouse::Middle: return MyGUI::MouseButton::Middle; break;
        case sf::Mouse::XButton1: return MyGUI::MouseButton::Button3; break; // Not sure
        case sf::Mouse::XButton2: return MyGUI::MouseButton::Button4; break; // Not sure
        default: return MyGUI::MouseButton::None; break;
    }
}

MyGUI::KeyCode getKeyCode(sf::Keyboard::Key code)
{
    switch (code)
    {
        case sf::Keyboard::Escape: return MyGUI::KeyCode::Escape;
        case sf::Keyboard::Num1: return MyGUI::KeyCode::One;
        case sf::Keyboard::Num2: return MyGUI::KeyCode::Two;
        case sf::Keyboard::Num3: return MyGUI::KeyCode::Three;
        case sf::Keyboard::Num4: return MyGUI::KeyCode::Four;
        case sf::Keyboard::Num5: return MyGUI::KeyCode::Five;
        case sf::Keyboard::Num6: return MyGUI::KeyCode::Six;
        case sf::Keyboard::Num7: return MyGUI::KeyCode::Seven;
        case sf::Keyboard::Num8: return MyGUI::KeyCode::Eight;
        case sf::Keyboard::Num9: return MyGUI::KeyCode::Nine;
        case sf::Keyboard::Num0: return MyGUI::KeyCode::Zero;
        case sf::Keyboard::Dash: return MyGUI::KeyCode::Minus;
        case sf::Keyboard::Equal: return MyGUI::KeyCode::Equals;
        case sf::Keyboard::BackSpace: return MyGUI::KeyCode::Backspace;
        case sf::Keyboard::Tab: return MyGUI::KeyCode::Tab;
        case sf::Keyboard::Q: return MyGUI::KeyCode::Q;
        case sf::Keyboard::W: return MyGUI::KeyCode::W;
        case sf::Keyboard::E: return MyGUI::KeyCode::E;
        case sf::Keyboard::R: return MyGUI::KeyCode::R;
        case sf::Keyboard::T: return MyGUI::KeyCode::T;
        case sf::Keyboard::Y: return MyGUI::KeyCode::Y;
        case sf::Keyboard::U: return MyGUI::KeyCode::U;
        case sf::Keyboard::I: return MyGUI::KeyCode::I;
        case sf::Keyboard::O: return MyGUI::KeyCode::O;
        case sf::Keyboard::P: return MyGUI::KeyCode::P;
        case sf::Keyboard::LBracket: return MyGUI::KeyCode::LeftBracket;
        case sf::Keyboard::RBracket: return MyGUI::KeyCode::RightBracket;
        case sf::Keyboard::Return: return MyGUI::KeyCode::Return;
        case sf::Keyboard::LControl: return MyGUI::KeyCode::LeftControl;
        case sf::Keyboard::A: return MyGUI::KeyCode::A;
        case sf::Keyboard::S: return MyGUI::KeyCode::S;
        case sf::Keyboard::D: return MyGUI::KeyCode::D;
        case sf::Keyboard::F: return MyGUI::KeyCode::F;
        case sf::Keyboard::G: return MyGUI::KeyCode::G;
        case sf::Keyboard::H: return MyGUI::KeyCode::H;
        case sf::Keyboard::J: return MyGUI::KeyCode::J;
        case sf::Keyboard::K: return MyGUI::KeyCode::K;
        case sf::Keyboard::L: return MyGUI::KeyCode::L;
        case sf::Keyboard::SemiColon: return MyGUI::KeyCode::Semicolon;
        case sf::Keyboard::Quote: return MyGUI::KeyCode::Apostrophe;
        case sf::Keyboard::Tilde: return MyGUI::KeyCode::Grave;
        case sf::Keyboard::LShift: return MyGUI::KeyCode::LeftShift;
        case sf::Keyboard::BackSlash: return MyGUI::KeyCode::Backslash;
        case sf::Keyboard::Z: return MyGUI::KeyCode::Z;
        case sf::Keyboard::X: return MyGUI::KeyCode::X;
        case sf::Keyboard::C: return MyGUI::KeyCode::C;
        case sf::Keyboard::V: return MyGUI::KeyCode::V;
        case sf::Keyboard::B: return MyGUI::KeyCode::B;
        case sf::Keyboard::N: return MyGUI::KeyCode::N;
        case sf::Keyboard::M: return MyGUI::KeyCode::M;
        case sf::Keyboard::Comma: return MyGUI::KeyCode::Comma;
        case sf::Keyboard::Period: return MyGUI::KeyCode::Period;
        case sf::Keyboard::Slash: return MyGUI::KeyCode::Slash;
        case sf::Keyboard::RShift: return MyGUI::KeyCode::RightShift;
        case sf::Keyboard::Multiply: return MyGUI::KeyCode::Multiply;
        case sf::Keyboard::LAlt: return MyGUI::KeyCode::LeftAlt;
        case sf::Keyboard::Space: return MyGUI::KeyCode::Space;
        case sf::Keyboard::F1: return MyGUI::KeyCode::F1;
        case sf::Keyboard::F2: return MyGUI::KeyCode::F2;
        case sf::Keyboard::F3: return MyGUI::KeyCode::F3;
        case sf::Keyboard::F4: return MyGUI::KeyCode::F4;
        case sf::Keyboard::F5: return MyGUI::KeyCode::F5;
        case sf::Keyboard::F6: return MyGUI::KeyCode::F6;
        case sf::Keyboard::F7: return MyGUI::KeyCode::F7;
        case sf::Keyboard::F8: return MyGUI::KeyCode::F8;
        case sf::Keyboard::F9: return MyGUI::KeyCode::F9;
        case sf::Keyboard::F10: return MyGUI::KeyCode::F10;
        case sf::Keyboard::Numpad7: return MyGUI::KeyCode::Numpad7;
        case sf::Keyboard::Numpad8: return MyGUI::KeyCode::Numpad8;
        case sf::Keyboard::Numpad9: return MyGUI::KeyCode::Numpad9;
        case sf::Keyboard::Subtract: return MyGUI::KeyCode::Subtract;
        case sf::Keyboard::Numpad4: return MyGUI::KeyCode::Numpad4;
        case sf::Keyboard::Numpad5: return MyGUI::KeyCode::Numpad5;
        case sf::Keyboard::Numpad6: return MyGUI::KeyCode::Numpad6;
        case sf::Keyboard::Add: return MyGUI::KeyCode::Add;
        case sf::Keyboard::Numpad1: return MyGUI::KeyCode::Numpad1;
        case sf::Keyboard::Numpad2: return MyGUI::KeyCode::Numpad2;
        case sf::Keyboard::Numpad3: return MyGUI::KeyCode::Numpad3;
        case sf::Keyboard::Numpad0: return MyGUI::KeyCode::Numpad0;
        case sf::Keyboard::F11: return MyGUI::KeyCode::F11;
        case sf::Keyboard::F12: return MyGUI::KeyCode::F12;
        case sf::Keyboard::F13: return MyGUI::KeyCode::F13;
        case sf::Keyboard::F14: return MyGUI::KeyCode::F14;
        case sf::Keyboard::F15: return MyGUI::KeyCode::F15;
        case sf::Keyboard::RControl: return MyGUI::KeyCode::RightControl;
        case sf::Keyboard::Divide: return MyGUI::KeyCode::Divide;
        case sf::Keyboard::RAlt: return MyGUI::KeyCode::RightAlt;
        case sf::Keyboard::Pause: return MyGUI::KeyCode::Pause;
        case sf::Keyboard::Home: return MyGUI::KeyCode::Home;
        case sf::Keyboard::Up: return MyGUI::KeyCode::ArrowUp;
        case sf::Keyboard::PageUp: return MyGUI::KeyCode::PageUp;
        case sf::Keyboard::Left: return MyGUI::KeyCode::ArrowLeft;
        case sf::Keyboard::Right: return MyGUI::KeyCode::ArrowRight;
        case sf::Keyboard::End: return MyGUI::KeyCode::End;
        case sf::Keyboard::Down: return MyGUI::KeyCode::ArrowDown;
        case sf::Keyboard::PageDown: return MyGUI::KeyCode::PageDown;
        case sf::Keyboard::Insert: return MyGUI::KeyCode::Insert;
        case sf::Keyboard::Delete: return MyGUI::KeyCode::Delete;
        case sf::Keyboard::LSystem: return MyGUI::KeyCode::LeftWindows;
        case sf::Keyboard::RSystem: return MyGUI::KeyCode::RightWindow;
        case sf::Keyboard::Menu: return MyGUI::KeyCode::AppMenu;
        default: return MyGUI::KeyCode::None;
    }
}

}

}