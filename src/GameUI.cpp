#include "GameUI.hpp"

#include <stdexcept>
#include <string>

#include <SFML/Graphics/Color.hpp>

GameUI::GameUI() {
    m_scoreText.setCharacterSize(100);
    m_scoreText.setFillColor(sf::Color::White);

    m_messageText.setCharacterSize(75);
    m_messageText.setFillColor(sf::Color::White);

    updateScore(0);
    setMessage("Press Enter to start!");
}

bool GameUI::loadFont(const std::string &fontPath) {
    if (!m_font.loadFromFile(fontPath)) {
        return false;
    }
    m_scoreText.setFont(m_font);
    m_messageText.setFont(m_font);
    return true;
}

void GameUI::updateScore(int newScore) { m_scoreText.setString("Score: " + std::to_string(newScore)); }

void GameUI::setScorePosition(float x, float y) { m_scoreText.setPosition(x, y); }

void GameUI::setMessagePosition(float x, float y) { m_messageText.setPosition(x, y); }

void GameUI::setMessage(const std::string &text) { m_messageText.setString(text); }

void GameUI::centerMessage() {
    if (m_font.getInfo().family.empty()) {
        throw std::logic_error("Font not loaded");
    }
    sf::FloatRect bounds = m_messageText.getLocalBounds();
    m_messageText.setOrigin(bounds.left + bounds.width / 2.0f, bounds.top + bounds.height / 2.0f);
}

void GameUI::showMessage(bool show) { m_showMessage = show; }

void GameUI::reset() {
    updateScore(0);
    showMessage(false);
    timebar.reset();
}

void GameUI::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(m_scoreText, states);
    if (m_showMessage) {
        target.draw(m_messageText, states);
    }
    target.draw(timebar);
}
