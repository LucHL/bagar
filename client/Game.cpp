/*
** EPITECH PROJECT, 2024
** bagar
** File description:
** Game
*/

#include "Game.hpp"

Game::Game()
{
    GlobalData &data = GlobalData::getInstance();
    SceneManager &scene = SceneManager::getInstance();
    InitWindow(1920, 1080, "BAGAR");
    InitAudioDevice();
    SetMasterVolume(10);

    Camera3D &cam3 = data.getCam3D();
    cam3.position = (Vector3){ 0.0f, 6.0f, 0.0f };
    cam3.target = (Vector3){ 0.0f, 1.0f, 0.0f };
    cam3.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    cam3.fovy = 45.0f;
    cam3.projection = CAMERA_PERSPECTIVE;

    Camera2D &cam2 = data.getCam2D();
    cam2.target = (Vector2){ 0.0f, 0.0f };
    cam2.offset = (Vector2){ 0.0f, 0.0f };
    cam2.rotation = 0.0f;
    cam2.zoom = 1.0f;
    SetTargetFPS(60);

    _currentScene = scene.changeScene(MENU);
}

Game::~Game()
{
}

void Game::gameLoop()
{
    GlobalData &data = GlobalData::getInstance();

    while (!data.boolGameClose()) {

        if (IsKeyPressed(KEY_ESCAPE))
            data.boolGameClose() = true;

        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(data.getCam3D());
                _currentScene->draw3D();
            EndMode3D();

            BeginMode2D(data.getCam2D());
                _currentScene->draw2D();
            EndMode2D();

        EndDrawing();
    }
    CloseAudioDevice();
    CloseWindow();
}
