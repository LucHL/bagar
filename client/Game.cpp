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
    InitWindow(_SCREEN_WIDTH, _SCREEN_HEIGHT, "BAGAR"); // TODO handle size in param
    InitAudioDevice();
    SetMasterVolume(_MUSIC_VOLUME); // TODO handle volume in param

    Camera3D &cam3 = data.getCam3D();
    cam3.position = (Vector3){ 4.0f, 4.0f, 4.0f };
    cam3.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    cam3.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    cam3.fovy = 45.0f;
    cam3.projection = CAMERA_PERSPECTIVE;

    Camera2D &cam2 = data.getCam2D();
    cam2.target = (Vector2){ 0.0f, 0.0f };
    cam2.offset = (Vector2){ 0.0f, 0.0f };
    cam2.rotation = 0.0f;
    cam2.zoom = 1.0f;
    SetTargetFPS(_FPS);

    ToggleFullscreen(); // TODO handle in param

    data.getCurrentScene() = scene.changeScene(MENU);
}

Game::~Game()
{
}

void Game::gameLoop()
{
    GlobalData &data = GlobalData::getInstance();

    while (!data.boolGameClose()) {

        data.getCurrentScene()->beforeDrawing();

        BeginDrawing();

            data.getCurrentScene()->beforeMode();

            BeginMode3D(data.getCam3D());
                data.getCurrentScene()->draw3D();
            EndMode3D();

            BeginMode2D(data.getCam2D());
                data.getCurrentScene()->draw2D();
            EndMode2D();

        EndDrawing();
    }
    CloseAudioDevice();
    CloseWindow();
}
