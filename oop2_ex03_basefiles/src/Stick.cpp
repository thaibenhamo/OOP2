#include <iostream> 
//#include <random>
#include <chrono>
#include <thread>
#include "Stick.h"
#include <cmath>


const double PI = 3.14159265358979323846;

Stick::Stick() : m_highlight(false)
{
    //std::random_device rd;
    //std::mt19937 gen(rd());
    
    m_stick.setTexture(ResourcesManager::instance().getTexture("stick1"));
  
    //m_stick.setSize(sf::Vector2f(343.5f, 6.5f));

    // Generate random length for each stick
    //std::uniform_real_distribution<float> disLength(100.0f, 292.0f);
    //m_length = disLength(gen);
    m_length = (rand() % 192) + 100;
    m_stick.setSize(sf::Vector2f(m_length, 9.0f));
    m_angle = rand() % 360;
 
    m_stick.setRotation(m_angle);

    // Generate random position for each stick
    //std::uniform_real_distribution<float> disX(293.0f, 907.0f);
    //std::uniform_real_distribution<float> disY(293.0f, 507.0f);

    int randomX = (rand() % 614) + 293;
    int randomY = (rand() % 214) + 293;

    m_stick.setPosition(randomX, randomY);

    m_startPoint = sf::Vector2f(randomX, randomY);
    m_stick.setFillColor(sf::Color::White);
   
    // Assign random color and score to the stick
    int colorIndex = rand() % 5; // Generate a random index for color selection
    switch (colorIndex) 
    {
    case 0:
        m_stick.setFillColor(sf::Color::Black);
        m_score = 25;
        break;
    case 1:
        m_stick.setFillColor(sf::Color(150, 134, 255)); // Purple color
        m_score = 15;
        break;
    case 2:
        m_stick.setFillColor(sf::Color::Yellow);
        m_score = 6;
        break;
    case 3:
        m_stick.setFillColor(sf::Color::Green);
        m_score = 5;
        break;
    case 4:
        m_stick.setFillColor(sf::Color(255, 102, 130));
        m_score = 4;
        break;
    default:
        break;
    }

    // Debug output
    std::cout << "Stick position: " << randomX << ", " << randomY << " Score: " << m_score << std::endl;
}

void Stick::draw(sf::RenderWindow& window)
{
    if (m_highlight && m_flickerClock.getElapsedTime().asMilliseconds() < 500) 
    {
        m_stick.setOutlineColor(sf::Color::Yellow);
        m_stick.setOutlineThickness(-2);
    }
    else 
    {
        m_stick.setOutlineThickness(0);
    }
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
    // Get the initial start point of the stick
    /*sf::Vector2f startPoint = m_startPoint;

    // Calculate the rotation angle in radians
    float rotation = m_angle * PI / 180.0;

    // Apply rotation transformation
    int rotatedX = startPoint.x * cos(rotation) - startPoint.y * sin(rotation);
    float rotatedY = startPoint.x * sin(rotation) + startPoint.y * cos(rotation);
   
    // Return the transformed start point
    return sf::Vector2f(rotatedX, rotatedY); */
    return m_startPoint;
}

sf::Vector2f Stick::getEndPoint() const
{
    float rotation = (90 + m_angle) * PI / 180.0;
    int endPointX = m_startPoint.x + m_length * cos(rotation);
    int endPointy = m_startPoint.y + m_length * sin(rotation);

    return(sf::Vector2f(endPointX, endPointy));
}


bool Stick::canBePicked() const 
{
    return (m_sticksAbove.size() == 0);
}

bool Stick::contains(const sf::Vector2f& point) const 
{
    sf::Vector2f position = m_stick.getTransform().getInverse().transformPoint(point);
    return m_stick.getLocalBounds().contains(position);
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

void Stick::update() 
{
    if (m_highlight && m_flickerClock.getElapsedTime().asMilliseconds() >= 500) 
    {
        m_highlight = false;
    }
}

void Stick::flicker() 
{
    m_highlight = true;
    m_flickerClock.restart();
}


void Stick::removeStickAbove(Stick* stickAbove)
{
    m_sticksAbove.erase(std::remove(m_sticksAbove.begin(), m_sticksAbove.end(), stickAbove), m_sticksAbove.end());
}

void Stick::addStickAbove(Stick* stick)
{
    m_sticksAbove.push_back(stick);
}