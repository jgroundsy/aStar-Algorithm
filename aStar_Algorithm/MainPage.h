#pragma once
#include "Tile.h"
#include "TileImages.h"
#include <iostream>
#include <fstream>
#include <Windows.h>


namespace aStarAlgorithm {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace aStarAlgorithm::Resources;
	using namespace std;

	/// <summary>
	/// Summary for MainPage
	/// </summary>
	/// 
	
	public ref class MainPage : public System::Windows::Forms::Form
	{

		bool isEditing = false; //Checks if the user is currently in scene building mode
		bool isLoading = false; //Checks if the user is currently loading a grid from text file
		bool isSaving = false; //Checks if the user is currently saving a grid to a text file
		ArrayList^ tiles = gcnew ArrayList; //List of all tiles within grid

		Tile^ startTile; //The starting tile
		Tile^ endTile; //The destination tile

		ArrayList^ pathTiles = gcnew ArrayList; //used for displaying the final calculated path

	private: System::Windows::Forms::Button^ clearButton; 
	private: System::Windows::Forms::Button^ loadButton;
	private: System::Windows::Forms::Button^ saveButton;
	private: System::Windows::Forms::Button^ buildButton;

	public:
		MainPage(void)
		{
			InitializeComponent();
			
		}


	public:

	protected:
		//Clean up resources being used
		~MainPage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ runButton;
	protected:

	private:
		//Required for designer variable
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		//Windows designer support
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainPage::typeid));
			this->runButton = (gcnew System::Windows::Forms::Button());
			this->buildButton = (gcnew System::Windows::Forms::Button());
			this->clearButton = (gcnew System::Windows::Forms::Button());
			this->loadButton = (gcnew System::Windows::Forms::Button());
			this->saveButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// runButton
			// 
			this->runButton->BackColor = System::Drawing::Color::Transparent;
			this->runButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"runButton.BackgroundImage")));
			this->runButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->runButton->FlatAppearance->BorderSize = 0;
			this->runButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->runButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->runButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->runButton->ForeColor = System::Drawing::Color::Transparent;
			this->runButton->Location = System::Drawing::Point(413, 647);
			this->runButton->Name = L"runButton";
			this->runButton->Size = System::Drawing::Size(150, 50);
			this->runButton->TabIndex = 0;
			this->runButton->UseVisualStyleBackColor = false;
			this->runButton->Click += gcnew System::EventHandler(this, &MainPage::runButton_Click);
			// 
			// buildButton
			// 
			this->buildButton->BackColor = System::Drawing::Color::Transparent;
			this->buildButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"buildButton.BackgroundImage")));
			this->buildButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->buildButton->FlatAppearance->BorderSize = 0;
			this->buildButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->buildButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->buildButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buildButton->Location = System::Drawing::Point(569, 647);
			this->buildButton->Name = L"buildButton";
			this->buildButton->Size = System::Drawing::Size(150, 50);
			this->buildButton->TabIndex = 2;
			this->buildButton->UseVisualStyleBackColor = false;
			this->buildButton->Click += gcnew System::EventHandler(this, &MainPage::buildButton_Click);
			// 
			// clearButton
			// 
			this->clearButton->BackColor = System::Drawing::Color::Transparent;
			this->clearButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"clearButton.BackgroundImage")));
			this->clearButton->Enabled = false;
			this->clearButton->FlatAppearance->BorderSize = 0;
			this->clearButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->clearButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->clearButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->clearButton->ForeColor = System::Drawing::Color::Transparent;
			this->clearButton->Location = System::Drawing::Point(725, 647);
			this->clearButton->Name = L"clearButton";
			this->clearButton->Size = System::Drawing::Size(150, 50);
			this->clearButton->TabIndex = 3;
			this->clearButton->UseVisualStyleBackColor = false;
			this->clearButton->Click += gcnew System::EventHandler(this, &MainPage::clearButton_Click);
			// 
			// loadButton
			// 
			this->loadButton->BackColor = System::Drawing::Color::Transparent;
			this->loadButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"loadButton.BackgroundImage")));
			this->loadButton->FlatAppearance->BorderSize = 0;
			this->loadButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->loadButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->loadButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->loadButton->ForeColor = System::Drawing::Color::Transparent;
			this->loadButton->Location = System::Drawing::Point(12, 647);
			this->loadButton->Name = L"loadButton";
			this->loadButton->Size = System::Drawing::Size(150, 50);
			this->loadButton->TabIndex = 4;
			this->loadButton->UseVisualStyleBackColor = false;
			this->loadButton->Click += gcnew System::EventHandler(this, &MainPage::loadButton_Click);
			// 
			// saveButton
			// 
			this->saveButton->BackColor = System::Drawing::Color::Transparent;
			this->saveButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"saveButton.BackgroundImage")));
			this->saveButton->FlatAppearance->BorderSize = 0;
			this->saveButton->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Transparent;
			this->saveButton->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Transparent;
			this->saveButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->saveButton->ForeColor = System::Drawing::Color::Transparent;
			this->saveButton->Location = System::Drawing::Point(1077, 647);
			this->saveButton->Name = L"saveButton";
			this->saveButton->Size = System::Drawing::Size(150, 50);
			this->saveButton->TabIndex = 5;
			this->saveButton->UseVisualStyleBackColor = false;
			this->saveButton->Click += gcnew System::EventHandler(this, &MainPage::saveButton_Click);
			// 
			// MainPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::Color::Black;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(1254, 709);
			this->Controls->Add(this->saveButton);
			this->Controls->Add(this->loadButton);
			this->Controls->Add(this->clearButton);
			this->Controls->Add(this->buildButton);
			this->Controls->Add(this->runButton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MainPage";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"A* Algorithm";
			this->Load += gcnew System::EventHandler(this, &MainPage::MainPage_Load);
			this->ResumeLayout(false);

		}
