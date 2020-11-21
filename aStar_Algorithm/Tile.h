#pragma once
#include "TileImages.h"

namespace aStarAlgorithm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	bool isDragging = false;

	ref class Tile : PictureBox { //Tile class -- derives from PictureBox class
		int hCost, gCost, fCost, type, posX, posY;
		ArrayList^ neighbors = gcnew ArrayList;
		Tile^ parent;
		bool isEnabled;

	public: //Get and set methods for Tile properties
		int getType() { return type; } //Returns tile type
		int getHCost() { return hCost; } //Returns tile hCost
		int getGCost() { return gCost; } //Returns tile gCost
		int getFCost() { return (gCost + hCost); } //Returns tile fCost
		int getPosX() { return posX; } //Returns tile x grid position 
		int getPosY() { return posY; } //Returns tile y grid position
		bool getEnabled() { return isEnabled; } //Returns whether the tile is enabled or not
		Point^ getPos() { return this->Location; } //Returns tile screen location
		Tile^ getNeighbor(int index) { //Returns neighbor at specific index
			if (index >= 0 && index < neighbors->Count) {
				Tile^ neighbor = (Tile^)neighbors[index];
				return neighbor;
			}
		}
		Tile^ getParent() { //Returns tile parent 
			return parent;
		}
		ArrayList^ getNeighbors() { //Return all neighbors
			if (this->neighbors->Count > 0) {
				return this->neighbors;
			}
		}

		void setType(int typenum) { //Sets the tile type
			this->type = typenum;
			switch (type) {
			case 0:
				this->Image = TileImages::Empty;
				this->Update();
				break;
			case 1:
				this->Image = TileImages::Start;
				this->Update();
				break;
			case 2:
				this->Image = TileImages::End;
				this->Update();
				break;
			case 3:
				this->Image = TileImages::Block;
				this->Update();
				break;
			case 4:
				this->Image = TileImages::Check;
				this->Update();
				break;
			case 5:
				this->Image = TileImages::Closed;
				this->Update();
				break;
			case 6:
				this->Image = TileImages::Path;
				this-> Update();
				break;
			}
		}

		void setHCost(int value) { hCost = value; } //Sets the tile hCost
		void setGCost(int value) { gCost = value; } //Sets the tile gCost
		void setFCost(int value) { fCost = value; } //Sets the tile fCost
		void setEnabled(bool boolean) { isEnabled = boolean; } //Sets the tile enabled state
		void setPos(Point point) { this->Location = point; } //Sets the tile location to a point on the form
		void setPosX(int value) { posX = value; } //Sets tile x position on grid
		void setPosY(int value) { posY = value; } //Sets tile y position on grid
		void setNeighbor(Tile^ tile) { //Adds a tile to the current tile's neighbors
				this->neighbors->Add(tile);
		}
		void setParent(Tile^ tile) { this->parent = tile; }
		void clearNeighbors() { //Removes all neighbors from a tile
			this->neighbors->Clear();
		}

		int GetTileDistance(Tile^ second) { //Calculates distance from current tile to another tile.
			int deltaX = Math::Abs(this->posX - second->posX); //Absolute value of the change in X
			int deltaY = Math::Abs(this->posY - second->posY); //Absolute value of the change in Y

			if (deltaX > deltaY) { return (14 * deltaY + 10 * (deltaX - deltaY)); } //Width distance is greater
			else{ return (14 * deltaX + 10 * (deltaY - deltaX)); } //Height distance is greater
		}

		void tileMouseDrag(Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {  //Tile mouse drag event handler
			Tile^ hoveredTile = (Tile^)sender;
			MouseEventArgs^ event = (MouseEventArgs^)e;

			if (isDragging == true && hoveredTile->getEnabled() == true) {  //User is hovering over a tile, set it to an obstacle
				hoveredTile->setType(3);
			}
		}

		void tileClick(Object^ sender, System::EventArgs^ e) { //Tile click event handler
			Tile^ selectedTile = (Tile^)sender;
			MouseEventArgs^ event = (MouseEventArgs^)e;

			if (event->Button == System::Windows::Forms::MouseButtons::Left && selectedTile->getEnabled() == true)
			{
				switch (selectedTile->getType()) { //Enabled tile is left-clicked, loop through tile types
				case 0:
					selectedTile->setType(1);
					break;
				case 1:
					selectedTile->setType(2);
					break;
				case 2:
					selectedTile->setType(0);
					break;
				default: 
					selectedTile->setType(0);
					break;
				}

			}
			else if (event->Button == System::Windows::Forms::MouseButtons::Right && selectedTile->getEnabled() == true) {
				if (selectedTile->getEnabled() == true) { //User right-clicked and is hovering over an enabled tile
					if (!isDragging) {
						isDragging = true;
					}
					else {
						isDragging = false;
					}
				}
			}
			else if (selectedTile->getEnabled() == false) {  //User is not in build-mode
			System::Diagnostics::Debug::WriteLine("[A * Algorithm] Warning: User cannot change tile type without entering build mode.");
			}
		}

	public: void setEventHandler(Form^ formInstance) { //Sets the event handler of a tile on specific form instance
		Form^ instance;
		instance = formInstance;
		this->Click += gcnew System::EventHandler(this, &Tile::tileClick);
		this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Tile::tileMouseDrag);
		instance->Controls->Add(this);
	}
	};
}

