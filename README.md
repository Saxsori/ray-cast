# ray-cast

I will explain here the formulas that I have used to implement the ray-casting. This raycast has been made in order to create a 3D game [Cub3D](https://github.com/Saxsori/cub3d) feel free to check the full project.
## Introduction
The idea of the raycasting in general is easy and the formulas isn't that complicated. I will explain what kind of calaculation I used to create, draw, and move around the walls.

Well let me firstly tell you what are the math concepts that I have used in the formulas. Right triangle trigonometry (SOHCAHTOA), Components of a Vector (X , Y), and Vector quantity (magnitude and direction). 

## Main Idea
In order to explain the main idea of the formulas, let's say that we have the player postion on a 2D map (x, y) coordinates. The player is looking at the wall in front of him (NORTH), let's say the looking angle is 90 which is straight to north. The distance from his coordinate to the point of the wall called a ray. Depending on the player's [FOV](https://www.techtarget.com/whatis/definition/field-of-view-FOV) the number of the rays will be decided. If the FOV is 120 then his looking width will be 60 degrees to the left and 60 degrees to the right from the looking angle (90).

Well where are we going to use the vectors?

Using the player's coordinate and his looking angle we can calculate the ray's vector (X and Y components). Then calculate the offset (gridline outlier) the points where the rays could hit vertically and horizontally till the point of the wall.

## GridLine Hit Checkers
Each time the ray will hit a grid line horizontally or vertically .. that point actually should be the position where we can check if it's a wall or not. To do that we firstly need to know how to calculate the ray's vectors using the player coordinates. Horizontal Grid Lines is the (NORTH & SOUTH) where the player could look at .. the upper and the lower sides of a 2d map. Vertical Grid Lines is the (WEST & EAST) where the player could look at .. the left and the right sides of a 2d map.
Depending on the looking angle of the player we can decide where is ray's is actually hitting vertically (left or right) and horizontally (up or down). Before that We actually need to understand how we can calculate the ray's line and the ray's vectors. ![alt text](https://github.com/Saxsori/ray-cast/blob/main/images/1.png)

### Horizontal Gridline

### Vertical Gridline 

## Resources
- [3DSage Raycasting](https://www.youtube.com/watch?v=gYRrGTC7GtA)

- [Lode's Tutorial](https://lodev.org/cgtutor/raycasting.html)

- [Gridline checkers](https://www.permadi.com/tutorial/raycast/rayc7.html)
