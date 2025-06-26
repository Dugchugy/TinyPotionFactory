# plan for basic game structure and event loop

most block placement will be done on grid. grid will contain be an array of pointers to tile Objects that handle the basic functionality of the tiles. if no tile is present then pointer will be set to null

## `TileObject`

   `TileObject` is the base class for all tiles. all functional and decorative tiles will inherit from TileObject. TileObjects each contain a model they use for rendering and a 2D vector of integers storing where they are on the grid. 
   TileObjects will have functions to get their input/output models (what sides they accept from) and applying an input or output to the tile. they will also have a both a draw and an update function. 