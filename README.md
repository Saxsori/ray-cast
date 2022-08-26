# ray-cast

I will explain here the formulas that I have used to implement the ray-casting. What kind of calaculation I made to create and draw the wall and moves around them. The idea of the raycasting in general is easy and the formulas isn't that complicated.

## Introduction
Well let me firstly tell you what are the math concepts that I have used in the formulas. Right triangle trigonometry (SOHCAHTOA), Components of a Vector (X , Y), and Vector quantity (magnitude and direction). 

## Main Idea
In order to explain the main idea of the formulas, let's say that we have the player postion on a 2D map (x, y) coordinates. The player is looking at the wall in front of him (NORTH), let's say the looking angle is 90 which is straight to north. The distance from his coordinate to the point of the wall called a ray. Depending on the player's [FOV](https://www.techtarget.com/whatis/definition/field-of-view-FOV) the number of the rays will be decided. If the FOV is 120 then his looking width will be 60 degrees to the left and 60 degrees to the right from the looking angle (90).
Well where are we going to use the vectors? 
Using the player's coordinate and his looking angle we can calculate the ray's vector (X and Y components). Then calculate the offset (gridline outlier) the points where the rays could hit vertically and horizontally till the point of the wall.

## GridLine Checkers


### Horizontal Gridline

### Vertical Gridline 

## Resources
- [3DSage Raycasting](https://www.youtube.com/watch?v=gYRrGTC7GtA)

- [Lode's Tutorial](https://lodev.org/cgtutor/raycasting.html)

- [Gridline checkers](https://www.permadi.com/tutorial/raycast/rayc7.html)
