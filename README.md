# MathCourse
Math course with 5 examples made in unreal engine 

Task 1 State: There are two cubes in the scene at game start the state is printed on screen with one cube being relative to the other, printing if its in front or behind
and if its below or above

Task 2 Interpolation:Player is able to dash forward with space barm interpolating player's position forward.

Task 3 Intersection : There are two actors with green debug spheres on them. Moving these objects in run-time detects their intersection printing to screen.
 Intersection is detected in the intersection manager actor in scene 

 
Task 4 Collision: Similar idea as Intersection now with red spheres. However I couldn't finish it i C++ so the logic for moving objects out of each other is done in blueprints ,
Collision is detected in the intersection manager actor in scene through C++ and applied in blueptint of that actor.

Task 5 Noise: I created a series of proceduraally generated platforms that can be seen in scene. I had issues with importing pacakges in C++ so I couldnt use a proceduralmesh 
package in C++ so I did all of the logic in blueprint. I also used a plugin for better noise called simplexnoise https://github.com/devdad/SimplexNoise. I used noise for Z position
of the platforms to make them randomized