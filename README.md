# Ray-Casting

I will explain here the formulas that I have used to implement the ray-casting. This raycast has been made in order to create a 3D game [Cub3D](https://github.com/Saxsori/cub3d) feel free to check the full project.
## Introduction
The idea of the raycasting in general is easy and the formulas isn't that complicated. I will explain what kind of calaculation I used to create, draw, and move around the walls.

Well let me firstly tell you what are the math concepts that I have used in the formulas. Right triangle trigonometry (SOHCAHTOA), Components of a Vector (X , Y), and Vector quantity (magnitude and direction). 

## Main Idea
In order to explain the main idea of the formulas, let's say that we have the player's postion on a 2D map (x, y) coordinates. The player is looking at the wall in front of him (NORTH), let's say the looking angle is 90 which is straight to north. The distance from his coordinate to the point of the wall called a ray. Depending on the player's [FOV](https://www.techtarget.com/whatis/definition/field-of-view-FOV) the number of the rays will be decided. If the FOV is 120 then his looking width will be 60 degrees to the left and 60 degrees to the right from the looking angle (90).

#### Well where are we going to use the vectors?

Using the player's coordinate and his looking angle we can calculate the ray's vector (X and Y components). Then calculate the offset (gridline outlier) the points where the rays could hit vertically and horizontally till the point of the wall.

## GridLine Hit Checkers
Each time the ray will hit a grid line horizontally or vertically, that point actually should be the position where we can check if it's a wall or not. To do that we firstly need to know how to calculate the ray's vector using the player's coordinates, then add some calculated values (Grid offset) to hit each grid line in order to reach the wall grid line.

![alt text](https://github.com/Saxsori/ray-cast/blob/main/images/1.png)

Horizontal Grid Lines is the (NORTH & SOUTH), or the upper and the lower sides of a 2d map. Vertical Grid Lines is the (WEST & EAST), or the left and the right sides of a 2d map.
Depending on the looking angle of the player we can decide where the ray is actually hitting vertically (left-right) or horizontally (up-down). Before that We actually need to understand how we can calculate the ray's line and the ray's vector.

Let's explain how we can get the formulas in general (ray's vectors)..
First thing to know is in order to get the ray's X and Y components (ray Y and ray X). We can use the rule of the right triangle.

This in example on how it should look like on a 2D map. I used [desmos](https://www.desmos.com/calculator/rhdvs6uffp) to plot them out. And I added the offset manually for the looking angle 60. The orange points are the upper side, the green points are the lower side, the black points are the left side, and the purple points are the right side. 

<img width="635" alt="Screen Shot 2022-08-27 at 7 37 59 AM" src="https://user-images.githubusercontent.com/92129820/187012948-2590fd02-a71b-461b-bd28-6a7101aa5ac4.png">

### Horizontal Gridline

To calculate the horizontal gridline checker formulas. We can follow these steps :

- The ray Y point should be the player's Y coordinate.

- Then to get the ray X point we can use the right triangle rules (SOHCAHTOA). The ray line would be Hypotenuse, the Opposite is the difference between the player Y coordinate and Ray Y point and the Adjacent is the ray X component which we are trying to find. So ray X is tan(looking angle) / opposite.

 ![alt text](https://github.com/Saxsori/ray-cast/blob/main/images/4.png) 
 
To scale them to the size of the grid (64) :

- The ray Y you should firstly scale the player's Y point to 64 unit. ((pY / 64) * 64);
- The ray X should had the player's X coordinate. (+ pX);

To make them hitting the next horizontal grid line we need to add a parameter :

- The ray Y point should had the distance from the player position to the next horizontal grid line (the difference between the player Y coordinate and the next Y line) so that it can hit the next horizontal gridline.

The formula when the player is looking (North) should finally look like this ..

#### rayY = ((pY / 64) * 64) + (Y.line - pY);

#### rayX = (pY - rayY) / -tan(looking angle) + pX;


If the player was looking (South) the direction is horizontally different now so the signs will be only changed

#### rayY = ((pY / 64) * 64) - (Y.line - pY);

#### rayX = (pY - rayY) / -tan(looking angle) + pX;


### Vertical Gridline 

To check the vertical grid line hit, it will be the same but opposite. The calculation will depend only on the ray Y where it could hit the Y lines. Previously on the horizontal checkers it was depending on the ray X where it can hit on the X lines

So the formula will be changed to this ..

If the player was looking to the East

#### rayX = ((pX / 64) * 64) + (X.line - pX);

#### rayY = (pX - rayX) / -tan(looking angle) + pY;

If the player was looking to the west the direction is now changes so the signs will be changed again.

#### rayX = ((pX / 64) * 64) - (X.line - pX);

#### rayY = (pX - rayX) / -tan(looking angle) + pY;

### Gridline Offset

(Offset) the value to add each time to hit the next grid line.

Offset basically means the amount or a value by which the calculation is out of line or where it could hit the outlier. And here it means the value to add each time to hit the next grid line. So, we want the rays to hit the grid lines not more not a less. Therefore, to calculate these amounts we are going to use SOHCAHTOA again.

#### If the player was looking North
The X offset will be the size of the grid (64). So it can hit the next horizontal line. And to get the Y offset we can use (SOHCAHTOA) -> X offset * Tan.

#### oX = 64;

#### oY = oX* tan(looking angle);

![](https://github.com/Saxsori/ray-cast/blob/main/images/H-U.png)

#### If the player was looking South

The offsets will be the same but only the direction of the X will be changed..

#### oX = -64;

#### oY = oX* tan(looking angle);


![](https://github.com/Saxsori/ray-cast/blob/main/images/H-D.png)

#### If the player was looking East

The Y offset will be the size of the grid (64). So it can hit the next vertical line. And to get the X offset we can use (SOHCAHTOA) -> Y offset * Tan.

#### oY = 64;

#### oX = oY * tan(looking angle);

![](https://github.com/Saxsori/ray-cast/blob/main/images/V-R.png)

#### If the player was looking West

The offsets will be the same but only the direction of the Y will be changed..

#### oY = - 64 ;

#### oX = oY * tan(looking angle);

![](https://github.com/Saxsori/ray-cast/blob/main/images/V-L.png)


## Resources
- [3DSage Raycasting](https://www.youtube.com/watch?v=gYRrGTC7GtA)

- [Lode's Tutorial](https://lodev.org/cgtutor/raycasting.html)

- [Gridline checkers](https://www.permadi.com/tutorial/raycast/rayc7.html)
