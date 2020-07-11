#include "imgui.h"
#include "imgui-SFML.h"
#include "./addons/imguitoolbar/imguitoolbar.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>

#ifdef WIN32
#include <Windows.h>
#endif

int main()
{

#ifdef WIN32
    auto hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_HIDE);
#endif

    sf::RenderWindow window(sf::VideoMode(640, 480), "Fusion View");
    window.setVerticalSyncEnabled(true);
    ImGui::SFML::Init(window);

    /**
    * Notes : Create a scenario class and scenario 
    *
    */
   
    sf::Color bgColor;

    float color[3] = { 0.f, 0.f, 0.f };

    window.resetGLStates(); // call it if you only draw ImGui. Otherwise not needed.
    static ImGui::Toolbar toolbar("myFirstToolbar##foo");

    sf::Clock deltaClock;
    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            ImGui::SFML::ProcessEvent(event);

            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        ImGui::SFML::Update(window, deltaClock.restart());

        ImGui::Begin("Sample window"); // begin window



        if (ImGui::BeginMainMenuBar())
        {
            if (ImGui::BeginMenu("File"))
            {
                if (ImGui::MenuItem("New"))
                {
                    //Do something
                }
                ImGui::EndMenu();
            }

            ImGui::EndMainMenuBar();
        }

                                       // Background color edit
        if (ImGui::ColorEdit3("Background color", color)) {
            // this code gets called if color value changes, so
            // the background color is upgraded automatically!
            bgColor.r = static_cast<sf::Uint8>(color[0] * 255.f);
            bgColor.g = static_cast<sf::Uint8>(color[1] * 255.f);
            bgColor.b = static_cast<sf::Uint8>(color[2] * 255.f);
        }

        ImGui::End(); // end window

        window.clear(bgColor); // fill background with color
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();
}