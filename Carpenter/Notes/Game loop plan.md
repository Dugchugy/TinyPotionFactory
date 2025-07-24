# plan for basic game structure and event loop

## Serialization

it should be possible to take the entire grid and all objects on it and serialize them to be save into a file.

## Game tick

The game tick will have 4 parts and all 4 will happen in order for each tick. A game tick will pass as fast as the players device will allow up to 30 ticks per second. Rendering will not be included in the tick and will happen at a rate determined by the players device with no cap.

### 1. Prepare

During the prepare stage, the game readies itself for a tick to occur. 

### 2. Transfer

During the transfer stage, resources are moved between tiles. Any tiles that can, will attempt to pull input from any adjacent tiles marked for input. Each tile can be updated in parallel to increase efficiency so tile outputs should be guarded to prevent multiple access.

### 3. Update

During the update state, all tiles are updated and their operations occur. during the update phase, each tile takes resources from its input storages and attempts to convert them into resources in it's output storage. tiles may not access the inventories of other tiles at this time. Each tile can be updated in parallel

### 4. Cleanup

during the cleanup state, the game finishes the update. this involves updating counters for total potions sold and potion sale rates as well as checking for any quests that may have been completed. 

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

### handWell

a well that can be used to retrieve water. accepts no inputs and outputs only by Drag and drop. can always drag and drop some water out of it

### handBottler

a bottler that can only be used to put potions into bottles. accepts input only from drag and drop and outputs only by Drag and drop. accepts a fluid (may also accept bottles if they are added)

### handCauldron 

a cauldron that can be used to mix one fluid with one solid. only accepts input from drag and drop and items can only be output by Drag and drop.

### salesBox

a box that items can be moved into. all items placed in it will be sold and converted into gold. accepts items from all sides (except bottom) and drag and drop

### lecturn

a pedestal with a book on it. used to access the journal for researching new tiles. can only be one. does not accept any input or produce any output

## Non-Tile objects

In addition to the factory and all the tiles that make it up, the player will also be able to see their current gold count and a shop. They will gain gold by selling potions with a specific price for each potion. The shop will show all the tiles they can buy to place in the factory and a price. if the player has enough gold, they will be able to drag a tile from the shop to the factory to purchase it and add it to the factory.

using the lecturn, the player will be able to research new tiles to unlock them in the shop for future use. most tiles will be locked at the start of the game. 

## Research

in order to progress in the game and unlock new parts for your factory. you will need to do research.  research will be done with a series of quests, each requiring you to either build a factory component or sell some number of potions (may add rate based quests too). the quests will be set up in a tree structure where quests have pre-reqisits that must be completed before they can be started. not all quests will unlock items

### The Journal Begins

pre-reqisits: None

quest: place lecturn

reward: none

I've been told that all good witches should keep a journal. It's a useful tool to help record their discoveries in the arcane arts. 