#include <iostream> 
#include <random>
#include <chrono>
#include <thread>
#include "Stick.h"

Stick::Stick()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    // Set texture, scale, and origin
    m_stick.setTexture(*(ResourcesManager::instance().getTexture("stick1")));
  
    m_stick.setScale(sf::Vector2f(0.4f, 0.4f));
 

    // Set rotation
    m_stick.setRotation(float(gen() % 360));

    // Generate random position for each stick
    std::uniform_real_distribution<float> disX(276.0f, 924.0f);
    std::uniform_real_distribution<float> disY(276.0f, 524.0f);
    float randomX = disX(gen);
    float randomY = disY(gen);
    m_stick.setPosition(randomX, randomY);

    // Assign random color and score to the stick
    int colorIndex = gen() % 5; // Generate a random index for color selection
    switch (colorIndex) 
    {
    case 0:
        m_stick.setColor(sf::Color::Black);
        m_score = 25;
        break;
    case 1:
        m_stick.setColor(sf::Color(128, 0, 128)); // Purple color
        m_score = 15;
        break;
    case 2:
        m_stick.setColor(sf::Color::Yellow);
        m_score = 6;
        break;
    case 3:
        m_stick.setColor(sf::Color::Green);
        m_score = 5;
        break;
    case 4:
        m_stick.setColor(sf::Color::Red);
        m_score = 4;
        break;
    default:
        break;
    }

    // Debug output
    std::cout << "Stick position: " << randomX << ", " << randomY << " Score: " << m_score << std::endl;
}

void Stick::draw(sf::RenderWindow& window) const 
{
    window.draw(m_stick);
}

bool Stick::intersects(const Stick& other) const 
{
    sf::Vector2f p1 = getStartPoint();
    sf::Vector2f q1 = getEndPoint();
    sf::Vector2f p2 = other.getStartPoint();
    sf::Vector2f q2 = other.getEndPoint();

    auto onSegment = [](sf::Vector2f p, sf::Vector2f q, sf::Vector2f r) 
        {
        return (q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
                q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y));
        };

    auto orientation = [](sf::Vector2f p, sf::Vector2f q, sf::Vector2f r) 
        {
        float val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
        if (val == 0) return 0;  // collinear
        return (val > 0) ? 1 : 2; // clock or counterclock wise
        };

    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4) return true;

    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;
}

sf::Vector2f Stick::getStartPoint() const 
{
    return m_stick.getPosition();
}

sf::Vector2f Stick::getEndPoint() const 
{
    sf::FloatRect bounds = m_stick.getGlobalBounds();
    return sf::Vector2f(bounds.left + bounds.width, bounds.top + bounds.height);
}

bool Stick::canBePicked() const 
{
    return m_sticksAbove.empty();
}

bool Stick::contains(const sf::Vector2f& point) const 
{
    return m_stick.getGlobalBounds().contains(point);
}

void Stick::checkAndFlickerAboveSticks() 
{
    // Check if there are sticks above
    if (!m_sticksAbove.empty()) 
    {
        // Flicker each stick above
        for (auto& aboveStick : m_sticksAbove) 
        {
            aboveStick->flicker();
        }
    }
}

void Stick::flicker() 
{
    // Save the original color of the stick
    sf::Color originalColor = m_stick.getColor();

    // Change the color of the stick to indicate flickering (e.g., change to black)
    m_stick.setColor(sf::Color::Black);

    // Wait for a short duration to create flicker effect (you may need to include <thread> and <chrono> headers)
    std::this_thread::sleep_for(std::chrono::milliseconds(200)); // Adjust the duration as needed

    // Restore the original color of the stick
    m_stick.setColor(originalColor);
}

void Stick::removeStickAbove(Stick* stick) 
{
    m_sticksAbove.remove(stick);
}