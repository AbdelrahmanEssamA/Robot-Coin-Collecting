//Name: Abdelrahman Essam
//ID: 155295 
#include <iostream>
#include <algorithm>
using namespace std;
const int num = 5; // number of rows and columns
int  grid[5][5] = { {0,0,0,1,-1}, {1,0,1,-1,1}, {1,-1,1,1,-1}, {0,-1,1,0,0}, {1,1,-1,-1,0} };

int  dp[num][num]; // Second Array uses dynamic programing to collect the highest number coins starting from the dead end to the starting that have the highest number of coins 
int step = 1; // the step on the x-axis 

int Check(int row, int col) //checks the cell's values whether it contains bomb coins or empty and return the max numer of coins mario can aquire 
{
	if (row >= num || col >= num) //checks if the cell is out of the grid
		return 0;

	if (row < 0 || col < 0)		  //checks if the cell is out of the grid
		return 0;

	if (grid[row][col] == -1)     // checks the cell for bomb
		return 0;

	if (dp[row][col] != -1)       //checks whether the cell is visted or not
	{
		return dp[row][col];
	}
	if (row % 2 == 0) //checks if the row's number is odd or even to decide the step on x-axis
		step = 1; 
	else 
		step = -1; 
	int result_Horizontal = Check(row,col+step); //recurse on the columns steping on step on left or right at a time
	int result_down = Check(row + 1, col); //recurse on the rows seping one step down at a time
	int result = max(result_Horizontal, result_down) + grid[row][col]; //compare betwen the values of each cell get the max add it to the value of current value of the grid ; value represent number of coins

	dp[row][col] = result; //add the result to the dp array with the number of coins
	return result; //return the last result at starting pin contains the max coins mario can collect
}

int main() {

	for (int i = 0; i < num; i++) { //filling the arry with -1 that stands for unvisited cell
		for (int j = 0; j < num; j++) {
			dp[i][j] = -1;
		}
	}
	Check(0, 0); //call the function starting with 0,0 as starting point

	cout << dp[0][0] << " Coins"<<endl;// output the max number of coins

system("pause");
	return 0;
}

