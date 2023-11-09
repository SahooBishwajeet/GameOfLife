// TO-DO :: More Cache-Friendly Code :::::::::::::::::::::::::::::::::::::::::: DONE
// TO-DO :: Make A Program To Implement This On Terminal

#include "screen.h"

const int SCREEN_HEIGHT = 128; // Define RENDER SCREEN HEIGHT (Don't Keep It
                               // Beyond 256, Otherwise It Will Be Glitchy)
const int SCREEN_WIDTH = 256;  // Define RENDER SCREEN WIDTH (Don't Keep It
                               // Beyond 256, Otherwise It Will Be Glitchy)

// isAlive Function To Determine The FATE Of The Next Geenration
bool isAlive(std::array<std::array<int, SCREEN_HEIGHT>, SCREEN_WIDTH> arr, int a, int b) {
  // Conway's Game Of Life Rules :-
  	// Any live cell with fewer than two live neighbours dies, as if by underpopulation.
  	// Any live cell with two or three live neighbours lives on to the next generation. 
  	// Any live cell with more than three live neighbours dies, as if by overpopulation. 
  	// Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

  // Shortened/Concise Rules
  	// Any live cell with two or three live neighbours survives.
  	// Any dead cell with three live neighbours becomes a live cell.
	// All other live cells die in the next generation. Similarly, all other dead cells stay dead.

  int aliveNeighbours = 0; // Count the number of alive neighbours of the point

  if ((a > 0 && b > 0) && arr[a - 1][b - 1] == 1)
    aliveNeighbours++; // Checking For Top-Left Neighbours
  if (a > 0 && arr[a - 1][b] == 1)
    aliveNeighbours++; // Checking For Top Neighbours
  if ((a > 0 && b < SCREEN_WIDTH) && arr[a - 1][b + 1] == 1)
    aliveNeighbours++; // Checking For Top-Right Neighbours

  if (b > 0 && arr[a][b - 1] == 1)
    aliveNeighbours++; // Checking For Left Neighbours
  if (b < SCREEN_WIDTH && arr[a][b + 1] == 1)
    aliveNeighbours++; // Checking For Right Neighbours
  
  if ((a < SCREEN_HEIGHT && b > 0) && arr[a + 1][b - 1] == 1)
    aliveNeighbours++; // Checking For Bottom-Left Neighbours
  if (a < SCREEN_HEIGHT && arr[a + 1][b] == 1)
    aliveNeighbours++; // Checking For Bottom Neighbours
  if ((a < SCREEN_HEIGHT && b < SCREEN_WIDTH) && arr[a + 1][b + 1] == 1)
    aliveNeighbours++; // Checking For Bottom-Right Neighbours

  // POINT'S FATE For The Next Generation (Alive OR Dead) <Alive :: True, Dead :: False>
  if (arr[a][b] == 1 && (aliveNeighbours == 2 || aliveNeighbours == 3))
    return true;
  if (arr[a][b] == 0 && (aliveNeighbours == 3))
    return true;

  return false;
}

int main() {
  GraphicsWrap screen;

  // Use 2 Arrays To Store Generations
  // 1st Array To Hold The Current Generation For FATE Calculation
  // 2nd Array To Hold The Next Generatiob For Display/Render

  std::array<std::array<int, SCREEN_HEIGHT>, SCREEN_WIDTH> mainDisp{};
  std::array<std::array<int, SCREEN_HEIGHT>, SCREEN_WIDTH> bufferDisp{};

  // Generate Random Alive Points At The Beginning
  for (auto &row : mainDisp)
    std::generate(row.begin(), row.end(), []() { return rand() % 10 == 0 ? 1 : 0; });

  // Render The World For "Game Of Life" Show
  while (true) {
    // Calculate Next Generation
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
      for (int j = 0; j < SCREEN_WIDTH; j++) {
        bufferDisp[i][j] = isAlive(mainDisp, i, j) ? 1 : 0;
      }
    }

    // Draw Using The SDL2 Library
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
      for (int j = 0; j < SCREEN_WIDTH; j++) {
        if (bufferDisp[i][j]) {
          screen.drawpixel(i, j);
        }
      }
    }

    // Replace Buffer Display With Main Display For The Next Generation
    std::copy(bufferDisp.begin(), bufferDisp.end(), mainDisp.begin());

    // Do All The Necessary Operatios To Render, Plot/Draw & Clear Screen (For Next Generation) 
    // Note That All Are Wrapper Function For SDL2 Library Functions
    screen.update();
    SDL_Delay(25);
    screen.input();
    screen.clearpixels();
  }
  return 0;
}
