#include "CellPosition.h"
#include "UI_Info.h"

CellPosition::CellPosition () 
{
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 
}

CellPosition::CellPosition (int v, int h)
{ 
	// (-1) indicating an invalid cell (uninitialized by the user)
	vCell = -1; 
	hCell = -1; 

	SetVCell(v);
	SetHCell(h);
}

CellPosition::CellPosition (int cellNum)
{
	(*this) = GetCellPositionFromNum(cellNum); // the function call with build a cell position (vCell and hCell)
												// from the passed (cellNum)
												// (*this) = ... --> this will copy the returned (vCell and hCell)
												//                   to the data members (vCell and hCell)
}

bool CellPosition::SetVCell(int v) 
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)
	if (v>=0 && v <= 8)
	{
		vCell = v;
		return true;
	}
	else
	{
		return false;
	}

	 // this line sould be changed with your implementation
}

bool CellPosition::SetHCell(int h) 
{
	///TODO: Implement this function as described in the .h file (don't forget the validation)

	if (h>=0 && h <= 10)
	{
		hCell = h;
		return true;
	}
	else
	{
		return false;
	}
	 // this line sould be changed with your implementation
}

int CellPosition::VCell() const 
{
	return vCell;
}

int CellPosition::HCell() const 
{
	return hCell;
}

bool CellPosition::IsValidCell() const 
{
	///TODO: Implement this function as described in the .h file
	if (hCell >= 0 && hCell <= 10 && vCell >= 0 && vCell <= 8)
	{
		return true;
	}
	else
	{
		return false;
	} // this line sould be changed with your implementation
}

int CellPosition::GetCellNum() const
{
	return GetCellNumFromPosition(*this); // (*this) is the calling object of GetCellNum
										  // which means the object of the current data members (vCell and hCell)
}

int CellPosition::GetCellNumFromPosition(const CellPosition & cellPosition)
{
	// Note:
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)
	// just define an integer that represents cell number and calculate it using the passed cellPosition then return it

	///TODO: Implement this function as described in the .h file
	int cellnumber=0 ;
	if (cellPosition.vCell == 0)
	{
		cellnumber = cellPosition.hCell +89;
	}
	if (cellPosition.vCell == 1)
	{
		cellnumber = (cellPosition.hCell) +78;
	}
	if (cellPosition.vCell == 2)
	{
		cellnumber = (cellPosition.hCell) +67;
	}
	if (cellPosition.vCell == 3)
	{
		cellnumber = (cellPosition.hCell)+56;
	}
	if (cellPosition.vCell == 4)
	{
		cellnumber = (cellPosition.hCell) +45;
	}
	if (cellPosition.vCell == 5)
	{
		cellnumber = (cellPosition.hCell) +34;
	}
	if (cellPosition.vCell == 6)
	{
		cellnumber = (cellPosition.hCell) +23;
	}
	if (cellPosition.vCell == 7)
	{
		cellnumber = (cellPosition.hCell) +12;
	}
	if (cellPosition.vCell == 8)
	{
		cellnumber = (cellPosition.hCell) +1;
	}
	return cellnumber; // this line should be changed with your implementation
}

CellPosition CellPosition::GetCellPositionFromNum(int cellNum)
{
	// this is a static function (do NOT need a calling object so CANNOT use the data members of the calling object, vCell&hCell)

	CellPosition position;

	/// TODO: Implement this function as described in the .h file
	if (cellNum>=1&&cellNum<=11)
	{
		position.SetVCell(8);
		position.SetHCell(cellNum - 1);
		
	}
	if (cellNum >=12 && cellNum <= 22)
	{
		position.SetVCell(7);
		position.SetHCell(cellNum - 12);
	}
	if (cellNum >= 23 && cellNum <= 33)
	{
		position.SetVCell(6);
		position.SetHCell(cellNum - 23);
	}
	if (cellNum >= 34 && cellNum <= 44)
	{
		position.SetVCell(5);
		position.SetHCell(cellNum - 34);
	}
	if (cellNum >= 45 && cellNum <= 55)
	{
		position.SetVCell(4);
		position.SetHCell(cellNum - 45);
	}
	if (cellNum >= 56 && cellNum <= 66)
	{
		position.SetVCell(3);
		position.SetHCell(cellNum - 56);
	}
	if (cellNum >= 67 && cellNum <= 77)
	{
		position.SetVCell(2);
		position.SetHCell(cellNum - 67);
	}
	if (cellNum >= 78 && cellNum <= 88)
	{
		position.SetVCell(1);
		position.SetHCell(cellNum - 78);
	}
	
	if (cellNum >= 89 && cellNum <= 99)
	{
		position.SetVCell(0);
		position.SetHCell(cellNum - 89);
	
	}
	
	// Note: use the passed cellNum to set the vCell and hCell of the "position" variable declared inside the function
	//       I mean: position.SetVCell(...) and position.SetHCell(...) then return it


	return position;
}

void CellPosition::AddCellNum (int addedNum)
{
	/// TODO: Implement this function as described in the .h file
	int x = GetCellNum();
	x = x + addedNum;
		
	vCell = GetCellPositionFromNum(x).vCell;
	hCell = GetCellPositionFromNum(x).hCell;
	

	// Note: this function updates the data members (vCell and hCell) of the calling object
}