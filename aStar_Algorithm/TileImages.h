#pragma once

using namespace System::Drawing;

ref class TileImages{ //Tile image storage
public:
	static Image^ Empty = Image::FromFile("..\\Debug\\empty.png");
	static Image^ Block = Image::FromFile("..\\Debug\\block.png");
	static Image^ Check = Image::FromFile("..\\Debug\\check.png");
	static Image^ Closed = Image::FromFile("..\\Debug\\closed.png");
	static Image^ End = Image::FromFile("..\\Debug\\end.png");
	static Image^ Path = Image::FromFile("..\\Debug\\path.png");
	static Image^ Start = Image::FromFile("..\\Debug\\start.png");
	static Image^ EnableRun = Image::FromFile("..\\Debug\\enableRun.png");
	static Image^ DisableRun = Image::FromFile("..\\Debug\\disableRun.png");
	static Image^ EnableBuild = Image::FromFile("..\\Debug\\enableEdit.png");
	static Image^ DisableBuild = Image::FromFile("..\\Debug\\disableEdit.png");
	static Image^ EnableClear = Image::FromFile("..\\Debug\\enableClear.png");
	static Image^ DisableClear = Image::FromFile("..\\Debug\\disableClear.png");
	static Image^ EnableLoad = Image::FromFile("..\\Debug\\enableLoad.png");
	static Image^ DisableLoad = Image::FromFile("..\\Debug\\disableLoad.png");
	static Image^ EnableSave= Image::FromFile("..\\Debug\\enableSave.png");
	static Image^ DisableSave = Image::FromFile("..\\Debug\\disableSave.png");
	static Image^ ApplicationIcon = Image::FromFile("..\\Debug\\icon.ico");
};

