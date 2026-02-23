#include <iostream>
#include <raylib.h>
#include <deque>
#include <raymath.h>

using namespace std;

static bool allowMove = false;
Color green = {200, 230, 201, 255};
Color darkGreen = {43, 51, 24, 255};

int cellSize = 30;
int cellCount = 25;
int offset = 75;

double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}

class Snake
{
public:
    deque<Vector2> body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    Vector2 direction = {1, 0};

    void Draw()
    {
        for (unsigned int i = 0; i < body.size(); i++)
        {
            float x = body[i].x;
            float y = body[i].y;
            Rectangle segment = Rectangle{offset + x * cellSize, offset + y * cellSize, (float)cellSize, (float)cellSize};
            DrawRectangleRounded(segment, 0.5, 6, darkGreen);
        }
    }

    void Update()
    {
        body.push_front(Vector2Add(body[0], direction));
        body.pop_back();
    }
};

int main()
{
    cout << "Starting the game..." << endl;
    InitWindow(2 * offset + cellSize * cellCount,
               2 * offset + cellSize * cellCount,
               "Snake Game");
    SetTargetFPS(60);

    Snake snake;

    while (WindowShouldClose() == false)
    {
        BeginDrawing();

        if (EventTriggered(0.2))
        {
            allowMove = true;
            snake.Update();
        }

        if (IsKeyPressed(KEY_UP) && snake.direction.y != 1 && allowMove)
        {
            snake.direction = {0, -1};
            allowMove = false;
        }
        if (IsKeyPressed(KEY_DOWN) && snake.direction.y != -1 && allowMove)
        {
            snake.direction = {0, 1};
            allowMove = false;
        }
        if (IsKeyPressed(KEY_LEFT) && snake.direction.x != 1 && allowMove)
        {
            snake.direction = {-1, 0};
            allowMove = false;
        }
        if (IsKeyPressed(KEY_RIGHT) && snake.direction.x != -1 && allowMove)
        {
            snake.direction = {1, 0};
            allowMove = false;
        }

        ClearBackground(green);

        DrawRectangleLinesEx(
            Rectangle{(float)offset - 5, (float)offset - 5,
            (float)cellSize * cellCount + 10,
            (float)cellSize * cellCount + 10},
            5, darkGreen);

        DrawText("Snake Game", offset - 5, 20, 40, darkGreen);

        snake.Draw();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}