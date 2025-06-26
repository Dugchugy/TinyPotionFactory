# plan for basic game structure and event loop

## Serialization

it should be possible to take the entire grid and all objects on it and serialize them to be save into a file.

## Objects

### `TileGrid`

most block placement will be done on grid. grid will contain be an array of pointers to tile Objects that handle the basic functionality of the tiles. if no tile is present then the pointer will be set to null.

the grid will have functions to look up tiles based on their position. if there is no tile in this position it will instead return a default TileObject. the grid will also have an update and draw function that calls the function on all the tiles it contains

each grid will be 16 by 16 tiles and store the grid position of it's bottom left corner.

### `TileObject`

`TileObject` is the base class for all tiles. all functional and decorative tiles will inherit from TileObject. TileObjects each contain a model they use for rendering and a 2D vector of integers storing where they are on the grid. 

TileObjects will have functions to get their input/output models (what sides they accept from) and applying an input or output to the tile. they will also have a both a draw and an update function. 