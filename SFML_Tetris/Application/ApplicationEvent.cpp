#include "ApplicationEvent.h"

bool ApplicationEvent::isKeyPressed(sf::Keyboard::Key key)
{
    return buttonPressList[key] == ButtonState::PRESS;
}

bool ApplicationEvent::isKeyHolding(sf::Keyboard::Key key)
{
    return buttonPressList[key] == ButtonState::HOLD;
}

bool ApplicationEvent::isKeyRelease(sf::Keyboard::Key key)
{
    return buttonPressList[key] == ButtonState::RELEASE;
}

bool ApplicationEvent::isMouseClick(sf::Mouse::Button button)
{
    return mouseClickList[button] == ButtonState::PRESS;
}

sf::Vector2i ApplicationEvent::getMousePos()
{
    return mousePos;
}

static void keyUpdate(ApplicationEvent::ButtonState* buttonList, size_t listSize) {
    for (int i = 0; i < listSize; i++) {
        ApplicationEvent::ButtonState& keyState = buttonList[i];
       
        if (keyState == ApplicationEvent::ButtonState::RELEASE)
            keyState = ApplicationEvent::ButtonState::UNTOUCH;
        if (keyState == ApplicationEvent::ButtonState::PRESS)
            keyState = ApplicationEvent::ButtonState::HOLD;
    }
}

void ApplicationEvent::update()
{
    keyUpdate(buttonPressList, sf::Keyboard::Key::KeyCount);
    keyUpdate(mouseClickList, sf::Mouse::Button::ButtonCount);

    sf::Event pollEvent;
    while (ApplicationWindow::getWindow().pollEvent(pollEvent)) {
        switch (pollEvent.type) {
        case sf::Event::KeyPressed:
            if (buttonPressList[pollEvent.key.code] == ButtonState::UNTOUCH)
                buttonPressList[pollEvent.key.code] = ButtonState::PRESS;
            break;
        case sf::Event::KeyReleased:
            buttonPressList[pollEvent.key.code] = ButtonState::RELEASE;
            break;
        case sf::Event::MouseButtonPressed:
            mouseClickList[pollEvent.mouseButton.button] = ButtonState::PRESS;
            break;
        case sf::Event::MouseButtonReleased:
            mouseClickList[pollEvent.mouseButton.button] = ButtonState::RELEASE;
            break;
        case sf::Event::Closed:
            ApplicationWindow::getWindow().close();
            break;
        }
    }
    mousePos = { pollEvent.mouseButton.x, pollEvent.mouseButton.y };

    updateTime();
}

sf::Font& ApplicationEvent::getFont()
{
    static bool done = false;
    if (done) {
        return font;
    }
    font.loadFromFile("font/font.ttf");
    done = true;
    return getFont();
}

const float& ApplicationEvent::getDeltaTime()
{
    return deltaTime;
}

void ApplicationEvent::updateTime()
{
    static sf::Clock windowClock;

    deltaTime = windowClock.restart().asSeconds();
}
