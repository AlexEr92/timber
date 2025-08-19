#include "Bee.hpp"
#include "Clouds.hpp"
#include "GameUI.hpp"
#include "Tree.hpp"

#include <iostream>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>

int main() {
    // Create a video mode object
    sf::VideoMode vm(1920, 1080);

    // Create and open a window for the game
    sf::RenderWindow window(vm, "Timber", sf::Style::Default);
    // Set FPS limit
    window.setFramerateLimit(60);

    // Create background texture and sprite
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("assets/graphics/background.png")) {
        std::cerr << "Error when loading background texture" << std::endl;
        return -1;
    }

    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0, 0);

    // Create clouds
    Clouds clouds;
    if (!clouds.loadFromFile("assets/graphics/cloud.png")) {
        std::cerr << "Error when loading cloud texture" << std::endl;
        return -1;
    }
    clouds.spawnClouds(3);

    // Create a tree
    Tree tree;
    if (!tree.loadFromFile("assets/graphics/tree.png")) {
        std::cerr << "Error when loading tree texture" << std::endl;
        return -1;
    }
    tree.centerHorizontally(window);

    // Create a bee
    Bee bee;
    if (!bee.loadFromFile("assets/graphics/bee.png")) {
        std::cerr << "Error when loading bee texture" << std::endl;
        return -1;
    }
    bee.setPosition(0, 800);

    // Track whether the game is running
    bool paused = true;
    // Game score
    int score = 0;

    GameUI ui;
    if (!ui.loadFont("assets/fonts/KOMIKAP_.ttf")) {
        std::cerr << "Error when loading font" << std::endl;
        return -1;
    }
    ui.setScorePosition(20, 20);
    ui.setMessagePosition(1920 / 2.0f, 1080 / 2.0f);
    ui.centerMessage();
    ui.getTimebar().setup(6.0f, 400.0f, 80.0f, sf::Color::Red, sf::Vector2f(1920.0f / 2 - 200, 980.0f));

    sf::Clock clock;

    // Main game loop
    while (window.isOpen()) {

        // Event handling
        sf::Event event;
        while (window.pollEvent(event)) {
            if ((event.type == sf::Event::Closed) ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }

            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                paused = false;
                // Reset UI
                ui.reset();
                // Reset game clock
                clock.restart();
            }
        }


        if (!paused) {
            sf::Time dt = clock.restart();
            // Update timebar
            if (ui.getTimebar().update(dt.asSeconds())) {
                paused = true;
                ui.setMessage("Out of time");
                ui.showMessage(true);
                ui.centerMessage();
            }
            // Update game objects position
            clouds.update(dt.asSeconds());
            bee.update(dt.asSeconds());
        }

        // Clear everything from the last frame
        window.clear();

        // Draw game scene
        window.draw(backgroundSprite);
        window.draw(clouds);
        window.draw(tree);
        window.draw(bee);
        window.draw(ui);

        // Show everything we just draw
        window.display();
    }

    return 0;
}
