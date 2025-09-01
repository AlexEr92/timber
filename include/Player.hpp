#pragma once

#include "Side.hpp"

#include <string>

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>

class Player : public sf::Drawable {
public:
    Player(const std::string &texturePath, Side initialSide = Side::LEFT);

    // Set player position
    void setPosition(Side side);

    // Get current player position
    const sf::Vector2f &getPosition() const;

    // Get current position of player
    Side getCurrentSide();

    // Reset player to initial state
    void reset();

    // Hide player
    void hide();

private:
    sf::Texture m_texture; // Player texture
    sf::Sprite m_sprite;   // Player sprite
    Side m_playerSide;     // The side the player is on
    bool m_showPlayer;

    // SFML rendering callback
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
