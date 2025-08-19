#include "Player.hpp"

Player::Player() : m_playerSide{Side::LEFT}, m_showPlayer{false} {}

bool Player::loadFromFile(const std::string &texturePath) {
    if (!m_texture.loadFromFile(texturePath)) {
        return false;
    }
    m_sprite.setTexture(m_texture);
    return true;
}

void Player::setPosition(Side side) {
    switch (side) {
    case Side::LEFT:
        m_sprite.setPosition(580, 720);
        break;
    case Side::RIGHT:
        m_sprite.setPosition(1200, 720);
        break;
    default:
        reset();
        break;
    }
    m_playerSide = side;
}

void Player::reset() {
    setPosition(Side::LEFT);
    m_showPlayer = true;
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (m_showPlayer) {
        target.draw(m_sprite, states);
    }
}
