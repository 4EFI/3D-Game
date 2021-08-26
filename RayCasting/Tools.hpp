#ifndef TOOLS
#define TOOLS

//-----------------------------------------------------------------------------

sf::Vector2f GetCursorPosition(sf::RenderWindow &window);

bool IsInsideRect(sf::Vector2f cursorPosition, sf::RectangleShape *rectangle);

//-----------------------------------------------------------------------------

sf::Vector2f GetCursorPosition(sf::RenderWindow &window)
{
    sf::Vector2f cursorPosition;

    cursorPosition = (sf::Vector2f)sf::Mouse::getPosition(window);
    cursorPosition = window.mapPixelToCoords((sf::Vector2i)cursorPosition);

    return cursorPosition;
}

//-----------------------------------------------------------------------------

bool IsInsideRect(sf::Vector2f cursorPosition, sf::RectangleShape *rectangle)
{
    sf::Vector2f position = rectangle->getPosition();
    sf::Vector2f size     = rectangle->getSize();
    sf::Vector2f scale    = rectangle->getScale();

    size = { size.x * scale.x, size.y * scale.y };

    if(cursorPosition.x >= position.x && cursorPosition.x <= position.x + size.x &&
       cursorPosition.y >= position.y && cursorPosition.y <= position.y + size.y)
    {
        return 1;
    }

    return 0;
}

//-----------------------------------------------------------------------------

#endif
