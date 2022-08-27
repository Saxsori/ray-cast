# Ray-Casting

I will explain here the formulas that I have used to implement the ray-casting. This raycast has been made in order to create a 3D game [Cub3D](https://github.com/Saxsori/cub3d). The project still in progress ⚙️🛠.

Note:
 `Im NoT DoNe yEt wItH KeYs .. AnD tHe PaLyEr cAn wAlK ThRouGh tHe WaLLs` 🧟‍♀️

## Introduction
The idea of the raycasting in general is easy and the formulas isn't that complicated. I will explain what kind of calaculation I used to create, draw, and move around the walls.

Well let me firstly tell you what are the math concepts that I have used in the formulas. [Right triangle trigonometry (SOHCAHTOA)](https://www.mathsisfun.com/algebra/sohcahtoa.html), and [Vectors: Components(X , Y), Quantity (magnitude and direction)](https://www.varsitytutors.com/hotmath/hotmath_help/topics/components-of-a-vector). 

## Main Idea
In order to explain the main idea of the formulas, let's say that we have the player's postion on a 2D map (x, y) coordinates. `The player is looking at the wall in front of him (NORTH), let's say the looking angle is 90 which is straight to north`. The distance from his coordinate to the point of the wall called a ray. Depending on the player's [FOV](https://www.techtarget.com/whatis/definition/field-of-view-FOV) the number of the rays will be decided. `If the FOV is 120 then his looking width will be 60 degrees to the left and 60 degrees to the right from the looking angle (90)`.

#### Well where are we going to use the vectors?

Using the player's coordinate and his looking angle we can calculate the ray's vector `(X and Y components)`. Then calculate the offset `(gridline outlier)` the points where the rays could hit vertically and horizontally till the point of the wall.

## GridLine Hit Checkers
Each time the ray will hit a grid line horizontally or vertically, that point actually should be the position where we can check if it's a wall or not. To do that we firstly need to know how to calculate the ray's vector using the player's coordinates, then add a specfic value `(parameters)` to hit the first grid line, then continually add a constant value to hit each grid line till the wall, these constant values called `(Grid Offsets)`.

![alt text](https://github.com/Saxsori/ray-cast/blob/main/images/1.png)

Horizontal Grid Lines is the (NORTH & SOUTH), or `the upper and the lower sides of a 2d map`. Vertical Grid Lines is the (WEST & EAST), `or the left and the right sides of a 2d map`.
Depending on the looking angle of the player we can decide where the ray is actually hitting vertically `(left or right)` and horizontally `(up or down)`. Before that We actually need to understand how we can calculate `the ray's line and the ray's vector`.

Let's explain how we can get the formulas in general (ray's vectors)..

First thing to know in order to get the ray's X and Y components `(ray Y and ray X)`, is that we can use the rule of the right triangle.

### Example
This in example on how the ray's points should look like when it hits the grid lines. I used [desmos](https://www.desmos.com/calculator/rhdvs6uffp) to plot them out. And I added the offsets and the parameter manually for the looking angle 60 and the position (77, 77). `The red point is the player's position, the orange points are the upper side, the green points are the lower side, the black points are the left side, and the purple points are the right side`. 

<img width="635" alt="Screen Shot 2022-08-27 at 7 37 59 AM" src="https://user-images.githubusercontent.com/92129820/187012948-2590fd02-a71b-461b-bd28-6a7101aa5ac4.png">

### Horizontal Gridline

To calculate the horizontal gridline checker formulas. We can follow these steps :

- The ray Y point should be the player's Y coordinate.

- Then to get the ray X point we can use the right triangle rules `(SOHCAHTOA)`. The ray line would be Hypotenuse, the Opposite is the difference between the player Y coordinate and Ray Y point and the Adjacent is the ray X component which we are trying to find. So ray X is `tan(looking angle) / opposite`.

 ![alt text](https://github.com/Saxsori/ray-cast/blob/main/images/4.png) 
 
To scale them to the size of the grid (64) :

- The ray Y you should firstly scale the player's Y point to 64 unit. `((pY / 64) * 64);`
- The ray X should had the player's X coordinate. `(+ pX);`

To make them hitting the next horizontal grid line we need to add a parameter :

- The ray Y point should had the distance from the player position to the next horizontal grid line `(the difference between the player Y coordinate and the next Y line)` so that it can hit the next horizontal gridline.

The formula when the player is looking (North) should finally look like this ..

```ruby
rayY = ((pY / 64) * 64) + (Y.line - pY);
rayX = (pY - rayY) / -tan(looking angle) + pX;
```

If the player was looking (South) the direction is horizontally different now so the signs will be only changed ..

```ruby
rayY = ((pY / 64) * 64) - (Y.line - pY);
rayX = (pY - rayY) / -tan(looking angle) + pX;
````

### Vertical Gridline 

To check the vertical grid line hit, it will be the same but opposite. The calculation will depend only on the ray Y where it could hit the Y lines. Previously on the horizontal checkers it was depending on the ray X where it can hit on the X lines.

So the formula will be changed to this ..

#### If the player was looking to the East.

```ruby
rayX = ((pX / 64) * 64) + (X.line - pX);
rayY = (pX - rayX) / -tan(looking angle) + pY;
```

#### If the player was looking to the west the direction is now changes so the signs will be changed again.

```ruby
rayX = ((pX / 64) * 64) - (X.line - pX);
rayY = (pX - rayX) / -tan(looking angle) + pY;
```

### Gridline Offset

Offset basically means the amount or a value by which the calculation is out of line or where it could hit the outlier. And here it means the value to add each time to hit the next grid line. So, we want the rays to hit the grid lines not more not a less. Therefore, to calculate these amounts we are going to use `SOHCAHTOA` again.

#### If the player was looking North
The X offset will be the size of the grid (64). So it can hit the next horizontal line. And to get the Y offset we can use `(SOHCAHTOA) -> X offset * Tan`.

```ruby
oX = 64;
oY = oX * tan(looking angle);
```

![](https://github.com/Saxsori/ray-cast/blob/main/images/H-U.png)

#### If the player was looking South

The offsets will be the same but only the direction of the X will be changed..

```ruby
oX = -64;
oY = oX * tan(looking angle);
```

![](https://github.com/Saxsori/ray-cast/blob/main/images/H-D.png)

#### If the player was looking East

The Y offset will be the size of the grid (64). So it can hit the next vertical line. And to get the X offset we can use `(SOHCAHTOA) -> Y offset * Tan`.

````ruby
oY = 64;
oX = oY * tan(looking angle);
````

![](https://github.com/Saxsori/ray-cast/blob/main/images/V-R.png)

#### If the player was looking West

The offsets will be the same but only the direction of the Y will be changed..

```ruby
oY = -64;
oX = oY * tan(looking angle);
```

![](https://github.com/Saxsori/ray-cast/blob/main/images/V-L.png)


For Example, let's say `the player's looking angle is 60. He's looking North to the East. Vertically the line should hit the right side and horizontally should hit the upper side`. So the formulas that we are going to use are ..

```ruby
rayY = ((pY / 64) * 64) + (Y.line - pY);
rayX = (pY - rayY) / -tan(looking angle) + pX;
```

And vertically 

```ruby
rayX = ((pX / 64) * 64) + (X.line - pX);
rayY = (pX - rayX) / -tan(looking angle) + pY;
```

`So depending on the looking angle we can choose the right formulas to get the hitting points till the wall`.

## Drawing the walls

Create a loop to check which grid line checker will hit the wall firstly, the vertical or the horizontal one. Then calculate the distance between the point where the ray hit the wall and the position of the player, and this should be the length of the ray line. You can easily use the [pythagorean rule]() to calculate the length of the line between two points. `$c = \sqrt{a^2 + b^2}$`

`Save this value (the length of the ray) for drawing but firstly let's explain how the width and the height of the screen should be scaled. How it should look like !`

### Width of the Screen
The width of the screen will be fixed. You can choose the width of the screen. As you cann see the width of the screen is the width of the image that the player can see. The size of the width will be the number of the rays. And the angle between each ray should be the `FOV / width`.

`````ruby
angle = looking_angle - (FOV / 2);
while (--WIDTH)
{
   ray[i].angle = angle;
   angle += (FOV / WIDTH);
}
`````

### Height of the Screen
The height of the screen will be fixed also. The height of the screen should the Max height that the wall could reach, you can choose your own size. To get the height of each wall, you should `multiply the grid size (64) by the screen height divide by the ray length`.

````ruby
wall_height = (64 * HEIGHT) / ray_len;
````
### Drawing
Okay let's wrap this all up. Using all of these ideas we can finally end up with these steps. Since the number of rays is the size of the width we can create this loop, inside the loop we should do the following steps..

1- Do the gridline check and get the final ray points.

2- Calculate the wall height using the HEIGHT of the screen and the ray length.

3- Calculate the starting point and the ending point of the walls.

4- Start drawing.

````ruby
x = -1;
while (++x < WIDTH)
{
   check_gridline(ray[x]);
   ray[x].wall_height = (64 * HEIGHT) / ray[x].ray_len;
   begin = (HEIGHT / 2) - (wall_height / 2);
   end = (HEIGHT / 2) + (wall_height / 2);
   y = begin - 1;
   while (++y < end)
     draw(x, y);
}
````

## Finaly ! This how it should look like ✌🏼

![](https://github.com/Saxsori/ray-cast/blob/main/images/10.gif)

## Resources
- [3DSage Raycasting](https://www.youtube.com/watch?v=gYRrGTC7GtA)

- [Lode's Tutorial](https://lodev.org/cgtutor/raycasting.html)

- [Gridline checkers](https://www.permadi.com/tutorial/raycast/rayc7.html)
 
