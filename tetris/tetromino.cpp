#include "tetromino.h"

//static Tetromino I, O, T, S, Z, J, L;
Tetromino Tetromino::I("I",4,"XXXXOOOOXXXXXXXX");
Tetromino Tetromino::O("O",2,"OOOO");
Tetromino Tetromino::T("T",3,"XOXOOOXXX");
Tetromino Tetromino::S("S",3,"XOOOOXXXX");
Tetromino Tetromino::Z("Z", 3, "OOXXOOXXX");
Tetromino Tetromino::J("J", 3, "OXXOOOXXX");
Tetromino Tetromino::L("L", 3, "XXOOOOXXX");



Tetromino(std::string name, int size, std::string shape)
    : name_(name), size_(size){
    // : 이용해서 빠른 초기화 각 값이 
        int index = 0;
        for(int i = 0; i < size_; ++i){
            for(int j = 0; j < size_; ++j){
                shape_[i][j] = (shape[index++] == 'O');
            }
        }
    }


// 시계 방향으로 회전한 모습의 테트로미노 객체를 반환한다.
  Tetromino rotatedCW(){

    Tetromino rotated(name_, size_, "");

    for(int i = 0; i < size_; ++i){
        for(int j = 0; j < size_; ++j){
            rotated.shape_[i][j] = shape_[size_ -j - 1][i];
        }
    }
    return rotated;
  }

 // 반시계 방향으로 회전한 모습의 테트로미노 객체를 반환한다.
  Tetromino rotatedCCW(){

    Tetromino rotated(name_, size_, "");

    for(int i = 0; i < size_; ++i){
        for(int j = 0; j < size_; ++j){
            rotated.shape_[i][j] = shape_[j][size_ -i - 1];
        }
    }
    return rotated;
  }

  // 화면의 x, y 위치에 s 문자열로  테트로미노를 그린다
  void drawAt(std::string s, int x, int y){
    int index = 0;
    for(int i = x; i < x + size_; ++i){
        for(int j = y; j < y + size_; ++j){
            if(shape_[i - x][j - y]){

                s[index] = BLOCK_STRING[0];
            }
            index++;
        }
    }

  }