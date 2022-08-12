//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2018 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//

#include "System/Vector2.h"
#include <SFML/Window/Cursor.hpp>
#include <cstddef>
#include <cstdint>

extern "C" sf::Cursor *sfCursor_createFromPixels(const uint8_t *pixels, sfVector2u size, sfVector2u hotspot) {
    sf::Cursor *cursor = new sf::Cursor;

    if (!cursor->loadFromPixels(pixels, sf::Vector2u(size.x, size.y), sf::Vector2u(hotspot.x, hotspot.y))) {
        delete cursor;
        cursor = NULL;
    }

    return cursor;
}

extern "C" sf::Cursor *sfCursor_createFromSystem(sf::Cursor::Type type) {
    sf::Cursor *cursor = new sf::Cursor;

    if (!cursor->loadFromSystem(type)) {
        delete cursor;
        cursor = NULL;
    }

    return cursor;
}

extern "C" void sfCursor_destroy(sf::Cursor *cursor) {
    delete cursor;
}
