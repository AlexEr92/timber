#include "Timebar.hpp"

Timebar::Timebar() : m_totalTime{0}, m_remainingTime{0}, m_initialWidth{0} {}

void Timebar::setup(float totalTime, float width, float height, const sf::Color &color, const sf::Vector2f &position) {
    m_totalTime = totalTime;
    m_remainingTime = totalTime;
    m_initialWidth = width;

    m_bar.setSize(sf::Vector2f(width, height));
    m_bar.setPosition(position);
    m_bar.setPosition(position);
}

bool Timebar::update(float dt) {
    m_remainingTime -= dt;
    m_remainingTime = std::max(0.0f, m_remainingTime);

    float progress = m_remainingTime / m_totalTime;
    m_bar.setSize(sf::Vector2f(m_initialWidth * progress, m_bar.getSize().y));

    return isTimeUp();
}

bool Timebar::isTimeUp() const { return m_remainingTime <= 0.0f; }

void Timebar::reset() {
    m_remainingTime = m_totalTime;
    m_bar.setSize(sf::Vector2f(m_initialWidth, m_bar.getSize().y));
}

void Timebar::setColor(const sf::Color &color) { m_bar.setFillColor(color); }

void Timebar::setPosition(const sf::Vector2f &position) { m_bar.setPosition(position); }

void Timebar::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(m_bar, states);
}
