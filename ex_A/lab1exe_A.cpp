/*
 *  File Name: lab1exe_A.cpp
 *  Assignment: ENSF 694 Lab 1, exercise A
 *  Created by: Mahmood Moussavi
 *  Completed by: Yael Gonzalez
 *  Submission Date: July 3, 2024
 */

#include <iostream>
#include <cmath>
#include <format>
using namespace std;

const double G = 9.8; /* gravitation acceleration 9.8 m/s^2 */
const double PI = 3.141592654;

void create_table(double v);
double Projectile_travel_time(double a, double v);
double Projectile_travel_distance(double a, double v);
double degree_to_radian(double d);

int main(void)
{
    double velocity;

    cout << "Please enter the velocity at which the projectile is launched (m/sec): ";
    cin >> velocity;

    if (!cin) // means if cin failed to read
    {
        cout << "Invalid input. Bye...\n";
        exit(1);
    }

    while (velocity < 0)
    {
        cout << "\nplease enter a positive number for velocity: ";
        cin >> velocity;
        if (!cin)
        {
            cout << "Invalid input. Bye...";
            exit(1);
        }
    }

    create_table(velocity);
    return 0;
}

/**
 * Prints a table showing projectile distance (d) and time (t) of flight for angles from 0 to 90 degrees.
 * @param v The initial velocity of the projectile in meters per second
 */
void create_table(double v)
{
    // Add column headers (names) and subheaders (units)
    cout << format("{:<10} {:<10} {:<10}\n", "Angle", "t", "d");
    cout << format("{:<10} {:<10} {:<10}\n", "(deg)", "(sec)", "(m)");

    // Iterate over angles from 0 to 90 degrees in steps of 5 degrees
    for (int deg = 0; deg <= 90; deg += 5)
    {
        // Convert degrees to radians
        double rad = degree_to_radian(deg);
        // Calculate time of flight
        double time = Projectile_travel_time(rad, v);
        // Calculate distance traveled
        double distance = Projectile_travel_distance(rad, v);

        // Print in console the angle, time, and distance
        cout << format("{:<10} {:<10.6f} {:<10.6f}\n",
                       deg,
                       time,
                       // Ensure distance is not negative (happens in 90°)
                       (distance < 0.0000001) ? 0.000000 : distance);
    }
}

/**
 * Calculates the time of flight (t) for a projectile.
 * @param a The launch angle
 * @param v The initial velocity
 * @return The time of flight
 */
double Projectile_travel_time(double a, double v)
{
    return 2 * v * sin(a) / G;
}

/**
 * Calculates the horizontal distance traveled (d) by a projectile.
 * @param a The launch angle
 * @param v The initial velocity
 * @return The horizontal distance traveled
 */
double Projectile_travel_distance(double a, double v)
{
    return (pow(v, 2.0) / G) * sin(2 * a);
}

/**
 * Converts an angle in degrees to radians.
 * @param d The angle in degrees
 * @return The converted angle in radians
 */
double degree_to_radian(double d)
{
    return d * PI / 180;
}