#pragma endregion

	public: void CreateGrid(int width, int height) { //instantiates a grid of tiles
		int paddingX = 32, paddingY = 32;
		for (int y = 0; y < 20; y++) {
			for (int x = 0; x < 39; x++) {
				Tile^ tile = gcnew Tile();
				tiles->Add(tile);
				tile->setType(0);
				tile->Height = 32;
				tile->Width = 32;
				tile->SizeMode = PictureBoxSizeMode::StretchImage;
				tile->setPosX(x);
				tile->setPosY(y);
				tile->setPos(Point(x * 32, y * 32));
				tile->setEventHandler(this);
				tile->setEnabled(false);
				this->Controls->Add(tile);
			}
		}
	}

	public: ArrayList^ GetNeighbors(Tile^ tile) { //Retrieves specific tile's neighbors if they are valid
		ArrayList^ neighbors = gcnew ArrayList;

		for (int y = -1; y <= 1; y++) {
			for (int x = -1; x <= 1; x++) {
				if (x == 0 && y == 0) { continue; }

				int nextX = tile->getPosX() + x;
				int nextY = tile->getPosY() + y;

				if ((nextX >= 0 && nextX < 39) && (nextY >= 0 && nextY < 20)) {
					for (int i = 0; i < tiles->Count; i++) {
						Tile^ newNeighbor = (Tile^)tiles[i];
						if (newNeighbor->getPosX() == nextX && newNeighbor->getPosY() == nextY) {
							neighbors->Add(newNeighbor);
							if (newNeighbor != startTile && newNeighbor != endTile && newNeighbor->getType() != 3) {
								newNeighbor->setType(5);
							}
						}
					}
				}
			}
		}
		return neighbors;
	}

	private: System::Void MainPage_Load(System::Object^ sender, System::EventArgs^ e) { //MainPage loading event handler
		CreateGrid(this->Size.Width, this->Size.Height);
	}

	private: System::Void buildButton_Click(System::Object^ sender, System::EventArgs^ e) { //Toggles build mode
		System::Diagnostics::Debug::WriteLine("[A* Algorithm] Info: Toggling build mode");
		if (isEditing) {
			setBuildMode(false);
		}
		else {
			setBuildMode(true);
		}
	}

	private: void setBuildMode(bool boolean) {
		if (boolean) {
			isEditing = true;
			buildButton->BackgroundImage = TileImages::EnableBuild;
			clearButton->BackgroundImage = TileImages::EnableClear;
			clearButton->Enabled = true;
			Tile^ currentTile;
			int length = tiles->Count;
			for (int i = 0; i < length; i++) {   //Sets build mode to true
				currentTile = (Tile^)tiles[i];
				currentTile->setEnabled(true);
				if (currentTile->getType() == 4 || currentTile->getType() == 5 || currentTile->getType() == 6) { //Clear any preexisting checked tiles from previous run
					currentTile->setType(0);     //Remove any existing checked, closed, or path tiles
				}
			}
		}
		else {
			isEditing = false;
			buildButton->BackgroundImage = TileImages::DisableBuild;
			clearButton->BackgroundImage = TileImages::DisableClear;
			clearButton->Enabled = false;
			Tile^ currentTile;
			int length = tiles->Count;
			for (int i = 0; i < length; i++) {   //Sets build mode to false
				currentTile = (Tile^)tiles[i];
				currentTile->setEnabled(false);
			}
		}
	}

	private: System::Void runButton_Click(System::Object^ sender, System::EventArgs^ e) { //Attempt to run algorithm
		int startTiles = 0;
		int endTiles = 0;
		Tile^ currentTile;
		for (int i = 0; i < tiles->Count; i++) {
			currentTile = (Tile^)tiles[i];
			if (currentTile->getType() == 1) {   //Check if there is a valid amount of start tiles and end tiles
				startTiles++;
			}
			else if (currentTile->getType() == 2) {
				endTiles++;
			}
		}

		if (startTiles == 1 && endTiles == 1) { //Tile amount is valid, run the algorithm
			Tile^ currentTile;
			for (int i = 0; i < tiles->Count; i++) {
				currentTile = (Tile^)tiles[i];
				if (currentTile->getType() == 1) {
					startTile = currentTile;
				}
				else if (currentTile->getType() == 2) {
					endTile = currentTile;
				}
			}
			runAlgorithm(); //Run the algorithm
		}
		else { //User entered invalid amount of start and end tiles
			System::Diagnostics::Debug::WriteLine("[A* Algorithm] Warning: Cannot run algorithm due to invalid amount of start/end tiles");
		}
	}
		   void MakePath(Tile^ startTile, Tile^ endTile) {   //Draws a path on the UI
			   ArrayList^ pathTiles = gcnew ArrayList;
			   Tile^ currentTile = endTile;

			   System::Diagnostics::Debug::WriteLine("[A * Algorithm] Info: Making the path!");
			   while (currentTile != startTile) {
				   pathTiles->Add(currentTile);  
				   currentTile = currentTile->getParent(); //Back-tracks through the route by getting each tile's parent.
			   }
			   pathTiles->Reverse(); //Reverse the order of the paths list so that it draws from start tile to end tile
			   Tile^ path;
			   for (int i = 0; i < pathTiles->Count - 1; i++) {
				   path = (Tile^)pathTiles[i]; 
				   path->setType(6);  //Update tile image
			   }
			   runButton->Enabled = true;
			   runButton->BackgroundImage = TileImages::EnableRun; //Enable the run button
		   }

		   void runAlgorithm() { //Main algorithmic function
			   System::Diagnostics::Debug::WriteLine("[A * Algorithm] Info: Running algorithm!");
			   runButton->BackgroundImage = TileImages::DisableRun; //Set run button image
			   runButton->Enabled = false; //Disable run button
			   ArrayList^ openTiles = gcnew ArrayList; //List of open tiles within grid
			   ArrayList^ closedTiles = gcnew ArrayList; //List of closed tiles within grid
			   Tile^ currentTile;
			   int tilesLength = tiles->Count;

			  setBuildMode(false); //User can no longer edit in build-mode while algorithm is running
			   
			   for (int i = 0; i < tilesLength; i++) {
				   currentTile = (Tile^)tiles[i];
				   currentTile->setEnabled(false);
				   if (currentTile->getType() == 4 || currentTile->getType() == 5 || currentTile->getType() == 6) { //Clear any preexisting checked tiles from previous run
					   currentTile->setType(0);
				   }
			   }
			   openTiles->Add(startTile);  //Sets the start tile as the first index in the openTiles list

			   while (openTiles->Count > 0) {
				   Tile^ currentTile = (Tile^)openTiles[0];
				   Tile^ openTile;

				   for (int i = 1; i < openTiles->Count; i++) {
					   openTile = (Tile^)openTiles[i];

					   if ((openTile->getFCost() < currentTile->getFCost()) || (openTile->getFCost() == currentTile->getFCost() && openTile->getHCost() < currentTile->getHCost())) { //Retrieve the lowest cost
						   currentTile = openTile;
					   }
				   }

				   openTiles->Remove(currentTile); //Remove current tile from open list
				   closedTiles->Add(currentTile); //Add current tile from closed list.

				   for (int i = 0; i < closedTiles->Count; i++) { //Loop through the closed tiles
					   currentTile = (Tile^)closedTiles[i];
				   }

				   if (currentTile == endTile) {
					   System::Diagnostics::Debug::WriteLine("[A * Algorithm] Info: Found destination");
					   MakePath(startTile, endTile);
					   return;
				   }

				   for each (Tile ^ neighborTile in GetNeighbors(currentTile)) {
					   if (neighborTile->getType() == 3) { //Neighboring tile is an obstacle, continue through the list
						   continue;
					   }
					   else if (closedTiles->Contains(neighborTile) && neighborTile != startTile) { //Found a neighboring tile that is not an obstacle
						   neighborTile->setType(4);
						   continue;
					   }

					   int costToNeighborTile = currentTile->getGCost() + currentTile->GetTileDistance(neighborTile); //Calculate total cost
					   if (costToNeighborTile < neighborTile->getGCost() || !openTiles->Contains(neighborTile)) {
						   neighborTile->setGCost(costToNeighborTile);
						   neighborTile->setHCost(neighborTile->GetTileDistance(endTile));
						   neighborTile->setParent(currentTile);

						   if (!openTiles->Contains(neighborTile)) {
							   openTiles->Add(neighborTile);
						   }
					   }
				   }
			   }
			  runButton->BackgroundImage = TileImages::EnableRun;
			  runButton->Enabled = true;
			  System::Diagnostics::Debug::WriteLine("[A * Algorithm] Warning: No path could be found.");
		   }
	private: System::Void clearButton_Click(System::Object^ sender, System::EventArgs^ e) { //Clear button event handler
		if (isEditing) {
			Tile^ currentTile;
			int tilesLength = tiles->Count;
			for (int i = 0; i < tilesLength; i++) {
				currentTile = (Tile^)tiles[i]; //Change each tile type in the grid to empty
				currentTile->setType(0);
			}
		}
		else { //User is not currently in build-mode
		System::Diagnostics::Debug::WriteLine("[A * Algorithm] Warning: User cannot clear tiles without entering build mode.");
		}
	}
	private: System::Void loadButton_Click(System::Object^ sender, System::EventArgs^ e) { //Load button event handler
		OpenFileDialog^ dialog = gcnew OpenFileDialog;
		loadButton->BackgroundImage = TileImages::DisableLoad;
		loadButton->Enabled = false;

		if (dialog->ShowDialog(this) == System::Windows::Forms::DialogResult::OK) { //User opened a file
			try {
				IO::StreamReader^ streamReader = gcnew IO::StreamReader(dialog->FileName);
				String^ tileGridFile = streamReader->ReadToEnd();
				int tileGridFileLength = tileGridFile->Length;
				if (tileGridFileLength == 799) { //only files with 799 bytes are accepted
					parseGridFile(tileGridFile);
				}
				else {
					System::Diagnostics::Debug::WriteLine("[A * Algorithm] Warning: Cannot read file of character length " + tileGridFile->Length + ". Expected 799");
				}
				streamReader->Close();
				loadButton->BackgroundImage = TileImages::EnableLoad;
				loadButton->Enabled = true;
			}
			catch(System::Exception^ e){
				System::Diagnostics::Debug::WriteLine("[A * Algorithm] Warning: " + e);
			}
		}
		else {
			loadButton->BackgroundImage = TileImages::EnableLoad;
			loadButton->Enabled = true;
		}
	}
		   void parseGridFile(String^ text) {
			   int row = 0;
			   Tile^ currentTile;
			   Array^ characterList = text->ToCharArray();
			   Char currentChar;
			   for (int i = 0; i < 799; i++) {
				   currentTile = (Tile^)tiles[i-row];
				   currentChar = (Char)characterList->GetValue(i);
				   if (currentChar == '-') {
					   currentTile->setType(0);
				   }else if (currentChar == 's') {
					   currentTile->setType(1);
				   }else if (currentChar == 'e') {
					   currentTile->setType(2); 
				   }else if (currentChar == 'b') {
					   currentTile->setType(3);
				   }else if (currentChar == '\n') {
					   row++;
				   }
				   else {
					   System::Diagnostics::Debug::WriteLine("[A * Algorithm] Warning: Invalid character '" + currentChar + "' while loading grid file.");
				   }
			   }
		   }
		   String^ getParsedGrid() { //Parses a grid into a text file and returns
			   Tile^ currentTile;
			   int currentType;
			   String^ text;

			   for (int i = 0; i < tiles->Count; i++) { 
				   currentTile = (Tile^)tiles[i];
				   currentType = currentTile->getType();

				   if (i % 39 == 0 && i != 0) { //Begin new text line if tile is on right edge
					   text += "\n";
				   }
				   switch (currentType) {
				   case 0:
					   text += "-";
					   break;
				   case 1:
					   text += "s";
					   break;
				   case 2:
					   text += "e";
					   break;
				   case 3:
					   text += "b";
					   break;
				   }
			   }
			   return text;
		   }

private: System::Void saveButton_Click(System::Object^ sender, System::EventArgs^ e) { //Save button event handler
	SaveFileDialog^ dialog = gcnew SaveFileDialog;
	saveButton->BackgroundImage = TileImages::DisableSave;
	saveButton->Enabled = false;

	if (dialog->ShowDialog(this) == System::Windows::Forms::DialogResult::OK) { //User selected save file
		try {
			IO::StreamWriter^ streamWriter = gcnew IO::StreamWriter(dialog->FileName);
			String^ tileGridText = getParsedGrid();
			streamWriter->Write(tileGridText);
			streamWriter->Close();
		}
		catch (System::Exception^ e) {
			System::Diagnostics::Debug::WriteLine(e);
		}
		saveButton->BackgroundImage = TileImages::EnableSave;
		saveButton->Enabled = true;
	}
	else {
		saveButton->BackgroundImage = TileImages::EnableSave;
		saveButton->Enabled = true;
	}
}
};



}
