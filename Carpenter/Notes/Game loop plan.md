# plan for basic game structure and event loop

## Serialization

it should be possible to take the entire grid and all objects on it and serialize them to be save into a file.

## Objects

### `TileIdentifier`

contains 2 parts, an enum and an index. the Enum determines what type of file it is and index is used to uniquely identify among tiles of that type. used to seializably identify each tile

### `TileGrid`

most block placement will be done on grid. grid will contain be an array of pointers to tile Objects that handle the basic functionality of the tiles. if no tile is present then the pointer will be set to null.

the grid will have functions to look up tiles based on their position. if there is no tile in this position it will instead return a default TileObject. the grid will also have an update and draw function that calls the function on all the tiles it contains

each grid will be 16 by 16 tiles and store the grid position of it's bottom left corner.

### `TileObject`

`TileObject` is the base class for all tiles. all functional and decorative tiles will inherit from TileObject. TileObjects each contain a model they use for rendering and a 2D vector of integers storing where they are on the grid. 

TileObjects will have functions to get their input/output models (what sides they accept from) and applying an input or output to the tile. they will also have a both a draw and an update function. 

### `GridBoard`

`GridBoard` is the highest level object of the game. it stores a vector of grids that make up the game as well as a collection of all the tiles in the grid. all grids should have a pointer to the GridBoard as well as any tiles that may need it. it has a draw and update function that calls the grid draw and update

## Tiles

### NullTile

default tile returned when no tile is present at the location. has no input or output and does nothing on update or draw. should never be stored in a grid and only returned when no item is in the grid location