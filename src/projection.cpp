#include "projection.h"
#include "math.h" // replace with own later

Vec3f projectCamera(const Vec3f &camera, int screenWidth, int screenHeight, float fov = 90.0f, float near  = 1.0f)
{
    float screenX = near * camera.x / (-camera.z);
    float screenY = near * camera.y / (-camera.z);

    // review canvas (confused)
    float aspectRatio = (float)screenWidth / screenHeight;
    float canvasHeight = 2 * near * tan(fov * M_PI / 180.0f / 2);
    float canvasWidth = canvasHeight * aspectRatio;

    // normalized pos in [-1, 1]
    float t = canvasHeight / 2;
    float b = -canvasHeight / 2;
    float r = canvasWidth / 2;
    float l = -canvasWidth / 2;
    float ndcX = 2 * screenX / (r - l) - (r + l) / (r - l);
    float ndcY = 2 * screenY / (t - b) - (t + b) / (t - b);

    float rasterX = (ndcX + 1) / 2 * screenHeight;
    float rasterY = (1 - ndcY) / 2 * screenWidth; // SDL y is down

    float rasterZ = -camera.z;


    return Vec3f(rasterX, rasterY, rasterZ);
}