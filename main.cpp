#include <iostream>
#include <SFML/Graphics.hpp>

// Constants
const sf::Color BACKGROUND_COLOR = sf::Color::Black;
const sf::Color DIVIDER_COLOR = sf::Color::White;
const sf::Color BUTTON_TEXT_COLOR(255, 51, 141); // #FF338D

// GUI elements
sf::RenderWindow window(sf::VideoMode(800, 600), "WikiVoyager");
sf::RectangleShape mainArea;
sf::RectangleShape sidebar;
sf::RectangleShape divider;
sf::Text menuButton;
sf::Text randomButton;
sf::Text aboutButton;
sf::Text quitButton;
sf::Text savedButton;
sf::Text backButton;
sf::Text translateButton;
sf::Text saveButton;

// Load icons and fonts
sf::Texture sideIcon;
sf::Texture savedIcon;
sf::Texture menuIcon;
sf::Texture randomIcon;
sf::Texture aboutIcon;
sf::Texture quitIcon;
sf::Texture backIcon;
sf::Texture translateIcon;
sf::Texture savedPageIcon;
sf::Texture unsavedPageIcon;
sf::Font font;

// GUI state
bool sidebarVisible = false;
bool savedSidebarVisible = false;
bool pageSaved = false;

// Function prototypes
void handleMenuButtonClick();
void handleRandomButtonClick();
void handleAboutButtonClick();
void handleQuitButtonClick();
void handleSavedButtonClick();
void handleBackButtonClick();
void handleTranslateButtonClick();
void handleSaveButtonClick();

// Initialize GUI elements
void initializeGUI()
{
    mainArea.setSize(sf::Vector2f(800, 500));
    mainArea.setFillColor(BACKGROUND_COLOR);

    sidebar.setSize(sf::Vector2f(200, 500));
    sidebar.setFillColor(BACKGROUND_COLOR);

    divider.setSize(sf::Vector2f(2, 500));
    divider.setFillColor(DIVIDER_COLOR);

    font.loadFromFile("font.ttf");

    menuButton.setFont(font);
    menuButton.setCharacterSize(16);
    menuButton.setFillColor(BUTTON_TEXT_COLOR);
    menuButton.setString("Menu");
    menuButton.setPosition(10, 10);

    randomButton.setFont(font);
    randomButton.setCharacterSize(16);
    randomButton.setFillColor(BUTTON_TEXT_COLOR);
    randomButton.setString("Random");
    randomButton.setPosition(10, 50);

    aboutButton.setFont(font);
    aboutButton.setCharacterSize(16);
    aboutButton.setFillColor(BUTTON_TEXT_COLOR);
    aboutButton.setString("About");
    aboutButton.setPosition(10, 90);

    quitButton.setFont(font);
    quitButton.setCharacterSize(16);
    quitButton.setFillColor(BUTTON_TEXT_COLOR);
    quitButton.setString("Quit");
    quitButton.setPosition(10, 130);

    savedButton.setFont(font);
    savedButton.setCharacterSize(16);
    savedButton.setFillColor(BUTTON_TEXT_COLOR);
    savedButton.setString("Saved");
    savedButton.setPosition(10, 50);

    backButton.setFont(font);
    backButton.setCharacterSize(16);
    backButton.setFillColor(BUTTON_TEXT_COLOR);
    backButton.setString("Back");
    backButton.setPosition(10, 10);

    translateButton.setFont(font);
    translateButton.setCharacterSize(16);
    translateButton.setFillColor(BUTTON_TEXT_COLOR);
    translateButton.setString("Translate");
    translateButton.setPosition(590, 520);

    saveButton.setFont(font);
    saveButton.setCharacterSize(16);
    saveButton.setFillColor(BUTTON_TEXT_COLOR);
    saveButton.setString("Save");
    saveButton.setPosition(10, 520);

    sideIcon.loadFromFile("bin/icons/side.ico");           // Done
    savedIcon.loadFromFile("bin/icons/nsaved.ico");        // Done
    menuIcon.loadFromFile("bin/icons/menu.ico");           // Done
    randomIcon.loadFromFile("bin/icons/random.ico");       // Done
    aboutIcon.loadFromFile("bin/icons/about.ico");         // Done
    quitIcon.loadFromFile("bin/icons/quit.ico");           // Done
    backIcon.loadFromFile("bin/icons/back.ico");           // Done
    translateIcon.loadFromFile("bin/icons/translate.ico"); // Done
    savedPageIcon.loadFromFile("bin/icons/saved.ico");     // Done
    unsavedPageIcon.loadFromFile("bin/icons/nsaved.ico");  // Done
}

