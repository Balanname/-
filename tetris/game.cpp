#include "game.h"
#include <iostream>
#include "console.h"

 // 게임의 한 프레임을 처리한다.
  void update(){
    int speed = DROP_DELAY;
    --speed;

    if(speed == 0){
        softDrop();
        speed = DROP_DELAY; 
        
    }
  }

  // 게임 화면을 그린다.
  void draw(){
     int minX = 0;
     int minY = 0;
     int maxX = BOARD_WIDTH - 1;
     int maxY = BOARD_HEIGHT - 1;
     int BORAD_SIZE = BOARD_HEIGHT*BOARD_WIDTH;
    console::clear();

    for (int i = 0; i < BORAD_SIZE; i++) {
    console::draw(i, 0, CONSOLEWALL_HORIZONTAL_STRING);
    console::draw(i, BOARD_SIZE - 1, WALL_HORIZONTAL_STRING);
    console::draw(0, i, WALL_VERTICAL_STRING);
    console::draw(BOARD_SIZE - 1, i, WALL_VERTICAL_STRING);
  }
     console::draw(minX, minY, "r");
     console::draw(maxX, minY, "┐");
     console::draw(minX, maxY, "└");
     console::draw(maxX, maxY, "┘");
     

  }
  // 소프트 드롭 로직
void softDrop() {
    // 게임 보드의 현재 테트로미노를 아래로 한 칸 이동
    moveCurrentTetrominoDown();
}
  
  // 게임 루프가 종료되어야 하는지 여부를 반환한다.
  bool shouldExit(){

    if(key(console::K_ESC))
        return;

    if(gamegover()){
      return true;
    }


    return false;
  }

  