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
    sf::FloatRect bounds = m_sprite.getLocalBounds();
    switch (side) {
    case Side::LEFT:
        m_sprite.setPosition(580 + bounds.width / 2, 720 + bounds.height / 2);
        m_sprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
        m_sprite.setScale(-1.f, 1.f);
        break;
    case Side::RIGHT:
        m_sprite.setPosition(1200 + bounds.width / 2, 720 + bounds.height / 2);
        m_sprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
        m_sprite.setScale(1.f, 1.f);
        break;
    default:
        reset();
        break;
    }
    m_playerSide = side;
}

const sf::Vector2f &Player::getPosition() const { return m_sprite.getPosition(); }

Side Player::getCurrentSide() { return m_playerSide; }

void Player::reset() {
    setPosition(Side::LEFT);
    m_showPlayer = true;
}

void Player::hide() { m_showPlayer = false; }

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    if (m_showPlayer) {
        target.draw(m_sprite, states);
    }
}
