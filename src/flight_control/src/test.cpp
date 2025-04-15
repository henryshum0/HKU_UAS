#include <iostream>
#include <cmath>

#include <Eigen/Dense>
#include <matplot/matplot.h>

using namespace Eigen;
using namespace std;


struct Target
{
    Vector2f pos;
    float force_draw = 10;

    // Constructor to initialize pos
    Target(const Vector2f& position) : pos(position) {}
};

struct Obstacle
{
    Vector2f pos;
    float dist_repel = 10;
    float force_repel = 10;

    Obstacle(const Vector2f& position) : pos(position) {}
};

struct Drone
{
    Vector2f pos, vel{0.,0.};
    float drag_factor = 2;

    Drone(const Vector2f& position) : pos(position) {}
};

int main()
{
    Target setpoint1(Vector2f(0.,10.));
    Drone drone1(Vector2f(0.,0.));
    Vector2f f_drag, f_draw;
    float dt = 0.01;
    vector<double> x_positions, y_positions;
    for (int i = 0; i<500; i++)
    {
        f_drag = - drone1.drag_factor * pow(drone1.vel.norm(),2)  * drone1.vel.normalized();
        f_draw = setpoint1.force_draw * (setpoint1.pos - drone1.pos).normalized();

        drone1.pos += drone1.vel * dt;
        drone1.vel += (f_draw + f_drag) * dt;

        x_positions.push_back(drone1.pos[0]);
        y_positions.push_back(drone1.pos[1]);
    }
    matplot::plot( y_positions);
    matplot::show();
    return 1;
}