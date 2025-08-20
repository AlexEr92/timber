#include "Log.hpp"

#include <SFML/System/Vector2.hpp>

bool Log::loadFromFile(const std::string &texturePath) {
    if (!m_texture.loadFromFile(texturePath)) {
        return false;
    }
    m_sprite.setTexture(m_texture);
    return true;
}

void Log::launch(Side direction) {
    m_isActive = true;

    switch (direction) {
    case Side::LEFT:
        m_speedX = -LOG_SPEED_X;
        break;
    case Side::RIGHT:
        m_speedX = LOG_SPEED_X;
        break;
    case Side::NONE:
        // Should not happen, but handle gracefully
        m_speedX = 0.f;
        break;
    }

    m_speedY = LOG_SPEED_Y;
    m_sprite.setPosition(LOG_START_X, LOG_START_Y);
}

void Log::update(float dt) {
    if (!m_isActive) {
        return;
    }

    m_sprite.move(m_speedX * dt, m_speedY * dt);

    if (isOutOfBounds()) {
        reset();
    }
}

void Log::reset() {
    m_isActive = false;
    m_speedX = 0.f;
    m_speedY = 0.f;
    m_sprite.setPosition(LOG_START_X, LOG_START_Y);
}

bool Log::isOutOfBounds() const {
    const sf::Vector2f pos = m_sprite.getPosition();
    return pos.x < -100 || pos.x > 2000;
}

void Log::draw(sf::RenderTarget &target, sf::RenderStates states) const { target.draw(m_sprite, states); }
