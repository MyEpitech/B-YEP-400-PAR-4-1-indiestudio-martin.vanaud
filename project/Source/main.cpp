/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-martin.vanaud
** File description:
** main
*/

// #include "Core.hpp"

// int main(void)
// {
//     Core core;

//     core.loop();
//     return 0;
// }

// Sans class

#include <iostream>
#include "raylib.h"

#define NUM_FRAMES_PER_LINE     5
#define NUM_LINES               5

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [textures] example - sprite explosion");

    InitAudioDevice();

    // Load explosion sound
    Sound fxBoom = LoadSound("Ressources/models/bomb/sounds/boom.wav");

    // Load explosion texture
    Texture2D explosion = LoadTexture("Ressources/models/bomb/explosion/explosion.png");

    // Init variables for animation
    std::cout << explosion.width << ", " << explosion.height << std::endl;
    float frameWidth = (float)(explosion.width/NUM_FRAMES_PER_LINE);   // Sprite one frame rectangle width
    float frameHeight = (float)(explosion.height/NUM_LINES);           // Sprite one frame rectangle height
    int currentFrame = 0;
    int currentLine = 0;

    Rectangle frameRec = { 0, 0, frameWidth, frameHeight };
    Vector2 position = { 0.0f, 0.0f };

    bool active = false;
    int framesCounter = 0;

    SetTargetFPS(120);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------

        // Check for mouse button pressed and activate explosion (if not active)
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT) && !active)
        {
            position = GetMousePosition();
            active = true;

            position.x -= frameWidth/2.0f;
            position.y -= frameHeight/2.0f;

            PlaySound(fxBoom);
        }

        // Compute explosion animation frames
        if (active)
        {
            framesCounter++;

            if (framesCounter > 2)
            {
                currentFrame++;

                if (currentFrame >= NUM_FRAMES_PER_LINE)
                {
                    currentFrame = 0;
                    currentLine++;

                    if (currentLine >= NUM_LINES)
                    {
                        currentLine = 0;
                        active = false;
                    }
                }

                framesCounter = 0;
            }
        }

        frameRec.x = frameWidth*currentFrame;
        frameRec.y = frameHeight*currentLine;
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            // Draw explosion required frame rectangle
            if (active) DrawTextureRec(explosion, frameRec, position, WHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(explosion);   // Unload texture
    UnloadSound(fxBoom);        // Unload sound

    CloseAudioDevice();

    CloseWindow();              // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}



// AVEC CLASS


// #include <iostream>
// #include <vector>
// #include <memory>
// #include "raylib.h"

// #define NUM_FRAMES_PER_LINE     5
// #define NUM_LINES               5

// class Explosion
// {
//     public:
//         Explosion(Vector2 position, Rectangle frameRec, float frameWidth, float frameHeight, int currentFrame, int currentLine)
//         {
//             // _fxBoom = LoadSound("Ressources/models/bomb/sounds/boom.wav");
//             // _explosion = LoadTexture("Ressources/models/bomb/explosion/explosion.png");
//             _frameWidth = frameWidth;
//             _frameHeight = frameHeight;
//             _currentFrame = currentFrame;
//             _currentLine = currentLine;
//             _position = position;
//             _frameRec = frameRec;
//         }
//         ~Explosion() { }
//         void setPosition(float x, float y)
//         {
//             _position.x = x;
//             _position.y = y;
//         }
//         void setFrameWidth(float width) { _frameWidth = width; }
//         void setFrameHeight(float height) { _frameHeight = height; }
//         void setCurrentFrame(int currentFrame) { _currentFrame = currentFrame; }
//         void setCurrentLine(int currentLine) { _currentLine = currentLine; }
//         void setFrameRec(float x, float y)
//         {
//             _frameRec.x = x;
//             _frameRec.y = y;
//         }

//         // Sound _fxBoom;
//         // Texture2D _explosion;
//         float _frameWidth;
//         float _frameHeight;
//         int _currentFrame;
//         int _currentLine;
//         Rectangle _frameRec;
//         Vector2 _position;
// };

// int main(void)
// {
//     // Initialization
//     //--------------------------------------------------------------------------------------
//     const int screenWidth = 800;
//     const int screenHeight = 450;

//     InitWindow(screenWidth, screenHeight, "raylib [textures] example - sprite explosion");

//     InitAudioDevice();

//     // Load explosion sound
//     Sound fxBoom = LoadSound("Ressources/models/bomb/sounds/boom.wav");

//     // Load explosion texture
//     Texture2D explosion = LoadTexture("Ressources/models/bomb/explosion/explosion.png");

//     // Init variables for animation
//     // explosion.width /= 10;
//     // explosion.height /= 10;
//     float frameWidth = (float)(explosion.width/NUM_FRAMES_PER_LINE);   // Sprite one frame rectangle width
//     float frameHeight = (float)(explosion.height/NUM_LINES);           // Sprite one frame rectangle height
//     int currentFrame = 0;
//     int currentLine = 0;

//     Rectangle frameRec = { 0, 0, frameWidth, frameHeight };
//     Vector2 position = { 0.0f, 0.0f };

//     bool active = false;
//     int framesCounter = 0;
//     std::vector<std::shared_ptr<Explosion>> explosions;

//     SetTargetFPS(120);
//     //--------------------------------------------------------------------------------------

//     // Main game loop
//     while (!WindowShouldClose())    // Detect window close button or ESC key
//     {
//         // Update
//         //----------------------------------------------------------------------------------

//         // Check for mouse button pressed and activate explosion (if not active)
//         if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
//         {
//             position = GetMousePosition();
//             // active = true;

//             position.x -= frameWidth / 2.0f;
//             position.y -= frameHeight / 2.0f;
//             explosions.push_back(std::unique_ptr<Explosion>(new Explosion(position, frameRec, frameWidth, frameHeight, currentFrame, currentLine)));

//             PlaySound(fxBoom);
//         }

//         // Compute explosion animation frames
//         for (int i = 0; i < explosions.size(); i++) {
//             framesCounter++;

//             if (framesCounter > 2)
//             {
//                 currentFrame++;

//                 if (currentFrame >= NUM_FRAMES_PER_LINE)
//                 {
//                     currentFrame = 0;
//                     currentLine++;

//                     if (currentLine >= NUM_LINES)
//                     {
//                         currentLine = 0;
//                         explosions.erase(explosions.begin() + i);
//                         i--;
//                     }
//                 }

//                 framesCounter = 0;
//             }
//             frameRec.x = frameWidth*currentFrame;
//             frameRec.y = frameHeight*currentLine;
//         }

//         //----------------------------------------------------------------------------------

//         // Draw
//         //----------------------------------------------------------------------------------
//         BeginDrawing();

//             ClearBackground(RAYWHITE);

//             // Draw explosion required frame rectangle
//             for (auto &item :explosions) {
//                 DrawTextureRec(explosion, frameRec, position, WHITE);
//             }

//         EndDrawing();
//         //----------------------------------------------------------------------------------
//     }

//     // De-Initialization
//     //--------------------------------------------------------------------------------------
//     UnloadTexture(explosion);   // Unload texture
//     UnloadSound(fxBoom);        // Unload sound

//     CloseAudioDevice();

//     CloseWindow();              // Close window and OpenGL context
//     //--------------------------------------------------------------------------------------

//     return 0;
// }
