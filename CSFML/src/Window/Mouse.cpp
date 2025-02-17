#include "System/Vector2.hpp"
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Window.hpp>

extern "C" bool sfMouse_isButtonPressed(sf::Mouse::Button button) {
    return sf::Mouse::isButtonPressed(button);
}

extern "C" sfVector2i sfMouse_getPosition() {
    sf::Vector2i pos = sf::Mouse::getPosition();
    return {pos.x, pos.y};
}

extern "C" sfVector2i sfMouse_getPositionRelativeTo(const sf::Window *relativeTo) {
    sf::Vector2i pos = sf::Mouse::getPosition(*relativeTo);
    return {pos.x, pos.y};
}

extern "C" void sfMouse_setPosition(sfVector2i position) {
    sf::Mouse::setPosition(sf::Vector2i(position.x, position.y));
}

extern "C" void sfMouse_setPositionRelativeTo(sfVector2i pos, const sf::Window *relativeTo) {
    sf::Mouse::setPosition(sf::Vector2i(pos.x, pos.y), *relativeTo);
}