// Handle GUI events
void handleEvents()
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        else if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f convertedMousePos = window.mapPixelToCoords(mousePos);

                if (sidebarVisible)
                {
                    if (menuButton.getGlobalBounds().contains(convertedMousePos))
                        handleMenuButtonClick();
                    else if (randomButton.getGlobalBounds().contains(convertedMousePos))
                        handleRandomButtonClick();
                    else if (aboutButton.getGlobalBounds().contains(convertedMousePos))
                        handleAboutButtonClick();
                    else if (quitButton.getGlobalBounds().contains(convertedMousePos))
                        handleQuitButtonClick();
                }
                else if (savedSidebarVisible)
                {
                    if (backButton.getGlobalBounds().contains(convertedMousePos))
                        handleBackButtonClick();
                }
                else
                {
                    if (savedButton.getGlobalBounds().contains(convertedMousePos))
                        handleSavedButtonClick();
                    else if (translateButton.getGlobalBounds().contains(convertedMousePos))
                        handleTranslateButtonClick();
                    else if (saveButton.getGlobalBounds().contains(convertedMousePos))
                        handleSaveButtonClick();
                }
            }
        }
    }
}

// Render the GUI
void render()
{
    window.clear(BACKGROUND_COLOR);

    window.draw(mainArea);

    if (sidebarVisible)
    {
        window.draw(sidebar);
        window.draw(menuButton);
        window.draw(randomButton);
        window.draw(aboutButton);
        window.draw(quitButton);
    }
    else if (savedSidebarVisible)
    {
        window.draw(sidebar);
        window.draw(backButton);
    }
    else
    {
        window.draw(savedButton);
        window.draw(translateButton);
        window.draw(saveButton);
    }

    window.draw(divider);

    window.display();
}

// Handle "Menu" button click
void handleMenuButtonClick()
{
    // TODO: Implement the logic for the "Menu" button
    std::cout << "Menu button clicked!" << std::endl;
}

// Handle "Random" button click
void handleRandomButtonClick()
{
    // TODO: Implement the logic for the "Random" button
    std::cout << "Random button clicked!" << std::endl;
}

// Handle "About" button click
void handleAboutButtonClick()
{
    // TODO: Implement the logic for the "About" button
    std::cout << "About button clicked!" << std::endl;
}

// Handle "Quit" button click
void handleQuitButtonClick()
{
    // TODO: Implement the logic for the "Quit" button
    std::cout << "Quit button clicked!" << std::endl;
    window.close();
}

// Handle "Saved" button click
void handleSavedButtonClick()
{
    // TODO: Implement the logic for the "Saved" button
    std::cout << "Saved button clicked!" << std::endl;
    savedSidebarVisible = true;
    sidebarVisible = false;
}

// Handle "Back" button click
void handleBackButtonClick()
{
    // TODO: Implement the logic for the "Back" button
    std::cout << "Back button clicked!" << std::endl;
    savedSidebarVisible = false;
    sidebarVisible = true;
}

// Handle "Translate" button click
void handleTranslateButtonClick()
{
    // TODO: Implement the logic for the "Translate" button
    std::cout << "Translate button clicked!" << std::endl;
}

// Handle "Save" button click
void handleSaveButtonClick()
{
    // TODO: Implement the logic for the "Save" button
    std::cout << "Save button clicked!" << std::endl;
    pageSaved = !pageSaved;
}

int main()
{
    initializeGUI();

    while (window.isOpen())
    {
        handleEvents();
        render();
    }

    return 0;
}
