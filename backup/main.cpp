//
// Created by andoro on 2025-10-13.
//


#include "GenMaze.hpp"
#include <opencv2/opencv.hpp>
#include "BicycleTemp.hpp"

int main ()
{
    int mazeSize =100;
    const int cellPixels = 12;
    MazeGenerator gen(mazeSize);
    gen.generateRandomMaze();
    gen.setRandomStartGoal();
    gen.printStatistics();

    Bicycle car(50.0, 50.0, -M_PI/2.0);
    car.setVelocity(1.0);          // 1 m/s

    // === 3. Visualization Setup ===
    cv::Mat image = gen.visualize(cellPixels);

    double t = 0.0;
    // === 4. Main Simulation Loop ===
    while (t < 200.0)
    {
        const double dt = 0.05;
        // Physics
        car.setSteerCmd(0.005);  // rad/s steering rate
        car.step(dt);

        // === 5. Draw Maze ===

        // === 6. Draw Car ===
        auto [x, y, phi] = car.pose();
        cv::Point carPos(int(x * cellPixels), int(y * cellPixels));
        circle(image, carPos, 3, cv::Scalar(255, 0, 0), -1);

        // === 7. Display ===
        cv::imshow("Maze + Bicycle Simulation", image);
        cv::waitKey(10);

        t += dt;
    }
    cv::waitKey(0);
    return 0;
}
