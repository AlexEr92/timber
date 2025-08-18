#include "Clouds.hpp"
#include "Tree.hpp"

#include <iostream>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>

int main() {
    // Create a video mode object
    sf::VideoMode vm(1920, 1080);

    // Create and open a window for the game
    sf::RenderWindow window(vm, "Timber", sf::Style::Default);

    // Create background texture and sprite
    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("assets/graphics/background.png");

    sf::Sprite backgroundSprite;
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0, 0);

    // Create clouds
    Clouds clouds;
    clouds.loadTexture("assets/graphics/cloud.png");
    clouds.spawnClouds(3);

    // Create a tree
    Tree tree;
    if (!tree.loadFromFile("assets/graphics/tree.png")) {
        std::cerr << "Error when loading tree texture" << std::endl;
        return -1;
    }
    tree.centerHorizontally(window);

    sf::Clock clock;

    // Main game loop
    while (window.isOpen()) {
        sf::Time dt = clock.restart();

        // Event handling
        sf::Event event;
        while (window.pollEvent(event)) {
            if ((event.type == sf::Event::Closed) ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }
        }

        // Update clouds position
        clouds.update(dt.asSeconds());

        // Clear everything from the last frame
        window.clear();

        // Draw game scene
        window.draw(backgroundSprite);
        window.draw(clouds);
        window.draw(tree);

        // Show everything we just draw
        window.display();
    }

    return 0;
}
