/*
** EPITECH PROJECT, 2022
** B-YEP-400-PAR-4-1-indiestudio-martin.vanaud
** File description:
** Camera
*/

#include "Camera.hpp"

RayLib::CinematicCamera::CinematicCamera()
{
    // Define the camera to look into our 3d world
    Camera3D camera = { 0 };
    camera.position = (Vector3){ 0.0f, 100.0f, 10.0f };
    camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetCameraMode(camera, CAMERA_FREE); // Set a free camera mode

    _camera = camera;
}

RayLib::CinematicCamera::~CinematicCamera()
{
}

void RayLib::CinematicCamera::updateCamera()
{
    UpdateCamera(&_camera);
}

void RayLib::CinematicCamera::startMode3D()
{
    BeginMode3D(_camera);
}

void RayLib::CinematicCamera::endMode3D()
{
    EndMode3D();
}

void RayLib::CinematicCamera::setPosition(Position const &position)
{
    _camera.position = (Vector3){ position.getX(), position.getY() + 200, position.getZ() + 35 };
}

void RayLib::CinematicCamera::setTarget(Position const &position)
{
    _camera.target = (Vector3){ position.getX(), position.getY(), position.getZ() };
}
